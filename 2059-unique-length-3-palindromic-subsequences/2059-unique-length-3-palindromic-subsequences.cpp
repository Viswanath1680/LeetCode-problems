class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first_occurence(26, -1), last_occurence(26, -1);
        for(int i = 0; i < n; i++) {
            int char_idx = s[i] - 'a';
            if(first_occurence[char_idx] == -1)     first_occurence[char_idx] = i;
            last_occurence[char_idx] = i;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(first_occurence[i] == -1 || last_occurence[i] <= first_occurence[i] + 1) continue;
            
            unordered_set<char> middle_chars;
            for(int j = first_occurence[i] + 1; j < last_occurence[i]; j++)    middle_chars.insert(s[j]);
            
            ans += middle_chars.size();
        }
        
        return ans;
    }
};