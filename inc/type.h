#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 100
#define MAX_DATA_VALID 10

enum pattern_type {
    pattern_invalid = 10,
    pattern_first = 11,
    pattern_second = 12,
    pattern_third = 13,
    pattern_fourth = 14,
    pattern_fifth = 15,
    pattern_sixth = 16,
    pattern_seventh = 17,
    pattern_eighth = 18,
    pattern_nineth = 19
};

enum input_type {
    input_invalid = 0,
    input_digit = 1,
    input_space_or_tab = 2,
    input_char = 3
};

enum input_type digitCheck(char* d_check);
int validCheck(char* v_check);
int starPrint(enum pattern_type pattern, int line);
enum pattern_type selectMenu();
void sig_int();