#include <stdio.h>
#include <string.h>
#include <ctype.h>

int power(int base, int exp){

	int r = 1;
	
	while(exp){
		r *= base;
		exp --;
	}
	return r;
}

int calc(char *s, int len){

	int r = 0, i = 0;
	len --;
	
	for(i = 0; s[i] != '\0'; i ++, len --){
		
		if(isdigit(s[i])) r += power(16, len) * (s[i] - '0');
		else if(isalpha(s[i]) && isupper(s[i])) r += power(16, len) * (s[i] - 91);
		else if(isalpha(s[i]) && islower(s[i])) r += power(16, len) * (s[i] - 131);
	}	
	return r;
}



int htoi(char *s){

	int comp = strlen(s), r = 0;
	
	if(comp){
		if(comp <= 2) r = calc(s, comp);
		else if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
			comp -= 2;
			r = calc(s+2, comp);
		}
		else r = calc(s, comp);
	}
	return r;

}



int main(){

	char c[] = "0x23";
	
	printf("%d\n", htoi(c));
	return 0;

}
