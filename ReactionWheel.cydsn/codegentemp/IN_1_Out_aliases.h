/*******************************************************************************
* File Name: IN_1_Out.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IN_1_Out_ALIASES_H) /* Pins IN_1_Out_ALIASES_H */
#define CY_PINS_IN_1_Out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IN_1_Out_0			(IN_1_Out__0__PC)
#define IN_1_Out_0_PS		(IN_1_Out__0__PS)
#define IN_1_Out_0_PC		(IN_1_Out__0__PC)
#define IN_1_Out_0_DR		(IN_1_Out__0__DR)
#define IN_1_Out_0_SHIFT	(IN_1_Out__0__SHIFT)
#define IN_1_Out_0_INTR	((uint16)((uint16)0x0003u << (IN_1_Out__0__SHIFT*2u)))

#define IN_1_Out_INTR_ALL	 ((uint16)(IN_1_Out_0_INTR))


#endif /* End Pins IN_1_Out_ALIASES_H */


/* [] END OF FILE */
