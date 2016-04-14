#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n = atoi(*(argv+1));
	long seedvalue = atoi(*(argv+2));

	srand( time(&seedvalue));

	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	char **square = new char*[n];

	for(int i=0; i<n; i++)
	{
		square[i] = new char[n];
	}
	
	
	for(int i=0, j=0; i<n; j++)
	{
		j%n == i ? i++ : square[i][j-(n+1)*i] = 'a' + rand()% ('z'-'a');
	}

	return square;
}

void drawCharSquare(char **square, int n)
{
	
	for(int i=0, j=0; i<n; j++)
	{
		j%n == i ? i++ : printf("%c%c", square[i][j-(n+1)*i], j%n == i ? '\n' : ' ');
	}
}