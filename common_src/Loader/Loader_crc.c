#include "App.h"

uint32_t crc_table[256];

/*-----------------------------------------------------------------------------------------------------
  Name  : CRC-32
  Poly  : 0x04C11DB7    x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1
  Init  : 0xFFFFFFFF
  Revert: true
  XorOut: 0xFFFFFFFF
  Check : 0xCBF43926 ("123456789")
  MaxLen: 268 435 455 Byte
-----------------------------------------------------------------------------------------------------*/
void Generate_CRC32_table(void)
{
  uint32_t crc;
  uint32_t i, j;

  for (i = 0; i < 256; i++)
  {
    crc = i;
    for (j = 0; j < 8; j++)
    {
      crc = crc & 1 ?(crc >> 1)^ 0xEDB88320UL : crc >> 1;
    }
    crc_table[i] = crc;
  };
}


/*-----------------------------------------------------------------------------------------------------


  \param buf
  \param len

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
uint32_t Get_CRC32(unsigned char *buf, uint32_t len)
{
  uint32_t crc;

  crc = 0xFFFFFFFFUL;

  while (len--) crc = crc_table[(crc ^*buf++) & 0xFF] ^(crc >> 8);

  return crc ^ 0xFFFFFFFFUL;
}

/*-----------------------------------------------------------------------------------------------------


  \param void

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
void Get_Init_CRC32(uint32_t *p_crc)
{
  *p_crc =  0xFFFFFFFFUL;
}

/*-----------------------------------------------------------------------------------------------------


  \param buf
  \param len

  \return uint32_t
-----------------------------------------------------------------------------------------------------*/
void Update_CRC32(uint32_t *p_crc, uint8_t *buf, uint32_t len)
{
  while (len--) *p_crc = crc_table[(*p_crc ^*buf++) & 0xFF] ^(*p_crc >> 8);
}

/*-----------------------------------------------------------------------------------------------------


  \param p_crc
-----------------------------------------------------------------------------------------------------*/
void Get_finish_CRC32(uint32_t *p_crc)
{
  *p_crc =*p_crc ^ 0xFFFFFFFFUL;
}
