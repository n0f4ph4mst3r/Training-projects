#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        const std::string& max = a.length() > b.length() ? a : b;
        const std::string& min = max == a ? b : a;

        char* buffer = new char[max.length() + 2];
        memset(buffer, 0, max.length() + 2);

        int index = max.length();
        bool extra = false;
        for (int i = max.length() - 1, j = min.length() - 1; i >=0; --i, --j) {
            int value = (max[i] - '0') + (j >= 0 ? min[j] - '0' : 0) + (extra ? 1 : 0);
            extra = value >= 2;
            value %= 2;
            buffer[index--] = '0' + value;
        }
        char* ptr = buffer;
        if (extra) ptr[index] = '1';
        else ++ptr;

        std::string result(ptr);
        delete[] buffer;
        return result;
    }
};