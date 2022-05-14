#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>

class Matrix
{
private:
    int rows, cols;
    T info;
    T **arr;
    static int cnt;

public:
    Matrix(int rows=0, int cols=0)
    {
        this-> rows = rows;
        this-> cols = cols;
        //this-> info = info;

        arr = new T *[rows];
        for(int count=0 ; count < rows ; count++)
        {
            arr[count] = new T [cols];
        }
    }



    void setInfo(T i)
    {
        info = i;
    }

    void setRow(int row)
    {
        rows = row;
    }

    void setCol(int col)
    {
        cols = col;
    }

    int getRow()
    {
        return rows;
    }

    int getCol()
    {
        return cols;
    }

    void MatrixTranspose(Matrix<T> obj)
    {
        Matrix m(rows, cols);

        for(int i=0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[j][i] = obj.arr[i][j];
            }
        }

        for(int i=0 ; i < cols ; i++)
        {
            for(int j = 0 ; j < rows ; j++)
            {
                cout << m.arr[i][j] << " ";
            }
            cout << endl;
        }


    }

    Matrix<T> operator+(Matrix<T> &A)
    {
        Matrix m(rows, cols);
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[i][j] = arr[i][j] + A.arr[i][j];
            }
        }

        cout << endl;
        return m;
    }

    Matrix<T> operator-(Matrix<T> &A)
    {
        Matrix m(rows, cols);
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                m.arr[i][j] = arr[i][j] - A.arr[i][j];
            }
        }

        cout << endl;
        return m;
    }

    Matrix<T> operator*(Matrix<T> &A)
    {
        int sum = 0;
        Matrix m(rows, cols);

        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < A.cols ; j++)
            {
                for(int a = 0 ; a < cols ; a++)
                {
                    sum += (arr[i][a] * A.arr[a][j]);
                }
                m.arr[i][j] = sum;
                sum = 0;
            }
        }

        cout << endl;
        return m;

    }

/*
    ~Matrix()
    {
        for(int cnt=0 ; cnt < rows ; cnt++)
        {
            delete[] arr[cnt];
        }
        delete[] arr;
    }
*/

    template <class t>
    friend istream& operator>>(istream &input, Matrix <t> &obj);

    template <class t>
    friend ostream& operator<<(ostream &output, const Matrix <t> &obj);

};

template <class t>
int Matrix<t>::cnt=0;

template <class t>
istream& operator>>(istream &input, Matrix <t> &obj)
{
    obj.cnt++;
    cout << "Enter the size of the matrix number " << obj.cnt << " :" << endl;
    cout << "Rows: ";
    cin >> obj.rows;
    cout << "Cols: ";
    cin >> obj.cols;

    obj.arr = new t *[obj.rows];
    for(int cnt=0 ; cnt < obj.rows ; cnt++)
    {
        obj.arr[cnt] = new t [obj.cols];
    }

    for(int i = 0 ; i < obj.rows ; i++)
        {
            for(int j = 0 ; j < obj.cols ; j++)
            {
                cout << "Enter the [" << i <<"][" << j << "] index: ";
                input >> obj.arr[i][j];
            }
        }

    return input;
}


template <class t>
ostream& operator<<(ostream &output, const Matrix <t> &obj)
{
    for(int cnt=0 ; cnt < obj.rows ; cnt++)
        {
            for(int i = 0 ; i < obj.cols ; i++)
            {
                output <<obj.arr[cnt][i] << " ";
            }
            output << endl;
        }

    return output;
}

template <class T>
class MatrixCaculator
{
public:
    MatrixCaculator(){}

    void menu()
    {
        cout << "Welcome to our Matrix Calculator" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "1- Perform Matrix Addition" << endl;
        cout << "2- Perform Matrix Subtraction" << endl;
        cout << "3- Perform Matrix Multiplication" << endl;
        cout << "4- Matrix Transpose" << endl;
        cout << "5- Exit the program" << endl;

        Matrix<T> obj1, obj2;
        int choice;
        cout << endl;

        cin >> obj1;
        cout << endl;
        cin >> obj2;
        while(true)
        {
            cout << "--------------------------------" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;



            if(choice == 1)
            {
                if(obj1.getRow()==obj2.getRow() && obj1.getCol()==obj2.getCol())
                {
                    cout << endl;
                    cout << "The result of adding is: " << endl;
                    cout << obj1 + obj2 << endl;
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be added" << endl;

                }

            }

            else if(choice == 2)
            {
                if(obj1.getRow()==obj2.getRow() && obj1.getCol()==obj2.getCol())
                {
                    cout << endl;
                    cout << "The result of subtracting is: " << endl;
                    cout << obj1 - obj2 << endl;
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be subtracted" << endl;
                }

            }

            else if(choice == 3)
            {

                if(obj1.getCol() == obj2.getRow())
                {
                    cout << endl;
                    cout << "The result of multiplying is: ";
                    cout << obj1 * obj2 <<endl;
                }

                else
                {
                    cout << endl;
                    cout << "The two matrices can't be multiplied" << endl;
                }
            }

            else if(choice == 4)
            {
                int option;
                cout << "First matrix or second one you want it transposed? (Enter 1 or 2): ";
                cin >> option;
                if(option == 1)
                {
                    cout << endl;
                    cout << "The first matrix transposed: " << endl;
                    obj1.MatrixTranspose(obj1);
                }

                else if(option == 2)
                {
                    cout << endl;
                    cout << "The second matrix transposed: " << endl;
                    obj2.MatrixTranspose(obj2);
                }



            }

            else if(choice == 5)
            {
                cout << endl;
                cout << "You have exited the program" << endl;
                break;
            }
        }
    }
};

int main()
{
    MatrixCaculator<int> obj;
    obj.menu();


    return 0;
}
