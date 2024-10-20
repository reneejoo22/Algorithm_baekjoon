#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char bin[1000000]; 

int main()
{
	int len;
	int r; 
	int oct = 0;

	scanf("%s", bin);
	len = strlen(bin);
	r = len % 3;

	if (r == 1)
	{
		oct += (bin[0] - 48) * 1;
		printf("%d", oct);
	}
	else if (r == 2)
	{
		oct += (bin[0] - 48) * 2;
		oct += (bin[1] - 48) * 1;
		printf("%d", oct);
	}
	
	for (int i = r; i < len; i += 3)
	{
		oct = 0;

		oct += (bin[i] - 48) * 4;
		oct += (bin[i+1] - 48) * 2;
		oct += (bin[i+2] - 48) * 1;
		printf("%d", oct);
	}
	return 0;
}