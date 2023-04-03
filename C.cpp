/*
Name: Aleksejs Gerasimovs
Stud. apl. numurs: ag21275


C1. Virkni a(1..n) sauc par monotonu, ja a(1)<=a(2)<=...<=a(n) vai a(1)>=a(2)>=...>=a(n).
Dots veselu skaitļu masīvs A(m). Noskaidrot garāko tajā sastopamo monotono virkni.
Izveidot un izmantot funkciju, kas nosaka masīvā sastopamās monotonas virknes garumu, sākot no elementa ar indeksu i.
*/

#include <iostream>

using namespace std;

void monGarums(int* mas, int size)
{
    int maxGar = 0;
    int maxI = 0;
    for (int i = 1; i < size; ++i)
    {
        int gar = 1;

        for (int j = i; j < size; ++j) // dilstoša monotona virkne
        {
            if (mas[j] <= mas[j - 1])
            {
                ++gar;
            }
            else
            {
                break;
            }
        }
        if (gar > maxGar)
        {
            maxGar = gar;
            maxI = i - 1;
        }
        gar = 1;
        
        for (int j = i; j < size; ++j) // augoša monotona virkne
        {
            if (mas[j] >= mas[j - 1])
            {
                ++gar;
            }
            else
            {
                break;
            }
        }
        if (gar > maxGar)
        {
            maxGar = gar;
            maxI = i - 1;
        }

    }

    cout <<"Longest string is "<< maxGar << " elements starting from array element " << maxI << endl;
}

int main()
{
    int ok = 1;
    do {
        int size = 0;
        cout<<"Input array size: ";
        cin >> size;
        if (size > 0) {
            int* A = new int[size];
            for (int i = 0; i < size; ++i)
            {
                cout << "Input array " << i << " element: ";
                cin >> A[i];
            }
            monGarums(A, size);
            delete[] A;
        }
        else {
            cout<<"Size should be bigger than 0"<<endl;
        }
        cout << "Input (1) to repeat or (0) to cancel:" << endl;
        cin >> ok;
    } while (ok == 1);
    return 0;
}
/*                               Test
* 
*       Input data            Expectation               Result
*   Size        Data
*   5         0 4 1 2 3          3   2                     +
*  -2                    Size should be bigger than 0      +
*   7       3 2 2 1 0 -1 -2         7 0                     +
* 

*/