#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& nums, int target) {
    int left=0, right=(int)nums.size()-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(target == nums[left])
            return left;
        if(target == nums[mid])
            return mid;
        if(target == nums[right])
            return right;
        if(nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++, right--;
        }else if(nums[left] < nums[mid]){
            if(nums[left] < target && target < nums[mid])
                right = mid-1, left++;
            else
                left = mid+1, right--;
        }else{
            if(nums[mid] < target && target < nums[right])
                left = mid+1, right--;
            else
                right = mid - 1, left++;
        }
    }
    return -1;
}

int main(){
    vector<int> array = vector<int>({2, 2, 3, 4, 5, 2});
    cout<<binary_search(array, 5)<<endl;
    return 0;
}