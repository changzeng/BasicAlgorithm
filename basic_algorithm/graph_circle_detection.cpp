#include <iostream>
#include <vector>

using namespace std;

bool graph_circle_detection(vector<vector<int>> &graph, int node_num){
    vector<int> enter_num(node_num, 0);
    vector<int> is_visit(node_num, 0);
    int visit_num=0;
    for(int i=0; i<node_num; i++){
        for(int j=0; j<node_num; j++){
            if(graph[i][j])
                enter_num[j]++;
        }
    }
    vector<int> zero_enter_list;
    for(int i=0; i<node_num; i++) {
        if (!enter_num[i]) {
            zero_enter_list.push_back(i);
            is_visit[i] = 1;
        }
    }

    while(!zero_enter_list.empty()){
        int zero_point = zero_enter_list.back();
        zero_enter_list.pop_back();
        visit_num++;
        for(int i=0; i<node_num; i++){
            enter_num[i] -= graph[zero_point][i];
            if(!enter_num[i] and !is_visit[i]) {
                zero_enter_list.push_back(i);
                is_visit[i] = 1;
            }
        }
    }

    return visit_num!=node_num;
}

int main(){
    vector<vector<int>> graph({
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
    });

    cout<<graph_circle_detection(graph, 4)<<endl;

    return 0;
}

