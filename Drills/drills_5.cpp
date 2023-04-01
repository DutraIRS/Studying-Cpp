/*
Problem 1:
Given a natural number n, your goal here is to build a function
that will print a 2D pyramid of height n, using ’#’. Then, it will print
that same pyramid upside down, forming a diamond. As in the examples:
>>> 3
    ##
   ####
  ######
   ####
    ##

>>> 4
     ##
    ####
   ######
  ########
   ######
    ####
     ##

Problem 2:
Make a "isPrime" function that given a number n smaller than 100000,
returns 1 if n is prime and 0 if n is not prime. Follow the example: 
>>> 3
1
>>> 8
0
>>> 11
1

Now use the function from the previous item to make a recursive function
that will count all primes between 1 and the m given.

Problem 3:
"Connect 4" is a game composed of a vertical "board" divided in 6 rows
and 7 columns, where players alternate placing their pieces on top of a
chosen column. Since the board is vertical, the piece falls until the
lowest possible line in that column. The goal of the player is to connect
four pieces of his color in a straight line, which can be vertical,
horizontal, or diagonal.
Implement a functional version of this game using a char array, where
'O' represents an empty space, 'L' and 'X' represent the two colors of
pieces. The board starts completely empty, and the pieces will be added
through a "play" function, which receives the board array, a char
representing the type of piece to be played, and an int, representing the
column number where the piece will be inserted (from 1 to 7).
In each play, it should be checked if the move is valid (that is, if it is
being made in an existing column and that is not full), and it should also
be checked if the move will lead to the player's victory. Regardless of
these checks, the function will also print the current state of the board
after processing the play. See the example:
>>> play(board, "X", 7)
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O X

>>> play(board, "L", 8)
 "Invalid play!"
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O O
 O O O O O O O X
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPrime (int n);
int countPrimes (int m);
void printPyramid (int n);
void connectFour (char (&board)[6][7], char piece, int column);
bool hasWon (char (&board)[6][7], char piece);

int main()
{
    // 1
    cout << countPrimes(100) << endl;
    cout << countPrimes(1000) << endl;
    
    // 2
    printPyramid(3);
    printPyramid(5);

    // 3
    char cBoard[6][7] = {   {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
                            {'O', 'O', 'O', 'O', 'O', 'O', 'O'}};
                            
    connectFour(cBoard, 'X', 7);
    connectFour(cBoard, 'L', 7);
    connectFour(cBoard, 'X', 7);
    connectFour(cBoard, 'L', 7);
    connectFour(cBoard, 'X', 6);
    connectFour(cBoard, 'L', 6);
    connectFour(cBoard, 'X', 5);
    connectFour(cBoard, 'L', 5);
    connectFour(cBoard, 'X', 4);

    return 0;
}

bool isPrime (int n)
{
    if (n == 1)
    {
        return false;
    } else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int countPrimes (int m)
{
    if (m == 1)
    {
        return 0;
    } else if (isPrime(m))
    {
        return 1 + countPrimes(m - 1);
    } else
    {
        return countPrimes(m - 1);
    }
}

void printPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        for (int k = 0; k < i; k++)
        {
            cout << "#";
        }
        
        for (int k = 0; k < i; k++)
        {
            cout << "#";
        }

        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        cout << endl;
    }
    
    for (int i = n; i > 0; i--)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        for (int k = 0; k < i; k++)
        {
            cout << "#";
        }
        
        for (int k = 0; k < i; k++)
        {
            cout << "#";
        }

        for (int j = n - i; j > 0; j--)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void connectFour (char (&board)[6][7], char piece, int column)
{
    if (column < 1 || column > 7)
    {
        cout << "Invalid play!" << endl;
    } else
    {
        for (int i = 6; i > 0; i--)
        {
            if (board[i][column - 1] == 'O')
            {
                board[i][column - 1] = piece;
                break;
            }

            if (i == 0)
            {
                cout << "Invalid play!" << endl;
            }
        }
    }
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Check for victory
    if (hasWon(board, piece))
    {
        cout << "Player " << piece << " wins!" << endl;
    }
}

bool hasWon (char (&board)[6][7], char piece)
{
    // Horizontal
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == piece && board[i][j + 1] == piece && board[i][j + 2] == piece && board[i][j + 3] == piece)
            {
                return true;
            }
        } 
    }

    // Vertical
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == piece && board[i + 1][j] == piece && board[i + 2][j] == piece && board[i + 3][j] == piece)
            {
                return true;
            }
        } 
    }

    // Main diagonal
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == piece && board[i + 1][j + 1] == piece && board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece)
            {
                return true;
            }
        } 
    }

    // Secondary diagonal
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j < 7; j++)
        {
            if (board[i][j] == piece && board[i + 1][j - 1] == piece && board[i + 2][j - 2] == piece && board[i + 3][j - 3] == piece)
            {
                return true;
            }
        } 
    }

    return false;
}