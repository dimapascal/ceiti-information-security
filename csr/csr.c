#include <stdio.h>
#include <string.h>
#include "../vars/vars.h"

void CSR_encrypt(char *mesg)
{
    int index = 0, csr_encrypt_step;
    char newEncryptedValue[255];

    printf("pas: ");
    scanf("%i", &csr_encrypt_step);

    for (char *key = mesg; *key; ++key)
    {
        int asciiKey = (int)*key;
        int encryptedKey = asciiKey + csr_encrypt_step;
        if (ASCII_INTERVAL_START_FOR_LOWERCASE_LETTERS <= asciiKey && asciiKey <= ASCII_INTERVAL_END_FOR_LOWERCASE_LETTERS)
        {
            if (encryptedKey > ASCII_INTERVAL_END_FOR_LOWERCASE_LETTERS)
                encryptedKey -= ASCII_CHARACTERS_LENGTH;
            newEncryptedValue[index] = (char)encryptedKey;
        }
        else if (ASCII_INTERVAL_START_FOR_UPPERCASE_LETTERS <= asciiKey && asciiKey <= ASCII_INTERVAL_END_FOR_UPPERCASE_LETTERS)
        {
            if (encryptedKey > ASCII_INTERVAL_END_FOR_UPPERCASE_LETTERS)
                encryptedKey -= ASCII_CHARACTERS_LENGTH;
            newEncryptedValue[index] = (char)encryptedKey;
        }
        else
            newEncryptedValue[index] = (char)asciiKey;

        index++;
    }
    printf("Encrypt function result: \"%s\"\n", newEncryptedValue);
}

void CSR_dencrypt(char *mesg)
{
    int index = 0, csr_encrypt_step;
    char newDecryptedValue[255];

    printf("pas: ");
    scanf("%i", &csr_encrypt_step);

    for (char *key = mesg; *key; ++key)
    {
        int asciiKey = (int)*key;
        int encryptedKey = asciiKey - csr_encrypt_step;
        if (ASCII_INTERVAL_START_FOR_LOWERCASE_LETTERS <= asciiKey && asciiKey <= ASCII_INTERVAL_END_FOR_LOWERCASE_LETTERS)
        {
            if (encryptedKey < ASCII_INTERVAL_START_FOR_LOWERCASE_LETTERS)
                encryptedKey += ASCII_CHARACTERS_LENGTH;
            newDecryptedValue[index] = (char)encryptedKey;
        }
        else if (ASCII_INTERVAL_START_FOR_UPPERCASE_LETTERS <= asciiKey && asciiKey <= ASCII_INTERVAL_END_FOR_UPPERCASE_LETTERS)
        {
            if (encryptedKey < ASCII_INTERVAL_START_FOR_UPPERCASE_LETTERS)
                encryptedKey += ASCII_CHARACTERS_LENGTH;
            newDecryptedValue[index] = (char)encryptedKey;
        }
        else
        {
            newDecryptedValue[index] = (char)asciiKey;
        }
        index++;
    }
    printf("Dencryption function result: \"%s\"\n", newDecryptedValue);
}

void MATH_encrypt(char *mesg)
{
    char enc[25];
    int pas, i, j, k;

    printf("pas: ");
    scanf("%i", &pas);

    for (i = 0; i < strlen(mesg); i++)
        for (j = 0; j < strlen(ALPHABET); j++)
            if (mesg[i] == ALPHABET[j])
            {
                k = (j + pas) % strlen(ALPHABET);
                enc[i] = ALPHABET[k];
            }

    printf("enc: ");
    for (i = 0; i < strlen(mesg); i++)
        printf("%c", enc[i]);
    printf("\n");
}

void MATH_dencrypt(char *mesg)
{
    char enc[25];
    int pas, i, j, k;

    printf("pas: ");
    scanf("%i", &pas);

    for (i = 0; i < strlen(mesg); i++)
        for (j = 0; j < strlen(ALPHABET); j++)
            if (mesg[i] == ALPHABET[j])
            {
                k = (j - pas) % strlen(ALPHABET);
                enc[i] = ALPHABET[k];
            }

    printf("den: ");
    for (i = 0; i < strlen(mesg); i++)
        printf("%c", enc[i]);
    printf("\n");
}
