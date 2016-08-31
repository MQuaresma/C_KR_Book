/* Several versions of strcpy */

/*strcpy: copy s to t; array subscript version */
void strcpy(char *s, char *t){

    int i;

    while((s[i] = t[i])) i++;

}


/*strcpyP: copy s to t; pointer version */
void strcpyP(char *s, char *t){

    while((*s = *t)){
        s ++;
        t ++;
    }
}


/*strcpyExpert: copy s to t; expert version */
void strcpyExpert(char *s, char *t){

    while((*t++ = *s++) != '\0');

}

/*strcpyExpertTwo: copy s to t; expert version 2.0 */
void strcpyExpert(char *s, char *t){

    while(*t++ = *s++);

}


/* Several versions of strcmp */

int strcmp(char *s, char *t){

    int i;

    for(i = 0; s[i] == t[i]; i ++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i]; 

}


int strcmpP(char *s, char *t){


    for(; *s == *t; s ++, t ++)
        if(*s == '\0')
            return 0;

    return *s - *t;

}
