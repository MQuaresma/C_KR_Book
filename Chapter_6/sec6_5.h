#define MAXWORD 100

typedef struct tnode{

	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;

};

struct tnode *addTree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);