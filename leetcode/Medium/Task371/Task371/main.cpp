#include <limits>

class Solution {
public:
    int getSum(int a, int b) {
        do {
            int tmp = a;
            a ^= b;
            b = tmp & b;
            if (b < 0) b &= std::numeric_limits<int>::max();
            b <<= 1;
        } while (b);

        return a;
    }
};