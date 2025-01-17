﻿// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2023-02-02
// 10:13:54 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"

//........................................................................................
//  Организация канала приема данных по I2C0
//  Используется модуль DTC
//........................................................................................
dtc_instance_ctrl_t DTC_I2C0_RX_control_block;

transfer_info_t DTC_I2C0_RX_transfer_info =
{
  .dest_addr_mode      = TRANSFER_ADDR_MODE_INCREMENTED,
  .repeat_area         = TRANSFER_REPEAT_AREA_DESTINATION,
  .irq                 = TRANSFER_IRQ_END,
  .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode       = TRANSFER_ADDR_MODE_FIXED,
  .size                = TRANSFER_SIZE_1_BYTE,
  .mode                = TRANSFER_MODE_NORMAL,
  .p_dest              = (void *) NULL,
  .p_src               = (void const *) NULL,
  .num_blocks          = 0,
  .length              = 0,
};

const transfer_cfg_t DTC_I2C0_RX_configuration =
{
  .p_info              =&DTC_I2C0_RX_transfer_info,
  .activation_source   = ELC_EVENT_IIC0_RXI,
  .auto_enable         = false,
  .p_callback          = NULL,
  .p_context           =&DTC_I2C0_RX_transfer_instance,
  .irq_ipl             =(BSP_IRQ_DISABLED)  // Interrupt priority level
};

const transfer_instance_t DTC_I2C0_RX_transfer_instance =
{
  .p_ctrl        =&DTC_I2C0_RX_control_block,
  .p_cfg         =&DTC_I2C0_RX_configuration,
  .p_api         =&g_transfer_on_dtc
};


//........................................................................................
//  Организация канала передачи данных по I2C0
//  Используется модуль DTC
//........................................................................................

dtc_instance_ctrl_t DTC_I2C0_TX_control_block;

transfer_info_t DTC_I2C0_TX_transfer_info =
{
  .dest_addr_mode      = TRANSFER_ADDR_MODE_FIXED,
  .repeat_area         = TRANSFER_REPEAT_AREA_SOURCE,
  .irq                 = TRANSFER_IRQ_END,
  .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode       = TRANSFER_ADDR_MODE_INCREMENTED,
  .size                = TRANSFER_SIZE_1_BYTE,
  .mode                = TRANSFER_MODE_NORMAL,
  .p_dest              = (void *) NULL,
  .p_src               = (void const *) NULL,
  .num_blocks          = 0,
  .length              = 0,
};

const transfer_cfg_t DTC_I2C0_TX_configuration =
{
  .p_info              =&DTC_I2C0_TX_transfer_info,
  .activation_source   = ELC_EVENT_IIC0_TXI,
  .auto_enable         = false,
  .p_callback          = NULL,
  .p_context           =&DTC_I2C0_TX_transfer_instance,
  .irq_ipl             =(BSP_IRQ_DISABLED)
};

const transfer_instance_t DTC_I2C0_TX_transfer_instance =
{
  .p_ctrl        =&DTC_I2C0_TX_control_block,
  .p_cfg         =&DTC_I2C0_TX_configuration,
  .p_api         =&g_transfer_on_dtc
};


//........................................................................................
//  Организация приема-передачи по I2C0
//........................................................................................

SSP_VECTOR_DEFINE_CHAN(iic_rxi_isr, IIC, RXI, 0);
SSP_VECTOR_DEFINE_CHAN(iic_txi_isr, IIC, TXI, 0);
SSP_VECTOR_DEFINE_CHAN(iic_tei_isr, IIC, TEI, 0);
SSP_VECTOR_DEFINE_CHAN(iic_eri_isr, IIC, ERI, 0);

riic_instance_ctrl_t    I2C0_control_block;

const riic_extended_cfg I2C0_extended_configuration =
{
  .timeout_mode = RIIC_TIMEOUT_MODE_LONG,
};

const i2c_cfg_t I2C0_configuration =
{
  .channel             = 0,
  .rate                = I2C_RATE_STANDARD,
  .slave               = 0,
  .addr_mode           = I2C_ADDR_MODE_7BIT,
  .sda_delay           = 300,
  .p_transfer_tx       =&DTC_I2C0_TX_transfer_instance,
  .p_transfer_rx       =&DTC_I2C0_RX_transfer_instance,
  .p_callback          = NULL,
  .p_context           = (void *)&I2C0_interface_instance,
  .rxi_ipl             =(12),  // Receive interrupt priority
  .txi_ipl             =(12),  // Transmit interrupt priority
  .tei_ipl             =(12),  // Transmit end interrupt priority
  .eri_ipl             =(12),  // Error interrupt priority
  .p_extend            =&I2C0_extended_configuration,
};

const i2c_master_instance_t I2C0_interface_instance =
{
  .p_ctrl        =&I2C0_control_block,
  .p_cfg         =&I2C0_configuration,
  .p_api         =&g_i2c_master_on_riic
};

//........................................................................................
//  Организация шины для коммуникации со многими дивайсами на шине I2C2
//........................................................................................

static TX_MUTEX                     i2c0_bus_mutex;
static TX_EVENT_FLAGS_GROUP         i2c0_bus_events;
static sf_i2c_instance_ctrl_t      *current_device_on_I2C0_bus_pointer;
static sf_i2c_instance_ctrl_t      *sf_curr_bus_ctrl_g_sf_i2c_bus0;

sf_i2c_bus_t I2C0_bus =
{
  .p_bus_name       = (uint8_t *)"I2C0_bus",
  .channel          = 0,
  .p_lock_mutex     = &i2c0_bus_mutex,
  .p_sync_eventflag = &i2c0_bus_events,
  .pp_curr_ctrl     = (sf_i2c_ctrl_t **)&current_device_on_I2C0_bus_pointer,
  .p_lower_lvl_api  = (i2c_api_master_t *)&g_i2c_master_on_riic,
  .device_count     = 0,
  .pp_curr_bus_ctrl = (sf_i2c_ctrl_t **)&sf_curr_bus_ctrl_g_sf_i2c_bus0,
};





