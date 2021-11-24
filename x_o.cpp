#include <iostream>  //   X_O
#include <string>
const int n=3;

class X_O
{
private:
	char board [n][n];
	int x;
	int y;
	bool tearn = true;
	std::string player1;
	std::string player2;
public:
	X_O();
	void set_x (int x) {this->x = x;}
	void set_y (int y) {this->y = y;}
public:
	void players_name();
	void display ();
	void takeAstep ();
	bool is_empty ();
	bool win ();
	bool no_one_continue ();
	bool is_valid();
	void new_game();
};

int main ()
{
	X_O game;
	game.players_name();
	game.display();
	game.takeAstep();
return 0;
}

X_O::X_O()
{
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j<n ; ++j)
			board[i][j]= ' ';
}
void X_O::players_name()
{
	std::cout<< "Enter first player name:" << std::endl;
	std::cin>> player1;
	std::cout<< "Enter second player name:" << std::endl;
	std::cin>> player2;
}

void X_O::display ()
{
	std::system("clear");
	for (int i=0; i<n; ++i)
	{
		std::cout<< std::endl;
		for(int j=0; j<n; ++j)
		{
			std::cout<< "  " << board[i][j] << "  |";	
		}
		std::cout<< std::endl;
	}
	std::cout<< std::endl;
}

void X_O::takeAstep ()
{
	while (no_one_continue())
	{
		std::cout<< (tearn ? player1 : player2) <<" jan enter your steps kordinats, x and y:" << std::endl;
			std::cin>> x >> y;
			if (is_empty())
			{
				board[x-1][y-1] = tearn ? 'X':'O';
			}
			else 
			{
				std::cout<< "You can't do that step, it's already busy." << std::endl;
			continue;
			}
		display();
		if (win())
		{
			std::cout<< ( tearn ? player1 : player2 ) << " jan congratulation , you win!!!" << std::endl;
			break;
		}
		tearn = ! tearn;
	}
	new_game();
}

bool X_O::is_empty()
{
	if(x > 3 || y > 3 || x < 1 || y < 1){return false;} 
	if (board[x-1][y-1] == 'X' or board[x-1][y-1] == 'O')
	{
		return false;
	}
	return true;
}

 bool X_O::win ()
{
	for(int i=0; i<n; ++i)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'X')
		{
			return true;
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'O')
		{
			return true;
		}
		else if (board[i][0] == board[i][1] and board[i][1] == board[i][2] and board[i][2] == 'X') 
		{
			return true;
		}
		else if (board[i][0] == board[i][1] and board[i][1] == board[i][2] and board[i][2] == 'O') 
		{
			return true;
		}
	}
	int count_general = 0;
	int count_second = 0;
	char general = board[0][0];
	char second = board[0][n-1];
	for(int i = 1; i<n; ++i)
	{
		if(board[i][i] == general && general != ' ')
		{
			count_general++;
		}
		else if(board[i][n-i-1] == second && second != ' ')
		{
			count_second++;
		}
	}
	if(general != ' ' && count_general == 2)
	{
		return true;
	}
	else if(second != ' ' && count_second == 2)
	{
		return true;
	}
//		std::cout << __LINE__ <<std::endl;
	return false;
}

bool X_O::no_one_continue()
{
	int count = 0;
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			if (board[i][j] == 'X' or board[i][j] == 'O')
			{
				++count;
			}
		}
	}
	if (count == n*n)
	{
		std::cout<< " Game over NO-One. Ther are no winner.";
		return false;
	}
	return true ;
}

/*
bool X_O::is_number()    //  it's warks false 
{
	if ((x >= 1 and x <= n) or (y >= 1 and y <= n)) 
	{return true;}
	return false;
}
*/

void X_O::new_game()
{
	std::string tmp;
	std::cout<< "Do you want to play again Enter Yes/No .\n";
	std::cin>> tmp;
	if (tmp == "Yes")
	{
		for(int i = 0 ; i < n ; ++i)
			for(int j = 0 ; j<n ; ++j)
				board[i][j]= ' ';
	takeAstep ();	
	}
}


