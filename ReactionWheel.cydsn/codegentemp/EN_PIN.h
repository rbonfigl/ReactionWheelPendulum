/*******************************************************************************
* File Name: EN_PIN.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_EN_PIN_H) /* Pins EN_PIN_H */
#define CY_PINS_EN_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EN_PIN_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} EN_PIN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   EN_PIN_Read(void);
void    EN_PIN_Write(uint8 value);
uint8   EN_PIN_ReadDataReg(void);
#if defined(EN_PIN__PC) || (CY_PSOC4_4200L) 
    void    EN_PIN_SetDriveMode(uint8 mode);
#endif
void    EN_PIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   EN_PIN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void EN_PIN_Sleep(void); 
void EN_PIN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(EN_PIN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define EN_PIN_DRIVE_MODE_BITS        (3)
    #define EN_PIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EN_PIN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the EN_PIN_SetDriveMode() function.
         *  @{
         */
        #define EN_PIN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define EN_PIN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define EN_PIN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define EN_PIN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define EN_PIN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define EN_PIN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define EN_PIN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define EN_PIN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define EN_PIN_MASK               EN_PIN__MASK
#define EN_PIN_SHIFT              EN_PIN__SHIFT
#define EN_PIN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EN_PIN_SetInterruptMode() function.
     *  @{
     */
        #define EN_PIN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define EN_PIN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define EN_PIN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define EN_PIN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(EN_PIN__SIO)
    #define EN_PIN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(EN_PIN__PC) && (CY_PSOC4_4200L)
    #define EN_PIN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define EN_PIN_USBIO_DISABLE              ((uint32)(~EN_PIN_USBIO_ENABLE))
    #define EN_PIN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define EN_PIN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define EN_PIN_USBIO_ENTER_SLEEP          ((uint32)((1u << EN_PIN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << EN_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define EN_PIN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << EN_PIN_USBIO_SUSPEND_SHIFT)))
    #define EN_PIN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << EN_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define EN_PIN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(EN_PIN__PC)
    /* Port Configuration */
    #define EN_PIN_PC                 (* (reg32 *) EN_PIN__PC)
#endif
/* Pin State */
#define EN_PIN_PS                     (* (reg32 *) EN_PIN__PS)
/* Data Register */
#define EN_PIN_DR                     (* (reg32 *) EN_PIN__DR)
/* Input Buffer Disable Override */
#define EN_PIN_INP_DIS                (* (reg32 *) EN_PIN__PC2)

/* Interrupt configuration Registers */
#define EN_PIN_INTCFG                 (* (reg32 *) EN_PIN__INTCFG)
#define EN_PIN_INTSTAT                (* (reg32 *) EN_PIN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define EN_PIN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(EN_PIN__SIO)
    #define EN_PIN_SIO_REG            (* (reg32 *) EN_PIN__SIO)
#endif /* (EN_PIN__SIO_CFG) */

/* USBIO registers */
#if !defined(EN_PIN__PC) && (CY_PSOC4_4200L)
    #define EN_PIN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define EN_PIN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define EN_PIN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define EN_PIN_DRIVE_MODE_SHIFT       (0x00u)
#define EN_PIN_DRIVE_MODE_MASK        (0x07u << EN_PIN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins EN_PIN_H */


/* [] END OF FILE */
