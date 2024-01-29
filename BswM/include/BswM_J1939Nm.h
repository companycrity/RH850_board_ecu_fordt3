/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BswM_J1939Nm.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for J1939Nm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#if !defined BSWM_J1939NM_H
# define BSWM_J1939NM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "J1939Nm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

/**********************************************************************************************************************
 *  BswM_J1939Nm_StateChangeNotification()
 *********************************************************************************************************************/
/*! \brief      Notification of current J1939Nm state after state changes.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   Network   Identification of the J1939 channel.
 * \param[in]   Node      Identification of the J1939 node.
 * \param[in]   NmState   Current (new) state of the J1939 node.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different combinations of network and node.
 * \synchronous TRUE
 * \config      BSWM_ENABLE_J1939NM
 */
extern FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification(NetworkHandleType Network, uint8 Node,
                               Nm_StateType NmState);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

#endif  /* BSWM_J1939NM_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM_CanSM.h
 *********************************************************************************************************************/
