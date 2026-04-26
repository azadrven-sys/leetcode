class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int maxLength = 0;
        int start = 0;
        int slen = s.length();
        for (int end = 0; end < slen; ++end) {
            char currentChar = s[end];
            if (lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1;
                }
            lastIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
            }
        return maxLength;
        }
    };
