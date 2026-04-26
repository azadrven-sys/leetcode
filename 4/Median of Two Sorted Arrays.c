int totalSize;
int* totalp;
int i = 0;
int j = 0;
int maxn = 0;
double ret;
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    totalSize = nums1Size + nums2Size;
    int total[totalSize];
    totalp = &total[0];
    i = 0;
    j = 0;
    maxn = 0;
    while (i < nums1Size || j < nums2Size) {
        if (i < nums1Size) {
            if (j >= nums2Size || *nums1 < *nums2) {
                *totalp = *nums1;
                i++;
                nums1++;
                totalp++;
                continue;
                }
            }
        *totalp = *nums2;
        j++;
        nums2++;
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
