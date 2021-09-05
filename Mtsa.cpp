#include "Mtsa.h"
using namespace std;
double fMSA(vector<int>& sSet,int sSize,int p1,
	vector<int>& lSet,int lSize,int p2) {

}

double Mtsa::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2, nums1);
	int a = nums1.size(), b = nums2.size();
	int low = 0, high = a;
	int pa, pb, aleftmax, arightmin, bleftmax, brightmin;
	while (low <= high) {
		pa = (low + high) / 2;
		pb = (a + b + 1) / 2 - pa;
		aleftmax = (pa == 0) ? INT_MIN : nums1[pa - 1];
		arightmin = (pa == a) ? INT_MAX : nums1[pa];
		bleftmax = (pb == 0) ? INT_MIN : nums2[pb - 1];
		brightmin = (pb == b) ? INT_MAX : nums2[pb];
		if (aleftmax <= brightmin && arightmin >= bleftmax) {
			if ((a + b) % 2 == 0)
				return ((double)(max(aleftmax, bleftmax)
					+ min(arightmin, brightmin))) / 2;
			else
				return (double)max(aleftmax, bleftmax);
		}
		else if (aleftmax > brightmin) {
			high = pa - 1;
		}
		else
			low = pa + 1;

	}
	return 0.0;

	/*if (nums1.size() == 0) {
		if (nums2.size() == 0) {

		}
	}
	if(nums1.size() > nums2.size() ){
		return fMSA(nums2, nums2.size(), nums2.size() / 2,
			nums1, nums1.size(), nums1.size() / 2);
	}
	return fMSA(nums1, nums1.size(), nums1.size() / 2,
		nums2, nums2.size(), nums2.size() / 2);*/
	//int a1=0, b1=nums1.size()-1, a2=0, b2=nums2.size()-1;
	//int p1 = (a1 + b1) / 2, p2 = (a2 + b2) / 2;
	//int flag= (nums1[p1] > nums2[p2]) ? 1 : 2;//-1: undefined, 1:p1>p2 2:p1<p2
	//while (true) {
	//	switch (flag) {
	//	case 1:


	//		break;
	//	case 2:

	//		break;
	//	}
	//}

	return 0.0;
}
