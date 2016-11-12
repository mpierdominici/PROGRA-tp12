#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_FALSE 0
#define BUFFER_TRUE 1
#define BUFFER_ERROR -1


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
				((*a).counter)++;
				((*a).push)++;//aumento el contador que agrega
				if(((*a).push)>(((*a).size)-1))//evaluo si llegue al final del arreglo lineal
				{
					((*a).push)=BUFFER_FALSE;//reinicio push
				}

			}
		}
	}








