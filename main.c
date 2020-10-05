#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *CESAR_ENCRYPT_OPTION = "-encrypt_cesar";
const char *CESAR_DENCRYPT_OPTION = "-dencrypt_cesar";
const char *MATH_ENCRYPT_OPTION = "-encrypt_math";
const char *MATH_DENCRYPT_OPTION = "-dencrypt_math";

const int ASCII_CHARACTERS_LENGTH = 26;

const int ASCII_INTERVAL_START_FOR_LOWERCASE_LETTERS = 97;
const int ASCII_INTERVAL_END_FOR_LOWERCASE_LETTERS = 122;

const int ASCII_INTERVAL_START_FOR_UPPERCASE_LETTERS = 65;
const int ASCII_INTERVAL_END_FOR_UPPERCASE_LETTERS = 90;

const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";

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

//compile code using command: gcc -o runme main.c && ./runme -encrypt_cesar text_to_encryption
int main(int argc, char *argv[])
{
    char *prog = argv[0];
    char *opts = argv[1];
    char *mesg = argv[2];

    const _Bool cesar_encrypt_option_exist = strcmp(opts, CESAR_ENCRYPT_OPTION) == 0;
    const _Bool cesar_dencrypt_option_exist = strcmp(opts, CESAR_DENCRYPT_OPTION) == 0;
    const _Bool math_encrypt_option_exist = strcmp(opts, MATH_ENCRYPT_OPTION) == 0;
    const _Bool math_dencrypt_option_exist = strcmp(opts, MATH_DENCRYPT_OPTION) == 0;

    const _Bool anyOptionExist = cesar_encrypt_option_exist || cesar_dencrypt_option_exist || math_encrypt_option_exist || math_dencrypt_option_exist;

    if (argc == 1)
    {
        fprintf(stderr, "%s: no option and message\n", prog);
        exit(5);
    }

    if (!anyOptionExist)
    {
        printf("No option was provided\n");
        exit(4);
    }

    if (argc == 2)
    {
        exit(3);
        printf("No message\n");
    }

    if (argc == 3)
    {
        if (cesar_encrypt_option_exist)
            CSR_encrypt(mesg);
        else if (cesar_dencrypt_option_exist)
            CSR_dencrypt(mesg);
        else if (math_encrypt_option_exist)
            MATH_encrypt(mesg);
        else if (math_dencrypt_option_exist)
            MATH_dencrypt(mesg);
        else
        {
            fprintf(stderr, "%s: no such option: %s\n", prog, opts);
            exit(2);
        }
    }

    if (argc >= 4 && anyOptionExist)
    {
        printf("To many strings\n");
        exit(1);
    }

    exit(0);
}