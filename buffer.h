#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>





typedef struct { //estructura del buffer circular

	uint16_t size;
	uint16_t push;
	uint16_t pull;
	int16_t counter;
	uint8_t * buff;



}M_C_BUFFER;

void create_c_buffer(M_C_BUFFER * a);
int16_t status_c_buffer(M_C_BUFFER * a);
void push_c_buffer(M_C_BUFFER * a,uint8_t caracter);
uint8_t pull_c_buffer(M_C_BUFFER * a);
void destroy_c_buffer(M_C_BUFFER * a);
void setsize_c_buffer(M_C_BUFFER * a,uint8_t tamaño);
#endif// end of BUFFE_H
