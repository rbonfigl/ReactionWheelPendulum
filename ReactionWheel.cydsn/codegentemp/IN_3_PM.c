/*******************************************************************************
* File Name: IN_3_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IN_3.h"

static IN_3_BACKUP_STRUCT IN_3_backup;


/*******************************************************************************
* Function Name: IN_3_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IN_3_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: IN_3_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IN_3_Sleep(void)
{
    if(0u != (IN_3_BLOCK_CONTROL_REG & IN_3_MASK))
    {
        IN_3_backup.enableState = 1u;
    }
    else
    {
        IN_3_backup.enableState = 0u;
    }

    IN_3_Stop();
    IN_3_SaveConfig();
}


/*******************************************************************************
* Function Name: IN_3_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IN_3_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: IN_3_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IN_3_Wakeup(void)
{
    IN_3_RestoreConfig();

    if(0u != IN_3_backup.enableState)
    {
        IN_3_Enable();
    }
}


/* [] END OF FILE */
