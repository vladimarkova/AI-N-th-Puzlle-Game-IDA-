#pragma once
#include <iostream>
#include <set>
#include "Board.h"
using namespace std;

class IDAStar
{
private:
    Board start;
    Board goal;
    const int FOUND = -1;
    const int INF = 1000000000;
    const vector<string> directions = {"left", "right", "up", "down"};

public:
    int dfs(const Board& board, int g, int threshold, set<Board>& visited, vector<string>& steps)
    {
        visited.insert(board);
        int f = g + board.heuristic();
        if (f > threshold) 
            return f;
        if (board == goal)
            return FOUND;
        int min = INF;
        for (int i = 0; i < directions.size(); i++)
        {
            Board neighbour = board.createNeighbour(directions[i]);
            if (neighbour.getSize() != 0 && !visited.count(neighbour))
            {
                steps.push_back(directions[i]);
                int temp = dfs(neighbour, g + 1, threshold, visited, steps);
                if (temp == FOUND) 
                    return FOUND;
                steps.pop_back();
                if (temp < min) 
                    min=temp;
            }
        }
        return min;   
    }

    vector<string> play() 
    {
        set<Board> visited;
        vector<string> steps;
        int threshold = start.heuristic();

        int i = 0;
        while(i < 50)           
        {
            visited.clear();
            steps.clear();
            int temp = dfs(start, 0, threshold, visited, steps); 
            if(temp == FOUND)
                 return steps;                                                       
            if(temp == INF)                               
                 return vector<string>(1, "UNSOLVABLE");                               
            threshold = temp;
            i++;
        }
        cout << "50\n";
        return vector<string>(); 
    }

    void setStart(const Board& _start)
    {
        start.makeEqual(_start);
    }

    void setGoal(int posOfZero, int _size)
    {
        goal.makeGoal(posOfZero, _size);
        // goal.print();
    }
};
