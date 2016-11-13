/************************************************************/
/*  Trabajo Practico N°12                                   */
/*                                                          */
/*                                                          */
/*Integrantes del grupo:                                    */
/*Maspero Martina(57120),Pierdominici Matias(57498),        */
/*Ayouba Gael(58622)                                        */
/* mpierdominici@itba.edu.ar                                */
/************************************************************/

//repository: https://github.com/mpierdominici/PROGRA-tp12.git

/*implementacion de buffer circular, cuando este se llena deja de almacenar informacion
pero avisa esto mediante status_c_buffer*/
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_FALSE 0
#define BUFFER_TRUE 1
#define BUFFER_ERROR -1
#define DEFAULT_SIZE 10 //en caso que no se defina el size, por defecto sera 10

void setsize_c_buffer(M_C_BUFFER * a,uint8_t tamanio)
{
	(*a).size=tamanio;
}

void create_c_buffer(M_C_BUFFER * a)//esta funcion creara el buffer en el heap, y modificara la estructura,
	{									//almacenando en el puntero correspondiente donde comienza el buffer.
		

		(*a).buff=(uint8_t *) calloc((*a).size,sizeof(uint8_t));
		((*a).counter)=BUFFER_FALSE;
		((*a).push)=BUFFER_FALSE;
		((*a).pull)=BUFFER_FALSE;

	}

int16_t status_c_buffer(M_C_BUFFER * a) //devuelve la cantidad de elementos ingresados, y si se 
{										//llena y no se vacia devuelve un -1
	return ((*a).counter);
}

void push_c_buffer(M_C_BUFFER * a,uint8_t caracter) //ingresa un caracter haste que el buffer se llena
	{
		if(status_c_buffer(a)!=BUFFER_ERROR)
		{
			if((status_c_buffer(a)+1)>((*a).size))
			{
				((*a).counter)=BUFFER_ERROR;
			}
			else
			{	
				((*a).buff)[((*a).push)]=caracter;
				//printf("%c\n",((*a).buff)[((*a).push)]);
				((*a).counter)++;
				((*a).push)++;//aumento el contador que agrega
				if(((*a).push)>(((*a).size)-1))//evaluo si llegue al final del arreglo lineal
				{
					((*a).push)=BUFFER_FALSE;//reinicio push
				}

			}
		}
	}


uint8_t pull_c_buffer(M_C_BUFFER * a)//vacia el buffer circular, si estuviese vacio devuelve 0,
{
	uint8_t caracter=BUFFER_FALSE;
	
	if (((*a).counter)!=BUFFER_FALSE)//evaluo si no esta vacio el buffer
	{

		if(((*a).counter)==BUFFER_ERROR)//si hubo overflow del buffer entonces seteo el contador 
		{								//con el tamaño de elementos del buffer(size)
			((*a).counter)=((*a).size);
		}

		caracter=((*a).buff)[((*a).pull)];
		//printf("%c\n",caracter);
		((*a).counter)--;
		((*a).pull)++;//aumento el contador que lee
		if(((*a).pull)>(((*a).size)-1))//evaluo si llegue al final del arreglo lineal
		{
			((*a).pull)=BUFFER_FALSE;//reinicio pull
		}


	}

	return caracter;
}

void destroy_c_buffer(M_C_BUFFER * a)//vacia el espacio de mamoria reservado para el buffer
{
	free(((*a).buff));
}





