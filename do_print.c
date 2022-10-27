#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/select.h>
#include "pm.h"
int do_print()
{
	char cadena[14];
	int pid=m_in.m1_i1;
	int ppid=m_in.m1_i2;
	int flag;
	strcpy(cadena, m_in.m3_ca1);
	int longitud=strlen(cadena);
	for(int i = 0;i<longitud/2;i++){
		flag=cadena[i];
		cadena[i]=cadena[longitud-i-1];
		cadena[longitud-i-1]=flag;
	}
	printf("\nLa cadena inversa es: %s\n", cadena);
	printf("\nEl PID es: %d\n", pid);
	printf("\nEl PPID es: %d\n", ppid);
	return 0;
}
