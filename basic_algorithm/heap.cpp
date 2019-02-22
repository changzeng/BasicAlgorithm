//
// Created by pc-20171125 on 2019/2/14.
//

#include "heap.h"
#include <iostream>

using std::swap;
using std::cout;
using std::endl;

Heap::Heap(const vector<int> &_input){
    this->size = _input.size();
    this->container.resize((unsigned)size+1);
    for(int i=1; i<=this->size; i++)
        this->container[i] = _input[i-1];
    int cur=this->size/2;
    while(cur > 0){
        sink(cur);
        cur--;
    }
}

void Heap::sink(int i){
    while(2*i-1 <= size){
        int left = 2*i;
        int right = 2*i+1;
        int min = i;
        if(left <= size && container[left]<container[min])
            min = left;
        if(right <= size && container[right]<container[min])
            min = right;
        if(min == i)
            break;
        swap(container[i], container[min]);
        i = min;
    }
}

void Heap::floating(int i){
    while(i > 0){
        int top = i/2;
        if(container[top] <= container[i])
            break;
        swap(container[top], container[i]);
        i = top;
    }
}

int Heap::pop(){
    int res = container[1];
    container[1] = container[size];
    size--;
    sink(1);

    return res;
}

void Heap::insert(int val){
    size++;
    container.push_back(val);
    floating(size);
}

void Heap::print(){
    for(int i=1; i<size; i++)
        cout<<container[i]<<" ";
    cout<<endl;
}