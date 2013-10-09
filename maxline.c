#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getcustomline(void);
void copy(void);

main()
{
	extern int max;
	extern char longest[MAXLINE];
	int len;
	while ( (len = getcustomline()) > 0 )
	{
		if ( len > max )
		{
			max = len;
			copy();
		}
	}
	
	if ( max > 0 )
	{
		printf("%s",longest);
	}
	return 0;
}

int getcustomline()
{
	extern char line[];
	
	int c,i;
	
	for ( i = 0; i < MAXLINE - 1 && ((c=getchar()) != EOF) && c != '\n'; ++i )
	{
		line[i] = c;
	} 
	
	if ( c == '\n' )
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	
	return i;
}

void copy()
{
	extern char line[];
	extern char longest[];
	int i = 0;
	while ( (longest[i] = line[i]) != '\0' )
	{
		++i;
	}
}
