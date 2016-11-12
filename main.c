#include <stdio.h>
#include <pthread.h>
#include "buffer.h"
#include "teclado.h"
#include <time.h>
#define TAMANIO_BUFFER 10
int main (void)

{
	pthread_t t1;
	M_C_BUFFER eventos_teclado;
	setsize_c_buffer(&eventos_teclado,TAMANIO_BUFFER);
	create_c_buffer(&eventos_teclado);
	set_buffer_teclado(&eventos_teclado);
	pthread_create(&t1,NULL,start_teclado,NULL);

	while(1)
	{
		
		if (status_c_buffer(&eventos_teclado)==-1)
		{

			while(status_c_buffer(&eventos_teclado))
			{	
				
				printf("%c",pull_c_buffer(&eventos_teclado) );
				
			}
			
		}

	}



	destroy_c_buffer(&eventos_teclado);
	return 0;
}