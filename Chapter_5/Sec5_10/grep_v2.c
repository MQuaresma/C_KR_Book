#include <stdio.h>
#define MAXLINE 1000

int getLine(char *s, int len);
char *strStr(char *s, char *t);


main(int argc, char *argv[]){

    char line[MAXLINE], c;
    int found = 0, numbers = 0, except = 0; 
    long int curLine = 1;

    while(--argc > 0 && (*++argv)[0] == '-')
        while((c = *++argv[0]))
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    numbers = 1;
                    break;
                default:
                    printf("Invalid parameter, please check the manual\n");
                    argc = 0;
                    found=-1;
                    break;
            }
    if(argc != 1){
        printf("Missing pattern\n");
        return found;
    }

    while(getLine(line, MAXLINE) > 0){
            if((strStr(line ,*argv) != NULL) != except){
                if(numbers) printf("%ld: ", curLine ++);
                printf("%s\n", line);
                found ++;
            }
    }

    return found;
}
