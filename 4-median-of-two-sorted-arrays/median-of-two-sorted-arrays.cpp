class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int mid = (n+m)/2;
        double median;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(),nums1.end());
        if((n+m)%2 ==0 ){
           median=(nums1[mid-1]+nums1[mid])/2.0;
        
        }
        else{
            median = nums1[mid];
        }
        return median;
    }
};