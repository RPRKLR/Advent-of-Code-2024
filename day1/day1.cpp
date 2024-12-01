// #include "../utils/utils.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "../utils/utils.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    fstream input("input.txt");
    vector<int> right, left;
    string temp_str;
    int temp_int;
    while (getline(input, temp_str))
    {
        istringstream iss(temp_str);
        iss >> temp_int;
        left.push_back(temp_int);
        iss >> temp_int;
        right.push_back(temp_int);
    }
    stable_sort(right.begin(), right.end());
    stable_sort(left.begin(), left.end());
    part1_solution_ = 0;
    for (size_t i = 0; i < right.size(); i++)
    {
        part1_solution_ += abs(left[i] - right[i]);
    }

    printSolutionPart1();

    int num_of_times = 0;
    part2_solution_ = 0;
    for (size_t i = 0; i < left.size(); i++)
    {
        for (size_t j = 0; j < right.size(); j++)
        {
            if (left[i] == right[j])
                num_of_times++;
        }
        part2_solution_ += num_of_times * left[i];
        num_of_times = 0;
    }
    printSolutionPart2();
    return 0;
}