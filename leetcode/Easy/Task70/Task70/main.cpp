#include <vector>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> f(n + 1);
        f[0] = 1;
        f[1] = 1;
        for (size_t i = 2; i < f.size(); ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

int main() {
    Solution s = Solution();
    std::cout << s.climbStairs(2) << std::endl;
    std::cout << s.climbStairs(3) << std::endl;
}