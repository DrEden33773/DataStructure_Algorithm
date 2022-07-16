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

#include <bits/stdc++.h>

// vec => [1, 2, 4, 3, 9, 6, 7, 5, 10]

class InsertSort {
private:
    static std::vector<int> test;

public:
    static inline void interface();
    static inline void accending(std::vector<int>& nums);
    static inline void decending(std::vector<int>& nums);
};
std::vector<int> InsertSort::test = { 1, 2, 4, 3, 9, 6, 7, 5, 10 };

// Insert the nums[i] into the sorted range [0, i)
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

// Insert the nums[i] into the sorted range [0, i)
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

void InsertSort::interface() {
    for (auto& num : test) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    InsertSort::accending(test);
    for (auto& num : test) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    InsertSort::decending(test);
    for (auto& num : test) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}