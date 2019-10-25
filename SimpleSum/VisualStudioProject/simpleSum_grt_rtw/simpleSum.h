/*
 * simpleSum.h
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

#ifndef RTW_HEADER_simpleSum_h_
#define RTW_HEADER_simpleSum_h_
#include <string.h>
#include <stddef.h>
#ifndef simpleSum_COMMON_INCLUDES_
# define simpleSum_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* simpleSum_COMMON_INCLUDES_ */

#include "simpleSum_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T In1;                        /* '<Root>/In1' */
  real32_T In2;                        /* '<Root>/In2' */
} ExtU_simpleSum_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Out1;                       /* '<Root>/Out1' */
} ExtY_simpleSum_T;

/* Real-time Model Data Structure */
struct tag_RTM_simpleSum_T {
  const char_T *errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_simpleSum_T simpleSum_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_simpleSum_T simpleSum_Y;

/* Model entry point functions */
extern void simpleSum_initialize(void);
extern void simpleSum_step(void);
extern void simpleSum_terminate(void);

/* Real-time Model object */
extern RT_MODEL_simpleSum_T *const simpleSum_M;

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
 * '<Root>' : 'simpleSum'
 */
#endif                                 /* RTW_HEADER_simpleSum_h_ */


#ifndef WRAPPER_API
#define WRAPPER_API __declspec(dllexport) 
#else
#define WRAPPER_API __declspec(dllimport) 
#endif

WRAPPER_API void initialize(void);
WRAPPER_API void step(void);
WRAPPER_API void set_inputs(real32_T _in1, real32_T _in2);
WRAPPER_API real32_T get_output();

