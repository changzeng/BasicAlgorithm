//
// Created by pc-20171125 on 2019/2/14.
//

#ifndef BASICALGORITHM_HEAP_H
#define BASICALGORITHM_HEAP_H

#include <vector>

using std::vector;

class Heap{
public:
    Heap(const vector<int> &_input);
    void sink(int i);
    void floating(int i);
    void print();
    int pop();
    void insert(int val);
private:
    int size;
    vector<int> container;
};

#endif //BASICALGORITHM_HEAP_H
