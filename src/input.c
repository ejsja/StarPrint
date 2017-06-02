#include "type.h"

enum pattern_type selectMenu()
{
    int menuNum = 0;
    int menuValid = 0;
    char inputMenu[MAX_INPUT_LENGTH] = "\0";

    while(1)
    {
        printf("========================================\n");
        printf("Pattern 1.\n");
        starPrint(pattern_first, 5);
        printf("\nPattern 2.\n");
        starPrint(pattern_second, 5);
        printf("\nPattern 3.\n");
        starPrint(pattern_third, 5);
        printf("\nPattern 4.\n");
        starPrint(pattern_fourth, 5);
        printf("\nPattern 5.\n");
        starPrint(pattern_fifth, 5);
        printf("\nPattern 6.\n");
        starPrint(pattern_sixth, 5);
        printf("\nPattern 7.\n");
        starPrint(pattern_seventh, 5);
        printf("\nPattern 8.\n");
        starPrint(pattern_eighth, 5);
        printf("\nPattern 9.\n");
        starPrint(pattern_nineth, 5);
        printf("\n========================================\n");
        printf("Select Pattern (1 ~ 9) ");
        scanf("%100[^\n]", inputMenu);
 menuValid = validCheck(inputMenu);

        if (menuValid)
            menuNum = atoi(inputMenu);

        while (getchar() != '\n');
        memset(inputMenu, '\0', MAX_INPUT_LENGTH);

        if (menuNum < 1 || menuNum > 9)
            printf("Invalid input - Range 1..9\n\n");
        else
            switch(menuNum)
            {
                case 1 : return pattern_first; break;
                case 2 : return pattern_second; break;
                case 3 : return pattern_third; break;
                case 4 : return pattern_fourth; break;
                case 5 : return pattern_fifth; break;
                case 6 : return pattern_sixth; break;
                case 7 : return pattern_seventh; break;
                case 8 : return pattern_eighth; break;
                case 9 : return pattern_nineth; break;
                default : printf("Invalid menuNum : %d\n", menuNum);
                        return pattern_invalid; break;
            }
    }
}

int selectLine()
{
    int lineNum = 0;
    int inputValid = 0;
    char inputLine[MAX_INPUT_LENGTH] = "\0";

    while(1)
    {
        printf("How many lines ? (1..100) ");
        scanf("%100[^\n]", inputLine);

        inputValid = validCheck(inputLine);

        if (inputValid)
            lineNum = atoi(inputLine);

        while (getchar() != '\n');
        memset(inputLine, '\0', MAX_INPUT_LENGTH);

        if (lineNum < 1 || lineNum > 100)
            printf("Invalid input - Range 1..100 \n");
        else
            return lineNum;
    }
}


enum input_type digitCheck(char* d_check)
{
    if ((*d_check >= '0') && (*d_check <= '9'))
        return input_digit;
    else if (*d_check == ' ' || *d_check == '\t')
        return input_space_or_tab;
    else if (*d_check != '\0')
        return input_char;
    else
        return input_invalid;
}

int validCheck(char* v_check)
{
    char* checkInput = v_check;
    int dataLength = 1;

    do
    {
        if (digitCheck(checkInput) == input_space_or_tab)
        {
            if (digitCheck(checkInput + 1) == input_char)
                return 0;
            else if ((dataLength > 1) && (digitCheck(checkInput - 1) == input_digit)) //공백 앞에 숫자가 있을 시
            {
                while (*checkInput++ != '\0') //공백 뒤로 문자나 숫자가 있을 시의 체크
                {
                    if (digitCheck(checkInput) == input_digit || digitCheck(checkInput) == input_char)
                        return 0;
                }
            }
        }
        else if (digitCheck(checkInput) == input_char)
            return 0;
        else
            dataLength++;
    }while (*checkInput++ != '\0');

    if(dataLength < MAX_DATA_VALID && *v_check != '\0')
        return 1;
    else
        return 0;
}
      