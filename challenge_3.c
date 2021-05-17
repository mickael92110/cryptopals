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

void letter_f_analyse_string(char * str){
	int ctr = 0;
	int len = strlen(str);
	int char_act = 0;
	float alpha[26];
	float alpha_p[26];
	char * alpha_c = malloc(sizeof(char)*26);
	for(int i = 0; i < 26; ++i) alpha_c[i] = 'a' + i;
	for(int i = 0; i < 26; ++i) alpha[i] = 0;
	
	for(int i = 0; i < len; ++i ){

		char_act = str[i]; 
		printf("%c", char_act); 
		if((char_act >= 'a' && char_act <= 'z') || (char_act >= 'A' && char_act <= 'Z')){
			++ctr;
			if(char_act >= 'a' && char_act <= 'z'){
					++alpha[char_act - 'a'];
			}
			else{
				++alpha[char_act - 'A'];
			}
		}
       	}
	printf("\nctr : %d\n", ctr);	
	for(int i = 0; i < 26; ++i) alpha_p[i] = (alpha[i] * 100) / ctr;

	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", i + 'a', alpha[i]);
	printf("\n");
	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", i + 'a', alpha_p[i]);
	sort_tab(alpha_p, alpha_c, 26);
	printf("\n");
	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", alpha_c[i], alpha_p[i]);
	
	int indice = 0;
	
	for(int i = 0; i < 11 ; ++i){
		if(alpha_c[i] == 'e' || alpha_c[i] == 't' || alpha_c[i] == 'a'|| alpha_c[i] == 'o'|| alpha_c[i] == 'n'|| alpha_c[i] == 'h'|| alpha_c[i] == 'i'|| alpha_c[i] == 'r'|| alpha_c[i] == 's'|| alpha_c[i] == 'd'|| alpha_c[i] == 'l'){
			++indice;	
		}
		else{
			--indice;
		}
	}
	printf("indice : %d \n", indice);	
}
	


void letter_f_analyse_File(FILE* fichier){
	int ctr = 0;
	int char_act = 0;
	float alpha[26];
	for(int i = 0; i < 26; ++i) alpha[i] = 0;
	float alpha_p[26];
	char * alpha_c = malloc(sizeof(char)*26);
	for(int i = 0; i < 26; ++i) alpha_c[i] = 'a' + i;

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
	sort_tab(alpha_p, alpha_c, 26);
	printf("\n");
	for(int i = 0; i < 26; ++i) printf("%c : %.2f\n", alpha_c[i], alpha_p[i]);
}



int  sort_tab(float * tab, char * tab_c, int len){
	float max = tab[0];
	int idx_max = 0;
	char temp;
	for(int i = 0; i < len; ++i){
		if(tab[i] > max){
			idx_max = i;
			max = tab[i];	
		}
	}
	tab[idx_max] = tab[0];
	tab[0] = max;
	temp = tab_c[idx_max];
	tab_c[idx_max] = tab_c[0];
	tab_c[0] = temp;
	if(len == 0) return 0;
	sort_tab(++tab, ++tab_c , --len);
	return 0;
}



