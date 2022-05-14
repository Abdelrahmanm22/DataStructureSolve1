/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/
#include <iostream>
#include <chrono>
#include <ratio>
#include <thread>
#include <bits/stdc++.h>
#include <time.h>
#include <stdio.h>
using namespace std;

///Insertion Sort without binary search(regular)
void InsertionSort(int arr[],int Size)
{
    int i,j,key;
    for(i=1;i<Size;i++)
    {
        key =arr[i];
        j =i-1;



        while(j>=0 and arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
}

///Binary Insertion Sort
void BinaryInsertionSort(int arr[],int Size)
{
    int i,j,key,index;
    for(i=1;i<Size;i++)
    {
        key =arr[i];
        j =i-1;



        // find index where Key should be inseretd using binary search
        int mid,left=0,right=j;
        for(mid = (left+right)/2; left <= right; mid=(left+right)/2)  //log n
        {
            if (key > arr[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        index=left;

        while (j>=index){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }

}

int main()
{

    int Size;
    cout<<"Times for InsertionSort: \n";
    for(int i=0;i<5;i++)
    {
        cout<<"Enter Size: ";
        cin>>Size;
        int arr[Size];
        for(int i=0;i<Size;i++)
        {
            arr[i]=rand();
        }
        clock_t start = clock();
        InsertionSort(arr,Size);
        clock_t stop = clock();
        double elapsed = (double)(stop-start)/CLOCKS_PER_SEC;//the duration of the run time
        cout << elapsed<<" microsecond" << endl;



    }


    cout<<"\n\nTimes for BinaryInsertionSort: \n";
    for(int i=0;i<5;i++)
    {
        cout<<"Enter Size: ";
        cin>>Size;
        int arr[Size];
        for(int i=0;i<Size;i++)
        {
            arr[i]=rand();
        }
        clock_t s = clock();
        BinaryInsertionSort(arr,Size);
        clock_t e = clock();
        double elapsed = (double)(e-s)/CLOCKS_PER_SEC;//the duration of the run time
        cout << elapsed<<" microsecond" << endl;



    }
    /*int arr[] = {3, 7, 1, 4, 6, 2, 5,9,10,8};
    int Size = sizeof(arr) / sizeof(arr[0]);

    int arr2[] = {3, 7, 1, 4, 6, 2, 5,9,10,8};

    int arr[10000];
    for(int i=0;i<10000;i++)
    {
        arr[i]=10000-i;
    }


    int arr2[15000];
    for(int i=0;i<15000;i++)
    {
        arr2[i]=15000-i;
    }



    //BinaryInsertionSort(arr2,Size);

    clock_t start = clock();
    BinaryInsertionSort(arr,10000);
    clock_t stop = clock();
    double duration = (double)(stop-start)*1000/CLOCKS_PER_SEC;//the duration of the run time
    cout << duration<<" microsecond" << endl;

    clock_t s = clock();
    InsertionSort(arr2,15000);
    clock_t e = clock();
    double elapsed = (double)(e-s)*1000/CLOCKS_PER_SEC;//the duration of the run time
    cout << elapsed<<" microsecond" << endl;



    /*auto f = []()-> int {return rand()%10000;}
    generate(arr,arr+15000 ,f);




    for(int k=0;k<10;k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;




    /*int* ptr;
    int n;
    auto f = []() -> int { return rand() % 10000; };//generate randome numbers
    cin >> n;
    ptr = new int[n];
    generate(ptr, ptr + n, f); // filling the ptr array with the randome numbers
    auto start = std::chrono::high_resolution_clock::now();//the start time before the function get called
    InsertionSort(ptr,n);//the function you want to estimate the run time for
    auto stop = std::chrono::high_resolution_clock::now(); // the end time after the function has been run completel
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);//the duration of the run time
    cout << duration.count()<<" microsecond" << endl;



    int* ptr2;

    auto s = []() -> int { return rand() % 10000; };//generate randome numbers

    ptr2 = new int[n];
    generate(ptr2, ptr2 + n, s); // filling the ptr array with the randome numbers
    auto st = std::chrono::high_resolution_clock::now();//the start time before the function get called
    BinaryInsertionSort(ptr2,n);//the function you want to estimate the run time for
    auto en = std::chrono::high_resolution_clock::now(); // the end time after the function has been run completel
    auto durationn = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);//the duration of the run time
    cout << durationn.count()<<" microsecond" << endl;*/



    return 0;
}
