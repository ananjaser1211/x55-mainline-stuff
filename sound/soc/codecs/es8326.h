/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * es8326.h -- es8326 ALSA SoC audio driver
 * Copyright Everest Semiconductor Co.,Ltd
 *
 * Authors: David Yang <yangxiaohua@everest-semi.com>
 */

#ifndef _ES8326_H
#define _ES8326_H

/* ES8326 register space */
#define ES8326_RESET		0x00
#define ES8326_CLK_CTL		0x01
#define ES8326_CLK_INV		0x02
#define ES8326_CLK_RESAMPLE	0x03
#define ES8326_CLK_DIV1		0x04
#define ES8326_CLK_DIV2		0x05
#define ES8326_CLK_DLL		0x06
#define ES8326_CLK_MUX		0x07
#define ES8326_CLK_ADC_SEL	0x08
#define ES8326_CLK_DAC_SEL	0x09
#define ES8326_CLK_ADC_OSR	0x0a
#define ES8326_CLK_DAC_OSR	0x0b
#define ES8326_CLK_DIV_CPC	0x0c
#define ES8326_CLK_DIV_BCLK	0x0d
#define ES8326_CLK_TRI		0x0e
#define ES8326_CLK_DIV_LRCK	0x0f
#define ES8326_CLK_VMIDS1	0x10
#define ES8326_CLK_VMIDS2	0x11
#define ES8326_CLK_CAL_TIME	0x12
#define ES8326_FMT		0x13

#define ES8326_DAC_MUTE		0x14
#define ES8326_ADC_MUTE		0x15
#define ES8326_ANA_PDN		0x16
#define ES8326_PGA_PDN		0x17
#define ES8326_VMIDSEL		0x18
#define ES8326_ANA_LP		0x19
#define ES8326_ANA_DMS		0x1a
#define ES8326_ANA_MICBIAS	0x1b
#define ES8326_ANA_VSEL		0x1c
#define ES8326_SYS_BIAS		0x1d
#define ES8326_BIAS_SW1		0x1e
#define ES8326_BIAS_SW2		0x1f
#define ES8326_BIAS_SW3		0x20
#define ES8326_BIAS_SW4		0x21
#define ES8326_VMIDLOW		0x22
#define ES8326_PGAGAIN		0x23
#define ES8326_HP_DRIVER	0x24
#define ES8326_DAC2HPMIX	0x25
#define ES8326_HP_VOL		0x26
#define ES8326_HP_CAL		0x27
#define ES8326_HP_DRIVER_REF	0x28
#define ES8326_ADC_SCALE	0x29
#define ES8326_ADC1_SRC		0x2a
#define ES8326_ADC2_SRC		0x2b
#define ES8326_ADC1_VOL		0x2c
#define ES8326_ADC2_VOL		0x2d
#define ES8326_ADC_RAMPRATE	0x2e
#define ES8326_ALC_RECOVERY	0x32
#define ES8326_ALC_LEVEL	0x33
#define ES8326_ADC_HPFS1	0x34
#define ES8326_ADC_HPFS2	0x35
#define ES8326_ADC_EQ		0x36
#define ES8326_HP_OFFSET_CAL	0x4A
#define ES8326_HPL_OFFSET_INI	0x4B
#define ES8326_HPR_OFFSET_INI	0x4C
#define ES8326_DAC_DSM		0x4D
#define ES8326_DAC_RAMPRATE	0x4E
#define ES8326_DAC_VPPSCALE	0x4F
#define ES8326_DAC_VOL		0x50
#define ES8326_DRC_RECOVERY	0x53
#define ES8326_DRC_WINSIZE	0x54
#define ES8326_DAC_CROSSTALK	0x55
#define ES8326_HPJACK_TIMER	0x56
#define ES8326_HPDET_TYPE	0x57
#define ES8326_INT_SOURCE	0x58
#define ES8326_INTOUT_IO	0x59
#define ES8326_SDINOUT1_IO	0x5A
#define ES8326_SDINOUT23_IO	0x5B
#define ES8326_JACK_PULSE	0x5C

#define ES8326_HP_MISC		0xF7
#define ES8326_CTIA_OMTP_STA	0xF8
#define ES8326_PULLUP_CTL	0xF9
#define ES8326_CSM_I2C_STA	0xFA
#define ES8326_HPDET_STA	0xFB
#define ES8326_CSM_MUTE_STA	0xFC
#define ES8326_CHIP_ID1		0xFD
#define ES8326_CHIP_ID2		0xFE
#define ES8326_CHIP_VERSION	0xFF

/* ES8326_RESET */
#define ES8326_CSM_ON (1 << 7)
#define ES8326_MASTER_MODE_EN	(1 << 6)
#define	ES8326_PWRUP_SEQ_EN	(1 << 5)
#define ES8326_CODEC_RESET (0x0f << 0)
#define ES8326_CSM_OFF (0 << 7)
#define ES8326_MUTE_MASK (3 << 0)
#define ES8326_MUTE (3 << 0)

/* ES8326_CLK_CTL */
#define ES8326_CLK_ON (0x7e << 0)
#define ES8326_CLK_OFF (0 << 0)

/* ES8326_CLK_INV */
#define ES8326_BCLK_AS_MCLK (1 << 3)

/* ES8326_FMT */
#define ES8326_S24_LE	(0 << 2)
#define ES8326_S20_3_LE	(1 << 2)
#define ES8326_S18_LE	(2 << 2)
#define ES8326_S16_LE	(3 << 2)
#define ES8326_S32_LE	(4 << 2)
#define ES8326_DATA_LEN_MASK	(7 << 2)

#define ES8326_DAIFMT_MASK	((1 << 5) | (3 << 0))
#define ES8326_DAIFMT_I2S	0
#define ES8326_DAIFMT_LEFT_J	(1 << 0)
#define ES8326_DAIFMT_DSP_A	(3 << 0)
#define ES8326_DAIFMT_DSP_B	((1 << 5) | (3 << 0))

/* ES8326_PGAGAIN */
#define ES8326_MIC_SEL_MASK (3 << 4)
#define ES8326_MIC1_SEL	(1 << 4)
#define ES8326_MIC2_SEL (1 << 5)

/* ES8326_HP_CAL */
#define ES8326_HP_OFF 0
#define ES8326_HP_FORCE_CAL ((1 << 7) | (1 << 3))
#define ES8326_HP_ON ((7 << 4) | (7 << 0))

/* ES8326_ADC1_SRC */
#define ES8326_ADC1_SHIFT 0
#define ES8326_ADC2_SHIFT 4
#define ES8326_ADC_SRC_ANA 0
#define ES8326_ADC_SRC_ANA_INV_SW0 1
#define ES8326_ADC_SRC_ANA_INV_SW1 2
#define ES8326_ADC_SRC_DMIC_MCLK 3
#define ES8326_ADC_SRC_DMIC_SDIN2 4
#define ES8326_ADC_SRC_DMIC_SDIN2_INV 5
#define ES8326_ADC_SRC_DMIC_SDIN3 6
#define ES8326_ADC_SRC_DMIC_SDIN3_INV 7

#define ES8326_ADC_AMIC	((ES8326_ADC_SRC_ANA_INV_SW1 << ES8326_ADC2_SHIFT) \
		| (ES8326_ADC_SRC_ANA_INV_SW1 << ES8326_ADC1_SHIFT))
#define ES8326_ADC_DMIC	((ES8326_ADC_SRC_DMIC_SDIN2 << ES8326_ADC2_SHIFT) \
		| (ES8326_ADC_SRC_DMIC_SDIN2 << ES8326_ADC1_SHIFT))
/* ES8326_ADC2_SRC */
#define ES8326_ADC3_SHIFT 0
#define ES8326_ADC4_SHIFT 3

/* ES8326_HPDET_TYPE */
#define ES8326_HP_DET_SRC_PIN27 (1 << 5)
#define ES8326_HP_DET_SRC_PIN9 (1 << 4)
#define ES8326_HP_DET_JACK_POL (1 << 3)
#define ES8326_HP_DET_BUTTON_POL (1 << 2)
#define ES8326_HP_TYPE_OMTP	(3 << 0)
#define ES8326_HP_TYPE_CTIA	(2 << 0)
#define ES8326_HP_TYPE_AUTO	(1 << 0)
#define ES8326_HP_TYPE_AUTO_INV	(0 << 0)

/* ES8326_INT_SOURCE */
#define ES8326_INT_SRC_DAC_MOZ (1 << 0)
#define ES8326_INT_SRC_ADC_MOZ (1 << 1)
#define ES8326_INT_SRC_BUTTON (1 << 2)
#define ES8326_INT_SRC_PIN9 (1 << 3)
#define ES8326_INT_SRC_PIN27 (1 << 4)

/* ES8326_SDINOUT1_IO */
#define ES8326_IO_INPUT	(0 << 0)
#define ES8326_IO_SDIN_SLOT0 (1 << 0)
#define ES8326_IO_SDIN_SLOT1 (2 << 0)
#define ES8326_IO_SDIN_SLOT2 (3 << 0)
#define ES8326_IO_SDIN_SLOT7 (8 << 0)
#define ES8326_IO_DMIC_CLK (9 << 0)
#define ES8326_IO_DMIC_CLK_INV (0x0a << 0)
#define ES8326_IO_SDOUT2 (0x0b << 0)
#define ES8326_IO_LOW (0x0e << 0)
#define ES8326_IO_HIGH (0x0f << 0)
#define ES8326_ADC2DAC (1 << 3)
#define ES8326_SDINOUT1_SHIFT 4

/* ES8326_SDINOUT23_IO */
#define ES8326_SDINOUT2_SHIFT 4
#define ES8326_SDINOUT3_SHIFT 0

/* ES8326_HPDET_STA */
#define ES8326_HPINSERT_FLAG (1 << 1)
#define ES8326_HPBUTTON_FLAG (1 << 0)

/* ES8326_CHIP_VERSION 0xFF */
#define ES8326_VERSION (1 << 0)
#define ES8326_VERSION_B (3 << 0)

#endif
