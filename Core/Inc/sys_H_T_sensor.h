/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H
#define __I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
/* include  i2c header */
  
 /* define */
//#define SI7006_ADR	     128   //0x80	//0x40<<1  0100 0000 <<1  ==> 0x80 1000 0000- DEC 128
#define SI7006_ADR	     128   //0x80	//0x40<<1  0100 0000 <<1  ==> 0x80 1000 0000- DEC 128
#define Humidity_Hold_Master_Mode       0xE5    // Measure Relative Humidity, Hold Master Mode
#define Temperature_Master_Mode        0xE3    //Measure Temperature, Hold Master Mode
 
void I2C1_Init();
void init_SI7006();

/**end ysh**/

#ifdef __cplusplus
}
#endif

#endif /* __I2C_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
