class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottles_drunk = 0, empty_bottles = 0;
        while( numBottles || ( numBottles == 0 && empty_bottles >= numExchange ) ){
            bottles_drunk += numBottles;
            empty_bottles += numBottles;
            numBottles = 0;
            if( empty_bottles >= numExchange ){
                empty_bottles -= numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return bottles_drunk;
    }
};