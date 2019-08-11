#include <iostream>
#include <vector>

using namespace std;

void find_all_combination(vector<int> &array, vector<int> &path, int ind, int left){
    if(ind >= array.size() || left<=0){
        if(left==0){
            for(int i=0; i<(int)array.size(); i++){
                if(path[i])
                    cout<<array[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    find_all_combination(array, path, ind+1, left);
    path[ind] = 1;
    find_all_combination(array, path, ind+1, left-array[ind]);
    path[ind] = 0;
}

void find_all_combination_loop(vector<int> &array, vector<int> &path, int ind, int left){
    if(left == 0){
        for(auto val:path){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=ind; i<(int)array.size(); i++){
        if(left-array[i] < 0)
            continue;
        path.push_back(array[i]);
        find_all_combination_loop(array, path, i+1, left-array[i]);
        path.pop_back();
    }
}

void find_all_combination_no_restrict(vector<int> &array, vector<int> &path, int left){
    if(left==0){
        for(auto val:path){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<(int)array.size(); i++){
        int remain = left-array[i];
        if(remain<0)
            continue;
        path.push_back(array[i]);
        find_all_combination_no_restrict(array, path, remain);
        path.pop_back();
    }
}

int main(){
    vector<int> array({1,3,6,4,2,7});
    vector<int> path(array.size(), 0);
    vector<int> val_list;

    int search_val = 8;
    cout<<"Restriction"<<endl;
    find_all_combination(array, path, 0, search_val);
    cout<<"Restriction Loop"<<endl;
    path.clear();
    find_all_combination_loop(array, path, 0, search_val);
    cout<<endl<<"No restriction"<<endl;
    find_all_combination_no_restrict(array, val_list, search_val);

    return 0;
}
