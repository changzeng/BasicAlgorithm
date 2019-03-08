//
// Created by Liao Changzeng on 2019/3/8.
//

/*
 * 对于数组中任意元素M定义排序前的索引位置为a,排序后的索引位置为b，定义|a-b|为元素M的距离。
 * 现给定数据中所有元素的最大距离，问如何最快让数组有序。
 */

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};

void distance_sort(vector<int> &array, int max_dist){
    int right=max_dist+1;
    priority_queue<int, vector<int>, cmp> tmp_queue;
    for(int i=0; i<right; i++)
        tmp_queue.push(array[i]);
    for(int i=0; i<array.size(); i++){
        array[i] = tmp_queue.top();
        tmp_queue.pop();
        if(right < array.size()){
            tmp_queue.push(array[right]);
            right++;
        }
    }
}

//int main(){
//    vector<int> array({2, 1, 5, 4, 9, 7});
//    distance_sort(array, 1);
//    for(auto val : array){
//        cout<<val<<endl;
//    }
//
//    return 0;
//}
