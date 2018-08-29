/* Parameter is designed to hold a key which identifies the flag and a value which identifies the state of the flag */
#define PARAMS 5
typedef struct dict{

	char key;
	int value;

}dictionary;

typedef dictionary dictionaryArray[PARAMS];

void initDict(dictionary *);
int newParam(dictionary *, char, int);
int checkValue(dictionary *, char);