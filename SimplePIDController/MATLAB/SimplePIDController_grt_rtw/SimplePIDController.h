/*
 * SimplePIDController.h
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

#ifndef RTW_HEADER_SimplePIDController_h_
#define RTW_HEADER_SimplePIDController_h_
#include <string.h>
#ifndef SimplePIDController_COMMON_INCLUDES_
# define SimplePIDController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                /* SimplePIDController_COMMON_INCLUDES_ */

#include "SimplePIDController_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T DerivativeGain;               /* '<S25>/Derivative Gain' */
  real_T Filter;                       /* '<S26>/Filter' */
  real_T SumD;                         /* '<S26>/SumD' */
  real_T IntegralGain;                 /* '<S28>/Integral Gain' */
  real_T Integrator;                   /* '<S31>/Integrator' */
  real_T FilterCoefficient;            /* '<S34>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S36>/Proportional Gain' */
  real_T Sum_d;                        /* '<S40>/Sum' */
} B_SimplePIDController_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[3];        /* '<Root>/Transfer Fcn' */
  real_T Filter_CSTATE;                /* '<S26>/Filter' */
  real_T Integrator_CSTATE;            /* '<S31>/Integrator' */
} X_SimplePIDController_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE[3];        /* '<Root>/Transfer Fcn' */
  real_T Filter_CSTATE;                /* '<S26>/Filter' */
  real_T Integrator_CSTATE;            /* '<S31>/Integrator' */
} XDot_SimplePIDController_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE[3];     /* '<Root>/Transfer Fcn' */
  boolean_T Filter_CSTATE;             /* '<S26>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S31>/Integrator' */
} XDis_SimplePIDController_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_SimplePIDController_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_SimplePIDController_T;

/* Parameters (default storage) */
struct P_SimplePIDController_T_ {
  real_T kd;                           /* Variable: kd
                                        * Referenced by: '<S25>/Derivative Gain'
                                        */
  real_T kf;                           /* Variable: kf
                                        * Referenced by: '<S34>/Filter Coefficient'
                                        */
  real_T ki;                           /* Variable: ki
                                        * Referenced by: '<S28>/Integral Gain'
                                        */
  real_T kp;                           /* Variable: kp
                                        * Referenced by: '<S36>/Proportional Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S26>/Filter'
                               */
  real_T PIDController_InitialConditio_e;
                              /* Mask Parameter: PIDController_InitialConditio_e
                               * Referenced by: '<S31>/Integrator'
                               */
  real_T TransferFcn_A[3];             /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C[3];             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimplePIDController_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_SimplePIDController_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_SimplePIDController_T SimplePIDController_P;

/* Block signals (default storage) */
extern B_SimplePIDController_T SimplePIDController_B;

/* Continuous states (default storage) */
extern X_SimplePIDController_T SimplePIDController_X;

/* External inputs (root inport signals with default storage) */
extern ExtU_SimplePIDController_T SimplePIDController_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SimplePIDController_T SimplePIDController_Y;

/* Model entry point functions */
extern void SimplePIDController_initialize(void);
extern void SimplePIDController_step(void);
extern void SimplePIDController_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimplePIDController_T *const SimplePIDController_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SimplePIDController'
 * '<S1>'   : 'SimplePIDController/PID Controller'
 * '<S2>'   : 'SimplePIDController/PID Controller/Anti-windup'
 * '<S3>'   : 'SimplePIDController/PID Controller/D Gain'
 * '<S4>'   : 'SimplePIDController/PID Controller/Filter'
 * '<S5>'   : 'SimplePIDController/PID Controller/Filter ICs'
 * '<S6>'   : 'SimplePIDController/PID Controller/I Gain'
 * '<S7>'   : 'SimplePIDController/PID Controller/Ideal P Gain'
 * '<S8>'   : 'SimplePIDController/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'SimplePIDController/PID Controller/Integrator'
 * '<S10>'  : 'SimplePIDController/PID Controller/Integrator ICs'
 * '<S11>'  : 'SimplePIDController/PID Controller/N Copy'
 * '<S12>'  : 'SimplePIDController/PID Controller/N Gain'
 * '<S13>'  : 'SimplePIDController/PID Controller/P Copy'
 * '<S14>'  : 'SimplePIDController/PID Controller/Parallel P Gain'
 * '<S15>'  : 'SimplePIDController/PID Controller/Reset Signal'
 * '<S16>'  : 'SimplePIDController/PID Controller/Saturation'
 * '<S17>'  : 'SimplePIDController/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'SimplePIDController/PID Controller/Sum'
 * '<S19>'  : 'SimplePIDController/PID Controller/Sum Fdbk'
 * '<S20>'  : 'SimplePIDController/PID Controller/Tracking Mode'
 * '<S21>'  : 'SimplePIDController/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'SimplePIDController/PID Controller/postSat Signal'
 * '<S23>'  : 'SimplePIDController/PID Controller/preSat Signal'
 * '<S24>'  : 'SimplePIDController/PID Controller/Anti-windup/Passthrough'
 * '<S25>'  : 'SimplePIDController/PID Controller/D Gain/Internal Parameters'
 * '<S26>'  : 'SimplePIDController/PID Controller/Filter/Cont. Filter'
 * '<S27>'  : 'SimplePIDController/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S28>'  : 'SimplePIDController/PID Controller/I Gain/Internal Parameters'
 * '<S29>'  : 'SimplePIDController/PID Controller/Ideal P Gain/Passthrough'
 * '<S30>'  : 'SimplePIDController/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S31>'  : 'SimplePIDController/PID Controller/Integrator/Continuous'
 * '<S32>'  : 'SimplePIDController/PID Controller/Integrator ICs/Internal IC'
 * '<S33>'  : 'SimplePIDController/PID Controller/N Copy/Disabled'
 * '<S34>'  : 'SimplePIDController/PID Controller/N Gain/Internal Parameters'
 * '<S35>'  : 'SimplePIDController/PID Controller/P Copy/Disabled'
 * '<S36>'  : 'SimplePIDController/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S37>'  : 'SimplePIDController/PID Controller/Reset Signal/Disabled'
 * '<S38>'  : 'SimplePIDController/PID Controller/Saturation/Passthrough'
 * '<S39>'  : 'SimplePIDController/PID Controller/Saturation Fdbk/Disabled'
 * '<S40>'  : 'SimplePIDController/PID Controller/Sum/Sum_PID'
 * '<S41>'  : 'SimplePIDController/PID Controller/Sum Fdbk/Disabled'
 * '<S42>'  : 'SimplePIDController/PID Controller/Tracking Mode/Disabled'
 * '<S43>'  : 'SimplePIDController/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S44>'  : 'SimplePIDController/PID Controller/postSat Signal/Forward_Path'
 * '<S45>'  : 'SimplePIDController/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_SimplePIDController_h_ */
