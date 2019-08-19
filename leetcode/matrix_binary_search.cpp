#include <iostream>
#include <vector>

using namespace std;

bool search_matrix_1(vector<vector<int>> &matrix, int val){
    if((int)matrix.size()==0 || (int)matrix[0].size()==0)
        return false;
    int row_ind=0, col_ind=matrix[0].size()-1;
    while(row_ind<(int)matrix.size() && col_ind>0){
        if(matrix[row_ind][col_ind] > val){
            col_ind--;
        }else if(matrix[row_ind][col_ind] < val){
            row_ind++;
        }else{
            return true;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>({1, 3, 5, 7}));
    matrix.push_back(vector<int>({10, 11, 16, 20}));
    matrix.push_back(vector<int>({23, 30, 34, 50}));

    cout<<search_matrix_1(matrix, 11)<<endl;

    return 0;
}