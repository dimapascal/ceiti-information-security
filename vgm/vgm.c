#include <stdio.h>
#include <string.h>
#include "../vars/vars.h"
#include "../utils/utils.h"

void VGM_encrypt(char *message)
{
    char encrMessage[25], encrKey[25] = "";
    int firstIndex, secondIndex, encrKeyCount = 0;
    int resultMessageAlphabetIndex, messageAlphabeticIndex, encrKeyAlphabeticIndex;
    int seed = getCurrentDayInWeek();

    printf("encryption key: ");
    scanf("%s", encrKey);

    for (firstIndex = 0; firstIndex < strlen(message); firstIndex++)
    {
        for (secondIndex = 0; secondIndex < strlen(FULL_ALPHABET); secondIndex++)
        {
            if (message[firstIndex] == FULL_ALPHABET[secondIndex])
                messageAlphabeticIndex = secondIndex;
            if (encrKey[encrKeyCount] == FULL_ALPHABET[secondIndex])
                encrKeyAlphabeticIndex = secondIndex;
        }

        resultMessageAlphabetIndex = (encrKeyAlphabeticIndex + messageAlphabeticIndex + seed) % strlen(FULL_ALPHABET);

        encrMessage[firstIndex] = FULL_ALPHABET[resultMessageAlphabetIndex];

        if (encrKeyCount == strlen(encrKey) - 1)
            encrKeyCount = 0;
        else
            encrKeyCount += 1;
    }

    logMessage(encrMessage, strlen(message));
    printf("day in week: %i\n", seed);
}

void VGM_dencrypt(char *message)
{
    char encrMessage[25], encrKey[25] = "";
    int firstIndex, secondIndex, encrKeyCount = 0;
    int resultMessageAlphabetIndex, messageAlphabeticIndex, encrKeyAlphabeticIndex;
    int seed = getCurrentDayInWeek();

    printf("encryption key: ");
    scanf("%s", encrKey);

    for (firstIndex = 0; firstIndex < strlen(message); firstIndex++)
    {
        for (secondIndex = 0; secondIndex < strlen(FULL_ALPHABET); secondIndex++)
        {
            if (message[firstIndex] == FULL_ALPHABET[secondIndex])
                messageAlphabeticIndex = secondIndex;
            if (encrKey[encrKeyCount] == FULL_ALPHABET[secondIndex])
                encrKeyAlphabeticIndex = secondIndex;
        }

        resultMessageAlphabetIndex = (messageAlphabeticIndex - encrKeyAlphabeticIndex - seed);
        if (resultMessageAlphabetIndex < 0)
            resultMessageAlphabetIndex += strlen(FULL_ALPHABET);

        encrMessage[firstIndex] = FULL_ALPHABET[resultMessageAlphabetIndex];

        if (encrKeyCount == strlen(encrKey) - 1)
            encrKeyCount = 0;
        else
            encrKeyCount += 1;
    }

    logMessage(encrMessage, strlen(message));
    printf("day in week: %i\n", seed);
}