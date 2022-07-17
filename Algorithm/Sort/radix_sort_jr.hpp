/**
 * @file radix_sort_jr.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief radix_sort_jr
 * @version 0.1
 * @date 2022-07-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

class RadixSortJr {
private:
    struct tuple {
        int a; // a = val / n
        int b; // b = val % n
        tuple() {
            a = -1;
            b = -1;
        };
    };
    struct bond {
        tuple tran;
        int val;
        bond()
            : tran() {
            val = -1;
        };
    };
    enum KEY {
        a,
        b,
    };
    std::vector<std::vector<bond>> DAA; // Direct Access Array
    std::vector<bond> bondVec;          // Array store bonds

public:
    void interface();
    void solution(std::vector<int>& input);
    void DAA_Sort(KEY input, const int& ToSortLen);
    void println_Vec(std::vector<int>& input);
};

/**
 * @brief radix_accending_sort
 * @attention input.size() or 0 <= input[i] < (input.size())^2 , input[i]>=0
 * @param input
 */
void RadixSortJr::solution(std::vector<int>& input) {
    static const int InputLen = static_cast<int>(input.size());
    // initialize bondVec
    bondVec.reserve(InputLen);
    for (auto& num : input) {
        bond temp;
        temp.tran.a = num / InputLen;
        temp.tran.b = num % InputLen;
        temp.val    = num;
        bondVec.emplace_back(temp); // emplace => place != push
    }
    // DAA_Sort
    DAA_Sort(b, InputLen);
    DAA_Sort(a, InputLen);
    // input <==pull== bondVec
    int scannedNums = 0;
    for (auto& bond : bondVec) {
        if (scannedNums == InputLen) {
            break;
        }
        input[scannedNums] = bond.val;
        scannedNums += 1;
    }
}

void RadixSortJr::DAA_Sort(KEY input, const int& ToSortLen) {
    DAA.reserve(ToSortLen);
    // initialize DAA => necessary
    std::vector<bond> init_elem {};
    for (int i = 0; i < ToSortLen; i++) {
        DAA.emplace_back(init_elem);
    }
    // bondVec ==push=> DAA
    for (auto& bond : bondVec) {
        int key;
        if (input == a) {
            key = bond.tran.a;
        } else {
            key = bond.tran.b;
        }
        DAA[key].push_back(bond);
    }
    // bondVec <==pull== DAA
    int scannedNums = 0;
    for (auto& bonds : DAA) {
        if (scannedNums == ToSortLen) {
            break;
        }
        if (bonds.size() == 0) {
            continue;
        }
        for (auto& bond : bonds) {
            bondVec[scannedNums] = bond;
            scannedNums += 1;
        }
    }
    // clear DAA => necessary
    DAA.erase(DAA.begin(), DAA.end());
}

void RadixSortJr::println_Vec(std::vector<int>& input) {
    for (auto& num : input) {
        std::cout << num << " ";
    }
    std::cout << "\b \b";
    std::cout << std::endl;
}

void RadixSortJr::interface() {
    std::vector<int> test { 1, 2, 4, 1, 6, 7, 5, 10, 9, 15, 30 };
    println_Vec(test);
    solution(test);
    println_Vec(test);
}