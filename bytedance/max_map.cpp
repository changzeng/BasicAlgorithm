//
// Created by pc-20171125 on 2019/2/16.
//

/*
 有 n 个字符串，每个字符串都是由 A-J 的大写字符构成。现在你将每个字符映射为一个 0-9 的数字，不同字符
 映射为不同的数字。这样每个字符串就可以看做一个整数，唯一的要求是这些整数必须是正整数且它们的字符串不
 能有前导零。现在问你怎样映射字符才能使得这些字符串表示的整数之和最大？

 input:
     2 -- 字符串个数
     2 -- 字符串个数
     ABC
     BCA
 output:
    1875
 */

#include <thread>
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<char, LL> __pair;

LL max_map(const vector<string> &_input){
    unordered_map<char, LL> char_val;
    unordered_map<char, bool> is_head;
    LL tmp=1;
    for(auto _str : _input){
        is_head[_str[0]] = true;
        tmp = (LL)pow(10, _str.size()-1);
        for(auto c : _str){
            char_val[c] += tmp;
            tmp /= 10;
        }
    }
    vector<__pair> pair_vec;
    pair_vec.reserve(char_val.size());
    for(auto val : char_val){
        pair_vec.emplace_back(val);
    }
    sort(pair_vec.begin(), pair_vec.end(), [](__pair a, __pair b){return a.second>b.second;});
    int ind=9;
    LL res=0;

    char zero_char='Z';
    if(pair_vec.size() == 10){
        for(auto val : pair_vec){
            if(!is_head[val.first])
                zero_char = val.first;
        }
    }
    for(auto val : pair_vec){
        if(val.first == zero_char)
            continue;
        res += val.second*ind;
        ind--;
    }

    return res;
}

//int main(){
//    LL a;
//    string tmp;
//    vector<string> _input;
//    int _input_size;cin>>_input_size;
//    for(int i=0; i<_input_size; i++){
//        cin>>tmp;
//        _input.push_back(tmp);
//    }
//    cout<<max_map(_input)<<endl;
//
//    return 0;
//}
