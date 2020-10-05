#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *CESAR_ENCRYPT_OPTION = "-encrypt_cesar";
const char *CESAR_DENCRYPT_OPTION = "-dencrypt_cesar";
const char *MATH_ENCRYPT_OPTION = "-dencrypt_math";
const char *MATH_DENCRYPT_OPTION = "-dencrypt_math";

const int CSR_ENCRYPT_STEPS = 6;

const int ASCII_CHARACTERS_LENGTH = 26;

const int ASCII_INTERVAL_START_FOR_LOWERCASE_LETTERS = 97;
const int ASCII_INTERVAL_END_FOR_LOWERCASE_LETTERS = 122;

const int ASCII_INTERVAL_START_FOR_UPPERCASE_LETTERS = 65;
const int ASCII_INTERVAL_END_FOR_UPPERCASE_LETTERS = 90;

void CSR_encrypt(char *value)
{
    int index = 0;
    char newEncryptedValue[255];
    for (char *key = value; *key; ++key)
    {
        int asciiKey = (int)*key;
        int encryptedKey = asciiKey + CSR_ENCRYPT_STEPS;
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

void CSR_dencrypt(char *value)
{
    int index = 0;
    char newDecryptedValue[255];
    for (char *key = value; *key; ++key)
    {
        int asciiKey = (int)*key;
        int encryptedKey = asciiKey - CSR_ENCRYPT_STEPS;
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

//compile code using command: gcc -o runme main.c && ./runme -encrypt_cesar text_to_encryption
int main(int argc, char *argv[])
{
    char *prog = argv[0];
    char *opts = argv[1];
    char *mesg = argv[2];

    _Bool encrypt_option_exist = strcmp(opts, CESAR_ENCRYPT_OPTION) == 0;
    _Bool dencrypt_option_exist = strcmp(opts, CESAR_DENCRYPT_OPTION) == 0;

    if (argc == 1)
    {
        fprintf(stderr, "%s: no option and message\n", prog);
        exit(5);
    }

    if (!(encrypt_option_exist || dencrypt_option_exist))
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
        if (encrypt_option_exist)
        {
            printf("Encrypt function start.\n\n");
            CSR_encrypt(mesg);
        }
        else if (dencrypt_option_exist)
        {
            printf("Dencrypt function start.\n\n");
            CSR_dencrypt(mesg);
        }
        else
        {
            fprintf(stderr, "%s: no such option: %s\n", prog, opts);
            exit(2);
        }
    }

    if (argc >= 4 && (encrypt_option_exist || dencrypt_option_exist))
    {
        printf("To many strings\n");
        exit(1);
    }

    exit(0);
}