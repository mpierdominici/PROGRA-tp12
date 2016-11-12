#ifndef _TECLADO_H
#define _TECLADO_H
#define	ERROR   -1

#include <stdint.h>
#include "buffer.h"
void * start_teclado(void * a);
void set_buffer_teclado(M_C_BUFFER * a);
void stop_teclado(void);

#endif
