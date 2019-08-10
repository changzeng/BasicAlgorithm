#include<iostream>
#include<vector>

using namespace std;

int binary_search_uniq(vector<int> &array, int val){
	int left=0, right=array.size()-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(array[mid] == val){
			return mid;
		}

		if(array[mid] < array[right]){
			if(array[mid] < val && val <= array[right])
				left = mid + 1;
			else
				right = mid - 1;
		}else{
			if(array[left] <= val < array[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return -1;
}

int binary_search_repeat(vector<int> &array, int val){

}

int main(){
	vector<int> array = vector<int>({6, 7, 8 ,9, 0, 1, 3, 4, 5});

	cout<<binary_search_uniq(array, 0)<<endl;

	return 0;
}
