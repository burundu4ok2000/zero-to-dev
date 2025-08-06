#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool key_check(int argc, string key);
void encryption(string text, string key);

int main(int argc, string argv[])
{
    if (key_check(argc, argv[1]) == false)
    {
        return 1;
    }

    string text = get_string("plaintext: ");

    encryption(text, argv[1]);

    printf("ciphertext: %s\n", text);
}

bool key_check(int argc, string key)
{
    // checking duplicates in user prompt array[]
    bool seen[26];

    // check if user is not prompting anything
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    if (argc > 2)
    {
        printf("Too many arguments\nUsage: ./substitution key\n");
        return false;
    }

    // check if there is 26 digits
    if (strlen(key) != 26)
    {
        // tell user that the key must be 26 digits length
        printf("Key must contain 26 characters.\n");
        return false;
    }

    memset(seen, false, sizeof(26));

    // check
    for (int i = 0, n = 0; i < 26; i++)
    {
        if (isalpha(key[i]) != 0)
        {
            if (islower(key[i]) != 0)
            {
                key[i] = toupper(key[i]);
            }

            n = key[i] - 'A';

            if (seen[n] == true)
            {
                printf("Key must not contain duplicate characters\n");
                return false;
            }
            else
            {
                seen[n] = true;
            }
        }
        else
        {
            printf("Key must contain alphabetical characters only\n");
            return false;
        }
    }
    return true;
}

void encryption(string text, string key)
{
    int length = strlen(text);

    for (int i = 0, n = 0; i < length; i++)
    {
        if (isupper(text[i]) != 0)
        {
            // loop for uppercase letter

            n = text[i] - 'A';

            text[i] = key[n];
        }
        else if (islower(text[i]) != 0)
        {
            // loop for lowercase letter
            n = text[i] - 'a';

            text[i] = tolower(key[n]);
        }
    }
}
