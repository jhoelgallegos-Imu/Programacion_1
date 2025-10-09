#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
//matrices

int main() {
    srand(time(0));
    int edades[4][5];
    for (int i = 0; i < 3; i++) //
    {
        for (int j = 0; j < 3; j++) //columnas
        {
            
            if (i==j)
            {
                edades[i][j]=-10;
            }
            else
            {
                edades[i][j]=(rand() % 100)+1;
            }
            
            
            cout<<edades[i][j]<<" \t";

        }
        cout<<endl;
    }
    
    return 0;
}

