class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0;
        int rows = matrix.size();
        int col = matrix[0].size();
        int right = rows* col - 1; 
       
        while(left<=right){
            int mid = left + (right-left)/2;
            int r1 = mid/col;
            int r2= mid%col;
            if(matrix[r1][r2] == target) return true;
            else if(matrix[r1][r2]<target){
                left = mid+1;
            }
            else if(matrix[r1][r2]>target){
                right = mid-1;
            }
        }
        return false;
    }
};
