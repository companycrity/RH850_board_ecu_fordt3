/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Xcp
 *           Program: MSR_Ford_SLP1 (MSR_Ford_SLP1)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701373EABG
 *    License Scope : The usage is restricted to CBD1601056_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanXcp_PBcfg.h
 *   Generation Time: 2018-01-24 11:34:48
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1601056_D00
 *      Tool Version: DaVinci Configurator (beta) 5.14.21 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

	

#include "CanXcp_Types.h"	
#include "CanXcp_Cfg.h"

 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_PduField - _ECU1
 ----------------------------------------------------------------------------- */
#define CANXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(CanXcp_XcpPduType, CANXCP_PBCFG) CanXcp_PduIdField_ECU1[CANXCP_NUMBER_OF_CHANNELS]; 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_Config - _ECU1
 ----------------------------------------------------------------------------- */

extern CONST(CanXcp_ConfigType, CANXCP_PBCFG) CanXcp_Config_ECU1;

#define CANXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"
 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_PduField - _ECU2
 ----------------------------------------------------------------------------- */
#define CANXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(CanXcp_XcpPduType, CANXCP_PBCFG) CanXcp_PduIdField_ECU2[CANXCP_NUMBER_OF_CHANNELS]; 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_Config - _ECU2
 ----------------------------------------------------------------------------- */

extern CONST(CanXcp_ConfigType, CANXCP_PBCFG) CanXcp_Config_ECU2;

#define CANXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


