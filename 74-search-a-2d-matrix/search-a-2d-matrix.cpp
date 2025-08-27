class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0 , h = m * n - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            int el = matrix[mid / n][mid % n];

            if (el == target) return true;
            else if (el > target) h = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
