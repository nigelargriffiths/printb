#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printb(char *buf,int size)
{
char s[81];
int i;
int j;
int num = 0;
char ch;

	printf("\n");
	for(i = 0; i < size; i++) {
		if(num == 0) {
			for(j = 0; j < 80; j++)
				s[j] = ' ';
			s[80] = 0;
		}

		s[num*3  ] = (ch = ((buf[i] >>4) & 0x0f)) > 9 ? ch + 'a' - 10: ch + '0';
		s[num*3+1] = (ch = ( buf[i]      & 0x0f)) > 9 ? ch + 'a' - 10: ch + '0';
		if( buf[i] < 0x7f && buf[i] > ' ')
			s[num + 60] = buf[i];
		else
			s[num + 60] = '.';
		if( (i + 1) % 20 == 0) {
			printf("%s\n",s);
			num = 0;
		}
		else num++;
	}
	if(num != 0)
		printf("%s\n",s);
	else
		printf("\n");
}

#define BUFSIZE (1024 * 1024)

int main()
{
	char *buffer;
	int ret;
	buffer = malloc(BUFSIZE);
	while((ret = read(0,buffer,BUFSIZE)) >0 ) {
		printb(buffer, ret);
	}
}
