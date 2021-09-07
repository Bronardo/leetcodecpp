#pragma once
#include <string>
#include <vector>
class RegularExpressionMatching
{
public:
    bool isMatch(std::string s, std::string p);
private:
    bool solve(std::string& s, std::string& p, int i, int j, char prev, std::vector<std::vector<int>>& dp);
};

