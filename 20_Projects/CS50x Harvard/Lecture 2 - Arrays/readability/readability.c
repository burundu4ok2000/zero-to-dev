#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Ptototypes
float letters_func(float length, string array);
float words_func(float length, string array);
float sentences_func(float length, string array);

int main(void)
{
    string text = get_string("Text: ");

    int text_length = strlen(text);

    float letters = letters_func(text_length, text);

    float words = words_func(text_length, text);

    float sentences = sentences_func(text_length, text);

    float L = letters / words * 100;

    float S = sentences / words * 100;

    float CL_index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(CL_index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float letters_func(float length, string array)
{
    float count = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(array[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

float words_func(float length, string array)
{
    float count = 0;

    for (int i = 0; i < length; i++)
    {
        if (isspace(array[i]) != 0)
        {
            count++;
        }
    }
    count++;
    return count;
}

float sentences_func(float length, string array)
{
    float count = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] == '!' || array[i] == '?' || array[i] == '.')
        {
            count++;
        }
    }
    return count;
}
