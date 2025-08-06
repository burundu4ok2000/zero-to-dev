#include <cs50.h>
#include <stdio.h>

void print_hashes(int length);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    print_hashes(height);
}

void print_hashes(int max_row)
{
    int whtspce;
    int row = 1;

    while (row <= max_row)
    {
        // start creating a left half of the pyramid
        whtspce = max_row - row;
        for (int i = whtspce; i > 0; i--)
        {
            printf(" ");
        }
        for (int i = row; i > 0; i--)
        {
            printf("#");
        }
        // end of the creating left half of the pyramid

        // creating a gap between pyramyds
        printf("  ");

        // start creating a right half of the pyramid
        for (int i = row; i > 0; i--)
        {
            printf("#");
        }
        // end creating a right half of the pyramid

        printf("\n");

        row++;
    }
}
