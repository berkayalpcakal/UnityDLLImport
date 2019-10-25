using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditorInternal;
using UnityEngine;


namespace DebuggingUtils
{
    [CustomEditor(typeof(LogToCSV)), CanEditMultipleObjects]
    public class LogToCSVInspector : Editor
    {

        private LogToCSV.LoggerConfig _loggerConfig;
        private DataBuffer _timeBuffer;
        private bool isSettingsExpanded = true;
        private string fileName = "output.csv";

        private void OnDisable()
        {

        }

        public override bool RequiresConstantRepaint()
        {
            return true;
        }


        public override void OnInspectorGUI()
        {
            try
            {
                LogToCSV logToCSV = (LogToCSV)target;
                _loggerConfig = logToCSV.loggerConfig;
                _timeBuffer = logToCSV.timeBuffer;

                DrawDefaultInspector();
                serializedObject.Update();

                GUILayout.Label("Log to CSV", EditorStyles.boldLabel);

                EditorGUILayout.BeginHorizontal();
                fileName = EditorGUILayout.TextField("File Name", fileName);

                if (GUILayout.Button("Export", new GUIStyle(EditorStyles.miniButtonRight) { fixedWidth = 100 }))
                    WriteBufferToFile(Path.Combine(_loggerConfig.outputFolder, fileName));
                EditorGUILayout.EndHorizontal();

                EditorGUILayout.BeginHorizontal();
                _loggerConfig.logOnUpdate = EditorGUILayout.Toggle("Logging on Application Run", _loggerConfig.logOnUpdate);
                EditorGUILayout.HelpBox(new GUIContent("Exports on Application Quit. Overrides existing log file."));
                EditorGUILayout.EndHorizontal();


                GUILayout.Space(10);
                isSettingsExpanded = EditorGUILayout.Foldout(isSettingsExpanded, "Settings", toggleOnLabelClick: true);
                if (isSettingsExpanded)
                {
                    EditorGUILayout.BeginHorizontal();
                    _loggerConfig.outputFolder = EditorGUILayout.TextField("Output Folder", _loggerConfig.outputFolder);
                    if (GUILayout.Button("Select", new GUIStyle(EditorStyles.miniButtonRight) { fixedWidth = 75 }))
                        _loggerConfig.outputFolder = EditorUtility.OpenFolderPanel("Select a folder", _loggerConfig.outputFolder, "");
                    EditorGUILayout.EndHorizontal();


                    EditorGUILayout.BeginVertical();
                    _loggerConfig.bufferLength = EditorGUILayout.IntField("Buffer Length", _loggerConfig.bufferLength);
                    EditorGUILayout.EndVertical();


                    EditorGUILayout.BeginVertical();
                    _loggerConfig.timeStampType = (LogToCSV.TimeStampType)EditorGUILayout.EnumPopup("Time Stamp Type", _loggerConfig.timeStampType);
                    EditorGUILayout.EndVertical();

                    EditorGUILayout.BeginVertical();
                    SerializedProperty property = serializedObject.FindProperty("loggerConfig");
                    EditorGUILayout.PropertyField(property.FindPropertyRelative("onGetValue"), new GUIContent("Select Data Source Function"));
                    EditorGUILayout.EndVertical();

                    EditorGUILayout.BeginVertical();
                    if (GUILayout.Button("Reset Settings", new GUIStyle(EditorStyles.miniButtonLeft) { fixedWidth = 150 }))
                        ResetSettings();
                    EditorGUILayout.EndVertical();
                    serializedObject.ApplyModifiedProperties();
                }
            }
            catch (Exception e)
            {
                Debug.Log(e.ToString());
            }

        }

        public void WriteBufferToFile(string filePath)
        {
            string lineFormat = "{0:G" + 4 + "} {1:G" + 4 + "}";

            try
            {
                DataBuffer timeBuffer = ((LogToCSV)target).timeBuffer;
                DataBuffer dataBuffer = _loggerConfig.dataBuffer;
                using (var outputFileWriter = new StreamWriter(@filePath))
                {
                    for (int i = 0; i < _loggerConfig.bufferLength; i++)
                    {
                        float data = dataBuffer.GetValueAt(i);
                        float time = timeBuffer.GetValueAt(i);
                        outputFileWriter.WriteLine(lineFormat, time, data);
                    }
                }
            }
            catch (Exception e)
            {
                Debug.Log(e.ToString());
            }

            AssetDatabase.Refresh();
        }

        public void ResetSettings()
        {
            fileName = "output.csv";
            _loggerConfig.outputFolder = Path.Combine(Path.Combine(Path.GetFullPath("."), "Assets"));
            _loggerConfig.bufferLength = 50;
            _loggerConfig.timeStampType = LogToCSV.TimeStampType.realtimeSinceStartup;
            _loggerConfig.logOnUpdate = false;
        }

    }
}