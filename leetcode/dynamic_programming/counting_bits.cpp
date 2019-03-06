//
// Created by pc-20171125 on 2019/2/18.
//

/*
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]

 faster than 100%, memory use less 100%
 */

#include <iostream>
#include <vector>
#include "heap.h"
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        if(num == 0)
            return res;
        int bit=0, ind;
        for(int i=1; i<=num; i++){
            if(i==1<<(bit+1))
                bit++;
            res[i]=res[i-(1<<bit)]+1;
        }
        return res;
    }
};

//int main(){
//    Solution s;
//    vector<int> res = s.countBits(16);
//
//    for(auto val : res){
//        cout<<val<<" ";
//    }
//    cout<<endl;
//
//    return 0;
//}