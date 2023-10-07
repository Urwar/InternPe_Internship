#include <iostream> //Header File
#include <cstdlib>  //Random number should be Generated
#include <ctime>
using namespace std; // cin and cout used directly

int main()
{
    int num = 0;
    int turn = 4;
    int check = 1;
    srand((unsigned int)time(0));   // After Every execution it gives new random number
    int guess = (rand() % 100) + 1; // Index is start from 0 so 0-99     0+1=99+1
    cout << "Guess a Number between 1 to 100" << endl;
    do
    {
        cout << "Turns Remaining " << turn + 1 << endl;
        cin >> num;

        if (num == guess)
        {
            cout << "Congratulation you are Correct" << endl;
            check = 0;
        }
        else if (num < guess)
        {
            cout << "Try a bigger number" << endl;
        }
        else if (num > guess)
        {
            cout << "Try a smaller number" << endl;
        }
    } while (check = 1 && turn--);
    cout << "You are failed and the Guessing Number is " << guess << endl;
    return 0;
}
