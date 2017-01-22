#include <stdlib.h>
#include <ctype.h>
#include "sorting.h"

int numcmp(char *s1, char *s2){

    return atof(s1) - atof(s2);    

}

int numcmpReverse(char *s1, char *s2){

    return atof(s2) - atof(s1);

}


int strcmpReverse(char *s1, char *s2){

    while(*s1 == *s2 && *s1 && *s2)
        s1 ++, s2 ++;
    return (*s2)-(*s1);


}

int strcmpReverseLower(char *s1, char *s2){

    while( *s1 && *s2 && tolower(*s1) == tolower(*s2))
        s1 ++, s2 ++;
    return tolower(*s2)-tolower(*s1);


}


int strCmpLower(char *s1, char *s2){

    while( *s1 && *s2 && tolower(*s1) == tolower(*s2))
        s1 ++, s2 ++;
    return tolower(*s1)-tolower(*s2);

}


int dirCompare(char *s1, char *s2){

	while(*s1 && *s2){
		while(s1 && !(isalpha(*s1) || isspace(*s1)))
			s1 ++;
		while(s2 && !(isalnum(*s2) || isspace(*s2)))
			s2 ++;
		if(*s1 != *s2) break;
		s1 ++;
		s2 ++;
	}

	return *s1 - *s2;
}

int indexSorting(char *s1, char *s2){

	int index1 = 0, index2 = 0;

	do
		index1 = index1 * 10.0 + (*s1 - '0');
	while(*s1 && isdigit(*s1++));

	do
		index2 = index2 * 10.0 + (*s2 - '0');
	while(*s2 && isdigit(*s2++));
			
	return index1 - index2;
}
