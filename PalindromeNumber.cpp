#include "PalindromeNumber.h"
#include <math.h>

bool PalindromeNumber::isPalindrome(int x)
{
    int a = x, c = 0;
    if (a < 0) return false;
    while (a > 0) {
        c++;
        a /= 10;
    }
    while (c>0) {
        if(
            x%10
            !=
            x/(int)(pow(10.0, (double)(c-1)))
        ) return false;
        x = x % (int)(pow(10.0, (double)(c-- - 1)));
        x = x / 10;
        c -= 2;
    }
    return true;
}
