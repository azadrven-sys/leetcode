#include <string.h>
int n;
int last_index[128];
unsigned char* c;
int max_len;
int left;
int min;
int right;
int size = sizeof(int) * 128;
int lengthOfLongestSubstring(char* s) {
    n = strlen(s);
    if (n == 0) return 0;
    memset(last_index, -1, size);
    c = s;
    max_len = 0;
    left = 0;
    unsigned char current_char;
    for (right = 0; right < n; right++) {
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
