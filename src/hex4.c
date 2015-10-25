#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _nibstor 
{
	uint8_t hi : 4;
	uint8_t lo : 4;	
} nibstor;

int main(int argc, char **argv)
{
	FILE *hexfile = NULL;
	long fsize = 0;
	nibstor *nibbles = NULL;
	long nibblenum = 0;
	int byte = 0;
	char hilo = -1;
	int i = 0;
	int j = 0;
	int inststart = 0;

	if(argc < 2)
	{
		return 0;
	}

	hexfile = fopen(argv[1], "rb");
	if(hexfile == NULL)
	{
		perror("Could not open hexfile");
		return 1;
	}
	
	fseek(hexfile, 0, SEEK_END);
	fsize = ftell(hexfile);
	if(fsize == 0)
	{
		fprintf(stderr, "File size is zero!\n");
		return 2;
	}
	rewind(hexfile);

	nibbles = calloc(sizeof(nibstor), fsize + 1);
	if(nibbles == NULL)
	{
		perror("Could not allocate memory");
		return 3;
	}

	byte = fgetc(hexfile);
	hilo = 0;
	while(byte != EOF)
	{
		nibbles[i].hi = (char)((byte >> 4) & 0xF);
		nibbles[i].lo = (char)(byte & 0xF);
		i++;
		byte = fgetc(hexfile);
	}
	nibblenum = i;
	fclose(hexfile);
	printf("      ");
	for(i = 0; i < 5; i++)
	{
		printf("%X ", i);
	}
	puts("");
	printf("%04X: ", 0);
	for(i = 0; i < nibblenum; i++)
	{
		printf("%X ", nibbles[i].hi);
		j++;
		if((j % 5) == 0)
		{
		/*
			printf("   ");
			if(nibbles[i - 2].hi == 0x1)
			{
				printf("LOD");
			}
		*/
			puts("");
			printf("%04X: ", j);
		}
		printf("%X ", nibbles[i].lo);
		j++;
		if(((j % 5) == 0) && (i+1 != nibblenum))
		{
		/*
			printf("   ");
			if(nibbles[i - 2].lo == 0x2)
			{
				printf("STR");
			}
		*/
			puts("");
			printf("%04X: ", j);
		}
	}
	free(nibbles);
	return 0;
}
