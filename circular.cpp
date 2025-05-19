#include<iostream>
using namespace std;

struct list
{
    int data;
    struct list *next;
};
struct list *start = nullptr;
struct list *last = nullptr;

class LinkList 
{
    private: 
    int count=0;
    public:
    
    void insert_at_beg(int val)
    {
        if(start == nullptr)
        {
            start = new list;
            start->data = val;
            start->next = nullptr;
            if(last == nullptr)
            {
                last = start;
            }
        }
        else 
        {
            struct list *temp = new list;
            temp->data = val;
            temp->next = start;
            last->next = temp;
            start = temp;
        }
        cout<<val<<" is inserted into linked list"<<endl;
        count++;
    }
    void insert_at_end(int val)
    {
        struct list *temp = new list;
        temp->data = val;
        temp->next = start;
        if(start == nullptr)
        {
            start = last = temp;
        }
        else 
        {
            last->next = temp;
            last = temp;
        }
        cout<<val<<" is inserted into linked list"<<endl;
        count++;
    }
    void insert_at_pos(int val,int pos)
    {
        if(pos < 1 || pos > count+1)
        {
            cout<<"Invalid position.";
            return;
        }
        else if(pos == 1) insert_at_beg(val);
        else if(pos == count+1) insert_at_end(val);
        else 
        {
            struct list *search = start;
            for(int i=1; i<pos-1; i++)
            {
                search = search->next;
            }
            struct list *temp = new list;
            temp->data = val;
            temp->next = search->next;
            search->next = temp;
            cout<<endl<<val<<" is inserted into linked list"<<endl;
            count++;
        }
    }
    void delete_at_beg()
    {
        if (start == nullptr)
        {
        cout << "List is empty, nothing to delete!" << endl;
        return;
        }
        cout<<start->data<<" is delted";
        if(start == last)
        {
            delete start;
           start = last = nullptr;
           count--;
           return;
        }
        struct list *temp = start;
        start = start->next;
        last->next = start;
        delete temp;
        count--;
    }
    void delete_at_end()
    {
        struct list *search = start;
        if(start == nullptr)
        {
            cout<<"List is empty";
            return;
        }
        while(search->next != last) 
        {
            search = search->next;
        }
        cout<<endl<<last->data<<" is deleted";
        delete last;
        last = search;
        last->next = start;
        count--;
    }
    void delete_at_pos(int pos)
    {
        if(pos < 1 || pos > count)
        {
            cout<<"Invalid position.";
            return;
        }
        else if(pos == 1) delete_at_beg();
        else if(pos == count) delete_at_end();
        else 
        {
            struct list *search = start;
            struct list *sl;
            for(int i=1; i<pos; i++)
            {
                sl = search;
                search = search->next;
            }
            cout<<endl<<search->data<<" is deleted";
            sl->next = search->next;
            delete search;
            count--;
        }
    }
    void travserse()
    {
        if(start == nullptr)
        {
            cout<<endl<<"Linked list is empty";
            return;
        } 
        struct list *temp = start;
        do 
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp != start);
    }
};

int main()
{
    LinkList lt;
    int choice,val,pos;

    while(1)
    {
        cout<<endl<<"Enter your choice : ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<endl<<"Enter the value : ";
            cin>>val;
            cout<<endl<<"Enter the position : ";
            cin>>pos;
            lt.insert_at_pos(val,pos);
        }
        else if(choice == 2)
        {
            cout<<endl<<"Enter the position : ";
            cin>>pos;
            lt.delete_at_pos(pos);
        }
        else if(choice == 3)
        {
            lt.travserse();
        }
        else if(choice == 4)
        {
            break;
        }
        else 
        {
            cout<<endl<<"wrong input ";
        }
    }
}