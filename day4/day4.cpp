#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "../utils/utils.hpp"
#include <regex>
using namespace std;

bool validCoord(int x, int y, int m, int n)
{
    if (x >= 0 && x < m && y >= 0 && y < n)
        return true;
    return false;
}

bool findWord(int index, string word, vector<string> &grid,
              int x, int y, int dirX, int dirY)
{

    if (index == word.length())
        return true;

    if (validCoord(x, y, grid.size(), grid[0].size()) && word[index] == grid[x][y])
        return findWord(index + 1, word, grid, x + dirX,
                        y + dirY, dirX, dirY);

    return false;
}

vector<vector<int>> searchWord(vector<string> grid,
                               string word)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> ans;

    vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (findWord(0, word, grid, i, j, x[k], y[k]))
                {
                    ans.push_back({i, j});
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> searchX(vector<string> grid)
{
    vector<vector<int>> ans;

    for (int i = 1; i < grid.size() - 1; ++i)
    {
        for (int j = 1; j < grid[i].size() - 1; ++j)
        {
            if (grid[i][j] == 'A')
            {
                if ((grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S') && (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S') ||
                    (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M') && (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M') ||
                    (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S') && (grid[i + 1][j - 1] == 'M' && grid[i - 1][j + 1] == 'S') ||
                    (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M') && (grid[i + 1][j - 1] == 'S' && grid[i - 1][j + 1] == 'M'))
                {
                    ans.push_back({i, j});
                }
            }
        }
    }

    return ans;
}

const string WORD = "XMAS";

int main(int argc, char *argv[])
{
    fstream input("input.txt");
    string temp_str;
    vector<string> lines;
    string str = "";
    while (getline(input, temp_str))
    {
        lines.push_back(temp_str);
        // cout << temp_str << endl;
    }
    cout << str;

    vector<vector<int>> ans = searchWord(lines, WORD);

    part1_solution_ = ans.size();
    printSolutionPart1();
    ans = searchX(lines);
    part2_solution_ = ans.size();
    printSolutionPart2();
    return 0;
}