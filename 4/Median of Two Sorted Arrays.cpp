class Solution {
    int* nums1data;
    int* nums2data;
    int nums1Size;
    int nums2Size;
    int totalSize;
    int* totalp;
    int i = 0;
    int j = 0;
    int maxn = 0;
    double ret;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1data = nums1.data();
        nums2data = nums2.data();
        nums1Size = nums1.size();
        nums2Size = nums2.size();
        totalSize = nums1Size + nums2Size;
        int total[totalSize];
        totalp = &total[0];
        i = 0;
        j = 0;
        maxn = 0;
        ret;
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
