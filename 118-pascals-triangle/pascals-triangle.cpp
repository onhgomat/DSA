class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            vector<int> ansRow;
            long long ans = 1;
            ansRow.push_back(1);

            for (int col = 1; col <= row; col++) {
                ans = ans * (row - col+1 ) / col;
                ansRow.push_back(ans);
            }

            triangle.push_back(ansRow);
        }

        return triangle;
    }
};