/* Includes ------------------------------------------------------------------*/
#include "sys_H_T_sensor.h"
/* USER CODE BEGIN 0 */
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern UART_HandleTypeDef huart2;
uint8_t TM_SensorData[2];

uint8_t char_buf[50]; 
float Humidity = 0;
float Temperature = 0;
uint8_t MODE = 0;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure i2c                                                           */
/*----------------------------------------------------------------------------*/

void I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

void init_SI7006()
{
 
  MODE= 0xE5;
  
  if(HAL_I2C_Master_Transmit(&hi2c1, SI7006_ADR, &MODE, 1, 1000) == HAL_OK)
  {
    // printf("SI7006 ok\r\n");
  }
  else
    printf("SI7006 fail\r\n");

  if(HAL_I2C_Master_Receive(&hi2c1, SI7006_ADR|0x01, TM_SensorData, 2, 1000) == HAL_OK)
  {
		uint16_t temp = (uint16_t)TM_SensorData[0] << 8;
		temp = (temp | TM_SensorData[1]);
		Humidity =  100 * ((float)temp / 65535.0f);
              // printf("I2C Rx ok\r\n");
                sprintf((char*)char_buf,"H= %2.2f \r\n", Humidity);
                printf("H= %2.2f \r\n", Humidity);
                HAL_UART_Transmit(&huart2,char_buf,sizeof(char_buf),1000);
                
  }
  HAL_Delay(50);
 
}
