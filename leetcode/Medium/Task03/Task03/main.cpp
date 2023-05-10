#include <string>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int index_left = 0;
        int max_length = 0;
        std::unordered_set<char> set;

        for (int i = 0; i < s.length(); ++i) {
            if (set.find(s[i]) != set.end()) {
                char deleted_char;
                do {
                    deleted_char = s[index_left];
                    set.erase(deleted_char);
                    ++index_left;
                } while (deleted_char != s[i]);
            }
            set.insert(s[i]);
            max_length = std::max(set.size(), (size_t)max_length);
        }

        return max_length;
    }
};