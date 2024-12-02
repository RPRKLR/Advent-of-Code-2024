// #include "../utils/utils.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "../utils/utils.hpp"
using namespace std;

bool getRowTruth(vector<int> input)
{
    bool increasing = input[1] > input[0];
    for (size_t i = 1; i < input.size(); ++i)
    {
        int diff = input[i] - input[i - 1];

        if (diff < -3 || diff > 3 || diff == 0)
        {
            return false;
        }

        // Check if the trend is consistent
        if (increasing && diff < 0)
        {
            return false;
        }
        if (!increasing && diff > 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    fstream input("input.txt");
    string temp_str;
    string element{""};
    vector<vector<int>> rows;
    char c;
    while (getline(input, temp_str))
    {
        vector<int> row;
        for (size_t i = 0; i < temp_str.size(); i++)
        {
            if (temp_str[i] == ' ')
            {
                row.push_back(stoi(element));
                element = "";
            }
            else
                element.push_back(temp_str[i]);
        }
        row.push_back(stoi(element));
        element = "";
        rows.push_back(row);
    }
    part1_solution_ = 0;
    bool increasing{true};

    for (size_t i = 0; i < rows.size(); ++i)
    {
        if (getRowTruth(rows[i]))
            part1_solution_++;
    }
    printSolutionPart1();
    part2_solution_ = 0;
    for (size_t i = 0; i < rows.size(); ++i)
    {
        if (getRowTruth(rows[i]))
            part2_solution_++;
        else
        {
            vector<vector<int>> separated_data;
            vector<int> temp_vec;
            for (size_t j = 0; j < rows[i].size(); ++j)
            {
                temp_vec = rows[i];
                temp_vec.erase(temp_vec.begin() + j);
                if (getRowTruth(temp_vec))
                {
                    part2_solution_++;
                    break;
                }
            }
        }
    }
    printSolutionPart2();
}