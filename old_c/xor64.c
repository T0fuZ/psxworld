/// Cryptological System 64-XOR 2003(C) By Leone Viru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRYPTO_TABLE 64  // cryption table 64 bytes, 8*8 matrix.
#define PARAMETERS 5     // five parameters from the user.
#define KEY_LENGHT 8

int main(int argc, char *argv[])
{
    // define variables
    int i, j;
    register int temp;
    char cryption_table[CRYPTO_TABLE];
    char key_A[9];
    char key_B[9];
    FILE *in_file;
    FILE *out_file;

    // program start
    if (argc == PARAMETERS)
    {
        // argv[1] - infile.
        in_file = fopen(argv[1], "rb");
        if (in_file == NULL)
        {
            printf("Input file not found.\n");
            exit(1);
        }

        out_file = fopen(argv[2], "wb");
        if (out_file == NULL)
        {
            printf("Can't create the Output file.\n");
            exit(1);
        }

        if ((strlen(argv[3]) == KEY_LENGHT))
        {
            strcpy(key_A, argv[3]);
        }
        else
        {
            printf("Key A doesn't contain 8 characters\n");
            exit(0);
        }

        if ((strlen(argv[4]) == KEY_LENGHT))
        {
            strcpy(key_B, argv[4]);
        }
        else
        {
            printf("Key B doesn't contain 8 characters\n");
            exit(0);
        }

        // create the encryption table.
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                cryption_table[i * 8 + j] = key_A[i] ^ key_B[j];
            }
        }

        // and into coding.
        i = 0;
        while ((temp = getc(in_file)) != EOF)
        {
            temp = cryption_table[i] ^ temp;
            putc((temp), out_file);
            i++;
            if (i == CRYPTO_TABLE)
                i = i - CRYPTO_TABLE;
        }

        printf("Cryption completed successfully.\n");
    }
    else
    {
        printf("----------------------------------------------------------\n");
        printf(" Cryptological System XOR64 V1.2 Beta 2003 By Leone Viru(C)\n");
        printf("----------------------------------------------------------\n\n");
        printf(" Usage: cryptic in_file out_file key_A key_B\n");
        printf(" Consult Cryptic.txt for more detailed information.\n");
    }

    return 0;
}
