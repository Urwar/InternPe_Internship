#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));

void printBoard()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    for (int j = 0; j < COLS; ++j)
    {
        cout << "  " << j + 1 << " ";
    }
    cout << endl;
}

bool isValidMove(int col)
{
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

void makeMove(int col, char player)
{
    for (int i = ROWS - 1; i >= 0; --i)
    {
        if (board[i][col] == EMPTY)
        {
            board[i][col] = player;
            break;
        }
    }
}

bool checkWin(char player)
{
    // Check horizontally
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS - 3; ++j)
        {
            if (board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player)
            {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i < ROWS - 3; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player)
            {
                return true;
            }
        }
    }

    // Check diagonally (down-right)
    for (int i = 0; i < ROWS - 3; ++i)
    {
        for (int j = 0; j < COLS - 3; ++j)
        {
            if (board[i][j] == player &&
                board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player)
            {
                return true;
            }
        }
    }

    // Check diagonally (down-left)
    for (int i = 0; i < ROWS - 3; ++i)
    {
        for (int j = 3; j < COLS; ++j)
        {
            if (board[i][j] == player &&
                board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player &&
                board[i + 3][j - 3] == player)
            {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int currentPlayer = 1;

    while (true)
    {
        printBoard();
        cout << "Player " << currentPlayer << ", enter column (1-" << COLS << "): ";
        int col;
        cin >> col;

        if (isValidMove(col - 1))
        {
            makeMove(col - 1, (currentPlayer == 1) ? PLAYER1 : PLAYER2);
            if (checkWin((currentPlayer == 1) ? PLAYER1 : PLAYER2))
            {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isBoardFull())
            {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else
        {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}