/*Sec 5.8:
 * Initialization of pointer arrays
* /

/* month_name: return the name of the n-th month */
char *month_name(int n){

    static char *name[]={
        "Illegal Month",
        "Januray", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];

}
