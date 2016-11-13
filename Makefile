
exe:main.c buffer.c nonblock.c teclado.c buffer.h nonblock.h teclado.h 
	gcc -o exe buffer.c main.c teclado.c nonblock.c -lpthread