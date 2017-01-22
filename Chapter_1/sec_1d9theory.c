#include <stdio.h> 
#define MAX_S 1000

int getLine(char *s){
	int i = 0;
	char c;

	while((c = getchar()) != '\n' && i < MAX_S-1){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}



void strCpy(char *src, char *dest, int length){
	int i = 0;	
	
	while(i < length){
		dest[i] = src[i];		
		i ++;
	}
	dest[i] = '\0';	
}


int main(){
	char runnerUpStr[MAX_S], longestStr[MAX_S] = "";
	int longest = 0, runnerUp = 1;	

	while(runnerUp > 0){
		runnerUp = 0;
		runnerUp = getLine(runnerUpStr);
		if(runnerUp > longest){
			strCpy(runnerUpStr, longestStr, runnerUp);
			longest = runnerUp;
		}
	}
	if(longest){
		printf("%d\n", longest);
		printf("%s\n", longestStr); 
	}
	else printf("No input recieved\n");
	return 0;
}
