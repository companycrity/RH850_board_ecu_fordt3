/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2018 Nexteer 
* Nexteer Confidential
*
* Module File Name  : FordMsg083BusHiSpdNonRte.c
* Module Description: FordMsg083BusHiSpdNonRte - MM054A
* Project           : CBD
* Author            : Sheeja R(TATA Elxsi)
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz3893 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                              SCR #
* --------  -------  --------  --------------------------------------------------------------------------  ------------
* 04/16/18   1       SR(TATA)  Initial version																EA4#20112 
* 05/03/18   2       BLS       Fix duplicate START_SEC_CODE for Memory Mapping                              EA4#23248
*----------------------------------------------------------------------------------------------------------------------
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
 /*********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Rte_FordMsg083BusHiSpd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */

#include "Appl_Cbk.h"
#include "Com_Cot.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#define FordMsg083BusHiSpd_START_SEC_CODE
#include "FordMsg083BusHiSpd_MemMap.h"

/******************************************** File-level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1] : AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*****************************************************************************
  * Name            : ComIPduCallout_Steering_Data_FD1_Oper
  * Description     : Implementation of ComIPduCallout_Steering_Data_FD1 subsystem in the model.
  * Inputs          : PduId, PduInfoPtr
  * Outputs         : Callback function return status always TRUE.
  * Usage Notes     : NA.
*****************************************************************************/
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_Steering_Data_FD1_Oper(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{    
	*Rte_Pim_FordVehMsg083Miss()  = FALSE;

	return TRUE;
}

/*****************************************************************************
  * Name            : ComTimeoutNotification_TurnLghtSwtch_D_Stat_Oper
  * Description     : Implementation of ComTimeoutNotification_TurnLghtSwtch_D_Stat subsystem in the model.
  * Inputs          : None.
  * Outputs         : None.
  * Usage Notes     : NA.
*****************************************************************************/
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TurnLghtSwtch_D_Stat_Oper(void)
{
	*Rte_Pim_FordVehMsg083Miss() = TRUE;
}

#define FordMsg083BusHiSpd_STOP_SEC_CODE
#include "FordMsg083BusHiSpd_MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 