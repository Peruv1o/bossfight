#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <conio.h>

using namespace std;

void controlGame();
void arena();
void mainMenu();
void playGame();


//universal 

int score = 0;
bool chosenResolution = false;
int n;
bool quitGame = false;


void arena()
{
    bool hit = false;
    if(chosenResolution == false)
    {
        cout << "Select Grid resolution (N x N, and more than 4): ";
        while(n < 4)
        {
            cin >> n;
        }
        chosenResolution = true;
    }
    int val = 1;
    int player = 1;
    bool back = false;
    bool attack = false;
    while(true)
    {
        system("cls");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == val-1)         // enemy
                {
                    if(attack == true && j == (player-1))
                    {
                        cout << "[X] ";
                        score++;
                        hit = true;
                    }
                    else
                    {
                        cout << "[A] ";
                    }
                }
                else if(i == n-1 && j == player-1) // player
                {
                    cout << "[O] ";
                }
                else if(i == (n-2))
                {
                    if(j == (player-1))
                    {
                        if(attack == true)
                        {
                            cout << "[X] ";
                        }
                        else
                        {
                            cout << "[ ] ";
                        }
                    }
                    else
                    {
                        cout << "[=] ";
                    }
                }
                else
                {
                    if(attack == true && j == (player-1))
                    {
                        cout << "[X] ";

                    }
                    else 
                    {
                        cout << "[ ] ";
                    }
                }
            }
            if(i == 0)
            {
                cout << '\t' << "Score: " << score;
            }
            else if(i == 1)
            {
                cout << '\t' << "q - quit game mid session";
            }
            else if(i == 2)
            {
                cout << '\t' << "w - attack";
            }
            else if(i == 3)
            {
                cout << '\t' << "a & d - move left n' right ";
            }
            cout << endl << endl;
        }
        attack = false;
        
        if(!back) // moving forward
        {
            val++;
            if(val >= n) // reached right end
                back = true;
        }
        else // moving backward
        {
            val--;
            if(val <= 1) // reached left end
                back = false;
        }
        
        if (_kbhit()) // key pressed
        {
            char move = _getch();
            if (move == 'a') // press 'p' to pause/resume
            {
                if(player > 1)
                {
                    player--;
                }
            }
            else if(move == 'd')
            {
                if(player < n)
                {
                    player++;
                }
            }
            else if(move == 'w')
            {
                attack = true;
            }
            else if(move == 'q')
            {
                quitGame = true;
                break;
            }
        }

        if(hit == true)
        {
            this_thread::sleep_for(chrono::milliseconds(1000));
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void mainMenu()
{
    system("cls");
    cout << "1. Play Game" << endl;
    cout << "2. Controls" << endl;
    cout << "3. Quit Game" << endl << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1 : playGame(); break;
        case 2 : controlGame(); break;
        case 3 : system("exit"); break;
        default : mainMenu(); break;
    }
}

void controlGame()
{
    system("cls");
    cout << "q - quit game mid session" << endl;
    cout << "w - attack" << endl;
    cout << "a & d - move left n' right " << endl;
    system("pause");
    mainMenu();
}

void playGame()
{
    system("cls");
    while(true)
    {
        arena();
        if(quitGame)
        {
           break;
        }
    }
}

int main()
{
    mainMenu();
    cout << "bwa";
    return 0;
}