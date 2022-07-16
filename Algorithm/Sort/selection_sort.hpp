/**
 * @file selection_sort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief selection_sort
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>

class SelectionSort {
public:
    static inline void interface();

private:
    static inline void accending(std::vector<int>& nums);
    static inline void decending(std::vector<int>& nums);
};

/**
 * @brief selection_sort (accending order)
 *
 * @param nums
 */
void SelectionSort::accending(std::vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    for (int i = 0; i < len; ++i) {
        int minIndex = i;
        // locate the min index in range [i + 1, len)
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }
}

/**
 * @brief selection_sort (decending order)
 *
 * @param nums
 */
void SelectionSort::decending(std::vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    for (int i = 0; i < len; ++i) {
        int maxIndex = i;
        // locate the max index in range [i + 1, len)
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] > nums[maxIndex]) {
                maxIndex = j;
            }
        }
        std::swap(nums[i], nums[maxIndex]);
    }
}