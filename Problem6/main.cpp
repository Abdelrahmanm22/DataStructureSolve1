#include <iostream>
using namespace std;

class PhoneDirectory
{
private:
    string firstName;
    string lastName;
    string num;

public:

    PhoneDirectory(string firstName="" , string lastName="" , string num="")
    {
        this-> firstName = firstName;
        this-> lastName = lastName;
        this-> num = num;
    }

    string getFirstName()
    {
        return firstName;
    }

    string getLastName()
    {
        return lastName;
    }

    string getNum()
    {
        return num;
    }

    void setFirstName(string fname)
    {
        firstName = fname;
    }

    void setLastName(string lname)
    {
        lastName = lname;
    }

    void setPhoneNum(string PhoneNum)
    {
        num = PhoneNum;
    }

    string operator+=(string q1)  //Operator overloading for += operator
    {
        firstName += q1;
        lastName += q1;
        num += q1;
        return q1;
    }

    friend bool operator<(PhoneDirectory const& q2, PhoneDirectory const& q3)
    {
        if(q2.firstName<q3.firstName)
        {
            return true;
        }

        else if(q2.firstName>=q3.firstName)
        {
            if(q2.lastName < q3.lastName)
            {
                return true;
            }

            else
                return false;
        }

        else
            return false;


    }





    friend ostream &operator<<(ostream &output, const PhoneDirectory &c2);

    friend class Entry ;

};


ostream &operator<<(ostream &output, const PhoneDirectory &e2)  //Operator overloading for cout << operator
{
    output << "first name: " << e2.firstName << endl;
    output << "last name: " << e2.lastName << endl;
    output << "student number: " << e2.num << endl;
    return output;
}

class Entry
{
private:
    PhoneDirectory *entry;
    int maxNum;
    int cnt=0;

public:
    Entry(int maxNum = 0)
    {
        this-> maxNum = maxNum;
        entry = new PhoneDirectory[maxNum];


    }

    void setMaxNum(int maxx)
    {
        maxNum = maxx;
        entry = new PhoneDirectory[maxx];
    }

    void Add(PhoneDirectory obj)
    {

        entry[cnt].firstName += obj.getFirstName();
        entry[cnt].lastName += obj.getLastName();
        entry[cnt].num += obj.getNum();
        cnt++;
    }


    void LookUpPN(string Number)
    {

        for(int i = 0 ; i < cnt ; i++)
        {
            if(entry[i].num == Number)
            {
                cout << "Phone Number is FOUND" << endl;
                cout<<entry[i].firstName<<endl;
                cout<<entry[i].lastName<<endl;
                cout<<entry[i].num<<endl;
                break;
            }

            else
            {
                if(i==cnt-1)
                {
                    cout << "Phone Number isn't FOUND" << endl;

                }

            }

        }
    }

    void LookUpFn(string fn)
    {
        for(int i = 0 ;  i < cnt ; i++)
        {
            if(entry[i].firstName == fn)
            {
                cout << "The entry you are searching for by the first name is FOUND" << endl;
                cout<<entry[i].firstName<<endl;
                cout<<entry[i].lastName<<endl;
                cout<<entry[i].num<<endl;
                break;
            }

            else
            {
                if(i==cnt-1)
                {
                    cout << "The entry you are searching for by the first name is not FOUND" << endl;
                }


            }

        }
    }

    void Delete(string firstN)
    {
        for(int i = 0 ; i < maxNum ; i++)
        {
            if(entry[i].firstName == firstN)
            {
                //int pos = i;
                for(int j = i ; j < maxNum ; j++)
                {
                    entry[j].firstName = entry[j+1].firstName;
                    entry[j].lastName = entry[j+1].lastName;
                    entry[j].num = entry[j+1].num;

                    maxNum--;
                }

            }
        }
    }

    void SelectionSort()
    {
        for(int i=0; i<cnt-1 ; i++)
        {
            for(int j=i+1 , minn = i ; j<cnt ; j++)
            {
                if(entry[j] < entry[minn])
                    minn = j;
                swap(entry[minn], entry[i]);
            }
        }
    }


    void InsertionSort()
    {
        for(int i = 1 ; i < cnt ; i++)
        {
            int j;
            PhoneDirectory temp = entry[i];
            for(j = i ; j>0 && temp<entry[j-1] ; j--)
            {
                entry[j] = entry[j-1];
            }
            entry[j]=temp;
        }
    }

    void BubbleSort()
    {
        for(int i =0; i< cnt-1 ; i++)
        {
            for(int j = maxNum-1 ; j>i ; --j)
            {
                if(entry[j] < entry[j-1])
                {
                    swap(entry[j], entry[j-1]);
                }
            }
        }
    }


    void display()
    {
        for(int i = 0 ; i < cnt ; i++)
        {
            cout << entry[i] << endl;
        }
    }


    ~Entry()
    {
        delete [] entry;
    }

    friend ostream &operator<<(ostream &output, const PhoneDirectory &c2);

};

//int Entry::cnt=0;

void menu()
{
    cout << "1. Add an entry to the directory" << endl;
    cout << "2. Look up a phone number" << endl;
    cout << "3. Look up by first name" << endl;
    cout << "4. Delete an entry from the directory" << endl;
    cout << "5. List all entries in phone directory" << endl;
    cout << "6. Exit from this program" << endl;
}


int main()
{

    int maxi, choice;
    string fname ,lname , number;

    cout << "enter maximum number of entries in your directory: ";
    cin >> maxi;
    Entry e2;
    e2.setMaxNum(maxi);

    menu();
    while(true)
    {

        cout << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Choose a number from the menu: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter the entry details: " << endl;
            cout << "        ---" << endl;
            cout << "Entry's first name: ";
            cin >> fname;
            cout << "Entry's last name: ";
            cin >> lname;
            cout << "Entry's Phone Number: ";
            cin >> number;

            PhoneDirectory e1(fname, lname, number);
            e2.Add(e1); //polymorphism
            cout << endl;
            //e2.display();
        }

        else if(choice == 2)
        {
            string mobNum;
            cout << "Enter the phone number you wanna find: ";
            cin >> mobNum;

            e2.LookUpPN(mobNum);
        }

        else if(choice == 3)
        {
            string first;
            cout << "Enter the first name you are searching for: ";
            cin >> first;

            e2.LookUpFn(first);
        }

        else if(choice == 4)
        {
            string firstDelete;
            cout << "Enter the first name of the entry you wanna delete: ";
            cin >> firstDelete;

            e2.Delete(firstDelete);
            e2.display();
        }

        else if(choice == 5)
        {
            cout << "Choose one of the 3 sorting algorithms: " << endl;
            cout << "1. Selection" << endl;
            cout << "2. Insertion" << endl;
            cout << "3. Bubble" << endl;
            cout << endl;

            int sortt;
            cout << "Enter the sorting algorithm you wanna use: ";
            cin >> sortt;

            if(sortt == 1)
            {
                e2.SelectionSort();
                e2.display();
            }


            else if(sortt == 2)
            {
                e2.InsertionSort();
                e2.display();
            }


            else if(sortt == 3)
            {
                e2.BubbleSort();
                e2.display();
            }

        }



        else if(choice == 6)
        {
            cout << "You have exited the program." << endl;
            break;
        }
    }





    return 0;
}
