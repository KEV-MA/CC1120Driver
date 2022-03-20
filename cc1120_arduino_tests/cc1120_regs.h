#ifndef CC1120_REGS_H
#define CC1120_REGS_H

// Standard address space registers
#define CC1120_REGS_IOCFG3              0x00U
#define CC1120_REGS_IOCFG2              0x01U
#define CC1120_REGS_IOCFG1              0x02U
#define CC1120_REGS_IOCFG0              0x03U
#define CC1120_REGS_SYNC3               0x04U
#define CC1120_REGS_SYNC2               0x05U
#define CC1120_REGS_SYNC1               0x06U
#define CC1120_REGS_SYNC0               0x07U
#define CC1120_REGS_SYNC_CFG1           0x08U
#define CC1120_REGS_SYNC_CFG0           0x09U
#define CC1120_REGS_DEVIATION_M         0x0AU
#define CC1120_REGS_MODCFG_DEV_E        0x0BU
#define CC1120_REGS_DCFILT_CFG          0x0CU
#define CC1120_REGS_PREAMBLE_CFG1       0x0DU
#define CC1120_REGS_PREAMBLE_CFG0       0x0EU
#define CC1120_REGS_FREQ_IF_CFG         0x0FU
#define CC1120_REGS_IQIC                0x10U
#define CC1120_REGS_CHAN_BW             0x11U
#define CC1120_REGS_MDMCFG1             0x12U
#define CC1120_REGS_MDMCFG0             0x13U
#define CC1120_REGS_SYMBOL_RATE2        0x14U
#define CC1120_REGS_SYMBOL_RATE1        0x15U
#define CC1120_REGS_SYMBOL_RATE0        0x16U
#define CC1120_REGS_AGC_REF             0x17U
#define CC1120_REGS_AGC_CS_THR          0x18U
#define CC1120_REGS_AGC_GAIN_ADJUST     0x19U
#define CC1120_REGS_AGC_CFG3            0x1AU
#define CC1120_REGS_AGC_CFG2            0x1BU
#define CC1120_REGS_AGC_CFG1            0x1CU
#define CC1120_REGS_AGC_CFG0            0x1DU
#define CC1120_REGS_FIFO_CFG            0x1EU
#define CC1120_REGS_DEV_ADDR            0x1FU
#define CC1120_REGS_SETTLING_CFG        0x20U
#define CC1120_REGS_FS_CFG              0x21U
#define CC1120_REGS_WOR_CFG1            0x22U
#define CC1120_REGS_WOR_CFG0            0x23U
#define CC1120_REGS_WOR_EVENT0_MSB      0x24U
#define CC1120_REGS_WOR_EVENT0_LSB      0x25U
#define CC1120_REGS_PKT_CFG2            0x26U
#define CC1120_REGS_PKT_CFG1            0x27U
#define CC1120_REGS_PKT_CFG0            0x28U
#define CC1120_REGS_RFEND_CFG1          0x29U
#define CC1120_REGS_RFEND_CFG0          0x2AU
#define CC1120_REGS_PA_CFG2             0x2BU
#define CC1120_REGS_PA_CFG1             0x2CU
#define CC1120_REGS_PA_CFG0             0x2DU
#define CC1120_REGS_PKT_LEN             0x2EU

// Extended address space register
#define CC1120_REGS_EXT_ADDR            0x2FU

// Strobe command registers
#define CC1120_REGS_STROBE_SRES         0x30U
#define CC1120_REGS_STROBE_SFSTXON      0x31U
#define CC1120_REGS_STROBE_SXOFF        0x32U
#define CC1120_REGS_STROBE_SCAL         0x33U
#define CC1120_REGS_STROBE_SRX          0x34U
#define CC1120_REGS_STROBE_STX          0x35U
#define CC1120_REGS_STROBE_SIDLE        0x36U
#define CC1120_REGS_STROBE_SWOR         0x38U
#define CC1120_REGS_STROBE_SPWD         0x39U
#define CC1120_REGS_STROBE_SFRX         0x3AU
#define CC1120_REGS_STROBE_SFTX         0x3BU
#define CC1120_REGS_STROBE_SWORRST      0x3CU
#define CC1120_REGS_STROBE_SNOP         0x3DU

// FIFO access registers
#define CC1120_REGS_FIFO_ACCESS_DIR     0x3EU
#define CC1120_REGS_FIFO_ACCESS_STD     0x3FU
#define CC1120_REGS_FIFO_TX_START       0x00U
#define CC1120_REGS_FIFO_TX_END         0x7FU
#define CC1120_REGS_FIFO_RX_START       0x80U
#define CC1120_REGS_FIFO_RX_END         0xFFU

// EXTENDED REGISTER SPACE
#define CC1120_REGS_EXT_IF_MIX_CFG          0x00U
#define CC1120_REGS_EXT_FREQOFF_CFG         0x01U
#define CC1120_REGS_EXT_TOC_CFG             0x02U
#define CC1120_REGS_EXT_MARC_SPARE          0x03U
#define CC1120_REGS_EXT_ECG_CFG             0x04U
#define CC1120_REGS_EXT_CFM_DATA_CFG        0x05U
#define CC1120_REGS_EXT_EXT_CTRL            0x06U
#define CC1120_REGS_EXT_RCCAL_FINE          0x07U
#define CC1120_REGS_EXT_RCCAL_COARSE        0x08U
#define CC1120_REGS_EXT_RCCAL_OFFSET        0x09U
#define CC1120_REGS_EXT_FREQOFF1            0x0AU
#define CC1120_REGS_EXT_FREQOFF0            0x0BU
#define CC1120_REGS_EXT_FREQ2               0x0CU
#define CC1120_REGS_EXT_FREQ1               0x0DU
#define CC1120_REGS_EXT_FREQ0               0x0EU
#define CC1120_REGS_EXT_IF_ADC2             0x0FU
#define CC1120_REGS_EXT_IF_ADC1             0x10U
#define CC1120_REGS_EXT_IF_ADC0             0x11U
#define CC1120_REGS_EXT_FS_DIG1             0x12U
#define CC1120_REGS_EXT_FS_DIG0             0x13U
#define CC1120_REGS_EXT_FS_CAL3             0x14U
#define CC1120_REGS_EXT_FS_CAL2             0x15U
#define CC1120_REGS_EXT_FS_CAL1             0x16U
#define CC1120_REGS_EXT_FS_CAL0             0x17U
#define CC1120_REGS_EXT_FS_CHP              0x18U
#define CC1120_REGS_EXT_FS_DIVTWO           0x19U
#define CC1120_REGS_EXT_FS_DSM1             0x1AU
#define CC1120_REGS_EXT_FS_DSM0             0x1BU
#define CC1120_REGS_EXT_FS_DVC1             0x1CU
#define CC1120_REGS_EXT_FS_DVC0             0x1DU
#define CC1120_REGS_EXT_FS_LBI              0x1EU
#define CC1120_REGS_EXT_FS_PFD              0x1FU
#define CC1120_REGS_EXT_FS_PRE              0x20U
#define CC1120_REGS_EXT_FS_REG_DIV_CML      0x21U
#define CC1120_REGS_EXT_FS_SPARE            0x22U
#define CC1120_REGS_EXT_FS_VCO4             0x23U
#define CC1120_REGS_EXT_FS_VCO3             0x24U
#define CC1120_REGS_EXT_FS_VCO2             0x25U
#define CC1120_REGS_EXT_FS_VCO1             0x26U
#define CC1120_REGS_EXT_FS_VCO0             0x27U
#define CC1120_REGS_EXT_GBIAS6              0x28U
#define CC1120_REGS_EXT_GBIAS5              0x29U
#define CC1120_REGS_EXT_GBIAS4              0x2AU
#define CC1120_REGS_EXT_GBIAS3              0x2BU
#define CC1120_REGS_EXT_GBIAS2              0x2CU
#define CC1120_REGS_EXT_GBIAS1              0x2DU
#define CC1120_REGS_EXT_GBIAS0              0x2EU
#define CC1120_REGS_EXT_IFAMP               0x2FU
#define CC1120_REGS_EXT_LNA                 0x30U
#define CC1120_REGS_EXT_RXMIX               0x31U
#define CC1120_REGS_EXT_XOSC5               0x32U
#define CC1120_REGS_EXT_XOSC4               0x33U
#define CC1120_REGS_EXT_XOSC3               0x34U
#define CC1120_REGS_EXT_XOSC2               0x35U
#define CC1120_REGS_EXT_XOSC1               0x36U
#define CC1120_REGS_EXT_XOSC0               0x37U
#define CC1120_REGS_EXT_ANALOG_SPARE        0x38U
#define CC1120_REGS_EXT_PA_CFG3             0x39U

#define CC1120_REGS_EXT_WOR_TIME1           0x64U
#define CC1120_REGS_EXT_WOR_TIME0           0x65U
#define CC1120_REGS_EXT_WOR_CAPTURE1        0x66U
#define CC1120_REGS_EXT_WOR_CAPTURE0        0x67U
#define CC1120_REGS_EXT_BIST                0x68U
#define CC1120_REGS_EXT_DCFILTOFFSET_I1     0x69U
#define CC1120_REGS_EXT_DCFILTOFFSET_I0     0x6AU
#define CC1120_REGS_EXT_DCFILTOFFSET_Q1     0x6BU
#define CC1120_REGS_EXT_DCFILTOFFSET_Q0     0x6CU
#define CC1120_REGS_EXT_IQIE_I1             0x6DU
#define CC1120_REGS_EXT_IQIE_I0             0x6EU
#define CC1120_REGS_EXT_IQIE_Q1             0x6FU
#define CC1120_REGS_EXT_IQIE_Q0             0x70U
#define CC1120_REGS_EXT_RSSI1               0x71U
#define CC1120_REGS_EXT_RSSI0               0x72U
#define CC1120_REGS_EXT_MARCSTATE           0x73U
#define CC1120_REGS_EXT_LQI_VAL             0x74U
#define CC1120_REGS_EXT_PQT_SYNC_ERR        0x75U
#define CC1120_REGS_EXT_DEM_STATUS          0x76U
#define CC1120_REGS_EXT_FREQOFF_EST1        0x77U
#define CC1120_REGS_EXT_FREQOFF_EST0        0x78U
#define CC1120_REGS_EXT_AGC_GAIN3           0x79U
#define CC1120_REGS_EXT_AGC_GAIN2           0x7AU
#define CC1120_REGS_EXT_AGC_GAIN1           0x7BU
#define CC1120_REGS_EXT_AGC_GAIN0           0x7CU
#define CC1120_REGS_EXT_CFM_RX_DATA_OUT     0x7DU
#define CC1120_REGS_EXT_CFM_TX_DATA_IN      0x7EU
#define CC1120_REGS_EXT_ASK_SOFT_RX_DATA    0x7FU
#define CC1120_REGS_EXT_RNDGEN              0x80U
#define CC1120_REGS_EXT_MAGN2               0x81U
#define CC1120_REGS_EXT_MAGN1               0x82U
#define CC1120_REGS_EXT_MAGN0               0x83U
#define CC1120_REGS_EXT_ANG1                0x84U
#define CC1120_REGS_EXT_ANG0                0x85U
#define CC1120_REGS_EXT_CHFILT_I2           0x86U
#define CC1120_REGS_EXT_CHFILT_I1           0x87U
#define CC1120_REGS_EXT_CHFILT_I0           0x88U
#define CC1120_REGS_EXT_CHFILT_Q2           0x89U
#define CC1120_REGS_EXT_CHFILT_Q1           0x8AU
#define CC1120_REGS_EXT_CHFILT_Q0           0x8BU
#define CC1120_REGS_EXT_GPIO_STATUS         0x8CU
#define CC1120_REGS_EXT_FSCAL_CTRL          0x8DU
#define CC1120_REGS_EXT_PHASE_ADJUST        0x8EU
#define CC1120_REGS_EXT_PARTNUMBER          0x8FU
#define CC1120_REGS_EXT_PARTVERSION         0x90U
#define CC1120_REGS_EXT_SERIAL_STATUS       0x91U
#define CC1120_REGS_EXT_MODEM_STATUS1       0x92U
#define CC1120_REGS_EXT_MODEM_STATUS0       0x93U
#define CC1120_REGS_EXT_MARC_STATUS1        0x94U
#define CC1120_REGS_EXT_MARC_STATUS0        0x95U
#define CC1120_REGS_EXT_PA_IFAMP_TEST       0x96U
#define CC1120_REGS_EXT_FSRF_TEST           0x97U
#define CC1120_REGS_EXT_PRE_TEST            0x98U
#define CC1120_REGS_EXT_PRE_OVR             0x99U
#define CC1120_REGS_EXT_ADC_TEST            0x9AU
#define CC1120_REGS_EXT_DVC_TEST            0x9BU
#define CC1120_REGS_EXT_ATEST               0x9CU
#define CC1120_REGS_EXT_ATEST_LVDS          0x9DU
#define CC1120_REGS_EXT_ATEST_MODE          0x9EU
#define CC1120_REGS_EXT_XOSC_TEST1          0x9FU
#define CC1120_REGS_EXT_XOSC_TEST0          0xA0U

#define CC1120_REGS_EXT_RXFIRST             0xD2U
#define CC1120_REGS_EXT_TXFIRST             0xD3U
#define CC1120_REGS_EXT_RXLAST              0xD4U
#define CC1120_REGS_EXT_TXLAST              0xD5U
#define CC1120_REGS_EXT_NUM_TXBYTES         0xD6U
#define CC1120_REGS_EXT_NUM_RXBYTES         0xD7U
#define CC1120_REGS_EXT_FIFO_NUM_TXBYTES    0xD8U
#define CC1120_REGS_EXT_FIFO_NUM_RXBYTES    0xD9U

#endif /* CC1120_REGS_H */
