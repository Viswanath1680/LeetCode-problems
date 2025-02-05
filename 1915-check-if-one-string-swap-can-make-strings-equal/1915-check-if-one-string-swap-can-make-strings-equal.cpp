class Solution {
public:
    bool sameStrings(string s1, string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1 == s2;
    }

    bool areAlmostEqual(string s1, string s2) {
        if( s1 == s2 )  return true;
        if( sameStrings(s1, s2) == false )  return false;
        int diff = 0;
        for( int i = 0; i < s1.length(); i++ ){
            if( s1[i] != s2[i] )    diff++;
            if( diff > 2 )  break;
        }
        if( diff == 2 ) return true;
        return false; 
    }
};