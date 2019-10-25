using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DebuggingUtils;

public class ReadMotorVelocity : DebuggingUtilsValueGetter
{
    public override float ReadValue()
    {
        return GetComponent<HingeJoint>().velocity;
    }
}
