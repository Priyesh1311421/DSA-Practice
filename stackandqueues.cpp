#include <bits/stdc++.h>
using namespace std;


class Stack{
    int* st;
    int size;
    int top = -1;

    Stack(int size){
        this->size = size;
        st = new int [size];
    }

    ~Stack(){
        delete []st;
    }


    void push(int x){
        if(top < size-1){
            top++;
            st[top] = x;
        }
        else{
            cout<< 'Stack full';
        }
    }
    void pop(){
        if(top < 0){
            cout<<"stack empty";
        }else{
            top--;
        }
    }

    int peek(){
        if(top >= 0){
            return st[top];
        }else{
            return -1;
        }
    }
};



class Queue{
    int* q;
    int size;
    int front = -1;
    int rear = -1;

public:
    Queue(int size){
        this->size = size;
        q = new int[size];
    }

    ~Queue(){
        delete [] q;
    }

    void push(int x){
        if(rear < size - 1){
            if(front == -1){
                front = 0;
            }
            rear++;
            q[rear] = x;
        }
        else{
            cout << "Queue full";
        }
    }

    void pop(){
        if(front == -1 || front > rear){
            cout << "Queue empty";
        }
        else{
            front++;
        }
    }

    int peek(){
        if(front != -1 && front <= rear){
            return q[front];
        }
        else{
            return -1;
        }
    }
};

int main(){
    return 0;
}
