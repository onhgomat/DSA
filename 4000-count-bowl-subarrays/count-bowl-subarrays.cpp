class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {  // <-- name must match exactly
        int n = nums.size();

        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Step 1: Nearest greater to left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        // Step 2: Nearest greater to right
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        // Step 3: Count valid bowls
        long long count = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] != -1 && right[i] != n) {
                count++;
            }
        }
        return count;
    }
};
