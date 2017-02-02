/* 
 * Bitfield: declares a structure in which each component is a field of w width, in this case 1 bit, meaning this structure takes up 4 bytes (one word) instead of 
 * 12 bytes, meaning we can have up to 32 one bit width variables in the structure, if we have 33 the structure will take up 8 bytes, and so on.
 * The fields don't have addresses so it is illegal to use the & operator.
 */
typedef struct{
    
    char is_keyword : 1;
    char is_extern : 1;
    char is_static : 1;

}flags;

