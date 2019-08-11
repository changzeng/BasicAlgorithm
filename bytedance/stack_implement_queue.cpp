#include <iostream>
#include <stack>

using namespace std;

class Queue{
public:
    void push(int val){
        s1.push(val);
    };
    int pop(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top(); s2.pop();
        return val;
    };
private:
    stack<int> s1;
    stack<int> s2;
};

int main(){
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.pop()<<endl;
}
