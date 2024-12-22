class Solution {
public:
    int findLeftmost( vector<int>& arr, int minHeight, int ind ){
        for( int i = 0; i <= ind; i++){
            if( arr[i] >= minHeight )
                return i;
        }
        return ind;
    }

    int findRightmost( vector<int>& arr, int minHeight, int ind ){
        for( int i = arr.size()-1; i >= ind; i-- ){
            if( arr[i] >= minHeight )
                return i;
        }
        return ind;
    }

    int maxArea(vector<int>& height) {
        int ans = 0;
        for( int i = 0; i < height.size(); i++ ){
            int left = findLeftmost(height, height[i], i);
            int right = findRightmost(height, height[i], i);
            ans = max(ans, height[i] * ( right - left ) );
        }
        return ans;
    }
};