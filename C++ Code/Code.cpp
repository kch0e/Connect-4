#include <iostream>
using namespace std;

void createBoard(string board[7][7]){

  for (int i = 0; i<7; i++){
    for (int j = 0; j<7; j++){
      board[i][j] = " ";
    }
  }
}

void displayBoard(string board[7][7]){
  for (int i = 1; i<8; i++){
    cout << "| " << i << " |";
  }
  cout << "\n";
  for (int i = 0; i<7; i++){
    for (int j = 0; j<7; j++){
      cout << "| " << board[i][j] << " |";
    }
    cout << "\n";
  }
}

int main(){
  int columnY;
  cout << "Time to Play some Connect 4!" << endl;
  string players[2] = {"Player 1", "Player 2"};
  string pMarks[2] = {"X", "O"};
  int moves = 0;
  int top;
  int column;
  bool placed = false;
  bool full = false;
  bool over = false;
  bool taken[7][7] = {false};
  string board[7][7];
  string winner;
  createBoard(board);
  while (over == false){
    placed = false;
    displayBoard(board);
    cout << players[moves%2] << ", pick a column";
    cin >> column;
    if (taken[0][column-1] == true){
      cout << "Column Full. Play turn again.";
      cin >> column;
    }
    else if (column<1 || column>7){
      cout << "This is not a valid move. Play turn again" << endl;
      cin >> column;
    }
    else {
      while (placed == false){
        for (int j = 6; j>=0; j--){
          if (taken[j][column-1] == false){
            board[j][column-1] = pMarks[moves%2];
            placed = true;
            taken[j][column-1] = true;
            columnY = j;
            j = -1;
          }
        }
      }
    }
    int noX;
    for (int i = 0; i<7; i++){
      noX = 0;
      for (int j = 0; j<7; j++){
        if (board[i][j]== pMarks[moves%2]){
          noX++;
        }
        else {
          noX = 0;
        }
        if (noX == 4){
          winner = players[moves%2];
          i = 7;
          over = true;
          break;
        }
      }
    }
    for (int i = 0; i<7; i++){
      noX = 0;
      for (int j = 0; j<7; j++){
        if (board[j][i]== pMarks[moves%2]){
          noX++;
        }
        else {
          noX = 0;
        }
        if (noX == 4){
          winner = players[moves%2];
          i = 7;
          over = true;
          break;
        }
      }
    }
    noX = 0;
    for (int i = 4; i>-5; i--){
      if (board[columnY-i][column-1-i] == pMarks[moves%2]){
        noX++;
      }
      else {
        noX = 0;
      }
      if (noX == 4){
        winner = players[moves%2];
        i = -5;
        over = true;
        break;
      }
    }
    noX = 0;
    for (int i = 4; i>-5; i--){
      if (board[columnY-i][column-1+i] == pMarks[moves%2]){
        noX++;
      }
      else {
        noX = 0;
      }
      if (noX == 4){
        winner = players[moves%2];
        i = -5;
        over = true;
        break;
      }
    }
    top = 0;
    for (int i = 0; i<7; i++){
      if (taken[0][i] == true){
        top++;
      }
      if (top == 7){
        over = true;
        full = true;
        break;
      }3
    }
    moves++;
  }
  if (full == true && winner != players[moves%2]){
    displayBoard(board);
    cout << "Welp, Guess it's a tie";
  }
  else{
    displayBoard(board);
    cout << " Congrats!!! The winner is " << winner << "!!!";
  }
}
