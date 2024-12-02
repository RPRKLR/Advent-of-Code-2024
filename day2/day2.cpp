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
        increasing = rows[i][1] > rows[i][0];
        for (size_t j = 1; j < rows[i].size(); ++j)
        {
            int diff = rows[i][j] - rows[i][j - 1];

            if (diff < -3 || diff > 3 || diff == 0)
            {
                break;
            }

            // Check if the trend is consistent
            if (increasing && diff < 0)
            {
                break;
            }
            if (!increasing && diff > 0)
            {
                break;
            }
            if (j == rows[i].size() - 1)
                part1_solution_++;
        }
    }
    printSolutionPart1();
}