#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Problem 1: 
    Implement a function that receives a int array and the array's size
    and prints the array in the following format:
    int a[ ] = { 1 , 1 , 2 , 3 , 5 , 8 , 13 }
    printArray(a, 7)
    >>> "{1, 1, 2, 3, 5, 8, 13}"

Problem 2:
    Receive two int arrays of equal length, a char representing the desired operation and a int of the arrays' length.
    Perform either the vectorial sum or subtraction (element-wise).
    There's no return, the result of the operation will be "overwritten" in the first array.
    If an invalid operation is passed, print "Inexistent operation!".

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 1, 2, 3};
    operateArrays(a, b, ’+’, 5);
    printArray(a, 5);
    >>> "{3, 6, 4, 6, 8}"

    operateArrays(a, b, ’−’, 5);
    printArray(a, 5)
    >>> "{1, 2, 3, 4, 5}"

    operateArrays(a, b, ’%’, 5);
    >>> "Inexistent operation!"

Problem 3:
    Implement a rock-paper-scissors-lizard-Spock.
    The rules are:
        1. scissors cuts paper;
        2. paper covers rock;
        3. rock crushes lizard;
        4. lizard poisons Spock;
        5. Spock smashes scissors;
        6. scissors decapitates lizard;
        7. lizard eats paper;
        8. paper disproves Spock;
        9. Spock vaporizes rock;
        10. rock crushes scissors.
    
    You are to implement a function that receives each players' moves and returns the winner (the first or the second).
    In the main, create a loop to have a best of 3, always printing the score and at the end returning the winner,
    if the game ends in a tie, keep playing, observe the examples:
    
    paper rock
    >>> 0 1

    lizard Spock
    >>> 1 1

    lizard rock
    >>> 1 2
    >>> "Bazinga! Player two has won."

    scissors paper
    >>> 1 0

    lizard lizard
    >>> 1 0

    Spock rock
    >>> 2 0
    >>> "Bazinga! Player one has won."

Problem 4:
    Implement a 1-dimensional char array that will represent a 3x3 tic-tac-toe board.
    Create a game function. It must receive the array that represents the game,
    an int representing the index where the play will occur and a char representing the play
    ("X" or "O"). The function should detect when a play occurs in an index that already
    has an element, and warn the user that this is not a valid play.
    The function should also detect when a play causes a victory,
    checking the condition of "three equal symbols in a row". Every time a play is made,
    it should print the current game state after the play.

    tictactoe(array, 4, ’X’)
    >>> ? ? ?
        ? X ?
        ? ? ?

    tictactoe(array, 4, ’O’)
    >>> "Invalid play!"

    tictactoe(array, 0, ’X’)
    >>> X ? ?
        ? X ?
        ? ? ?

    tictactoe(array, 8, ’X’)
    >>> X ? ?
        ? X ?
        ? ? X
    
    >>> "Congratulations! Player one has won."
*/

void printArray(int iArray[], int iSize);
void operateArrays(int (&iArray1)[], int iArray2[], char cOperation, int iSize);
void bazinga();
void tictactoe(char (&cArray)[], int iIndex, char cPlay);

int main()
{
    // 1
    int iArray[] = {1, 1, 2, 3, 5, 8, 13};
    printArray(iArray, 7);

    // 2
    int iArray1[] = {1, 2, 3, 4, 5};
    int iArray2[] = {2, 4, 1, 2, 3};
    
    cout << "\niArray1 + iArray2 = ";
    operateArrays(iArray1, iArray2, '+', 5);
    printArray(iArray1, 5);
    
    cout << "\niArray1 - iArray2 = ";
    operateArrays(iArray1, iArray2, '-', 5);
    printArray(iArray1, 5);

    cout << "\niArray1 / iArray2 = ";
    operateArrays(iArray1, iArray2, '/', 5);

    // 3
//    bazinga();

    // 4
    char cArray[] = {'?', '?', '?', '?', '?', '?', '?', '?', '?'};
    tictactoe(cArray, 4, 'X');
    tictactoe(cArray, 4, 'O');
    tictactoe(cArray, 1, 'O');
    tictactoe(cArray, 0, 'X');
    tictactoe(cArray, 7, 'O');
    tictactoe(cArray, 8, 'X');

    return 0;
}

void printArray(int iArray[], int iSize)
{
    cout << "{";

    for (int i = 0; i < iSize - 1; i++)
    {
        cout << iArray[i] << ", ";
    }

    cout << iArray[iSize - 1] << "}" << endl;
}

void operateArrays(int (&iArray1)[], int iArray2[], char cOperation, int iSize)
{
    switch (cOperation)
    {
    case '+':
        for (int i = 0; i < iSize; i++)
        {
            iArray1[i] += iArray2[i];
        }
        break;
    case '-':
        for (int i = 0; i < iSize; i++)
        {
            iArray1[i] -= iArray2[i];
        }
        break;
    default:
        cout << "Inexistent operation!" << endl;
        break;
    }
}

void bazinga()
{
    int iScorePlayer1 = 0, iScorePlayer2 = 0;
    enum Options {rock, paper, scissors, lizard, Spock};
    
    while (iScorePlayer1 < 2 && iScorePlayer2 < 2)
    {
        string sInput1, sInput2;
        Options sPlayer1, sPlayer2;

        cout << "Input your moves:" << endl;
        cin >> sInput1 >> sInput2;

        if (sInput1 == "rock")
        {
            sPlayer1 = rock;
        } else if (sInput1 == "paper")
        {
            sPlayer1 = paper;
        } else if (sInput1 == "scissors")
        {
            sPlayer1 = scissors;
        } else if (sInput1 == "lizard")
        {
            sPlayer1 = lizard;
        } else if (sInput1 == "Spock")
        {
            sPlayer1 = Spock;
        }

        if (sInput2 == "rock")
        {
            sPlayer2 = rock;
        } else if (sInput2 == "paper")
        {
            sPlayer2 = paper;
        } else if (sInput2 == "scissors")
        {
            sPlayer2 = scissors;
        } else if (sInput2 == "lizard")
        {
            sPlayer2 = lizard;
        } else if (sInput2 == "Spock")
        {
            sPlayer2 = Spock;
        }

        switch (sPlayer1)
        {
            case rock:
                switch (sPlayer2)
                {
                    case rock:
                        cout << "Tie!" << endl;
                        break;
                    
                    case scissors:
                    case lizard:
                        cout << "Player 1 has scored a point!" << endl;
                        iScorePlayer1++;
                        break;

                    case Spock:
                    case paper:
                        cout << "Player 2 has scored a point!" << endl;
                        iScorePlayer2++;
                        break;
                }
                break;

            case paper:
                switch (sPlayer2)
                {
                    case paper:
                        cout << "Tie!" << endl;
                        break;
                    
                    case rock:
                    case Spock:
                        cout << "Player 1 has scored a point!" << endl;
                        iScorePlayer1++;
                        break;

                    case scissors:
                    case lizard:
                        cout << "Player 2 has scored a point!" << endl;
                        iScorePlayer2++;
                        break;
                }
                break;

            case scissors:
                switch (sPlayer2)
                {
                    case scissors:
                        cout << "Tie!" << endl;
                        break;
                    
                    case paper:
                    case lizard:
                        cout << "Player 1 has scored a point!" << endl;
                        iScorePlayer1++;
                        break;
                    
                    case rock:
                    case Spock:
                        cout << "Player 2 has scored a point!" << endl;
                        iScorePlayer2++;
                        break;
                }
                break;

            case lizard:
                switch (sPlayer2)
                {
                    case lizard:
                        cout << "Tie!" << endl;
                        break;
                    
                    case paper:
                    case Spock:
                        cout << "Player 1 has scored a point!" << endl;
                        iScorePlayer1++;
                        break;

                    case rock:
                    case scissors:
                        cout << "Player 2 has scored a point!" << endl;
                        iScorePlayer2++;
                        break;
                }
                break;

            case Spock:
                switch (sPlayer2)
                {
                    case Spock:
                        cout << "Tie!" << endl;
                        break;
                    
                    case rock:
                    case scissors:
                        cout << "Player 1 has scored a point!" << endl;
                        iScorePlayer1++;
                        break;
                    
                    case paper:
                    case lizard:
                        cout << "Player 2 has scored a point!" << endl;
                        iScorePlayer2++;
                        break;
                }
                break;
        }
    }

    if (iScorePlayer1 == 2)
    {
        cout << "Bazinga! Player 1 has won." << endl;
    } else
    {
        cout << "Bazinga! Player 2 has won." << endl;
    }
}

void tictactoe(char (&cArray)[], int iIndex, char cPlay)
{
    if (cArray[iIndex] != '?')
    {
        cout << "Invalid move!" << endl;
        return;
    }

    cArray[iIndex] = cPlay;

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;
        }

        cout << cArray[i] << " ";
    }

    cout << endl;

    if ((cArray[0] == cArray[1] && cArray[1] == cArray[2] && cArray[2] != '?') ||
        (cArray[3] == cArray[4] && cArray[4] == cArray[5] && cArray[5] != '?') ||
        (cArray[6] == cArray[7] && cArray[7] == cArray[8] && cArray[8] != '?') ||
        (cArray[0] == cArray[3] && cArray[3] == cArray[6] && cArray[6] != '?') ||
        (cArray[1] == cArray[4] && cArray[4] == cArray[7] && cArray[7] != '?') ||
        (cArray[2] == cArray[5] && cArray[5] == cArray[8] && cArray[8] != '?') ||
        (cArray[0] == cArray[4] && cArray[4] == cArray[8] && cArray[8] != '?') ||
        (cArray[2] == cArray[4] && cArray[4] == cArray[6] && cArray[6] != '?') )
    {
        cout << "Player " << cPlay << " has won!" << endl;
        return;
    }
}