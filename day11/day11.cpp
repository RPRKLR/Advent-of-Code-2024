// #include "../utils/utils.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "../utils/utils.hpp"
using namespace std;

long long countStones(int num_of_iter, vector<string> init_stone)
{
    for (int i = 0; i < num_of_iter; ++i)
    {
        cout << i << endl;
        vector<string> new_stones;
        for (int j = 0; j < init_stone.size(); ++j)
        {
            if (init_stone[j] == "0")
            {
                new_stones.push_back("1");
            }
            else if ((init_stone[j].size() % 2) == 0)
            {
                string left_half = to_string(stoll(init_stone[j].substr(0, init_stone[j].size() / 2)) * 1);
                string right_half = to_string(stoll(init_stone[j].substr(init_stone[j].size() / 2, string::npos)) * 1);
                new_stones.push_back(left_half);
                new_stones.push_back(right_half);
                // cout << "left: " << left_half << " right: " << right_half << endl;
            }
            else
            {
                long long new_num = stoll(init_stone[j]) * 2024;
                // cout << "new num " << new_num << endl;
                new_stones.push_back(to_string(new_num));
            }
        }
        init_stone = new_stones;
    }
    return init_stone.size();
}

int main(int argc, char *argv[])
{
    fstream input("input.txt");
    string temp_str;
    string element{""};
    vector<string> stones;
    while (getline(input, temp_str))
    {
        string s = "";
        for (const auto &c : temp_str)
        {
            if (c == ' ')
            {
                stones.push_back(s);
                s = "";
            }
            else
            {
                s += c;
            }
        }
        stones.push_back(s);
    }

    part1_solution_ = countStones(25, stones);
    printSolutionPart1();
    part2_solution_ = countStones(75, stones);
    printSolutionPart2();
}