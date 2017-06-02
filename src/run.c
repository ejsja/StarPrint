#include "type.h"

int starPrint(enum pattern_type pattern, int line)
{
    int i, j;
    int mid = line / 2;
    int starCnt = 1;
    int spaceCnt = line - 1;
    int printCnt = 0;
    int loopCnt = line + spaceCnt;
    int randomSelect = 0;
    int selectedIndex[MAX_INPUT_LENGTH] = {0};

    if (pattern == pattern_first)
    {
        while (printCnt++ != line)
        {
            for (i = 0 ; i < printCnt ; i++)
                printf("*");
            printf("\n");
        }
    }
    else if (pattern == pattern_second)
    {
        while (printCnt++ != line)
        {
            for (i = line ; i > printCnt - 1 ; i--)
                printf("*");
            printf("\n");
        }
    }
    else if ((pattern == pattern_third) && (line % 2 == 1))
    {
        spaceCnt = mid ;
        for (i = 0 ; i < line ; i++)
        {
            for (j = 0 ; j < spaceCnt ; j++)
                printf(" ");
            for (j = 0 ; j < line - (abs(mid - i) * 2) ; j++)
                printf("*");
            printf("\n");
            if (i < mid)
                spaceCnt--;
            else
                spaceCnt++;
        }
    }
    else if (pattern == pattern_fourth)
    {
        for (i = 0 ; i < line ; i++)
        {
            for (j = 0 ; j < loopCnt ; j++)
            {
                if (j < spaceCnt)
                    printf(" ");
                else if ((j >= spaceCnt) && (starCnt++ < (line + 1)))
                    printf("*");
            }
            printf("\n");
            starCnt = 1;
            spaceCnt--;
        }
    }
    else if (pattern == pattern_fifth)
                                            {
        for (i = 0 ; i < line ; i++)
        {
            for (j = 0 ; j < loopCnt ; j++)
            {
                if (j < spaceCnt)
                    printf(" ");
                else if (starCnt++ < (line + 1))
                    printf("*");
            }
            printf("\n");
            starCnt = i + 2;
            spaceCnt--;
        }
    }
    else if (pattern == pattern_sixth)
    {
        for (i = 0 ; i < line ; i++)
        {
            for (j = 0 ; j < line ; j++)
            {
                if (j < spaceCnt)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
            spaceCnt--;
        }
    }
    else if (pattern == pattern_seventh)
    {
        for (i = 0 ; i < line ; i++)
        {
            starPrint(pattern_first, starCnt);
            printf("\n");
            starCnt++;
        }
    }
    else if (pattern == pattern_eighth)
    {
        loopCnt = line + 1;
        while (printCnt != line)
        {
            for (i = 0 ; i < line ; i++)
            {
                if (i < printCnt)
                {
                    for (j = 0 ; j < loopCnt ; j++)
                        printf(" ");
                }
                else
                {
                    for (j = 0 ; j < loopCnt ; j++)
                    {
                        if (j < starCnt)
                            printf("*");
                        else
                            printf(" ");
                    }
                }
            }
            printf("\n");
            starCnt++;
            printCnt++;
        }
    }
    else if (pattern == pattern_nineth)
    {
        srand(time(NULL));
        while (printCnt != line)
        {
            randomSelect = (rand() % line) + 1;
            if(!selectedIndex[randomSelect])
            {
                starPrint(pattern_first, randomSelect);
                printf("\n");
                selectedIndex[randomSelect] = 1;
                printCnt++;
            }
        }
    }
    else
    {
        printf("Invalid input - Range 1..99 (ODD NUMBER)\n");
        return 0;
    }
    return 1;
}
            