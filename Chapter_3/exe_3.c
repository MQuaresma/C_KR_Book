#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*convert s to integer*/
int atoI(char s[]){

    int i, n, sign;

    for(i = 0; isspace(s[i]); i ++);

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+') /*skip sign*/
        i ++;

    for(n = 0; isdigit(s[i]); i ++)
        n = 10 * n + (s[i] - '0');        

    return sign * n;
}


/*shellsort: sort v[0]...v[n-1] into increasing order*/
void shellsort(int v[], int n){

    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i ++){
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

        }
    }
}


/*reverse: reverse string s in place*/
void reverse(char s[]){

    char c;
    int i, j;

    for(i = 0, j = strlen(s)-1; i<j; i ++, j --){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/*expandSimple: same as expand but with simpler code*/
void expandSimple(char *s1, char *s2){
    char c;

    for(; *s1; s1 ++){
        if(c){

            while(c <= *s1){
                *(s2++) = c;
                c ++;
            }
            c = '\0';
        }
        if(*s1 == '-'){
            
            
        }

    }


}


/*expand: expands shorthand notation in string s1 to the equivalent complete list in string s2*/
void expand(char *s1, char *s2){
    int i, j;
    char c;

    for(i = 0, j = 0; s1[i]; i ++){
        if(isalpha(s1[i])){
            if(s1[i+1] == '-' && isalpha(s1[i+2])){
                c = s1[i];
                while(c <= s1[i+2]){
                    s2[j++] = c;
                    c ++;
                }
                i += 2;
            }
            else s2[j ++] = s1[i];
        }
        else if(isdigit(s1[i])){
            if(s1[i+1] == '-' && isdigit(s1[i+2])){
                c = s1[i];
                while(c <= s1[i+2]){
                    s2[j++] = c;
                    c ++;
                }
                i += 2;
              }
              else s2[j ++] = s1[i];   
        }
        else s2[j++] = s1[i];
    }

    s2[j] = '\0';
}


/*expandedSize: calculates the amount of space required (in bytes) to store the result of expandind all shorthand notation in string s*/
size_t expandedSize(char *s){

    int i, r;
    char c;

    for(i = 0, r = 0; s[i]; i ++){
        if(isalpha(s[i])){
            if(s[i+1] == '-' && isalpha(s[i+2])){
                c = s[i];
                while(c <= s[i+2]){
                    c ++;
                    r ++;
                }
                i += 2;
            }
            else r ++;
        }
        else if(isdigit(s[i])){
            if(s[i+1] == '-' && isdigit(s[i+2])){
                c = s[i];
                while(c <= s[i+2]){
                    c ++;
                    r ++;
                }
                i += 2;
            }
            else r ++;
        }        
        else r ++;
    }


    return (r+1)*sizeof(char);
}


/*expand_safe: expands shorthand notation in string s1 to the equivalent complete list in string s2, 
sames as expand but allocates the necessary memory for string s2 to prevent access to illegall memory adresses*/
void expandSafe(char *s1, char **s2){

    size_t mem = expandedSize(s1);
    int i, j;
    char c;
    
    *s2 = (char *) malloc(mem);

    for(i = 0, j = 0; s1[i]; i ++){
        if(isalpha(s1[i])){
            if(s1[i+1] == '-' && isalpha(s1[i+2])){
                c = s1[i];
                while(c <= s1[i+2]){
                    (*s2)[j++] = c;
                    c ++;
                }
                i += 2;
            }
            else (*s2)[j++] = s1[i];
        }

        else if(isdigit(s1[i])){
            if(s1[i+1] == '-' && isdigit(s1[i+2])){
                c = s1[i];
                while(c <= s1[i+2]){
                    (*s2)[j++] = c;
                    c ++;
                }
                i += 2;
            }
            else (*s2)[j++] = s1[i];
        }
        else (*s2)[j++] = s1[i];
    }
    (*s2)[j] = '\0';
}

int main(){

    char s1[] = "Miguel a-z", *s2;

    expandSafe(s1, &s2);
    printf("%s\n", s2);

    return 0;
}