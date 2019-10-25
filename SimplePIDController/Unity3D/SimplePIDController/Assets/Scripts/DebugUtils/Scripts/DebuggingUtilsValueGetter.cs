using UnityEngine;

namespace DebuggingUtils
{
    public abstract class DebuggingUtilsValueGetter : MonoBehaviour
    {
        public void GetValue(LineGrapher.GraphConfig config)
        {
            config.dataBuffer.AddToBuffer(ReadValue());
        }

        public void GetValue(LogToCSV.LoggerConfig config)
        {
            config.dataBuffer.AddToBuffer(ReadValue());
        }

        public abstract float ReadValue();
    }

}