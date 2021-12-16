#include <iostream>
using namespace std;

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 
int N = 3;

// display game board
void board() 
{
	system("cls"); // clear screen
	cout << "\n Tic Tac Toe\n\n";

	cout << "Player 1(X) - Player 2(O)" << endl << endl;
	cout << endl;

	for (int i = 0; i < 3; i++) 
	{
		int row = i * 3;
		cout << "     |     |     " << endl;
		cout << "  " << square[row + 1] << "  |  " << square[row + 2] << "  |  " << square[row + 3] << endl;
		if (i != 2) {
			cout << "_____|_____|_____" << endl;
		}
	}
	cout << "     |     |     " << endl;

}


// check winner
int checkWin()
{
	for (int i = 0; i < N; i++)
	{
		int row = i * 3;
		int col = i + 1;
		// check row
		if (square[row + 1] == square[row + 2] 
			&& square[row + 2] == square[row + 3]) return 1;
		// check column
		if (square[col] == square[col + N]
			&& square[col + N] == square[col + 2*N]) return 1;

	}
	if (square[1] == square[5] && square[5] == square[9]) return 1;
	else if (square[3] == square[5] && square[5] == square[7]) return 1;
	// hasWinner -> 1

	// draw -> 2
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9') return 2;
	// not complete -> 0
	else return 0;


}

void play()
{
	int player = 1;
	int hasWinner = 0;
	int move; // position of board
	char mark; // X || O

	do
	{
		board();
		player = (player % 2) ? 1 : 2;

		cout << "Player" << player << ", enter a number:  ";
		cin >> move;

		mark = (player == 1) ? 'X' : 'O';

		if (9 >= move > 0 && move == square[move] - '0') 
		{
			square[move] = mark;
		}
		else 
		{
			cout << "Invalid Move ";
			cin.ignore();
			cin.get();
		}

		hasWinner = checkWin();
		player++;

	} while (hasWinner == 0);
	board();

	// has winner
	if (hasWinner == 1)
	{
		cout << "==>\aPlayer " << --player << " win ";
	}
	else
	{
		cout << "==>\aGame draw";
	}

	cin.ignore();
	cin.get();
	

}

int main()
{
	//board();
	play();
	return 0;



}
