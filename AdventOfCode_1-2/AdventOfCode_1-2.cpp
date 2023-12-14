#include <stdio.h>

FILE* fptr;
char outputstring[100];
int c = 0;

int check_number(int c, int letter_count, char* string_digit);

int main()
{
    printf("Calculation started!\n");
    fopen_s(&fptr, "1_inputdata.txt", "r");
    int i = 0;
    char first_digit = 0;
    char last_digit = 0;
    int sum = 0;
    int possible_find[] = { 0,0,0,0,0,0,0,0,0 };
    int number_string_length[] = { 3,3,5,4,4,3,5,5,4 };
    char string_numbers[][10] = { "one","two","three","four","five","six","seven","eight","nine" };

    for (i = 0; (c = fgetc(fptr)) != EOF ; i++) {
        if (c > 47 && c < 58) {
            last_digit = c - 48;
            if (first_digit == 0) {
                first_digit = c - 48;
            }
        }
        for (int j = 0; j < 9; j++) {
            if (c == string_numbers[j][possible_find[j]]) {     // does c match next symbol in string?
                possible_find[j] += 1;                          // does match
            } else {                                            // does not match
                if (c == string_numbers[j][0]) { //             // is c the start of a new string of the same type?
                    possible_find[j] = 1;                   
                } else {
                    possible_find[j] = 0;
                }
            }
            if (possible_find[j] == number_string_length[j]) {
                possible_find[j] = 0;
                last_digit = j+1;
                if (first_digit == 0) {
                    first_digit = j+1;
                }
            }
        }
        if (c == 10) {
            sprintf_s(outputstring, "%i%i\n", first_digit, last_digit);
            printf(outputstring);
            sum += first_digit * 10;
            sum += last_digit;
            first_digit = 0;
        }
    }
    sprintf_s(outputstring, "sum: %i \nPress any button to close.", sum);
    printf(outputstring);
    c = getchar();
    return 0;
}