#include <stdio.h>
#include <string.h>
#include <math.h>

FILE* fptr;
char line[100];
char outputstring[100];
int c = 0;
int rgb_count[10][3] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
int digits = 1;
char type = 0;
int GameID = 0;
int number = 0;
int sum = 0;

int find_number(int* digits, char* line, int index);
void find_digits(int* digits, char* line, int index);

int main()
{
    //fopen_s(&fptr, "2_example.txt", "r");
    fopen_s(&fptr, "2_inputdata.txt", "r");
    int turnID = 0;
    int line_number = 0;

    while (fgets(line, 200, fptr) != NULL) {
        line_number++;
        int i = 0;
        int gameValid = 0;
        turnID = 0;
        int power = 0;
        int rgb_count[10][3] = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
        while (i < strlen(line)) {
            digits = 0;
            type = 0;
            number = 0;
            if (line[i] > 47 && line[i] < 58) {
                number = find_number(&digits, line, i);
                switch (line[i + digits]) {
                case ':':
                    GameID = number;
                    break;
                case ' ':
                    switch (line[i + digits + 1]) {
                    case 'r':
                        rgb_count[turnID][0] = number;
                        if (number > 12) {
                            gameValid = 1;
                        }
                        break;
                    case 'g':
                        rgb_count[turnID][1] = number;
                        if (number > 13) {
                            gameValid = 1;
                        }
                        break;
                    case 'b':
                        rgb_count[turnID][2] = number;
                        if (number > 14) {
                            gameValid = 1;
                        }
                        break;
                    default:
                        break;
                    }
                default:
                    break;
                }
            }
            if (line[i] == ';') {
                turnID++;
            }
            i += digits;
            i++;
        }

        // find minima for every color
        int r_max = 0;
        int g_max = 0;
        int b_max = 0;
        for (int i = 0; i < 10; i++) {
            if (rgb_count[i][0] > r_max) {
                r_max = rgb_count[i][0];
            }
            if (rgb_count[i][1] > g_max) {
                g_max = rgb_count[i][1];
            }
            if (rgb_count[i][2] > b_max) {
                b_max = rgb_count[i][2];
            }
        }
        sprintf_s(outputstring, "r:%i, g:%i, b:%i, power: %i\n", r_max, g_max, b_max, r_max*g_max*b_max);
        printf(outputstring);
        sum += r_max*g_max*b_max;
    }

    sprintf_s(outputstring, "sum: %i \nPress any button to close.", sum);
    printf(outputstring);
    c = getchar();
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