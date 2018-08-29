#include "parameters.h"

static const char keys[] = "nrfds";

void initDict(dictionary *p){
	int i;

	for(i = 0; keys[i]; i++, p ++){
		p->value = 0;
		p->key = keys[i];
	}
}


int newParam(dictionary *p, char c, int size){

	int i;
	for(i = 0; i < size && p->key != c; i ++, p ++);

	if(i == size) return 1;
	p->value = 1;
	return 0;
}


int checkValue(dictionary *p, char c){

	while(p->key != c)
		p ++;
	return p->value;
}