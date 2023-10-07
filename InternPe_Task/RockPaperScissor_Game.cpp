#include <iostream> //Header File
#include <cstdlib>  //Random number genrated
#include <ctime>

#define ROCK 1 // I take rock as 1 in number form
#define PAPER 2
#define SCISSORS 3
using namespace std; // use cin and cout directly

int main()
{
    srand((unsigned int)time(NULL)); // Random number genrated at every time of execution.
    int player_throw = 0;            //// number changes into name
    bool draw = false;
    int ai_throw = (rand() % 3) + 1; // 0-2   //0+1 - 2+1
    do
    {
        cout << "Select your throw" << endl;
        cout << "1) Rock" << endl;
        cout << "2) Paper" << endl;
        cout << "3) Scissors" << endl;
        cout << "I choose: ";
        cin >> player_throw;

        if (ai_throw == ROCK)
        {
            cout << "AI throw ROCK" << endl;
        }
        else if (ai_throw == PAPER)
        {
            cout << "AI throw PAPER" << endl;
        }
        else if (ai_throw == SCISSORS)
        {
            cout << "AI throw SCISSORS" << endl;
        }
        // draw = false;
        if (player_throw == ai_throw)
        {
            draw = true;
            cout << "Draw! Play Again" << endl;
        }
        else if (player_throw == ROCK && ai_throw == PAPER)
        {
            cout << "PAPER beats ROCK! YOU LOSE" << endl;
        }
        else if (player_throw == ROCK && ai_throw == SCISSORS)
        {
            cout << "ROCK beats SCISSORS! YOU WIN" << endl;
        }
        else if (player_throw == PAPER && ai_throw == ROCK)
        {
            cout << "PAPER beats ROCK! YOU WIN" << endl;
        }
        else if (player_throw == PAPER && ai_throw == SCISSORS)
        {
            cout << "SCISSORS beats PAPER! YOU LOSE" << endl;
        }
        else if (player_throw == SCISSORS && ai_throw == ROCK)
        {
            cout << "ROCK beat SCISSORS! YOU LOSE" << endl;
        }
        else if (player_throw == SCISSORS && ai_throw == PAPER)
        {
            cout << "SCISSORS beats PAPER! YOU WIN" << endl;
        }
    } while (draw);
    return 0;
}