class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 1; i<strs.size();i++){
            string temp = "";
            int j = 0;
            while(j<ans.size()&&j<strs[i].size()&&ans[j]==strs[i][j]){
                temp +=ans[j];
                j++;
            }
            ans = temp;
            if(ans.empty()) return "";
        }
        return ans;
    }

};