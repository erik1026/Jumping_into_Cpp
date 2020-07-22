#include <iostream>

enum Turn
{
	pl1 = 1,
	pl2 = 2
};

enum Slots
{
	player1 = 'X',
	player2 = 'O',
	empty = '_'
};

//	Getting memory access exeptions thrown
//	Will attempt to fix later
void create_board(char** board, int length, int height)
{
	for (int i = 0; i < height; i++)
	{
		board[i] = new char[length];
	}

	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < length; j++)
		{
			board[j][k] = empty;
			std::cout << board[j][k] << std::endl;
		}
	}
}

//	Display the board
void display_board(char** board, int length, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}

//	Places the players move on the board
void make_play(char** board, int height, int length, int &player)
{
	switch(player)
	{
	case pl1:
		board[height-1][length-1] = player1;
		break;
	case pl2:
		board[height-1][length-1] = player2;
		break;
	default:
		std::cout << "Should never get here" << std::endl;
	}
}

int main()
{
	int player = 1;
	int length, height;
	int row, column;
	bool game_finished = false;
	std::cout << "Welcome to Erik's Connect Four!\n" << "Enter the dimensions you want for the board" << std::endl;
	std::cout << "Length: ";
	std::cin >> length;
	std::cout << "Height: ";
	std::cin >> height;

	//  Create the board
	char** board = new char*[height];
	for (int i = 0; i < height; i++)
	{
		board[i] = new char[length];
	}
	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < length; k++)
		{
			board[j][k] = empty;
		}
	}

	display_board(board, length, height);
	
	std::cout << "Player 1's turn" << std::endl;
	std::cout << "Enter the row: ";
	std::cin >> row;
	std::cout << "Enter the column: ";
	std::cin >> column;

	make_play(board, row, column, player);
	display_board(board, length, height);
	player = 2;
	std::cout << "Player 2's turn" << std::endl;
	std::cout << "Enter the row: ";
	std::cin >> row;
	std::cout << "Enter the column: ";
	std::cin >> column;

	make_play(board, row, column, player);
	display_board(board, length, height);
	



	delete board;
	return 0;
}

