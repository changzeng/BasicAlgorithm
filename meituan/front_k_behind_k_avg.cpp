//
// Created by Liao Changzeng on 2019/3/13.
//

/*
 * 给定数组A1和A2, A2[i] = A2[i]前k个和后k个共2k+1个元素的均值，如果缺失值则有多少算多少，计算A1。
 */

#include <iostream>
#include <vector>

using namespace std;

void calculate(vector<double> &a_1, vector<double> &a_2, int k){
    double tmp_sum;
    int count = k, array_size = a_1.size();
    for(int i=0; i<count; i++){
        tmp_sum += a_2[i];
    }
    for(int i=0; i<array_size; i++){
        int left = i-k-1, right = i+k;
        if(left >= 0) {
            tmp_sum -= a_2[left];
            count--;
        }
        if(right < array_size){
            tmp_sum += a_2[right];
            count++;
        }
        a_1[i] = tmp_sum/count;
    }
}

//int main(){
//    int num, k; cin>>num>>k;
//    vector<double> a_1(num), a_2(num);
//    for(int i=0; i<num; i++)
//        cin>>a_2[i];
//    calculate(a_1, a_2, k);
//    for(auto val : a_1)
//        cout<<val<<endl;
//
//    return 0;
//}
