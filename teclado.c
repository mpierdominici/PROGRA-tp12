/************************************************************/
/*  Trabajo Practico N°12                                   */
/*                                                          */
/*                                                          */
/*Integrantes del grupo:                                    */
/*Maspero Martina(57120),Pierdominici Matias(57498),        */
/*Ayouba Gael(58622)                                        */
/* mpierdominici@itba.edu.ar                                */
/************************************************************/

//repository:  https://github.com/mpierdominici/PROGRA-tp12.git

/*manejo de teclado que guarda eventos en buffer circular*/

#include "nonblock.h"
#include <stdlib.h>

#include "teclado.h"

#ifdef _WIN32
   #error "This program is only targeted at Linux systems"
#endif

#define	ERROR   -1
#define TRUE 1
#define FALSE 0

static uint8_t un_carcater=FALSE;
static M_C_BUFFER * teclado_eventos=NULL;
static uint8_t stop =TRUE;
void * start_teclado(void * a)
{

int result =ERROR;		
uint8_t caracter =FALSE;
stop =TRUE;
	
	while (stop)
	{



		nonblock(NB_ENABLE);

		if(kbhit()!=FALSE)
		{
				
			un_carcater=TRUE;
			caracter=getchar();
		
			
	
		}

		else if((kbhit()==FALSE)&&(un_carcater==TRUE))
		{
			//printf("%c\n",caracter );
			push_c_buffer(teclado_eventos,caracter);
			un_carcater=FALSE;
		}


		nonblock(NB_DISABLE);
	
	


	}

}



void set_buffer_teclado(M_C_BUFFER * a)
{
	teclado_eventos=a;
}

void stop_teclado(void)
{
	stop =FALSE;
}