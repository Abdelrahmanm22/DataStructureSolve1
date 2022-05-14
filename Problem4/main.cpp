/*
    answered by:
        Ziyad Ashraf Ali                20200197
        Nouran Ahmed Abdelaziz          20200609
        Abdelrahman Mohamed Ramadan     20200293
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
void RecPermute(string soFar,string rest )
{
    vector<string> vec,i;
    if (rest == ""){
        cout<<soFar<<endl;
    }
    else
    {



        for (int i = 0; i <rest.length(); i++)
        {
            string next = soFar + rest[i];
            string remaining = rest.substr(0,i) + rest.substr(i+1);
            int Size = vec.size();


            vec.push_back(next);
            ///to check next already exist or not
            for(int i=0;i<Size;i++){
                if(vec[i]==next){
                    vec.pop_back();
                }
            }

            if(vec.size()>Size){
                RecPermute(next,remaining);
            }

         }
    }
}
void ListPermutations(string s)
{
    RecPermute("", s);
}


int main()
{
    ListPermutations("abb");
    /*string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);*/


    /*set<string>arr;
    string s;
    for(int i=0;i<5;i++){
        cin>>s;
        arr.insert(s);
    }


    for(auto s:arr){
        cout<<s<<" ";
    }
    cout<<endl;*/




    //string s = "bc";

    //cout<<s.substr(1);



    return 0;
}


