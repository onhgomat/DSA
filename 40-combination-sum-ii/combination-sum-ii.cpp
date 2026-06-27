class Solution {
public:
    void solve(vector<int>& candidates,int ind,set<vector<int>> &st,vector<int>& v,int target,int n){
        if(target == 0){
            st.insert(v);
            return;
        }

        if(ind == n || target < 0){
            return;
        }

        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i] == candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates,i+1,st,v,target-candidates[i],n);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        set<vector<int>>st;
        vector<int>v;
        int ind = 0;
        int n = candidates.size();

        solve(candidates,ind,st,v,target,n);

        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }

        return ans;
    }
};