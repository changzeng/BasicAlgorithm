#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> get_delete_char_list(string &str1, string &str2){
    set<char> char_set;
    vector<char> result;
    for(auto c:str1){
        char_set.insert(c);
    }
    for(auto c:str2){
        if(char_set.find(c) == char_set.end())
            result.push_back(c);
    }
    return result;
}

int main(){
    string s1="abc";
    string s2="cbdaef";

    for(auto c:get_delete_char_list(s1, s2))
        cout<<c<<" ";

    return 0;
}
