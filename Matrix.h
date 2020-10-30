#include <iostream>
#include <cstring>
using namespace std;

class Matrix
{
    private:
    int size;
    int matrix[16][16];

    public:
    Matrix()
    {
        size = 9;
        int number = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = number;
            }
            number++;
        }
        matrix[size-1][size-1] = 0;
    }

    Matrix(int size, int matrix[100][100])
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }

    int getSize()
    {
        return size;
    }

    void init()
    {
        cout << "Enter matrix size:" << endl;
        int size;
        cin >> size;
        this->size = size;
        cout << "Enter matrix: " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> matrix[i][j];
            }
            cout << endl;
        }
    }
};