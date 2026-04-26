#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;
    int last_index[128];
    memset(last_index, -1, sizeof(last_index));
    unsigned char* c = s;
    int max_len = 0;
    int left = 0;
    int min;
    unsigned char current_char;
    for (int right = 0; right < n; right++) {
        current_char = *c;
        if (last_index[current_char] >= left) {
            left = last_index[current_char] + 1;
            }
        last_index[current_char] = right;
        min = right - left + 1;
        if (max_len <= min) max_len = min;
        c++;
        }
    return max_len;
    }
