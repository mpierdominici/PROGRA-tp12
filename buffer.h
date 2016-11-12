#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>

typedef struct { //estructura del buffer circular

	int16_t size;
	uint16_t push;
	uint16_t pull;
	uint8_t * buff;



}M_C_BUFFER



#endif
