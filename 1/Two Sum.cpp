#include <vector>
#include <unordered_map>
class Solution {
    unordered_map<int, int> seen;
    int len;
    int* arr;
    int complement;
    size_t (unordered_map<int, int>::*countFn)(const int&) const = &unordered_map<int, int>::count;
    int x;
    int i;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    len = nums.size();
        arr = nums.data();
        for (i = 0; i < len; i++) {
	        x = *arr;
            complement = target - x;
            if ((seen.*countFn)(complement)) {
                return {seen[complement], i};
                }
            seen[x] = i;
            arr++;
            }
        return {};
        }
    };
