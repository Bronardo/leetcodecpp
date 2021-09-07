#include "RegularExpressionMatching.h"
using namespace std;

bool RegularExpressionMatching::isMatch(
    std::string s, std::string p)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    return solve(s, p, 0, 0, ' ', dp);
}

bool RegularExpressionMatching::solve(string& s, string& p, int i, int j, char prev, vector<vector<int>>& dp)
{

    if (dp[i][j] != -1) return dp[i][j];


    /* If next char in pattern is '*' then instead of processing currently, recurse for next pos of j */

    if (j + 1 < p.length() and p[j + 1] == '*')
        return dp[i][j] = solve(s, p, i, j + 1, p[j], dp);


    /* ----------------------- Base Cases -------------------------*/

    // --> Case 1 : if i reached at the end 

    if (i == s.length()) {

        /* If j also reached at the end return true */

        if (j == p.length()) return true;

        /* If curr is * then there is still chance to skip remaining pattern hence recurse for j+1 */

        else if (p[j] == '*')
            return dp[i][j] = solve(s, p, i, j + 1, '*', dp);

        /* Else return false */

        else return false;
    }

    // --> Case 2 :  If j reached at the end, and i didnt then directly return false

    else if (j == p.length()) return false;

    /* --------------------------------------------------------------*/


    /* If curr char is . or it matched current char of s then recurse for i+1 and j+1 */

    if (p[j] == '.' or p[j] == s[i])
        return dp[i][j] = solve(s, p, i + 1, j + 1, p[j], dp);


    else if (p[j] == '*') {

        /* if curr char is * then prev can be either . or any lowercase letter */

        if (prev == '.' or prev == s[i]) {

            /* Case1 :  Matching more then one element */

            bool res = solve(s, p, i + 1, j, prev, dp);

            /* Case2 : Matching exactly one element */

            bool res2 = solve(s, p, i + 1, j + 1, '*', dp);

            /* Case3 : Matching zero element with '*' */

            bool res3 = solve(s, p, i, j + 1, '*', dp);

            return dp[i][j] = res or res2 or res3;
        }

        /* If prev!=s[i] then only one case is left which is we will match 0 char with '*' */

        else {
            bool res = solve(s, p, i, j + 1, '*', dp);
            return dp[i][j] = res;
        }
    }
    return false;
}



//char match = NULL;
//bool repeat = false;
//int sp = 0, least = 0;
//for (int i = 0; i < p.size(); i++) {
//    repeat = false;
//    least = 0;
//    if (p[i] == '.') match = NULL;
//    else match = p[i];
//    while (i + 1 < p.size()) {
//        if (repeat) {
//            if (p[i + 1] == match) {
//                least++;
//                i++;
//            }
//            else if (p[i + 1] == '*') {
//                i++;
//            }
//            else break;
//        }
//        else {
//            if (p[i + 1] == '*') {
//                repeat = true;
//                i++;
//            }
//            else {
//                break;
//            }
//        }
//    }
//    if (sp >= s.size()) return false;
//    while (sp < s.size()) {
//        if (match != NULL) {
//            if (s[sp] != match) {
//                if (repeat) break;
//                return false;
//            }
//            else {
//                if (repeat && least > 0) {
//                    if (--least <= 0) return false;
//                }
//            }
//        }
//        sp++;
//        if (!repeat) break;
//    }
//}
//if (sp != s.size()) return false;
//if (match == NULL) {
//    sp++;
//}
//else {
//    if (s[sp] != match) return false;
//    sp++;
//}


//if (i + 1 < p.size()) {
//    if (p[i + 1] == '*') {
//        repeat = true;
//        i++;
//    }
//}