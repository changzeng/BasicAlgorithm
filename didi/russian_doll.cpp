//
// Created by Liao Changzeng on 2019/3/8.
//

/*
 * 每一个套娃都有一个尺寸规格，宽和高用一对整型来表示（w,h），当套娃A的宽和高都小于套娃B的时候，套娃A就可以嵌套进套娃B内，
 * 在多个套娃的尺寸数据中找出可以依次嵌套最多的个数。
 *
 *  输入：
    4
    5 4
    6 4
    6 7
    2 3

    输出：
    3
 */

#include <iostream>
#include <vector>

using namespace std;

//int main(){
//    typedef pair<int, int> i_i_p;
//    int doll_num; cin>>doll_num;
//    vector<pair<int, int>> doll_list;
//    for(int i=0; i<doll_num; i++){
//        int a, b; cin>>a>>b;
//        doll_list.emplace_back(a, b);
//    }
//    sort(doll_list.begin(), doll_list.end(), [](i_i_p &a, i_i_p &b){return a.first<b.first;});
//
//    vector<int> dp(doll_num, 1);
//    int res = 1;
//    for(int i=1; i<doll_num; i++){
//        for(int j=0; j<i; j++){
//            if(doll_list[i].first>doll_list[j].first && doll_list[i].second>doll_list[j].second){
//                dp[i] = max(dp[i], dp[j]+1);
//                res = max(dp[i], res);
//            }
//        }
//    }
//    cout<<res<<endl;
//
//    return 0;
//}
