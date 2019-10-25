/*
 * SimplePIDController_data.c
 *
 * Code generation for model "SimplePIDController".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Oct 25 17:19:47 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "SimplePIDController.h"
#include "SimplePIDController_private.h"

/* Block parameters (default storage) */
P_SimplePIDController_T SimplePIDController_P = {
  /* Variable: kd
   * Referenced by: '<S25>/Derivative Gain'
   */
  0.0,

  /* Variable: kf
   * Referenced by: '<S34>/Filter Coefficient'
   */
  100.0,

  /* Variable: ki
   * Referenced by: '<S28>/Integral Gain'
   */
  0.0,

  /* Variable: kp
   * Referenced by: '<S36>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S26>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_e
   * Referenced by: '<S31>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -1.4545465410588977E+6, -8.6143521699462742E+7, -0.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { 0.0, 0.0, 3.08624593099875E+9 }
};
