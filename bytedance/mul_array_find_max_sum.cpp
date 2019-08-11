#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> val_list;

int find_max_sum(vector<val_list> &array){
    int pre=0, cur=0;
    int result=0;
    for(int i=(int)array.size()-1; i>=0; i--){
        for(int j=0; j<(int)array[0].size(); j++){
            if(array[i][j] > cur){
                if(i!=array.size()-1){
                    if(array[i][j] <= pre)
                        cur = array[i][j];
                }else{
                    cur = array[i][j];
                }
            }
        }
        result += cur;
        pre=cur; cur=0;
    }
    return result;
}

int main(){
    vector<val_list> array({
        {3, 1, 3, 1, 3},
        {3, 1, 3, 1, 3},
        {3, 1, 3, 1, 3},
        {2, 1, 2, 1, 2},
        {3, 1, 3, 1, 3},
        {3, 1, 3, 1, 3}
    });

    cout<<find_max_sum(array)<<endl;
}
