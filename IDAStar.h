#include <iostream>
#include <set>
#include "Board.h"

using std::set;

class IDAStar
{
private:
    Board start;
    Board goal;
    const int FOUND = -1;
    const int INF = 1000000000;

public:
    int dfs(const Board& board, int g, int threshold, set<Board>& visited)
    {
        visited.insert(board);
        int f = g + board.heuristic();
        if (f > threshold) 
            return f;
        if (board == goal)
            // cout << g << endl;
            return FOUND;
        int min = INF;
        vector<Board> neighbours = board.neighbours();
        for (int i = 0; i < neighbours.size(); i++)
        {
            if (!visited.count(neighbours[i]))
            {
                int temp = dfs(neighbours[i], g + 1, threshold, visited);
                if (temp == FOUND) 
                    return FOUND;
                if (temp < min) 
                    min=temp;
            }
        }
        return min;      
    }

    int play()
    {
        set<Board> visited;
        int threshold = start.heuristic();
        while(true)           
        {
            visited.clear();
            int temp = dfs(start, 0, threshold, visited); 
            if(temp == FOUND)                                
                return FOUND;                                             
            if(temp == INF)                               
                return INF;                               
            threshold = temp;
        }
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
