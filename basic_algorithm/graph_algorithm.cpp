//
// Created by Liao Changzeng on 2019/3/7.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> matrix;

int dijkstra(matrix &map){
    int res=0;
    vector<int> dis(map.size(), -1);
    vector<bool> visit(map.size(), false);
    return 0;
}

struct Triple{
    vector<int> d;
    Triple(int a[3]) {
        d.resize(3);
        for (int i = 0; i < 3; i++)
            d[i] = a[i];
    }
    bool operator()(const Triple &a, const Triple &b){
        return a.d[1] > b.d[1];
    }
};


//int main(){
//    matrix map;
//    map.emplace_back({0, 5, 10, 0, 0, 0});
//    map.emplace_back({5, 0, 4, 0, 30, 20});
//    map.emplace_back({10, 4, 0, 5, 0, 0});
//    map.emplace_back({0, 0, 5, 0, 0, 7});
//    map.emplace_back({0, 30, 0, 0, 0, 1});
//    map.emplace_back({0, 20, 0, 7, 1, 0});

//    priority_queue<Triple, vector<Triple>> test;
//    test.emplace({1, 3, 1});
//    test.emplace({1, 2, 1});
//    test.emplace({1, 1, 1});
//    while(!test.empty()){
//        cout<<test.top()[1]<<endl;
//        test.pop();
//    }
//
//    return 0;
//}

