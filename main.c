#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "challenge_1.h"
#include "challenge_2.h"
#include "challenge_3.h"

int main(){

//**********************************************************************************
//	Challenge 1
//**********************************************************************************

	char str[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";	

	int len = (int)sizeof(str)-1;
	
	int * tab_hex = str_to_hex(str, len);
	
	printf("\n");
	
	int * tab_base64 = hex_to_base64(tab_hex, len);
	
	printf("%s\n", base64_to_str(tab_base64,len)) ;	
	
	char * hex_char = hex_to_ASCII(tab_hex, len); 	
	
	printf("%s\n", hex_char);
	

//**********************************************************************************
//	Challenge 2
//**********************************************************************************
	
	char buff1[] = "1c0111001f010100061a024b53535009181c";	
	char buff2[] = "686974207468652062756c6c277320657965";
	printf("%s\n", hex_to_ASCII(str_to_hex(buff1, sizeof(buff1)),sizeof(buff1)));	
 	printf("%s\n", hex_to_ASCII(str_to_hex(buff2, sizeof(buff2)),sizeof(buff2)));	
	int len2 = sizeof(buff1);
	int * res_xor = XOR(buff1, buff2, len2);
	printf("%s\n", hex_to_ASCII(res_xor, len2));


//**********************************************************************************
//	Challenge 3
//**********************************************************************************

//	char buff_myst[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
//	int len = sizeof(buff_myst)-1;
//	brute_force_1_octet(buff_myst, len);
//	
	return 0;
}
