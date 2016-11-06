#include <stdlib.h>
#include <ctype.h>

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

}
