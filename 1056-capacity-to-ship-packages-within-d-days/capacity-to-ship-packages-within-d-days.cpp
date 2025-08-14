class Solution {
public:
    int shipWithinDays(vector<int>& arr, int k) {
         int n=arr.size();
        int l=0,h=0;
        for(int i=0;i<n;i++){
            l=max(l,arr[i]);
            h+=arr[i];
        }
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int c=1,t=0;
            for(int i=0;i<n;i++){
                t+=arr[i];
                if(t>mid){
                    c++;
                    t=arr[i];
                }
            }
            if(c<=k){
               ans=mid;
               h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};