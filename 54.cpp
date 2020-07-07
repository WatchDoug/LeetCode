class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        vector<int> res;
        res.clear();
        if(row == 0)
            return res;
        int line = matrix[0].size();
        if(line == 0)
            return res;
        int x = 0, y = 0;
        while(row > 0 && line > 0){
            for(int j = 0;j<line;++j){
                res.push_back(matrix[x][y+j]);
            }
            if(row == 1)
                break;
            for(int i = 1; i<row;++i){
                res.push_back(matrix[x+i][y+line-1]);
            }
            if(line == 1)
                break;
            for(int j = line-2; j>=0; --j){
                res.push_back(matrix[x+row-1][y+j]);
            }
            for(int i = row-2; i>0; --i){
                res.push_back(matrix[x+i][y]);
            }
            row-=2;
            line-=2;
            ++x;++y;
        }
        return res;
    }
};