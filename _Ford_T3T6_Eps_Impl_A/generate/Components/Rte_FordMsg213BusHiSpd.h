/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_FordMsg213BusHiSpd.h
 *        Config:  EPS.dpa
 *   ECU-Project:  PSCM_FD
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1601056 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <FordMsg213BusHiSpd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_FORDMSG213BUSHISPD_H
# define _RTE_FORDMSG213BUSHISPD_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_FordMsg213BusHiSpd_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_FordMsg213BusHiSpd_FordVehAbsActv_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_FordMsg213BusHiSpd_FordVehAbsEscStsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDenied_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisad_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_FordMsg213BusHiSpd_FordVehEscActv_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_DiagcMgr_ClrDiagcFlgProxy_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordBrkPlsRejctnEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_FordCanDtcInhb_FordCanDtcInhb_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_FordCanDtcInhb_FordEpsLifeCycMod_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordEvasSteerAssiEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordLaneCentrAssiEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordLaneDprtrWarnEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordLaneKeepAssiEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CustDiag_FordTrfcJamAssiEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ClrDiagcFlgProxy_Val (0U)
#  define Rte_InitValue_FordBrkOscnRednEnad_Logl (FALSE)
#  define Rte_InitValue_FordCanDtcInhb_Logl (TRUE)
#  define Rte_InitValue_FordEpsLifeCycMod_Val (0U)
#  define Rte_InitValue_FordEvasSteerAssiEnad_Logl (FALSE)
#  define Rte_InitValue_FordLaneCentrAssiEnad_Logl (FALSE)
#  define Rte_InitValue_FordLaneDetnWarnEnad_Logl (FALSE)
#  define Rte_InitValue_FordLkaEnad_Logl (FALSE)
#  define Rte_InitValue_FordTrfcJamAssiEnad_Logl (FALSE)
#  define Rte_InitValue_FordVehAbsActv_Val (0U)
#  define Rte_InitValue_FordVehAbsEscStsVld_Logl (FALSE)
#  define Rte_InitValue_FordVehCllsnMtgtnByBrkgDenied_Val (0U)
#  define Rte_InitValue_FordVehCllsnMtgtnByBrkgDisad_Val (0U)
#  define Rte_InitValue_FordVehEscActv_Val (0U)
#  define Rte_InitValue_Ford_AbsActv_B_Actl_Ford_AbsActv_B_Actl (FALSE)
#  define Rte_InitValue_Ford_CmbbBrkDis_B_Actl_Ford_CmbbBrkDis_B_Actl (FALSE)
#  define Rte_InitValue_Ford_CmbbDeny_B_ActlBrk_Ford_CmbbDeny_B_ActlBrk (FALSE)
#  define Rte_InitValue_Ford_StabCtlBrkActv_B_Actl_Ford_StabCtlBrkActv_B_Actl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ClrDiagcFlgProxy_Val Rte_Read_FordMsg213BusHiSpd_ClrDiagcFlgProxy_Val
#  define Rte_Read_FordMsg213BusHiSpd_ClrDiagcFlgProxy_Val(data) (*(data) = Rte_DiagcMgr_ClrDiagcFlgProxy_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordBrkOscnRednEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordBrkOscnRednEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordBrkOscnRednEnad_Logl(data) (*(data) = Rte_CustDiag_FordBrkPlsRejctnEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordCanDtcInhb_Logl Rte_Read_FordMsg213BusHiSpd_FordCanDtcInhb_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordCanDtcInhb_Logl(data) (*(data) = Rte_FordCanDtcInhb_FordCanDtcInhb_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordEpsLifeCycMod_Val Rte_Read_FordMsg213BusHiSpd_FordEpsLifeCycMod_Val
#  define Rte_Read_FordMsg213BusHiSpd_FordEpsLifeCycMod_Val(data) (*(data) = Rte_FordCanDtcInhb_FordEpsLifeCycMod_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordEvasSteerAssiEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordEvasSteerAssiEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordEvasSteerAssiEnad_Logl(data) (*(data) = Rte_CustDiag_FordEvasSteerAssiEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordLaneCentrAssiEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordLaneCentrAssiEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordLaneCentrAssiEnad_Logl(data) (*(data) = Rte_CustDiag_FordLaneCentrAssiEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordLaneDetnWarnEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordLaneDetnWarnEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordLaneDetnWarnEnad_Logl(data) (*(data) = Rte_CustDiag_FordLaneDprtrWarnEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordLkaEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordLkaEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordLkaEnad_Logl(data) (*(data) = Rte_CustDiag_FordLaneKeepAssiEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FordTrfcJamAssiEnad_Logl Rte_Read_FordMsg213BusHiSpd_FordTrfcJamAssiEnad_Logl
#  define Rte_Read_FordMsg213BusHiSpd_FordTrfcJamAssiEnad_Logl(data) (*(data) = Rte_CustDiag_FordTrfcJamAssiEnad_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Ford_AbsActv_B_Actl_Ford_AbsActv_B_Actl Rte_Read_FordMsg213BusHiSpd_Ford_AbsActv_B_Actl_Ford_AbsActv_B_Actl
#  define Rte_Read_FordMsg213BusHiSpd_Ford_AbsActv_B_Actl_Ford_AbsActv_B_Actl(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_AbsActv_B_Actl_eaa4779a, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Ford_CmbbBrkDis_B_Actl_Ford_CmbbBrkDis_B_Actl Rte_Read_FordMsg213BusHiSpd_Ford_CmbbBrkDis_B_Actl_Ford_CmbbBrkDis_B_Actl
#  define Rte_Read_FordMsg213BusHiSpd_Ford_CmbbBrkDis_B_Actl_Ford_CmbbBrkDis_B_Actl(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_CmbbBrkDis_B_Actl_eaa4779a, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Ford_CmbbDeny_B_ActlBrk_Ford_CmbbDeny_B_ActlBrk Rte_Read_FordMsg213BusHiSpd_Ford_CmbbDeny_B_ActlBrk_Ford_CmbbDeny_B_ActlBrk
#  define Rte_Read_FordMsg213BusHiSpd_Ford_CmbbDeny_B_ActlBrk_Ford_CmbbDeny_B_ActlBrk(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_CmbbDeny_B_ActlBrk_eaa4779a, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Ford_StabCtlBrkActv_B_Actl_Ford_StabCtlBrkActv_B_Actl Rte_Read_FordMsg213BusHiSpd_Ford_StabCtlBrkActv_B_Actl_Ford_StabCtlBrkActv_B_Actl
#  define Rte_Read_FordMsg213BusHiSpd_Ford_StabCtlBrkActv_B_Actl_Ford_StabCtlBrkActv_B_Actl(data) ((void)Com_ReceiveSignal(ComConf_ComSignal_StabCtlBrkActv_B_Actl_eaa4779a, (data)), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_FordVehAbsActv_Val Rte_Write_FordMsg213BusHiSpd_FordVehAbsActv_Val
#  define Rte_Write_FordMsg213BusHiSpd_FordVehAbsActv_Val(data) (Rte_FordMsg213BusHiSpd_FordVehAbsActv_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FordVehAbsEscStsVld_Logl Rte_Write_FordMsg213BusHiSpd_FordVehAbsEscStsVld_Logl
#  define Rte_Write_FordMsg213BusHiSpd_FordVehAbsEscStsVld_Logl(data) (Rte_FordMsg213BusHiSpd_FordVehAbsEscStsVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FordVehCllsnMtgtnByBrkgDenied_Val Rte_Write_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDenied_Val
#  define Rte_Write_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDenied_Val(data) (Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDenied_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FordVehCllsnMtgtnByBrkgDisad_Val Rte_Write_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisad_Val
#  define Rte_Write_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisad_Val(data) (Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisad_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_FordVehEscActv_Val Rte_Write_FordMsg213BusHiSpd_FordVehEscActv_Val
#  define Rte_Write_FordMsg213BusHiSpd_FordVehEscActv_Val(data) (Rte_FordMsg213BusHiSpd_FordVehEscActv_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_FordMsg213BusHiSpdAbsActvVldFaildThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->FordMsg213BusHiSpdAbsActvVldFaildThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FordMsg213BusHiSpdAbsActvVldPassdThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->FordMsg213BusHiSpdAbsActvVldPassdThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FordMsg213BusHiSpdEvasSteerAssiEnadThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->FordMsg213BusHiSpdEvasSteerAssiEnadThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FordMsg213BusHiSpdMissMsgFaildThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->FordMsg213BusHiSpdMissMsgFaildThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FordMsg213BusHiSpdMissMsgPassdThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->FordMsg213BusHiSpdMissMsgPassdThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_AbsActvVldFaildRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_AbsActvVldPassdRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_MissMsgFaildRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_MissMsgPassdRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_ClrDiagcFlgProxyPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehAbsActvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDeniedPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisadPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehEscActvPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FirstTranVldFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehAbsEscStsVldPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_FordMsg213BusHiSpd_FordVehMsg213Miss; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_AbsActvVldFaildRefTi() \
  (&Rte_FordMsg213BusHiSpd_AbsActvVldFaildRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AbsActvVldPassdRefTi() \
  (&Rte_FordMsg213BusHiSpd_AbsActvVldPassdRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgFaildRefTi() \
  (&Rte_FordMsg213BusHiSpd_MissMsgFaildRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgPassdRefTi() \
  (&Rte_FordMsg213BusHiSpd_MissMsgPassdRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ClrDiagcFlgProxyPrev() \
  (&Rte_FordMsg213BusHiSpd_ClrDiagcFlgProxyPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehAbsActvPrev() \
  (&Rte_FordMsg213BusHiSpd_FordVehAbsActvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehCllsnMtgtnByBrkgDeniedPrev() \
  (&Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDeniedPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehCllsnMtgtnByBrkgDisadPrev() \
  (&Rte_FordMsg213BusHiSpd_FordVehCllsnMtgtnByBrkgDisadPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehEscActvPrev() \
  (&Rte_FordMsg213BusHiSpd_FordVehEscActvPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FirstTranVldFlg() \
  (&Rte_FordMsg213BusHiSpd_FirstTranVldFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehAbsEscStsVldPrev() \
  (&Rte_FordMsg213BusHiSpd_FordVehAbsEscStsVldPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FordVehMsg213Miss() \
  (&Rte_FordMsg213BusHiSpd_FordVehMsg213Miss) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define FordMsg213BusHiSpd_START_SEC_CODE
# include "FordMsg213BusHiSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_FordMsg213BusHiSpdInit1 FordMsg213BusHiSpdInit1
#  define RTE_RUNNABLE_FordMsg213BusHiSpdPer1 FordMsg213BusHiSpdPer1
# endif

FUNC(void, FordMsg213BusHiSpd_CODE) FordMsg213BusHiSpdInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, FordMsg213BusHiSpd_CODE) FordMsg213BusHiSpdPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define FordMsg213BusHiSpd_STOP_SEC_CODE
# include "FordMsg213BusHiSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_FORDMSG213BUSHISPD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
