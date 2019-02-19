//
// Created by pc-20171125 on 2019/2/19.
//

/*
 * Nero在小魔方上做了一些改动，用数字替换每个块上面的颜色，称之为数字魔方。魔方上每一面的优美度就是这个面上4个数字的乘积，而魔方的总优美度就是6个面优美度总和。
现在Nero有一个数字魔方，他想知道这个魔方在操作不超过5次的前提下能达到的最大优美度是多少。
魔方展开后每一块的序号如下图：
 100% AC
 */

#include <iostream>
#include <vector>

using namespace std;

int mp[6][24] = {
    {0, 21, 2, 23, 4, 5, 6, 1, 9, 15, 10, 11, 12, 3, 8, 14, 16, 7, 18, 13, 20, 17, 22, 19},
    {0, 7, 2, 13, 4, 5, 6, 17, 14, 8, 10, 11, 12, 19, 15, 9, 16, 21, 18, 23, 20, 1, 22, 3},
    {2, 0, 3, 1, 6, 7, 8, 9, 23, 22, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 5, 4},
    {1, 3, 0, 2, 23, 22, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 9, 8},
    {0, 1, 8, 14, 4, 3, 7, 13, 17, 9, 10, 2, 6, 12, 16, 15, 5, 11, 18, 19, 20, 21, 22, 23},
    {0, 1, 11, 5, 4, 16, 12, 6, 2, 9, 10, 17, 13, 7, 3, 15, 14, 8, 18, 19, 20, 21, 22, 23}
};

int b_value(const vector<int> &nums){
    int res = 0;
    res += nums[0]*nums[1]*nums[2]*nums[3];
    res += nums[6]*nums[7]*nums[12]*nums[13];
    res += nums[4]*nums[5]*nums[10]*nums[11];
    res += nums[8]*nums[9]*nums[14]*nums[15];
    res += nums[16]*nums[17]*nums[18]*nums[19];
    res += nums[20]*nums[21]*nums[22]*nums[23];
    return res;
}

vector<int> rotate(vector<int> &nums, int d){
    auto res = nums;
    for(int i=0; i<24; i++)
        res[i] = nums[mp[d][i]];
    return res;
}

void dp(vector<int> &nums, int depth, int &value){
    for(int i=0; i<6; i++){
        auto rotate_res = rotate(nums, i);
        value = max(value, b_value(rotate_res));
        if(depth<5)
            dp(rotate_res, depth+1, value);
    }
}

int main(){
    vector<int> nums(24);
    for(int i=0; i<24; i++)
        cin>>nums[i];

    int max_b_value = b_value(nums);
    dp(nums, 1, max_b_value);
    cout<<max_b_value<<endl;

    return 0;
}