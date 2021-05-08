#include "challenge_3.h"
#include "challenge_2.h"
#include "challenge_1.h"

void brute_force_1_octet(int * hex_buff_myst, int len){
	//int * hex_buff_myst = str_to_hex(buff_myst, len);
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


void letter_f_analyse(FILE* fichier){
	int ctr = 0;
	int char_act = 0;
	float alpha[26];
	for(int i = 0; i < 26; ++i) alpha[i] = 0;
	float alpha_p[26];

	if (fichier != NULL){
		do{

			char_act = fgetc(fichier); 
			//printf("%c", char_act); 
			if((char_act >= 'a' && char_act <= 'z') || (char_act >= 'A' && char_act <= 'Z')){
				++ctr;
				if(char_act >= 'a' && char_act <= 'z'){
					++alpha[char_act - 'a'];
				}
				else{
					++alpha[char_act - 'A'];
				}
			}	

	       	} while (char_act != EOF);
		printf("\nctr : %d\n", ctr);	
		for(int i = 0; i < 26; ++i) alpha_p[i] = (alpha[i] * 100) / ctr;


		fclose(fichier);
   	}
   	else{
   	     printf("Impossible d'ouvrir le fichier");
    	}
	
	
	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", i + 'a', alpha[i]);
	printf("\n");
	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", i + 'a', alpha_p[i]);
}
