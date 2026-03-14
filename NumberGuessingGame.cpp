#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

int main()
{
	int randomnumber, guessnumber, guesscount = 0, score = 100;
	srand(time(0));
	randomnumber = (rand() % 100) + 1;
	cout << "guess a number between 1 and 100\n";
	
	do {
		cout << "enter the number of guesses:";
		cin >> guessnumber;
		
		if (guessnumber == -1) break;
		
		if (guessnumber < 1 || guessnumber > 100) {
			cout << "please enter a number between 1 and 100\n";
			continue;	
		}
		
		guesscount++;
		
		if (guessnumber == randomnumber) {
			cout << "congratutations you found it the " << guesscount << "th time\n";
			break;
		} else {
			if (guessnumber > randomnumber)
				cout << "you must enter a smaller number\n";
			else
				cout << "you must enter a larger number\n";
			score-=10;
		}
		
	} while (guessnumber != -1);
	cout<<"\n your score is "<<(score<<0?0:score)<<"\n";
	return 0;
}