
// Author - @Jayashree Ghosh //
// Basic Tic Tac Toe Game //

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>

using namespace std;

char square[10] = {'o',' ',' ',' ',' ',' ',' ',' ',' ',' '};            // 'o' has been added just to match the index
int checkWin();                     /* function to check we have the winner or not, returns: 1 -> winner
                                                                                            -1 -> game in progress
                                                                                             0 -> draw     */

void drawBoard(string,string);                                                       // function to draw the board on our screen

int main()
{
    int player = 1,i,choice;                // i -> to check if the game is in progress or not
                                            // choice -> the position where player wants to mark
    char mark ;
    string name1,name2;

    cout<<"\n Player1 enter your firstname: ";
    cin>>name1;

    cout<<"\n Player2 enter your firstname: ";
    cin>>name2;
                           // X,0
 do{
    drawBoard(name1,name2);

    player = (player%2) ? 1 : 2;

    if(player == 1)
    cout<<"\n " <<name1<<" enter your choice (1-9): ";
    else
    cout<<"\n " <<name2<<" enter your choice (1-9): ";

    cin>>choice;

    mark = (player == 1)? 'X' : 'O';

    if (choice == 1 && square[1] == ' ')     // the place is still vacant
        square[1] = mark ;
    else if (choice == 2 && square[2] == ' ')
        square[2] = mark ;
    else if (choice == 3 && square[3] == ' ')
        square[3] = mark ;
    else if (choice == 4 && square[4] == ' ')
        square[4] = mark ;
    else if (choice == 5 && square[5] == ' ')
        square[5] = mark ;
    else if (choice == 6 && square[6] == ' ')
        square[6] = mark ;
    else if (choice == 7 && square[7] == ' ')
        square[7] = mark ;
    else if (choice == 8 && square[8] == ' ')
        square[8] = mark ;
    else if (choice == 9 && square[9] == ' ')
        square[9] = mark ;
    else{
        cout<<"Invalid Option !";
        player--;
        getch();
    }
    i = checkWin();
    player ++;

  }while(i == -1);

  drawBoard(name1,name2);

  if (i == 1){
    if((--player) == 1)
    cout<<"\n ==> "<<name1<<" won !!";
    else
        cout<<"\n ==> "<<name2<<" won !!";
    PlaySound(TEXT("D:\\C Programs\\Project\\Tic-Tac-Toe\\win.wav"),NULL,SND_SYNC);
  }
  else{
    cout<<"\n Game Draw !!";
  }
    getch();
    return 0;
}


int checkWin(){
  if(square[1]==square[2] && square[2]==square[3] && (square[1]=='X' || square[1]=='O'))
    return 1;
  else if (square[4]==square[5] && square[5]==square[6] && (square[4]=='X' || square[4]=='O'))
    return 1;
  else if (square[7]==square[8] && square[8]==square[9] && (square[7]=='X' || square[7]=='O'))
    return 1;
  else if (square[1]==square[4] && square[4]==square[7] && (square[1]=='X' || square[1]=='O'))
    return 1;
  else if (square[2]==square[5] && square[5]==square[8] && (square[2]=='X' || square[2]=='O'))
    return 1;
  else if (square[3]==square[6] && square[6]==square[9] && (square[3]=='X' || square[3]=='O'))
    return 1;
  else if (square[1]==square[5] && square[5]==square[9] && (square[1]=='X' || square[1]=='O'))
    return 1;
  else if (square[3]==square[5] && square[5]==square[7] && (square[3]=='X' || square[3]=='O'))
    return 1;
  else if(square[1] != ' ' && square[2] != ' ' && square[4] != ' ' && square[5] != ' ' && square[6] != ' ' && square[7] != ' ' && square[8] != '8' && square[9] != '9')
    return 0;              // No winner -> draw
  else
    return -1;            // Game still in progress
}


void drawBoard(string name1,string name2){
    system("cls");   // to clear screen
    cout<<"\n\n\tTic Tac Toe \n\n";
    cout<<" "<<name1<<" (X)    -    "<<name2<<" (O) \n\n\n";
    cout<<"      |     |     \n";
    cout<<"   "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<"\n";
    cout<<" _____|_____|_____\n";
    cout<<"      |     |     \n";
    cout<<"   "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<"\n";
    cout<<" _____|_____|_____\n";
    cout<<"      |     |     \n";
    cout<<"   "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<"\n";
    cout<<"      |     |     \n";
}
