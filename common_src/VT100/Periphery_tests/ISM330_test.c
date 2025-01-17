﻿// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2023-01-27
// 11:47:55
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"


/*-----------------------------------------------------------------------------------------------------


  \param void
-----------------------------------------------------------------------------------------------------*/
static void _Print_ISM330_test_header(void)
{
  GET_MCBL;
  MPRINTF(VT100_CLEAR_AND_HOME);
  MPRINTF(" ===  ISM330 test ===\n\r");
  MPRINTF("ESC - exit, [E] - edit register (format: <HEX_ADDR> <HEX_VAL>), \n\r");
  MPRINTF("----------------------------------------------------------------------\n\r");
}

/*-----------------------------------------------------------------------------------------------------


  \param start_row
  \param last_row
-----------------------------------------------------------------------------------------------------*/
static void _Print_ISM330_registers(uint32_t start_row, uint32_t last_row)
{
  GET_MCBL;
  uint32_t row;
  uint32_t col;
  T_ISM330_reg_descr const *rds;
  uint8_t  b;
  char     str[64];

  row = start_row;
  col = 1;

  for (uint32_t i = 0; i < ISM330_reg_count(); i++)
  {
    rds = ISM330_get_reg_descr(i);
    ISM330_read_register(rds->reg_addr,rds->reg_val);

    b = *rds->reg_val;
    Get_8bit_str(str, b);

    if (((i % (last_row - start_row + 1)) == 0) && (i != 0))
    {
      row = start_row;
      col += 60;
    }
    MPRINTF(VT100_CURSOR_SET,row,col);
    MPRINTF("[0x%02X] %s = 0x%02X (%s),",rds->reg_addr, rds->reg_name, b, str);
    MPRINTF("\n\r");
    row++;
  }

}

/*-----------------------------------------------------------------------------------------------------


  \param void

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
static uint32_t _ISM330_check_chip_id(void)
{
  uint8_t   b;

  GET_MCBL;

  if (ISM330_read_register(ISM330_WHO_AM_I,&b) != SSP_SUCCESS)
  {
    MPRINTF("Read ISM330_WHO_AM_I error.\n\r");
    goto EXIT_ON_ERROR;
  }

  MPRINTF("ISM330 CHIP ID = %02X. ", b);

  if (b == ISM330_CHIP_ID)
  {
    MPRINTF(" Correct!\n\r");
  }
  else
  {
    MPRINTF(" Incorrect!\n\r");
  }
  return RES_OK;

EXIT_ON_ERROR:


  return RES_ERROR;

}

/*-----------------------------------------------------------------------------------------------------


  \param keycode
-----------------------------------------------------------------------------------------------------*/
void Do_ISM330_test(uint8_t keycode)
{
  GET_MCBL;
  char                str[16];
  uint8_t             b;


  MPRINTF(VT100_CLEAR_AND_HOME);
  if (ISM330_open() != SSP_SUCCESS)
  {
    MPRINTF("Connection to ISM330 error.\n\r");
    return;
  }

  _ISM330_check_chip_id();
  Wait_ms(1000);

  _Print_ISM330_test_header();

  do
  {
    if (WAIT_CHAR(&b,  ms_to_ticks(500)) == RES_OK)
    {
      if (b > 0)
      {
        switch (b)
        {
        case 'E':
        case 'e':
          if (VT100_edit_string_in_pos(str, sizeof(str), 36, 0) == RES_OK)
          {
            uint32_t reg_addr;
            uint32_t reg_val;
            if (sscanf(str, "%X %X",&reg_addr,&reg_val) == 2)
            {
              uint8_t buf[2];
              buf[1] = (uint8_t)reg_val;
              if (ISM330_write_buf(reg_addr,buf, 1) != SSP_SUCCESS)
              {
                MPRINTF("\n\r Write error!");
                Wait_ms(1000);
              }
            }
            else
            {
              MPRINTF("\n\r String error!");
              Wait_ms(1000);
            }
          }
          MPRINTF(VT100_CURSOR_SET,36,1);
          MPRINTF(VT100_CLR_FM_CRSR);
          _Print_ISM330_registers(4, 34);
          break;

        case VT100_ESC:
          ISM330_close();
          return;

        default:
          _Print_ISM330_test_header();
          break;
        }
      }
    }
    else
    {
      _Print_ISM330_registers(4, 34);
    }
  } while (1);
}


