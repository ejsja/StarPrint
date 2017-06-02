#include "type.h"

int main(void)
{
    enum pattern_type menuFlag;
    int lineNum;

    signal(SIGINT, sig_int);

    while (1)
    {
        menuFlag = selectMenu();
        lineNum = selectLine();
        starPrint(menuFlag, lineNum);
    }
    return 0;
}

void sig_int()
{
    printf("\nThank You !\n");
    exit(0);
}