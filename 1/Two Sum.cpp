#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
	      int len = nums.size();
        int* arr = nums.data();
        int complement;
        size_t (unordered_map<int, int>::*countFn)(const int&) const = &unordered_map<int, int>::count;
	      int x;
        for (int i = 0; i < len; i++) {
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
