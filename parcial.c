#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc<2){exit(1);}
	char cadena[14];
	for(int i=0;i<argc;i++){
		strcpy(cadena, argv[i]);
	}
	message m;
	strcpy(m.m3_ca1, cadena);
	m.m1_i1=getpid();
	m.m1_i2=getppid();
	_syscall(PM_PROC_NR, PRINTP, &m);
	return 0;
}
