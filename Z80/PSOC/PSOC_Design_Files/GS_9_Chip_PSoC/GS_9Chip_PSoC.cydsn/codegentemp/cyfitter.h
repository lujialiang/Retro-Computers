/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* M1_n */
#define M1_n__0__INTTYPE CYREG_PICU0_INTTYPE0
#define M1_n__0__MASK 0x01u
#define M1_n__0__PC CYREG_PRT0_PC0
#define M1_n__0__PORT 0u
#define M1_n__0__SHIFT 0u
#define M1_n__AG CYREG_PRT0_AG
#define M1_n__AMUX CYREG_PRT0_AMUX
#define M1_n__BIE CYREG_PRT0_BIE
#define M1_n__BIT_MASK CYREG_PRT0_BIT_MASK
#define M1_n__BYP CYREG_PRT0_BYP
#define M1_n__CTL CYREG_PRT0_CTL
#define M1_n__DM0 CYREG_PRT0_DM0
#define M1_n__DM1 CYREG_PRT0_DM1
#define M1_n__DM2 CYREG_PRT0_DM2
#define M1_n__DR CYREG_PRT0_DR
#define M1_n__INP_DIS CYREG_PRT0_INP_DIS
#define M1_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define M1_n__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define M1_n__LCD_EN CYREG_PRT0_LCD_EN
#define M1_n__MASK 0x01u
#define M1_n__PORT 0u
#define M1_n__PRT CYREG_PRT0_PRT
#define M1_n__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define M1_n__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define M1_n__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define M1_n__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define M1_n__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define M1_n__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define M1_n__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define M1_n__PS CYREG_PRT0_PS
#define M1_n__SHIFT 0u
#define M1_n__SLW CYREG_PRT0_SLW

/* CLK_5 */
#define CLK_5__0__INTTYPE CYREG_PICU15_INTTYPE4
#define CLK_5__0__MASK 0x10u
#define CLK_5__0__PC CYREG_IO_PC_PRT15_PC4
#define CLK_5__0__PORT 15u
#define CLK_5__0__SHIFT 4u
#define CLK_5__AG CYREG_PRT15_AG
#define CLK_5__AMUX CYREG_PRT15_AMUX
#define CLK_5__BIE CYREG_PRT15_BIE
#define CLK_5__BIT_MASK CYREG_PRT15_BIT_MASK
#define CLK_5__BYP CYREG_PRT15_BYP
#define CLK_5__CTL CYREG_PRT15_CTL
#define CLK_5__DM0 CYREG_PRT15_DM0
#define CLK_5__DM1 CYREG_PRT15_DM1
#define CLK_5__DM2 CYREG_PRT15_DM2
#define CLK_5__DR CYREG_PRT15_DR
#define CLK_5__INP_DIS CYREG_PRT15_INP_DIS
#define CLK_5__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define CLK_5__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define CLK_5__LCD_EN CYREG_PRT15_LCD_EN
#define CLK_5__MASK 0x10u
#define CLK_5__PORT 15u
#define CLK_5__PRT CYREG_PRT15_PRT
#define CLK_5__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define CLK_5__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define CLK_5__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define CLK_5__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define CLK_5__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define CLK_5__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define CLK_5__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define CLK_5__PS CYREG_PRT15_PS
#define CLK_5__SHIFT 4u
#define CLK_5__SLW CYREG_PRT15_SLW

/* CPU_A3 */
#define CPU_A3__0__INTTYPE CYREG_PICU2_INTTYPE3
#define CPU_A3__0__MASK 0x08u
#define CPU_A3__0__PC CYREG_PRT2_PC3
#define CPU_A3__0__PORT 2u
#define CPU_A3__0__SHIFT 3u
#define CPU_A3__AG CYREG_PRT2_AG
#define CPU_A3__AMUX CYREG_PRT2_AMUX
#define CPU_A3__BIE CYREG_PRT2_BIE
#define CPU_A3__BIT_MASK CYREG_PRT2_BIT_MASK
#define CPU_A3__BYP CYREG_PRT2_BYP
#define CPU_A3__CTL CYREG_PRT2_CTL
#define CPU_A3__DM0 CYREG_PRT2_DM0
#define CPU_A3__DM1 CYREG_PRT2_DM1
#define CPU_A3__DM2 CYREG_PRT2_DM2
#define CPU_A3__DR CYREG_PRT2_DR
#define CPU_A3__INP_DIS CYREG_PRT2_INP_DIS
#define CPU_A3__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define CPU_A3__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define CPU_A3__LCD_EN CYREG_PRT2_LCD_EN
#define CPU_A3__MASK 0x08u
#define CPU_A3__PORT 2u
#define CPU_A3__PRT CYREG_PRT2_PRT
#define CPU_A3__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define CPU_A3__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define CPU_A3__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define CPU_A3__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define CPU_A3__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define CPU_A3__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define CPU_A3__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define CPU_A3__PS CYREG_PRT2_PS
#define CPU_A3__SHIFT 3u
#define CPU_A3__SLW CYREG_PRT2_SLW

/* CPU_A4 */
#define CPU_A4__0__INTTYPE CYREG_PICU2_INTTYPE4
#define CPU_A4__0__MASK 0x10u
#define CPU_A4__0__PC CYREG_PRT2_PC4
#define CPU_A4__0__PORT 2u
#define CPU_A4__0__SHIFT 4u
#define CPU_A4__AG CYREG_PRT2_AG
#define CPU_A4__AMUX CYREG_PRT2_AMUX
#define CPU_A4__BIE CYREG_PRT2_BIE
#define CPU_A4__BIT_MASK CYREG_PRT2_BIT_MASK
#define CPU_A4__BYP CYREG_PRT2_BYP
#define CPU_A4__CTL CYREG_PRT2_CTL
#define CPU_A4__DM0 CYREG_PRT2_DM0
#define CPU_A4__DM1 CYREG_PRT2_DM1
#define CPU_A4__DM2 CYREG_PRT2_DM2
#define CPU_A4__DR CYREG_PRT2_DR
#define CPU_A4__INP_DIS CYREG_PRT2_INP_DIS
#define CPU_A4__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define CPU_A4__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define CPU_A4__LCD_EN CYREG_PRT2_LCD_EN
#define CPU_A4__MASK 0x10u
#define CPU_A4__PORT 2u
#define CPU_A4__PRT CYREG_PRT2_PRT
#define CPU_A4__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define CPU_A4__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define CPU_A4__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define CPU_A4__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define CPU_A4__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define CPU_A4__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define CPU_A4__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define CPU_A4__PS CYREG_PRT2_PS
#define CPU_A4__SHIFT 4u
#define CPU_A4__SLW CYREG_PRT2_SLW

/* CPU_A5 */
#define CPU_A5__0__INTTYPE CYREG_PICU2_INTTYPE5
#define CPU_A5__0__MASK 0x20u
#define CPU_A5__0__PC CYREG_PRT2_PC5
#define CPU_A5__0__PORT 2u
#define CPU_A5__0__SHIFT 5u
#define CPU_A5__AG CYREG_PRT2_AG
#define CPU_A5__AMUX CYREG_PRT2_AMUX
#define CPU_A5__BIE CYREG_PRT2_BIE
#define CPU_A5__BIT_MASK CYREG_PRT2_BIT_MASK
#define CPU_A5__BYP CYREG_PRT2_BYP
#define CPU_A5__CTL CYREG_PRT2_CTL
#define CPU_A5__DM0 CYREG_PRT2_DM0
#define CPU_A5__DM1 CYREG_PRT2_DM1
#define CPU_A5__DM2 CYREG_PRT2_DM2
#define CPU_A5__DR CYREG_PRT2_DR
#define CPU_A5__INP_DIS CYREG_PRT2_INP_DIS
#define CPU_A5__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define CPU_A5__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define CPU_A5__LCD_EN CYREG_PRT2_LCD_EN
#define CPU_A5__MASK 0x20u
#define CPU_A5__PORT 2u
#define CPU_A5__PRT CYREG_PRT2_PRT
#define CPU_A5__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define CPU_A5__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define CPU_A5__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define CPU_A5__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define CPU_A5__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define CPU_A5__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define CPU_A5__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define CPU_A5__PS CYREG_PRT2_PS
#define CPU_A5__SHIFT 5u
#define CPU_A5__SLW CYREG_PRT2_SLW

/* CPU_A6 */
#define CPU_A6__0__INTTYPE CYREG_PICU2_INTTYPE7
#define CPU_A6__0__MASK 0x80u
#define CPU_A6__0__PC CYREG_PRT2_PC7
#define CPU_A6__0__PORT 2u
#define CPU_A6__0__SHIFT 7u
#define CPU_A6__AG CYREG_PRT2_AG
#define CPU_A6__AMUX CYREG_PRT2_AMUX
#define CPU_A6__BIE CYREG_PRT2_BIE
#define CPU_A6__BIT_MASK CYREG_PRT2_BIT_MASK
#define CPU_A6__BYP CYREG_PRT2_BYP
#define CPU_A6__CTL CYREG_PRT2_CTL
#define CPU_A6__DM0 CYREG_PRT2_DM0
#define CPU_A6__DM1 CYREG_PRT2_DM1
#define CPU_A6__DM2 CYREG_PRT2_DM2
#define CPU_A6__DR CYREG_PRT2_DR
#define CPU_A6__INP_DIS CYREG_PRT2_INP_DIS
#define CPU_A6__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define CPU_A6__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define CPU_A6__LCD_EN CYREG_PRT2_LCD_EN
#define CPU_A6__MASK 0x80u
#define CPU_A6__PORT 2u
#define CPU_A6__PRT CYREG_PRT2_PRT
#define CPU_A6__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define CPU_A6__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define CPU_A6__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define CPU_A6__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define CPU_A6__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define CPU_A6__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define CPU_A6__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define CPU_A6__PS CYREG_PRT2_PS
#define CPU_A6__SHIFT 7u
#define CPU_A6__SLW CYREG_PRT2_SLW

/* CPU_A7 */
#define CPU_A7__0__INTTYPE CYREG_PICU2_INTTYPE6
#define CPU_A7__0__MASK 0x40u
#define CPU_A7__0__PC CYREG_PRT2_PC6
#define CPU_A7__0__PORT 2u
#define CPU_A7__0__SHIFT 6u
#define CPU_A7__AG CYREG_PRT2_AG
#define CPU_A7__AMUX CYREG_PRT2_AMUX
#define CPU_A7__BIE CYREG_PRT2_BIE
#define CPU_A7__BIT_MASK CYREG_PRT2_BIT_MASK
#define CPU_A7__BYP CYREG_PRT2_BYP
#define CPU_A7__CTL CYREG_PRT2_CTL
#define CPU_A7__DM0 CYREG_PRT2_DM0
#define CPU_A7__DM1 CYREG_PRT2_DM1
#define CPU_A7__DM2 CYREG_PRT2_DM2
#define CPU_A7__DR CYREG_PRT2_DR
#define CPU_A7__INP_DIS CYREG_PRT2_INP_DIS
#define CPU_A7__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define CPU_A7__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define CPU_A7__LCD_EN CYREG_PRT2_LCD_EN
#define CPU_A7__MASK 0x40u
#define CPU_A7__PORT 2u
#define CPU_A7__PRT CYREG_PRT2_PRT
#define CPU_A7__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define CPU_A7__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define CPU_A7__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define CPU_A7__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define CPU_A7__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define CPU_A7__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define CPU_A7__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define CPU_A7__PS CYREG_PRT2_PS
#define CPU_A7__SHIFT 6u
#define CPU_A7__SLW CYREG_PRT2_SLW

/* IOCS_n */
#define IOCS_n__0__INTTYPE CYREG_PICU12_INTTYPE7
#define IOCS_n__0__MASK 0x80u
#define IOCS_n__0__PC CYREG_PRT12_PC7
#define IOCS_n__0__PORT 12u
#define IOCS_n__0__SHIFT 7u
#define IOCS_n__AG CYREG_PRT12_AG
#define IOCS_n__BIE CYREG_PRT12_BIE
#define IOCS_n__BIT_MASK CYREG_PRT12_BIT_MASK
#define IOCS_n__BYP CYREG_PRT12_BYP
#define IOCS_n__DM0 CYREG_PRT12_DM0
#define IOCS_n__DM1 CYREG_PRT12_DM1
#define IOCS_n__DM2 CYREG_PRT12_DM2
#define IOCS_n__DR CYREG_PRT12_DR
#define IOCS_n__INP_DIS CYREG_PRT12_INP_DIS
#define IOCS_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define IOCS_n__MASK 0x80u
#define IOCS_n__PORT 12u
#define IOCS_n__PRT CYREG_PRT12_PRT
#define IOCS_n__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define IOCS_n__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define IOCS_n__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define IOCS_n__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define IOCS_n__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define IOCS_n__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define IOCS_n__PS CYREG_PRT12_PS
#define IOCS_n__SHIFT 7u
#define IOCS_n__SIO_CFG CYREG_PRT12_SIO_CFG
#define IOCS_n__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define IOCS_n__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define IOCS_n__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define IOCS_n__SLW CYREG_PRT12_SLW

/* IORQ_n */
#define IORQ_n__0__INTTYPE CYREG_PICU4_INTTYPE4
#define IORQ_n__0__MASK 0x10u
#define IORQ_n__0__PC CYREG_PRT4_PC4
#define IORQ_n__0__PORT 4u
#define IORQ_n__0__SHIFT 4u
#define IORQ_n__AG CYREG_PRT4_AG
#define IORQ_n__AMUX CYREG_PRT4_AMUX
#define IORQ_n__BIE CYREG_PRT4_BIE
#define IORQ_n__BIT_MASK CYREG_PRT4_BIT_MASK
#define IORQ_n__BYP CYREG_PRT4_BYP
#define IORQ_n__CTL CYREG_PRT4_CTL
#define IORQ_n__DM0 CYREG_PRT4_DM0
#define IORQ_n__DM1 CYREG_PRT4_DM1
#define IORQ_n__DM2 CYREG_PRT4_DM2
#define IORQ_n__DR CYREG_PRT4_DR
#define IORQ_n__INP_DIS CYREG_PRT4_INP_DIS
#define IORQ_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU4_BASE
#define IORQ_n__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define IORQ_n__LCD_EN CYREG_PRT4_LCD_EN
#define IORQ_n__MASK 0x10u
#define IORQ_n__PORT 4u
#define IORQ_n__PRT CYREG_PRT4_PRT
#define IORQ_n__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define IORQ_n__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define IORQ_n__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define IORQ_n__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define IORQ_n__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define IORQ_n__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define IORQ_n__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define IORQ_n__PS CYREG_PRT4_PS
#define IORQ_n__SHIFT 4u
#define IORQ_n__SLW CYREG_PRT4_SLW

/* MREQ_n */
#define MREQ_n__0__INTTYPE CYREG_PICU4_INTTYPE7
#define MREQ_n__0__MASK 0x80u
#define MREQ_n__0__PC CYREG_PRT4_PC7
#define MREQ_n__0__PORT 4u
#define MREQ_n__0__SHIFT 7u
#define MREQ_n__AG CYREG_PRT4_AG
#define MREQ_n__AMUX CYREG_PRT4_AMUX
#define MREQ_n__BIE CYREG_PRT4_BIE
#define MREQ_n__BIT_MASK CYREG_PRT4_BIT_MASK
#define MREQ_n__BYP CYREG_PRT4_BYP
#define MREQ_n__CTL CYREG_PRT4_CTL
#define MREQ_n__DM0 CYREG_PRT4_DM0
#define MREQ_n__DM1 CYREG_PRT4_DM1
#define MREQ_n__DM2 CYREG_PRT4_DM2
#define MREQ_n__DR CYREG_PRT4_DR
#define MREQ_n__INP_DIS CYREG_PRT4_INP_DIS
#define MREQ_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU4_BASE
#define MREQ_n__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define MREQ_n__LCD_EN CYREG_PRT4_LCD_EN
#define MREQ_n__MASK 0x80u
#define MREQ_n__PORT 4u
#define MREQ_n__PRT CYREG_PRT4_PRT
#define MREQ_n__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define MREQ_n__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define MREQ_n__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define MREQ_n__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define MREQ_n__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define MREQ_n__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define MREQ_n__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define MREQ_n__PS CYREG_PRT4_PS
#define MREQ_n__SHIFT 7u
#define MREQ_n__SLW CYREG_PRT4_SLW

/* CPUWR_n */
#define CPUWR_n__0__INTTYPE CYREG_PICU4_INTTYPE3
#define CPUWR_n__0__MASK 0x08u
#define CPUWR_n__0__PC CYREG_PRT4_PC3
#define CPUWR_n__0__PORT 4u
#define CPUWR_n__0__SHIFT 3u
#define CPUWR_n__AG CYREG_PRT4_AG
#define CPUWR_n__AMUX CYREG_PRT4_AMUX
#define CPUWR_n__BIE CYREG_PRT4_BIE
#define CPUWR_n__BIT_MASK CYREG_PRT4_BIT_MASK
#define CPUWR_n__BYP CYREG_PRT4_BYP
#define CPUWR_n__CTL CYREG_PRT4_CTL
#define CPUWR_n__DM0 CYREG_PRT4_DM0
#define CPUWR_n__DM1 CYREG_PRT4_DM1
#define CPUWR_n__DM2 CYREG_PRT4_DM2
#define CPUWR_n__DR CYREG_PRT4_DR
#define CPUWR_n__INP_DIS CYREG_PRT4_INP_DIS
#define CPUWR_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU4_BASE
#define CPUWR_n__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define CPUWR_n__LCD_EN CYREG_PRT4_LCD_EN
#define CPUWR_n__MASK 0x08u
#define CPUWR_n__PORT 4u
#define CPUWR_n__PRT CYREG_PRT4_PRT
#define CPUWR_n__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define CPUWR_n__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define CPUWR_n__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define CPUWR_n__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define CPUWR_n__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define CPUWR_n__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define CPUWR_n__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define CPUWR_n__PS CYREG_PRT4_PS
#define CPUWR_n__SHIFT 3u
#define CPUWR_n__SLW CYREG_PRT4_SLW

/* CPU_A14 */
#define CPU_A14__0__INTTYPE CYREG_PICU3_INTTYPE6
#define CPU_A14__0__MASK 0x40u
#define CPU_A14__0__PC CYREG_PRT3_PC6
#define CPU_A14__0__PORT 3u
#define CPU_A14__0__SHIFT 6u
#define CPU_A14__AG CYREG_PRT3_AG
#define CPU_A14__AMUX CYREG_PRT3_AMUX
#define CPU_A14__BIE CYREG_PRT3_BIE
#define CPU_A14__BIT_MASK CYREG_PRT3_BIT_MASK
#define CPU_A14__BYP CYREG_PRT3_BYP
#define CPU_A14__CTL CYREG_PRT3_CTL
#define CPU_A14__DM0 CYREG_PRT3_DM0
#define CPU_A14__DM1 CYREG_PRT3_DM1
#define CPU_A14__DM2 CYREG_PRT3_DM2
#define CPU_A14__DR CYREG_PRT3_DR
#define CPU_A14__INP_DIS CYREG_PRT3_INP_DIS
#define CPU_A14__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define CPU_A14__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define CPU_A14__LCD_EN CYREG_PRT3_LCD_EN
#define CPU_A14__MASK 0x40u
#define CPU_A14__PORT 3u
#define CPU_A14__PRT CYREG_PRT3_PRT
#define CPU_A14__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define CPU_A14__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define CPU_A14__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define CPU_A14__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define CPU_A14__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define CPU_A14__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define CPU_A14__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define CPU_A14__PS CYREG_PRT3_PS
#define CPU_A14__SHIFT 6u
#define CPU_A14__SLW CYREG_PRT3_SLW

/* CPU_A15 */
#define CPU_A15__0__INTTYPE CYREG_PICU3_INTTYPE7
#define CPU_A15__0__MASK 0x80u
#define CPU_A15__0__PC CYREG_PRT3_PC7
#define CPU_A15__0__PORT 3u
#define CPU_A15__0__SHIFT 7u
#define CPU_A15__AG CYREG_PRT3_AG
#define CPU_A15__AMUX CYREG_PRT3_AMUX
#define CPU_A15__BIE CYREG_PRT3_BIE
#define CPU_A15__BIT_MASK CYREG_PRT3_BIT_MASK
#define CPU_A15__BYP CYREG_PRT3_BYP
#define CPU_A15__CTL CYREG_PRT3_CTL
#define CPU_A15__DM0 CYREG_PRT3_DM0
#define CPU_A15__DM1 CYREG_PRT3_DM1
#define CPU_A15__DM2 CYREG_PRT3_DM2
#define CPU_A15__DR CYREG_PRT3_DR
#define CPU_A15__INP_DIS CYREG_PRT3_INP_DIS
#define CPU_A15__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define CPU_A15__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define CPU_A15__LCD_EN CYREG_PRT3_LCD_EN
#define CPU_A15__MASK 0x80u
#define CPU_A15__PORT 3u
#define CPU_A15__PRT CYREG_PRT3_PRT
#define CPU_A15__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define CPU_A15__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define CPU_A15__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define CPU_A15__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define CPU_A15__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define CPU_A15__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define CPU_A15__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define CPU_A15__PS CYREG_PRT3_PS
#define CPU_A15__SHIFT 7u
#define CPU_A15__SLW CYREG_PRT3_SLW

/* CPU_CLK */
#define CPU_CLK__0__INTTYPE CYREG_PICU5_INTTYPE6
#define CPU_CLK__0__MASK 0x40u
#define CPU_CLK__0__PC CYREG_PRT5_PC6
#define CPU_CLK__0__PORT 5u
#define CPU_CLK__0__SHIFT 6u
#define CPU_CLK__AG CYREG_PRT5_AG
#define CPU_CLK__AMUX CYREG_PRT5_AMUX
#define CPU_CLK__BIE CYREG_PRT5_BIE
#define CPU_CLK__BIT_MASK CYREG_PRT5_BIT_MASK
#define CPU_CLK__BYP CYREG_PRT5_BYP
#define CPU_CLK__CTL CYREG_PRT5_CTL
#define CPU_CLK__DM0 CYREG_PRT5_DM0
#define CPU_CLK__DM1 CYREG_PRT5_DM1
#define CPU_CLK__DM2 CYREG_PRT5_DM2
#define CPU_CLK__DR CYREG_PRT5_DR
#define CPU_CLK__INP_DIS CYREG_PRT5_INP_DIS
#define CPU_CLK__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU5_BASE
#define CPU_CLK__LCD_COM_SEG CYREG_PRT5_LCD_COM_SEG
#define CPU_CLK__LCD_EN CYREG_PRT5_LCD_EN
#define CPU_CLK__MASK 0x40u
#define CPU_CLK__PORT 5u
#define CPU_CLK__PRT CYREG_PRT5_PRT
#define CPU_CLK__PRTDSI__CAPS_SEL CYREG_PRT5_CAPS_SEL
#define CPU_CLK__PRTDSI__DBL_SYNC_IN CYREG_PRT5_DBL_SYNC_IN
#define CPU_CLK__PRTDSI__OE_SEL0 CYREG_PRT5_OE_SEL0
#define CPU_CLK__PRTDSI__OE_SEL1 CYREG_PRT5_OE_SEL1
#define CPU_CLK__PRTDSI__OUT_SEL0 CYREG_PRT5_OUT_SEL0
#define CPU_CLK__PRTDSI__OUT_SEL1 CYREG_PRT5_OUT_SEL1
#define CPU_CLK__PRTDSI__SYNC_OUT CYREG_PRT5_SYNC_OUT
#define CPU_CLK__PS CYREG_PRT5_PS
#define CPU_CLK__SHIFT 6u
#define CPU_CLK__SLW CYREG_PRT5_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* EEPCS_n */
#define EEPCS_n__0__INTTYPE CYREG_PICU4_INTTYPE2
#define EEPCS_n__0__MASK 0x04u
#define EEPCS_n__0__PC CYREG_PRT4_PC2
#define EEPCS_n__0__PORT 4u
#define EEPCS_n__0__SHIFT 2u
#define EEPCS_n__AG CYREG_PRT4_AG
#define EEPCS_n__AMUX CYREG_PRT4_AMUX
#define EEPCS_n__BIE CYREG_PRT4_BIE
#define EEPCS_n__BIT_MASK CYREG_PRT4_BIT_MASK
#define EEPCS_n__BYP CYREG_PRT4_BYP
#define EEPCS_n__CTL CYREG_PRT4_CTL
#define EEPCS_n__DM0 CYREG_PRT4_DM0
#define EEPCS_n__DM1 CYREG_PRT4_DM1
#define EEPCS_n__DM2 CYREG_PRT4_DM2
#define EEPCS_n__DR CYREG_PRT4_DR
#define EEPCS_n__INP_DIS CYREG_PRT4_INP_DIS
#define EEPCS_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU4_BASE
#define EEPCS_n__LCD_COM_SEG CYREG_PRT4_LCD_COM_SEG
#define EEPCS_n__LCD_EN CYREG_PRT4_LCD_EN
#define EEPCS_n__MASK 0x04u
#define EEPCS_n__PORT 4u
#define EEPCS_n__PRT CYREG_PRT4_PRT
#define EEPCS_n__PRTDSI__CAPS_SEL CYREG_PRT4_CAPS_SEL
#define EEPCS_n__PRTDSI__DBL_SYNC_IN CYREG_PRT4_DBL_SYNC_IN
#define EEPCS_n__PRTDSI__OE_SEL0 CYREG_PRT4_OE_SEL0
#define EEPCS_n__PRTDSI__OE_SEL1 CYREG_PRT4_OE_SEL1
#define EEPCS_n__PRTDSI__OUT_SEL0 CYREG_PRT4_OUT_SEL0
#define EEPCS_n__PRTDSI__OUT_SEL1 CYREG_PRT4_OUT_SEL1
#define EEPCS_n__PRTDSI__SYNC_OUT CYREG_PRT4_SYNC_OUT
#define EEPCS_n__PS CYREG_PRT4_PS
#define EEPCS_n__SHIFT 2u
#define EEPCS_n__SLW CYREG_PRT4_SLW

/* SIOCS_n */
#define SIOCS_n__0__INTTYPE CYREG_PICU12_INTTYPE3
#define SIOCS_n__0__MASK 0x08u
#define SIOCS_n__0__PC CYREG_PRT12_PC3
#define SIOCS_n__0__PORT 12u
#define SIOCS_n__0__SHIFT 3u
#define SIOCS_n__AG CYREG_PRT12_AG
#define SIOCS_n__BIE CYREG_PRT12_BIE
#define SIOCS_n__BIT_MASK CYREG_PRT12_BIT_MASK
#define SIOCS_n__BYP CYREG_PRT12_BYP
#define SIOCS_n__DM0 CYREG_PRT12_DM0
#define SIOCS_n__DM1 CYREG_PRT12_DM1
#define SIOCS_n__DM2 CYREG_PRT12_DM2
#define SIOCS_n__DR CYREG_PRT12_DR
#define SIOCS_n__INP_DIS CYREG_PRT12_INP_DIS
#define SIOCS_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define SIOCS_n__MASK 0x08u
#define SIOCS_n__PORT 12u
#define SIOCS_n__PRT CYREG_PRT12_PRT
#define SIOCS_n__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define SIOCS_n__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define SIOCS_n__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define SIOCS_n__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define SIOCS_n__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define SIOCS_n__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define SIOCS_n__PS CYREG_PRT12_PS
#define SIOCS_n__SHIFT 3u
#define SIOCS_n__SIO_CFG CYREG_PRT12_SIO_CFG
#define SIOCS_n__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define SIOCS_n__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define SIOCS_n__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define SIOCS_n__SLW CYREG_PRT12_SLW

/* CRESET_n */
#define CRESET_n__0__INTTYPE CYREG_PICU5_INTTYPE7
#define CRESET_n__0__MASK 0x80u
#define CRESET_n__0__PC CYREG_PRT5_PC7
#define CRESET_n__0__PORT 5u
#define CRESET_n__0__SHIFT 7u
#define CRESET_n__AG CYREG_PRT5_AG
#define CRESET_n__AMUX CYREG_PRT5_AMUX
#define CRESET_n__BIE CYREG_PRT5_BIE
#define CRESET_n__BIT_MASK CYREG_PRT5_BIT_MASK
#define CRESET_n__BYP CYREG_PRT5_BYP
#define CRESET_n__CTL CYREG_PRT5_CTL
#define CRESET_n__DM0 CYREG_PRT5_DM0
#define CRESET_n__DM1 CYREG_PRT5_DM1
#define CRESET_n__DM2 CYREG_PRT5_DM2
#define CRESET_n__DR CYREG_PRT5_DR
#define CRESET_n__INP_DIS CYREG_PRT5_INP_DIS
#define CRESET_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU5_BASE
#define CRESET_n__LCD_COM_SEG CYREG_PRT5_LCD_COM_SEG
#define CRESET_n__LCD_EN CYREG_PRT5_LCD_EN
#define CRESET_n__MASK 0x80u
#define CRESET_n__PORT 5u
#define CRESET_n__PRT CYREG_PRT5_PRT
#define CRESET_n__PRTDSI__CAPS_SEL CYREG_PRT5_CAPS_SEL
#define CRESET_n__PRTDSI__DBL_SYNC_IN CYREG_PRT5_DBL_SYNC_IN
#define CRESET_n__PRTDSI__OE_SEL0 CYREG_PRT5_OE_SEL0
#define CRESET_n__PRTDSI__OE_SEL1 CYREG_PRT5_OE_SEL1
#define CRESET_n__PRTDSI__OUT_SEL0 CYREG_PRT5_OUT_SEL0
#define CRESET_n__PRTDSI__OUT_SEL1 CYREG_PRT5_OUT_SEL1
#define CRESET_n__PRTDSI__SYNC_OUT CYREG_PRT5_SYNC_OUT
#define CRESET_n__PS CYREG_PRT5_PS
#define CRESET_n__SHIFT 7u
#define CRESET_n__SLW CYREG_PRT5_SLW

/* MAIN_CLK */
#define MAIN_CLK__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define MAIN_CLK__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define MAIN_CLK__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define MAIN_CLK__CFG2_SRC_SEL_MASK 0x07u
#define MAIN_CLK__INDEX 0x01u
#define MAIN_CLK__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define MAIN_CLK__PM_ACT_MSK 0x02u
#define MAIN_CLK__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define MAIN_CLK__PM_STBY_MSK 0x02u

/* WRESET_n */
#define WRESET_n__0__INTTYPE CYREG_PICU6_INTTYPE0
#define WRESET_n__0__MASK 0x01u
#define WRESET_n__0__PC CYREG_PRT6_PC0
#define WRESET_n__0__PORT 6u
#define WRESET_n__0__SHIFT 0u
#define WRESET_n__AG CYREG_PRT6_AG
#define WRESET_n__AMUX CYREG_PRT6_AMUX
#define WRESET_n__BIE CYREG_PRT6_BIE
#define WRESET_n__BIT_MASK CYREG_PRT6_BIT_MASK
#define WRESET_n__BYP CYREG_PRT6_BYP
#define WRESET_n__CTL CYREG_PRT6_CTL
#define WRESET_n__DM0 CYREG_PRT6_DM0
#define WRESET_n__DM1 CYREG_PRT6_DM1
#define WRESET_n__DM2 CYREG_PRT6_DM2
#define WRESET_n__DR CYREG_PRT6_DR
#define WRESET_n__INP_DIS CYREG_PRT6_INP_DIS
#define WRESET_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define WRESET_n__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define WRESET_n__LCD_EN CYREG_PRT6_LCD_EN
#define WRESET_n__MASK 0x01u
#define WRESET_n__PORT 6u
#define WRESET_n__PRT CYREG_PRT6_PRT
#define WRESET_n__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define WRESET_n__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define WRESET_n__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define WRESET_n__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define WRESET_n__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define WRESET_n__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define WRESET_n__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define WRESET_n__PS CYREG_PRT6_PS
#define WRESET_n__SHIFT 0u
#define WRESET_n__SLW CYREG_PRT6_SLW

/* SRAMCS1_n */
#define SRAMCS1_n__0__INTTYPE CYREG_PICU12_INTTYPE5
#define SRAMCS1_n__0__MASK 0x20u
#define SRAMCS1_n__0__PC CYREG_PRT12_PC5
#define SRAMCS1_n__0__PORT 12u
#define SRAMCS1_n__0__SHIFT 5u
#define SRAMCS1_n__AG CYREG_PRT12_AG
#define SRAMCS1_n__BIE CYREG_PRT12_BIE
#define SRAMCS1_n__BIT_MASK CYREG_PRT12_BIT_MASK
#define SRAMCS1_n__BYP CYREG_PRT12_BYP
#define SRAMCS1_n__DM0 CYREG_PRT12_DM0
#define SRAMCS1_n__DM1 CYREG_PRT12_DM1
#define SRAMCS1_n__DM2 CYREG_PRT12_DM2
#define SRAMCS1_n__DR CYREG_PRT12_DR
#define SRAMCS1_n__INP_DIS CYREG_PRT12_INP_DIS
#define SRAMCS1_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define SRAMCS1_n__MASK 0x20u
#define SRAMCS1_n__PORT 12u
#define SRAMCS1_n__PRT CYREG_PRT12_PRT
#define SRAMCS1_n__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define SRAMCS1_n__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define SRAMCS1_n__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define SRAMCS1_n__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define SRAMCS1_n__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define SRAMCS1_n__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define SRAMCS1_n__PS CYREG_PRT12_PS
#define SRAMCS1_n__SHIFT 5u
#define SRAMCS1_n__SIO_CFG CYREG_PRT12_SIO_CFG
#define SRAMCS1_n__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define SRAMCS1_n__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define SRAMCS1_n__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define SRAMCS1_n__SLW CYREG_PRT12_SLW

/* SRAMCS2_n */
#define SRAMCS2_n__0__INTTYPE CYREG_PICU12_INTTYPE4
#define SRAMCS2_n__0__MASK 0x10u
#define SRAMCS2_n__0__PC CYREG_PRT12_PC4
#define SRAMCS2_n__0__PORT 12u
#define SRAMCS2_n__0__SHIFT 4u
#define SRAMCS2_n__AG CYREG_PRT12_AG
#define SRAMCS2_n__BIE CYREG_PRT12_BIE
#define SRAMCS2_n__BIT_MASK CYREG_PRT12_BIT_MASK
#define SRAMCS2_n__BYP CYREG_PRT12_BYP
#define SRAMCS2_n__DM0 CYREG_PRT12_DM0
#define SRAMCS2_n__DM1 CYREG_PRT12_DM1
#define SRAMCS2_n__DM2 CYREG_PRT12_DM2
#define SRAMCS2_n__DR CYREG_PRT12_DR
#define SRAMCS2_n__INP_DIS CYREG_PRT12_INP_DIS
#define SRAMCS2_n__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define SRAMCS2_n__MASK 0x10u
#define SRAMCS2_n__PORT 12u
#define SRAMCS2_n__PRT CYREG_PRT12_PRT
#define SRAMCS2_n__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define SRAMCS2_n__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define SRAMCS2_n__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define SRAMCS2_n__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define SRAMCS2_n__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define SRAMCS2_n__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define SRAMCS2_n__PS CYREG_PRT12_PS
#define SRAMCS2_n__SHIFT 4u
#define SRAMCS2_n__SIO_CFG CYREG_PRT12_SIO_CFG
#define SRAMCS2_n__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define SRAMCS2_n__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define SRAMCS2_n__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define SRAMCS2_n__SLW CYREG_PRT12_SLW

/* RESET_CTRL_REG */
#define RESET_CTRL_REG_Sync_ctrl_reg__0__MASK 0x01u
#define RESET_CTRL_REG_Sync_ctrl_reg__0__POS 0
#define RESET_CTRL_REG_Sync_ctrl_reg__1__MASK 0x02u
#define RESET_CTRL_REG_Sync_ctrl_reg__1__POS 1
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB04_05_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB04_05_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B0_UDB04_05_MSK
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB04_05_MSK
#define RESET_CTRL_REG_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define RESET_CTRL_REG_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define RESET_CTRL_REG_Sync_ctrl_reg__CONTROL_REG CYREG_B0_UDB04_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B0_UDB04_ST_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__COUNT_REG CYREG_B0_UDB04_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__COUNT_ST_REG CYREG_B0_UDB04_ST_CTL
#define RESET_CTRL_REG_Sync_ctrl_reg__MASK 0x03u
#define RESET_CTRL_REG_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define RESET_CTRL_REG_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define RESET_CTRL_REG_Sync_ctrl_reg__PERIOD_REG CYREG_B0_UDB04_MSK

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 66352499U
#define BCLK__BUS_CLK__KHZ 66352U
#define BCLK__BUS_CLK__MHZ 66U
#define CY_PROJECT_NAME "GS_9Chip_PSoC"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E133069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000000u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP 
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
