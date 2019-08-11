#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(int v1, int v2){
        return v1>v2;
    }
};

float find_proper_height(vector<int> &forest, float C){
    sort(forest.begin(), forest.end(), cmp());
    float trim=0.0, trim_h=0.0;
    int trim_num=0;
    while(trim_num<(int)forest.size()-1){
        if(trim >= C) {
            return trim_h;
        }
        trim_num++;
        int diff = forest[trim_num-1] - forest[trim_num];
        if(trim+trim_num*diff >= C){
            return trim_h + (C-trim)/trim_num;
        }
        trim_h += diff;
        trim += trim_num*diff;
    }
    return trim_h + (C-trim)/(trim_num+1);
}

int main(){
    vector<int> height_vec = vector<int>({4, 1, 3});
    cout<<find_proper_height(height_vec, 4.0)<<endl;

    return 0;
}