//
// Created by pc-20171125 on 2019/2/16.
//

/*
 给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：
 区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:
 [6] = 6 * 6 = 36;
 [2] = 2 * 2 = 4;
 [1] = 1 * 1 = 1;
 [6,2] = 2 * 8 = 16;
 [2,1] = 1 * 3 = 3;
 [6, 2, 1] = 1 * 9 = 9;
 从上述计算可见选定区间 [6] ，计算值为 36， 则程序输出为 36。
 区间内的所有数字都在[0, 100]的范围内;
 */

#include <iostream>
#include <vector>
#include <limits>

using std::pair;
using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::max;
using std::endl;

// O(N^2) 超时
int max_interval_1(const vector<int> &_input){
    int res=INT32_MIN;
    for(int i=0; i<_input.size()-1; i++){
        int _sum=_input[i], _min=_input[i];
        int _max = _sum*_min;
        for(int j=i+1; j<_input.size(); j++){
            _sum += _input[j];
            _min = min(_min, _input[j]);
            _max = max(_max, _sum*_min);
        }
        res = max(_max, res);
    }
    return res;
}

// O(N)
int max_interval_2(const vector<int> &_input){
    int res=INT32_MIN;
    for(int i=100; i>0; i--){
        int _sum=0, _min=101;
        for(auto val : _input){
            if(val >=i){
                _sum += val;
                _min = min(_min, val);
            }else{
                res = max(res, _sum*_min);
                _sum=0, _min=101;
            }
        }
        res = max(res, _sum*_min);
    }
    return res;
}

//int main(){
//    int num;cin>>num;
//    vector<int> _input; _input.resize(num);
//    for(int i=0; i<num; i++){
//        cin>>_input[i];
//    }
//    cout<<max_interval_2(_input)<<endl;
//    return 0;
//}