using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEditorInternal;
using UnityEngine;


namespace DebuggingUtils
{
    [CustomEditor(typeof(LineGrapher)), CanEditMultipleObjects]
    public class LineGrapherInspector : Editor
    {
        private int windowMaxHeight = 200;
        private int windowMinHeight = 200;
        private int windowMinWidth = 100;
        private int windowMaxWidth = 1000;
        private Rect windowRectangle;
        private Material _material;
        private Shader _shader;
        private ReorderableList _reorderableList;
        private SerializedProperty _graphConfigsProperty;
        private List<LineGrapher.GraphConfig> _graphConfigs;

        private void OnEnable()
        {
            _shader = Shader.Find("Hidden/Internal-Colored");
            _material = new Material(_shader);
            _graphConfigsProperty = serializedObject.FindProperty("graphConfigs");

            _reorderableList = new ReorderableList(serializedObject: serializedObject, elements: _graphConfigsProperty, true, true, true, true);
            _reorderableList.drawHeaderCallback += DrawHeaderCallback;
            _reorderableList.drawElementCallback += DrawElementCallback;
            _reorderableList.elementHeightCallback += ElementHeightCallback;
            
        }

        private void DrawHeaderCallback(Rect rect)
        {
            EditorGUI.LabelField(rect, "Line Graphs");

        }

        private void DrawElementCallback(Rect rect, int index, bool isActive, bool isFocused)
        {
            SerializedProperty property = _reorderableList.serializedProperty.GetArrayElementAtIndex(index);

            rect.y += 2;
            Rect tempRect = new Rect(rect.x + 10, rect.y, rect.width, EditorGUIUtility.singleLineHeight);
            property.isExpanded = EditorGUI.Foldout(tempRect, property.isExpanded, new GUIContent("Line Graph " + index.ToString()));

            if (property.isExpanded)
            {
                rect.y += EditorGUIUtility.singleLineHeight;

                EditorGUI.PropertyField(new Rect(rect.x, rect.y, rect.width, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("bufferLength"));
                rect.y += EditorGUIUtility.singleLineHeight * 1.2f;

                EditorGUI.PropertyField(new Rect(rect.x, rect.y, rect.width * 0.55f, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("VerticalAxisScale"));

                EditorGUI.PropertyField(new Rect(rect.x + rect.width * 0.55f, rect.y, rect.width, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("autoScale"), new GUIContent("  Auto Scale"));
                rect.y += EditorGUIUtility.singleLineHeight * 1.2f;

                EditorGUI.PropertyField(new Rect(rect.x, rect.y, rect.width, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("color"));
                rect.y += EditorGUIUtility.singleLineHeight * 1.2f;

                EditorGUI.PropertyField(new Rect(rect.x, rect.y, rect.width, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("labelCurrentValue"));
                rect.y += EditorGUIUtility.singleLineHeight * 1.2f;
                
                EditorGUI.PropertyField(new Rect(rect.x, rect.y, rect.width, EditorGUIUtility.singleLineHeight), property.FindPropertyRelative("onGetValue"), new GUIContent("Select Data Source Function"));
                rect.y += EditorGUIUtility.singleLineHeight * 1.2f + EditorGUI.GetPropertyHeight(property.FindPropertyRelative("onGetValue"), true);
            } 
        }

        private float ElementHeightCallback(int index)
        {
            SerializedProperty property = _reorderableList.serializedProperty.GetArrayElementAtIndex(index);

            if (property.isExpanded)
            {
                float propertyHeight = EditorGUI.GetPropertyHeight(_reorderableList.serializedProperty.GetArrayElementAtIndex(index), true);
                float spacing = EditorGUIUtility.singleLineHeight * 10;
                return propertyHeight + spacing;
            }
            else
                return EditorGUIUtility.singleLineHeight * 1.2f;
        }

        private void OnDisable()
        {
            DestroyImmediate(_material);
        }

        public override bool RequiresConstantRepaint()
        {
            return true;
        }

        public override void OnInspectorGUI()
        {
            DrawDefaultInspector();

            serializedObject.Update();
            _reorderableList.DoLayoutList();
            serializedObject.ApplyModifiedProperties();

            _graphConfigs = ((LineGrapher)target).graphConfigs;

            #region LineGraph
            windowRectangle = GUILayoutUtility.GetRect(windowMinWidth, windowMaxWidth, windowMinHeight, windowMaxHeight);

            if (Event.current.type == EventType.Repaint)
            {
                GUI.BeginClip(windowRectangle);
                GL.PushMatrix();

                GL.Clear(true, false, Color.black);
                _material.SetPass(0);

                #region draw background
                // background
                GL.Begin(GL.QUADS);
                GL.Color(Color.black);
                GL.Vertex3(0, 0, 0);
                GL.Vertex3(windowRectangle.width, 0, 0);
                GL.Vertex3(windowRectangle.width, windowRectangle.height, 0);
                GL.Vertex3(0, windowRectangle.height, 0);
                GL.End();
                #endregion

                #region draw grid
                // draw grid
                GL.Begin(GL.LINES);
                int offset = 0; // (Time.frameCount) % 50;
                int count = (int)(windowRectangle.width / 10) + 20;
                for (int i = 0; i < count; i++)
                {
                    float f = (i % 5 == 0) ? 0.5f : 0.2f;
                    GL.Color(new Color(f, f, f, 1));
                    float x = i * 10 - offset;
                    if (x >= 0 && x < windowRectangle.width)
                    {
                        GL.Vertex3(x, 0, 0);
                        GL.Vertex3(x, windowRectangle.height, 0);
                    }
                    if (i < windowRectangle.height / 10)
                    {
                        GL.Vertex3(0, i * 10, 0);
                        GL.Vertex3(windowRectangle.width, i * 10, 0);
                    }
                }
                GL.End();
                #endregion

                #region draw data
                foreach (LineGrapher.GraphConfig graphConfig in _graphConfigs)
                    DrawDataOnGraph(graphConfig);
                #endregion

                GL.PopMatrix();
                GUI.EndClip();
            }

            #region DrawAxisLabelsAndCurrentValue
            float labelPosX = windowRectangle.x + 10;
            foreach (LineGrapher.GraphConfig graphConfig in ((LineGrapher)target).graphConfigs)
            {
                if (graphConfig.autoScale && graphConfig.dataBuffer.GetDataBuffer().Count != 0)
                {
                    graphConfig.VerticalAxisYmin = graphConfig.dataBuffer.GetDataBuffer().Min();
                    graphConfig.VerticalAxisYmax = graphConfig.dataBuffer.GetDataBuffer().Max();
                }
                else
                {
                    graphConfig.VerticalAxisYmin = -graphConfig.VerticalAxisScale;
                    graphConfig.VerticalAxisYmax = graphConfig.VerticalAxisScale;
                }

                GUIStyle style = new GUIStyle();
                style.normal.textColor = graphConfig.color;

                GUI.Label(new Rect(labelPosX, windowRectangle.y, 50, 50), "y =  " + graphConfig.VerticalAxisYmax.ToString(), style);
                GUI.Label(new Rect(labelPosX, windowRectangle.y + windowRectangle.height - 13, 50, 50), "y = " + graphConfig.VerticalAxisYmin.ToString(), style);

                if(graphConfig.labelCurrentValue && graphConfig.dataBuffer.GetDataBuffer().Count != 0)
                    GUI.Label(new Rect(labelPosX, windowRectangle.y + 12, 50, 50), graphConfig.dataBuffer.GetValueAt(graphConfig.dataBuffer.GetDataBuffer().Count - 1).ToString(), style);

                labelPosX += 100;
            }
            #endregion DrawAxisLabelsAndCurrentValue


            #endregion LineGraph

        }

        private float MapValueToRectangleWindow(float val, float _y_max, float _y_min)
        {
            return windowRectangle.height * (1 - (val - _y_min) / (_y_max - _y_min));
        }

        private void DrawDataOnGraph(LineGrapher.GraphConfig _graphConfig)
        {
            _graphConfig.dataBuffer.UpdateBufferLength(_graphConfig.bufferLength);
            List<float> _data = _graphConfig.dataBuffer.GetDataBuffer();
            Color _color = _graphConfig.color;

            if (_data.Count != 0)
            {
                GL.Begin(GL.LINE_STRIP);
                GL.Color(_color);

                int max_iter = _data.Count > windowRectangle.width ? (int)windowRectangle.width : _data.Count;

                for (int i = 0; i < max_iter; i++)
                    GL.Vertex3(windowRectangle.width - i, MapValueToRectangleWindow(_data[_data.Count - 1 - i], _graphConfig.VerticalAxisYmax, _graphConfig.VerticalAxisYmin), 0);

                GL.End();
            }

        }

    }
}