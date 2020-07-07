#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    vector<int> mergedInterval;
    int l = newInterval[0];
    int r = newInterval[1];
    int lb = 0, rb = intervals.size()-1;
    int indexl = 0, indexr = intervals.size()-1;
    if(intervals.size() == 0){
        mergedInterval.push_back(l);
        mergedInterval.push_back(r);
        res.push_back(mergedInterval);
        return res;
    }
    while(lb != rb){
        //binary search l in upper bound
        int mid = (lb+rb)/2;
        if(intervals[mid][1] == l)
            lb = rb = mid;
        else if(intervals[mid][1] < l){
            if(lb == mid)
                lb = rb;
            else
                lb = mid;
        }
        else
            rb = mid;
    }
    indexl = lb;
    lb = 0, rb = intervals.size()-1;
    while(lb != rb){
        int mid = (lb+rb)/2;
        if(intervals[mid][0] == r)
            lb = rb = mid;
        else if(intervals[mid][0] < r){
            if(lb == mid)
                rb = lb;
            else
                lb = mid;
        }
        else
            rb = mid;
    }
    indexr = lb;
    mergedInterval.push_back(intervals[indexl][0]<l?intervals[indexl][0]:l);
    mergedInterval.push_back(intervals[indexr][1]>r?intervals[indexr][1]:r);
    for(int i=0; i<indexl; ++i){
        res.push_back(intervals[i]);
    }
    res.push_back(mergedInterval);
    for(int i=indexr+1; i<intervals.size(); ++i){
        res.push_back(intervals[i]);
    }
    return res;
}
int main(){
	int n, t, k;
	vector<vector<int>> input;
    vector<int> newInterval;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t>>k;
        input.push_back({t,k});
	}
    cin>>t>>k;
    newInterval.push_back(t);
    newInterval.push_back(k);
    auto res = insert(input, newInterval);
    for(auto item : res){
        cout<<item[0]<<" "<<item[1]<<endl;
    }
	return 0;
}
