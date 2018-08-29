#include <stdio.h>
#include <string.h>

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]){

    int n;

    for(n = strlen(s)-1; n >= 0; n --) if(s[n] != '\n' && s[n] != '\t' && s[n] != ' ') break;

    s[n+1] = '\0';
    return n;
}

/* Two version of trim with some adaptions made for experimentation purposes */
void myTrim(char s[]){
    char *safe = s;

    for(s += strlen(s)-1; s >= safe; s --)
        if(*s != '\t' && *s != '\n' && *s != ' ') break;
        
    *(s+1) = '\0';
    s = safe;
}

void myTrim2(char s[]){
    
    char *safe = s;

    for(s += strlen(s)-1; s >= safe && (*s != '\t' && *s != '\n' && *s != ' '); s --);
        
    *(s+1) = '\0';
    s = safe;
}


int main(){

    char s[] = "mg    as";
    myTrim(s);
    printf("%s\n", s);
    return 0;
}