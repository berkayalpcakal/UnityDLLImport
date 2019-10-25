using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DebuggingUtils;

public class ReadMotorAngle : DebuggingUtilsValueGetter
{
    public override float ReadValue()
    {
        return GetComponent<HingeJoint>().angle;
    }
}
