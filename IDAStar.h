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
    const int INF = 1000000;
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

    // int dfs(const Board& board, int g, int threshold, set<Board>& visited)
    // {
    //     // board.print();
    //     visited.insert(board);
    //     int f = g + board.heuristic();
    //     if (f > threshold) 
    //         return f;
    //     if (board == goal)
    //         return FOUND;
    //     int min = INF;
    //     vector<Board> neighbours = board.getNeighbours();
    //     for (int i = 0; i < neighbours.size(); i++)
    //     {            
    //         if (!visited.count(neighbours[i]))
    //         {
    //             int temp = dfs(neighbours[i], g + 1, threshold, visited);
    //             if (temp == FOUND) 
    //                 return FOUND;
    //             if (temp < min) 
    //                 min=temp;
    //         }
    //     }
    //     return min;   
    // }

    vector<string> play() 
    {
        set<Board> visited;
        vector<string> steps;
        int threshold = start.heuristic();

        while(true)         
        {
            visited.clear();
            steps.clear();
            int temp = dfs(start, 0, threshold, visited, steps); 
            if(temp == FOUND)
                 return steps;                                                       
            if(temp == INF)                               
                 return vector<string>(1, "UNSOLVABLE");                               
            threshold = temp;
        }
        // cout << "50\n";
        // return vector<string>(); 
    }

    // int play() 
    // {
    //     set<Board> visited;
    //     int threshold = start.heuristic();

    //     int i = 0;
    //     while(i < 50)         
    //     {
    //         visited.clear();
    //         int temp = dfs(start, 0, threshold, visited); 
    //         if(temp == FOUND)
    //              return FOUND;                                                       
    //         if(temp == INF)                               
    //              return INF;                             
    //         threshold = temp;
    //         i++;
    //     }
    //     cout << "50\n";
    //     return -50; 
    // }

    void setStart(const Board& _start)
    {
        start = _start;
    }

    void setGoal(int posOfZero, int _size)
    {
        goal.makeGoal(posOfZero, _size);
    }
};
