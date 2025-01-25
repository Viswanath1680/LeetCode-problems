class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while( i < n && j < m ){
            if( nums1[i] < nums2[j] ){
                arr.emplace_back(nums1[i]);
                i++;
            }
            else{
                arr.emplace_back(nums2[j]);
                j++;
            }
        }
        while( i < n )  arr.emplace_back(nums1[i++]);
        while( j < m )  arr.emplace_back(nums2[j++]);
        if( (m+n) & 1 ) return (double)arr[ (m+n)/2 ];
        return (double)( arr[(m+n)/2] + arr[(m+n)/2 - 1])/2; 
    }
};