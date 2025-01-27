class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int mini = min(red, blue ), maxi = max( red, blue );
        int minicopy = mini, maxcopy = maxi;
        bool flag = false;
        int row = 1, ans = 0;
        while( maxi >= 0 && mini >= 0  ){
            if( flag == false ){
                if( maxi >= row )   maxi -= row, ans++;
                else    break;
            }
            else{
                if( mini >= row )    mini -= row, ans++;
                else    break;
            }
            flag = ! flag;
            row++;
        }
        row = 1;
        int ans2 = 0;
        flag = true;
        mini = minicopy, maxi = maxcopy;
        while( maxi >= 0 && mini >= 0  ){
            if( flag == false ){
                if( maxi >= row )   maxi -= row, ans2++;
                else    break;
            }
            else{
                if( mini >= row )    mini -= row, ans2++;
                else    break;
            }
            flag = ! flag;
            row++;
        }
        return max( ans, ans2 );
    }
};