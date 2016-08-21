
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> buf;
        int n = matrix.size();
        int idxn = n-1;
        for(int x=0; x<n/2; x++){
            int low=x, high=idxn-x;
            for(int y=low; y<high; y++){
                int c = matrix[x][y];
                matrix[x][y] = matrix[idxn-y][x];
                matrix[idxn-y][x] = matrix[idxn-x][idxn-y];
                matrix[idxn-x][idxn-y] = matrix[y][idxn-x];
                matrix[y][idxn-x] = c;
            }
        }
    }
};