#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vars/vars.h"
#include "csr/csr.h"
#include "vgn/vgn.h"
#include "vgm/vgm.h"

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
    const _Bool vgn_encrypt_option_exist = strcmp(opts, VGN_ENCRYPT_OPTION) == 0;
    const _Bool vgn_dencrypt_option_exist = strcmp(opts, VGN_DENCRYPT_OPTION) == 0;
    const _Bool vgm_encrypt_option_exist = strcmp(opts, VGM_ENCRYPT_OPTION) == 0;
    const _Bool vgm_dencrypt_option_exist = strcmp(opts, VGM_DENCRYPT_OPTION) == 0;

    const _Bool anyOptionExist = ((cesar_encrypt_option_exist || cesar_dencrypt_option_exist) ||
                                  (math_encrypt_option_exist || math_dencrypt_option_exist) ||
                                  (vgn_encrypt_option_exist || vgn_dencrypt_option_exist) ||
                                  (vgm_encrypt_option_exist || vgm_dencrypt_option_exist));

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
        else if (vgn_encrypt_option_exist)
            VGN_encrypt(mesg);
        else if (vgn_dencrypt_option_exist)
            VGN_dencrypt(mesg);
        else if (vgm_encrypt_option_exist)
            VGM_encrypt(mesg);
        else if (vgm_dencrypt_option_exist)
            VGM_dencrypt(mesg);
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