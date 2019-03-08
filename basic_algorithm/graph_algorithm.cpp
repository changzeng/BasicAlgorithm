//
// Created by Liao Changzeng on 2019/3/7.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef vector<vector<int>> matrix;

struct Triple{
    vector<int> d;
    explicit Triple(int a, int b, int c) {
        this->d.resize(3);
        d[0]=a; d[1]=b; d[2]=c;
    }
    int get(int i){
        return this->d[i];
    }
};

struct cmp{
    bool operator()(Triple &a, Triple &b){
        return a.get(1) > b.get(1);
    }
};

int dijkstra(matrix &map){
    int res=0;
    vector<int> dis(map.size(), INT32_MAX);
    vector<int> version(map.size(), 0);
    vector<bool> visit(map.size(), false);
    priority_queue<Triple, vector<Triple>, cmp> queue;
    visit[0] = true;
    dis[0]=0;
    int cur_node=0, node_num=6;
    while(cur_node<node_num){
        for(int i=1; i<node_num; i++){
            if(visit[i] or map[cur_node][i]==0)
                continue;
            int pre_d=dis[i];
            dis[i] = min(dis[cur_node]+map[cur_node][i], dis[i]);
            if(dis[i] != pre_d){
                version[i]++;
                queue.emplace(i, dis[i], version[i]);
            }
        }
        while(true){
            Triple tmp = queue.top();
            queue.pop();
            if(version[tmp.get(0)] == tmp.get(2)){
                cur_node=tmp.get(0);
                visit[cur_node] = true;
                if(cur_node == node_num-1)
                    return tmp.get(1);
                break;
            }
        }
    }
    return -1;
}

//int main(){
//    matrix map;
//    map.push_back(vector<int>({0, 5, 10, 0, 0, 0}));
//    map.push_back(vector<int>({5, 0, 4, 0, 30, 20}));
//    map.push_back(vector<int>({10, 4, 0, 5, 0, 0}));
//    map.push_back(vector<int>({0, 0, 5, 0, 0, 7}));
//    map.push_back(vector<int>({0, 30, 0, 0, 0, 1}));
//    map.push_back(vector<int>({0, 20, 0, 7, 1, 0}));
//
//    cout<<dijkstra(map)<<endl;
//    return 0;
//}

