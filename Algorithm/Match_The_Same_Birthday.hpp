/**
 * @file Match_The_Same_Birthday.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief {
        0. pre_definations => class birthday { int month; int day; };
        1. found those who have the same birthday
        2. return all <date:birthday, vector<name:string>> pairs
    }
 * @version 0.1
 * @date 2022-07-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @attention => only match the same day and same month, year is not considered
 */
class Match_The_Same_Birthday {
public:
    inline void interface();

private:
    struct birthday {
        int month;
        int day;
    };
    using type_in  = unordered_map<string, birthday>; // alias => input_type
    using type_res = map<birthday, vector<string>>;   // alias => result_type
    inline auto solution(type_in input) -> type_res;  // give the result
    inline void print_output(type_res result);        // print the result
};

auto Match_The_Same_Birthday::solution(type_in input) -> type_res {
    type_res res;
    unordered_map<int, vector<string>> month_table;
    // fill the month_table
    for (const auto& _pair : input) {
        string _name       = _pair.first;
        birthday _birthday = _pair.second;
        month_table[_birthday.month].push_back(_name);
    }
    // search in each month
    for (const auto& _pair : month_table) {
        // generate vector to store whose birthdays have the same month
        vector<pair<string, birthday>> temp_container;
        vector<string> _names = _pair.second;
        int _month            = _pair.first;
        for (const auto& _name : _names) {
            birthday _birthday = input[_name];
            auto pair_to_push  = make_pair(_name, _birthday);
            temp_container.push_back(pair_to_push);
        }
        // sort the container
        sort(
            temp_container.begin(),
            temp_container.end(),
            [](const pair<string, birthday>& a, const pair<string, birthday>& b) {
                return a.second.day < b.second.day;
            }
        );
        // search the same birthday
        for (int i = 0; i + 1 < temp_container.size(); i++) {
            if (temp_container[i].second.day == temp_container[i + 1].second.day) {
                res[temp_container[i].second].push_back(temp_container[i].first);
                res[temp_container[i + 1].second].push_back(temp_container[i + 1].first);
            }
        }
    }
    // unique each vector in the result unordered_map
    for (auto& _pair : res) {
        sort(_pair.second.begin(), _pair.second.end());
        _pair.second.erase(
            unique(_pair.second.begin(), _pair.second.end()),
            _pair.second.end()
        );
    }
    // return the result
    return res;
}