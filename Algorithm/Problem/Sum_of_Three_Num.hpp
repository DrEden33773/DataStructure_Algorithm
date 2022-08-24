#include <bits/stdc++.h>
using namespace std;

class Sum_of_Three_Num {
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
        for (int first = 0; first < nums.size() - 2; ++first) {
            // smallest + biggest + second_biggest < 0
            if (nums[first] + nums[last] + nums[last - 1] < 0) {
                // abort
                continue; // nums[first] won't join the tuple in res
            } else {
                // vector<int> inner;
                // now could iterate
                for (int second = first + 1; second < nums.size() - 1; ++second) {
                    vector<int> inner;
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
                    // give a iterator which points to nums[second + 1]
                    auto second_plus_one_iterator = nums.begin();
                    ranges::advance(second_plus_one_iterator, second + 1);
                    // find
                    auto the_third_element = find_if(
                        second_plus_one_iterator,
                        nums.end(),
                        find_third_element
                    );
                    if (the_third_element != nums.end()) {
                        // successfully find!
                        inner.push_back(nums[first]);
                        inner.push_back(nums[second]);
                        inner.push_back(*the_third_element);
                        res.push_back(inner);
                    }
                }
            }
        }

        // have to unique the res
        // EG: {{-1,-1,2},{-1,0,1},{-1,0,1}} => {{-1,-1,2},{-1,0,1}}

        auto Judge_Tuple_Equality =
            [&](vector<int>& InputA, vector<int>& InputB)
            -> bool {
            // {-1 -1 2} and {-1 2 -1}
            if (InputA.size() != InputB.size()) {
                return false;
            }
            sort(InputA.begin(), InputA.end());
            sort(InputB.begin(), InputB.end());
            bool res = true;
            for (int i = 0; i < InputA.size(); ++i) {
                if (InputA[i] != InputB[i]) {
                    res = false;
                    break;
                }
            }
            return res;
        };
        auto LAST = unique(res.begin(), res.end(), Judge_Tuple_Equality);
        res.erase(LAST, res.end());

        return res;
    }

    static void example() {
        auto TestSolution   = new Sum_of_Three_Num();
        vector<int> TestVec = { -1, -1, 4, 0, 1, 2 }; // after sort => {-1 -1 0 1 2 4}
        auto Result         = TestSolution->threeSum(TestVec);
        // Print the outcome
        cout << endl;
        cout << "{";
        for (const auto& Tuple : Result) {
            cout << "{";
            for (const auto& Element : Tuple) {
                cout << Element << ",";
            }
            cout << "\b \b";
            cout << "},";
        }
        cout << "\b \b";
        cout << "}";
        cout << endl;
        cout << endl;
    }
};
