class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 < len2) {
        	return findMedianSortedArrays(nums2, nums1);
        }

        int lo = 0;
        int hi = len2 * 2;
        while (lo <= hi) {
        	int mid2 = (lo + hi) / 2;
        	int mid1 = len1 + len2 - mid2;

        	double l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
        	double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
        	double r1 = (mid1 == len1 * 2) ? INT_MAX : nums1[mid1 / 2];
        	double r2 = (mid2 == len2 * 2) ? INT_MAX : nums2[mid2 / 2];

        	if (l1 > r2) {
        		lo = mid2 + 1;
        	}
        	else if (l2 > r1) {
        		hi = mid2 - 1;
        	}
        	else {
        		return (max(l1, l2) + min(r1, r2)) / 2;
        	}

        }

        return -1;
    }
};