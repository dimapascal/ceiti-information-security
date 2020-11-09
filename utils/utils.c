#include <time.h>
#include <stdio.h>
#include <string.h>

void logMessage(char *message, int itemsCount)
{
    printf("result: ");
    for (int index = 0; index < itemsCount; index++)
        printf("%c", message[index]);
    printf("\n");
}

int getCurrentDayInWeek()
{
    struct tm time;
    memset(&time, 0, sizeof(time));
    mktime(&time);
    return time.tm_wday + 1;
}
