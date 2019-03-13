//
// Created by Liao Changzeng on 2019/3/13.
//

/*
 * 问题描述：一个数组先递增后递减，求最大值。
 *
 * case:
 * 5
 * 1 2 3 2 1
 * answer: 3
 *
 * 5
 * 1 2 1 0 -1
 * answer: 3
 */

// O(lg(n))解法

#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &array){
    int left=0, right=array.size()-1;
    int mid;
    while(left<right){
        if(right - left <= 1)
            return array[left];
        mid = (left+right)/2;
        if(array[mid] > array[mid-1]){
            left = mid;
        }else{
            right = mid;
        }
    }
}

//int main(){
//    int array_size; cin>>array_size;
//    vector<int> array(array_size);
//    for(int i=0; i<array_size; i++)
//        cin>>array[i];
//    cout<<binary_search(array)<<endl;
//
//    return 0;
//}
