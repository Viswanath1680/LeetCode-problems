struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int childCount;

    TrieNode() {
        isEndOfWord = false;
        childCount = 0;
        for (int i = 0; i < 26; i++)    children[i] = nullptr;
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
            current->childCount++;
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        TrieNode* root = new TrieNode();
        for (const string& word : strs)    insert(root, word);

        string prefix = "";
        TrieNode* current = root;
        // while child count is 1 and it is not end of word.
        while (true) {
            if (current->childCount != 1 || current->isEndOfWord)    break;
            for (int i = 0; i < 26; i++) {
                if (current->children[i]) {
                    prefix += (char)(i + 'a');
                    current = current->children[i];
                    break;
                }
            }
        }
        return prefix; 
    }
};