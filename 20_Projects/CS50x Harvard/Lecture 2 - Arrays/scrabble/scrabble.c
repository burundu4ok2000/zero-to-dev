#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int letter_score(char);

int main(void)
{
    int p1_score = 0;
    int p2_score = 0;

    // get inputs from the user
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    // calculate length of this words
    int p1_len = strlen(p1);
    int p2_len = strlen(p2);

    // calculate player 1 score
    for (int i = 0; i < p1_len; i++)
    {
        p1_score += letter_score(p1[i]);
    }

    // calculate player 2 score
    for (int i = 0; i < p2_len; i++)
    {
        p2_score += letter_score(p2[i]);
    }

    // compare and print the result
    if (p2_score > p1_score)
    {
        printf("Player 2 wins!\n");
    }

    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }

    if (p2_score == p1_score)
    {
        printf("Tie!\n");
    }
}

int letter_score(char letter)
{
    // check if letter is uppercase, if not, make it uppercase
    if (isupper(letter) == 0)
    {
        letter = toupper(letter);
    }

    // return a value of the letter
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' ||
        letter == 'O' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U')
    {
        return 1;
    }

    if (letter == 'D' || letter == 'G')
    {
        return 2;
    }

    if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
    {
        return 3;
    }

    if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
    {
        return 4;
    }

    if (letter == 'K')
    {
        return 5;
    }

    if (letter == 'J' || letter == 'X')
    {
        return 8;
    }

    if (letter == 'Q' || letter == 'Z')
    {
        return 10;
    }
    else
    {
        return 0;
    }
}
