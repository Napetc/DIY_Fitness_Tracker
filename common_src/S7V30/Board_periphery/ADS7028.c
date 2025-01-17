﻿// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2023-01-29
// 14:09:35 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"

#define  MAX_ADS7028_BUF_SZ   128

typedef __packed  struct
{
  uint8_t cmd;
  uint8_t addr;
  uint8_t data[MAX_ADS7028_BUF_SZ];

} T_ADS7028_buf;

T_ADS7028_buf ads7028_buf;

static void Set_ADC1_CS(uint8_t v);
static void Set_ADC2_CS(uint8_t v);

typedef void (*T_set_adc_sc)(uint8_t val);

T_set_adc_sc Set_adc_cs[2] = {Set_ADC1_CS, Set_ADC2_CS};




const  T_ADS7028_reg_descr ADS7028_regs[]=
{
  {  ADS7028_SYSTEM_STATUS             , "SYSTEM_STATUS            "},
  {  ADS7028_GENERAL_CFG               , "GENERAL_CFG              "},
  {  ADS7028_DATA_CFG                  , "DATA_CFG                 "},
  {  ADS7028_OSR_CFG                   , "OSR_CFG                  "},
  {  ADS7028_OPMODE_CFG                , "OPMODE_CFG               "},
  {  ADS7028_PIN_CFG                   , "PIN_CFG                  "},
  {  ADS7028_GPIO_CFG                  , "GPIO_CFG                 "},
  {  ADS7028_GPO_DRIVE_CFG             , "GPO_DRIVE_CFG            "},
  {  ADS7028_GPO_VALUE                 , "GPO_VALUE                "},
  {  ADS7028_GPI_VALUE                 , "GPI_VALUE                "},
  {  ADS7028_ZCD_BLANKING_CFG          , "ZCD_BLANKING_CFG         "},
  {  ADS7028_SEQUENCE_CFG              , "SEQUENCE_CFG             "},
  {  ADS7028_CHANNEL_SEL               , "CHANNEL_SEL              "},
  {  ADS7028_AUTO_SEQ_CH_SEL           , "AUTO_SEQ_CH_SEL          "},
  {  ADS7028_ALERT_CH_SEL              , "ALERT_CH_SEL             "},
  {  ADS7028_ALERT_MAP                 , "ALERT_MAP                "},
  {  ADS7028_ALERT_PIN_CFG             , "ALERT_PIN_CFG            "},
  {  ADS7028_EVENT_FLAG                , "EVENT_FLAG               "},
  {  ADS7028_EVENT_HIGH_FLAG           , "EVENT_HIGH_FLAG          "},
  {  ADS7028_EVENT_LOW_FLAG            , "EVENT_LOW_FLAG           "},
  {  ADS7028_EVENT_RGN                 , "EVENT_RGN                "},
  {  ADS7028_HYSTERESIS_CH0            , "HYSTERESIS_CH0           "},
  {  ADS7028_HIGH_TH_CH0               , "HIGH_TH_CH0              "},
  {  ADS7028_EVENT_COUNT_CH0           , "EVENT_COUNT_CH0          "},
  {  ADS7028_LOW_TH_CH0                , "LOW_TH_CH0               "},
  {  ADS7028_HYSTERESIS_CH1            , "HYSTERESIS_CH1           "},
  {  ADS7028_HIGH_TH_CH1               , "HIGH_TH_CH1              "},
  {  ADS7028_EVENT_COUNT_CH1           , "EVENT_COUNT_CH1          "},
  {  ADS7028_LOW_TH_CH1                , "LOW_TH_CH1               "},
  {  ADS7028_HYSTERESIS_CH2            , "HYSTERESIS_CH2           "},
  {  ADS7028_HIGH_TH_CH2               , "HIGH_TH_CH2              "},
  {  ADS7028_EVENT_COUNT_CH2           , "EVENT_COUNT_CH2          "},
  {  ADS7028_LOW_TH_CH2                , "LOW_TH_CH2               "},
  {  ADS7028_HYSTERESIS_CH3            , "HYSTERESIS_CH3           "},
  {  ADS7028_HIGH_TH_CH3               , "HIGH_TH_CH3              "},
  {  ADS7028_EVENT_COUNT_CH3           , "EVENT_COUNT_CH3          "},
  {  ADS7028_LOW_TH_CH3                , "LOW_TH_CH3               "},
  {  ADS7028_HYSTERESIS_CH4            , "HYSTERESIS_CH4           "},
  {  ADS7028_HIGH_TH_CH4               , "HIGH_TH_CH4              "},
  {  ADS7028_EVENT_COUNT_CH4           , "EVENT_COUNT_CH4          "},
  {  ADS7028_LOW_TH_CH4                , "LOW_TH_CH4               "},
  {  ADS7028_HYSTERESIS_CH5            , "HYSTERESIS_CH5           "},
  {  ADS7028_HIGH_TH_CH5               , "HIGH_TH_CH5              "},
  {  ADS7028_EVENT_COUNT_CH5           , "EVENT_COUNT_CH5          "},
  {  ADS7028_LOW_TH_CH5                , "LOW_TH_CH5               "},
  {  ADS7028_HYSTERESIS_CH6            , "HYSTERESIS_CH6           "},
  {  ADS7028_HIGH_TH_CH6               , "HIGH_TH_CH6              "},
  {  ADS7028_EVENT_COUNT_CH6           , "EVENT_COUNT_CH6          "},
  {  ADS7028_LOW_TH_CH6                , "LOW_TH_CH6               "},
  {  ADS7028_HYSTERESIS_CH7            , "HYSTERESIS_CH7           "},
  {  ADS7028_HIGH_TH_CH7               , "HIGH_TH_CH7              "},
  {  ADS7028_EVENT_COUNT_CH7           , "EVENT_COUNT_CH7          "},
  {  ADS7028_LOW_TH_CH7                , "LOW_TH_CH7               "},
  {  ADS7028_MAX_CH0_LSB               , "MAX_CH0_LSB              "},
  {  ADS7028_MAX_CH0_MSB               , "MAX_CH0_MSB              "},
  {  ADS7028_MAX_CH1_LSB               , "MAX_CH1_LSB              "},
  {  ADS7028_MAX_CH1_MSB               , "MAX_CH1_MSB              "},
  {  ADS7028_MAX_CH2_LSB               , "MAX_CH2_LSB              "},
  {  ADS7028_MAX_CH2_MSB               , "MAX_CH2_MSB              "},
  {  ADS7028_MAX_CH3_LSB               , "MAX_CH3_LSB              "},
  {  ADS7028_MAX_CH3_MSB               , "MAX_CH3_MSB              "},
  {  ADS7028_MAX_CH4_LSB               , "MAX_CH4_LSB              "},
  {  ADS7028_MAX_CH4_MSB               , "MAX_CH4_MSB              "},
  {  ADS7028_MAX_CH5_LSB               , "MAX_CH5_LSB              "},
  {  ADS7028_MAX_CH5_MSB               , "MAX_CH5_MSB              "},
  {  ADS7028_MAX_CH6_LSB               , "MAX_CH6_LSB              "},
  {  ADS7028_MAX_CH6_MSB               , "MAX_CH6_MSB              "},
  {  ADS7028_MAX_CH7_LSB               , "MAX_CH7_LSB              "},
  {  ADS7028_MAX_CH7_MSB               , "MAX_CH7_MSB              "},
  {  ADS7028_MIN_CH0_LSB               , "MIN_CH0_LSB              "},
  {  ADS7028_MIN_CH0_MSB               , "MIN_CH0_MSB              "},
  {  ADS7028_MIN_CH1_LSB               , "MIN_CH1_LSB              "},
  {  ADS7028_MIN_CH1_MSB               , "MIN_CH1_MSB              "},
  {  ADS7028_MIN_CH2_LSB               , "MIN_CH2_LSB              "},
  {  ADS7028_MIN_CH2_MSB               , "MIN_CH2_MSB              "},
  {  ADS7028_MIN_CH3_LSB               , "MIN_CH3_LSB              "},
  {  ADS7028_MIN_CH3_MSB               , "MIN_CH3_MSB              "},
  {  ADS7028_MIN_CH4_LSB               , "MIN_CH4_LSB              "},
  {  ADS7028_MIN_CH4_MSB               , "MIN_CH4_MSB              "},
  {  ADS7028_MIN_CH5_LSB               , "MIN_CH5_LSB              "},
  {  ADS7028_MIN_CH5_MSB               , "MIN_CH5_MSB              "},
  {  ADS7028_MIN_CH6_LSB               , "MIN_CH6_LSB              "},
  {  ADS7028_MIN_CH6_MSB               , "MIN_CH6_MSB              "},
  {  ADS7028_MIN_CH7_LSB               , "MIN_CH7_LSB              "},
  {  ADS7028_MIN_CH7_MSB               , "MIN_CH7_MSB              "},
  {  ADS7028_RECENT_CH0_LSB            , "RECENT_CH0_LSB           "},
  {  ADS7028_RECENT_CH0_MSB            , "RECENT_CH0_MSB           "},
  {  ADS7028_RECENT_CH1_LSB            , "RECENT_CH1_LSB           "},
  {  ADS7028_RECENT_CH1_MSB            , "RECENT_CH1_MSB           "},
  {  ADS7028_RECENT_CH2_LSB            , "RECENT_CH2_LSB           "},
  {  ADS7028_RECENT_CH2_MSB            , "RECENT_CH2_MSB           "},
  {  ADS7028_RECENT_CH3_LSB            , "RECENT_CH3_LSB           "},
  {  ADS7028_RECENT_CH3_MSB            , "RECENT_CH3_MSB           "},
  {  ADS7028_RECENT_CH4_LSB            , "RECENT_CH4_LSB           "},
  {  ADS7028_RECENT_CH4_MSB            , "RECENT_CH4_MSB           "},
  {  ADS7028_RECENT_CH5_LSB            , "RECENT_CH5_LSB           "},
  {  ADS7028_RECENT_CH5_MSB            , "RECENT_CH5_MSB           "},
  {  ADS7028_RECENT_CH6_LSB            , "RECENT_CH6_LSB           "},
  {  ADS7028_RECENT_CH6_MSB            , "RECENT_CH6_MSB           "},
  {  ADS7028_RECENT_CH7_LSB            , "RECENT_CH7_LSB           "},
  {  ADS7028_RECENT_CH7_MSB            , "RECENT_CH7_MSB           "},
  {  ADS7028_RMS_CFG                   , "RMS_CFG                  "},
  {  ADS7028_RMS_LSB                   , "RMS_LSB                  "},
  {  ADS7028_RMS_MSB                   , "RMS_MSB                  "},
  {  ADS7028_GPO0_TRIG_EVENT_SEL       , "GPO0_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO1_TRIG_EVENT_SEL       , "GPO1_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO2_TRIG_EVENT_SEL       , "GPO2_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO3_TRIG_EVENT_SEL       , "GPO3_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO4_TRIG_EVENT_SEL       , "GPO4_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO5_TRIG_EVENT_SEL       , "GPO5_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO6_TRIG_EVENT_SEL       , "GPO6_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO7_TRIG_EVENT_SEL       , "GPO7_TRIG_EVENT_SEL      "},
  {  ADS7028_GPO_VALUE_ZCD_CFG_CH0_CH3 , "GPO_VALUE_ZCD_CFG_CH0_CH3"},
  {  ADS7028_GPO_VALUE_ZCD_CFG_CH4_CH7 , "GPO_VALUE_ZCD_CFG_CH4_CH7"},
  {  ADS7028_GPO_ZCD_UPDATE_EN         , "GPO_ZCD_UPDATE_EN        "},
  {  ADS7028_GPO_TRIGGER_CFG           , "GPO_TRIGGER_CFG          "},
  {  ADS7028_GPO_VALUE_TRIG            , "GPO_VALUE_TRIG           "},
};


/*-----------------------------------------------------------------------------------------------------
  Открытие коммуникационного канала с чипом ADS7028

  Быть внимательным при вызове из разных задач!!!

  n - номер чипа на плате

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
uint32_t  ADS7028_open(void)
{
  SCI8_SPI_init();
  return RES_OK;
}

/*-----------------------------------------------------------------------------------------------------
  Закрытие коммуникационного канала с чипом ADS7028
  Поскольку на шине находятся и другие чипы то здесь также производится освобождение шины.


  n - номер чипа на плате

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
uint32_t  ADS7028_close(void)
{
  return RES_OK;
}


static void Set_ADC1_CS(uint8_t v)
{
  R_PFS->PB02PFS_b.PODR = v;
}

static void Set_ADC2_CS(uint8_t v)
{
  R_PFS->PB06PFS_b.PODR = v;
}

/*-----------------------------------------------------------------------------------------------------

  n - номер чипа на плате
  \param addr
  \param val

  \return ssp_err_t
-----------------------------------------------------------------------------------------------------*/
uint32_t ADS7028_read(uint8_t n, uint8_t addr, uint8_t *val)
{
  uint32_t       res;
  uint8_t        rd_buf[3];

  ads7028_buf.cmd  = 0x10;
  ads7028_buf.addr = addr;
  ads7028_buf.data[0] = 0;


  Set_adc_cs[n](0);
  res = SCI8_SPI_tx_rx_buf((uint8_t*)&ads7028_buf, 0, 3);
  Set_adc_cs[n](1);


  if (res != RES_OK) return res;

  Set_adc_cs[n](0);
  res = SCI8_SPI_tx_rx_buf(0, rd_buf, 3);
  Set_adc_cs[n](1);

  *val = rd_buf[0];

  return res;
}

/*-----------------------------------------------------------------------------------------------------


  \param n - номер чипа на плате
  \param addr
  \param val

  \return ssp_err_t
-----------------------------------------------------------------------------------------------------*/
uint32_t ADS7028_write(uint8_t n, uint8_t addr, uint8_t val)
{
  uint32_t   res;

  ads7028_buf.cmd  = 0x08;
  ads7028_buf.addr = addr;
  ads7028_buf.data[0] = val;

  Set_adc_cs[n](0);
  res = SCI8_SPI_tx_rx_buf((uint8_t*)&ads7028_buf, 0, 3);
  Set_adc_cs[n](1);

  return res;
}

/*-----------------------------------------------------------------------------------------------------


  \param n
  \param addr
  \param val

  \return ssp_err_t
-----------------------------------------------------------------------------------------------------*/
uint32_t ADS7028_set_channel_read_result(uint8_t n, uint8_t addr, uint8_t channel_sel, uint16_t *pval)
{
  uint32_t       res;
  uint8_t        rx_buf[3];

  *pval = 0;

  ads7028_buf.cmd  = 0x08;
  ads7028_buf.addr = addr;
  ads7028_buf.data[0] = channel_sel;

  Set_adc_cs[n](0);
  res = SCI8_SPI_tx_rx_buf((uint8_t*)&ads7028_buf, rx_buf, 3);
  Set_adc_cs[n](1);


  *pval = ((rx_buf[0] << 8) | rx_buf[1]) >> 4;
  return res;
}

/*-----------------------------------------------------------------------------------------------------


  \param n
  \param pval

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
uint32_t ADS7028_read_autoscan_result(uint8_t n, uint16_t *pval)
{
  uint32_t   res;
  uint8_t    rx_buf[2];

  Set_adc_cs[n](0);
  res = SCI8_SPI_tx_rx_buf(0, rx_buf, 2);
  Set_adc_cs[n](1);

  *pval = ((rx_buf[0] << 8) | rx_buf[1]) >> 4;
  return res;
}

