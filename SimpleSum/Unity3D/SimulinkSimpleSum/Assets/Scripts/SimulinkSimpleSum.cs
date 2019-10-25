using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;

public class SimulinkSimpleSum : MonoBehaviour
{
    [DllImport("simpleSum", EntryPoint = "initialize")]
    public static extern void simpleSum_initialize();

    [DllImport("simpleSum", EntryPoint = "step")]
    public static extern float simpleSum_step();

    [DllImport("simpleSum", EntryPoint = "set_inputs")]
    public static extern void simpleSum_set_inputs(float in1, float in2);

    [DllImport("simpleSum", EntryPoint = "get_output")]
    public static extern float simpleSum_get_output();

    public float in1;
    public float in2;
    public float out1;


    void Start()
    {
        simpleSum_initialize();
    }

    void Update()
    {
        simpleSum_set_inputs(in1, in2);
        simpleSum_step();
        out1 = simpleSum_get_output();
    }
}
