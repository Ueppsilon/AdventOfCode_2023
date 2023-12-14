#include <stdio.h>

char inputstring[24000];
FILE* fptr;
char outputstring[100];
int c = 0;

int main()
{
    printf("Calculation started!\n");
    fopen_s(&fptr, "1_inputdata.txt", "r");
    int ones = 0;
    int i = 0;
    char first_digit = 0;
    char last_digit = 0;
    int sum = 0;
    for (i = 0; i < 23039; i++) {
        c = fgetc(fptr);
        if (c > 47 && c < 58){
            last_digit = c - 48;
            if (first_digit == 0) {
                first_digit = c - 48;
            }
        }
        if (c == 10) {
            sum += first_digit * 10;
            sum += last_digit;
            first_digit = 0;
        }
    }
    sprintf_s(outputstring, "sum: %i \nPress any button to close.", sum);
    printf(outputstring);
    getchar();
    return 0;
}

