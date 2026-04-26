class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int* nums1data = nums1.data();
        int* nums2data = nums2.data();
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int totalSize = nums1Size + nums2Size;
        int total[totalSize];
        int* totalp = &total[0];
        int i = 0, j = 0, maxn = 0;
        while (i < nums1Size || j < nums2Size) {
            if (i < nums1Size) {
                if (j >= nums2Size || *nums1data < *nums2data) {
                    *totalp = *nums1data;
                    i++;
                    nums1data++;
                    totalp++;
                    continue;
                    }
                }
            *totalp = *nums2data;
            j++;
            nums2data++;
            totalp++;
            }
        double ret;
        if (totalSize % 2 == 1) {
            ret = total[totalSize / 2];
            }
        else {
            totalp = &total[totalSize / 2 - 1];
            ret = *totalp + totalp[1];
            ret /= 2;
            }
        return ret;
        }
    };
