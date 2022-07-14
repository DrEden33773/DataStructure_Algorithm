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

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

using frame = class Match_The_Same_Birthday {
public:
  inline void interface();

private:
  struct birthday {
    int month;
    int day;
  };
  map<birthday, vector<string>> typeof_result;
  unordered_map<string, birthday> typeof_input;
  using type_in  = decltype(typeof_input);
  using type_res = decltype(typeof_result);
  inline auto solution(type_in input) -> type_res;
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
    int _month            = _pair.first;
    vector<string> _names = _pair.second;
    for (const string& name : _names) {
      birthday _birthday = input[name];
      temp_container.push_back(make_pair(name, _birthday));
    }
    // sort the container
    sort(temp_container.begin(), temp_container.end(),
         [](const pair<string, birthday>& a, const pair<string, birthday>& b) {
           return a.second.day < b.second.day;
         });
    // search the same birthday
    for (int i = 0; i < temp_container.size(); i++) {
      if (temp_container[i].second.day == temp_container[i + 1].second.day) {
        res[temp_container[i].second].push_back(temp_container[i].first);
        res[temp_container[i + 1].second].push_back(
            temp_container[i + 1].first);
      }
    }
  }
  // unique each vector in the result unordered_map
  for (auto& _pair : res) {
    sort(_pair.second.begin(), _pair.second.end());
    _pair.second.erase(unique(_pair.second.begin(), _pair.second.end()),
                       _pair.second.end());
  }
  // return the result
  return res;
}