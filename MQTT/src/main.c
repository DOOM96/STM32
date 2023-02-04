/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.3.0   2023-02-03

The MIT License (MIT)
Copyright (c) 2019 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32f10x.h"

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{

	/*************************************************************
	 *
	 *                  TIMER2 SETUP
	 *
	 * ************************************************************/
	/*Enables the clock in the ADC1 and in the port C*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
	/*Enables the TIM2*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	/* Preload value to counter*/
	TIM2->ARR = 0X0FFF;
	/*the value to preescaler*/
	TIM2->PSC = 0X8FFF;
	/*Enables the interrupt when update occurs*/
	TIM2->DIER |= TIM_DIER_UIE;
	/*Enables interrupt to TIM2*/
	NVIC->ISER[0] = NVIC_ISER_SETENA_28;
	/*Enables counter*/
	TIM2->CR1 |= TIM_CR1_CEN;
	/*Pin13 PortC output pull down*/
	GPIOC->CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE14 | GPIO_CRH_MODE15;
	GPIOC->CRH |= GPIO_CRH_CNF13_0;

	/******************************************************
	 *
	 *                    UART1 Configuration
	 *
	 * *****************************************************/

	/*Enables USART1 clock and port A clock*/
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;

	/*Enables the input and output in the bit 9 on port A*/
	GPIOA->CRH |= GPIO_CRH_MODE9 | GPIO_CRH_CNF9_1;
	GPIOA->CRH &= ~(GPIO_CRH_CNF9_0);

	/*
	 * Enables UART = Set UE bit
	 * Transmit enable = Set TE bit
	 * Receive enable = Set RE bit
	 * Enables Receive interrupt = Set RXNEIE bit
	 * */
	USART1->CR1 |= USART_CR1_UE | USART_CR1_TE| USART_CR1_RE| USART_CR1_RXNEIE;

	/*Enables the global interruption to UART in NVIC*/
	NVIC->ISER[1] = NVIC_ISER_SETENA_5;

	/*Sets the baudrate in 9600 Baudios*/
	USART1->BRR = 0x1D4C;

	/******************************************************
	 *
	 *                    UART2 Configuration
	 *
	 * *****************************************************/

	/*Enables USART1 clock and port A clock*/
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN ;

	/*Enables the input and output in the bit 2 on port A*/
	GPIOA->CRL |= GPIO_CRL_MODE2 | GPIO_CRL_CNF2_1;
	GPIOA->CRL &= ~(GPIO_CRL_CNF2_0);

	/*
	 * Enables UART = Set UE bit
	 * Transmit enable = Set TE bit
	 * Receive enable = Set RE bit
	 * Enables Receive interrupt = Set RXNEIE bit
	 * */
	USART2->CR1 |= USART_CR1_UE | USART_CR1_TE| USART_CR1_RE| USART_CR1_RXNEIE;

	/*Enables the global interruption to UART in NVIC*/
	NVIC->ISER[1] = NVIC_ISER_SETENA_6;

	/*Sets the baudrate in 9600 Baudios*/
	USART2->BRR = 0xEA6;

//	/********************************************************
//	 *
//	 *               SPI Configuration
//	 *
//	 * ******************************************************/
//
//	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN ;
//
//	SPI1->CR1 |= SPI_CR1_BR;
//
//	SPI1->CR1 |= SPI_CR1_DFF;
//
//	SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI;
//
//	GPIOA->CRL &= ~(GPIO_CRL_CNF4_0 | GPIO_CRL_CNF5_0 | GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_0);
//	GPIOA->CRL |= GPIO_CRL_CNF7_1 | GPIO_CRL_CNF6_1 |GPIO_CRL_CNF5_1 | GPIO_CRL_MODE5 | GPIO_CRL_MODE6 | GPIO_CRL_MODE7 | GPIO_CRL_MODE4;
//
//	GPIOC->CRH &= ~(GPIO_CRH_CNF14_0 | GPIO_CRH_CNF15_0);
//
//	/*Enables the global interruption to SPI1 in NVIC*/
//	NVIC->ISER[1] = NVIC_ISER_SETENA_3;
//
//	//	SPI1->SR &= ~(SPI_SR_TXE);
//	SPI1->CR2 |= SPI_CR2_RXNEIE;
//
//	SPI1->CR1 |= SPI_CR1_MSTR | SPI_CR1_SPE;
//
//	SPI1->DR = 0;
//
//	GPIOC->BRR |= GPIO_BRR_BR15;



  /* TODO - Add your application code here */

  /* Infinite loop */
  while (1)
  {


  }
}


