#include <iostream>
using namespace std;                                               // Cin and cout directly used
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Global
char player = 'X';
int n;
void printMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " "; // it will print matrix, two loops for row and column
        }
        cout << endl;
    }
}
void userInput()
{
    int num;
    cout << "Press number of Filled ";
    cin >> num;
    if (num == 1)
    {
        if (matrix[0][0] == '1')
        {
            matrix[0][0] = player;
        }
        else
        {
            cout << "This Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 2)
    {
        if (matrix[0][1] == '2')
        {
            matrix[0][1] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 3)
    {
        if (matrix[0][2] == '3')
        {
            matrix[0][2] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 4)
    {
        if (matrix[1][0] == '4')
        {
            matrix[1][0] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 5)
    {
        if (matrix[1][1] == '5')
        {
            matrix[1][1] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 6)
    {
        if (matrix[1][2] == '6')
        {
            matrix[1][2] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 7)
    {
        if (matrix[2][0] == '7')
        {
            matrix[2][0] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 8)
    {
        if (matrix[2][1] == '8')
        {
            matrix[2][1] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
    else if (num == 9)
    {
        if (matrix[2][2] == '9')
        {
            matrix[2][2] = player;
        }
        else
        {
            cout << "Filled is already in use so Try Again!" << endl;
            userInput();
        }
    }
}
void TogglePlayer()
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}
char win()
{
    // First Player
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
    {
        return 'X';
    }

    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
    {
        return 'X';
    }

    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
    {
        return 'X';
    }
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
    {
        return 'X';
    }
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
    {
        return 'X';
    }
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
    {
        return 'X';
    }
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
    {
        return 'X';
    }
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
    {
        return 'X';
    }

    // Second Player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
    {
        return 'O';
    }

    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
    {
        return 'O';
    }

    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
    {
        return 'O';
    }
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
    {
        return 'O';
    }
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
    {
        return 'O';
    }
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
    {
        return 'O';
    }
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
    {
        return 'O';
    }
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
    {
        return 'O';
    }
    return '/';
}
int main()
{
    /*1 2 3
    4 5 6
    7 8 9   this matrix pattern to follow*/
    cout << "This is a Tic-Tac-Toe Game" << endl;
    printMatrix();
    n = 0;
    while (1)
    {
        n++;
        userInput();
        printMatrix();
        if (win() == 'X')
        {
            cout << "X wins!" << endl;
            break;
        }
        else if (win() == 'O')
        {
            cout << "O wins!" << endl;
            break;
        }
        // Draw Game Condition
        else if (win() == '/' && n == 9)
        {
            cout << "It's a Draw!" << endl;
            break;
        }
        TogglePlayer();
    }
    return 0;
}