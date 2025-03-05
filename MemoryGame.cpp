// Author: Alexandra L
// Date: 8-30-24
// Filename: MemoryGame.cpp
// Memory Game
//
// Would be cool to add a GUI someday

#include <iostream>
#include <ctime>

using namespace std;

void initialize(int deck[][4], int pool[]);
void instructions();
void show_face_up_cards(int deck[][4]);
void pick(int deck[][4], int player[]);
void gameplay(int deck[][4], int p1[], int p2[]);
bool check_matrix_empty(int deck[][4]);
void scores(int p1[], int p2[]);
void show_progress(int deck[][4]);

int main() {
    int deck[4][4];
    int p1 [8] = {0};
    int p2 [8] = {0};

    while(true){
        int pool[16] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
        char ready;
        cout << "Are Player1 and Player2 ready?: (y/n)";
        cin >> ready;
        cout << endl;
        if(ready == 'n')
            break;
        initialize(deck, pool);
        instructions();
        show_face_up_cards(deck);
        gameplay(deck, p1, p2);
    }

    return 0;
}

void gameplay(int deck[][4], int p1[], int p2[]){
    while(true){
        int n = 1;
        cout << "Turn " << n << ":" << endl;
        cout <<"Player 1: " << endl;
        pick(deck, p1);

        if(check_matrix_empty(deck)){
            cout << "Good memory!" << endl;
            scores(p1, p2);
            break;
        }

        cout <<"Player 2: " << endl;
        pick(deck, p2);

        if(check_matrix_empty(deck)){
            cout << "Good memory!" << endl;
            scores(p1, p2);
            break;
        }
        n++;
    }
}

void pick(int deck[][4], int player[]){
    int row1, col1, row2, col2, temp1, temp2;
    while(true){
        show_progress(deck);
        cout << "Please pick a row and column(separated by a space): ";
        cin >> row1 >> col1;
        cout << endl;
        temp1 = deck[row1-1][col1-1];
        cout << "The card is a " << temp1 << endl;
        if(temp1 == 0){
            cout << "Card has already been removed, please pick again." << endl;
            continue;
        }
        else
            break;
        }
    while(true){
        cout << "Please pick a second card\n(row and column, separated by a space): ";
    cin >> row2 >> col2;
    cout << endl;
    temp2 = deck[row2-1][col2-1];
    cout << "The card is a " << temp2 << endl;
    if(temp2 == 0){
            cout << "Card has already been removed, please pick again." << endl;
            continue;
        }
        else
            break;
    }
    if(temp1 == temp2){
        player[temp1 - 1] = temp1;
        deck[row1-1][col1-1] = 0;
        deck[row2-1][col2-1] = 0;
        cout << "Your cards match!\n you get a point!" << endl;
    }
    else{
        cout << "The cards do not match. Sorry." << endl;
    }

}

void scores(int p1[], int p2[]){ 
    int pl1 = 0;
    int pl2 = 0;
    cout << "You've picked all the cards!" << endl;
    cout << "Player1 matches: " << endl;
    for(int i = 0; i < 8; i++){
        if(p1[i] != 0){
            cout << p1[i] << endl;
            pl1 += 1;
        }
    }
    cout << "Player2 matches: " << endl;
    for(int j = 0; j < 8; j++){
        if(p2[j] != 0){
            cout << p2[j] << endl;
            pl2 += 1;
        }
    }
    cout << "Scores:\nPlayer1: " << pl1 << endl;
    cout << "Player2: " << pl2 << endl;
}

void initialize(int deck[][4], int pool[]) {
    srand((unsigned int)time(NULL));
    int x = 0;
    int y = 0;
    for(int i = 0; i < 16; i++){
        int temp = -1;
        while(temp == -1){
            int pick = rand() % 16;
            if(pool[pick] == 0){
                continue;
            }
            else{
                temp = pool[pick];
                pool[pick] = 0;
            }
        }
        deck[x][y] = temp;
        x++;
        if (x == 4) {
            x = 0;
            y++;
            if (y == 4) {
                break;
            }
        }
    }
}

bool check_matrix_empty(int deck[][4]){
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            if(deck[x][y] != 0)
                return false;
        }
    }
    return true;
}

void instructions(){
    cout << "\nWelcome to the memory game!\n" << endl;
    cout << "The rules are simple:\nThere are 16 cards face down & 8 possible matches." << endl;
    cout << "Take turns picking two cards at a time. \nTurn them over to try to find matches." << endl;
    cout << "The cards flip back over if they don't match.\n" << endl;
    cout << "    1   2   3   4 " << endl;
    cout << "1  [?] [?] [?] [?]" << endl;
    cout << "2  [?] [?] [?] [?]" << endl;
    cout << "3  [?] [?] [?] [?]" << endl;
    cout << "4  [?] [?] [?] [?]" << endl;
    
}

void show_face_up_cards(int deck[][4]){
    for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
                cout << " [" << deck[x][y] << "]";
            }
            cout << endl;
        }
}

void show_progress(int deck[][4]){
    for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
                if(deck[x][y] == 0)
                    cout << " [0]"; 
                else
                    cout << " [?]";
            }
            cout << endl;
        }
}