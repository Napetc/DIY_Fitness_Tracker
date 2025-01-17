﻿#ifndef __PARAMS_IVAR_H
  #define __PARAMS_IVAR_H

#define  S7V30BOOT_0                    0
#define  S7V30BOOT_main                 1
#define  S7V30BOOT_General              2
#define  S7V30BOOT_USB_Interface        3
#define  S7V30BOOT_Network              4
#define  S7V30BOOT_MQTT                 5
#define  S7V30BOOT_FTP_server           6
#define  S7V30BOOT_SNTP                 7
#define  S7V30BOOT_WIFI_STA             8
#define  S7V30BOOT_WIFI_AP              9
#define  S7V30BOOT_Telnet               10
#define  S7V30BOOT_WIFI_STA1            11
#define  S7V30BOOT_WIFI_STA2            12
#define  S7V30BOOT_FreeMaster           13
#define  S7V30BOOT_Audio                14
#define  S7V30BOOT_WEB                  15
#define  S7V30BOOT_BLE                  16
#define  S7V30BOOT_Charger              17
#define  S7V30BOOT_IMU                  18

typedef struct
{
  uint8_t        accelerometer_scale;           // Accelerometer full-scale selection | def.val.= 0
  float          accum_nominal_capacity;        // Accumulator capacity, mAh | def.val.= 500
  uint8_t        ap_default_ip_addr[16+1];      // Default IP address | def.val.= 192.168.10.1
  uint8_t        ap_default_net_mask[16+1];     // Default network mask  | def.val.= 255.255.255.0
  uint8_t        ap_en_dhcp_server;             // Enable DHCP server | def.val.= 1
  uint32_t       audio_volume;                  // Volume (0...10) | def.val.= 8
  uint8_t        ble_device_name[32+1];         // Bluetooth LE device name | def.val.= BLE_S7V30
  uint8_t        bt_device_name[16+1];          // Bluetooth Classic device name | def.val.= BT_S7V30
  uint32_t       emb_charger_max_current;       // Max charging current, mAh | def.val.= 500
  uint8_t        en_ble;                        // Enable Bluetooth | def.val.= 1
  uint8_t        en_compress_settins;           // Enable compress settings file | def.val.= 1
  uint8_t        en_ecm_host_dhcp_client;       // Enable DHCP client on ECM host interface  | def.val.= 1
  uint8_t        en_embedded_charger;           // Enable embedded Li-Po charger | def.val.= 0
  uint8_t        en_engineering_log;            // Enable engineering log | def.val.= 0
  uint8_t        en_formated_settings;          // Enable formating in  settings file | def.val.= 1
  uint8_t        en_freemaster;                 // Enable FreeMaster protocol | def.val.= 0
  uint8_t        en_log_to_file;                // Enable logging to file | def.val.= 0
  uint8_t        en_log_to_freemaster;          // Enable logging to FreeMaster pipe | def.val.= 0
  uint8_t        en_net_log;                    // Enable log | def.val.= 1
  uint8_t        en_rndis_dhcp_server;          // Enable DHCP server on RNDIS interface  | def.val.= 1
  uint8_t        en_sntp;                       // Enable SNTP client | def.val.= 1
  uint8_t        en_sntp_time_receiving;        // Allow to receive time from time servers | def.val.= 1
  uint8_t        en_telnet;                     // Enable Telnet | def.val.= 1
  uint8_t        en_wifi_ap;                    // Enable Acces Point mode | def.val.= 1
  uint8_t        en_wifi_module;                // Enable  Wi-Fi Bluetooth module  | def.val.= 1
  uint8_t        enable_ftp_server;             // Enable FTP server | def.val.= 1
  uint8_t        enable_HTTP_server;            // Enable HTTP server | def.val.= 1
  uint8_t        enable_HTTPS;                  // Enable TLS | def.val.= 1
  uint8_t        ftp_serv_login[16+1];          // Login | def.val.= ftp_login
  uint8_t        ftp_serv_password[64+1];       // Password  | def.val.= ftp_pass
  uint8_t        gyroscope_scale;               // Gyroscope full-scale selection | def.val.= 0
  uint8_t        hardware_version[64+1];        // Hardware version | def.val.= S7V30V2 
  uint8_t        HTTP_server_password[32+1];    // HTTP server password | def.val.= 123456789
  uint32_t       imu_6d_threshold;              // Threshold for 4D/6D function | def.val.= 0
  uint32_t       imu_fifo_rd_period;            // Period of reading FIFO (ms) | def.val.= 50
  uint32_t       imu_free_fall_duration;        // Free fall duration duration (ms) | def.val.= 10
  uint32_t       imu_free_fall_threshold;       // Threshold for free-fall function | def.val.= 0
  uint32_t       imu_max_tap_time_gap;          // Maximum time gap for double tap recognition (ms) | def.val.= 200
  uint8_t        imu_output_data_rate;          // Output Data Rate selection | def.val.= 0
  uint32_t       imu_tap_quiet_time;            // Expected quiet time after a tap detection (ms) | def.val.= 50
  uint32_t       imu_tap_shock_window;          // Maximum duration of overthreshold event for tap(ms) | def.val.= 10
  uint8_t        imu_tap_threshold;             // Tap recognition threshold (0..31)  | def.val.= 1
  uint32_t       imu_wakeup_duration;           // Wake up duration (ms) | def.val.= 10
  uint8_t        imu_wakeup_threshold;          // Wake Up threshold (0..63) | def.val.= 1
  uint8_t        motion_logfile_name[32+1];     // Motion logfile name | def.val.= motion_log
  uint8_t        mqtt_client_id[16+1];          // Client ID | def.val.= Client1
  uint8_t        mqtt_enable;                   // Enable MQTT client  | def.val.= 0
  uint8_t        mqtt_password[16+1];           // User password | def.val.= pass
  uint8_t        mqtt_server_ip[16+1];          // MQTT server IP address | def.val.= 192.168.3.2
  uint32_t       mqtt_server_port;              // MQTT server port number | def.val.= 1883
  uint8_t        mqtt_user_name[16+1];          // User name | def.val.= user
  uint8_t        product_name[64+1];            // Product  name | def.val.= S7V30
  uint8_t        sd_card_password[17+1];        // SD card password | def.val.= 1234
  uint32_t       sntp_poll_interval;            // Poll interval (s) | def.val.= 10
  uint8_t        software_version[64+1];        // Software version | def.val.= S7V30
  uint8_t        this_host_name[16+1];          // This device host name | def.val.= S7V30
  uint8_t        time_server_1[64+1];           // Time server 1 URL | def.val.= pool.ntp.org
  uint8_t        time_server_2[64+1];           // Time server 2 URL | def.val.= 129.6.15.28
  uint8_t        time_server_3[64+1];           // Time serber 3 URL | def.val.= time.nist.gov
  uint8_t        usb_default_ip_addr[16+1];     // Default IP address | def.val.= 192.168.13.1
  uint8_t        usb_default_net_mask[16+1];    // Default network mask  | def.val.= 255.255.255.0
  uint32_t       usb_mode;                      // USB interface mode | def.val.= 1
  uint8_t        usd_dev_interface;             // USB device interface (HS/FS) | def.val.= 0
  float          utc_offset;                    // UTC offset (difference in hours +-) | def.val.= 3
  uint8_t        wifi_ap_channel;               // WIFI channell | def.val.= 1
  uint8_t        wifi_ap_key[32+1];             // Access Point password (>=8 symbols) | def.val.= 12345678
  uint8_t        wifi_ap_ssid[32+1];            // Access Point SSID | def.val.= S7V30
  uint8_t        wifi_sta_cfg1_default_gate_addr[16+1]; // Default gateway address | def.val.= 192.168.11.1
  uint8_t        wifi_sta_cfg1_default_ip_addr[16+1]; // Default IP address | def.val.= 192.168.11.1
  uint8_t        wifi_sta_cfg1_default_net_mask[16+1]; // Default network mask  | def.val.= 255.255.255.0
  uint8_t        wifi_sta_cfg1_en;              // Enable configuration | def.val.= 0
  uint8_t        wifi_sta_cfg1_en_dhcp;         // Enable DHCP client | def.val.= 1
  uint8_t        wifi_sta_cfg1_pass[32+1];      // Password  | def.val.= wifi_pass
  uint8_t        wifi_sta_cfg1_ssid[32+1];      // SSID | def.val.= wifi_login
  uint8_t        wifi_sta_cfg2_default_gate_addr[16+1]; // Default gateway address | def.val.= 192.168.12.1
  uint8_t        wifi_sta_cfg2_default_ip_addr[16+1]; // Default IP address | def.val.= 192.168.12.1
  uint8_t        wifi_sta_cfg2_default_net_mask[16+1]; // Default network mask  | def.val.= 255.255.255.0
  uint8_t        wifi_sta_cfg2_en;              // Enable configuration | def.val.= 0
  uint8_t        wifi_sta_cfg2_en_dhcp;         // Enable DHCP client | def.val.= 1
  uint8_t        wifi_sta_cfg2_pass[32+1];      // Password  | def.val.= wifi_pass
  uint8_t        wifi_sta_cfg2_ssid[32+1];      // SSID | def.val.= wifi_login
} IVAR_TYPE;



// Selector description:  Выбор между Yes и No
#define BINARY_NO                                 0
#define BINARY_YES                                1

// Selector description:  LED mode
#define LEDS_MODE_ALWAYS_OFF                      0
#define LEDS_MODE_NORMAL_WORK                     1

// Selector description:  USB mode
#define USB_MODE_NONE                             0
#define USB_MODE_VCOM_PORT                        1
#define USB_MODE_MASS_STORAGE_                    2
#define USB_MODE_VCOM_AND_MASS_STORAGE            3
#define USB_MODE_VCOM_AND_FREEMASTER_PORT         5
#define USB_MODE_RNDIS                            6
#define USB_MODE_HOST_ECM                         7
#define USB_MODE_VCOM_AND_VCOM                    4

// Selector description:  IP address assignment method
#define IP_ADDRESS_ASSIGNMENT_METHOD_STATIC_ADRESS  0
#define IP_ADDRESS_ASSIGNMENT_METHOD_DHCP_SERVER  1

// Selector description:  Выбор интерфейса для работы USB device
#define USB_DEV_INTERFACE_HIGH_SPEED_INTERFACE    0
#define USB_DEV_INTERFACE_FULL_SPEED_INTERFACE    1

// Selector description:  Accelerometer full-scale selection
#define ACCELEROMETER_SCALE_2G                    0
#define ACCELEROMETER_SCALE_4G                    1
#define ACCELEROMETER_SCALE_8G                    2
#define ACCELEROMETER_SCALE_16G                   3

// Selector description:  Gyroscope full-scale selection
#define GYROSCOPE_SCALE_250DPS                    0
#define GYROSCOPE_SCALE_500DPS                    1
#define GYROSCOPE_SCALE_1000DPS                   2
#define GYROSCOPE_SCALE_2000DPS                   3

// Selector description:  Output Data Rate
#define IMU_OUTPUT_DATA_RATE_1666HZ               0
#define IMU_OUTPUT_DATA_RATE_833HZ                1
#define IMU_OUTPUT_DATA_RATE_416HZ                2
#define IMU_OUTPUT_DATA_RATE_208HZ                3
#define IMU_OUTPUT_DATA_RATE_104HZ                4
#define IMU_OUTPUT_DATA_RATE_52                   5
#define IMU_OUTPUT_DATA_RATE_26                   6
#define IMU_OUTPUT_DATA_RATE_12_5                 7
#define IMU_OUTPUT_DATA_RATE_1_6                  8


extern IVAR_TYPE  ivar;
extern const T_NV_parameters_instance ivar_inst;

#endif


