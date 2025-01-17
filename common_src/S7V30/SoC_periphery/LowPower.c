// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2021-03-29
// 15:09:23 
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"



const cgc_clocks_cfg_t g_cgc_cfg_240Mhz =
{
  .system_clock           = CGC_CLOCK_PLL,
  .pll_cfg                = {
    .source_clock = CGC_CLOCK_MAIN_OSC,
    .divider      = CGC_PLL_DIV_2,
    .multiplier   = (float)(20.0),
  },
  .sys_cfg                = {
    .pclka_div    = CGC_SYS_CLOCK_DIV_2,
    .pclkb_div    = CGC_SYS_CLOCK_DIV_4,
    .pclkc_div    = CGC_SYS_CLOCK_DIV_4,
    .pclkd_div    = CGC_SYS_CLOCK_DIV_2,
    .bclk_div     = CGC_SYS_CLOCK_DIV_2,
    .fclk_div     = CGC_SYS_CLOCK_DIV_4,
    .iclk_div     = CGC_SYS_CLOCK_DIV_1,
  },
  .loco_state             = CGC_CLOCK_CHANGE_NONE,
  .moco_state             = CGC_CLOCK_CHANGE_NONE,
  .hoco_state             = CGC_CLOCK_CHANGE_NONE,
  .subosc_state           = CGC_CLOCK_CHANGE_NONE,
  .mainosc_state          = CGC_CLOCK_CHANGE_START,
  .pll_state              = CGC_CLOCK_CHANGE_START,

};
const cgc_clocks_cfg_t g_cgc_cfg_24Mhz =
{
  .system_clock           = CGC_CLOCK_MAIN_OSC,
  .pll_cfg                = {
    .source_clock = CGC_CLOCK_MAIN_OSC,
    .divider      = CGC_PLL_DIV_2,
    .multiplier   = (float)(20.0),
  },
  .sys_cfg                = {
    .pclka_div    = CGC_SYS_CLOCK_DIV_1,
    .pclkb_div    = CGC_SYS_CLOCK_DIV_1,
    .pclkc_div    = CGC_SYS_CLOCK_DIV_1,
    .pclkd_div    = CGC_SYS_CLOCK_DIV_1,
    .bclk_div     = CGC_SYS_CLOCK_DIV_1,
    .fclk_div     = CGC_SYS_CLOCK_DIV_4,
    .iclk_div     = CGC_SYS_CLOCK_DIV_1,
  },
  .loco_state             = CGC_CLOCK_CHANGE_NONE,
  .moco_state             = CGC_CLOCK_CHANGE_NONE,
  .hoco_state             = CGC_CLOCK_CHANGE_NONE,
  .subosc_state           = CGC_CLOCK_CHANGE_NONE,
  .mainosc_state          = CGC_CLOCK_CHANGE_NONE,
  .pll_state              = CGC_CLOCK_CHANGE_STOP,

};


const lpmv2_mcu_cfg_t g_lpmv2_standby0_mcu_cfg =
{
  .standby_wake_sources       = (lpmv2_standby_wake_source_bits_t)0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0,
  .snooze_request_source      =  LPMV2_SNOOZE_REQUEST_RXD0_FALLING,
  .snooze_end_sources         = (lpmv2_snooze_end_bits_t)0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0 |
  0,
  .dtc_state_in_snooze        =  LPMV2_SNOOZE_DTC_DISABLE,
  .output_port_enable         =  LPMV2_OUTPUT_PORT_ENABLE_RETAIN,
  .io_port_state              =  LPMV2_IO_PORT_NO_CHANGE,
  .power_supply_state         =  LPMV2_POWER_SUPPLY_DEEPCUT0,
  .deep_standby_cancel_source = (lpmv2_deep_standby_cancel_source_bits_t)LPMV2_DEEP_STANDBY_CANCEL_SOURCE_RESET_ONLY,
  .deep_standby_cancel_edge   = (lpmv2_deep_standby_cancel_edge_bits_t)LPMV2_DEEP_STANDBY_CANCEL_SOURCE_EDGE_NONE,
  .snooze_cancel_sources      = LPMV2_SNOOZE_CANCEL_SOURCE_SCI0_RXI_OR_ERI,
};
const lpmv2_cfg_t g_lpmv2_standby0_cfg =
{
  .low_power_mode     = LPMV2_LOW_POWER_MODE_STANDBY,
  .p_extend           =&g_lpmv2_standby0_mcu_cfg,
};
const lpmv2_instance_t g_lpmv2_standby0 =
{
  .p_api =&g_lpmv2_on_lpmv2,
  .p_cfg =&g_lpmv2_standby0_cfg
};



const lpmv2_cfg_t g_lpmv2_sleep0_cfg =
{
  .low_power_mode     = LPMV2_LOW_POWER_MODE_SLEEP,
  .p_extend           = NULL,
};
const lpmv2_instance_t g_lpmv2_sleep0 =
{
  .p_api =&g_lpmv2_on_lpmv2,
  .p_cfg =&g_lpmv2_sleep0_cfg
};

sf_power_profiles_v2_ctrl_t g_sf_power_profiles_v2_common_ctrl;

sf_power_profiles_v2_cfg_t g_sf_power_profiles_v2_common_cfg =
{
  .p_extend = NULL,
};

sf_power_profiles_v2_instance_t g_sf_power_profiles_v2_common =
{
  .p_ctrl =&g_sf_power_profiles_v2_common_ctrl,
  .p_cfg =&g_sf_power_profiles_v2_common_cfg,
  .p_api =&g_sf_power_profiles_v2_on_sf_power_profiles_v2,
};


#if POWER_PROFILES_V2_CALLBACK_USED_g_sf_power_profiles_Standby
void NULL(sf_power_profiles_v2_callback_args_t *p_args);
#endif

sf_power_profiles_v2_low_power_cfg_t g_sf_power_profiles_Standby =
{
#if POWER_PROFILES_V2_EXIT_PIN_CFG_TBL_USED_g_sf_power_profiles_Standby
  .p_ioport_pin_tbl_exit      =&NULL,
#else
  .p_ioport_pin_tbl_exit      = NULL,
#endif
#if POWER_PROFILES_V2_ENTER_PIN_CFG_TBL_USED_g_sf_power_profiles_Standby
  .p_ioport_pin_tbl_enter     =&NULL,
#else
  .p_ioport_pin_tbl_enter     = NULL,
#endif
  .p_lower_lvl_lpm            =&g_lpmv2_standby0,
  .p_callback                 = NULL,
  .p_context                  =&g_sf_power_profiles_Standby,
  .p_extend                   = NULL,
};


#if POWER_PROFILES_V2_CALLBACK_USED_g_sf_power_profiles_Sleep
void NULL(sf_power_profiles_v2_callback_args_t *p_args);
#endif
sf_power_profiles_v2_low_power_cfg_t g_sf_power_profiles_Sleep =
{
#if POWER_PROFILES_V2_EXIT_PIN_CFG_TBL_USED_g_sf_power_profiles_Sleep
  .p_ioport_pin_tbl_exit      =&NULL,
#else
  .p_ioport_pin_tbl_exit      = NULL,
#endif
#if POWER_PROFILES_V2_ENTER_PIN_CFG_TBL_USED_g_sf_power_profiles_Sleep
  .p_ioport_pin_tbl_enter     =&NULL,
#else
  .p_ioport_pin_tbl_enter     = NULL,
#endif
  .p_lower_lvl_lpm            =&g_lpmv2_sleep0,
  .p_callback                 = NULL,
  .p_context                  =&g_sf_power_profiles_Sleep,
  .p_extend                   = NULL,
};

#if POWER_PROFILES_V2_CALLBACK_USED_g_sf_power_profiles_Deep_Standby
void NULL(sf_power_profiles_v2_callback_args_t *p_args);
#endif

/*-----------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------*/
void sf_power_profiles_v2_init0(void)
{
  ssp_err_t err;
  err = g_sf_power_profiles_v2_common.p_api->open(g_sf_power_profiles_v2_common.p_ctrl, g_sf_power_profiles_v2_common.p_cfg);
  if (SSP_SUCCESS != err)
  {
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);
  }
}


