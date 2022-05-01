#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nam[31];
    char phone[16];
} LISTING;
const int cMax_Size = 53;

void buildList(LISTING phoneList[], int *last);

void hashSearch(LISTING *phoneList, int last);
int hashKey(char *key, int last);
int collision(int last, int locn);
int main(void)
{
    // Local Definitions
    LISTING phoneList[cMax_Size];
    int last;
    // Statements
    printf("Begin Phone Listing\n");
    last = cMax_Size - 1;
    buildList(phoneList, &last);
    hashSearch(phoneList, last);
    printf("\nEnd Phone Listing\n");
    return 0;
} 
void buildList(LISTING phoneList[], int *last)
{
    // Local Definitions
    FILE *fpPhoneNums;
    LISTING aListing;
    int locn;
    int cntCol;
    int end;
    // Statements
    fpPhoneNums = fopen("ph.txt", "r");
    if (!fpPhoneNums)
    {
        printf("Can't open phone file\a\n");
        exit(100);
    } // if
    // Set keys to null
    for (int i = 0; i <= *last; i++)
        phoneList[i].nam[0] = '\0';

    while (!feof(fpPhoneNums))
    {
        fscanf(fpPhoneNums, " %30[^;]%*c %[^;]%*c",
               aListing.nam, aListing.phone);
        locn = hashKey(aListing.nam, *last);
        if (phoneList[locn].nam[0] != '\0')
        {
            // Collision
            end = *last;
            cntCol = 0;
            while (phoneList[locn].nam[0] != '\0' && cntCol++ <= *last)
                locn = collision(*last, locn);
            if (phoneList[locn].nam[0] != '\0')
            {
                printf("List full. Not all read.\n");
                return;
            } 
        }  
        phoneList[locn] = aListing;
    } 
    return;
} 

int hashKey(char *key, int last)
{
    // Local Definitions
    int addr;
    int keyLen;
    // Statements
    keyLen = strlen(key);
    addr = 0;
    for (int i = 0; i < keyLen; i++)
        if (key[i] != ' ')
            addr += key[i];
    return (addr % last + 1);
} 
int collision(int last, int locn)
{
    
    return locn < last ? ++locn : 0;
} 
void hashSearch(LISTING *phoneList, int last)
{
    // Local Definitions
    char srchName[31];
    char more;
    int locn;
    int maxSrch;
    int cntCol;
    // Statements
    do
    {
        printf("Enter name: ");
        scanf("%s", srchName);
        locn = hashKey(srchName, last);
        if (strcmp(srchName, phoneList[locn].nam) != 0)
        {
            
            maxSrch = last;
            cntCol = 0;
            while (strcmp(srchName,
                          phoneList[locn].nam) != 0 &&
                   cntCol++ <= maxSrch)
                locn = collision(last, locn);
        } 
        if (strcmp(srchName, phoneList[locn].nam) == 0)
        {
            printf("%-32s (%02d) %-15s\n",
                   phoneList[locn].nam,
                   locn,
                   phoneList[locn].phone);
        }
        else
            printf("%s not found\n", srchName);
        printf("\nLook up another number <Y/N>? ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
} 