/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

void BiasedSort(vector<string> &Arr, int Size)
{

    int x=0;
    ///check if the song name "untitled"
    for(int i=0; i<Size; i++){
        if(Arr[i] == "untitled" || Arr[i] == "Untitled"){
            swap(Arr[x], Arr[i]);
            x++;
            i++;
        }
    }

    ///Using selection Sort
    for(int i = x ; i < Size - 1; i++)
    {
        int minimum = i;

        for(int j = i ; j < Size; j++)
        {

            if(Arr[j] < Arr[minimum]){
                minimum = j;
            }

        }
        swap(Arr[minimum], Arr[i]);
    }
}


int main()
{
    vector<string>Arr;
    string x;
    int Size;
    cout << "Enter Size: ";
    cin >> Size;
    cout << "Enter List of Songs: \n";

    for(int i=0;i<Size;i++)
    {
        cin>>x;
        Arr.push_back(x);
    }

    cout << endl;

    BiasedSort(Arr,Size);

    for(int i = 0;i < Size;i++)
    {
        cout << Arr[i] <<endl;
    }
    return 0;
}



