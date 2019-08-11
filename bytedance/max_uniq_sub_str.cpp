#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int max_uniq_sub_str(string &str){
    unordered_map<char, int> char_to_ind;
    int start=0, max_len=0;
    for(int i=0; i<(int)str.size(); i++){
        char c=str[i];
        auto item = char_to_ind.find(c);
        if(item != char_to_ind.end()) {
            max_len = max(max_len, i - start);
            start = item->second + 1;
        }
        char_to_ind[c] = i;
    }
    return max(max_len, (int)str.size()-start);
}

int main(){
    string str="aabcdefgaaaaaaaaaaaaaaaaaaaa";

    cout<<max_uniq_sub_str(str)<<endl;

    return 0;
}
