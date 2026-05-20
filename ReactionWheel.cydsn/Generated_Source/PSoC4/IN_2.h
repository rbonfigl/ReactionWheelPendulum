/*******************************************************************************
* File Name: IN_2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the IN_2
*  component.
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

#if !defined(CY_TCPWM_IN_2_H)
#define CY_TCPWM_IN_2_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} IN_2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  IN_2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define IN_2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define IN_2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define IN_2_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define IN_2_QUAD_ENCODING_MODES            (0lu)
#define IN_2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define IN_2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define IN_2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define IN_2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define IN_2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define IN_2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define IN_2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define IN_2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define IN_2_TC_RUN_MODE                    (0lu)
#define IN_2_TC_COUNTER_MODE                (0lu)
#define IN_2_TC_COMP_CAP_MODE               (2lu)
#define IN_2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define IN_2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define IN_2_TC_COUNT_SIGNAL_MODE           (3lu)
#define IN_2_TC_START_SIGNAL_MODE           (0lu)
#define IN_2_TC_STOP_SIGNAL_MODE            (0lu)
#define IN_2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define IN_2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define IN_2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define IN_2_TC_START_SIGNAL_PRESENT        (0lu)
#define IN_2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define IN_2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define IN_2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define IN_2_PWM_KILL_EVENT                 (0lu)
#define IN_2_PWM_STOP_EVENT                 (0lu)
#define IN_2_PWM_MODE                       (4lu)
#define IN_2_PWM_OUT_N_INVERT               (0lu)
#define IN_2_PWM_OUT_INVERT                 (0lu)
#define IN_2_PWM_ALIGN                      (2lu)
#define IN_2_PWM_RUN_MODE                   (0lu)
#define IN_2_PWM_DEAD_TIME_CYCLE            (0lu)
#define IN_2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define IN_2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define IN_2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define IN_2_PWM_START_SIGNAL_MODE          (0lu)
#define IN_2_PWM_STOP_SIGNAL_MODE           (0lu)
#define IN_2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define IN_2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define IN_2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define IN_2_PWM_START_SIGNAL_PRESENT       (0lu)
#define IN_2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define IN_2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define IN_2_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define IN_2_TC_PERIOD_VALUE                (65535lu)
#define IN_2_TC_COMPARE_VALUE               (65535lu)
#define IN_2_TC_COMPARE_BUF_VALUE           (65535lu)
#define IN_2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define IN_2_PWM_PERIOD_VALUE               (1200lu)
#define IN_2_PWM_PERIOD_BUF_VALUE           (1200lu)
#define IN_2_PWM_PERIOD_SWAP                (0lu)
#define IN_2_PWM_COMPARE_VALUE              (120lu)
#define IN_2_PWM_COMPARE_BUF_VALUE          (120lu)
#define IN_2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define IN_2__LEFT 0
#define IN_2__RIGHT 1
#define IN_2__CENTER 2
#define IN_2__ASYMMETRIC 3

#define IN_2__X1 0
#define IN_2__X2 1
#define IN_2__X4 2

#define IN_2__PWM 4
#define IN_2__PWM_DT 5
#define IN_2__PWM_PR 6

#define IN_2__INVERSE 1
#define IN_2__DIRECT 0

#define IN_2__CAPTURE 2
#define IN_2__COMPARE 0

#define IN_2__TRIG_LEVEL 3
#define IN_2__TRIG_RISING 0
#define IN_2__TRIG_FALLING 1
#define IN_2__TRIG_BOTH 2

#define IN_2__INTR_MASK_TC 1
#define IN_2__INTR_MASK_CC_MATCH 2
#define IN_2__INTR_MASK_NONE 0
#define IN_2__INTR_MASK_TC_CC 3

#define IN_2__UNCONFIG 8
#define IN_2__TIMER 1
#define IN_2__QUAD 3
#define IN_2__PWM_SEL 7

#define IN_2__COUNT_UP 0
#define IN_2__COUNT_DOWN 1
#define IN_2__COUNT_UPDOWN0 2
#define IN_2__COUNT_UPDOWN1 3


/* Prescaler */
#define IN_2_PRESCALE_DIVBY1                ((uint32)(0u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY2                ((uint32)(1u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY4                ((uint32)(2u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY8                ((uint32)(3u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY16               ((uint32)(4u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY32               ((uint32)(5u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY64               ((uint32)(6u << IN_2_PRESCALER_SHIFT))
#define IN_2_PRESCALE_DIVBY128              ((uint32)(7u << IN_2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define IN_2_MODE_TIMER_COMPARE             ((uint32)(IN_2__COMPARE         <<  \
                                                                  IN_2_MODE_SHIFT))
#define IN_2_MODE_TIMER_CAPTURE             ((uint32)(IN_2__CAPTURE         <<  \
                                                                  IN_2_MODE_SHIFT))
#define IN_2_MODE_QUAD                      ((uint32)(IN_2__QUAD            <<  \
                                                                  IN_2_MODE_SHIFT))
#define IN_2_MODE_PWM                       ((uint32)(IN_2__PWM             <<  \
                                                                  IN_2_MODE_SHIFT))
#define IN_2_MODE_PWM_DT                    ((uint32)(IN_2__PWM_DT          <<  \
                                                                  IN_2_MODE_SHIFT))
#define IN_2_MODE_PWM_PR                    ((uint32)(IN_2__PWM_PR          <<  \
                                                                  IN_2_MODE_SHIFT))

/* Quad Modes */
#define IN_2_MODE_X1                        ((uint32)(IN_2__X1              <<  \
                                                                  IN_2_QUAD_MODE_SHIFT))
#define IN_2_MODE_X2                        ((uint32)(IN_2__X2              <<  \
                                                                  IN_2_QUAD_MODE_SHIFT))
#define IN_2_MODE_X4                        ((uint32)(IN_2__X4              <<  \
                                                                  IN_2_QUAD_MODE_SHIFT))

/* Counter modes */
#define IN_2_COUNT_UP                       ((uint32)(IN_2__COUNT_UP        <<  \
                                                                  IN_2_UPDOWN_SHIFT))
#define IN_2_COUNT_DOWN                     ((uint32)(IN_2__COUNT_DOWN      <<  \
                                                                  IN_2_UPDOWN_SHIFT))
#define IN_2_COUNT_UPDOWN0                  ((uint32)(IN_2__COUNT_UPDOWN0   <<  \
                                                                  IN_2_UPDOWN_SHIFT))
#define IN_2_COUNT_UPDOWN1                  ((uint32)(IN_2__COUNT_UPDOWN1   <<  \
                                                                  IN_2_UPDOWN_SHIFT))

/* PWM output invert */
#define IN_2_INVERT_LINE                    ((uint32)(IN_2__INVERSE         <<  \
                                                                  IN_2_INV_OUT_SHIFT))
#define IN_2_INVERT_LINE_N                  ((uint32)(IN_2__INVERSE         <<  \
                                                                  IN_2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define IN_2_TRIG_RISING                    ((uint32)IN_2__TRIG_RISING)
#define IN_2_TRIG_FALLING                   ((uint32)IN_2__TRIG_FALLING)
#define IN_2_TRIG_BOTH                      ((uint32)IN_2__TRIG_BOTH)
#define IN_2_TRIG_LEVEL                     ((uint32)IN_2__TRIG_LEVEL)

/* Interrupt mask */
#define IN_2_INTR_MASK_TC                   ((uint32)IN_2__INTR_MASK_TC)
#define IN_2_INTR_MASK_CC_MATCH             ((uint32)IN_2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define IN_2_CC_MATCH_SET                   (0x00u)
#define IN_2_CC_MATCH_CLEAR                 (0x01u)
#define IN_2_CC_MATCH_INVERT                (0x02u)
#define IN_2_CC_MATCH_NO_CHANGE             (0x03u)
#define IN_2_OVERLOW_SET                    (0x00u)
#define IN_2_OVERLOW_CLEAR                  (0x04u)
#define IN_2_OVERLOW_INVERT                 (0x08u)
#define IN_2_OVERLOW_NO_CHANGE              (0x0Cu)
#define IN_2_UNDERFLOW_SET                  (0x00u)
#define IN_2_UNDERFLOW_CLEAR                (0x10u)
#define IN_2_UNDERFLOW_INVERT               (0x20u)
#define IN_2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define IN_2_PWM_MODE_LEFT                  (IN_2_CC_MATCH_CLEAR        |   \
                                                         IN_2_OVERLOW_SET           |   \
                                                         IN_2_UNDERFLOW_NO_CHANGE)
#define IN_2_PWM_MODE_RIGHT                 (IN_2_CC_MATCH_SET          |   \
                                                         IN_2_OVERLOW_NO_CHANGE     |   \
                                                         IN_2_UNDERFLOW_CLEAR)
#define IN_2_PWM_MODE_ASYM                  (IN_2_CC_MATCH_INVERT       |   \
                                                         IN_2_OVERLOW_SET           |   \
                                                         IN_2_UNDERFLOW_CLEAR)

#if (IN_2_CY_TCPWM_V2)
    #if(IN_2_CY_TCPWM_4000)
        #define IN_2_PWM_MODE_CENTER                (IN_2_CC_MATCH_INVERT       |   \
                                                                 IN_2_OVERLOW_NO_CHANGE     |   \
                                                                 IN_2_UNDERFLOW_CLEAR)
    #else
        #define IN_2_PWM_MODE_CENTER                (IN_2_CC_MATCH_INVERT       |   \
                                                                 IN_2_OVERLOW_SET           |   \
                                                                 IN_2_UNDERFLOW_CLEAR)
    #endif /* (IN_2_CY_TCPWM_4000) */
#else
    #define IN_2_PWM_MODE_CENTER                (IN_2_CC_MATCH_INVERT       |   \
                                                             IN_2_OVERLOW_NO_CHANGE     |   \
                                                             IN_2_UNDERFLOW_CLEAR)
#endif /* (IN_2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define IN_2_CMD_CAPTURE                    (0u)
#define IN_2_CMD_RELOAD                     (8u)
#define IN_2_CMD_STOP                       (16u)
#define IN_2_CMD_START                      (24u)

/* Status */
#define IN_2_STATUS_DOWN                    (1u)
#define IN_2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   IN_2_Init(void);
void   IN_2_Enable(void);
void   IN_2_Start(void);
void   IN_2_Stop(void);

void   IN_2_SetMode(uint32 mode);
void   IN_2_SetCounterMode(uint32 counterMode);
void   IN_2_SetPWMMode(uint32 modeMask);
void   IN_2_SetQDMode(uint32 qdMode);

void   IN_2_SetPrescaler(uint32 prescaler);
void   IN_2_TriggerCommand(uint32 mask, uint32 command);
void   IN_2_SetOneShot(uint32 oneShotEnable);
uint32 IN_2_ReadStatus(void);

void   IN_2_SetPWMSyncKill(uint32 syncKillEnable);
void   IN_2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   IN_2_SetPWMDeadTime(uint32 deadTime);
void   IN_2_SetPWMInvert(uint32 mask);

void   IN_2_SetInterruptMode(uint32 interruptMask);
uint32 IN_2_GetInterruptSourceMasked(void);
uint32 IN_2_GetInterruptSource(void);
void   IN_2_ClearInterrupt(uint32 interruptMask);
void   IN_2_SetInterrupt(uint32 interruptMask);

void   IN_2_WriteCounter(uint32 count);
uint32 IN_2_ReadCounter(void);

uint32 IN_2_ReadCapture(void);
uint32 IN_2_ReadCaptureBuf(void);

void   IN_2_WritePeriod(uint32 period);
uint32 IN_2_ReadPeriod(void);
void   IN_2_WritePeriodBuf(uint32 periodBuf);
uint32 IN_2_ReadPeriodBuf(void);

void   IN_2_WriteCompare(uint32 compare);
uint32 IN_2_ReadCompare(void);
void   IN_2_WriteCompareBuf(uint32 compareBuf);
uint32 IN_2_ReadCompareBuf(void);

void   IN_2_SetPeriodSwap(uint32 swapEnable);
void   IN_2_SetCompareSwap(uint32 swapEnable);

void   IN_2_SetCaptureMode(uint32 triggerMode);
void   IN_2_SetReloadMode(uint32 triggerMode);
void   IN_2_SetStartMode(uint32 triggerMode);
void   IN_2_SetStopMode(uint32 triggerMode);
void   IN_2_SetCountMode(uint32 triggerMode);

void   IN_2_SaveConfig(void);
void   IN_2_RestoreConfig(void);
void   IN_2_Sleep(void);
void   IN_2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define IN_2_BLOCK_CONTROL_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define IN_2_BLOCK_CONTROL_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define IN_2_COMMAND_REG                    (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define IN_2_COMMAND_PTR                    ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define IN_2_INTRRUPT_CAUSE_REG             (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define IN_2_INTRRUPT_CAUSE_PTR             ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define IN_2_CONTROL_REG                    (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__CTRL )
#define IN_2_CONTROL_PTR                    ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__CTRL )
#define IN_2_STATUS_REG                     (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__STATUS )
#define IN_2_STATUS_PTR                     ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__STATUS )
#define IN_2_COUNTER_REG                    (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__COUNTER )
#define IN_2_COUNTER_PTR                    ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__COUNTER )
#define IN_2_COMP_CAP_REG                   (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__CC )
#define IN_2_COMP_CAP_PTR                   ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__CC )
#define IN_2_COMP_CAP_BUF_REG               (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define IN_2_COMP_CAP_BUF_PTR               ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define IN_2_PERIOD_REG                     (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__PERIOD )
#define IN_2_PERIOD_PTR                     ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__PERIOD )
#define IN_2_PERIOD_BUF_REG                 (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define IN_2_PERIOD_BUF_PTR                 ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define IN_2_TRIG_CONTROL0_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define IN_2_TRIG_CONTROL0_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define IN_2_TRIG_CONTROL1_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define IN_2_TRIG_CONTROL1_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define IN_2_TRIG_CONTROL2_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define IN_2_TRIG_CONTROL2_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define IN_2_INTERRUPT_REQ_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR )
#define IN_2_INTERRUPT_REQ_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR )
#define IN_2_INTERRUPT_SET_REG              (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_SET )
#define IN_2_INTERRUPT_SET_PTR              ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_SET )
#define IN_2_INTERRUPT_MASK_REG             (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define IN_2_INTERRUPT_MASK_PTR             ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define IN_2_INTERRUPT_MASKED_REG           (*(reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define IN_2_INTERRUPT_MASKED_PTR           ( (reg32 *) IN_2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define IN_2_MASK                           ((uint32)IN_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define IN_2_RELOAD_CC_SHIFT                (0u)
#define IN_2_RELOAD_PERIOD_SHIFT            (1u)
#define IN_2_PWM_SYNC_KILL_SHIFT            (2u)
#define IN_2_PWM_STOP_KILL_SHIFT            (3u)
#define IN_2_PRESCALER_SHIFT                (8u)
#define IN_2_UPDOWN_SHIFT                   (16u)
#define IN_2_ONESHOT_SHIFT                  (18u)
#define IN_2_QUAD_MODE_SHIFT                (20u)
#define IN_2_INV_OUT_SHIFT                  (20u)
#define IN_2_INV_COMPL_OUT_SHIFT            (21u)
#define IN_2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define IN_2_RELOAD_CC_MASK                 ((uint32)(IN_2_1BIT_MASK        <<  \
                                                                            IN_2_RELOAD_CC_SHIFT))
#define IN_2_RELOAD_PERIOD_MASK             ((uint32)(IN_2_1BIT_MASK        <<  \
                                                                            IN_2_RELOAD_PERIOD_SHIFT))
#define IN_2_PWM_SYNC_KILL_MASK             ((uint32)(IN_2_1BIT_MASK        <<  \
                                                                            IN_2_PWM_SYNC_KILL_SHIFT))
#define IN_2_PWM_STOP_KILL_MASK             ((uint32)(IN_2_1BIT_MASK        <<  \
                                                                            IN_2_PWM_STOP_KILL_SHIFT))
#define IN_2_PRESCALER_MASK                 ((uint32)(IN_2_8BIT_MASK        <<  \
                                                                            IN_2_PRESCALER_SHIFT))
#define IN_2_UPDOWN_MASK                    ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                            IN_2_UPDOWN_SHIFT))
#define IN_2_ONESHOT_MASK                   ((uint32)(IN_2_1BIT_MASK        <<  \
                                                                            IN_2_ONESHOT_SHIFT))
#define IN_2_QUAD_MODE_MASK                 ((uint32)(IN_2_3BIT_MASK        <<  \
                                                                            IN_2_QUAD_MODE_SHIFT))
#define IN_2_INV_OUT_MASK                   ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                            IN_2_INV_OUT_SHIFT))
#define IN_2_MODE_MASK                      ((uint32)(IN_2_3BIT_MASK        <<  \
                                                                            IN_2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define IN_2_CAPTURE_SHIFT                  (0u)
#define IN_2_COUNT_SHIFT                    (2u)
#define IN_2_RELOAD_SHIFT                   (4u)
#define IN_2_STOP_SHIFT                     (6u)
#define IN_2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define IN_2_CAPTURE_MASK                   ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                  IN_2_CAPTURE_SHIFT))
#define IN_2_COUNT_MASK                     ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                  IN_2_COUNT_SHIFT))
#define IN_2_RELOAD_MASK                    ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                  IN_2_RELOAD_SHIFT))
#define IN_2_STOP_MASK                      ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                  IN_2_STOP_SHIFT))
#define IN_2_START_MASK                     ((uint32)(IN_2_2BIT_MASK        <<  \
                                                                  IN_2_START_SHIFT))

/* MASK */
#define IN_2_1BIT_MASK                      ((uint32)0x01u)
#define IN_2_2BIT_MASK                      ((uint32)0x03u)
#define IN_2_3BIT_MASK                      ((uint32)0x07u)
#define IN_2_6BIT_MASK                      ((uint32)0x3Fu)
#define IN_2_8BIT_MASK                      ((uint32)0xFFu)
#define IN_2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define IN_2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define IN_2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(IN_2_QUAD_ENCODING_MODES     << IN_2_QUAD_MODE_SHIFT))       |\
         ((uint32)(IN_2_CONFIG                  << IN_2_MODE_SHIFT)))

#define IN_2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(IN_2_PWM_STOP_EVENT          << IN_2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(IN_2_PWM_OUT_INVERT          << IN_2_INV_OUT_SHIFT))         |\
         ((uint32)(IN_2_PWM_OUT_N_INVERT        << IN_2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(IN_2_PWM_MODE                << IN_2_MODE_SHIFT)))

#define IN_2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(IN_2_PWM_RUN_MODE         << IN_2_ONESHOT_SHIFT))
            
#define IN_2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(IN_2_PWM_ALIGN            << IN_2_UPDOWN_SHIFT))

#define IN_2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(IN_2_PWM_KILL_EVENT      << IN_2_PWM_SYNC_KILL_SHIFT))

#define IN_2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(IN_2_PWM_DEAD_TIME_CYCLE  << IN_2_PRESCALER_SHIFT))

#define IN_2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(IN_2_PWM_PRESCALER        << IN_2_PRESCALER_SHIFT))

#define IN_2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(IN_2_TC_PRESCALER            << IN_2_PRESCALER_SHIFT))       |\
         ((uint32)(IN_2_TC_COUNTER_MODE         << IN_2_UPDOWN_SHIFT))          |\
         ((uint32)(IN_2_TC_RUN_MODE             << IN_2_ONESHOT_SHIFT))         |\
         ((uint32)(IN_2_TC_COMP_CAP_MODE        << IN_2_MODE_SHIFT)))
        
#define IN_2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(IN_2_QUAD_PHIA_SIGNAL_MODE   << IN_2_COUNT_SHIFT))           |\
         ((uint32)(IN_2_QUAD_INDEX_SIGNAL_MODE  << IN_2_RELOAD_SHIFT))          |\
         ((uint32)(IN_2_QUAD_STOP_SIGNAL_MODE   << IN_2_STOP_SHIFT))            |\
         ((uint32)(IN_2_QUAD_PHIB_SIGNAL_MODE   << IN_2_START_SHIFT)))

#define IN_2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(IN_2_PWM_SWITCH_SIGNAL_MODE  << IN_2_CAPTURE_SHIFT))         |\
         ((uint32)(IN_2_PWM_COUNT_SIGNAL_MODE   << IN_2_COUNT_SHIFT))           |\
         ((uint32)(IN_2_PWM_RELOAD_SIGNAL_MODE  << IN_2_RELOAD_SHIFT))          |\
         ((uint32)(IN_2_PWM_STOP_SIGNAL_MODE    << IN_2_STOP_SHIFT))            |\
         ((uint32)(IN_2_PWM_START_SIGNAL_MODE   << IN_2_START_SHIFT)))

#define IN_2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(IN_2_TC_CAPTURE_SIGNAL_MODE  << IN_2_CAPTURE_SHIFT))         |\
         ((uint32)(IN_2_TC_COUNT_SIGNAL_MODE    << IN_2_COUNT_SHIFT))           |\
         ((uint32)(IN_2_TC_RELOAD_SIGNAL_MODE   << IN_2_RELOAD_SHIFT))          |\
         ((uint32)(IN_2_TC_STOP_SIGNAL_MODE     << IN_2_STOP_SHIFT))            |\
         ((uint32)(IN_2_TC_START_SIGNAL_MODE    << IN_2_START_SHIFT)))
        
#define IN_2_TIMER_UPDOWN_CNT_USED                                                          \
                ((IN_2__COUNT_UPDOWN0 == IN_2_TC_COUNTER_MODE)                  ||\
                 (IN_2__COUNT_UPDOWN1 == IN_2_TC_COUNTER_MODE))

#define IN_2_PWM_UPDOWN_CNT_USED                                                            \
                ((IN_2__CENTER == IN_2_PWM_ALIGN)                               ||\
                 (IN_2__ASYMMETRIC == IN_2_PWM_ALIGN))               
        
#define IN_2_PWM_PR_INIT_VALUE              (1u)
#define IN_2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_IN_2_H */

/* [] END OF FILE */
