using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace DebuggingUtils
{
    public class DataBuffer
    {
        private List<float> _floatList;

        public DataBuffer()
        {
            _floatList = new List<float>();
            for(int i=0; i<100; i++)
                _floatList.Add(0);
        }

        public List<float> GetDataBuffer()
        {
            return _floatList;
        }

        public float GetValueAt(int idx)
        {
            return _floatList[idx];
        }

        public void AddToBuffer(float val)
        {
            if (_floatList.Count != 0)
            {
                _floatList.RemoveAt(0);
                _floatList.Add(val);
            }
        }

        public int GetBufferLength()
        {
            return _floatList.Count;
        }

        public void UpdateBufferLength(int count)
        {
            if (_floatList.Count > count)
            {
                _floatList.RemoveRange(0, _floatList.Count - count);
            }

            if (_floatList.Count < count)
            {
                _floatList.InsertRange(0, new float[count - _floatList.Count]);
            }

        }
    }
}