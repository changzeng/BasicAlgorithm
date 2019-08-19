#include <iostream>
#include <vector>
#include <string>

using namespace std;

void preprocess(const string &str, vector<int> &dp){
    dp.resize(str.size());
    dp[0] = 0;
    for(int i=1; i<(int)str.size(); i++){
        int cur_ind = i-1;
        while(cur_ind>0 && str[cur_ind] != str[i]){
            cur_ind = dp[cur_ind];
        }
        if(str[cur_ind] == str[i])
            dp[i] = dp[cur_ind]+1;
    }
}

bool is_match(string &str1, string &str2){
    vector<int> dp;
    preprocess(str2, dp);
    int str2_ind=0;
    for(char i : str1){
        if(i == str2[str2_ind]) {
            str2_ind++;
        }else{
            while(str2_ind>0 && i != str2[str2_ind]){
                str2_ind = dp[str2_ind];
            }
            if(i == str2[str2_ind])
                str2_ind++;
        }
        if(str2_ind >= str2.size())
            return true;
    }
    return false;
}

int main(){
    string str1="abccccabacefgs", str2="aba";
    cout<<is_match(str1, str2)<<endl;

    return 0;
}