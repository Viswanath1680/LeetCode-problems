class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        sort(nums.begin(),nums.end());
        for( int i = 0 ; i < n ; i++)   mp[ nums[i] ].push_back(i);
        vector<vector<int>> ans;
        set<vector<int>> s;
        for( int i = 0 ; i < n-2;){
            // vector<vector<int>>temp;
            for( int j = i + 1; j < n-1;){
                int target = -1 * ( nums[i] + nums[j] );
                if( mp.find(target) != mp.end() ){
                    vector<int> arr = mp[target];
                    int p;
                    p = upper_bound( arr.begin(), arr.end(), j ) - arr.begin();
                    while( p < arr.size() ){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[arr[p]]);
                        s.insert(temp);
                        p++;
                    }
                }
                int k = j;
                while( k < n-1 && nums[j] == nums[k] )   k++;
                j = k;
            }
            int k = i;
            while( k < n-2 && nums[k] == nums[i])     k++;
            i = k;
        }
        for( auto it : s )  ans.push_back(it);
        return ans;
    }
};