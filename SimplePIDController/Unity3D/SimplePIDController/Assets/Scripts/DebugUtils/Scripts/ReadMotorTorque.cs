using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DebuggingUtils;

public class ReadMotorTorque : DebuggingUtilsValueGetter
{
    public override float ReadValue()
    {
        return GetComponent<HingeJoint>().currentTorque.magnitude;
    }
}
