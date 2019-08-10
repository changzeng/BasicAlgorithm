#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int ans=0, building_num;
	cin>>building_num;
	vector<int> height_vec(building_num);
	for(int ind=0; ind<building_num; ind++){
		cin>>height_vec[ind];
	}

	for(int ind=building_num-1; ind>=0; ind--){
		ans = ceil((ans+height_vec[ind])/2.0);
	}

	cout<<ans<<endl;

	return 0;
}
