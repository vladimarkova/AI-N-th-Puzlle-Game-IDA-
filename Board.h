#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;
// using std::tuple;
// using std::make_tuple;
// using std::string;

class Board
{
    private:
    int size;
    int matrix[16][16];
    int rowOfZero;
    int colOfZero;

    public:
    Board(int _size = 3)
    {
        size = _size;
    }

    int getSize() const
    {
        return size;
    }

    void read()
    {
        cout << "Enter number of blocks:" << endl;

        int number, zeroPosition;
        cin >> number;
        
        size = 0;
        if(number == 8) {
            size = 3;
        }
        else if (number == 15) {
            size = 4;
        }
        // size = sqrt(number + 1);

        cout << "Enter position of 0: " << endl;
        cin >> zeroPosition;
        if (zeroPosition < 0 || zeroPosition >= size*size)
        {
            rowOfZero = size - 1;
            colOfZero = size - 1;
        }
        else
        {
            rowOfZero = zeroPosition / size;
            colOfZero = zeroPosition % size;
        }

        cout << "Enter board: " << endl;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> matrix[i][j];
            }
        }

        matrix[rowOfZero][colOfZero] = 0;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    // make goalRow and goalCol work with different positions
    int heuristic() const
    {
        int sum = 0;
        int goalRow, goalCol;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                 goalRow = (matrix[i][j] - 1) / size;
                 goalCol = (matrix[i][j] - 1) % size;  
                 sum += abs(i - goalRow) + abs(j - goalCol); 
            }
        }
        return sum;
    }

    bool operator==(const Board& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j] != other.matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator<(const Board& other) const
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j] < other.matrix[i][j])
                {
                    return true;
                }
                 if (matrix[i][j] > other.matrix[i][j])
                {
                    return false;
                }               
            }
        }
        return false;
    }

    void makeEqual(const Board& other)
    {
        size = other.size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // make it work for different positions of zero 
    void makeGoal(int posOfZero, int _size)
    {
        int number = 1;
        size = _size;
        if (posOfZero < 0 || posOfZero >= size*size)
        {
            rowOfZero = size - 1;
            colOfZero = size - 1;
        }
        else
        {
            rowOfZero = posOfZero / size;
            colOfZero = posOfZero % size;
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = number;
                number++;
            }
        }
        matrix[rowOfZero][colOfZero] = 0;
    }

    // vector<Board> neighbours() const
    // {
    //     vector<Board> neighbours;
    //     if (colOfZero > 0)
    //     {
    //         Board neighbour = *this;
    //         neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero][colOfZero - 1];
    //         neighbour.matrix[rowOfZero][colOfZero - 1] = 0;
    //         neighbour.colOfZero--;
    //         neighbours.push_back(neighbour);
    //     }
    //     if (colOfZero < size - 1)
    //     {
    //         Board neighbour = *this;
    //         neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero][colOfZero + 1];
    //         neighbour.matrix[rowOfZero][colOfZero + 1] = 0; 
    //         neighbour.colOfZero++;
    //         neighbours.push_back(neighbour); 
    //     }
    //     if (rowOfZero > 0)
    //     {
    //         Board neighbour = *this;
    //         neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero - 1][colOfZero];
    //         neighbour.matrix[rowOfZero - 1][colOfZero] = 0;
    //         neighbour.rowOfZero--;
    //         neighbours.push_back(neighbour); 
    //     }
    //     if (rowOfZero < size - 1)
    //     {
    //         Board neighbour = *this;
    //         neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero + 1][colOfZero];
    //         neighbour.matrix[rowOfZero + 1][colOfZero] = 0;
    //         neighbour.rowOfZero++;
    //         neighbours.push_back(neighbour); 
    //     }
    //     return neighbours;
    // }

    Board createNeighbour(string step) const
    {
        if (step == "left" && colOfZero > 0)
        {
            Board neighbour = *this;
            neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero][colOfZero - 1];
            neighbour.matrix[rowOfZero][colOfZero - 1] = 0;
            neighbour.colOfZero--;
            return neighbour;
        }
        if (step == "right" && colOfZero < size - 1)
        {
            Board neighbour = *this;
            neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero][colOfZero + 1];
            neighbour.matrix[rowOfZero][colOfZero + 1] = 0; 
            neighbour.colOfZero++;
            return neighbour;
        }
        if (step == "up" && rowOfZero > 0)
        {
            Board neighbour = *this;
            neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero - 1][colOfZero];
            neighbour.matrix[rowOfZero - 1][colOfZero] = 0;
            neighbour.rowOfZero--;
            return neighbour;
        }
        if (step == "down" && rowOfZero < size - 1)
        {
            Board neighbour = *this;
            neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero + 1][colOfZero];
            neighbour.matrix[rowOfZero + 1][colOfZero] = 0;
            neighbour.rowOfZero++;
            return neighbour;
        }
        return Board(0);
    }

    string direction()
    {
        if (colOfZero > 0)
        {
            return "left";
        }
        if (colOfZero < size - 1)
        {
            return "right";
        }
        if (rowOfZero > 0)
        {
            return "up";
        }
        if (rowOfZero < size - 1)
        {
            return "down";
        }
    }

    tuple<int, int> getIndexes(int position) 
    {
        int row = position / size;
        int col = position % size;
        tuple<int, int> indexes = make_tuple(row, col);
        return indexes;
    } 

    int toPlain(int array[256]) 
    {
        int k = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                array[k] = matrix[i][j];
                k++;
            }
        }
        return k;
    }

    int countInversions()
    {
        int array[256];
        int inversions = 0;
        int length = toPlain(array);
        for (int i = 0; i < length - 1; i++) 
        {
            for (int j = i + 1; j < length; j++)
            {
                if ((array[i] > array[j]) && array[i] != 0 && array[j] != 0)
                {
                    inversions++;
                }
            }
        }
        // cout << inversions << endl;
        return inversions;
    }
    
    bool solvable()
    {
        if ((size % 2))
        {
            return !(countInversions() % 2);
        }
        else
        {
            return ((countInversions() + rowOfZero) % 2);        
        }
    }

    bool unsolvable()
    {
        return !(solvable());
    }

};