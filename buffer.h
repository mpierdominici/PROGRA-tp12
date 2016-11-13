#ifndef BUFFER_H
#define BUFFER_H
#include <stdint.h>

#include <stdio.h>


typedef struct { //estructura del buffer circular

	uint16_t size;
	uint16_t push;
	uint16_t pull;
	int16_t counter;
	uint8_t * buff;



}M_C_BUFFER;

void create_c_buffer(M_C_BUFFER * a);//crea el buffer. NOTA:primero deve asignarsele tamaño al  buffer
int16_t status_c_buffer(M_C_BUFFER * a);//indica cuantos elementos se cargaron(sin leer) en el buffer, si hubo overflow, devuelve -1
void push_c_buffer(M_C_BUFFER * a,uint8_t caracter);//ingresa caracteres al buffer, cuando esta lleno no se almacena mas informacion
uint8_t pull_c_buffer(M_C_BUFFER * a);//obtiene lo ingresado al buffer, si nada se ingreso devuelve 0
void destroy_c_buffer(M_C_BUFFER * a);//destruye el buffer
void setsize_c_buffer(M_C_BUFFER * a,uint8_t tamanio);//setea el tamaño del buffer
#endif// end of BUFFE_H
