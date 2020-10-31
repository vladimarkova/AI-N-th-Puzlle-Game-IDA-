#include <iostream>
#include <cmath>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
        rowOfZero = size - 1;
        colOfZero = size - 1;
        matrix[rowOfZero][colOfZero] = 0;
    }

    int getSize() const
    {
        return size;
    }

    int read()
    {
        cout << "Enter number of blocks:" << endl;

        int number, zeroPosition;
        cin >> number;
        size = sqrt(number + 1);

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

        return sqrt(number + 1);
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
        rowOfZero = posOfZero / size;
        colOfZero = posOfZero % size;
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

    vector<Board> neighbours() const
    {
        vector<Board> neighbours;
        if (colOfZero > 0)
        {
            Board neighbour = *this;
            neighbour.matrix[rowOfZero][colOfZero] = neighbour.matrix[rowOfZero][colOfZero - 1];
            neighbour.matrix[rowOfZero][colOfZero - 1] = 0;
            neighbour.colOfZero--;
            neighbours.push_back(neighbour);
        }
        return neighbours;
    }

};