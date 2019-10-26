#include "DS3231.h"
#include "stm32f7xx_hal.h"

extern I2C_HandleTypeDef hi2c4;

void DS3231_init(rtl *handle_rtl){
	
	uint8_t init_data[8] = {0};
	
	init_data[0] = DS3231_TIME_SEC_ADDR;
	init_data[1] = SEC_BIT_TRM_SET(handle_rtl->sec);
	init_data[2] = MIN_BIT_TRM_SET(handle_rtl->min);
	init_data[3] = HOUR_BIT_TRM_SET(handle_rtl->hour);
	init_data[4] = WDAY_BIT_TRM_SET(handle_rtl->wday);
	init_data[5] = DATE_BIT_TRM_SET(handle_rtl->day);
	init_data[6] = MON_BIT_TRM_SET(handle_rtl->mon);
	init_data[7] = YEAR_BIT_TRM_SET(handle_rtl->year);
	
	HAL_I2C_Master_Transmit(&hi2c4,DS3231_SLA<<1,init_data,8,5000);
	
}

void DS3231_get(rtl *handle_rtl){
	uint8_t read_data[7] = {0};
	uint8_t reg = DS3231_TIME_SEC_ADDR;
	
	HAL_I2C_Master_Transmit(&hi2c4,DS3231_SLA<<1,&reg,1,5000);
	HAL_I2C_Master_Receive(&hi2c4,(DS3231_SLA<<1)|1,read_data,7,5000);
	handle_rtl->sec = SEC_BIT_TRM_GET(read_data[0]);
	handle_rtl->min = MIN_BIT_TRM_GET(read_data[1]);
	handle_rtl->hour = HOUR_BIT_TRM_GET(read_data[2]);
	handle_rtl->wday = WDAY_BIT_TRM_GET(read_data[3]);
	handle_rtl->day = DATE_BIT_TRM_GET(read_data[4]);
	handle_rtl->mon = MON_BIT_TRM_GET(read_data[5]);
	handle_rtl->year = YEAR_BIT_TRM_GET(read_data[6]);
	
}
