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
    vector<string> map;
    Point2d position;
    vector<Point2d> directions = {Point2d(-1, 0), Point2d(0, 1), Point2d(1, 0), Point2d(0, -1)};
    while (getline(input, temp_str))
    {
        map.push_back(temp_str);
    }
    for (int i = 0; i < map.size(); ++i)
    {
        int found = map[i].find("^");
        if (found != std::string::npos)
        {
            position.x = i;
            position.y = found;
            break;
        }
    }
    int dir = 0;
    map[position.x][position.y] = 'X';
    for (int i = 0; i < 1000000; ++i)
    {
        if (position.x + directions[dir].x < 0 || position.x + directions[dir].x > map.size() - 1 || position.y + directions[dir].y < 0 || position.y + directions[dir].y > map[0].size() - 1)
            break;
        if (dir > 3)
            dir = 0;
        if (map[position.x + directions[dir].x][position.y + directions[dir].y] != '#')
        {
            map[position.x + directions[dir].x][position.y + directions[dir].y] = 'X';
            position.x += directions[dir].x;
            position.y += directions[dir].y;
        }
        else
        {
            dir++;
        }
        // for (int i = 0; i < map.size(); ++i)
        // {
        //     cout << map[i] << endl;
        // }
        // cout << endl;
    }
    for (int i = 0; i < map.size(); ++i)
    {
        part1_solution_ += count(map[i].begin(), map[i].end(), 'X');
    }

    printSolutionPart1();
}