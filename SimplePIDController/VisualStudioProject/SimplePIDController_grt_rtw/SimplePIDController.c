/*
 * SimplePIDController.c
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

/* Block signals (default storage) */
B_SimplePIDController_T SimplePIDController_B;

/* Continuous states */
X_SimplePIDController_T SimplePIDController_X;

/* External inputs (root inport signals with default storage) */
ExtU_SimplePIDController_T SimplePIDController_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SimplePIDController_T SimplePIDController_Y;

/* Real-time model */
RT_MODEL_SimplePIDController_T SimplePIDController_M_;
RT_MODEL_SimplePIDController_T *const SimplePIDController_M =
  &SimplePIDController_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SimplePIDController_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SimplePIDController_step();
  SimplePIDController_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SimplePIDController_step();
  SimplePIDController_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void SimplePIDController_step(void)
{
  if (rtmIsMajorTimeStep(SimplePIDController_M)) {
    /* set solver stop time */
    if (!(SimplePIDController_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SimplePIDController_M->solverInfo,
                            ((SimplePIDController_M->Timing.clockTickH0 + 1) *
        SimplePIDController_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SimplePIDController_M->solverInfo,
                            ((SimplePIDController_M->Timing.clockTick0 + 1) *
        SimplePIDController_M->Timing.stepSize0 +
        SimplePIDController_M->Timing.clockTickH0 *
        SimplePIDController_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SimplePIDController_M)) {
    SimplePIDController_M->Timing.t[0] = rtsiGetT
      (&SimplePIDController_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  SimplePIDController_B.TransferFcn = 0.0;
  SimplePIDController_B.TransferFcn += SimplePIDController_P.TransferFcn_C[0] *
    SimplePIDController_X.TransferFcn_CSTATE[0];
  SimplePIDController_B.TransferFcn += SimplePIDController_P.TransferFcn_C[1] *
    SimplePIDController_X.TransferFcn_CSTATE[1];
  SimplePIDController_B.TransferFcn += SimplePIDController_P.TransferFcn_C[2] *
    SimplePIDController_X.TransferFcn_CSTATE[2];

  /* Outport: '<Root>/Out1' */
  SimplePIDController_Y.Out1 = SimplePIDController_B.TransferFcn;

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/In1'
   */
  SimplePIDController_B.Sum = SimplePIDController_U.In1 -
    SimplePIDController_B.TransferFcn;

  /* Gain: '<S25>/Derivative Gain' */
  SimplePIDController_B.DerivativeGain = SimplePIDController_P.kd *
    SimplePIDController_B.Sum;

  /* Integrator: '<S26>/Filter' */
  SimplePIDController_B.Filter = SimplePIDController_X.Filter_CSTATE;

  /* Sum: '<S26>/SumD' */
  SimplePIDController_B.SumD = SimplePIDController_B.DerivativeGain -
    SimplePIDController_B.Filter;

  /* Gain: '<S28>/Integral Gain' */
  SimplePIDController_B.IntegralGain = SimplePIDController_P.ki *
    SimplePIDController_B.Sum;

  /* Integrator: '<S31>/Integrator' */
  SimplePIDController_B.Integrator = SimplePIDController_X.Integrator_CSTATE;

  /* Gain: '<S34>/Filter Coefficient' */
  SimplePIDController_B.FilterCoefficient = SimplePIDController_P.kf *
    SimplePIDController_B.SumD;

  /* Gain: '<S36>/Proportional Gain' */
  SimplePIDController_B.ProportionalGain = SimplePIDController_P.kp *
    SimplePIDController_B.Sum;

  /* Sum: '<S40>/Sum' */
  SimplePIDController_B.Sum_d = (SimplePIDController_B.ProportionalGain +
    SimplePIDController_B.Integrator) + SimplePIDController_B.FilterCoefficient;
  if (rtmIsMajorTimeStep(SimplePIDController_M)) {
    rt_ertODEUpdateContinuousStates(&SimplePIDController_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SimplePIDController_M->Timing.clockTick0)) {
      ++SimplePIDController_M->Timing.clockTickH0;
    }

    SimplePIDController_M->Timing.t[0] = rtsiGetSolverStopTime
      (&SimplePIDController_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-6s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-6, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      SimplePIDController_M->Timing.clockTick1++;
      if (!SimplePIDController_M->Timing.clockTick1) {
        SimplePIDController_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SimplePIDController_derivatives(void)
{
  XDot_SimplePIDController_T *_rtXdot;
  _rtXdot = ((XDot_SimplePIDController_T *) SimplePIDController_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += SimplePIDController_P.TransferFcn_A[0] *
    SimplePIDController_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += SimplePIDController_P.TransferFcn_A[1] *
    SimplePIDController_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[2] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += SimplePIDController_P.TransferFcn_A[2] *
    SimplePIDController_X.TransferFcn_CSTATE[2];
  _rtXdot->TransferFcn_CSTATE[1] += SimplePIDController_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[2] += SimplePIDController_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[0] += SimplePIDController_B.Sum_d;

  /* Derivatives for Integrator: '<S26>/Filter' */
  _rtXdot->Filter_CSTATE = SimplePIDController_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S31>/Integrator' */
  _rtXdot->Integrator_CSTATE = SimplePIDController_B.IntegralGain;
}

/* Model initialize function */
void SimplePIDController_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SimplePIDController_M, 0,
                sizeof(RT_MODEL_SimplePIDController_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SimplePIDController_M->solverInfo,
                          &SimplePIDController_M->Timing.simTimeStep);
    rtsiSetTPtr(&SimplePIDController_M->solverInfo, &rtmGetTPtr
                (SimplePIDController_M));
    rtsiSetStepSizePtr(&SimplePIDController_M->solverInfo,
                       &SimplePIDController_M->Timing.stepSize0);
    rtsiSetdXPtr(&SimplePIDController_M->solverInfo,
                 &SimplePIDController_M->derivs);
    rtsiSetContStatesPtr(&SimplePIDController_M->solverInfo, (real_T **)
                         &SimplePIDController_M->contStates);
    rtsiSetNumContStatesPtr(&SimplePIDController_M->solverInfo,
      &SimplePIDController_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SimplePIDController_M->solverInfo,
      &SimplePIDController_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SimplePIDController_M->solverInfo,
      &SimplePIDController_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SimplePIDController_M->solverInfo,
      &SimplePIDController_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SimplePIDController_M->solverInfo,
                          (&rtmGetErrorStatus(SimplePIDController_M)));
    rtsiSetRTModelPtr(&SimplePIDController_M->solverInfo, SimplePIDController_M);
  }

  rtsiSetSimTimeStep(&SimplePIDController_M->solverInfo, MAJOR_TIME_STEP);
  SimplePIDController_M->intgData.y = SimplePIDController_M->odeY;
  SimplePIDController_M->intgData.f[0] = SimplePIDController_M->odeF[0];
  SimplePIDController_M->intgData.f[1] = SimplePIDController_M->odeF[1];
  SimplePIDController_M->intgData.f[2] = SimplePIDController_M->odeF[2];
  SimplePIDController_M->contStates = ((X_SimplePIDController_T *)
    &SimplePIDController_X);
  rtsiSetSolverData(&SimplePIDController_M->solverInfo, (void *)
                    &SimplePIDController_M->intgData);
  rtsiSetSolverName(&SimplePIDController_M->solverInfo,"ode3");
  rtmSetTPtr(SimplePIDController_M, &SimplePIDController_M->Timing.tArray[0]);
  SimplePIDController_M->Timing.stepSize0 = 1.0E-6;

  /* block I/O */
  (void) memset(((void *) &SimplePIDController_B), 0,
                sizeof(B_SimplePIDController_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SimplePIDController_X, 0,
                  sizeof(X_SimplePIDController_T));
  }

  /* external inputs */
  SimplePIDController_U.In1 = 0.0;

  /* external outputs */
  SimplePIDController_Y.Out1 = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  SimplePIDController_X.TransferFcn_CSTATE[0] = 0.0;
  SimplePIDController_X.TransferFcn_CSTATE[1] = 0.0;
  SimplePIDController_X.TransferFcn_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<S26>/Filter' */
  SimplePIDController_X.Filter_CSTATE =
    SimplePIDController_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S31>/Integrator' */
  SimplePIDController_X.Integrator_CSTATE =
    SimplePIDController_P.PIDController_InitialConditio_e;
}

/* Model terminate function */
void SimplePIDController_terminate(void)
{
  /* (no terminate code required) */
}

void initialize(void)
{
	SimplePIDController_initialize();
}

void step(void)
{
	SimplePIDController_step();
}

void set_inputs(real_T _in)
{
	SimplePIDController_U.In1 = _in;
}

real_T get_output()
{
	return SimplePIDController_Y.Out1;
}