#include <iostream>
using namespace std;
 
int x,y,z,i,j,k;
 
class Tab_3D 
{
    public:
        void Metoda_1()
        {
            cout<<"Podaj x = ";
            cin>>x;
            cout<<endl;
            cout<<"Podaj y = ";
            cin>>y;
            cout<<endl;
            cout<<"Podaj z = ";
            cin>>z;
            cout<<endl;

            double *** tab_1;
            tab_1 = new double **[ x ];
            for( i = 0; i < x; i++ )
            {
                tab_1[ i ] = new double *[ y ];
                for(j = 0; j < y; j++)
                {
                    tab_1[ i ][ j ] = new double[ z ];
                }
            }
            double *** tab_2;
            tab_2 = new double **[ x ];
            for( i = 0; i < x; i++ )
            {
                tab_2[ i ] = new double *[ y ];
                for(j = 0; j < y; j++)
                {
                    tab_2[ i ][ j ] = new double[ z ];
                }
            }
            double *** tab_3;
            tab_3 = new double **[ x ];
            for( i = 0; i < x; i++ )
            {
                tab_3[ i ] = new double *[ y ];
                for(j = 0; j < y; j++)
                {
                    tab_3[ i ][ j ] = new double[ z ];
                }
            }
            cout<<"Podaj wyrazy tab_1 : "<<endl;
            cout<<endl;
            for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                    for(k=0;k<z;k++)
                    {
                        cout<<"tab_1 ["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = ";
                        cin>>tab_1[i][j][k];
                    }
                }
            }
            cout<<endl;

            cout<<"Podaj wyrazy tab_2 : "<<endl;
            cout<<endl;
            for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                    for(k=0;k<z;k++)
                    {
                        cout<<"tab_2 ["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = ";
                        cin>>tab_2[i][j][k];
                    }
                }
            }
            cout<<endl;

            cout<<"Wynik sumy tablic 3D : tab_3 : "<<endl;
            cout<<endl;
            for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                    for(k=0;k<z;k++)
                    {
                        tab_3[i][j][k]=tab_1[i][j][k]+tab_2[i][j][k];
                        cout<<"tab_3 ["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = "<<tab_3[i][j][k]<<endl;
                    }
                }
            }
            cout<<endl;
            delete [] tab_1;
            delete [] tab_2;
            delete [] tab_3;
        }
};
 
int main(int argc, const char * argv[])
{
    Tab_3D obiekt_3D;
    Tab_3D*wskazmik;
    wskazmik=&obiekt_3D;
    wskazmik->Metoda_1();
 
    return 0;
}