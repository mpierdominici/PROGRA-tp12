#ifndef _TECLADO_H
#define _TECLADO_H
#define	ERROR   -1

#include <stdint.h>
#include "buffer.h"
void * start_teclado(void * a);//se deve utilizar como pthread, inicia a tomar eventos del teclado. NOTA:primero se deve utilizar set_buffer_teclado
void set_buffer_teclado(M_C_BUFFER * a);//se setea dondes se guardaran los eventos
void stop_teclado(void);//se detiene la ejecuacion del teclado

#endif
