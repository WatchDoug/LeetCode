#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int maxArea(vector<int>& height){
	// Can be simplified to only two pointers with only constant space overhead
	vector<tuple<int, int> > leftbound;
    vector<tuple<int, int> > rightbound;
	int res = 0;
    int sz = height.size();
    if(sz==0 || sz==1)
        return 0;
    leftbound.push_back({height[0], 0});
    rightbound.push_back({height[sz-1], sz-1});
    for(int i=1;i<sz;++i){
        if(height[i] > std::get<0>(leftbound.back()))
            leftbound.push_back({height[i], i});
    }
    for(int i=sz-2;i>=0;--i){
        if(height[i] > std::get<0>(rightbound.back()))
            rightbound.push_back({height[i], i});
    }
	int lp = 0, rp = 0;
	for(auto item : leftbound){
		int t = 0;
		while(rp<rightbound.size()-1 && std::get<0>(rightbound[rp]) < std::get<0>(item)){
			t = std::get<0>(rightbound[rp])*(std::get<1>(rightbound[rp])-std::get<1>(item));
			res = res>t?res:t;
			++rp;
		}
		t = std::get<0>(item)*(std::get<1>(rightbound[rp])-std::get<1>(item));
		res = res>t?res:t;
	}
	return res;
}
int main(){
	int n, t;
	vector<int> input;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t;
		input.push_back(t);
	}
	cout<<maxArea(input)<<"\n";
	return 0;
}
