#include "ReverseInteger.h"
#include <limits>
//#include <exception>
using namespace std;

int ReverseInteger::reverse(int x)
{

    if (x == INT_MIN) return 0;
    if (x < 0) return -1*reverse(x*-1);
    int ans = 0;
    while (true) {
        if (abs(ans) > INT_MAX / 10) return 0;
        ans = ans * 10 + x % 10;
        x = x / 10;
        if (x == 0) break;
    }
    return ans;
}
