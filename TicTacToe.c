#include <stdio.h>

char _player1Name[11] = {};
char _player2Name[11] = {};

char * _currentPlayer;
char * _winner;

char _playerTurn = 'X';

char _board[3][3];

bool _gameOver = false;

short _spacesTaken = 0;
short _wrongInputs = 0;

//function prototypes
void drawBoard();

void startGame();

bool makeMove(int r, int c);

void clearBoard();

bool checkForWinner();

void cleanupGarbage();

int main(int argc, char* argv[]) {
    
    // Players will enter their names here
	//for (short i = 0; i < 255; i++ ) { printf("\n"); }
    
	printf("-------------------------------------------  \n");
	printf("Welcome to Tic Tac Toe C 2013 for OSX!!! \n \n");
	printf("By Christopher Gorsky \n");
	printf("------------------------------------------- \n");
	system("clear");
    printf("Player1 enter your name! \n");
	scanf("%10s",_player1Name);
    
	printf("Player2 enter your name! \n");
	scanf("%10s",_player2Name);
    
	for (short i = 0; i < 255; i++ ) { printf("\n"); }
    
	clearBoard();
	drawBoard();
	startGame();
    
    return 0;

}

void drawBoard() {

	for (short i = 0; i < 255; i++ ) { printf("\n"); }
    
    printf("-------------------------------------------  \n");
	printf("Welcome to Tic Tac Toe C++ OSX 2013!!! \n \n");
	printf("By Christopher Gorsky \n");
	printf("------------------------------------------- \n");
	printf("Welcome %s and %s to Tic Tac Toe! \n \n",_player1Name,_player2Name);

	printf("  0   1   2\n");
	printf("0 %c | %c | %c \n",_board[0][0],_board[0][1],_board[0][2]);
	printf(" ---|---|---\n");
	printf("1 %c | %c | %c \n",_board[1][0],_board[1][1],_board[1][2]);
	printf(" ---|---|---\n");
	printf("2 %c | %c | %c \n \n",_board[2][0],_board[2][1],_board[2][2]);

}

void startGame() {

	while (! _gameOver) {

		if (_playerTurn == 'X') {_currentPlayer = _player1Name;}
		else {_currentPlayer = _player2Name;}

        int cinput = 0;
		int rowinput = 0;

	    char playerinput = 0;

		do {

			do {

				printf("%s Please enter your row: ",_currentPlayer);
				playerinput = getchar();
				printf("%c\n",playerinput);

				if (playerinput != '0'  &&  playerinput != '1'  && playerinput != '2')
                    {printf("Please input a valid number! \n");cleanupGarbage();}
			} while (playerinput != '0' &&  playerinput != '1' && playerinput != '2');

				if (playerinput == '0') {rowinput = 0;}
				if (playerinput == '1') {rowinput = 1;}
				if (playerinput == '2') {rowinput = 2;}

			do {

				printf("%s Please enter your column: ",_currentPlayer);
				playerinput = getchar();
				printf("%c\n",playerinput);

				if (playerinput != '0'  &&  playerinput != '1'  && playerinput != '2')
                    {printf("Please input a valid number! \n"); cleanupGarbage();}

			} while (playerinput != '0' &&  playerinput != '1' && playerinput != '2');

				if (playerinput == '0') {cinput = 0;}
				if (playerinput == '1') {cinput = 1;}
				if (playerinput == '2') {cinput = 2;}

		} while (!makeMove(rowinput,cinput));
	}
}

bool makeMove( int r, int c ) {

	if(_board[r][c] == ' ') {

		_board[r][c] = _playerTurn;
		drawBoard();

	    if (_playerTurn == 'X') {_currentPlayer = _player2Name; _playerTurn = 'O';}
		else {_currentPlayer = _player1Name; _playerTurn = 'X';}

		_spacesTaken++;

		if (checkForWinner() == true) {
			printf("%s wins! \n",_winner);

        

			clearBoard();
			for ( short i = 0; i < 100; i++ ) { printf("/n"); }

			_spacesTaken = 0;
			drawBoard();

		}
		else {

			if (_spacesTaken == 9) {

		    printf("It's a tie! \n");
			system("Pause");

			clearBoard();
			for (short i = 0; i < 255; i++ ) { printf("\n"); }

			_spacesTaken = 0;
			drawBoard();

			}
		}

		return true;
	}
	else {

		cleanupGarbage();
		printf("You cannot move there! \n");

		return false;
	}
}

bool checkForWinner() {

	// X
	if(_board[0][0] == 'X' && _board[0][1] == 'X' && _board[0][2] == 'X') {_winner = _player1Name;return true;}
	else if(_board[1][0] == 'X' && _board[1][1] == 'X' && _board[1][2] == 'X') {_winner = _player1Name;return true;}
	else if(_board[2][0] == 'X' && _board[2][1] == 'X' && _board[2][2] == 'X') {_winner = _player1Name;return true;}

    else if(_board[0][0] == 'X' && _board[1][0] == 'X' && _board[2][0] == 'X') {_winner = _player1Name;return true;}
	else if(_board[0][1] == 'X' && _board[1][1] == 'X' && _board[2][1] == 'X') {_winner = _player1Name;return true;}
	else if(_board[2][0] == 'X' && _board[1][2] == 'X' && _board[2][2] == 'X') {_winner = _player1Name;return true;}

    else if(_board[0][0] == 'X' && _board[1][1] == 'X' && _board[2][2] == 'X') {_winner = _player1Name;return true;}
	else if(_board[0][2] == 'X' && _board[1][1] == 'X' && _board[2][0] == 'X') {_winner = _player1Name;return true;}
	// O
	else if(_board[0][0] == 'O' && _board[0][1] == 'O' && _board[0][2] == 'O') {_winner = _player2Name;return true;}
	else if(_board[1][0] == 'O' && _board[1][1] == 'O' && _board[1][2] == 'O') {_winner = _player2Name;return true;}
	else if(_board[2][0] == 'O' && _board[2][1] == 'O' && _board[2][2] == 'O') {_winner = _player2Name;return true;}

    else if(_board[0][0] == 'O' && _board[1][0] == 'O' && _board[2][0] == 'O') {_winner = _player2Name;return true;}
	else if(_board[0][1] == 'O' && _board[1][1] == 'O' && _board[2][1] == 'O') {_winner = _player2Name;return true;}
	else if(_board[2][0] == 'O' && _board[1][2] == 'O' && _board[2][2] == 'O') {_winner = _player2Name;return true;}

    else if(_board[0][0] == 'O' && _board[1][1] == 'O' && _board[2][2] == 'O') {_winner = _player2Name;return true;}
	else if(_board[0][2] == 'O' && _board[1][1] == 'O' && _board[2][0] == 'O') {_winner = _player2Name; return true;}

	else {return false;}

}

void cleanupGarbage() {

	_wrongInputs++;

	if(_wrongInputs >= 3) {
        drawBoard();
        _wrongInputs = 0;
	}
}

void clearBoard() {
	//Inception
	for (short x = 0; x < 3; x++) {
		for (short y = 0; y < 3; y++) {
			_board[x][y] = ' ';
		}
	}
}






