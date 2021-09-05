#include "Lps.h"

using namespace std;

std::string Lps::longestPalindrome(std::string s)
{
    int l = s.length();
    //check for palindrome with odd length ie. have a center;
    int  ccount=0, cmax = 0, cmaxat;
    for (int i = 0; i < l; i++) {
        ccount = 0;
        for (int j = 1; j <= min(i, l - i-1); j++) {
            if (s[i - j] == s[i + j]) {
                if (++ccount > cmax) {
                    cmax = ccount;
                    cmaxat = i;
                }
            }
            else {
                break;
            }
        }
    }
    //check for palindrome w/o center
    int dcount=0, dmax = 0, dmaxat;
    if (l >= 2) {
        for (int i = 0; i < l - 1; i++) {
            if (s[i] == s[i + 1]) {
                dcount = 1;
                if (dmax == 0) {
                    dmax = 1;
                    dmaxat = i;
                }
                for (int j = 1; j <= min(i, l - i - 2); j++) {
                    if (s[i - j] == s[i + j + 1]) {
                        if (++dcount > dmax) {
                            dmax = dcount;
                            dmaxat = i;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    if (cmax == 0 && dmax ==0) return s.substr(0, 1);
    return (cmax * 2 + 1 > dmax * 2) ?
        s.substr(cmaxat - cmax, cmax *2+1) :
        s.substr(dmaxat - dmax+1, dmax *2);

    return std::string();
}
