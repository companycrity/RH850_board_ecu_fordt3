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
 *          File:  Rte_CDD_NvMProxy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  PSCM_FD
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1601056 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_NvMProxy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_NVMPROXY_H
# define _RTE_CDD_NVMPROXY_H

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

# include "Rte_CDD_NvMProxy_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_ShtdwnClsChk; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_NvmStsCollctd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_BlkFltTblRec1_5, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_BlkFltTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_CmdRtnBufRec1_NvMProxy1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_CmdRtnBuf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_boolean_NvMProxy1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_NvmBlkActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_ShtdwnClsChk() \
  (&Rte_CDD_NvMProxy_ShtdwnClsChk) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_NvmStsCollctd() \
  (&Rte_CDD_NvMProxy_NvmStsCollctd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_BlkFltTbl() (&((*RtePim_BlkFltTbl())[0]))
#  else
#   define Rte_Pim_BlkFltTbl() RtePim_BlkFltTbl()
#  endif
#  define RtePim_BlkFltTbl() \
  (&Rte_CDD_NvMProxy_BlkFltTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_CmdRtnBuf() (&((*RtePim_CmdRtnBuf())[0]))
#  else
#   define Rte_Pim_CmdRtnBuf() RtePim_CmdRtnBuf()
#  endif
#  define RtePim_CmdRtnBuf() \
  (&Rte_CDD_NvMProxy_CmdRtnBuf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvmBlkActv() (&((*RtePim_NvmBlkActv())[0]))
#  else
#   define Rte_Pim_NvmBlkActv() RtePim_NvmBlkActv()
#  endif
#  define RtePim_NvmBlkActv() \
  (&Rte_CDD_NvMProxy_NvmBlkActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_NvMProxy_START_SEC_CODE
# include "CDD_NvMProxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_NvMProxyInit1 NvMProxyInit1
# endif

FUNC(void, CDD_NvMProxy_CODE) NvMProxyInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_NvMProxy_STOP_SEC_CODE
# include "CDD_NvMProxy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_NVMPROXY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
