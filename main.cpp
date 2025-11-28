#include <array>
#include <iostream>

using namespace std;

enum class Result { None, Player, Computer, Draw };

void printBoard(const array<char, 9> &board) {
  for (int i = 0; i < 9; i++) {
    cout << board[i];
    if (i == 8)
      cout << "\n";
    else if ((i + 1) % 3 == 0)
      cout << "\n---------\n";
    else
      cout << " | ";
  }
  cout << "\n";
}

void computerMove(array<char, 9> &board) {
  for (int i = 0; i < 9; i++) {
    if (board[i] != 'X' && board[i] != 'O') {
      board[i] = 'O';
      return;
    }
  }
}

void playerMove(array<char, 9> &board) {
  int choice = 0;
  do {
    cout << "Your turn(1-9):";
    cin >> choice;
  } while (choice < 1 || choice > 9 || board[choice - 1] == 'X' ||
           board[choice - 1] == 'O');

  board[choice - 1] = 'X';
}

Result checkRes(array<char, 9> &board) {
  if ((board[0] == board[1] && board[1] == board[2]))
    return board[0] == 'X' ? Result::Player : Result::Computer;
  if ((board[3] == board[4] && board[4] == board[5]))
    return board[0] == 'X' ? Result::Player : Result::Computer;
  if ((board[6] == board[7] && board[7] == board[8]))
    return board[0] == 'X' ? Result::Player : Result::Computer;

  if ((board[0] == board[3] && board[3] == board[6]))
    return board[0] == 'X' ? Result::Player : Result::Computer;
  if ((board[1] == board[4] && board[4] == board[7]))
    return board[0] == 'X' ? Result::Player : Result::Computer;
  if ((board[2] == board[6] && board[6] == board[8]))
    return board[0] == 'X' ? Result::Player : Result::Computer;

  if ((board[0] == board[4] && board[4] == board[8]))
    return board[0] == 'X' ? Result::Player : Result::Computer;
  if ((board[2] == board[4] && board[4] == board[6]))
    return board[0] == 'X' ? Result::Player : Result::Computer;

  for (int i = 0; i < 9; i++) {
    if (board[i] != 'X' && board[i] != 'O')
      return Result::None;
  }

  return Result::Draw;
}

int main() {
  array<char, 9> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  printBoard(board);

  bool shouldStop = false;
  Result res = Result::None;

  while (res == Result::None) {
    playerMove(board);
    if ((res = checkRes(board)) == Result::None) {
      computerMove(board);
      cout << "Computer played its move.\n";
    }

    printBoard(board);
    cout << "------------------------\n";
    res = checkRes(board);
  }

  if (res == Result::Player)
    cout << "You win!\n";
  else if (res == Result::Computer)
    cout << "Computer wins!\n";
  else
    cout << "Draw.\n";

  return 0;
}
