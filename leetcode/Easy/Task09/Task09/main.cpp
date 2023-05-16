#include <cstring>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        char buffer[11];
        memset(buffer, 0, 11);
        int index = 0;
        while (x > 0) {
            buffer[index++] = x % 10 + '0';
            x /= 10;
        }
        bool flag = true;
        for (int i = 0, j = index - 1; i < j; ++i, --j) {
            if (buffer[i] != buffer[j]) return false;
        }
        return true;
    }
};