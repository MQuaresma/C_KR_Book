#include <stdio.h>
#include <stdlib.h>
#include "sec6_5.h"

main(){

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addTree(root, word);
	treeprint(root);
	return 0;

}


struct tnode *addTree(struct tnode *r, char *w){

	int cmp;

	if(!r){
		r = (tnode *)malloc(sizeof(struct tnode));
		strcpy(r->word, w); // r->word = strdup(w);
		r->count = 1;
		r->left = r->right = 0;
	}
	cmp = strcmp(w, r->word);
	if(cmp == 0) r->count ++;
	else if(cmp < 0) r->left = addTree(r->left, w);
	else r->right = addTree(r->right, w);

	return r;
}

void treeprint(struct tnode *t){

	if(*t){
		treeprint(t->left);
		printf("%4d %s\n", t->count, t->word);
		treeprint(t->right);
	}

}