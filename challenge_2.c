#include "challenge_2.h"
#include "challenge_1.h"


int * XOR(int * buff1, int * buff2, int len){
	//int *buff1_hex = str_to_hex(buff1, len);
	//int *buff2_hex = str_to_hex(buff2, len);
	int *res = NULL;
	res = malloc(sizeof(int)*len);
	for(int i = 0; i < len; ++i){
		res[i] = buff1[i] ^ buff2[i];
	//	printf("%X", res[i]);
	}
	return res; 
}


