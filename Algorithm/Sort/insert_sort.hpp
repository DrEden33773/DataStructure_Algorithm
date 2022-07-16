/**
 * @file insert_sort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief insert_sort
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>

class InsertSort {
public:
    static inline void interface();
    static inline void accending(std::vector<int>& nums);
    static inline void decending(std::vector<int>& nums);
};

void InsertSort::accending(std::vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    for (int i = 1; i < len; ++i) {
        int j = i;
        while (j > 0 && nums[j] < nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            --j;
        }
    }
}

void InsertSort::decending(std::vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    for (int i = 1; i < len; ++i) {
        int j = i;
        while (j > 0 && nums[j] > nums[j - 1]) {
            std::swap(nums[j], nums[j - 1]);
            --j;
        }
    }
}