#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

void SystemClock_Config(void);


int main(){
	
}


void SystemClock_Config(void){
	RCC_OscInitTypeDef Rcc_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	
	Rcc_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	Rcc_OscInitStruct.HSEState = RCC_HSE_ON;
	
}
