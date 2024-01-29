/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Stack  Stack
 *  \brief       Call Stack functionality.
 *  \details
 *
 *  This module provides two stack based functionalities:
 *
 *  - **Stack Measurement**:
 *  Stack Measurment provides an API to the costumer, which returns the maximum occurred stack usage of a task/ISR/hook.
 *  On initialization each stack is filled with a pattern beginning at the current stack pointer address.
 *  The unused stack size is determined by counting the number of consecutive fill pattern bytes, beginning
 *  at the end of the stack. The difference between the unused stack size and the total stack size equals
 *  the number of stack bytes which where used at most.
 *  - **Stack Monitoring**:
 *  The last element of the stack is filled with a stack pattern. On every stack switch, the stack check API
 *  is called, in order to verify, that the pattern is still unchanged.
 *
 *  As the stack growing direction and the stack pointer position may differ between various platforms,
 *  a general wording is defined (see \ref GlossaryStackWording).
 *
 *
 *  \see \ref Stack
 *  \see \ref GlossaryStackWording
 *
 *
 *  \note 89394-ESCAN  Usage of StackUsage API may lead to deadlock situation if stack of a foreign core is checked
 *                     and caller has interrupts disabled.
 *  \note 89395-ESCAN  StackUsage API missing for Non-Trusted Function Stacks.
 *
 *  \{
 *
 *  \file
 *  \brief       Call stack definitions.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#if !defined(OS_STACKINT_H)                                                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACKINT_H


/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"
# include "Os_Stack_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_ErrorInt.h"
# include "Os_Task_Types.h"
# include "Os_Isr_Types.h"
# include "Os_Core_Types.h"

/* Os Hal dependencies */
# include "Os_Hal_CoreInt.h"


#if !defined(OS_VCAST_INSTRUMENTATION_OS_STACK)
/*VCAST_DONT_INSTRUMENT_START*/
#endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Defines whether any stack feature is active (STD_ON) or not (STD_OFF). */
# if ((OS_CFG_STACKMONITORING == STD_ON) || (OS_CFG_STACKMEASUREMENT == STD_ON))
#  define OS_CFG_STACKMODULE           STD_ON
# else
#  define OS_CFG_STACKMODULE           STD_OFF
# endif


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! General stack representation. */
struct Os_StackConfigType_Tag
{
  /*! First writable address. */
  P2VAR(Os_Hal_StackType, TYPEDEF, OS_VAR_NOINIT) LowAddress;
  /*! Last writable address. */
  P2VAR(Os_Hal_StackType, TYPEDEF, OS_VAR_NOINIT) HighAddress;
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */


/***********************************************************************************************************************
 *  Os_StackIsModuleEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether stack module is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Stack measurement is enabled.
 *  \retval       0     Stack measurement is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_StackIsModuleEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_StackIsMeasurementEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether stack measurement is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Stack measurement is enabled.
 *  \retval       0     Stack measurement is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_StackIsMeasurementEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_StackIsMonitoringEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether stack monitoring is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Stack monitoring is enabled.
 *  \retval       0     Stack monitoring is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_StackIsMonitoringEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_StackInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given stack.
 *  \details
 *  The kernel uses this function to provide:
 *  - Stack usage measurement
 *  - Stack monitoring
 *  This function is called in Init-Step3 and Init-Step4 in order to handle the situation that Init-Step3 is optional.
 *
 *  \param[in,out]  Stack           The stack which shall be initialized
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different stacks.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_StackInit,
(
  P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) Stack
));


/***********************************************************************************************************************
 *  Os_StackGetThreadStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current stack usage of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread           The owner thread of the stack to query.
 *
 *  \return       Stack usage in bytes.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given object pointer(s) are valid.
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetThreadStackUsage
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
);


/***********************************************************************************************************************
 *  Os_StackOverflowCheck()
 **********************************************************************************************************************/
/*! \brief        Check whether the given stack has overflowed.
 *  \details
 *  The kernel uses this function to provide stack monitoring.
 *
 *  \param[in]    Stack           The stack to query.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given object pointer(s) are valid.
 *
 *  \trace        CREQ-88
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_StackOverflowCheck,
(
  P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST) Stack
));


/***********************************************************************************************************************
 *  Os_Api_GetTaskStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current stack usage of the given task.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    TaskID        The task which shall be queried.
 *
 *  \return       Current stack usage of the given task in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetTaskStackUsage
(
  TaskType TaskID
);


/***********************************************************************************************************************
 *  Os_Api_GetISRStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current stack usage of the given ISR.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    IsrID         The ISR which shall be queried.
 *
 *  \return       Current stack usage of the given ISR in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetISRStackUsage
(
  ISRType IsrID
);


/***********************************************************************************************************************
 *  Os_Api_GetKernelStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current kernel stack usage on the given core.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current kernel stack usage on the given core in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetKernelStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_Api_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current startup hook stack usage on the given core.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current startup hook stack usage on the given core in bytes.
 *
 *  \retval       OS_STATUS_OK                  No Error.
 *  \retval       OS_STATUS_ID_1                (EXTENDED status:) Passed is not a valid ID.
 *  \retval       OS_STATUS_ID_TYPE_1           (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *  \retval       OS_STATUS_HOOK_NOT_AVAILABLE  (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetStartupHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_Api_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current error hook stack usage on the given core.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current error hook stack usage on the given core in bytes.
 *
 *  \retval       OS_STATUS_OK                  No Error.
 *  \retval       OS_STATUS_ID_1                (EXTENDED status:) Passed is not a valid ID.
 *  \retval       OS_STATUS_ID_TYPE_1           (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *  \retval       OS_STATUS_HOOK_NOT_AVAILABLE  (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetErrorHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_Api_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current shutdown hook stack usage on the given core.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current shutdown hook stack usage on the given core in bytes.
 *
 *  \retval       OS_STATUS_OK                  No Error.
 *  \retval       OS_STATUS_ID_1                (EXTENDED status:) Passed is not a valid ID.
 *  \retval       OS_STATUS_ID_TYPE_1           (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *  \retval       OS_STATUS_HOOK_NOT_AVAILABLE  (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetShutdownHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_Api_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current protection hook stack usage on the given core.
 *  \details
 *  (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current protection hook stack usage on the given core in bytes.
 *
 *  \retval       OS_STATUS_OK                  No Error.
 *  \retval       OS_STATUS_ID_1                (EXTENDED status:) Passed is not a valid ID.
 *  \retval       OS_STATUS_ID_TYPE_1           (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *  \retval       OS_STATUS_HOOK_NOT_AVAILABLE  (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-159, CREQ-40, CREQ-261
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_GetProtectionHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_StackGetTaskStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Task         The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetTaskStackUsageLocal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_StackGetISRStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Isr           The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetISRStackUsageLocal
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
);


/***********************************************************************************************************************
 *  Os_StackGetKernelStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Core         The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetKernelStackUsageLocal
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
);


/***********************************************************************************************************************
 *  Os_StackGetStartupHookStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Core        The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given core has a startup hook configured.
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetStartupHookStackUsageLocal
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
);


/***********************************************************************************************************************
 *  Os_StackGetErrorHookStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Core        The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given core has a error hook configured.
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetErrorHookStackUsageLocal
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
);


/***********************************************************************************************************************
 *  Os_StackGetShutdownHookStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Core        The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given core has a shutdown hook configured.
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetShutdownHookStackUsageLocal
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
);


/***********************************************************************************************************************
 *  Os_StackGetProtectionHookStackUsageLocal()
 **********************************************************************************************************************/
/*! \brief        Get the stack of the object allocated to the current core.
 *  \details      --no details--
 *
 *  \param[in]    Core        The core which shall be queried.
 *
 *  \return       The stack usage.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given core has a protection hook configured.
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_StackGetProtectionHookStackUsageLocal
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(OS_VCAST_INSTRUMENTATION_OS_STACK)
/*VCAST_DONT_INSTRUMENT_END*/
#endif

#endif /* OS_STACKINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_StackInt.h
 **********************************************************************************************************************/
