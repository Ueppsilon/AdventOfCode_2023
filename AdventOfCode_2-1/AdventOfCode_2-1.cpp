#include <stdio.h>
#include <string.h>

FILE* fptr;
char line[100];
char outputstring[100];
int c = 0;
int count_red = 0;
int count_green = 0;
int count_blue = 0;

int main()
{
    fopen_s(&fptr, "2_example.txt", "r");
    //fopen_s(&fptr, "2_inputdata.txt", "r");

    fgets(line, 100, fptr);
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] > 47 && line[i] < 58) {
            
        }
    
    }

    //sprintf_s(outputstring, "sum: %i \nPress any button to close.", sum);
    printf(outputstring);

    fgets(outputstring, 100, fptr);
    printf(outputstring);
    
    fgets(outputstring, 100, fptr);
    printf(outputstring);
    fgets(outputstring, 100, fptr);
    printf(outputstring);
    fgets(outputstring, 100, fptr);
    printf(outputstring);
    c = getchar();
    return 0;
}