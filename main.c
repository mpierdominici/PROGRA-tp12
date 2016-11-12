#include <stdio.h>
#include <pthread.h>
#include "buffer.h"
#include "teclado.h"
#include <time.h>
#define TAMANIO_BUFFER 10
#define ESC 0X1b
int main (void)

{
	pthread_t t1;
	uint8_t carac;
	uint8_t exit=1;
	M_C_BUFFER eventos_teclado;
	setsize_c_buffer(&eventos_teclado,TAMANIO_BUFFER);
	create_c_buffer(&eventos_teclado);
	set_buffer_teclado(&eventos_teclado);
	pthread_create(&t1,NULL,start_teclado,NULL);

	while(exit)
	{
		
		if (status_c_buffer(&eventos_teclado)==-1)
		{
			printf("\n");
			while(status_c_buffer(&eventos_teclado))
			{	
				carac=pull_c_buffer(&eventos_teclado);
				if (carac==ESC)
				{
					exit=0;
					carac=0;
				}
				printf("%c",carac);
				
			}
			printf("\n");
		}

	}


	stop_teclado();
	destroy_c_buffer(&eventos_teclado);
	return 0;
}