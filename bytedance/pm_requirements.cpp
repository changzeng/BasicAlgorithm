//
// Created by pc-20171125 on 2019/2/17.
//

/*
30% 通过率 i don't know why?
产品经理(PM)有很多好的idea，而这些idea需要程序员实现。现在有N个PM，在某个时间会想出一个 idea，每个 idea 有提出时间、所需时间和优先等级。对于一个PM来说，最想实现的idea首先考虑优先等级高的，相同的情况下优先所需时间最小的，还相同的情况下选择最早想出的，没有 PM 会在同一时刻提出两个 idea。

同时有M个程序员，每个程序员空闲的时候就会查看每个PM尚未执行并且最想完成的一个idea,然后从中挑选出所需时间最小的一个idea独立实现，如果所需时间相同则选择PM序号最小的。直到完成了idea才会重复上述操作。如果有多个同时处于空闲状态的程序员，那么他们会依次进行查看idea的操作。

求每个idea实现的时间。

输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。随后有P行，每行有4个数字，分别是PM序号、提出时间、优先等级和所需时间。输出P行，分别表示每个idea实现的时间点。


输入描述:
输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。随后有P行，每行有4个数字，分别是PM序号、提出时间、优先等级和所需时间。全部数据范围 [1, 3000]。

输出描述:
输出P行，分别表示每个idea实现的时间点。

输入例子1:
2 2 5
1 1 1 2
1 2 1 1
1 3 2 2
2 1 1 2
2 3 5 5

输出例子1:
3
4
5
3
9
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct Req{
    Req():id(-1){};
    Req(int id, int ind, int _time, int p, int c):id(id),ind(ind),_time(_time),p(p),c(c){};
    int id;
    int ind;
    int _time;
    int p;
    int c;
};

struct most_need_req{
    bool operator()(const Req &a, const Req &b){
        bool res;
        if(a.p == b.p){
            if(a.c == b.c){
                res = a._time < b._time;
            }else{
                res = a.c < b.c;
            }
        }else{
            res = a.p > b.p;
        }
        return !res;
    }
};

typedef pair<int, int> PAIR;
typedef priority_queue<Req, vector<Req>, most_need_req> pm_queue;

bool rd_select_func(const Req &a, const Req &b){
    bool res;
    if(a.c == b.c){
        res = a.ind < b.ind;
    }else{
        res = a.c < b.c;
    }
    return res;
}

struct rd_cmp{
    bool operator()(const PAIR &a, const PAIR &b){
        return a.second > b.second;
    }
};

//int main(){
//    priority_queue<PAIR, vector<PAIR>, rd_cmp> rd_queue;
//    unordered_map<int, pm_queue> all_pm_req;
//    unordered_map<int, int> req_finish_time;
//
//    int pm_num, rd_num, req_num;
//    cin>>pm_num>>rd_num>>req_num;
//    vector<Req> all_req;
//    int ind, _time, p, c;
//    for(int i=0; i<req_num; i++){
//        cin>>ind>>_time>>p>>c;
//        all_req.emplace_back(i, ind, _time, p, c);
//    }
//    sort(all_req.begin(), all_req.end(), [](Req &a, Req &b){return a._time<b._time;});
//
//    for(int i=0; i<rd_num; i++){
//        rd_queue.emplace(i, 1);
//    }
//
//    int left_ind=0;
//    while(left_ind < all_req.size()){
//        int cur_time=all_req[left_ind]._time;
//        while(left_ind<all_req.size() && all_req[left_ind]._time == cur_time){
//            // cout<<cur_time<<endl;
//            Req tmp_req = all_req[left_ind];
//            all_pm_req[tmp_req.ind].push(tmp_req);
//            left_ind++;
//        }
//        if(left_ind >= all_req.size())
//            cur_time = INT32_MAX;
//        while(rd_queue.top().second <= cur_time){
//            Req most_req;
//            for(int i=1; i<=pm_num; i++){
//                if(all_pm_req[i].empty())
//                    continue;
//                if(most_req.id == -1 or rd_select_func(all_pm_req[i].top(), most_req)){
//                    most_req = all_pm_req[i].top();
//                }
//            }
//            if(most_req.id == -1)
//                break;
//            // Req item = most_req;
//            // cout << item.id << " " << item.ind << " " << item._time << " " << item.p << " " << item.c << endl;
//            all_pm_req[most_req.ind].pop();
//            PAIR exc_rd = rd_queue.top(); rd_queue.pop();
//            exc_rd.second = max(exc_rd.second, most_req._time) + most_req.c;
//            // cout<<exc_rd.second<<" "<<most_req._time<<" "<<most_req.id<<" "<<exc_rd.second<<endl;
//            req_finish_time[most_req.id] = exc_rd.second;
//            rd_queue.push(exc_rd);
//        }
//    }
//
//    // cout<<endl;
//    for(int i=0; i<req_num; i++){
//        cout<<req_finish_time[i]<<endl;
//    }
//
////    for(int i=1; i<=pm_num; i++){
////        while(!all_pm_req[i].empty()){
////            auto item = all_pm_req[i].top();
////            all_pm_req[i].pop();
////            cout << item.id << " " << item.ind << " " << item._time << " " << item.p << " " << item.c << endl;
////        }
////        cout << endl;
////    }
//
//    return 0;
//}