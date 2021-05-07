#include "challenge_3.h"
#include "challenge_2.h"
#include "challenge_1.h"

void brute_force_1_octet(char * buff_myst, int len){
	int * hex_buff_myst = str_to_hex(buff_myst, len);
	int c;                                	
        int c1;
        int c2; 
	int * hex_res = malloc(sizeof(int) * len);
	for(int j = 0; j < 256 ; ++j){
	c = j;
	c1 = c >> 4;
	c2 = c & ~(0xF0); 	
	
		for(int i = 0; i< len; i+= 2){
			hex_res[i] = c1 ^ hex_buff_myst[i] ;
			hex_res[i+1] = c2 ^ hex_buff_myst[i+1];
			//printf("%X%X", hex_res[i], hex_res[i+1]);	
		}
	printf("key: %c ->  %s\n",j, hex_to_ASCII(hex_res, len));	
	}
}


