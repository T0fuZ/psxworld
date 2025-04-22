/*
 * Net Yaroze
 * Echo back until 'quit'
 *
 * This program prints back to SIOCONS whatever you type there.
 */
#include <libps.h>
#include <stdio.h>

void main (void)
{
	char a[100] = "";
	while(strcmp(a,"quit")){
		//i--;
		gets(a);
		printf("Reply to STDOUT: %s\n",a);
	}
	
}
