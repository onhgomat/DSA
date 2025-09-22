class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = 0 , mini = INT_MAX; 
        for(int i : nums){
            maxi = max(maxi , i ); 
            mini = min(mini , i); 
        }
        return static_cast<long long>(maxi - mini) * k ; 
    }
};