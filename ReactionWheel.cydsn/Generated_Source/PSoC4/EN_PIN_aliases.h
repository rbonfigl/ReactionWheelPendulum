/*******************************************************************************
* File Name: EN_PIN.h  
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

#if !defined(CY_PINS_EN_PIN_ALIASES_H) /* Pins EN_PIN_ALIASES_H */
#define CY_PINS_EN_PIN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define EN_PIN_0			(EN_PIN__0__PC)
#define EN_PIN_0_PS		(EN_PIN__0__PS)
#define EN_PIN_0_PC		(EN_PIN__0__PC)
#define EN_PIN_0_DR		(EN_PIN__0__DR)
#define EN_PIN_0_SHIFT	(EN_PIN__0__SHIFT)
#define EN_PIN_0_INTR	((uint16)((uint16)0x0003u << (EN_PIN__0__SHIFT*2u)))

#define EN_PIN_INTR_ALL	 ((uint16)(EN_PIN_0_INTR))


#endif /* End Pins EN_PIN_ALIASES_H */


/* [] END OF FILE */
