/************************************************************/
/*  Trabajo Practico N°12                                   */
/*                                                          */
/*                                                          */
/*Integrantes del grupo:                                    */
/*Maspero Martina(57120),Pierdominici Matias(57498),        */
/*Ayouba Gael(58622)                                        */
/*                                                          */
/************************************************************/

//repository: https://github.com/mpierdominici/PROGRA-tp12.git

/*este programa utiliza un buffer cirular para almacenar los eventos del teclado,
y los imprimie cuando se lleno el buffer*/

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
	M_C_BUFFER eventos_teclado;//creo el buffer circular
	setsize_c_buffer(&eventos_teclado,TAMANIO_BUFFER);//seteo el tamaño del teclado
	set_buffer_teclado(&eventos_teclado);//inidico que se guarden los eventos del teclado en el buffer indicado
	pthread_create(&t1,NULL,start_teclado,NULL);//inicializo el teclado

	while(exit)//se ejecuta hasta que se presione ESC
	{
		
		if (status_c_buffer(&eventos_teclado)==-1)
		{
			printf("\n");
			while(status_c_buffer(&eventos_teclado))//cuando se llena el buffer, se imprime lo que se ingreso por teclado
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


	stop_teclado();//detengo el teclado
	destroy_c_buffer(&eventos_teclado);//detruyo el buffer
	
}