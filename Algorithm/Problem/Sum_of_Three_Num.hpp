#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // construct
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }

        // sort
        sort(nums.begin(), nums.end());

        // iterate
        int last = nums.size() - 1;
        for (int first = 0; first < nums.size(); ++first) {
            // smallest + biggest + second_biggest < 0
            if (nums[first] + nums[last] + nums[last - 1] < 0) {
                // abort
                continue; // nums[first] won't join the tuple in res
            } else {
                vector<int> inner;
                inner.push_back(nums[first]);
                // now could iterate
                for (int second = first + 1; second < nums.size(); ++second) {
                    int sum_of_two = nums[first] + nums[second];
                    if (sum_of_two + nums[last] < 0) {
                        // abort
                        continue;
                    }
                    // start to find!
                    int first_in_nums       = nums[first];
                    int second_in_nums      = nums[second];
                    auto find_third_element = [&first_in_nums, &second_in_nums](int i) {
                        return first_in_nums + second_in_nums + i == 0;
                    };
                    auto the_third_element
                        = find_if(nums.begin(), nums.end(), find_third_element);
                    if (the_third_element != nums.end()) {
                        // successfully find!
                        inner.push_back(nums[second]);
                        inner.push_back(*the_third_element);
                    }
                }
            }
        }

        return res;
    }
};
