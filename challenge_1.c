#include "challenge_1.h"


char * hex_to_ASCII (int * tab_hex, int len){
	char *  hex_char = NULL;
	hex_char = malloc(len/2 * sizeof(char));
	char temp;
	int j = 0;
	
	for(int i = 0; i < len; i += 2 ){
		temp = tab_hex[i] << 4;
		temp = temp |  tab_hex[i+1];
		hex_char[j] = temp;
		++j;
	}
	return hex_char;
}



char * strHex_to_ASCII(char * str, int len){
	char * temp_str = NULL;
	temp_str = malloc(sizeof(char)*len);
	int * temp = str_to_hex(str,len);
	temp_str = hex_to_ASCII(temp, len);
	return temp_str; 
}

void binary_shift(int a, int b, int c, int * r1, int * r2){ 
	*r1 = a   << 4;
	*r1 = *r1 |  b;
	*r1 = *r1 >> 2;  
	
	*r2 = b   << 4;
	*r2 = *r2 |  c;
	*r2 = *r2 &  ~(0xC0);
}

int * hex_to_base64(int * tab_hex, int len){
	int * tab_base64 = NULL; 
	tab_base64 = malloc(sizeof(int) * len);
	int * r1 = malloc(sizeof(int));
	int * r2 = malloc(sizeof(int));
	int j = 0;


	for(int i = 0; i < len-1; i += 3){
		binary_shift(tab_hex[i],tab_hex[i+1],tab_hex[i+2],r1,r2);
		tab_base64[j]   = *r1;
		tab_base64[j+1] = *r2; 
		j += 2;
	}
	
	free(r1);
	free(r2);

	return tab_base64;
}

char * base64_to_str(int * tab, int len){
	len = (len*2)/3; 
	char * res = malloc(sizeof(char) * len);
	res[0] = '\0';
	for(int i = 0; i < len; ++i){
		switch(tab[i]){
			case 0  : strcat(res, "A"); break;
			case 1  : strcat(res, "B"); break;
			case 2  : strcat(res, "C"); break;
			case 3  : strcat(res, "D"); break;
			case 4  : strcat(res, "E"); break;
			case 5  : strcat(res, "F"); break;
			case 6  : strcat(res, "G"); break;
			case 7  : strcat(res, "H"); break;
			case 8  : strcat(res, "I"); break;
			case 9  : strcat(res, "J"); break;
			case 10 : strcat(res, "K"); break;
			case 11 : strcat(res, "L"); break;
			case 12 : strcat(res, "M"); break;
			case 13 : strcat(res, "N"); break;
			case 14 : strcat(res, "O"); break;
			case 15 : strcat(res, "P"); break;
			case 16 : strcat(res, "Q"); break;
			case 17 : strcat(res, "R"); break;
			case 18 : strcat(res, "S"); break;
			case 19 : strcat(res, "T"); break;
			case 20 : strcat(res, "U"); break;
			case 21 : strcat(res, "V"); break;
			case 22 : strcat(res, "W"); break;
			case 23 : strcat(res, "X"); break;
			case 24 : strcat(res, "Y"); break;
			case 25 : strcat(res, "Z"); break;
			case 26 : strcat(res, "a"); break;
			case 27 : strcat(res, "b"); break;
			case 28 : strcat(res, "c"); break;
			case 29 : strcat(res, "d"); break;
			case 30 : strcat(res, "e"); break;
			case 31 : strcat(res, "f"); break;
			case 32 : strcat(res, "g"); break;
			case 33 : strcat(res, "h"); break;
			case 34 : strcat(res, "i"); break;
			case 35 : strcat(res, "j"); break;
			case 36 : strcat(res, "k"); break;
			case 37 : strcat(res, "l"); break;
			case 38 : strcat(res, "m"); break;
			case 39 : strcat(res, "n"); break;
			case 40 : strcat(res, "o"); break;
			case 41 : strcat(res, "p"); break;
			case 42 : strcat(res, "q"); break;
			case 43 : strcat(res, "r"); break;
			case 44 : strcat(res, "s"); break;
			case 45 : strcat(res, "t"); break;
			case 46 : strcat(res, "u"); break;
			case 47 : strcat(res, "v"); break;
			case 48 : strcat(res, "w"); break;
			case 49 : strcat(res, "x"); break;
			case 50 : strcat(res, "y"); break;
			case 51 : strcat(res, "z"); break;
			case 52 : strcat(res, "0"); break;
			case 53 : strcat(res, "1"); break;
			case 54 : strcat(res, "2"); break;
			case 55 : strcat(res, "3"); break;
			case 56 : strcat(res, "4"); break;
			case 57 : strcat(res, "5"); break;
			case 58 : strcat(res, "6"); break;
			case 59 : strcat(res, "7"); break;
			case 60 : strcat(res, "8"); break;
			case 61 : strcat(res, "9"); break;
			case 62 : strcat(res, "+"); break;
			case 63 : strcat(res, "/"); break;
			default : strcat(res, "error"); break;
		}
	}

	return res;
}

int * str_to_hex(char * str, int len){
	int * tab_hex = NULL;
	tab_hex = malloc(sizeof(int) * len);

	for(int i = 0; i < len; ++i){
		if(str[i] > '9'){
			tab_hex[i] = str[i]-'a'+10;
		}
		else{
			tab_hex[i]= str[i]-'0';
		}
		//printf("%X", tab_hex[i]);
	}
	return tab_hex;
<<<<<<< HEAD:challenge_1.c
=======
} 

int * hex_to_base64(int * tab_hex, int len){
	int * tab_base64 = NULL; 
	tab_base64 = malloc(sizeof(int) * len);
	int * r1 = malloc(sizeof(int));
	int * r2 = malloc(sizeof(int));
	int j = 0;


	for(int i = 0; i < len-1; i += 3){
		binary_shift(tab_hex[i],tab_hex[i+1],tab_hex[i+2],r1,r2);
		tab_base64[j]   = *r1;
		tab_base64[j+1] = *r2; 
		j += 2;
	}
	
	free(r1);
	free(r2);

	return tab_base64;
}

char * hex_to_ASCII (int * tab_hex, int len){
	char *  hex_char = NULL;
	hex_char = malloc(len/2 * sizeof(char));
	char temp;
	int j = 0;
	
	for(int i = 0; i < len; i += 2 ){
		temp = tab_hex[i] << 4;
		temp = temp |  tab_hex[i+1];
		hex_char[j] = temp;
		++j;
	}
	return hex_char;
}

char * strHex_to_ASCII(char * str, int len){
	char * temp_str = NULL;
	temp_str = malloc(sizeof(char)*len);
	int * temp = str_to_hex(str,len);
	temp_str = hex_to_ASCII(temp, len);
	return temp_str; 
}

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

int main(){

//**********************************************************************************
//	Challenge 1
//**********************************************************************************

//	char str[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";	
//
//	int len = (int)sizeof(str)-1;
//	
//	int * tab_hex = str_to_hex(str, len);
//	
//	printf("\n");
//	
//	int * tab_base64 = hex_to_base64(tab_hex, len);
//	
//	printf("%s\n", base64_to_str(tab_base64,len)) ;	
//	
//	char * hex_char = hex_to_ASCII(tab_hex, len); 	
//	
//	printf("%s\n", hex_char);
	

//**********************************************************************************
//	Challenge 2
//**********************************************************************************
	
	//char buff1[] = "1c0111001f010100061a024b53535009181c";	
	//char buff2[] = "686974207468652062756c6c277320657965";
	//printf("%s\n", hex_to_ASCII(str_to_hex(buff1, sizeof(buff1)),sizeof(buff1)));	
 	//printf("%s\n", hex_to_ASCII(str_to_hex(buff2, sizeof(buff2)),sizeof(buff2)));	
	//int len2 = sizeof(buff1);
	//int * res_xor = XOR(buff1, buff2, len2);
	//printf("%s\n", hex_to_ASCII(res_xor, len2));


//**********************************************************************************
//	Challenge 3
//**********************************************************************************

	char buff_myst[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	int len = sizeof(buff_myst)-1;
	brute_force_1_octet(buff_myst, len);
	
	return 0;
>>>>>>> 37174bc8dc8cd104d63d02cf70e3c8e4d2070746:hex_to_base_64.c
}
