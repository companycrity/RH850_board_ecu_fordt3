/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Timer Timer
 *  \brief       High level timer hardware handling.
 *  \details
 *  This module provides abstraction from the functionality of different timer types:
 *   - Software timer (SW counter)
 *   - Periodic interval timer
 *   - High Resolution Timer / Free running timer
 *
 *  Timer ISR
 *  ---------
 *  The OS provided timer ISR is implemented by using a category 2 ISR.
 *
 *  ![Timer ISR](Timer_TimerIsr.png)
 *
 *  ![PIT timer interrupt handling](Timer_TimerIsr_Pit.png)
 *
 *  ![HRT timer interrupt handling](Timer_TimerIsr_Hrt.png)
 *
 *
 *  \{
 *
 *  \file
 *  \brief       Interface to high level timer hardware handling.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#if !defined(OS_TIMERINT_H)                                                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TIMERINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Timer_Types.h"

/* Os kernel module dependencies */
# include "Os_Counter_Types.h"
# include "Os_CounterInt.h"
# include "Os_Common_Types.h"
# include "Os_IsrInt.h"

/* Os HAL dependencies */
# include "Os_Hal_TimerInt.h"

#if !defined(OS_VCAST_INSTRUMENTATION_OS_TIMER)
/*VCAST_DONT_INSTRUMENT_START*/
#endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! \def        OS_TIMERSW_GETMAXCOUNTINGVALUE()
 *  \brief      This macro is used to calculate the maximum counting value for a software counter.
 *  \details    This value is needed for modulo calculation.
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERSW_GETMAXCOUNTINGVALUE(MaxAllowedValue)                                                              \
    ((((Os_TickType)(MaxAllowedValue))*2)+1)                                                                            /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! \def        OS_TIMERPIT_GETMAXCOUNTINGVALUE()
 *  \brief      This macro is used to calculate the maximum counting value for a PIT.
 *  \details    This value is needed for modulo calculation.
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERPIT_GETMAXCOUNTINGVALUE(MaxAllowedValue)                                                             \
      OS_TIMERSW_GETMAXCOUNTINGVALUE((MaxAllowedValue))                                                                 /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! \def        OS_TIMERHRT_GETMAXCOUNTINGVALUE()
 *  \brief      This macro is used to calculate the maximum counting value for a HRT.
 *  \details    This value is needed for modulo calculation.
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERHRT_GETMAXCOUNTINGVALUE(MaxAllowedValue)                                                             \
  ((((Os_TickType)(MaxAllowedValue))*4)+3)                                                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! \def        OS_TIMERSW_GETMAXDIFFERENTIALVALUE()
 *  \brief      This macro is used to calculate the maximum differential value between two software timer values.
 *  \details    --no details--
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERSW_GETMAXDIFFERENTIALVALUE(MaxAllowedValue)                                                          \
      ((Os_TickType)(MaxAllowedValue))                                                                                  /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! \def        OS_TIMERPIT_GETMAXDIFFERENTIALVALUE()
 *  \brief      This macro is used to calculate the maximum differential value between two PIT values.
 *  \details    --no details--
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERPIT_GETMAXDIFFERENTIALVALUE(MaxAllowedValue)                                                         \
      (OS_TIMERSW_GETMAXDIFFERENTIALVALUE((MaxAllowedValue)))                                                           /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! \def        OS_TIMERHRT_GETMAXDIFFERENTIALVALUE()
 *  \brief      This macro is used to calculate the maximum differential value between two HRT values.
 *  \details    --no details--
 *
 *  \param[in]  MaxAllowedValue   Max allowed value of the counter.
 */
# define  OS_TIMERHRT_GETMAXDIFFERENTIALVALUE(MaxAllowedValue)                                                         \
      ((((Os_TickType)(MaxAllowedValue))*2)+1)                                                                          /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! Type cast from Os_TimerIsrConfigType to Os_IsrConfigType by use of base element addressing.
 * \note Spell correction in the next implementation phase: OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR ->
 *                                                          OS_TIMER_CASTCONFIG_TIMERISR_2_ISR       */
#define OS_TIMER_CASTCONFIG_TIMEREISR_2_ISR(timer)        (&((timer).Isr))                                              /* PRQA S 3453 */ /* MD_MSR_19.7 */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Dynamic information of a software counter. */
typedef struct
{
  /*! The current counter value of the software counter. */
  Os_TickType Value;

  /*! The next time stamp where Os_CounterWorkJobs() has to be called. */
  Os_TickType Compare;
} Os_TimerSwType;



/*! Timer configuration for software counters.
 *  \extends Os_CounterConfigType_Tag
 */
struct Os_TimerSwConfigType_Tag
{
  /*! General counter.
   * This attribute must come first! */
  Os_CounterConfigType Counter;

  /*! Dynamic part of the software counter. */
  P2VAR(Os_TimerSwType, TYPEDEF, OS_VAR_NOINIT) Dyn;
};



/*! Configuration information of a PIT driven hardware counter.
 *  \extends Os_TimerSwConfigType_Tag
 */
struct Os_TimerPitConfigType_Tag
{
  /*! Software counter.
   * This attribute must come first! */
  Os_TimerSwConfigType SwCounter;

  /*! Hardware specific information of the PIT. */
  P2CONST(Os_Hal_TimerPitConfigType, TYPEDEF, OS_CONST) HwConfig;
};



/*! Dynamic information of a (range extended) HRT driven hardware counter. */
typedef struct
{
  /*! A snapshot of the range extended counter value.
   * The current value is calculated each time in Os_TimerHrtGetValue(). */
  Os_TickType Value;

  /*! The next time stamp where Os_CounterWorkJobs() has to be called. */
  Os_TickType Compare;

  /*! Time value mask. Set to 0 on timer initialization, set to MaxCountingValue on timer start.
   *  Used to keep the Value field at zero until the timer is started by Os_TimerHrtStart() */
  Os_TickType ValueMask;

  /*! Time stamp of the last hardware counter read. */
  Os_Hal_TimerFrtTickType LastCounterValue;

  /*! \brief    The deviation between TickType values and FrtTickType values.
   *  \details  This value has to be added when converting a TickType value into a FRT TickType value. */
  Os_Hal_TimerFrtTickType HwTimeAtLogicalZero;

} Os_TimerHrtType;



/*! Timer configuration of a (software extended) HRT driven hardware counter.
 *  \extends Os_CounterConfigType_Tag
 */
struct Os_TimerHrtConfigType_Tag
{
  /*! General counter.
   * This attribute must come first! */
  Os_CounterConfigType Counter;

  /*! Dynamic information. */
  P2VAR(Os_TimerHrtType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! Hardware specific information of the FRT. */
  P2CONST(Os_Hal_TimerFrtConfigType, TYPEDEF, OS_CONST) HwConfig;
};


/*! Configuration information of a timer ISR.
 *  \extends Os_IsrConfigType_Tag */
struct Os_TimerIsrConfigType_Tag
{
  /*! The timer ISR which is responsible for the counter. */
  Os_IsrConfigType Isr;

  /*! The hardware counter, which triggers the timer ISR. */
  P2CONST(Os_CounterConfigType, TYPEDEF, OS_CONST) Counter;
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
 *  Os_TimerSwInit()
 **********************************************************************************************************************/
/*! \brief          Initializes a software timer.
 *  \details        Initialize counter value to zero. The function is called in Init-Step4. In case the timer is used
 *                  for timing protection, it is also called in Init-Step3.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerSwInit,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerPitInit()
 **********************************************************************************************************************/
/*! \brief          Initializes a PIT driven counter.
 *  \details        Initialize software counter value and PIT hardware. The function is called in Init-Step4. In case
 *                  the timer is used for timing protection, it is also called in Init-Step3.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerPitInit,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerHrtInit()
 **********************************************************************************************************************/
/*! \brief          Initializes HRT driven counter.
 *  \details        Initialize HRT hardware and the software part for range extension. The function is called in
 *                  Init-Step4. In case the timer is used for timing protection, it is also called in Init-Step3.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtInit,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));



/***********************************************************************************************************************
 *  Os_TimerSwStart()
 **********************************************************************************************************************/
/*! \brief          Starts a software timer.
 *  \details        There is nothing to be done for starting a software timer. Therefore, no preconditions.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerSwStart,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerPitStart()
 **********************************************************************************************************************/
/*! \brief          Starts a PIT driven counter.
 *  \details        Initialize the PIT hardware.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerPitStart,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerHrtStart()
 **********************************************************************************************************************/
/*! \brief          Starts a HRT driven counter.
 *  \details        Initialize HRT hardware.
 *
 *  \param[in,out]  Timer           The timer to initialize.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtStart,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerSwGetValue()
 **********************************************************************************************************************/
/*! \brief          Returns the current counter value of a software timer.
 *  \details
 *
 *  \param[in,out]  Timer           The timer to query.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given timer shall be prevented, if processor word width is smaller than
 *                  with of Os_TickType.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerSwGetValue,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerSwSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Sets the compare value variable of a software timer.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to modify.
 *  \param[in]      ExpirationTime  The time stamp, which defines when the timer shall call Os_CounterWorkJobs().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerSwSetCompareValue,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_TimerSwUserModulo()
 **********************************************************************************************************************/
/*! \brief          Performs Value = Value mod MaxAllowedValue.
 *  \details        Because the modulo operator (%) is assumed to be inefficient, an optimized modulo function is used,
 *                  which has the assumption on the parameter Value as defined in the precondition. The optimization
 *                  is to simply subtract MaxAllowedValue+1 in case the value is bigger than MaxAllowedValue.
 *
 *  ![Visualization](SoftwareCounterModulo.png)
 *
 *  \param[in]      Timer     The timer to query.
 *  \param[in]      Value     The value to be limited.
 *
 *  \return         The limited value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Value has to be in range 0 <= Value <= MaxCountingValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerSwUserModulo,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_TimerSwIncrement()
 **********************************************************************************************************************/
/*! \brief          Increment a given software timer.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to be incremented.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Timer belongs to the local core.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TimerSwIncrement
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
);


/***********************************************************************************************************************
 *  Os_TimerPitGetValue()
 **********************************************************************************************************************/
/*! \brief          Returns the current counter value of a PIT driven counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to query.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given timer shall be prevented, if processor word width is smaller than
 *                  with of Os_TickType.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerPitGetValue,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerPitSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Sets the compare value variable of a PIT driven counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to modify.
 *  \param[in]      ExpirationTime  The time stamp, which defines when the timer shall call Os_CounterWorkJobs().
 *
 *  \retval         !0  ExpirationTime is in the past or now.
 *  \retval         0   ExpirationTime is in the future.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerPitSetCompareValue,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_TimerPitUserModulo()
 **********************************************************************************************************************/
/*! \brief          Performs Value = Value mod MaxAllowedValue.
 *  \details        Use modulo function for software timer.
 *
 *  \param[in]      Timer     The counter to query.
 *  \param[in]      Value     The value to be limited.
 *
 *  \return         The limited value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Value has to be in range -MaxAllowedValue <= Value <= MaxCountingValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerPitUserModulo,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_TimerHrtGetValue()
 **********************************************************************************************************************/
/*! \brief          Returns the current value of a high resolution timer driven counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to query.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The ValueMask of the given counter is zero or the maximum possible value in TickType
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtGetValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerHrtGetCounter()
 **********************************************************************************************************************/
/*! \brief          Returns the counter of the given timer.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to query.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TimerHrtGetCounter,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerHrtTickType2FrtTickType()
 **********************************************************************************************************************/
/*! \brief          Converts the given TickType into a FrtTickType.
 *  \details        --no details--
 *
 *  \param[in]      Timer           The timer to query.
 *  \param[in]      Value           The TickType into a FrtTickType value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtTickType2FrtTickType,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_TimerHrtSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Sets the compare value of a HRT driven counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to modify.
 *  \param[in]      ExpirationTime  The time stamp, where the next interrupt shall occur.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            ExpirationTime-Now is in range -MaxAllowedValue to +MaxAllowedValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerHrtSetCompareValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_TimerHrtGetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Get the compare value of a HRT driven counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Timer           The timer to modify.
 *
 *  \return         The next expiration time.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different timers.
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtGetCompareValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));


/***********************************************************************************************************************
 *  Os_TimerHrtUserModulo()
 **********************************************************************************************************************/
/*! \brief          Performs Value = Value mod MaxAllowedValue.
 *  \details        Cut off bits which are beyond MaxAllowedValue.
 *
 *  ![Visualization](HrtCounterModulo.png)
 *
 *  \param[in]      Timer     The timer to query.
 *  \param[in]      Value     The value to be limited.
 *
 *  \return         The limited value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 *  \pre            MaxAllowedValue is 2^(n)-1.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerHrtUserModulo,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_TimerHrtAcknowledge()
 **********************************************************************************************************************/
/*! \brief          Acknowledges a HRT timer interrupt.
 *  \details        --no details--
 *
 *  \param[in]      Timer     The timer to acknowledge.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given object pointer(s) are valid.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_3219 */
Os_TimerHrtAcknowledge,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
));



/***********************************************************************************************************************
 *  Os_TimerSwAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
/*! \brief        Converts an absolute counter time stamp into an absolute SW timer time stamp.
 *  \details      As there are two counter cycles within one SW Timer cycle, the counter value may be mapped to
 *                two different timer values:
 *
 *                  timerValue = CounterValue + n*(MaxAllowedValue+1) with n={0,1}
 *
 *                   Cycle             |   Value range
 *                   ------------------|-----------------
 *                   First cycle       |  0 .. MaxAllowedValue
 *                   Second cycle      |  MaxAllowedValue+1 .. 2*MaxAllowedValue+1
 *
 *                As a consequence of #40 and #60, the expiry time will be reached up to MaxAllowedValue+1 ticks
 *                ahead of Now. So this function must not be called while still jobs for Now are in the job queue!
 *
 *  \param[in]    MaxAllowedValue   The maximum value allowed value for CounterValue.
 *  \param[in]    Now               The current timer value.
 *  \param[in]    CounterValue      The counter value which shall be converted.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given CounterValue is in range 0..MaxAllowedValue of the respective counter configuration.
 *  \pre          Now is lower than or equal to MaxCountingValue.
 *  \pre          All jobs which have to expire Now have already been removed from the job queue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerSwAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType Now,
  Os_TickType CounterValue
));


/***********************************************************************************************************************
 *  Os_TimerPitAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
/*! \brief        Converts an absolute counter time stamp into an absolute PIT timer time stamp.
 *  \details      Bypass conversion to Os_TimerSwAbsCounter2AbsTimerValue().
 *
 *  \param[in]    MaxAllowedValue   The maximum value allowed value for CounterValue.
 *  \param[in]    Now               The current timer value.
 *  \param[in]    CounterValue      The counter value which shall be converted.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given CounterValue is in range 0..MaxAllowedValue of the respective counter configuration.
 *  \pre          Now is lower than or equal to MaxCountingValue.
 *  \pre          All jobs which have to expire Now have already been removed from the job queue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerPitAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType Now,
  Os_TickType CounterValue
));


/***********************************************************************************************************************
 *  Os_TimerHrtAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
/*! \brief        Converts an absolute counter time stamp into an absolute HRT timer time stamp.
 *  \details      As there are four counter cycles within one (E)HRT cycle, the counter value may be mapped to
 *                four different timer values. The two MSbs of the timer value represent the timer cycle,
 *                the LSbs represent the counter value.
 *
 *                timerValue = |n|CounterValue|; // Bit mapping
 *                or
 *                timerValue = n*counterPeriode + CounterValue  with n={0,..,3}
 *
 *                Where n equals the upper two bits of the timerValue.
 *
 *  \param[in]    MaxAllowedValue   The maximum value allowed value for CounterValue.
 *  \param[in]    MaxCountingValue  The max. value of the underlying timer.
 *  \param[in]    Now               The current timer value.
 *  \param[in]    CounterValue      The counter value which shall be converted.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given CounterValue is in range 0..MaxAllowedValue
 *  \pre          MaxAllowedValue must be (2^n)-1, where n is a native number and MaxAllowedValue <= Max(TickType)/4.
 *  \pre          MaxCountingValue must be (2^n)-1, where n is a native number and MaxCountingValue <= Max(TickType)/2.
 *  \pre          Now is lower than or equal to MaxCountingValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TimerHrtAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType MaxCountingValue,
  Os_TickType Now,
  Os_TickType CounterValue
));



/***********************************************************************************************************************
 *  Os_TimerAdd()
 **********************************************************************************************************************/
/*! \brief          Performs Value = (Value+Add) mod MaxCountingValue+1.
 *  \details        --no details--
 *
 *  ![Visualization](TimerAdd.png)
 *
 *  \param[in]      MaxAllowedValue       The MaxAllowedValue of the underlying counter.
 *  \param[in]      MaxCountingValue      The counting limit of the underlying timer.
 *  \param[in]      Value                 A timer value.
 *  \param[in]      Add                   The counter value to be added.
 *
 *  \return         The limited value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Value has to be in range 0 <= Value <= MaxCountingValue.
 *  \pre            Add has to be in range 0 <= Add   <= MaxAllowedValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerAdd,
(
  Os_TickType MaxAllowedValue,
  Os_TickType MaxCountingValue,
  Os_TickType Value,
  Os_TickType Add
));


/***********************************************************************************************************************
 *  Os_TimerSub()
 **********************************************************************************************************************/
/*! \brief          Performs Value = (Value-Sub) mod MaxCountingValue+1.
 *  \details        --no details--
 *
 *  ![Visualization](TimerSub.png)
 *
 *  \param[in]      MaxAllowedValue       The MaxAllowedValue of the underlying counter.
 *  \param[in]      MaxCountingValue      The counting limit of the underlying timer.
 *  \param[in]      Value                 A timer value.
 *  \param[in]      Sub                   The counter value to be subtracted.
 *
 *  \return         The limited value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Value has to be in range 0 <= Value <= MaxCountingValue.
 *  \pre            Value has to be in range 0 <= Sub   <= MaxAllowedValue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerSub,
(
  Os_TickType MaxAllowedValue,
  Os_TickType MaxCountingValue,
  Os_TickType Value,
  Os_TickType Sub
));


/***********************************************************************************************************************
 *  ISR(Os_TimerPitIsr)
 **********************************************************************************************************************/
/*! \brief        ISR for PIT timers.
 *  \details
 *  This ISR drives a PIT hardware counter.
 *  The ISR acknowledges the hardware timer and increments the underlying software counter value.
 *  The counter will check, whether there are expired jobs and work them off.
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE, for different timers.
 *  \synchronous  TRUE
 *
 *  \pre          Timer belongs to the local core.
 *  \pre          Timer is a PIT counter.
 **********************************************************************************************************************/
ISR(Os_TimerPitIsr);


/***********************************************************************************************************************
 *  ISR(Os_TimerHrtIsr)
 **********************************************************************************************************************/
/*! \brief        ISR for HRT timers.
 *  \details
 *  This ISR drives a HRT hardware counter.
 *  This ISR acknowledges the hardware timer and informs the counter to work off expired jobs.
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE, for different timers.
 *  \synchronous  TRUE
 *
 *  \pre          Timer belongs to the local core.
 *  \pre          Timer is a HRT counter.
 **********************************************************************************************************************/
ISR(Os_TimerHrtIsr);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if !defined(OS_VCAST_INSTRUMENTATION_OS_TIMER)
/*VCAST_DONT_INSTRUMENT_END*/
#endif

#endif /* OS_TIMERINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_TimerInt.h
 **********************************************************************************************************************/
