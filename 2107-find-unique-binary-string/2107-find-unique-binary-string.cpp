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
            if( n & 1 ) ans += '1';
            else    ans += '0';
            n = n >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int>arr;
        int len = nums[0].length();
        for( auto it : nums ){
            int temp = convertToInt(it);
            arr.emplace_back(temp);
        }
        sort(arr.begin(),arr.end());
        for( int i = 0; i < arr.size(); i++ ){
            if( arr[i] != i ){
                string temp = convertToString(i);
                while( temp.length() < len )    temp = '0' + temp;
                return temp;
            }
        }
        string temp = convertToString(arr.size());
        while( temp.length() < len )    temp = '0' + temp;
        return temp; 
    }
};