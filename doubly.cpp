#include<iostream>
using namespace std;

struct list
{
    struct list *pre;
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
            start->pre = nullptr;
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
            temp->pre = nullptr;
            temp->data = val;
            temp->next = start;
            start->pre = temp;
            start = temp;
        }
        cout<<val<<" is inserted into linked list"<<endl;
        count++;
    }
    void insert_at_end(int val)
    {
        struct list *temp = new list;
        temp->pre = last;
        temp->data = val;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
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
            struct list *sl = nullptr;
            for(int i=1; i<pos; i++)
            {
                sl = search;
                search = search->next;
            }
            struct list *temp = new list;
            temp->pre = search->pre;
            temp->data = val;
            temp->next = search;
            search->pre = temp;
            sl->next = temp;
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
        struct list *temp = start;
        cout<<start->data<<" is delted";
        if(start->next == nullptr)
        {
            delete start;
           start = last = nullptr;
           count--;
           return;
        }
        start = start->next;
        start->pre = nullptr;
        delete temp;
        count--;
    }
    void delete_at_end()
    {
        struct list *temp = last;
        cout<<endl<<last->data<<" is deleted";
        last = last->pre;
        last->next = nullptr;
        delete temp;
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
            struct list *sl= nullptr;
            for(int i=1; i<pos; i++)
            {
                sl = search;
                search = search->next;
            }
            cout<<endl<<search->data<<" is deleted";
            struct list *temp = search->next;
            sl->next = temp;
            temp->pre = sl;
            delete search;
            count--;
        }
    }
    // traverse logic
    void traverse()
    {
        if(start == nullptr)
        {
            cout<<endl<<"Linked list is empty";
            return;
        } 
        struct list *temp = start;
        while(temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void rev_traverse()
    {
        if(last == nullptr)
        {
            cout<<endl<<"Linked list is empty";
            return;
        } 
        struct list *temp = last;
        while(temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->pre;
        }
    }

};


// main part
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
            lt.traverse();
        }
        else if(choice == 4)
        {
            lt.rev_traverse();
        }
        else if(choice == 5)
        {
            break;
        }
        else 
        {
            cout<<endl<<"wrong input ";
        }
    }
}