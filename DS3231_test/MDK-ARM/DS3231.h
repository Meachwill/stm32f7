#ifndef DS3231_H
#define DS3231_H

#include <inttypes.h>

//DS3231 slave address
#define DS3231_SLA 0x68

//data transmit
#define SEC_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define MIN_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define HOUR_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define WDAY_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define DATE_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define MON_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))
#define YEAR_BIT_TRM_SET(data)		((((data)/10)<<4)+((data)%10))

//data receive
#define SEC_BIT_TRM_GET(data) 	(((data>>4)*10)+(data & 0x0f))
#define MIN_BIT_TRM_GET(data) 	(((data>>4)*10)+(data & 0x0f))
#define HOUR_BIT_TRM_GET(data)	(((data>>4)*10)+(data & 0x0f))
#define WDAY_BIT_TRM_GET(data)	(((data>>4)*10)+(data & 0x0f))
#define DATE_BIT_TRM_GET(data)	(((data>>4)*10)+(data & 0x0f))
#define MON_BIT_TRM_GET(data)		(((data>>4)*10)+(data & 0x0f))
#define YEAR_BIT_TRM_GET(data)	(((data>>4)*10)+(data & 0x0f))


// DS3231 Registers
#define DS3231_TIME_SEC_ADDR		0x00
#define DS3231_TIME_MIN_ADDR		0x01
#define DS3231_TIME_HOUR_ADDR		0x02
#define DS3231_TIME_WDAY_ADDR		0x03
#define DS3231_TIME_DATE_ADDR		0x04
#define DS3231_TIME_MON_ADDR		0x05
#define DS3231_TIME_YEAR_ADDR		0x06

#define DS3231_ALARM1_ADDR          0x07
#define DS3231_ALARM2_ADDR          0x0B
#define DS3231_CONTROL_ADDR         0x0E
#define DS3231_STATUS_ADDR          0x0F
#define DS3231_AGING_OFFSET_ADDR    0x10
#define DS3231_TEMPERATURE_ADDR     0x11

//control register bits
#define DS3231_CONTROL_A1IE     0x1		/* Alarm 2 Interrupt Enable */
#define DS3231_CONTROL_A2IE     0x2		/* Alarm 2 Interrupt Enable */
#define DS3231_CONTROL_INTCN    0x4		/* Interrupt Control */
#define DS3231_CONTROL_RS1	    0x8		/* square-wave rate select 1 */
#define DS3231_CONTROL_RS2    	0x10	/* square-wave rate select 2 */
#define DS3231_CONTROL_CONV    	0x20	/* Convert Temperature */
#define DS3231_CONTROL_BBSQW    0x40	/* Battery-Backed Square-Wave Enable */
#define DS3231_CONTROL_EOSC	    0x80	/* not Enable Oscillator, 0 equal on */



typedef struct {
    uint8_t sec;         
    uint8_t min;
    uint8_t hour;
		uint8_t wday;
    uint8_t day;
    uint8_t mon;
    int16_t year;
}rtl;



#endif
