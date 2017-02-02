#define N 10
#define INT 1
#define FLOAT 2
#define CHAR 3

union u_test{

    int i;
    float f;
    char c;

};

typedef struct{
    int *name;
    int flags, utype;
    union u_test u;
    
}Symbol;
