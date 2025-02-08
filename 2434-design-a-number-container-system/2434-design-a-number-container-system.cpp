class NumberContainers {
private:
    map<int, int> indexToNumber; // Maps index -> number
    map<int, set<int>> numberToIndices; // Maps number -> set of indices

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // If the index already has a number, remove it from the old number's set
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber); // Remove if no indices remain
            }
        }

        // Updating the mappings
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        // Check if the number exists and has any indices
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin(); // Smallest index
        }
        return -1; // Number not found
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */