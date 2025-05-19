#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    stack<int> st;
    if(st.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    st.push(10);
    if(st.empty()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    st.push(20);
    st.push(30);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

    queue<int> q;
    q.push(10);
    q.back() = 100;
    cout<<q.back()<<endl;
    cout<<boolalpha<<q.empty();
}