#include <stdio.h>
#define TRUNC 10

main(){

    char *s = "hello, world";

    printf(":%15s:\n", s);        // Use at least 15 characters to print s, if s is less than 15 then spaces are added (to the right)
    printf(":%.10s:\n", s);       // Print 10 characters of s, at most
    printf(":%.*s:\n", TRUNC, s); // Print TRUNC characters of s, at most
    printf(":%-15s:\n", s);       // Same as the first expression but the spaces are added to the left
    printf(":%-15.*s:\n", TRUNC, s);    // Combination of the previous formats

    return 0;
}
