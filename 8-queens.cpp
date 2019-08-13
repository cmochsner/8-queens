#include <iostream>
#include<stdio.h> 
#include<stdbool.h>

using namespace std;

class queens
{
	private:
		int n;
		int **board;
	public:
		queens(): queens(8)
		{}
		queens(int n)
		{
			this->n = n;
			board = new int*[n];

			for (int i = 0; i < n; i++)
			{
				board[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					board[i][j] = 0;
				}
			}
			
		}
		void print()
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << " " << board[i][j] << " ";
				}
				cout << endl;
			}
		}
		bool check(int row, int col)
		{
			int i, j;

			//check that in this space a queen will not able to defeat any other queen
			for (i = 0; i < col; i++)
			{
				if (board[row][i])
				{
					return false;
				}
			}
			for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
			{
				if (board[i][j])
				{
					return false;
				}
			}
			for (i = row, j = col; j >= 0 && i < n; i++, j--)
			{
				if (board[i][j])
				{
					return false;
				}
			}

			return true;
		}
		bool backtracker(int col)
		{
			if (col >= n)
			{
				return true;
			}

			for (int i = 0; i < n; i++)
			{
				//if the queen can be placed, do so.
				if (check(i, col))
				{
					board[i][col] = 1;

					//use recursion to keep trying to place more queens.
					if (backtracker(col + 1))
					{
						return true;
					}

					board[i][col] = 0;
				}
			}
			return false;
		}

		bool solve()
		{
			//if queens can not be placed on board without defeating each other, return false.
			if (backtracker(0) == false)
			{
				return false;
			}
			//return true if solution is found
			return true;
		}

		~queens()
		{
			for (int i = 0; i < n; i++)
			{
				delete[] board[i];
			}
			delete [] board;
		}
};

int main()
{
	cout << "Welcome to the 8 Queens Program! Enter -1 to exit." << endl;
	int n = 8;

	while (n != -1)
	{
		cout << "\nWhat would you like to use for the dimensions of your nxn board? Enter one number." << endl;
		cin >> n;

		if (n == -1)
		{
			continue;
		}

		if (n > 100 || n < 1)
		{
			n = 8;
		}

		queens q(n);

		if (q.solve())
		{
			cout << "Here is the solution!" << endl << endl;
			q.print();
		}
		else
		{
			cout << "Sorry, no solution." << endl;
		}
	}

	return 0;
}

