#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "../utils/utils.hpp"
#include <regex>
using namespace std;

void calculateSolution(vector<string> &input, int &solution)
{
    std::regex pattern(R"(\((\d+),(\d+)\))");
    std::smatch matches;
    vector<vector<int>> coordinates;
    for (auto &str : input)
    {
        if (regex_search(str, matches, pattern))
        {
            coordinates.push_back({std::stoi(matches[1].str()), std::stoi(matches[2].str())});
        }
    }
    for (auto &coordinate : coordinates)
    {
        solution += coordinate[0] * coordinate[1];
    }
}

int main(int argc, char *argv[])
{
    fstream input("input.txt");
    string temp_str;
    vector<string> commands;
    while (getline(input, temp_str))
    {
        std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|\bdo\(\)|\bdon't\(\))");
        smatch match;
        while (regex_search(temp_str, match, pattern))
        {
            commands.push_back(match.str());
            temp_str = match.suffix().str();
        }
    }
    calculateSolution(commands, part1_solution_);
    printSolutionPart1();
    bool dont{false};
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "don't()")
            dont = true;
        else if (commands[i] == "do()")
            dont = false;
        if (dont)
        {
            commands.erase(commands.begin() + i);
            i--;
        }
    }
    calculateSolution(commands, part2_solution_);
    printSolutionPart2();
}