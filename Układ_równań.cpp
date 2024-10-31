#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int main()
{
 
	double a1,a2,b1,b2,c1,c2,wx,wy,w,x,y;
 
	cout<<"Podaj a1: ";
	cin>>a1;
	cout<<"Podaj b1: ";
	cin>>b1;
	cout<<"Podaj c1: ";
	cin>>c1;
	cout<<"Podaj a2: ";
	cin>>a2;
	cout<<"Podaj b2: ";
	cin>>b2;
	cout<<"Podaj c2: ";
	cin>>c2;
 
	w = a1*b2 - b1*a2;
	wx = c1*b2 - b1*c2;
	wy = a1*c2 - c1*a2;
 
	if(w!=0)
	{
		cout<<"x = "<<wx/w<<endl;
		cout<<"y = "<<wy/w<<endl;
	} 
	else
		if(wx==0&&wy==0)
			cout<<"Uklad ma nieskonczenie wiele rozwiazan"<<endl;
		else
			cout<<"Uklad sprzeczny"<<endl;

	return 0;
}