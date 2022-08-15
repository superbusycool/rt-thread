/***************************************************************************//**
* \file cyhal_hwmgr_impl_part.h
*
* \brief
* Provides device specific information to the hardware manager. This file must
* only ever be included by cyhal_hwmgr.c.
*
********************************************************************************
* \copyright
* Copyright 2018-2021 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*******************************************************************************
*       Defines
*******************************************************************************/

#include "cyhal_hwmgr_impl.h"
#include "cyhal_interconnect.h"
#include "cyhal_scb_common.h"

#if defined(CY_IP_MXS40PASS_SAR_INSTANCES)
    #define CY_BLOCK_COUNT_ADC  (CY_IP_MXS40PASS_SAR_INSTANCES)
#elif defined (CY_IP_M0S8PASS4A_SAR_INSTANCES)
    #define CY_BLOCK_COUNT_ADC  (CY_IP_M0S8PASS4A_SAR_INSTANCES)
#else
    #define CY_BLOCK_COUNT_ADC      (0)
#endif

#if defined(CY_IP_MXS40ADCMIC_INSTANCES)
    #define CY_BLOCK_COUNT_ADCMIC (CY_IP_MXS40ADCMIC_INSTANCES)
#else
    #define CY_BLOCK_COUNT_ADCMIC (0)
#endif

#if defined(CY_IP_MXBLESS_INSTANCES)
    #define CY_BLOCK_COUNT_BLE      CY_IP_MXBLESS_INSTANCES
#else
    #define CY_BLOCK_COUNT_BLE      (0)
#endif

#if defined(CY_IP_MXTTCANFD_INSTANCES)
    #define CY_BLOCK_COUNT_CAN      (CY_IP_MXTTCANFD_INSTANCES)
    #if (CY_IP_MXTTCANFD_INSTANCES == 0)
        #define CY_CHANNEL_COUNT_CAN (0u)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 1)
        #define CY_CHANNEL_COUNT_CAN (CANFD_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 2)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 3)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 4)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 5)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 6)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 7)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 8)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR + CANFD7_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 9)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR + CANFD7_CAN_NR + CANFD8_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES == 10)
        #define CY_CHANNEL_COUNT_CAN (CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR + CANFD7_CAN_NR + CANFD8_CAN_NR + CANFD9_CAN_NR)
    #elif (CY_IP_MXTTCANFD_INSTANCES > 10)
        #warning Unhandled CAN instance count
    #endif
#elif defined(CY_IP_M0S8CAN_INSTANCES)
    #define CY_BLOCK_COUNT_CAN      (CY_IP_M0S8CAN_INSTANCES)
    #define CY_CHANNEL_COUNT_CAN    (1)
#else
    #define CY_BLOCK_COUNT_CAN      (0)
    #define CY_CHANNEL_COUNT_CAN    (0)
#endif

#if defined(COMPONENT_CAT1A)
#define PERI_DIV_NR (PERI_DIV_8_NR + PERI_DIV_16_NR + PERI_DIV_16_5_NR + PERI_DIV_24_5_NR)

#elif defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C)
#if (PERI_PERI_PCLK_PCLK_GROUP_NR == 0)
    #define PERI_DIV_NR  (0)
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR == 1)
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 2
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 3
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 4
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 5
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 6
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 7
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 8
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 9
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 10
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 11
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 12
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 13
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 14
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 15
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13) + CY_MXSPERI_PCLK_DIV_CNT(14))
#else
    #warning "PCLK table size exceeded"
#endif
#endif

#if defined(COMPONENT_CAT1A)
// 12 dedicated = IMO, EXT, ILO, FLL, LF, Pump, BAK, Timer, AltSysTick, Slow, Fast, Peri
//  7 optional =  ECO, ALTHF, ALTLF, PILO, WCO, MFO, MF
#define CY_CHANNEL_COUNT_CLOCK      (12 + 7 + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + PERI_DIV_NR)
#elif defined(COMPONENT_CAT1B)
// 10 dedicated = IHO, IMO, EXT, ILO, FLL, LF, Pump, BAK, AltSysTick, Peri
//  7 optional =  ECO, ALTHF, ALTLF, PILO, WCO, MFO, MF
#define CY_CHANNEL_COUNT_CLOCK      (10 + 7 + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + PERI_DIV_NR)
// TODO : to be fixed
#elif defined(COMPONENT_CAT1C)
// 15 dedicated = IMO, EXT, ILO, IL01, FLL, LF, Pump, BAK, AltSysTick, Peri, Fast0, Fast1, Slow, Mem, Timer
//  2 optional =  ECO, WCO
#define CY_CHANNEL_COUNT_CLOCK      (15 + 2 + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + PERI_DIV_NR)
// TODO : to be fixed
#elif defined(COMPONENT_CAT1D)
// 10 dedicated = IMO, EXT, ILO, IL01, FLL, LF, Pump, BAK, AltSysTick, Peri
//  2 optional =  ECO, WCO
#define CY_CHANNEL_COUNT_CLOCK      (10 + 2 + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT)
#elif defined(COMPONENT_CAT2)
// 7 dedicated = IMO, EXT, ILO, HF, LF, PUMP, SYSCLK
// 5 optional  = ECO, WCO, PLL, PLLSEL, WDCSEL
#define CY_CHANNEL_COUNT_CLOCK      (7 + 5 + PERI_PCLK_CLOCK_NR)
#endif

#if defined(CY_IP_MXCRYPTO_INSTANCES)
    #define CY_BLOCK_COUNT_CRYPTO   (CY_IP_MXCRYPTO_INSTANCES)
#elif defined(CY_IP_MXCRYPTOCELL_INSTANCES)
    #define CY_BLOCK_COUNT_CRYPTO   (CY_IP_MXCRYPTOCELL_INSTANCES)
#elif defined(CPUSS_CRYPTO_PRESENT)
    #define CY_BLOCK_COUNT_CRYPTO   (CPUSS_CRYPTO_PRESENT)
#elif defined(CY_IP_M0S8CRYPTO_INSTANCES)
    #define CY_BLOCK_COUNT_CRYPTO   (CY_IP_M0S8CRYPTO_INSTANCES)
#elif defined(CY_IP_M0S8CRYPTOLITE_INSTANCES)
    #define CY_BLOCK_COUNT_CRYPTO   (CY_IP_M0S8CRYPTOLITE_INSTANCES)
#else
    #define CY_BLOCK_COUNT_CRYPTO   (0)
#endif

#if defined(CY_IP_MXS40PASS_CTDAC_INSTANCES)
    #define CY_BLOCK_COUNT_DAC      (CY_IP_MXS40PASS_CTDAC_INSTANCES)
#else
    #define CY_BLOCK_COUNT_DAC      (0)
#endif

#if defined(CY_IP_M4CPUSS_DMAC_INSTANCES)
    #define CY_BLOCK_COUNT_DMA      (CY_IP_M4CPUSS_DMAC_INSTANCES)
    #define CY_CHANNEL_COUNT_DMA    (CPUSS_DMAC_CH_NR)
#elif defined(CY_IP_MXAHBDMAC_INSTANCES)
    #define CY_BLOCK_COUNT_DMA      (CY_IP_MXAHBDMAC_INSTANCES)

    #if (CY_IP_MXAHBDMAC_INSTANCES == 0)
        #define CY_CHANNEL_COUNT_DMA (0u)
    #elif (CY_IP_MXAHBDMAC_INSTANCES == 1)
        #define CY_CHANNEL_COUNT_DMA (MXAHBDMAC0_CH_NR)
    #elif (CY_IP_MXAHBDMAC_INSTANCES == 2)
        #define CY_CHANNEL_COUNT_DMA (MXAHBDMAC0_CH_NR + MXAHBDMAC1_CH_NR)
    #elif (CY_IP_MXAHBDMAC_INSTANCES == 3)
        #define CY_CHANNEL_COUNT_DMA (MXAHBDMAC0_CH_NR + MXAHBDMAC1_CH_NR + MXAHBDMAC2_CH_NR)
    #else
        #warning Unhandled DMA instance count
    #endif
#elif defined(CPUSS_CPUMEMSS_DMAC_PRESENT)
    #define CY_BLOCK_COUNT_DMA      (CPUSS_CPUMEMSS_DMAC_PRESENT)
    #define CY_CHANNEL_COUNT_DMA    (CPUSS_DMAC_CH_NR)
#elif defined(CPUSS_DMAC_PRESENT)
    #define CY_BLOCK_COUNT_DMA      (CPUSS_DMAC_PRESENT)
    #define CY_CHANNEL_COUNT_DMA    (CPUSS_DMAC_CH_NR)
#else
    #define CY_BLOCK_COUNT_DMA      (0)
    #define CY_CHANNEL_COUNT_DMA    (0)
#endif

#if defined(CY_IP_M4CPUSS_DMA_INSTANCES)
    #define CY_BLOCK_COUNT_DW       (CY_IP_M4CPUSS_DMA_INSTANCES)
    #define CY_CHANNEL_COUNT_DW     (CPUSS_DW0_CH_NR + CPUSS_DW1_CH_NR)
#elif defined(CY_IP_MXDW_INSTANCES) && (CPUSS_DW0_PRESENT == 1)
    #define CY_BLOCK_COUNT_DW       (CY_IP_MXDW_INSTANCES)
    #if(CPUSS_DW1_PRESENT == 1)
        #define CY_CHANNEL_COUNT_DW     (CPUSS_DW0_CH_NR + CPUSS_DW1_CH_NR)
    #else
        #define CY_CHANNEL_COUNT_DW     (CPUSS_DW0_CH_NR)
    #endif
#elif defined(CPUSS_DW_NR)
    #define CY_BLOCK_COUNT_DW       (CPUSS_DW_NR)
    #if (CPUSS_DW_NR == 0)
        #define CY_CHANNEL_COUNT_DW     (0)
    #elif (CPUSS_DW_NR == 1)
        #define CY_CHANNEL_COUNT_DW     (CPUSS_DW0_CH_NR)
    #elif (CPUSS_DW_NR == 2)
        #define CY_CHANNEL_COUNT_DW     (CPUSS_DW0_CH_NR + CPUSS_DW1_CH_NR)
    #else
        #warning "Unhandled number of DataWire controllers."
    #endif /* CPUSS_DW_NR is 0, 1, 2, or other (unhandled) */
#else
    #define CY_BLOCK_COUNT_DW       (0)
    #define CY_CHANNEL_COUNT_DW     (0)
#endif

#ifdef CY_IP_MXETH_INSTANCES
    #define CY_BLOCK_COUNT_ETH      (CY_IP_MXETH_INSTANCES)
#else
    #define CY_BLOCK_COUNT_ETH      (0)
#endif

#if defined(IOSS_GPIO_GPIO_PORT_NR)
    #define CY_BLOCK_COUNT_GPIO     (IOSS_GPIO_GPIO_PORT_NR)
    #define CY_CHANNEL_COUNT_GPIO   (8 * IOSS_GPIO_GPIO_PORT_NR)
#else
    #define CY_BLOCK_COUNT_GPIO     (0)
    #define CY_CHANNEL_COUNT_GPIO   (0)
#endif

#if defined(CY_IP_MXAUDIOSS_INSTANCES)
    #define CY_BLOCK_COUNT_I2S      (CY_IP_MXAUDIOSS_INSTANCES)
#else
    #define CY_BLOCK_COUNT_I2S      (0)
#endif

#ifdef CY_IP_MXI3C_INSTANCES
    #define CY_BLOCK_COUNT_I3C      (CY_IP_MXI3C_INSTANCES)
#else
    #define CY_BLOCK_COUNT_I3C      (0)
#endif

#if defined(CY_IP_MXKEYSCAN_INSTANCES)
    #define CY_BLOCK_COUNT_KEYSCAN   (CY_IP_MXKEYSCAN_INSTANCES)
#else
    #define CY_BLOCK_COUNT_KEYSCAN   (0)
#endif

#if defined(CY_IP_MXLCD_INSTANCES)
    #define CY_BLOCK_COUNT_LCD      (CY_IP_MXLCD_INSTANCES)
#elif defined(CY_IP_M0S8LCD_INSTANCES)
    #define CY_BLOCK_COUNT_LCD      (CY_IP_M0S8LCD_INSTANCES)
#else
    #define CY_BLOCK_COUNT_LCD      (0)
#endif

#if defined(CY_IP_MXLIN_INSTANCES)
    #define CY_BLOCK_COUNT_LIN      (CY_IP_MXLIN_INSTANCES)
#else
    #define CY_BLOCK_COUNT_LIN      (0)
#endif

#if defined(CY_IP_MXLPCOMP_INSTANCES)
    #define CY_BLOCK_COUNT_LPCOMP   (CY_IP_MXLPCOMP_INSTANCES)
#elif defined(CY_IP_M0S8LPCOMP_INSTANCES)
    #define CY_BLOCK_COUNT_LPCOMP   (CY_IP_M0S8LPCOMP_INSTANCES)
#else
    #define CY_BLOCK_COUNT_LPCOMP   (0)
#endif
#define CY_CHANNEL_COUNT_LPCOMP     (2 * CY_BLOCK_COUNT_LPCOMP)

#if defined(PASS_NR_CTBS)
    #define CY_BLOCK_COUNT_OPAMP    (PASS_NR_CTBS)
#elif defined(PASS0_NR_CTBS)
    #if defined(PASS1_NR_CTBS)
        #define CY_BLOCK_COUNT_OPAMP    ((PASS0_NR_CTBS + PASS1_NR_CTBS))
    #else
        #define CY_BLOCK_COUNT_OPAMP    (PASS0_NR_CTBS)
    #endif
#else
    #define CY_BLOCK_COUNT_OPAMP    (0)
#endif
#define CY_CHANNEL_COUNT_OPAMP      (2 * CY_BLOCK_COUNT_OPAMP)

#if defined(CY_IP_MXAUDIOSS_INSTANCES)
    #define CY_BLOCK_COUNT_PDMPCM   (CY_IP_MXAUDIOSS_INSTANCES)
#elif defined(CY_IP_MXPDM_INSTANCES)
    #define CY_BLOCK_COUNT_PDMPCM   (CY_IP_MXPDM_INSTANCES)
#else
    #define CY_BLOCK_COUNT_PDMPCM   (0)
#endif

#if defined(CY_IP_MXSMIF_INSTANCES)
    #define CY_BLOCK_COUNT_QSPI     (CY_IP_MXSMIF_INSTANCES)
#else
    #define CY_BLOCK_COUNT_QSPI     (0)
#endif

#if (defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS40SRSS)) && SRSS_BACKUP_PRESENT
    #define CY_BLOCK_COUNT_RTC      (1)
#else
    #define CY_BLOCK_COUNT_RTC      (0)
#endif

#if defined(CY_IP_MXSCB_INSTANCES) || defined(CY_IP_M0S8SCB_INSTANCES)
    #define CY_BLOCK_COUNT_SCB      (_SCB_ARRAY_SIZE)
#else
    #define CY_BLOCK_COUNT_SCB      (0)
#endif

#if defined(CY_IP_MXSDHC_INSTANCES)
    #define CY_BLOCK_COUNT_SDHC     (CY_IP_MXSDHC_INSTANCES)
#else
    #define CY_BLOCK_COUNT_SDHC     (0)
#endif

#ifdef CY_IP_MXSDIODEV_INSTANCES
    #define CY_BLOCK_COUNT_SDIODEV  (CY_IP_MXSDIODEV_INSTANCES)
#else
    #define CY_BLOCK_COUNT_SDIODEV  (0)
#endif

#if defined(CY_IP_MXTCPWM_INSTANCES)
    #define CY_BLOCK_COUNT_TCPWM    CY_IP_MXTCPWM_INSTANCES
    #if (CY_IP_MXTCPWM_VERSION == 1)
        #if (CY_IP_MXTCPWM_INSTANCES == 0)
            #define CY_CHANNEL_COUNT_TCPWM (0u)
        #elif (CY_IP_MXTCPWM_INSTANCES == 1)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 2)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 3)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 4)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 5)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 6)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 7)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 8)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR + TCPWM7_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 9)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR + TCPWM7_CNT_NR + TCPWM8_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES == 10)
            #define CY_CHANNEL_COUNT_TCPWM (TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR + TCPWM7_CNT_NR + TCPWM8_CNT_NR + TCPWM9_CNT_NR)
        #elif (CY_IP_MXTCPWM_INSTANCES > 10)
            #warning Unhandled TCPWM instance count
        #endif
    #elif (CY_IP_MXTCPWM_VERSION == 2)
        #if (CY_IP_MXTCPWM_INSTANCES == 1)
            #if (TCPWM_GRP_NR == 0)
                #define CY_CHANNEL_COUNT_TCPWM (0u)
            #elif (TCPWM_GRP_NR == 1)
                #define CY_CHANNEL_COUNT_TCPWM (TCPWM_GRP_NR0_GRP_GRP_CNT_NR)
            #elif (TCPWM_GRP_NR == 2)
                #define CY_CHANNEL_COUNT_TCPWM (TCPWM_GRP_NR0_GRP_GRP_CNT_NR + TCPWM_GRP_NR1_GRP_GRP_CNT_NR)
            #elif (TCPWM_GRP_NR == 3)
                #define CY_CHANNEL_COUNT_TCPWM (TCPWM_GRP_NR0_GRP_GRP_CNT_NR + TCPWM_GRP_NR1_GRP_GRP_CNT_NR + TCPWM_GRP_NR2_GRP_GRP_CNT_NR)
            #elif (TCPWM_GRP_NR == 4)
                #define CY_CHANNEL_COUNT_TCPWM (TCPWM_GRP_NR0_GRP_GRP_CNT_NR + TCPWM_GRP_NR1_GRP_GRP_CNT_NR + TCPWM_GRP_NR2_GRP_GRP_CNT_NR + TCPWM_GRP_NR3_GRP_GRP_CNT_NR)
            #elif (TCPWM_GRP_NR > 4)
                #warning Unhandled TCPWM instance count
            #endif
        #elif (CY_IP_MXTCPWM_INSTANCES == 2)
            #if (TCPWM0_GRP_NR == 0)
                #define CY_CHANNEL_COUNT_TCPWM0 (0u)
            #elif (TCPWM0_GRP_NR == 1)
                #define CY_CHANNEL_COUNT_TCPWM0 (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR)
            #elif (TCPWM0_GRP_NR == 2)
                #define CY_CHANNEL_COUNT_TCPWM0 (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR)
            #elif (TCPWM0_GRP_NR == 3)
                #define CY_CHANNEL_COUNT_TCPWM0 (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR + TCPWM0_GRP_NR2_GRP_GRP_CNT_NR)
            #elif (TCPWM0_GRP_NR > 3)
                #warning Unhandled TCPWM instance count
            #endif
            #if (TCPWM1_GRP_NR == 0)
                #define CY_CHANNEL_COUNT_TCPWM1 (0u)
            #elif (TCPWM1_GRP_NR == 1)
                #define CY_CHANNEL_COUNT_TCPWM1 (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR)
            #elif (TCPWM1_GRP_NR == 2)
                #define CY_CHANNEL_COUNT_TCPWM1 (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR)
            #elif (TCPWM1_GRP_NR == 3)
                #define CY_CHANNEL_COUNT_TCPWM1 (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR + TCPWM1_GRP_NR2_GRP_GRP_CNT_NR)
            #elif (TCPWM1_GRP_NR > 3)
                #warning Unhandled TCPWM instance count
            #endif
            #define CY_CHANNEL_COUNT_TCPWM (CY_CHANNEL_COUNT_TCPWM0 + CY_CHANNEL_COUNT_TCPWM1)
        #elif (CY_IP_MXTCPWM_INSTANCES > 2)
            #warning Unhandled TCPWM instance count
        #endif
    #else
        #warning Unrecognized TCPWM IP version
    #endif
#elif defined(CY_IP_M0S8TCPWM_INSTANCES)
    #define CY_BLOCK_COUNT_TCPWM        (CY_IP_M0S8TCPWM_INSTANCES)
    #if (CY_IP_M0S8TCPWM_INSTANCES == 0)
        #define CY_CHANNEL_COUNT_TCPWM  (0u)
    #elif (CY_IP_M0S8TCPWM_INSTANCES == 1)
        #define CY_CHANNEL_COUNT_TCPWM  (TCPWM_CNT_NR)
    #else
        #warning Unhandled TCPWM instance count
    #endif
#else
    #define CY_BLOCK_COUNT_TCPWM    (0)
    #define CY_CHANNEL_COUNT_TCPWM  (0)
#endif

#ifdef CY_IP_MXTDM_INSTANCES
    #define CY_BLOCK_COUNT_TDM      (CY_IP_MXTDM_INSTANCES)
    #if (CY_IP_MXTDM_INSTANCES == 0)
        #define CY_CHANNEL_COUNT_TDM (0u)
    #elif (CY_IP_MXTDM_INSTANCES == 1)
        #define CY_CHANNEL_COUNT_TDM (TDM_NR)
    #else
        #warning Unhandled TDM instance count
    #endif
#else
    #define CY_BLOCK_COUNT_TDM      (0)
    #define CY_CHANNEL_COUNT_TDM    (0u)
#endif

#if defined(CY_IP_MXUDB_INSTANCES)
    #define CY_BLOCK_COUNT_UDB      (CY_IP_MXUDB_INSTANCES)
#else
    #define CY_BLOCK_COUNT_UDB      (0)
#endif

#if defined(CY_IP_MXUSBFS_INSTANCES)
    #define CY_BLOCK_COUNT_USB      (CY_IP_MXUSBFS_INSTANCES)
#else
    #define CY_BLOCK_COUNT_USB      (0)
#endif

#if defined(CY_IP_MXUSBPD_INSTANCES)
    #define CY_BLOCK_COUNT_USBPD    CY_IP_MXUSBPD_INSTANCES
#else
    #define CY_BLOCK_COUNT_USBPD    (0)
#endif

#if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS)
    #define CY_BLOCK_COUNT_MCWDT    (SRSS_NUM_MCWDT)
#elif (defined(CY_IP_S8SRSSLT_INSTANCES) && defined(CY_IP_M0S8WCO))
    #define CY_BLOCK_COUNT_MCWDT    (CY_IP_M0S8WCO_INSTANCES)
#else
    #define CY_BLOCK_COUNT_MCWDT    (0)
#endif

#if (defined(CY_IP_MXTCPWM_INSTANCES) && (CY_IP_MXTCPWM_VERSION >= 2) && (CY_IP_MXTCPWM_INSTANCES == 2))
    #if (TCPWM0_GRP_NR > 3)
        #define _CYHAL_TCPWM0_TOTAL_CNT_NR (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR + TCPWM0_GRP_NR2_GRP_GRP_CNT_NR + TCPWM0_GRP_NR3_GRP_GRP_CNT_NR)
    #elif (TCPWM0_GRP_NR > 2)
        #define _CYHAL_TCPWM0_TOTAL_CNT_NR (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR + TCPWM0_GRP_NR2_GRP_GRP_CNT_NR)
    #elif (TCPWM0_GRP_NR > 1)
        #define _CYHAL_TCPWM0_TOTAL_CNT_NR (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR)
    #elif (TCPWM0_GRP_NR > 0)
        #define _CYHAL_TCPWM0_TOTAL_CNT_NR (TCPWM0_GRP_NR0_GRP_GRP_CNT_NR)
    #endif
    #if (TCPWM1_GRP_NR > 3)
        #define _CYHAL_TCPWM1_TOTAL_CNT_NR (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR + TCPWM1_GRP_NR2_GRP_GRP_CNT_NR + TCPWM1_GRP_NR3_GRP_GRP_CNT_NR)
    #elif (TCPWM1_GRP_NR > 2)
        #define _CYHAL_TCPWM1_TOTAL_CNT_NR (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR + TCPWM1_GRP_NR2_GRP_GRP_CNT_NR)
    #elif (TCPWM1_GRP_NR > 1)
        #define _CYHAL_TCPWM1_TOTAL_CNT_NR (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR)
    #elif (TCPWM1_GRP_NR > 0)
        #define _CYHAL_TCPWM1_TOTAL_CNT_NR (TCPWM1_GRP_NR0_GRP_GRP_CNT_NR)
    #endif
#endif

/*
    All resources have an offset and a size, offsets are stored in an array
    Subsequent resource offset equals the preceding offset + size
    Offsets are bit indexes in the arrays that track used, configured etc.

    Channel based resources have an extra array for block offsets

    Note these are NOT offsets into the device's MMIO address space;
    they are bit offsets into arrays that are internal to the HW mgr.
*/


#define CY_OFFSET_ADC      0
#define CY_SIZE_ADC        CY_BLOCK_COUNT_ADC
#define CY_OFFSET_ADCMIC   (CY_OFFSET_ADC + CY_SIZE_ADC)
#define CY_SIZE_ADCMIC     CY_BLOCK_COUNT_ADCMIC
#define CY_OFFSET_BLE      (CY_OFFSET_ADCMIC + CY_SIZE_ADCMIC)
#define CY_SIZE_BLE        CY_BLOCK_COUNT_BLE
#define CY_OFFSET_CAN      (CY_OFFSET_BLE + CY_SIZE_BLE)
#define CY_SIZE_CAN        CY_CHANNEL_COUNT_CAN
#define CY_OFFSET_CLOCK    (CY_OFFSET_CAN + CY_SIZE_CAN)
#define CY_SIZE_CLOCK      CY_CHANNEL_COUNT_CLOCK
#define CY_OFFSET_CRYPTO   (CY_OFFSET_CLOCK + CY_SIZE_CLOCK)
#define CY_SIZE_CRYPTO     CY_BLOCK_COUNT_CRYPTO
#define CY_OFFSET_DAC      (CY_OFFSET_CRYPTO + CY_SIZE_CRYPTO)
#define CY_SIZE_DAC        CY_BLOCK_COUNT_DAC
#define CY_OFFSET_DMA      (CY_OFFSET_DAC + CY_SIZE_DAC)
#define CY_SIZE_DMA        CY_CHANNEL_COUNT_DMA
#define CY_OFFSET_DW       (CY_OFFSET_DMA + CY_SIZE_DMA)
#define CY_SIZE_DW         CY_CHANNEL_COUNT_DW
#define CY_OFFSET_ETH      (CY_OFFSET_DW + CY_SIZE_DW)
#define CY_SIZE_ETH        CY_BLOCK_COUNT_ETH
#define CY_OFFSET_GPIO     (CY_OFFSET_ETH + CY_SIZE_ETH)
#define CY_SIZE_GPIO       CY_CHANNEL_COUNT_GPIO
#define CY_OFFSET_I2S      (CY_OFFSET_GPIO + CY_SIZE_GPIO)
#define CY_SIZE_I2S        CY_BLOCK_COUNT_I2S
#define CY_OFFSET_I3C      (CY_OFFSET_I2S + CY_SIZE_I2S)
#define CY_SIZE_I3C        CY_BLOCK_COUNT_I3C
#define CY_OFFSET_KEYSCAN  (CY_OFFSET_I3C + CY_SIZE_I3C)
#define CY_SIZE_KEYSCAN    CY_BLOCK_COUNT_KEYSCAN
#define CY_OFFSET_LCD      (CY_OFFSET_KEYSCAN + CY_SIZE_KEYSCAN)
#define CY_SIZE_LCD        CY_BLOCK_COUNT_LCD
#define CY_OFFSET_LIN      (CY_OFFSET_LCD + CY_SIZE_LCD)
#define CY_SIZE_LIN        CY_BLOCK_COUNT_LIN
#define CY_OFFSET_LPCOMP   (CY_OFFSET_LIN + CY_SIZE_LIN)
#define CY_SIZE_LPCOMP     CY_CHANNEL_COUNT_LPCOMP
#define CY_OFFSET_LPTIMER  (CY_OFFSET_LPCOMP + CY_SIZE_LPCOMP)
#define CY_SIZE_LPTIMER    CY_BLOCK_COUNT_MCWDT
#define CY_OFFSET_OPAMP    (CY_OFFSET_LPTIMER + CY_SIZE_LPTIMER)
#define CY_SIZE_OPAMP      CY_CHANNEL_COUNT_OPAMP
#define CY_OFFSET_PDMPCM   (CY_OFFSET_OPAMP + CY_SIZE_OPAMP)
#define CY_SIZE_PDMPCM     CY_BLOCK_COUNT_PDMPCM
#define CY_OFFSET_QSPI     (CY_OFFSET_PDMPCM + CY_SIZE_PDMPCM)
#define CY_SIZE_QSPI       CY_BLOCK_COUNT_QSPI
#define CY_OFFSET_RTC      (CY_OFFSET_QSPI + CY_SIZE_QSPI)
#define CY_SIZE_RTC        CY_BLOCK_COUNT_RTC
#define CY_OFFSET_SCB      (CY_OFFSET_RTC + CY_SIZE_RTC)
#define CY_SIZE_SCB        CY_BLOCK_COUNT_SCB
#define CY_OFFSET_SDHC     (CY_OFFSET_SCB + CY_SIZE_SCB)
#define CY_SIZE_SDHC       CY_BLOCK_COUNT_SDHC
#define CY_OFFSET_SDIODEV  (CY_OFFSET_SDHC + CY_SIZE_SDHC)
#define CY_SIZE_SDIODEV    CY_BLOCK_COUNT_SDIODEV
#define CY_OFFSET_TCPWM    (CY_OFFSET_SDIODEV + CY_SIZE_SDIODEV)
#define CY_SIZE_TCPWM      CY_CHANNEL_COUNT_TCPWM
#define CY_OFFSET_TDM      (CY_OFFSET_TCPWM + CY_SIZE_TCPWM)
#define CY_SIZE_TDM        CY_CHANNEL_COUNT_TDM
#define CY_OFFSET_UDB      (CY_OFFSET_TDM + CY_SIZE_TDM)
#define CY_SIZE_UDB        CY_BLOCK_COUNT_UDB
#define CY_OFFSET_USB      (CY_OFFSET_UDB + CY_SIZE_UDB)
#define CY_SIZE_USB        CY_BLOCK_COUNT_USB
#define CY_OFFSET_USBPD    (CY_OFFSET_USB + CY_SIZE_USB)
#define CY_SIZE_USBPD      CY_BLOCK_COUNT_USBPD

#define CY_TOTAL_ALLOCATABLE_ITEMS     (CY_OFFSET_USBPD + CY_SIZE_USBPD)

/*******************************************************************************
*       Variables
*******************************************************************************/

#if ((CY_CHANNEL_COUNT_GPIO) > 32)
    /* 8 bits per port, offset = 8 * (portIdx) means port 33 has offset >= 256 */
    typedef uint16_t _cyhal_hwmgr_offset_t;
#else
    typedef uint8_t _cyhal_hwmgr_offset_t;
#endif

#if defined(COMPONENT_CAT1A)

#if ((PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 18) >= 256)
#error "Too many clocks to use uint8_t as offset type"
#endif
/* The order of items here must match the order in cyhal_clock_impl.h
 *
 * Each entry in the array below is the prior entry plus the number of clocks that exist
 * of the prior type. When there is only 1 clock (e.g: IMO/ECO) the next number is simply
 * one higher than the previous value. When there are multiple clocks (e.g.: PathMux/PLL)
 * the subsequent value is increased by the define that specifies how many clocks are
 * actually present. */
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_clock[26] =
{
    0,                                                                    // 8-bit dividers
    PERI_DIV_8_NR,                                                        // 16-bit dividers
    PERI_DIV_8_NR + PERI_DIV_16_NR,                                       // 16.5 bit dividers
    PERI_DIV_8_NR + PERI_DIV_16_NR + PERI_DIV_16_5_NR,                    // 24.5 bit dividers

    PERI_DIV_NR,                                                          // IMO
    PERI_DIV_NR + 1,                                                      // ECO
    PERI_DIV_NR + 2,                                                      // EXT
    PERI_DIV_NR + 3,                                                      // ALTHF
    PERI_DIV_NR + 4,                                                      // ALTLF
    PERI_DIV_NR + 5,                                                      // ILO
    PERI_DIV_NR + 6,                                                      // PILO
    PERI_DIV_NR + 7,                                                      // WCO
    PERI_DIV_NR + 8,                                                      // MFO

    PERI_DIV_NR + 9,                                                      // PathMux

    PERI_DIV_NR + SRSS_NUM_CLKPATH + 9,                                   // FLL
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 10,                                  // PLL

    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + 10,                   // LF
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + 11,                   // MF
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + 12,                   // HF

    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 12, // PUMP
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 13, // BAK
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 14, // TIMER
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 15, // AltSysTick

    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 16, // Fast
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 17, // Peri
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 18, // Slow
};

#elif defined(COMPONENT_CAT1B)

#define CY_MXSPERI_PCLK_DIV_CNT(gr) ( \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_24_5_VECT))

#define CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(gr) \
        (PERI_DIV_OFFSET##gr), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT)

#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 0)
    #define PERI_DIV_OFFSET0  (0)
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 1)
    #define PERI_DIV_OFFSET1  (CY_MXSPERI_PCLK_DIV_CNT(0))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 2
    #define PERI_DIV_OFFSET2  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 3
    #define PERI_DIV_OFFSET3  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 4
    #define PERI_DIV_OFFSET4  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 5
    #define PERI_DIV_OFFSET5  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 6
    #define PERI_DIV_OFFSET6  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 7
    #define PERI_DIV_OFFSET7  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 8
    #define PERI_DIV_OFFSET8  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 9
    #define PERI_DIV_OFFSET9  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 10
    #define PERI_DIV_OFFSET10  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 11
    #define PERI_DIV_OFFSET11  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 12
    #define PERI_DIV_OFFSET12  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 13
    #define PERI_DIV_OFFSET13  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 14
    #define PERI_DIV_OFFSET14  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 15
    #define PERI_DIV_OFFSET15  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13) + CY_MXSPERI_PCLK_DIV_CNT(14))
#endif


#if ((PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 18) >= 256)
#error "Too many clocks to use uint8_t as offset type"
#endif

/* The order of items here must match the order in cyhal_clock_impl.h
 *
 * Each entry in the array below is the prior entry plus the number of clocks that exist
 * of the prior type. When there is only 1 clock (e.g: IMO/ECO) the next number is simply
 * one higher than the previous value. When there are multiple clocks (e.g.: PathMux/PLL)
 * the subsequent value is increased by the define that specifies how many clocks are
 * actually present. */
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_clock[PERI_PERI_PCLK_PCLK_GROUP_NR * 4 + 22] =
{
    // Peripheral dividers (8-bit, 16-bit, 16.5-bit & 24.5 bit) for each group
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 0)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(0),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 1)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(1),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 2)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(2),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 3)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(3),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 4)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(4),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 5)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(5),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 6)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(6),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 7)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(7),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 8)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(8),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 9)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(9),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 10)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(10),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 11)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(11),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 12)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(12),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 13)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(13),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 14)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(14),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 15)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(15),
    #endif

    PERI_DIV_NR,                                                                                    // IHO
    PERI_DIV_NR + 1,                                                                                // IMO
    PERI_DIV_NR + 2,                                                                                // ECO
    PERI_DIV_NR + 3,                                                                                // EXT
    PERI_DIV_NR + 4,                                                                                // ALTHF
    PERI_DIV_NR + 5,                                                                                // ALTLF
    PERI_DIV_NR + 6,                                                                                // ILO
    PERI_DIV_NR + 7,                                                                                // PILO
    PERI_DIV_NR + 8,                                                                                // WCO
    PERI_DIV_NR + 9,                                                                                // MFO

    PERI_DIV_NR + 10,                                                                               // PathMux

    PERI_DIV_NR + SRSS_NUM_CLKPATH + 10,                                                            // FLL
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 11,                                                            // PLL200
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + 11,                                         // PLL400
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + 11,                      // ECO_PreScaler

    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + 12,                      // LF
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + 13,                      // MF
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + 14,                      // HF

    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 14,    // PUMP
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 15,    // BAK
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 16,    // AltSysTick
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL200M + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 17,    // Peri
};

#elif defined(COMPONENT_CAT1C)

#define CY_MXSPERI_PCLK_DIV_CNT(gr) ( \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_24_5_VECT))

#define CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(gr) \
        (PERI_DIV_OFFSET##gr), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT)

#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 0)
    #define PERI_DIV_OFFSET0  (0)
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 1)
    #define PERI_DIV_OFFSET1  (CY_MXSPERI_PCLK_DIV_CNT(0))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 2
    #define PERI_DIV_OFFSET2  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 3
    #define PERI_DIV_OFFSET3  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 4
    #define PERI_DIV_OFFSET4  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 5
    #define PERI_DIV_OFFSET5  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 6
    #define PERI_DIV_OFFSET6  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 7
    #define PERI_DIV_OFFSET7  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 8
    #define PERI_DIV_OFFSET8  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 9
    #define PERI_DIV_OFFSET9  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 10
    #define PERI_DIV_OFFSET10  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 11
    #define PERI_DIV_OFFSET11  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 12
    #define PERI_DIV_OFFSET12  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 13
    #define PERI_DIV_OFFSET13  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 14
    #define PERI_DIV_OFFSET14  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 15
    #define PERI_DIV_OFFSET15  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13) + CY_MXSPERI_PCLK_DIV_CNT(14))
#endif


#if ((PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 18) >= 256)
#error "Too many clocks to use uint8_t as offset type"
#endif

/* The order of items here must match the order in cyhal_clock_impl.h
 *
 * Each entry in the array below is the prior entry plus the number of clocks that exist
 * of the prior type. When there is only 1 clock (e.g: IMO/ECO) the next number is simply
 * one higher than the previous value. When there are multiple clocks (e.g.: PathMux/PLL)
 * the subsequent value is increased by the define that specifies how many clocks are
 * actually present. */
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_clock[PERI_PERI_PCLK_PCLK_GROUP_NR * 4 + 22] =
{
    // Peripheral dividers (8-bit, 16-bit, 16.5-bit & 24.5 bit) for each group
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 0)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(0),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 1)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(1),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 2)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(2),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 3)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(3),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 4)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(4),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 5)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(5),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 6)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(6),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 7)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(7),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 8)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(8),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 9)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(9),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 10)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(10),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 11)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(11),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 12)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(12),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 13)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(13),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 14)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(14),
    #endif
    #if (PERI_PERI_PCLK_PCLK_GROUP_NR > 15)
        CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(15),
    #endif

    PERI_DIV_NR,                                                                                                                                 // IMO
    PERI_DIV_NR + 1,                                                                                                                             // ECO
    PERI_DIV_NR + 2,                                                                                                                             // EXT
    PERI_DIV_NR + 3,                                                                                                                             // ILO
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + 3,                                                                                                       // WCO
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + 4,                                                                                                       // PathMux
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + 4,                                                                                    // FLL
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + 5,                                                                                    // PLL200
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + 5,                                                                     // PLL400

    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + 5,                                                  // LF
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + 6,                                                  // HF

    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 6,                                // PUMP
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 7,                                // BAK
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 8,                                // AltSysTick
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 9,                               // Peri
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + 10,                               // Fast
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + _CYHAL_SRSS_NUM_FAST + 10,        // Slow
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + _CYHAL_SRSS_NUM_FAST + 11,        // MEM
    PERI_DIV_NR + _CYHAL_SRSS_NUM_ILO + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_PLL400M + SRSS_NUM_HFROOT + _CYHAL_SRSS_NUM_FAST + 12,        // Timer
};

// TODO : To be fixed
// This section is just copy & fix of block above (CAT1C) and can be completely irrelevant.
#elif defined(COMPONENT_CAT1D)

#define CY_MXSPERI_PCLK_DIV_CNT(gr) ( \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT) + \
        (PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_24_5_VECT))

#define CY_MXSPERI_PCLK_DIV_CNT_OFFSETS(gr) \
        (PERI_DIV_OFFSET##gr), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT), \
        (PERI_DIV_OFFSET##gr + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_8_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_VECT + PERI_PERI_PCLK_PCLK_GROUP_NR##gr##_GR_DIV_16_5_VECT)

#if (PERI_PERI_PCLK_PCLK_GROUP_NR == 0)
    #define PERI_DIV_NR  (0)
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR == 1)
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 2
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 3
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 4
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 5
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 6
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 7
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 8
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 9
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 10
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 11
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 12
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 13
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 14
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13))
#elif (PERI_PERI_PCLK_PCLK_GROUP_NR) == 15
    #define PERI_DIV_NR  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13) + CY_MXSPERI_PCLK_DIV_CNT(14))
#else
    #warning "PCLK table size exceeded"
#endif

#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 0)
    #define PERI_DIV_OFFSET0  (0)
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR > 1)
    #define PERI_DIV_OFFSET1  (CY_MXSPERI_PCLK_DIV_CNT(0))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 2
    #define PERI_DIV_OFFSET2  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 3
    #define PERI_DIV_OFFSET3  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 4
    #define PERI_DIV_OFFSET4  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 5
    #define PERI_DIV_OFFSET5  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 6
    #define PERI_DIV_OFFSET6  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 7
    #define PERI_DIV_OFFSET7  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 8
    #define PERI_DIV_OFFSET8  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 9
    #define PERI_DIV_OFFSET9  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 10
    #define PERI_DIV_OFFSET10  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 11
    #define PERI_DIV_OFFSET11  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 12
    #define PERI_DIV_OFFSET12  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 13
    #define PERI_DIV_OFFSET13  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 14
    #define PERI_DIV_OFFSET14  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13))
#endif
#if (PERI_PERI_PCLK_PCLK_GROUP_NR) > 15
    #define PERI_DIV_OFFSET15  (CY_MXSPERI_PCLK_DIV_CNT(0) + CY_MXSPERI_PCLK_DIV_CNT(1) + CY_MXSPERI_PCLK_DIV_CNT(2) + CY_MXSPERI_PCLK_DIV_CNT(3) + CY_MXSPERI_PCLK_DIV_CNT(4) + CY_MXSPERI_PCLK_DIV_CNT(5) + CY_MXSPERI_PCLK_DIV_CNT(6) + CY_MXSPERI_PCLK_DIV_CNT(7) + CY_MXSPERI_PCLK_DIV_CNT(8) + CY_MXSPERI_PCLK_DIV_CNT(9) + CY_MXSPERI_PCLK_DIV_CNT(10) + CY_MXSPERI_PCLK_DIV_CNT(11) + CY_MXSPERI_PCLK_DIV_CNT(12) + CY_MXSPERI_PCLK_DIV_CNT(13) + CY_MXSPERI_PCLK_DIV_CNT(14))
#endif


#if ((PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_PLL + SRSS_NUM_HFROOT + 18) >= 256)
#error "Too many clocks to use uint8_t as offset type"
#endif

/* The order of items here must match the order in cyhal_clock_impl.h
 *
 * Each entry in the array below is the prior entry plus the number of clocks that exist
 * of the prior type. When there is only 1 clock (e.g: IMO/ECO) the next number is simply
 * one higher than the previous value. When there are multiple clocks (e.g.: PathMux/PLL)
 * the subsequent value is increased by the define that specifies how many clocks are
 * actually present. */
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_clock[22] =
{
    // Peripheral dividers (8-bit, 16-bit, 16.5-bit & 24.5 bit) for each group
    // TODO: To be added

    PERI_DIV_NR,
    PERI_DIV_NR + 1,
    PERI_DIV_NR + 2,
    PERI_DIV_NR + 3,
    PERI_DIV_NR + 4,
    PERI_DIV_NR + 5,
    PERI_DIV_NR + 6,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 6,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 7,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 8,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + 9,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 9,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 10,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 11,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 12,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 13,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 14,
    PERI_DIV_NR + SRSS_NUM_CLKPATH + SRSS_NUM_HFROOT + 15,
};

#elif defined(COMPONENT_CAT2)
/* The order of items here must match the order in cyhal_clock_impl.h
 *
 * Each entry in the array below is the prior entry plus the number of clocks that exist
 * of the prior type. When there is only 1 clock (e.g: IMO/ECO) the next number is simply
 * one higher than the previous value. When there are multiple clocks (e.g.: PCLK)
 * the subsequent value is increased by the define that specifies how many clocks are
 * actually present. */
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_clock[16] =
{
    0,                                                                  // 8-bit dividers
    PERI_PCLK_DIV_8_NR,                                                 // 16-bit dividers
    PERI_PCLK_DIV_8_NR + PERI_PCLK_DIV_16_NR,                           // 16.5 bit dividers
    PERI_PCLK_DIV_8_NR + PERI_PCLK_DIV_16_NR + PERI_PCLK_DIV_16_5_NR,   // 24.5 bit dividers

    PERI_PCLK_CLOCK_NR,                                                 // IMO
    PERI_PCLK_CLOCK_NR + 1,                                             // ECO
    PERI_PCLK_CLOCK_NR + 2,                                             // EXT
    PERI_PCLK_CLOCK_NR + 3,                                             // ILO
    PERI_PCLK_CLOCK_NR + 4,                                             // WCO

    PERI_PCLK_CLOCK_NR + 5,                                             // WDCSEL
    PERI_PCLK_CLOCK_NR + 6,                                             // PLLSEL
    PERI_PCLK_CLOCK_NR + 7,                                             // PLL
    PERI_PCLK_CLOCK_NR + 8,                                             // LF
    PERI_PCLK_CLOCK_NR + 9,                                             // HF
    PERI_PCLK_CLOCK_NR + 10,                                            // PUMP
    PERI_PCLK_CLOCK_NR + 11,                                            // SYS
};
#endif

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_dma[] =
{
    0,
#if defined(CY_IP_MXAHBDMAC_INSTANCES)
#if (CY_IP_MXAHBDMAC_INSTANCES > 1)
    MXAHBDMAC0_CH_NR,
#endif
#if (CY_IP_MXAHBDMAC_INSTANCES > 2)
    MXAHBDMAC0_CH_NR + MXAHBDMAC1_CH_NR,
#endif
#if (CY_IP_MXAHBDMAC_INSTANCES > 3)
    #warning Unhandled DMA instance count
#endif
#endif /* defined(CY_IP_MXAHBDMAC_INSTANCES) */
};

#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C)
static const _cyhal_hwmgr_offset_t cyhal_block_offsets_dw[] =
{
    0,
    CPUSS_DW0_CH_NR,
};

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_tdm[] =
{
    0,
#if defined(CY_IP_MXTDM_INSTANCES)
#if (CY_IP_MXTDM_INSTANCES > 1)
    TDM_NR,
#endif
#endif
};
#endif

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_gpio[] =
{
    0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120,
    #if defined(COMPONENT_CAT1C)
    /* Most devices don't have more than 16 ports, so save the flash in most cases */
    128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224,
    232, 240, 248, 256, 264, 272, 280
    #endif
};

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_can[] =
{
#ifdef CY_IP_MXTTCANFD_INSTANCES
    #if (CY_IP_MXTTCANFD_INSTANCES > 0)
        0,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 1)
        CANFD0_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 2)
        CANFD0_CAN_NR + CANFD1_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 3)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 4)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 5)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 6)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 7)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 8)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR + CANFD7_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 9)
        CANFD0_CAN_NR + CANFD1_CAN_NR + CANFD2_CAN_NR + CANFD3_CAN_NR + CANFD4_CAN_NR + CANFD5_CAN_NR + CANFD6_CAN_NR + CANFD7_CAN_NR + CANFD8_CAN_NR,
    #endif
    #if (CY_IP_MXTTCANFD_INSTANCES > 10)
        #warning Unhandled CAN instance count
    #endif
#else
    0
#endif
};

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_lpcomp[] =
{
    0,
#if (CY_BLOCK_COUNT_LPCOMP > 1)
    #error "Unhandled LPComp count"
#endif
};

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_opamp[] =
{
    0,
#if (CY_BLOCK_COUNT_OPAMP > 1)
    2,
#elif (CY_BLOCK_COUNT_OPAMP > 2)
    #error "Unhandled Opamp count"
#endif
};

static const _cyhal_hwmgr_offset_t cyhal_block_offsets_tcpwm[] =
{
    0,
#ifdef CY_IP_MXTCPWM_INSTANCES
    #if CY_IP_MXTCPWM_VERSION == 1
        #if (CY_IP_MXTCPWM_INSTANCES > 1)
            TCPWM0_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 2)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 3)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 4)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 5)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 6)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 7)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 8)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR + TCPWM7_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 9)
            TCPWM0_CNT_NR + TCPWM1_CNT_NR + TCPWM2_CNT_NR + TCPWM3_CNT_NR + TCPWM4_CNT_NR + TCPWM5_CNT_NR + TCPWM6_CNT_NR + TCPWM7_CNT_NR + TCPWM8_CNT_NR,
        #endif
        #if (CY_IP_MXTCPWM_INSTANCES > 10)
            #warning Unhandled TCPWM instance count
        #endif
    #else // CY_IP_MXTCPWM_VERSION >= 2
        #if (CY_IP_MXTCPWM_INSTANCES == 1)
            #if (TCPWM_GRP_NR > 1)
                TCPWM_GRP_NR0_GRP_GRP_CNT_NR,
            #endif
            #if (TCPWM_GRP_NR > 2)
                TCPWM_GRP_NR0_GRP_GRP_CNT_NR + TCPWM_GRP_NR1_GRP_GRP_CNT_NR,
            #endif
            #if (TCPWM_GRP_NR > 3)
                TCPWM_GRP_NR0_GRP_GRP_CNT_NR + TCPWM_GRP_NR1_GRP_GRP_CNT_NR + TCPWM_GRP_NR2_GRP_GRP_CNT_NR,
            #endif
        #elif (CY_IP_MXTCPWM_INSTANCES == 2)
            // The 'else's are placeholders to ensure the groups line up, even if groups are empty or absent
            #if (TCPWM0_GRP_NR > 1)
                TCPWM0_GRP_NR0_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR,
            #endif
            #if (TCPWM0_GRP_NR > 2)
                TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR,
            #endif
            #if (TCPWM0_GRP_NR > 3)
                TCPWM0_GRP_NR0_GRP_GRP_CNT_NR + TCPWM0_GRP_NR1_GRP_GRP_CNT_NR + TCPWM0_GRP_NR2_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR,
            #endif

            #if (TCPWM1_GRP_NR > 0)
                _CYHAL_TCPWM0_TOTAL_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR + _CYHAL_TCPWM1_TOTAL_CNT_NR,
            #endif
            #if (TCPWM1_GRP_NR > 1)
                _CYHAL_TCPWM0_TOTAL_CNT_NR + TCPWM1_GRP_NR0_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR +_CYHAL_TCPWM1_TOTAL_CNT_NR,
            #endif
            #if (TCPWM1_GRP_NR > 2)
                _CYHAL_TCPWM0_TOTAL_CNT_NR + TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR +_CYHAL_TCPWM1_TOTAL_CNT_NR,
            #endif
            #if (TCPWM1_GRP_NR > 3)
                _CYHAL_TCPWM0_TOTAL_CNT_NR + TCPWM1_GRP_NR0_GRP_GRP_CNT_NR + TCPWM1_GRP_NR1_GRP_GRP_CNT_NR + TCPWM1_GRP_NR2_GRP_GRP_CNT_NR,
            #else
                _CYHAL_TCPWM0_TOTAL_CNT_NR +_CYHAL_TCPWM1_TOTAL_CNT_NR,
            #endif
        #else
            #warning Unhandled TCPWM instance count
        #endif
    #endif
#endif
};

static uint8_t cyhal_used[(CY_TOTAL_ALLOCATABLE_ITEMS + 7) / 8] = {0};

// Note: the ordering here needs to be parallel to that of cyhal_resource_t
static const uint16_t cyhal_resource_offsets[] =
{
#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C) || defined(COMPONENT_CAT1D)
    CY_OFFSET_ADC,
    CY_OFFSET_ADCMIC,
    CY_OFFSET_BLE,
    CY_OFFSET_CAN,
    CY_OFFSET_CLOCK,    /* Placeholder for ClockPath which is deprecated */
    CY_OFFSET_CLOCK,
    CY_OFFSET_CRYPTO,
    CY_OFFSET_DAC,
    CY_OFFSET_DMA,
    CY_OFFSET_DW,
    CY_OFFSET_ETH,
    CY_OFFSET_GPIO,
    CY_OFFSET_I2S,
    CY_OFFSET_I3C,
    CY_OFFSET_KEYSCAN,
    CY_OFFSET_LCD,
    CY_OFFSET_LIN,
    CY_OFFSET_LPCOMP,
    CY_OFFSET_LPTIMER,
    CY_OFFSET_OPAMP,
    CY_OFFSET_PDMPCM,
    CY_OFFSET_QSPI,
    CY_OFFSET_RTC,
    CY_OFFSET_SCB,
    CY_OFFSET_SDHC,
    CY_OFFSET_SDIODEV,
    CY_OFFSET_TCPWM,
    CY_OFFSET_TDM,
    CY_OFFSET_UDB,
    CY_OFFSET_USB,
#elif defined(COMPONENT_CAT2)
    CY_OFFSET_ADC,
    CY_OFFSET_CAN,
    CY_OFFSET_CLOCK,
    CY_OFFSET_CRYPTO,
    CY_OFFSET_DMA,
    CY_OFFSET_GPIO,
    CY_OFFSET_I2S,
    CY_OFFSET_LCD,
    CY_OFFSET_LPCOMP,
    CY_OFFSET_LPTIMER,
    CY_OFFSET_OPAMP,
    CY_OFFSET_SCB,
    CY_OFFSET_TCPWM,
    CY_OFFSET_USB,
    CY_OFFSET_USBPD,
#endif
};

#define _CYHAL_RESOURCES (sizeof(cyhal_resource_offsets)/sizeof(cyhal_resource_offsets[0]))

static const uint32_t cyhal_has_channels =
    (1 << CYHAL_RSC_CAN)   |
    (1 << CYHAL_RSC_CLOCK) |
    (1 << CYHAL_RSC_DMA)   |
#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C)
    (1 << CYHAL_RSC_DW)    |
    (1 << CYHAL_RSC_TDM)   |
#endif
    (1 << CYHAL_RSC_GPIO)  |
    (1 << CYHAL_RSC_LPCOMP)|
    (1 << CYHAL_RSC_OPAMP) |
    (1 << CYHAL_RSC_TCPWM) ;

/*******************************************************************************
*       Utility helper functions
*******************************************************************************/

static inline uint16_t _cyhal_uses_channels(cyhal_resource_t type)
{
    return (cyhal_has_channels & (1 << type)) > 0;
}

static inline uint16_t _cyhal_get_resource_offset(cyhal_resource_t type)
{
    return cyhal_resource_offsets[type];
}

static inline const _cyhal_hwmgr_offset_t* _cyhal_get_block_offsets(cyhal_resource_t type)
{
    switch (type)
    {
        case CYHAL_RSC_CAN:
            return cyhal_block_offsets_can;
        case CYHAL_RSC_CLOCK:
            return cyhal_block_offsets_clock;
        case CYHAL_RSC_DMA:
            return cyhal_block_offsets_dma;
#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C)
        case CYHAL_RSC_DW:
            return cyhal_block_offsets_dw;
        case CYHAL_RSC_TDM:
            return cyhal_block_offsets_tdm;
#endif
        case CYHAL_RSC_GPIO:
            return cyhal_block_offsets_gpio;
        case CYHAL_RSC_LPCOMP:
            return cyhal_block_offsets_lpcomp;
        case CYHAL_RSC_OPAMP:
            return cyhal_block_offsets_opamp;
        case CYHAL_RSC_TCPWM:
            return cyhal_block_offsets_tcpwm;
        default:
            CY_ASSERT(false);
            return NULL;
    }
}

// Gets the number of block offset entries, only valid for blocks which have channels.
static inline uint8_t _cyhal_get_block_offset_length(cyhal_resource_t type)
{
    switch (type)
    {
        case CYHAL_RSC_CAN:
            return sizeof(cyhal_block_offsets_can)/sizeof(cyhal_block_offsets_can[0]);
        case CYHAL_RSC_CLOCK:
            return sizeof(cyhal_block_offsets_clock)/sizeof(cyhal_block_offsets_clock[0]);
        case CYHAL_RSC_DMA:
            return sizeof(cyhal_block_offsets_dma)/sizeof(cyhal_block_offsets_dma[0]);
#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C)
        case CYHAL_RSC_DW:
            return sizeof(cyhal_block_offsets_dw)/sizeof(cyhal_block_offsets_dw[0]);
        case CYHAL_RSC_TDM:
            return sizeof(cyhal_block_offsets_tdm)/sizeof(cyhal_block_offsets_tdm[0]);
#endif
        case CYHAL_RSC_GPIO:
            return sizeof(cyhal_block_offsets_gpio)/sizeof(cyhal_block_offsets_gpio[0]);
        case CYHAL_RSC_LPCOMP:
            return sizeof(cyhal_block_offsets_lpcomp)/sizeof(cyhal_block_offsets_lpcomp[0]);
        case CYHAL_RSC_OPAMP:
            return sizeof(cyhal_block_offsets_opamp)/sizeof(cyhal_block_offsets_opamp[0]);
        case CYHAL_RSC_TCPWM:
            return sizeof(cyhal_block_offsets_tcpwm)/sizeof(cyhal_block_offsets_tcpwm[0]);
        default:
            CY_ASSERT(false);
            return 0;
    }
}