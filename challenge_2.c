#include "challenge_2.h"
#include "challenge_1.h"


int * XOR(char * buff1, char * buff2, int len){
	int *buff1_hex = str_to_hex(buff1, len);
	int *buff2_hex = str_to_hex(buff2, len);
	int *res = NULL;
	res = malloc(sizeof(int)*len);
	for(int i = 0; i < len; ++i){
		res[i] = buff1_hex[i] ^ buff2_hex[i];
	//	printf("%X", res[i]);
	}
	return res; 
}


