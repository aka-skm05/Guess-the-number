// Guess-the-number.cpp : Defines the entry point for the console application.

#include "stdafx.h"


#include <iostream> // For input/output.
#include <stdlib.h> // For srand() and rand() to generate random number and system() for system commands --> Here : "cls" and "pause".
#include <time.h>   // To get real time to generate random number everytime.
#include <math.h>   // For pow().
#include <conio.h>
#include <stdio.h>

using namespace std;

// Function to provide some hints like, range in which the needed number lies and no of digits.
void hint(int r_num)
{
	int temp = r_num;
	int i, digits[10];

	for (i = 0; temp != 0; i++)         								// Counting number of digits. Value stored in 'i'.
	{
		digits[i] = temp % 10;
		temp /= 10;
	}

	cout << "\n\n\t\t\t    ------------------------------ HINT ------------------------------\n";

	cout << "\n\t\t\t\t\t\t  It's a '" << i << "' digit number.";       // Printing number of digits.

	void range(int a[], int);
	range(digits, i);

	cout << "\n\t\t\t    ------------------------------ HINT ------------------------------\n";
}

// Funtion to calculate range.
void range(int a[10], int i)
{
	long int min = (a[i - 1] * pow(10, i - 1));
	long int max = ((a[i - 1] * pow(10, i - 1)) + (pow(10, i - 1)));

	cout << "\n\t\t\t\t\t\t  Range = (" << min << "," << max << ").\n";     // Printing range.
}

// Fuction for providing inital details.
void details()
{
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "*************************************************** GUESS THE NUMBER ***************************************************";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t   -: [Tech. S.K.M.] :-\n";

	cout << "\tABOUT THE GAME :\n";
	cout << "\t   This is a simple number guessing game. Here you have to guess the random number generated.";
	cout << "\n\t  Yeah, but you don't have to guess the exact number. A guess can be '300' more or less the number.\n";

	cout << "\n\tRULES :\n";
	cout << "\t  1. You will be given total '4' chances, '1' default + '3' extra chances.\n";
	cout << "\t  2. Number of digits and range in which the random number lies will be given.\n";
	cout << "\t  3. Enter number and try to make most precise guess to the number to win.\n";

	cout << "\n\t  YEAH! NOW WE ARE GOOD TO GO.\n\n\n\t\t\t\t\t  ";

	system("pause");
	system("cls");
}

int main()
{
	int num, rnum, chance = 4;
	bool win = 0;

	details();   															// Information of the game.

	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "*************************************************** GUESS THE NUMBER ***************************************************";
	cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t   -: [Tech. S.K.M.] :-\n";

	srand(time(0));

	rnum = rand();                    									  // Generating random number.

	hint(rnum);									                          // Fetching hints.

	cout << "\n\t\t\t\t\t\tMake a guess : ";

	do
	{
		cin >> num;                     // Main input goes here.
		--chance;                       // Reducing chances.

		if ((num <= (rnum + 300) && num >= (rnum - 300)) || num == rnum)         		// Winning conditon check.
		{
			win = 1;

			system("cls");

			cout << "------------------------------------------------------------------------------------------------------------------------\n";
			cout << "*************************************************** GUESS THE NUMBER ***************************************************";
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

			cout << "\n\t\t\t\t\t\t\t\t\t\t\t   -: [Tech. S.K.M.] :-\n";

			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t   Chances left : " << chance << "\n\n";

			cout << "\n\t\t\t\t\t\t  WOW! Correct answer. YOU WON!!\n";

			// Providing winning precision.
			if (num <= (rnum + 300))
				cout << "\n\t\t\t\t\t\t  You won by the difference of '" << (num - rnum) << "'.\n";
			else
				if (num >= (rnum - 300))
					cout << "\n\t\t\t\t\t\t  You won by the difference of '" << (rnum - num) << "'.\n";
				else
					cout << "\n\t\t\t\t\t\t  GREAT! EXACT GUESS.\n";
		}

		// Loosing conditions.
		else
			if (num > rnum)
			{
				win = 0;

				system("cls");

				cout << "------------------------------------------------------------------------------------------------------------------------\n";
				cout << "*************************************************** GUESS THE NUMBER ***************************************************";
				cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

				cout << "\n\t\t\t\t\t\t\t\t\t\t\t   -: [Tech. S.K.M.] :-\n";

				cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t   Chances left : " << chance << "\n\n";

				cout << "\t\t\t\t\t\t  Oh! It's bigger than the number.";

				hint(rnum);

				if (chance != 0)
					cout << "\n\n\t\t\t\t\t\t  Guess again : ";

				else
					cout << "\n\n\t\t\t\t\t\t  SORRY! Chances are over.\n";
			}

			else
				if (num < rnum)
				{
					win = 0;

					system("cls");

					cout << "------------------------------------------------------------------------------------------------------------------------\n";
					cout << "*************************************************** GUESS THE NUMBER ***************************************************";
					cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

					cout << "\n\t\t\t\t\t\t\t\t\t\t\t   -: [Tech. S.K.M.] :-\n";

					cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t   Chances left : " << chance << "\n\n";

					cout << "\t\t\t\t\t\t  Oh! It's smaller than the number.";

					hint(rnum);

					if (chance != 0)
						cout << "\n\n\t\t\t\t\t\t  Guess again : ";
				}
					else
						cout << "\n\n\t\t\t\t\t\t  SORRY! Chances are over.\n";

	} while (win != 1 && chance != 0);     							  // Loop condtion; only for '3' extra chances and if you win.

				cout << "\n\t\t\t\t\t\t  Answer = " << rnum << endl;               // At the end 'Answer'.

																				   // Providing losing precision.
				if (win == 0)
				{
					if (num > rnum)
						cout << "\n\t\t\t\t\t\t  You lost by the difference of '" << (num - rnum) << "'.\n";
					else
						if (num < rnum)
							cout << "\n\t\t\t\t\t\t  You lost by the difference of '" << (rnum - num) << "'.\n";
				}

				cout << "\n\t\t\t\t\t\t  MEET YOU AGAIN!\n";

				cout << "\n\t\t\t\t\t      --------------------------------";
				cout << "\n\t\t\t\t\t   -: Brought to you by [Tech. S.K.M.] :-";
				cout << "\n\t\t\t\t\t      --------------------------------";

				cout << "\n\n\n\t\t\t\t\t\t  Press any to exit . . .    ";

				_getch();

				return 0;
}