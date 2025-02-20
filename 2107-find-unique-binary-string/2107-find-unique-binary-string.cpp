class Solution {
public:
    int convertToInt(string s){
        reverse(s.begin(), s.end());
        int ans = 0;
        for( int i = 0; i < s.length(); i++ ){
            if( s[i] == '1' )   ans += 1 << i;
        }
        return ans;
    }

    string convertToString(int n){
        string ans;
        while( n ){
            if( n & 1 ) ans = '1' + ans;
            else    ans = '0' + ans;
            n = n >> 1;
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums[0].length();
        int count = 0;
        for( auto it : nums ){
            int temp = convertToInt(it);
            if( temp != count ){
                string ans = convertToString(count);
                while( ans.length() < len ) ans = '0' + ans;
                return ans;
            }
            count++;
        }

        string ans = convertToString(count);
        while( ans.length() < len ) ans = '0' + ans;
        return ans;
    }
};