#include <iostream>
#include <bits/stdc++.h>
using namespace std;



template<class type>
class Node
{
public:

    type info;
    Node<type> *next;
};

///List class be a template class.
template<class type>
class linkedList
{
    Node<type> *Head;
    //we make it to pushback take constant time
    Node<type> *End;

    //to calc Size of list
    int length;

public:
    ///default constructor
    linkedList()
    {
        Head=End=NULL;
        length = 0;
    }

    ///– constructs a list having initial_size elements whose values are ‘value’.
    linkedList(type element,int Size)
    {
        length=Size;
        for(int i=0;i<length;i++)
        {
            Node<type> *newNode;
            newNode = new Node<type>;
            newNode->info = element;
            if(i==0){
                Head=End=newNode;
                newNode->next = NULL;
            }else{
                End->next=newNode;
                newNode->next = NULL;
                End = newNode;
            }
        }
    }




    ///check the list is empty or not
    bool isEmpty()
    {
        return length==0;
    }

    /// returns the current number of elements in the list.
    int Size()
    {
        return length;
    }


    ///usage of the scope operator in the declaration of the iterator, this is because the
    ///iterator class is defined as an inner class inside the list class

    //we send specific Node and class iterator determine i
    class iterator
    {


    public:
        //to save Node Address and Head Address and make it public to access
        Node<type> *NodeAdd;
        Node<type> *HeadAdd;
        iterator()
        {
            NodeAdd=NULL;
            HeadAdd=NULL;
        }
        ///To make function(begin(),end())
        iterator(Node<type> *ptr,Node<type> *ptrH)
        {
            NodeAdd = ptr;
            HeadAdd = ptrH;
        }

        //عملتهم جوا كلاس دا عشان اقدر استخدم الفي البرايفت
        ///advance the iterator one
        ///position towards the end of the list, throws exception if it is currently pointing after the last
        ///element.
        void operator ++()
        {
            if(NodeAdd->next==NULL)
            {
                cout<<"the list ended\n";
            }else{
                NodeAdd = NodeAdd->next;

            }
        }

        // return the value contained in the current node by refrence to allow its modification.
        type& operator *()
        {
            return NodeAdd->info;
        }


        ///return true if the passed operator points to the same node.
        bool operator == (const iterator & i)
        {
            if(NodeAdd==i.NodeAdd)
            {
                return true;
            }else{
                return false;
            }
        }


        ///return true if the passed operator points to the not same node.
        bool operator != (const iterator & i)
        {
            if(NodeAdd!=i.NodeAdd)
            {
                return true;
            }else{
                return false;
            }
        }


        /*bool operator <= (const iterator & i)
        {
            if(NodeAdd<=i.NodeAdd)
            {
                return true;
            }else{
                return false;
            }
        }*/


    };


    ///to insert Element at End
    void push_back(type element)
    {
        Node<type> *newNode;
        newNode = new Node<type>;
        newNode->info = element;
        if(length==0){
            Head=End=newNode;
            newNode->next = NULL;
        }else{
            End->next=newNode;
            newNode->next = NULL;
            End = newNode;
        }
        length++;
    }

    ///To Display List
    void print(){
        Node<type> *cur=Head;
        while(cur!=NULL)
        {
            cout<<cur->info<<" ";
            cur = cur->next;
        }
    }


  ///returns an iterator pointing to the first element.
    iterator begin()
    {
      return iterator(Head,Head);
    }



    ///returns an iterator pointing after the last element.
    iterator end()
    {
      return iterator(End,Head);
    }





    /// return an iterator to the next element
    iterator erase(iterator i)
    {
        if(length==0)
        {
            cout<<"Empty List\n";

        }else{
            Node<type> *temp = i.NodeAdd->next;  //because this line we make Node Address and Head Address public
            i.NodeAdd->next = i.NodeAdd->next->next;
            delete temp;
        }
        return i;
    }




    ///To insert element at Start
    void inserAtStart(type element)
    {
        Node<type> *newNode;
        newNode = new Node<type>;
        newNode->info = element;
        if(length==0){
             Head=End=newNode;
            newNode->next = NULL;
        }else{
            //the new node refer to the node that head
            newNode->next = Head;
            Head = newNode;
        }
        length++;
    }


    ///To insert element at Position
    void insertAtPos(int pos,type element)
    {

        if(pos==0){
            inserAtStart(element);
        }else if(pos==length){
            push_back(element);
        }else{
            Node<type> *newNode;
            newNode = new Node<type>;
            newNode->info = element;
            Node<type> *current;
            current = Head;
            for(int i=1;i<pos;i++)
            {
               current= current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            length++;
        }
    }

    ///To remove Element at End
    void pop_back()
    {
        if(length==0)
        {
            cout<<"List Empty"<<endl;
        }else{
            Node<type> *curr = Head->next;
            Node<type> *prev = Head;
            while(curr!=End)
            {
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;
            End = prev;
            length--;
        }
    }


    void removeElement(type element)
    {
        bool stat = false;
        if(End->info == element)
        {
            pop_back();
        }else{
            Node<type> *curr = Head->next;
            Node<type> *prev = Head;
            while(curr!=End){
                prev = curr;
                curr=curr->next;
                if(curr->info==element){
                    stat = true;
                    break;
                }
                prev = curr;
                curr=curr->next;

            }
            prev->next = curr->next;
            delete curr;
            length--;
        }
        if(stat == false)
        {
            cout<<"Not Found..";
        }
    }


    //assignment operator to deep copy a list into another list and return the current list by ((reference))
    linkedList<type>& operator =(linkedList<type> &list2)
    {
        for(iterator i = list2.begin();i!=list2.end();++i)
        {
            this->push_back(*i);
        }
        this->push_back(*list2.end());
        return *this;
    }


    ///A destructor to clear the list and leave no memory leaks
    ~linkedList()
    {
        do{
            Node<type> *curr = Head->next;
            Node<type> *prev = Head;
            while(curr!=End){
                prev = curr;
                curr=curr->next;
            }
            delete curr;
            prev->next = NULL;
            End = prev;
            length--;
        }while(Head!=End);

        delete Head;
        delete End;

    }
};
int main()
{
    int value,Size;
    cout<<"Enter Value to pass it to  constructs a list having elements: ";
    cin>>value;
    cout<<"Enter initial Size: ";
    cin>>Size;
    linkedList<int> Mylist(value,Size);

    cout<<"Enter 3 Elements to insert At End: ";
    for(int i=0;i<3;i++)
    {
        cin>>value;
        Mylist.push_back(value);

    }
    cout<<"Your list: ";
    Mylist.print();
    cout<<" and Size = "<<Mylist.Size()<<"\n\n";

    cout<<"Enter element to insert it at start: ";
    cin>>value;
    Mylist.inserAtStart(value);
    int pos;
    cout<<"Enter Position: ";
    cin>>pos;
    cout<<"Enter element to insert it at Position: ";
    cin>>value;
    Mylist.insertAtPos(pos,value);
    cout<<"Your List: ";
    Mylist.print();
    cout<<" and Size = "<<Mylist.Size()<<endl;

    Mylist.pop_back();
    cout<<"Your List After remove last Element: ";
    Mylist.print();
    cout<<" and Size = "<<Mylist.Size();
    cout<<endl<<endl;


    cout<<"Enter Element you want to remove it: ";
    cin>>value;
    Mylist.removeElement(value);
    cout<<"Your List After remove Element: ";
    Mylist.print();
    cout<<" and Size = "<<Mylist.Size();
    cout<<endl<<endl;

    linkedList<int> CopyList;
    CopyList=Mylist;
    cout<<"Copy List for your List: ";
    CopyList.print();
    cout<<endl<<endl;


    linkedList<int>:: iterator i = Mylist.begin();

    cout<<"Display Your list using iterator: ";
    while(i!=Mylist.end())
    {
        cout<<*i<<" ";
        ++i;
    }
    cout<<endl;



    linkedList<int>:: iterator i3 = Mylist.begin();
    Mylist.erase(i3);





    return 0;
}
