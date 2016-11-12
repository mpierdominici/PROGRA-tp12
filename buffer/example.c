

#include <stdio.h>
#include "buffer.h"

int main (void)
{
	M_C_BUFFER example;

	example.size=6;//le asigno tamaño al buffer
	char counter;
	create_c_buffer(&example);//inicializo el buffer circular
	for (counter=0;counter<3;counter++)
	push_c_buffer(&example,('A'+counter));
	for (counter=0;counter<2;counter++)
	printf("%c\n",pull_c_buffer(&example));
	
	for (counter=0;counter<3;counter++)
	push_c_buffer(&example,('1'+counter));
	for (counter=0;counter<4;counter++)
	printf("%c\n",pull_c_buffer(&example));

	destroy_c_buffer(&example);//elimino el buffer circular
	return 0;
}