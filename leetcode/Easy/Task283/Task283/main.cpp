#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        for (size_t i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[j]);
                ++j;
            }
        }
    }
};