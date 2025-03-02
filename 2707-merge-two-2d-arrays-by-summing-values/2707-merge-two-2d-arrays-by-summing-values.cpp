class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int i = 0, j = 0, N1 = nums1.size(), N2 = nums2.size();
        while( i < N1 && j < N2 ){
            int id1 = nums1[i][0], id2 = nums2[j][0];
            int val1 = nums1[i][1], val2 = nums2[j][1];
            int id, sum;
            if( id1 == id2 ){
                id = id1, sum = val1 + val2;
                i++, j++;
            }
            else{
                if( id1 < id2 ){
                    id = id1, sum = val1;
                    i++;
                }
                else{
                    id = id2, sum = val2;
                    j++;
                }
            }
            ans.push_back({id, sum});
        }
        while( i < N1 )    ans.push_back({ nums1[i][0], nums1[i++][1]});
        while( j < N2 )    ans.push_back({nums2[j][0], nums2[j++][1]});
        return ans;
    }
};