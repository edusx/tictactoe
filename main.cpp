//  TicTacToe Game functonality and console graphics for Fundamentals of Computing and Programming, Universiy of Warwick (WMG)
//  main.cpp
//  TicTacToe
//
//  Created by Eduard Sala X on 16/01/2018.
//  Copyright © 2018 Eduard Sala X. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

#define SIZE 3

// Game graphics
char dispValue[] = {' '};
char dispValuePlayer2[] = {'X'};
char dispValuePlayer1[] = {'O'};

// Counts if is Player 1 or Player 2 turn
int occupiedSpots = 0;

class tictactoe
{
    int b[SIZE][SIZE];
 
    void placeMove(unsigned int x, unsigned int y)
    {
        b[x][y] = 0;
    }
public:
    tictactoe() {
        for (unsigned int i = 0; i < SIZE; i++)
            for (unsigned int j = 0; j < SIZE; j++)
                b[i][j] = 0;
    }

    // Displays the board and its style
    void display()
    {
        cout << " ------------------- \n";
        for (unsigned int i = 0; i < SIZE; i++) {
            for (unsigned int j = 0; j < SIZE; j++)
                cout << " | " << dispValue[b[i][j]] << " | ";
            cout << "\n -------------------" << endl;
        }
    }
    bool setXY(unsigned int x, unsigned int y)
    {
        // Checking if the range is inside the available coordinates
        if ((x < 0 || x >= SIZE) || (y < 0 || y >= SIZE)) {
            cout << "\nInvalid input, try again! \n\n";
            return false;
        }
        // Putting the hits if available
        if (b[x][y] == 0) {
            if (occupiedSpots % 2 == 0) {
                // Player 1 turn, moves with "O".
                b[x][y] = 2;
                occupiedSpots++;
                return true;
            }
            else {
                // Player 2 turn, moves with "X".
                b[x][y] = 1;
                occupiedSpots++;
                return true;
                }
            }
        else {
            // When input is already occupied, therefore not available.
            cout << "\nInput already occupied, try again! \n\n";
            return false;}
    }
    bool isWinner()
    {
// Checking if is an horizontal match
        if (b[0][0] > 0 && b[0][0] == b[0][1] && b[0][0] == b[0][2]) {
            cout << "\nHorizontal match in the first row! \n\n";
            return true;
        }
        else if (b[1][0] > 0 && b[1][0] == b[1][1] && b[1][1] == b[1][2]) {
            cout << "\nHorizontal match in the second row! \n\n";
            return true;
        }
        else if (b[2][0] > 0 && b[2][0] == b[2][1] && b[2][1] == b[2][2]) {
            cout << "\nHorizontal match in the third row! \n\n";
            return true;
        }
// Checking if is a vertical match
        else if (b[0][0] > 0 && b[0][0] > 1 && b[0][0] == b[1][0] && b[1][0] == b[2][0]) {
            cout << "\nVeritcal match in the first column! \n\n";
            return true;
        }
        else if (b[0][1] > 0 && b[0][1] == b[1][1] && b[1][1] == b[2][1]) {
            cout << "\nVertical match in the second column! \n\n";
            return true;
        }
        else if (b[0][2] > 0 && b[0][2] == b[1][2] && b[1][2] == b[2][2]) {
            cout << "\nVertical match in the third column! \n\n";
            return true;
        }
// Checking if is a crossed match
        else if (b[0][0] > 0 && b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
            cout << "\nCrossed match, left-up to right-down! \n\n";
            return true;
        }
        else if (b[0][2] > 0 && b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
            cout << "\nCrossed match, right-up to left-down! \n\n";
            return true;
        }
        else return false;
        }
    
    bool arrayFull() {
        if (occupiedSpots == 9)
        {
         return true;
        }
        else return false;
    }
};
// class getting the player and machine movements
class players
{
public:
    players() {}
    unsigned int getX() {
        unsigned int x;
        cin >> x;
        return x;
    }
    unsigned int getY() {
        unsigned int y;
        cin >> y;
        return y;
    }
    unsigned int getXfromAI()
    {
        unsigned int x;
        x=rand()%SIZE;
        return x;
    }
    unsigned int getYfromAI()
    {
        unsigned int y;
        y=rand()%SIZE;
        return y;
    }
};

int main()
{
    START:tictactoe b;
    
    int playAgain;
    int playerSelection;
    int playerSelection2;
    
    // Questions and input to choose if human or machine at the beginning
    cout << "Would you like to start Player 1 as a machine? [Yes = 1 / No = 2]" << endl;
    cin >> playerSelection;
    cout << "Would you like to start Player 2 as a machine? [Yes = 1 / No = 2]" << endl;
    cin >> playerSelection2;
    
        // Game loop starts
do {
    players p1;
    b.display();
        unsigned int x;
        unsigned int y;
        do {
            // Choosing if machine or human player only the first time
            cout << "\n- Turn of Player 1. Please, input coordinates: " << endl;
            if (playerSelection == 2) {
            x = p1.getX();
            y = p1.getY();
            }
            
            else if (playerSelection == 1) {
            x = p1.getXfromAI();
            y = p1.getYfromAI();
            }
        } while (!b.setXY(x, y));
    if (b.isWinner()==true && occupiedSpots % 2 != 0) {
        b.display();
        cout << "\nGame over, " << "Player 1 won."<< " Please, play again soon." << endl;
        break;
    }
    else if (b.isWinner()==false && b.arrayFull()==true) {
        b.display();
        cout << "It seems there are no spots left! Let's call it a draw!" << endl;
        break;
    }
    players p2;
        b.display();
        do {
            // Choosing if machine or human player only the first time
            cout << "\n- Turn of Player 2. Please, input coordinates: " << endl;
            if (playerSelection2 == 2) {
            x = p2.getX();
            y = p2.getY();
            }
            
            else if (playerSelection2 == 1) {
            x = p2.getXfromAI();
            y = p2.getYfromAI();
            }
            
        } while (!b.setXY(x, y));
    if (b.isWinner()==true && occupiedSpots % 2 == 0) {
        b.display();
        cout << "\nGame over, " << "Player 2 won."<< " Please, play again soon." << endl;
        break;
    }
    else if (b.isWinner()==false && b.arrayFull()==true) {
        b.display();
        cout << "It seems there are no spots left! Let's call it a draw!" << endl;
        break;
    }
        // End of the game loop, final display of the game and question to play again
} while (!b.isWinner() || !b.arrayFull());

    occupiedSpots = 0;
    cout << "\nWould you like to play again? [Yes = 1 / No = 2]" << endl;
    cin >> playAgain;
    if (playAgain == 1) {goto START;}
    else{cout << "\nSee you again soon!" << endl;}
    
}
