class Solution {
    int maxLength;
    int start;
    int slen;
    char currentChar;
    int end;
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        maxLength = 0;
        start = 0;
        slen = s.length();
        currentChar;
        end;
        for (end = 0; end < slen; ++end) {
            currentChar = s[end];
            if (lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1;
                }
            lastIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
            }
        return maxLength;
        }
    };
