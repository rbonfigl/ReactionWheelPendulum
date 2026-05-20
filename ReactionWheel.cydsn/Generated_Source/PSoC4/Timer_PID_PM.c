/*******************************************************************************
* File Name: Timer_PID_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_PID.h"

static Timer_PID_backupStruct Timer_PID_backup;


/*******************************************************************************
* Function Name: Timer_PID_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_PID_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_PID_SaveConfig(void) 
{
    #if (!Timer_PID_UsingFixedFunction)
        Timer_PID_backup.TimerUdb = Timer_PID_ReadCounter();
        Timer_PID_backup.InterruptMaskValue = Timer_PID_STATUS_MASK;
        #if (Timer_PID_UsingHWCaptureCounter)
            Timer_PID_backup.TimerCaptureCounter = Timer_PID_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_PID_UDB_CONTROL_REG_REMOVED)
            Timer_PID_backup.TimerControlRegister = Timer_PID_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_PID_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_PID_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_PID_RestoreConfig(void) 
{   
    #if (!Timer_PID_UsingFixedFunction)

        Timer_PID_WriteCounter(Timer_PID_backup.TimerUdb);
        Timer_PID_STATUS_MASK =Timer_PID_backup.InterruptMaskValue;
        #if (Timer_PID_UsingHWCaptureCounter)
            Timer_PID_SetCaptureCount(Timer_PID_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_PID_UDB_CONTROL_REG_REMOVED)
            Timer_PID_WriteControlRegister(Timer_PID_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_PID_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_PID_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_PID_Sleep(void) 
{
    #if(!Timer_PID_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_PID_CTRL_ENABLE == (Timer_PID_CONTROL & Timer_PID_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_PID_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_PID_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_PID_Stop();
    Timer_PID_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_PID_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_PID_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_PID_Wakeup(void) 
{
    Timer_PID_RestoreConfig();
    #if(!Timer_PID_UDB_CONTROL_REG_REMOVED)
        if(Timer_PID_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_PID_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
