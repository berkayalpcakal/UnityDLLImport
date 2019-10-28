using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.IO;

public class SimplePIDController : MonoBehaviour
{
    [DllImport("SimplePIDController", EntryPoint = "initialize")]
    public static extern void SimplePIDController_initialize();

    [DllImport("SimplePIDController", EntryPoint = "step")]
    public static extern float SimplePIDController_step();

    [DllImport("SimplePIDController", EntryPoint = "set_inputs")]
    public static extern void SimplePIDController_set_inputs(double _in);

    [DllImport("SimplePIDController", EntryPoint = "get_output")]
    public static extern double SimplePIDController_get_output();

    [DllImport("SimplePIDController", EntryPoint = "set_pid_params")]
    public static extern double SimplePIDController_set_pid_params(double _kp, double _ki, double _kd);

    public double target = 1;
    public double controlValue;

    public double kp = 1;
    public double ki = 0;
    public double kd = 0; 
    public bool setPIDParams = false;

    void Start()
    {
        SimplePIDController_initialize();
    }


    void FixedUpdate()
    {
        if(setPIDParams)
        {
            SimplePIDController_set_pid_params(kp, ki, kd);
            setPIDParams = false;
        }

        SimplePIDController_set_inputs(target);

        for (int i = 0; i < 100; i++)
        {
            SimplePIDController_step();
            controlValue = SimplePIDController_get_output();
        }
        Debug.Log(controlValue);
    }
}
