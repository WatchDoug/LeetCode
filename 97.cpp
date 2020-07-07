class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> t(s2.size()+1, 0);
        vector<vector<int>> res(s1.size()+1, t);
        if(s3.size() != s1.size()+s2.size())
            return false;
        
        for(int i = 1; i<=s1.size() && s1[i-1] == s3[i-1];++i){
            res[i][0] = res[i-1][0]+1;
        }
        for(int j = 1; j<=s2.size() && s2[j-1] == s3[j-1];++j){
            res[0][j] = res[0][j-1]+1;
        }
        for(int i = 1; i<=s1.size(); ++i){
            for(int j = 1; j<=s2.size(); ++j){
                res[i][j] = res[i-1][j]>res[i][j-1]?res[i-1][j]:res[i][j-1];
                if(s3[i+j-1] == s1[i-1])
                    res[i][j] = res[i][j]>res[i-1][j]+1?res[i][j]:res[i-1][j]+1;
                if(s3[i+j-1] == s2[j-1])
                    res[i][j] = res[i][j]>res[i][j-1]+1?res[i][j]:res[i][j-1]+1;
            }
        }
        return (res[s1.size()][s2.size()] == s3.size());
    }
};