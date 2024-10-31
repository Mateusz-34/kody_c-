#include<iostream>
using namespace std;
 
int main()
{
 
	int tab[4][5];
 
	cout<<"Przed transpozycją: "  << endl;
 
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			tab[i][j]=rand()%19-9; 
			cout<<tab[i][j]<<" "; 
		}
		cout<<endl;
	}
 
	cout<<"Po transpozycji: "<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
			cout<<tab[j][i]<<" ";
	cout<<endl;
	}
 
	return 0;
}