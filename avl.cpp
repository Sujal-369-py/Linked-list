#include<iostream>
using namespace std;

struct tree 
{
    int data;
    struct tree *l;
    struct tree *r;
};

struct tree *root = nullptr;

class Tree 
{
    public: 

    int treeHeight();

    void insert(int val)
    {
        if(root == nullptr)
        {
            root = new tree;
            root->data = val;
            root->l = nullptr;
            root->r = nullptr;
            cout<<val<<" is insereted as ROOT into tree"<<endl;
        }
        else 
        {
            struct tree *temp = new tree;
            temp->data = val;
            temp->l = nullptr;
            temp->r = nullptr;
            struct tree *search = root;
            struct tree *sl = nullptr;
            while(search != nullptr)
            {
                sl = search;
                if(temp->data < search->data) search = search->l;
                else search = search->r;
            }
            if(temp->data < sl->data) sl->l = temp;
            else sl->r = temp;
            cout<<val<<" is insereted into tree"<<endl;
        }
    }
    struct tree *treeHeight()
    {
        int count = 0;
        struct tree *temp = root;
        while(temp != nullptr)
        {
            struct tree *temp2 = temp;
            while(temp2 != nullptr)
            {
                count++;
                temp2 = temp2->r;
                if(count == 2 || count == -2) return temp;
            }
            temp = temp->r;
        }
        temp = root;
        while(temp != nullptr)
        {
            struct tree *temp2 = temp;
            while(temp2 != nullptr)
            {
                count++;
                temp2 = temp2->l;
                if(count == 2 || count == -2) return temp;
            }
            temp = temp->l;
        }
        return nullptr;
    }
    void traverse(struct tree *temp)
    {
        if(temp == nullptr) return;
        cout<<temp->data<<" ";
        traverse(temp->l);
        traverse(temp->r);
    }
    void search(int found)
    {
        struct tree *temp = root;
        while(temp != nullptr)
        {
            if(temp->data == found)
            {
                cout<<endl<<found<<" is founded"<<endl;
                break;
            }
            else if(found < temp->data) temp = temp->l;
            else temp = temp->r;
        }
    }
    int treeDepth(struct tree *temp)
    {
       if(temp == nullptr) return -1;
       return max(treeDepth(temp->l),treeDepth(temp->r)) + 1;
    }
};

int main()
{
    Tree t;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    t.insert(10);
    t.insert(25);
    t.insert(35);
    t.insert(45);
    t.insert(55);
    t.insert(65);
    t.insert(75);
    t.insert(85);
    int len = t.treeDepth(root);
    cout<<"Total depth of tree : "<<len;

}