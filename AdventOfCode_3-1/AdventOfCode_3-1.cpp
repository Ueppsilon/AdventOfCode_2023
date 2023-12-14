#include <stdio.h>
#include <string.h>
#include <math.h>


int find_number(int* digits, char* line, int index);
void find_digits(int* digits, char* line, int index);

int main()
{
    FILE* fptr;
    char line[200];
    char outputstring[100];
    int digits = 1;
    int number = 0;
    int sum = 0;

    fopen_s(&fptr, "3_example.txt", "r");
    //fopen_s(&fptr, "3_inputdata.txt", "r");

    int line_number = 0;
    while (fgets(line, 200, fptr) != NULL) {
        line_number++;
        int i = 0;        
        while (i < strlen(line)) {

            number = 0;
            if (line[i] > 47 && line[i] < 58) {
                number = find_number(&digits, line, i);

            }


            i += digits;
            i++;
        }
        sum += 1;
    }

    sprintf_s(outputstring, "sum: %i \nPress any button to close.", sum);
    printf(outputstring);
    int c = getchar();
    return 0;
}

int find_number(int* digits, char* line, int index) {
    find_digits(digits, line, index);
    int number = 0;
    for (int i = 0; i < *digits; i++) {
        number += (line[index + i] - 48) * pow(10, (double)(*digits - i - 1));
    }
    return number;
}

void find_digits(int* digits, char* line, int index) {
    if (line[index] > 47 && line[index] < 58) {
        *digits += 1;
        find_digits(digits, line, index + 1);
    }
}