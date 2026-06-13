#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void show(char ticarray[][3]){
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (j > 0 )
            {
                cout << "| ";
            }
            
            cout << ticarray[i][j] << "  ";
        }
        cout << '\n';
        cout << "------------";
        cout << '\n';
    }
}

void checkcondition(char &input){
    while (input < '1' || input > '9')
    {
        cout << "Invalid Input! Try again." << '\n';
        cin >> input;
    }
}

void humanPlay(char ticarray[][3]){
    char HumIn;
    int inrow = 0;
    int incol = 0;
    bool validmove = false;

    while (validmove == false){

        cout << "Human's turn!"<< '\n';
        cout << "Input a number from 1-9 to place X" << '\n';
        cin >> HumIn;
        checkcondition(HumIn);

        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (ticarray[i][j] == HumIn)
                {
                    inrow = i;
                    incol = j;
                    break;
                }
            }
        }

        if (ticarray[inrow][incol] != 'X' && ticarray[inrow][incol] != 'O')
        {
            ticarray[inrow][incol] = 'X';
            validmove = true;
        }
        else{
            cout << "Already taken.\n";
        }
    }   
}

void CompPlay(char ticarray[][3]){
    char CompIn;
    int inrow = 0;
    int incol = 0;
    bool validmove = false;

    while (validmove == false){

        CompIn = (rand() % 9 + 1) + '0';

        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (ticarray[i][j] == CompIn)
                {
                    inrow = i;
                    incol = j;
                    break;
                }
            }
        }

        if (ticarray[inrow][incol] != 'X' && ticarray[inrow][incol] != 'O')
        {
            ticarray[inrow][incol] = 'O';
            validmove = true;
        }
    }
}   

bool checkwin(char ticarray[][3], char& winner){
    if (ticarray[0][0] == ticarray[0][1] && ticarray[0][1] == ticarray[0][2]) {
        winner = ticarray[0][0]; 
        return true;
    }
    if (ticarray[1][0] == ticarray[1][1] && ticarray[1][1] == ticarray[1][2]) {
        winner = ticarray[1][0];
        return true;
    }
    if (ticarray[2][0] == ticarray[2][1] && ticarray[2][1] == ticarray[2][2]) {
        winner = ticarray[2][0];
        return true;
    }

    if (ticarray[0][0] == ticarray[1][0] && ticarray[1][0] == ticarray[2][0]) {
        winner = ticarray[0][0];
        return true;
    }
    if (ticarray[0][1] == ticarray[1][1] && ticarray[1][1] == ticarray[2][1]) {
        winner = ticarray[0][1];
        return true;
    }
    if (ticarray[0][2] == ticarray[1][2] && ticarray[1][2] == ticarray[2][2]) {
        winner = ticarray[0][2];
        return true;
    }

    if (ticarray[0][0] == ticarray[1][1] && ticarray[1][1] == ticarray[2][2]) {
        winner = ticarray[0][0];
        return true;
    }
    if (ticarray[0][2] == ticarray[1][1] && ticarray[1][1] == ticarray[2][0]) {
        winner = ticarray[0][2];
        return true;
    }

    return false;
}

int main(){
    srand(time(0));
    
    char tic[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char winningSide = ' ';
    
    for (int i = 1; i <= 5; i++){
        show(tic);
        humanPlay(tic);
        
        if (i < 5) {
            CompPlay(tic);
        }
        
        if (i >= 3)
        {
            if (checkwin(tic, winningSide)) {
                show(tic); 
                cout << "Match Determined! Player " << winningSide << " Wins!" << '\n';
                return 0; 
            }
        }
    }
    
    show(tic);
    cout << "It's a draw!" << '\n';
    return 0;
}