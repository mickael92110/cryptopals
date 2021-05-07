#ifndef CHALLENGE_1_H
#define CHALLENGE_1_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char * hex_to_ASCII (int * tab_hex, int len);

char * strHex_to_ASCII(char * str, int len);

int * hex_to_base64(int * tab_hex, int len);

void binary_shift(int a, int b, int c, int * r1, int * r2); 

char * base64_to_str(int * tab, int len);

int * str_to_hex(char * str, int len);







#endif
