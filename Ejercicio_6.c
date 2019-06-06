#include <stdio.h>
#include <stdlib.h>

int strcmp1(char *s, char *p){
	if(*s == '\0' && *p == '\0'){
		return 0;
	}
	else if(*s != '\0' && *p != '\0'){
		return strcmp1((s+1), (p+1));
	}else if(*s == '\0'){
		return -1;
	}else{
		return 1;
	}
}	
