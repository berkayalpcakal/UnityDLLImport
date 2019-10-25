/*
 * simpleSum.c
 *
 * Code generation for model "simpleSum".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Oct 25 15:31:56 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "simpleSum.h"
#include "simpleSum_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_simpleSum_T simpleSum_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_simpleSum_T simpleSum_Y;

/* Real-time model */
RT_MODEL_simpleSum_T simpleSum_M_;
RT_MODEL_simpleSum_T *const simpleSum_M = &simpleSum_M_;

/* Model step function */
void simpleSum_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<Root>/Add'
   */
  simpleSum_Y.Out1 = simpleSum_U.In1 + simpleSum_U.In2;
}

/* Model initialize function */
void simpleSum_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(simpleSum_M, (NULL));

  /* external inputs */
  (void)memset(&simpleSum_U, 0, sizeof(ExtU_simpleSum_T));

  /* external outputs */
  simpleSum_Y.Out1 = 0.0F;
}

/* Model terminate function */
void simpleSum_terminate(void)
{
  /* (no terminate code required) */
}

void initialize(void)
{
	simpleSum_initialize();
}

void step(void)
{
	simpleSum_step();
}

void set_inputs(real32_T _in1, real32_T _in2)
{
	simpleSum_U.In1 = _in1;
	simpleSum_U.In2 = _in2;
}

real32_T get_output()
{
	return simpleSum_Y.Out1;
}