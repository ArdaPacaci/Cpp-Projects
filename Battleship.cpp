#include <iostream>
using namespace std;

int main()
{
	bool ships[4][4]={
		
		{0,0,1,1},
		{0,0,0,0},
		{0,0,0,1},
		{0,1,0,0},
	};
	
	int hits=0,numberofturns=0;
	int row,column;
	while(hits<4){
		cout<<"selecting coordinates \n";
		
		cout<<"choose a row number between 0 and 3:";
		cin>>row;
		
		cout<<"choose a column number between 0 and 3:";
		cin>>column;
		
		if(ships[row] [column]){
		   ships[row] [column]=0;
		   hits++;
		   cout<<"you hit! "<<(4-hits)<<" left\n\n";
		}
		else{
			cout<<"you missed\n";
		}
		numberofturns++;
	}
	cout<<"victory!\n";
	cout<<"you won in "<<numberofturns<<" turns\n";
}