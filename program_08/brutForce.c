#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_pat 10
#define max_str 40

/**
 * Function prototype
 */

int bruteForce(char *ser, char *pat, int str_len, int pat_len);


int main(){
    
    char pat_inp[max_pat];;
    char str_inp[max_str];
    int res;

    // get the string part from user
    printf("\nEnter the string part:\t");
    fgets(str_inp, max_str, stdin);


    // remove the new line that is attached to the prev inp
    while(getchar()!='\n');

    // get pattern input from user
    printf("\nEnter the pattern part:\t");
    fgets(pat_inp, max_pat, stdin);

    str_inp[strlen(str_inp) - 1] = '\0';
    pat_inp[strlen(pat_inp) - 1] = '\0';

    //printf("\n%s\n%s\n", str_inp, pat_inp);

    res = bruteForce(str_inp, pat_inp, strlen(str_inp), strlen(pat_inp));
        if (res == -1) {
                printf("Search pattern is not available\n");
        } else {
                printf("Search pattern available at the location %d\n", res);
        }
        return 0;

    return 0;
}

int bruteForce(char *ser, char *pat, int str_len, int pat_len){

    printf("\n%s\n%s\n", ser, pat);
    printf("\n%d\n%d\n", str_len, pat_len);

    int i, j, k;

        for (i = 0; i <= str_len - pat_len; i++) {
                for (j = 0, k = i; (ser[k] == pat[j]) &&
                        (j < pat_len); j++, k++);
                if (j == pat_len)
                        return j;
        }
        return -1;

}