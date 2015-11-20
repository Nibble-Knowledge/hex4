#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>

typedef struct _nibstor
{
	uint8_t hi : 4;
	uint8_t lo : 4;
} nibstor;

void printdisasm(unsigned char *inst);
int interactive(char *file);
