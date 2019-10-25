using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.Events;

namespace DebuggingUtils
{
    [Serializable]
    public class UnityEventLoggerConfig : UnityEvent<LogToCSV.LoggerConfig> { }

    public class LogToCSV : MonoBehaviour
    {
        public enum TimeStampType
        {
            time = 0,
            fixedTime = 1,
            realtimeSinceStartup = 2,
        };


        [Serializable]
        public class LoggerConfig
        {
            [SerializeField]
            public string outputFolder;

            [SerializeField]
            public bool logOnUpdate;

            [SerializeField]
            public int bufferLength;

            [SerializeField]
            public TimeStampType timeStampType;

            [SerializeField]
            public UnityEventLoggerConfig onGetValue;

            public DataBuffer dataBuffer;

            public LoggerConfig()
            {
                outputFolder = Path.Combine(Path.Combine(Path.GetFullPath("."), "Assets"));
                bufferLength = 50;
                timeStampType = TimeStampType.realtimeSinceStartup;
                dataBuffer = new DataBuffer();
            }

        }

        [HideInInspector]
        public LoggerConfig loggerConfig = new LoggerConfig();

        [HideInInspector]
        public DataBuffer timeBuffer = new DataBuffer();

        private StreamWriter logOnUpdateStreamWriter;
        private string logOnUpdateFilePath;
        private string logOnUpdateLineFormat;
        private List<float> logOnUpdateDataBuffer = new List<float>();
        private List<float> logOnUpdateTimeBuffer = new List<float>();


        private void Start()
        {
            timeBuffer = new DataBuffer();

            logOnUpdateLineFormat = "{0:G" + 4 + "} {1:G" + 4 + "}";
            if(loggerConfig.outputFolder != null)
                logOnUpdateFilePath = Path.Combine(loggerConfig.outputFolder, "autolog.csv");
            else
                logOnUpdateFilePath = Path.Combine(Path.Combine(Path.GetFullPath("."), "Assets"), "autolog.csv");            
            logOnUpdateStreamWriter = new StreamWriter(logOnUpdateFilePath);
        }

        private void Update()
        {
            try
            {
                timeBuffer.AddToBuffer(GetTimeStamp());
                loggerConfig.onGetValue.Invoke(loggerConfig);
                loggerConfig.dataBuffer.UpdateBufferLength(loggerConfig.bufferLength);
                timeBuffer.UpdateBufferLength(loggerConfig.bufferLength);

                if (loggerConfig.logOnUpdate)
                {
                    logOnUpdateDataBuffer.Add(loggerConfig.dataBuffer.GetValueAt(loggerConfig.dataBuffer.GetBufferLength() - 1));
                    logOnUpdateTimeBuffer.Add(timeBuffer.GetValueAt(timeBuffer.GetBufferLength() - 1));
                }

            }

            catch (Exception e)
            {
                Debug.Log(e.ToString());
            }
        }

        private float GetTimeStamp()
        {
            float time = 0;

            switch (loggerConfig.timeStampType)
            {
                case TimeStampType.time:
                    time = Time.time;
                    break;
                case TimeStampType.fixedTime:
                    time = Time.fixedTime;
                    break;
                case TimeStampType.realtimeSinceStartup:
                    time = Time.realtimeSinceStartup;
                    break;
            }
            return time;
        }

        private void OnApplicationQuit()
        {
            for (int i = 0; i < logOnUpdateDataBuffer.Count; i++)
            {
                logOnUpdateStreamWriter.WriteLine(logOnUpdateLineFormat, logOnUpdateTimeBuffer[i], logOnUpdateDataBuffer[i]);
            }
        }

    }
}