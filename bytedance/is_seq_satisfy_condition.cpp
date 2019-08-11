#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_rising_seq_len(vector<int> &array){
    if((int)array.size() == 0)
        return 0;
    vector<int> val_list({array[0]});
    for(int i=1; i<(int)array.size(); i++){
        int val = array[i];
        if(val > val_list.back()){
            val_list.push_back(val);
        }else if(val < val_list.back()){
            int ind=lower_bound(val_list.begin(), val_list.end(), val)-val_list.begin();
            if(val != val_list[ind]){
                val_list[ind+1] = val;
            }
        }
    }
    return val_list.size();
}

bool is_seq_satisfy_condition(vector<int> &array){
    if((int)array.size() == 0)
        return false;
    vector<int> val_list({array[0]});
    for(int i=1; i<(int)array.size(); i++){
        int val = array[i];
        if(val > val_list.back()){
            val_list.push_back(val);
            if(val_list.size() >= 3)
                return true;
        }else if(val < val_list.back()){
            int ind=lower_bound(val_list.begin(), val_list.end(), val)-val_list.begin();
            if(val != val_list[ind]){
                val_list[ind+1] = val;
            }
        }
    }
    return val_list.size()>=3;
}

int main(){
    vector<int> array({1, 2, 2, 3, 4, 4, 5});

    cout<<longest_rising_seq_len(array)<<endl;
    cout<<is_seq_satisfy_condition(array)<<endl;

    return 0;
}
