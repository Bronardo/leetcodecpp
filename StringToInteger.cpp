#include "StringToInteger.h"

int StringToInteger::myAtoi(std::string s)
{
    int state = 0;
    //0 trim
    //1 read sign
    //2 read number
    int ans = 0; bool sign =true;
    int i = 0,size =s.size();
    if (size == 0) return 0;
    while (true) {
        if (!isblank(s[i])) {
            break;
        }
        if (++i >= size) return 0;
    }

    if (s[i] == '-') {
        sign = false;
        i++;
    }
    else if (s[i] == '+') {
        i++;
    }
    if (i >= size) return 0;

    while (true) {
        if (isdigit(s[i])) {
            if (sign) {
                if (ans > INT_MAX / 10) return INT_MAX;
                if (INT_MAX - ans * 10 - s[i] + '0' < 0) return INT_MAX;
                ans = s[i] - '0' + ans * 10;
                if (++i >= size) break;
            }
            else {
                if (ans < INT_MIN / 10) return INT_MIN;
                if (INT_MIN - ans * 10 + s[i] - '0' > 0) return INT_MIN;
                ans = ans * 10 - s[i] + '0';
                if (++i >= size) break;
            }

        }
        else break;
    }
    return ans;
    //if (ans > INT_MAX / 10)
//    return sign ? INT_MAX : INT_MIN;
//ans = s[i] - '0' + ans * 10;
//if (++i >= size) break;
// 
    //while (i<size) {
    //    switch (state) {
    //    case 0://trim
    //        while (true) {
    //            if (!isblank(s[i])) {
    //                state = 1;
    //                break;
    //            }
    //            if (++i >= size) return 0;
    //        }
    //        break;
    //    case 1://read sign
    //        if (s[i] == '-') {
    //            sign = false;
    //            i++;
    //        }
    //        else if (s[i] == '+') {
    //            i++;
    //        }
    //        if (i >= size) return 0;
    //        state = 2;
    //        break;
    //    case 2:
    //        if (isdigit(s[i])) {
    //            if (ans > INT_MAX / 10) 
    //                return sign ? INT_MAX : INT_MIN;
    //            ans = ans * 10 + s[i]-'0';
    //            i++;
    //        }

    //    }
    //}
    
    return sign ? ans: -ans;
}
