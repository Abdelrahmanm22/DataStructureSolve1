
/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/

//There is a file word for the performance of the problem

#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

class Sorter{

public:
    virtual void Sort(int *arr, int _size){};

};

class SelectionSorter : public Sorter{

public:
    void Sort(int *arr, int _size) {

        for (int i = 0, j, least; i < _size-1; i++) {

            for (j = i+1, least = i; j < _size; j++)
                if (arr [j] < arr [least])
                    least = j;

            swap (arr [least], arr [i]);

        }
    }

};

class QuickSorter : public Sorter{

public:
    void Sort(int arr[], int _size){

        int low, high;

        low = arr[0];

        for(int i = 0; i < _size; i++){
            if(arr[i] < low)
                low = arr[i];
        }

        high = arr[0];

        for(int i = 0; i < _size; i++){
            if(arr[i] > high)
                high = arr[i];
        }

        quickSort(arr, low, high);

}


    int Partition(int arr[], int low, int high) {

        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
        }
      }

      swap(arr[i + 1], arr[high]);

      return (i + 1);
}

    void quickSort(int arr[], int low, int high) {

      if (low < high) {
        int pi = Partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
      }
    }

};




class TestBed{


public:

    float RunOnce(Sorter *s, int *arr, int _size){

        auto start = clock(); //the start time before the function get called
        s -> Sort(arr, _size);
        auto stop = clock(); // the end time after the function run completely
        auto duration = (double)(stop-start)/CLOCKS_PER_SEC;//the duration of the run time


        return duration;
    }

     float RunAndAverage(Sorter *s, int type, int _min, int _max, int _size, int sets_num){

        int *arr;
        float avg = 0;
        if(type==0){
            for(int i = 0; i < sets_num; i++){
                arr = GenerateRandomList(_min, _max, _size);
                //QuickSorter *QS = new QuickSorter[_size];
                avg+=RunOnce(s, arr, _size);
                delete [] arr;
            }

            return avg/=sets_num;
        }
        else if(type==1){
            for(int i = 0; i < sets_num; i++){
                arr = GenerateReversedOrderedList(_min, _max, _size);
                //QuickSorter *QS = new QuickSorter[_size];
                avg+=RunOnce(s, arr, _size);
                delete[] arr;
            }

            return avg/=sets_num;
        }


    }

    void RunExperient(Sorter *s, int type , int _min, int _max, int minVal, int maxVal, int sets_num, int step)
    {
        int minn = minVal;


        while(minn <= maxVal)
        {
            cout << "On size: " << minn << endl;
            cout << "Set Size ----- Average Time" << endl;
            for(int i = 0 ; i < sets_num ; i++)
            {
                float avg = RunAndAverage(s, type, minn, maxVal, _max, sets_num);
                cout << minn << "       ---     " << avg<< endl;

            }
            cout << "------------------------" << endl;
            minn += step;
        }


    }

    int* GenerateRandomList(int _min, int _max, int _size){

        int *randomizedArray = new int[_size];

        for(int i = 0; i < _size; i++){

            randomizedArray[i] = rand()%(_max-_min+1)+ _min;

        }

        return randomizedArray;
    }

    int* GenerateReversedOrderedList(int _min, int _max, int _size){

        int *randomizedArray = new int[_size];

        randomizedArray = GenerateRandomList(_min, _max, _size);
         for (int i = 0, j, highest; i < _size-1; i++) {

            for (j = i+1, highest = i; j < _size; j++)
                if (randomizedArray [j] > randomizedArray [highest])
                    highest = j;

            swap (randomizedArray [highest], randomizedArray [i]);

        }

        return randomizedArray;

    }
};




int main(){

    TestBed t1;
    int _size = 10000;
    t1.GenerateReversedOrderedList(100, 1000, _size);

    int *arr = t1.GenerateRandomList(100,1000,_size);
    SelectionSorter *SS= new SelectionSorter [_size];
    QuickSorter *QS = new QuickSorter [_size];


    cout<<"Selection Sort Performance on the random list is "<<t1.RunOnce(SS, arr, _size)<<" microseconds"<<endl;

    cout<<endl;

    cout<<"Quick Sort Performance on the random list is "<<t1.RunOnce(QS, arr, _size)<<" microseconds"<<endl;

    cout<<endl<<"------------------------------------------------------------------"<<endl;

    cout<<"Selection Sort Average Performance on the random list is "<<t1.RunAndAverage(SS, 0, 100, 1000, _size, 5)<<" microseconds"<<endl;
    cout<<endl;


    cout<<"Quick Sort Average Performance on the random list is "<<t1.RunAndAverage(QS, 0, 100, 1000, _size, 5)<<" microseconds"<<endl;
    cout<<endl;


    cout<<"Selection Sort Average Performance on the reversed list is "<<t1.RunAndAverage(SS, 1, 100, 1000, _size, 5)<<" microseconds"<<endl;
    cout<<endl;


    cout<<"Quick Sort Average Performance on the reversed list is "<<t1.RunAndAverage(QS, 1, 100, 1000, _size, 5)<<" microseconds"<<endl;
    cout<<endl;

    cout << "Selection Sort Run Experient on the random list is: " << endl;
    t1.RunExperient(SS, 0, 100, 1000, 100, 1000, 5, 100);
    cout << endl<<"---------------------------------------------------------"<<endl;

    cout << "Quick Sort Run Experient on the random list is: " << endl;
    t1.RunExperient(QS, 0, 100, 1000, 100, 1000, 5, 100);
    cout << endl<<"---------------------------------------------------------"<<endl;


    cout << "Selection Sort Run Experient on the reversed list is: " << endl;
    t1.RunExperient(SS, 1, 100, 1000, 100, 1000, 5, 100);
    cout << endl<<"---------------------------------------------------------"<<endl;

    cout << "Quick Sort Run Experient on the reversed list is: " << endl;
    t1.RunExperient(QS, 1, 100, 1000, 100, 1000, 5, 100);
    cout << endl<<"---------------------------------------------------------"<<endl;


    return 0;
}
