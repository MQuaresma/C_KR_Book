/* strlen: return lenght of strig s */
int strlen(char *s){
    
    char *p = s;

    while(*p != '\0') p ++;

    return p-s;
}
