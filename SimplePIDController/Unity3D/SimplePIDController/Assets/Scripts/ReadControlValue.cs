using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DebuggingUtils;

public class ReadControlValue : DebuggingUtilsValueGetter
{
    public override float ReadValue()
    {
        return (float) GetComponent<SimplePIDController>().controlValue;
    }

}
