/**
 ******************************************************************************
 * @file    GPIO/IOToggle/main.c
 * @author  MCD Application Team
 * @version V3.5.0
 * @date    08-April-2011
 * @brief   Main program body.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stdio.h"

/** @addtogroup STM32F10x_StdPeriph_Examples
 * @{
 */

/** @addtogroup GPIO_IOToggle
 * @{
 */

void delay(vu32 i)
{
	while (i--)
		;
}

//串口1初始化
void packageUsart1()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO, ENABLE);

	/**********************引脚分配*****************************/
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_StructInit(&GPIO_InitStruct);

	// Initialize USART1_Tx 初始化发送
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	// Initialize USART1_RX 初始化接收
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	/**********************引脚分配*****************************/

	/**********************串口初始化****************************/
	USART_InitTypeDef USART_InitStructure;
	// Initialize USART structure
	USART_StructInit(&USART_InitStructure);
	// Modify USART_InitStructure for non - default values , e.g.
	// USART_InitStructure . USART_BaudRate = 38400;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_InitStructure);	//初始化所使用的串口外设
	USART_Cmd(USART1, ENABLE);	//使能或者失能USART外设
	/**********************串口初始化****************************/
}

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured,
	 this is done through SystemInit() function which is called from startup
	 file (startup_stm32f10x_xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32f10x.c file
	 */

	packageUsart1();

	/* GPIOD Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

	/* Configure PB0/1/10/11/12 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* To achieve GPIO toggling maximum frequency, the following  sequence is mandatory.
	 You can monitor PD0 or PD2 on the scope to measure the output signal.
	 If you need to fine tune this frequency, you can add more GPIO set/reset
	 cycles to minimize more the infinite loop timing.
	 This code needs to be compiled with high speed optimization option.  */
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i = 0;
	while (1)
	{
		/* Set PD0 and PD2 */
		GPIO_ResetBits(GPIOB, GPIO_Pin_0 );
		delay(0xffff);
		GPIO_SetBits(GPIOB, GPIO_Pin_0 );
		delay(0xffff);
		GPIO_ResetBits(GPIOB, GPIO_Pin_1 );

		delay(0xffff);
		GPIO_SetBits(GPIOB, GPIO_Pin_1 );
		delay(0xffff);

		GPIO_ResetBits(GPIOB, GPIO_Pin_10 );
		delay(0xffff);
		GPIO_SetBits(GPIOB, GPIO_Pin_10 );
		delay(0xffff);

		GPIO_ResetBits(GPIOB, GPIO_Pin_11 );
		delay(0xffff);
		GPIO_SetBits(GPIOB, GPIO_Pin_11 );
		delay(0xffff);

		GPIO_ResetBits(GPIOB, GPIO_Pin_12 );
		delay(0xffff);
		GPIO_SetBits(GPIOB, GPIO_Pin_12 );
		delay(0xffff);

		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE ) == RESET)
			;
		USART1 ->DR = 'a';

		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE ) == RESET)
			;
		USART1 ->DR = 'b';

		printf("OK-->%d\n\r", i++);
		///////////////////////////

	}
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
