/*******************************************************************************
* File Name: IN_3.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the IN_3
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

#if !defined(CY_TCPWM_IN_3_H)
#define CY_TCPWM_IN_3_H


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
} IN_3_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  IN_3_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define IN_3_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define IN_3_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define IN_3_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define IN_3_QUAD_ENCODING_MODES            (0lu)
#define IN_3_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define IN_3_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define IN_3_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define IN_3_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define IN_3_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define IN_3_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define IN_3_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define IN_3_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define IN_3_TC_RUN_MODE                    (0lu)
#define IN_3_TC_COUNTER_MODE                (0lu)
#define IN_3_TC_COMP_CAP_MODE               (2lu)
#define IN_3_TC_PRESCALER                   (0lu)

/* Signal modes */
#define IN_3_TC_RELOAD_SIGNAL_MODE          (0lu)
#define IN_3_TC_COUNT_SIGNAL_MODE           (3lu)
#define IN_3_TC_START_SIGNAL_MODE           (0lu)
#define IN_3_TC_STOP_SIGNAL_MODE            (0lu)
#define IN_3_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define IN_3_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define IN_3_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define IN_3_TC_START_SIGNAL_PRESENT        (0lu)
#define IN_3_TC_STOP_SIGNAL_PRESENT         (0lu)
#define IN_3_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define IN_3_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define IN_3_PWM_KILL_EVENT                 (0lu)
#define IN_3_PWM_STOP_EVENT                 (0lu)
#define IN_3_PWM_MODE                       (4lu)
#define IN_3_PWM_OUT_N_INVERT               (0lu)
#define IN_3_PWM_OUT_INVERT                 (0lu)
#define IN_3_PWM_ALIGN                      (2lu)
#define IN_3_PWM_RUN_MODE                   (0lu)
#define IN_3_PWM_DEAD_TIME_CYCLE            (0lu)
#define IN_3_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define IN_3_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define IN_3_PWM_COUNT_SIGNAL_MODE          (3lu)
#define IN_3_PWM_START_SIGNAL_MODE          (0lu)
#define IN_3_PWM_STOP_SIGNAL_MODE           (0lu)
#define IN_3_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define IN_3_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define IN_3_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define IN_3_PWM_START_SIGNAL_PRESENT       (0lu)
#define IN_3_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define IN_3_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define IN_3_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define IN_3_TC_PERIOD_VALUE                (65535lu)
#define IN_3_TC_COMPARE_VALUE               (65535lu)
#define IN_3_TC_COMPARE_BUF_VALUE           (65535lu)
#define IN_3_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define IN_3_PWM_PERIOD_VALUE               (2400lu)
#define IN_3_PWM_PERIOD_BUF_VALUE           (1200lu)
#define IN_3_PWM_PERIOD_SWAP                (0lu)
#define IN_3_PWM_COMPARE_VALUE              (120lu)
#define IN_3_PWM_COMPARE_BUF_VALUE          (120lu)
#define IN_3_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define IN_3__LEFT 0
#define IN_3__RIGHT 1
#define IN_3__CENTER 2
#define IN_3__ASYMMETRIC 3

#define IN_3__X1 0
#define IN_3__X2 1
#define IN_3__X4 2

#define IN_3__PWM 4
#define IN_3__PWM_DT 5
#define IN_3__PWM_PR 6

#define IN_3__INVERSE 1
#define IN_3__DIRECT 0

#define IN_3__CAPTURE 2
#define IN_3__COMPARE 0

#define IN_3__TRIG_LEVEL 3
#define IN_3__TRIG_RISING 0
#define IN_3__TRIG_FALLING 1
#define IN_3__TRIG_BOTH 2

#define IN_3__INTR_MASK_TC 1
#define IN_3__INTR_MASK_CC_MATCH 2
#define IN_3__INTR_MASK_NONE 0
#define IN_3__INTR_MASK_TC_CC 3

#define IN_3__UNCONFIG 8
#define IN_3__TIMER 1
#define IN_3__QUAD 3
#define IN_3__PWM_SEL 7

#define IN_3__COUNT_UP 0
#define IN_3__COUNT_DOWN 1
#define IN_3__COUNT_UPDOWN0 2
#define IN_3__COUNT_UPDOWN1 3


/* Prescaler */
#define IN_3_PRESCALE_DIVBY1                ((uint32)(0u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY2                ((uint32)(1u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY4                ((uint32)(2u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY8                ((uint32)(3u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY16               ((uint32)(4u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY32               ((uint32)(5u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY64               ((uint32)(6u << IN_3_PRESCALER_SHIFT))
#define IN_3_PRESCALE_DIVBY128              ((uint32)(7u << IN_3_PRESCALER_SHIFT))

/* TCPWM set modes */
#define IN_3_MODE_TIMER_COMPARE             ((uint32)(IN_3__COMPARE         <<  \
                                                                  IN_3_MODE_SHIFT))
#define IN_3_MODE_TIMER_CAPTURE             ((uint32)(IN_3__CAPTURE         <<  \
                                                                  IN_3_MODE_SHIFT))
#define IN_3_MODE_QUAD                      ((uint32)(IN_3__QUAD            <<  \
                                                                  IN_3_MODE_SHIFT))
#define IN_3_MODE_PWM                       ((uint32)(IN_3__PWM             <<  \
                                                                  IN_3_MODE_SHIFT))
#define IN_3_MODE_PWM_DT                    ((uint32)(IN_3__PWM_DT          <<  \
                                                                  IN_3_MODE_SHIFT))
#define IN_3_MODE_PWM_PR                    ((uint32)(IN_3__PWM_PR          <<  \
                                                                  IN_3_MODE_SHIFT))

/* Quad Modes */
#define IN_3_MODE_X1                        ((uint32)(IN_3__X1              <<  \
                                                                  IN_3_QUAD_MODE_SHIFT))
#define IN_3_MODE_X2                        ((uint32)(IN_3__X2              <<  \
                                                                  IN_3_QUAD_MODE_SHIFT))
#define IN_3_MODE_X4                        ((uint32)(IN_3__X4              <<  \
                                                                  IN_3_QUAD_MODE_SHIFT))

/* Counter modes */
#define IN_3_COUNT_UP                       ((uint32)(IN_3__COUNT_UP        <<  \
                                                                  IN_3_UPDOWN_SHIFT))
#define IN_3_COUNT_DOWN                     ((uint32)(IN_3__COUNT_DOWN      <<  \
                                                                  IN_3_UPDOWN_SHIFT))
#define IN_3_COUNT_UPDOWN0                  ((uint32)(IN_3__COUNT_UPDOWN0   <<  \
                                                                  IN_3_UPDOWN_SHIFT))
#define IN_3_COUNT_UPDOWN1                  ((uint32)(IN_3__COUNT_UPDOWN1   <<  \
                                                                  IN_3_UPDOWN_SHIFT))

/* PWM output invert */
#define IN_3_INVERT_LINE                    ((uint32)(IN_3__INVERSE         <<  \
                                                                  IN_3_INV_OUT_SHIFT))
#define IN_3_INVERT_LINE_N                  ((uint32)(IN_3__INVERSE         <<  \
                                                                  IN_3_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define IN_3_TRIG_RISING                    ((uint32)IN_3__TRIG_RISING)
#define IN_3_TRIG_FALLING                   ((uint32)IN_3__TRIG_FALLING)
#define IN_3_TRIG_BOTH                      ((uint32)IN_3__TRIG_BOTH)
#define IN_3_TRIG_LEVEL                     ((uint32)IN_3__TRIG_LEVEL)

/* Interrupt mask */
#define IN_3_INTR_MASK_TC                   ((uint32)IN_3__INTR_MASK_TC)
#define IN_3_INTR_MASK_CC_MATCH             ((uint32)IN_3__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define IN_3_CC_MATCH_SET                   (0x00u)
#define IN_3_CC_MATCH_CLEAR                 (0x01u)
#define IN_3_CC_MATCH_INVERT                (0x02u)
#define IN_3_CC_MATCH_NO_CHANGE             (0x03u)
#define IN_3_OVERLOW_SET                    (0x00u)
#define IN_3_OVERLOW_CLEAR                  (0x04u)
#define IN_3_OVERLOW_INVERT                 (0x08u)
#define IN_3_OVERLOW_NO_CHANGE              (0x0Cu)
#define IN_3_UNDERFLOW_SET                  (0x00u)
#define IN_3_UNDERFLOW_CLEAR                (0x10u)
#define IN_3_UNDERFLOW_INVERT               (0x20u)
#define IN_3_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define IN_3_PWM_MODE_LEFT                  (IN_3_CC_MATCH_CLEAR        |   \
                                                         IN_3_OVERLOW_SET           |   \
                                                         IN_3_UNDERFLOW_NO_CHANGE)
#define IN_3_PWM_MODE_RIGHT                 (IN_3_CC_MATCH_SET          |   \
                                                         IN_3_OVERLOW_NO_CHANGE     |   \
                                                         IN_3_UNDERFLOW_CLEAR)
#define IN_3_PWM_MODE_ASYM                  (IN_3_CC_MATCH_INVERT       |   \
                                                         IN_3_OVERLOW_SET           |   \
                                                         IN_3_UNDERFLOW_CLEAR)

#if (IN_3_CY_TCPWM_V2)
    #if(IN_3_CY_TCPWM_4000)
        #define IN_3_PWM_MODE_CENTER                (IN_3_CC_MATCH_INVERT       |   \
                                                                 IN_3_OVERLOW_NO_CHANGE     |   \
                                                                 IN_3_UNDERFLOW_CLEAR)
    #else
        #define IN_3_PWM_MODE_CENTER                (IN_3_CC_MATCH_INVERT       |   \
                                                                 IN_3_OVERLOW_SET           |   \
                                                                 IN_3_UNDERFLOW_CLEAR)
    #endif /* (IN_3_CY_TCPWM_4000) */
#else
    #define IN_3_PWM_MODE_CENTER                (IN_3_CC_MATCH_INVERT       |   \
                                                             IN_3_OVERLOW_NO_CHANGE     |   \
                                                             IN_3_UNDERFLOW_CLEAR)
#endif /* (IN_3_CY_TCPWM_NEW) */

/* Command operations without condition */
#define IN_3_CMD_CAPTURE                    (0u)
#define IN_3_CMD_RELOAD                     (8u)
#define IN_3_CMD_STOP                       (16u)
#define IN_3_CMD_START                      (24u)

/* Status */
#define IN_3_STATUS_DOWN                    (1u)
#define IN_3_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   IN_3_Init(void);
void   IN_3_Enable(void);
void   IN_3_Start(void);
void   IN_3_Stop(void);

void   IN_3_SetMode(uint32 mode);
void   IN_3_SetCounterMode(uint32 counterMode);
void   IN_3_SetPWMMode(uint32 modeMask);
void   IN_3_SetQDMode(uint32 qdMode);

void   IN_3_SetPrescaler(uint32 prescaler);
void   IN_3_TriggerCommand(uint32 mask, uint32 command);
void   IN_3_SetOneShot(uint32 oneShotEnable);
uint32 IN_3_ReadStatus(void);

void   IN_3_SetPWMSyncKill(uint32 syncKillEnable);
void   IN_3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   IN_3_SetPWMDeadTime(uint32 deadTime);
void   IN_3_SetPWMInvert(uint32 mask);

void   IN_3_SetInterruptMode(uint32 interruptMask);
uint32 IN_3_GetInterruptSourceMasked(void);
uint32 IN_3_GetInterruptSource(void);
void   IN_3_ClearInterrupt(uint32 interruptMask);
void   IN_3_SetInterrupt(uint32 interruptMask);

void   IN_3_WriteCounter(uint32 count);
uint32 IN_3_ReadCounter(void);

uint32 IN_3_ReadCapture(void);
uint32 IN_3_ReadCaptureBuf(void);

void   IN_3_WritePeriod(uint32 period);
uint32 IN_3_ReadPeriod(void);
void   IN_3_WritePeriodBuf(uint32 periodBuf);
uint32 IN_3_ReadPeriodBuf(void);

void   IN_3_WriteCompare(uint32 compare);
uint32 IN_3_ReadCompare(void);
void   IN_3_WriteCompareBuf(uint32 compareBuf);
uint32 IN_3_ReadCompareBuf(void);

void   IN_3_SetPeriodSwap(uint32 swapEnable);
void   IN_3_SetCompareSwap(uint32 swapEnable);

void   IN_3_SetCaptureMode(uint32 triggerMode);
void   IN_3_SetReloadMode(uint32 triggerMode);
void   IN_3_SetStartMode(uint32 triggerMode);
void   IN_3_SetStopMode(uint32 triggerMode);
void   IN_3_SetCountMode(uint32 triggerMode);

void   IN_3_SaveConfig(void);
void   IN_3_RestoreConfig(void);
void   IN_3_Sleep(void);
void   IN_3_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define IN_3_BLOCK_CONTROL_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define IN_3_BLOCK_CONTROL_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define IN_3_COMMAND_REG                    (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define IN_3_COMMAND_PTR                    ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define IN_3_INTRRUPT_CAUSE_REG             (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define IN_3_INTRRUPT_CAUSE_PTR             ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define IN_3_CONTROL_REG                    (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__CTRL )
#define IN_3_CONTROL_PTR                    ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__CTRL )
#define IN_3_STATUS_REG                     (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__STATUS )
#define IN_3_STATUS_PTR                     ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__STATUS )
#define IN_3_COUNTER_REG                    (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__COUNTER )
#define IN_3_COUNTER_PTR                    ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__COUNTER )
#define IN_3_COMP_CAP_REG                   (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__CC )
#define IN_3_COMP_CAP_PTR                   ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__CC )
#define IN_3_COMP_CAP_BUF_REG               (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define IN_3_COMP_CAP_BUF_PTR               ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__CC_BUFF )
#define IN_3_PERIOD_REG                     (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__PERIOD )
#define IN_3_PERIOD_PTR                     ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__PERIOD )
#define IN_3_PERIOD_BUF_REG                 (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define IN_3_PERIOD_BUF_PTR                 ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define IN_3_TRIG_CONTROL0_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define IN_3_TRIG_CONTROL0_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define IN_3_TRIG_CONTROL1_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define IN_3_TRIG_CONTROL1_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define IN_3_TRIG_CONTROL2_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define IN_3_TRIG_CONTROL2_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define IN_3_INTERRUPT_REQ_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR )
#define IN_3_INTERRUPT_REQ_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR )
#define IN_3_INTERRUPT_SET_REG              (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_SET )
#define IN_3_INTERRUPT_SET_PTR              ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_SET )
#define IN_3_INTERRUPT_MASK_REG             (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define IN_3_INTERRUPT_MASK_PTR             ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_MASK )
#define IN_3_INTERRUPT_MASKED_REG           (*(reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define IN_3_INTERRUPT_MASKED_PTR           ( (reg32 *) IN_3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define IN_3_MASK                           ((uint32)IN_3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define IN_3_RELOAD_CC_SHIFT                (0u)
#define IN_3_RELOAD_PERIOD_SHIFT            (1u)
#define IN_3_PWM_SYNC_KILL_SHIFT            (2u)
#define IN_3_PWM_STOP_KILL_SHIFT            (3u)
#define IN_3_PRESCALER_SHIFT                (8u)
#define IN_3_UPDOWN_SHIFT                   (16u)
#define IN_3_ONESHOT_SHIFT                  (18u)
#define IN_3_QUAD_MODE_SHIFT                (20u)
#define IN_3_INV_OUT_SHIFT                  (20u)
#define IN_3_INV_COMPL_OUT_SHIFT            (21u)
#define IN_3_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define IN_3_RELOAD_CC_MASK                 ((uint32)(IN_3_1BIT_MASK        <<  \
                                                                            IN_3_RELOAD_CC_SHIFT))
#define IN_3_RELOAD_PERIOD_MASK             ((uint32)(IN_3_1BIT_MASK        <<  \
                                                                            IN_3_RELOAD_PERIOD_SHIFT))
#define IN_3_PWM_SYNC_KILL_MASK             ((uint32)(IN_3_1BIT_MASK        <<  \
                                                                            IN_3_PWM_SYNC_KILL_SHIFT))
#define IN_3_PWM_STOP_KILL_MASK             ((uint32)(IN_3_1BIT_MASK        <<  \
                                                                            IN_3_PWM_STOP_KILL_SHIFT))
#define IN_3_PRESCALER_MASK                 ((uint32)(IN_3_8BIT_MASK        <<  \
                                                                            IN_3_PRESCALER_SHIFT))
#define IN_3_UPDOWN_MASK                    ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                            IN_3_UPDOWN_SHIFT))
#define IN_3_ONESHOT_MASK                   ((uint32)(IN_3_1BIT_MASK        <<  \
                                                                            IN_3_ONESHOT_SHIFT))
#define IN_3_QUAD_MODE_MASK                 ((uint32)(IN_3_3BIT_MASK        <<  \
                                                                            IN_3_QUAD_MODE_SHIFT))
#define IN_3_INV_OUT_MASK                   ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                            IN_3_INV_OUT_SHIFT))
#define IN_3_MODE_MASK                      ((uint32)(IN_3_3BIT_MASK        <<  \
                                                                            IN_3_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define IN_3_CAPTURE_SHIFT                  (0u)
#define IN_3_COUNT_SHIFT                    (2u)
#define IN_3_RELOAD_SHIFT                   (4u)
#define IN_3_STOP_SHIFT                     (6u)
#define IN_3_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define IN_3_CAPTURE_MASK                   ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                  IN_3_CAPTURE_SHIFT))
#define IN_3_COUNT_MASK                     ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                  IN_3_COUNT_SHIFT))
#define IN_3_RELOAD_MASK                    ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                  IN_3_RELOAD_SHIFT))
#define IN_3_STOP_MASK                      ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                  IN_3_STOP_SHIFT))
#define IN_3_START_MASK                     ((uint32)(IN_3_2BIT_MASK        <<  \
                                                                  IN_3_START_SHIFT))

/* MASK */
#define IN_3_1BIT_MASK                      ((uint32)0x01u)
#define IN_3_2BIT_MASK                      ((uint32)0x03u)
#define IN_3_3BIT_MASK                      ((uint32)0x07u)
#define IN_3_6BIT_MASK                      ((uint32)0x3Fu)
#define IN_3_8BIT_MASK                      ((uint32)0xFFu)
#define IN_3_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define IN_3_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define IN_3_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(IN_3_QUAD_ENCODING_MODES     << IN_3_QUAD_MODE_SHIFT))       |\
         ((uint32)(IN_3_CONFIG                  << IN_3_MODE_SHIFT)))

#define IN_3_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(IN_3_PWM_STOP_EVENT          << IN_3_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(IN_3_PWM_OUT_INVERT          << IN_3_INV_OUT_SHIFT))         |\
         ((uint32)(IN_3_PWM_OUT_N_INVERT        << IN_3_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(IN_3_PWM_MODE                << IN_3_MODE_SHIFT)))

#define IN_3_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(IN_3_PWM_RUN_MODE         << IN_3_ONESHOT_SHIFT))
            
#define IN_3_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(IN_3_PWM_ALIGN            << IN_3_UPDOWN_SHIFT))

#define IN_3_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(IN_3_PWM_KILL_EVENT      << IN_3_PWM_SYNC_KILL_SHIFT))

#define IN_3_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(IN_3_PWM_DEAD_TIME_CYCLE  << IN_3_PRESCALER_SHIFT))

#define IN_3_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(IN_3_PWM_PRESCALER        << IN_3_PRESCALER_SHIFT))

#define IN_3_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(IN_3_TC_PRESCALER            << IN_3_PRESCALER_SHIFT))       |\
         ((uint32)(IN_3_TC_COUNTER_MODE         << IN_3_UPDOWN_SHIFT))          |\
         ((uint32)(IN_3_TC_RUN_MODE             << IN_3_ONESHOT_SHIFT))         |\
         ((uint32)(IN_3_TC_COMP_CAP_MODE        << IN_3_MODE_SHIFT)))
        
#define IN_3_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(IN_3_QUAD_PHIA_SIGNAL_MODE   << IN_3_COUNT_SHIFT))           |\
         ((uint32)(IN_3_QUAD_INDEX_SIGNAL_MODE  << IN_3_RELOAD_SHIFT))          |\
         ((uint32)(IN_3_QUAD_STOP_SIGNAL_MODE   << IN_3_STOP_SHIFT))            |\
         ((uint32)(IN_3_QUAD_PHIB_SIGNAL_MODE   << IN_3_START_SHIFT)))

#define IN_3_PWM_SIGNALS_MODES                                                              \
        (((uint32)(IN_3_PWM_SWITCH_SIGNAL_MODE  << IN_3_CAPTURE_SHIFT))         |\
         ((uint32)(IN_3_PWM_COUNT_SIGNAL_MODE   << IN_3_COUNT_SHIFT))           |\
         ((uint32)(IN_3_PWM_RELOAD_SIGNAL_MODE  << IN_3_RELOAD_SHIFT))          |\
         ((uint32)(IN_3_PWM_STOP_SIGNAL_MODE    << IN_3_STOP_SHIFT))            |\
         ((uint32)(IN_3_PWM_START_SIGNAL_MODE   << IN_3_START_SHIFT)))

#define IN_3_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(IN_3_TC_CAPTURE_SIGNAL_MODE  << IN_3_CAPTURE_SHIFT))         |\
         ((uint32)(IN_3_TC_COUNT_SIGNAL_MODE    << IN_3_COUNT_SHIFT))           |\
         ((uint32)(IN_3_TC_RELOAD_SIGNAL_MODE   << IN_3_RELOAD_SHIFT))          |\
         ((uint32)(IN_3_TC_STOP_SIGNAL_MODE     << IN_3_STOP_SHIFT))            |\
         ((uint32)(IN_3_TC_START_SIGNAL_MODE    << IN_3_START_SHIFT)))
        
#define IN_3_TIMER_UPDOWN_CNT_USED                                                          \
                ((IN_3__COUNT_UPDOWN0 == IN_3_TC_COUNTER_MODE)                  ||\
                 (IN_3__COUNT_UPDOWN1 == IN_3_TC_COUNTER_MODE))

#define IN_3_PWM_UPDOWN_CNT_USED                                                            \
                ((IN_3__CENTER == IN_3_PWM_ALIGN)                               ||\
                 (IN_3__ASYMMETRIC == IN_3_PWM_ALIGN))               
        
#define IN_3_PWM_PR_INIT_VALUE              (1u)
#define IN_3_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_IN_3_H */

/* [] END OF FILE */
