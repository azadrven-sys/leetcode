class Solution {
    int start;
    int maxLen;
    int n;
    int nmo;
    int i;
    int left;
    int right;
    int currentLen;
    char* sptr1;
    char* sptr2;
public:
    string longestPalindrome(string s) {
        n = s.length();
        if (n <= 1) return s;
        start = 0;
        maxLen = 1;
        nmo = n - 1;
        i = 0;
        left;
        right;
        currentLen;
        sptr1;
        sptr2;
        while (i < n && n - i > maxLen / 2) {
            left = i;
            right = i;
            sptr1 = &s[i];
            sptr2 = sptr1;
            sptr2++;
            while (right < nmo && *sptr2 == *sptr1) {
                right++;
                sptr1++;
                sptr2++;
                }
            sptr1 = &s[0];
            sptr1 += left - 1;
            i = right + 1;
            while (left > 0 && right < nmo && *sptr1 == *sptr2) {
                left--;
                sptr1--;
                right++;
                sptr2++;
                }
            currentLen = right - left + 1;
            if (currentLen > maxLen) {
                start = left;
                maxLen = currentLen;
                }
            }
        return s.substr(start, maxLen);
        }
    };
