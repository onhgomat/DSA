class Solution {
    const int MOD = (int)1e9+7;
public:
    vector<int>findNSE(vector<int>&arr) {
        int n = arr.size();
        vector<int>ans(n, n);
        stack<int>st;

        for(int i=n-1; i>= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = n;
            st.push(i);
        }
        return ans;
    }

    vector<int>findPSE(vector<int>&arr) {
        int n = arr.size();
        vector<int>ans(n, -1);
        stack<int>st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) { 
                                //remove only smaller or equal
                st.pop();
            }

            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(i);
        }
        return ans;
    }


    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right * (long long)arr[i]));
        }
        return total;
    }

    vector<int>findnge(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,n);

        for(int i = n-1; i>= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>findpge(vector<int>&arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,-1);

        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMax(vector<int>&arr) {
        int n = arr.size();
        vector<int> nge = findnge(arr);
        vector<int> pge = findpge(arr);

        long long total=0;

        for(int i = 0; i<n; i++) {
            long long left = i-pge[i];
            long long right = nge[i]-i;

            total =(total + (left * right *(long long)arr[i]));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};