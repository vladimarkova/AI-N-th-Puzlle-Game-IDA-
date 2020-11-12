#pragma once
#include <iostream>
#include <ctime>
#include "Board.h"
#include "IDAStar.h"
using namespace std;

void gameTest()
{
    char response = '1';
    Board board;
    while(response != '0')
    {
            time_t startTime;
            time(&startTime);
            board.read();
            cout << endl;
            int size = board.getSize();
            while (board.unsolvable())
            {
                cout << "This board does not have a solution. Please try with another board." << endl;
                board.read();
                size = board.getSize();
            }
            board.print(); 

            cout << "Enter position of zero in result:" << endl;
            int posOfZero;
            cin >> posOfZero;

            IDAStar game;
            game.setStart(board);
            game.setGoal(posOfZero, size);
            string result = game.play();
            // game.play();
            if (result.size() > 0 && result == "UNSOLVABLE")
            {
                cout << "This board is unsolvable!" << endl;
            }
            else
            {
                cout << result.size() << endl;
                for (int i = 0; i < result.size(); i++)
                {
                    if(result[i] == 'L')
                    {
                        cout << "left" << endl;
                    }
                    if(result[i] == 'R')
                    {
                        cout << "right" << endl;
                    }
                    if(result[i] == 'U')
                    {
                        cout << "up" << endl;
                    }
                    if(result[i] == 'D')
                    {
                        cout << "down" << endl;
                    }
                }
            }
            cout << "The time it took to finish the task in seconds: " << time(NULL) - startTime << 's' << endl;
            cout << "Enter 0 to stop the game or 1 to continue." << endl;
            cin >> response;
            if (response == '0')
            {
                cout << "Game finished!" << endl;
            }
            else
            {
                cout << "New try started." << endl;
            }
    }
}
