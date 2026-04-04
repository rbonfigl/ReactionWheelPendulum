/*******************************************************************************
* File Name: IN_3_Out.h  
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

#if !defined(CY_PINS_IN_3_Out_ALIASES_H) /* Pins IN_3_Out_ALIASES_H */
#define CY_PINS_IN_3_Out_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IN_3_Out_0			(IN_3_Out__0__PC)
#define IN_3_Out_0_PS		(IN_3_Out__0__PS)
#define IN_3_Out_0_PC		(IN_3_Out__0__PC)
#define IN_3_Out_0_DR		(IN_3_Out__0__DR)
#define IN_3_Out_0_SHIFT	(IN_3_Out__0__SHIFT)
#define IN_3_Out_0_INTR	((uint16)((uint16)0x0003u << (IN_3_Out__0__SHIFT*2u)))

#define IN_3_Out_INTR_ALL	 ((uint16)(IN_3_Out_0_INTR))


#endif /* End Pins IN_3_Out_ALIASES_H */


/* [] END OF FILE */
