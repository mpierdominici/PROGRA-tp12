#include "nonblock.h"
#include <stdlib.h>
#include <stdint.h>
#include "teclado.h"

#ifdef _WIN32
   #error "This program is only targeted at Linux systems"
#endif

#define	ERROR   -1
#define TRUE 1
#define FALSE 0

static uint8_t un_carcater=FALSE;

void teclado_nb(void)
{

int result =ERROR;		
uint8_t caracter =0;

	while (TRUE)
	{



		nonblock(NB_ENABLE);

		if(kbhit()!=FALSE)
		{
				
			un_carcater=TRUE;
			caracter=getchar();
		
			
	
		}

		else if((kbhit()==FALSE)&&(un_carcater==TRUE))
		{
			//aca va la funcion que guarda en el buffer
			un_carcater=FALSE;
		}


		nonblock(NB_DISABLE);
	
	


	}

}
