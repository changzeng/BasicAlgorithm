#include <iostream>
#include <vector>

using namespace std;

int max_continue_sum(vector<int> &array){
    if((int)array.size()<=0)
        return 0;
    int max_sum=array[0], tmp_sum=array[0];
    for(int i=1; i<array.size(); i++){
        if(tmp_sum>0 && tmp_sum+array[i]>0)
            tmp_sum += array[i];
        else
            tmp_sum = array[i];
        max_sum = max(max_sum, tmp_sum);
    }
    return max_sum;
}

int main(){
    vector<int> array({4, 1, 3, -1, 3, -10, 1});

    cout<<max_continue_sum(array)<<endl;

    return 0;
}
