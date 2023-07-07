#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int index_write = -1;
        for (int index_read = 0; index_read < nums.size(); ++index_read) {
            if (index_read == 0 || index_read == 1) {
                nums[++index_write] = nums[index_read];
            }
            else {
                if (nums[index_read] != nums[index_write - 1]) {
                    nums[++index_write] = nums[index_read];
                }
            }
        }

        return ++index_write;
    }
};