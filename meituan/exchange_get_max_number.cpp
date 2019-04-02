//
// Created by Liao Changzeng on 2019/3/14.
//

/*
 * 问题描述：给定一个数字，仅能交换相邻的两个数字，问在在最多k次交换的情况下数字能最大能为多少。
 * 输入：
 * 5 2
 * 1 2 3 5 4
 * 输出：
 * 3 1 2 5 4
 */

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> element;

struct cmp{
    bool operator()(element &a, element &b){
        return a.first < b.first;
    }
};

int find_max_in_k(vector<int> &array, int k){
    priority_queue<element, vector<element>, cmp> tmp_queue;
    vector<int> res;
    int array_size = array.size();
    k = min(array_size, k);
    int left = k, right = 0, finish=0;
    for(int i=0; i<array_size; i++){
        if(left>0){
            while(right < array_size && right <= i + left)
                tmp_queue.emplace(array[right++], right);
            auto tmp_pair = tmp_queue.top();
            tmp_queue.pop();
            while(tmp_pair.second+finish > i + left){
                tmp_pair = tmp_queue.top();
                tmp_queue.pop();
            }
            res.push_back(tmp_pair.first);
            if(i != tmp_pair.second+finish) {
                left -= tmp_pair.second + finish - i;
                finish++;
            }
        }else{
            res.push_back(array[i]);
        }
    }
    int res_num=0, base=1;
    for(int i=res.size()-1; i>=0; i--){
        cout<<res[i]<<endl;
        res_num += base*res[i];
        base *= 10;
    }
    return res_num;
}


//int main(){
//    vector<int> test({1, 2, 3, 5, 4});
//    cout<<find_max_in_k(test, 2)<<endl;
//
//    return 0;
//}
