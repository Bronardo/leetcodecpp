#include "TwoSum.h"
#include <iostream>
#include <vector>
using namespace std;


//int TwoSum::twoSumDo(vecotr<int> &nums, int target)
//{
//
//
//
//	return 0;
//}

vector<int> ts::TwoSum::twoSumDo(std::vector<int>& nums, int target)
{
	int i, j;
	for (i = 0; i < nums.size(); i++) {
		for (j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) return {i,j};
		}
	}
	return {};
}
