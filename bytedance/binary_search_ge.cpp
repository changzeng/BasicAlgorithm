#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int> &array, int val){
	int left=0, right=array.size()-1, res=-1;
	while(right >= left){
		int mid = (left+right)/2;
		if(array[mid] >= val){
			res = mid;
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return res;
}

int main(){
	vector<int> test_vec_1 = vector<int>({1, 2, 2, 3, 3, 3, 5});
	int search_num_1 = 2;

	cout<<binary_search(test_vec_1, search_num_1)<<endl;

	return 0;
}
