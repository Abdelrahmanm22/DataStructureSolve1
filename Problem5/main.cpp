/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/
#include <iostream>
#include <vector>
using namespace std;



class StudentName
{
    string name;
    int spaces; //to claculate number of spaces
public:
    /// constructor that takes a string from user.
    StudentName(string n="")
    {
        spaces=0;
        string rest; //To store the rest of the name
        for(int i=0;i<n.length();++i){
            if(n[i]==' '){
                rest ="";
                spaces++;


                ///store the rest of the name
                for(int k=i+1;k<n.length();++k){
                    rest+=n[k];
                }
            }
        }
        if(spaces==0)
        {

            name = n + " " + n +" "+n;
            spaces=2;

        }else if(spaces==1)
        {
            name = n +" "+rest;
            spaces++;
        }
        else{
            name = n;
        }
    }




    ///function print that prints the detailed parts of the name each in one line.
    void print()
    {
        string part="";
        int Size=name.length(), noOfParts = 1;
        vector<string> parts;       ///use (Vector)  dynamic array with the ability to resize itself automatically when an element is inserted
        for(int i=0;i<Size;++i)
        {
            part+=name[i];
            if(name[i]==' ')
            {

                parts.push_back(part);
                part="";
            }else if(i==(Size-1)){
                parts.push_back(part);
            }
        }
        for(int i=0;i<parts.size();i++){

            cout<<noOfParts++<<") "<<parts[i]<<"\n";
        }
        cout<<endl;
    }





    ///function replace(int i,int j) that replaces the name at position I with the name at position j and return true if operation is valid and false if one of the two indices is out of range.
    bool replace(int i,int j)
    {

        string str="";
        string arr[spaces+1];
        int index=0;
        for(int y=0;y<name.length();y++)
        {

            if(name[y]==' ')
            {
                arr[index]=str;
                str="";
                index++;
            }else if(y==(name.length()-1)){
                str+=name[y];
                arr[index]=str;
                index++;
            }else{
                str+=name[y];
            }
        }

        if(i<=(spaces+1) and j<=(spaces+1))
        {

            swap(arr[i-1],arr[j-1]);
            name="";
            for(int y=0;y<(spaces+1);y++)
            {
                name+=arr[y] +" ";
            }
            cout<<name<<endl;
            return 1;
        }else{
            cout<<name<<"\n";
            cout<<"Replacement not done 'out of range'\n";
            return 0;
        }
    }
};

int main()
{
    StudentName n1("Abdelrahman Mohamed Ramadan");
    n1.replace(1,3);
    n1.print();


    StudentName n2("Abdelrahman Mohamed Ramadan");
    n2.replace(2,3);
    n2.print();


    StudentName n3("Abdelrahman Mohamed");
    n3.replace(3,1);
    n3.print();


    StudentName n4("Abdelrahman mohamed ramadan hassan");
    n4.replace(3,1);
    n4.print();


    StudentName n5("Abdelrahman Mohamed");
    n5.replace(1,4);
    n5.print();

    return 0;
}

