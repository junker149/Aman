#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int validate_1(string key);
// int validate_2(string key);
int validate_3(string key);

void subs(string, string);

int main(int argc, string argv[])
{
    // Validate the key
    if (argc != 2)
    {
        printf("usage: ./substitution key\n");
        return 1;
    }

    // To check length of the key
    int l = strlen(argv[1]);
    if (l != 26)
    {
        return 1;
    }

    // To check every character is alphabet in key
    for (int i = 0; i < l; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            return 1;
        }
        for (int j = 0; j < i; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                // Will return 1 if there is an error
                return 1;
            }
        }
    }

    // Get the plain text
    string text = get_string("plaintext: ");

    subs(argv[1], text);
}

int validate_3(string key)
{
    // To check if there is any repetition
    int l = strlen(key);
    int n = 1;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                // Will return 1 if there is an error
                n = 1;
                break;
            }
            else
            {
                n = 0;
            }
        }
    }
    return n;
}

void subs(string key, string text)
{
    // Get the index of every letter in plain text
    int index;
    string e_text;
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        index = toupper(text[i]) - 65;
        if (text[i] >= 97 && text[i] <= 122)
        {
            printf("%c", tolower(key[index]));
        }
        else if (text[i] >= 65 && text[i] <= 90)
        {
            printf("%c", toupper(key[index]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
