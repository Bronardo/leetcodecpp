#include "Lswrc.h"
//#include <unordered_map>
using namespace std;

int Lswrc::lengthOfLongestSubstring(std::string s)
{
    if (s.empty()) return 0;
    if (s.size() == 1) return 1;
    int a = 0, l = 1;
    //bool f;
    for (int i = 1; i < s.size(); i++) {

        for (int j = a; j <= i; j++) {
            if (s[i] == s[j]) {
                //what happen to counter? nothing, do it on incrementing when not found
                //if (i - a + 1 > l) l = i - a + 1;
                //what happen to a b pointer?
                a = j+1;
            }
        }
        if (i - a+1> l) l = i - a+1;
    }
    return l;
    
    /*if (s.empty()) return 0;
    int c, l = 1;
    char p;
    for (int i = 0; i < s.size(); i++) {
        p = s[i];
        c = 1;
        for (int j = i + 1; j < s.size(); j++) {
            if (p != s[j]) {
                c++;
                continue;
            }
            break;
        }
        if (c > l) l = c;
    }
    return l;*/
    //unordered_map<char, int> umap;
    /*int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (umap.at(s[i])) {
            c = 0;
            continue;
        }

    }*/
    //return l;
}
