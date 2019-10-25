using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.Serialization;
using UnityEngine.UI;

namespace DebuggingUtils
{
    [Serializable]
    public class UnityEventGraphConfig : UnityEvent<LineGrapher.GraphConfig> { }

    public class LineGrapher : MonoBehaviour
    {

        [Serializable]
        public class GraphConfig
        {
            [SerializeField]
            public int bufferLength;

            [SerializeField]
            public float VerticalAxisScale;

            public float VerticalAxisYmin;
            public float VerticalAxisYmax;

            [SerializeField]
            public bool autoScale;

            [SerializeField]
            public bool labelCurrentValue;

            [SerializeField]
            public UnityEventGraphConfig onGetValue;

            [SerializeField]
            public Color color;

            public DataBuffer dataBuffer;

            public GraphConfig()
            {
                dataBuffer = new DataBuffer();
                VerticalAxisScale = 50;
                color = Color.green;
            }
        }

        [HideInInspector]
        public List<GraphConfig> graphConfigs = new List<GraphConfig>();

        private int[] prevBufferLengths;

        private void Start()
        {
            prevBufferLengths = new int[graphConfigs.Count];
            for (int i = 0; i < graphConfigs.Count; i++)
                prevBufferLengths[i] = 100;
        }

        private void Update()
        {
            for (int i = 0; i < graphConfigs.Count; i++)
                graphConfigs[i].onGetValue.Invoke(graphConfigs[i]);
            
        }
    }
}