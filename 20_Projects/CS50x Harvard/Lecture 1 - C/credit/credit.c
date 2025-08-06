#include <cs50.h>
#include <stdio.h>

bool validate_luhn_algorithm(int num1, int num2, int num3, int num4, int num5, int num6, int num7,
                             int num8, int num9, int num10, int num11, int num12, int num13,
                             int num14, int num15, int num16);

int credit_card_length_checker(long number);

int main(void)
{
    // initializating credit cards digits
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14,
        num15, num16;

    //"ccn" is a credit card number

    long ccn = get_long("Number: ");

    int credit_card_length = credit_card_length_checker(ccn);

    if (credit_card_length < 0)
    {
        // end of the programm. Invalid ccn length

        printf("INVALID\n");
        return 0;
    }
    else
    {
        num1 = ccn % 10;
        num2 = ccn / 10 % 10;
        num3 = ccn / 100 % 10;
        num4 = ccn / 1000 % 10;
        num5 = ccn / 10000 % 10;
        num6 = ccn / 100000 % 10;
        num7 = ccn / 1000000 % 10;
        num8 = ccn / 10000000 % 10;
        num9 = ccn / 100000000 % 10;
        num10 = ccn / 1000000000 % 10;
        num11 = ccn / 10000000000 % 10;
        num12 = ccn / 100000000000 % 10;
        num13 = ccn / 1000000000000 % 10;
        num14 = ccn / 10000000000000 % 10;
        num15 = ccn / 100000000000000 % 10;
        num16 = ccn / 1000000000000000 % 10;

        // checking if VISA

        if ((credit_card_length == 16) && num16 == 4)
        {
            // checking Luhn’s Algorithm validation

            if (validate_luhn_algorithm(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
                                        num11, num12, num13, num14, num15, num16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            return 0;
        }

        // checking if VISA

        if ((credit_card_length == 13) && num13 == 4)
        {
            // final checking Luhn’s Algorithm validation

            if (validate_luhn_algorithm(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
                                        num11, num12, num13, num14, num15, num16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            return 0;
        }

        // checking if AMEX

        if ((credit_card_length == 15) &&
            (((num15 == 3) && (num14 == 4)) || ((num15 == 3) && (num14 == 7))))
        {
            // final checking Luhn’s Algorithm validation

            if (validate_luhn_algorithm(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
                                        num11, num12, num13, num14, num15, num16))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            return 0;
        }

        // checking if MASTERCARD

        if ((credit_card_length == 16) &&
            ((num16 == 5) &&
             ((num15 == 1) || (num15 == 2) || (num15 == 3) || (num15 == 4) || (num15 == 5))))
        {
            // final checking Luhn’s Algorithm validation

            if (validate_luhn_algorithm(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
                                        num11, num12, num13, num14, num15, num16))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
            return 0;
        }
        else
        {
            // end of the programm. Invalid ccn beginning

            printf("INVALID\n");
        }
    }
}

bool validate_luhn_algorithm(int num1, int num2, int num3, int num4, int num5, int num6, int num7,
                             int num8, int num9, int num10, int num11, int num12, int num13,
                             int num14, int num15, int num16)
{
    int checker;

    checker = (((num16 * 2 / 10) + (num16 * 2 % 10)) + ((num14 * 2 / 10) + (num14 * 2 % 10)) +
               ((num12 * 2 / 10) + (num12 * 2 % 10)) + ((num10 * 2 / 10) + (num10 * 2 % 10)) +
               ((num8 * 2 / 10) + (num8 * 2 % 10)) + ((num6 * 2 / 10) + (num6 * 2 % 10)) +
               ((num4 * 2 / 10) + (num4 * 2 % 10)) + ((num2 * 2 / 10) + (num2 * 2 % 10)) + num15 +
               num13 + num11 + num9 + num7 + num5 + num3 + num1);

    if ((checker % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int credit_card_length_checker(long number)
{
    if (number > 1000000000000 && number < 10000000000000)
    {
        return 13;
    }
    if (number > 100000000000000 && number < 1000000000000000)
    {
        return 15;
    }
    if (number > 1000000000000000 && number < 10000000000000000)
    {
        return 16;
    }
    else
    {
        return -1;
    }
}
