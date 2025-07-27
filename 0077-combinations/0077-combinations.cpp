/*
Template code:

function backtrack(params){
		if( base_case_condition ){
			result.append(solution)
			return;
		}
		
		for ( choice : choices ) {
			if (violates_constraints)
				continue;

			make_choice;	
			backtrack(updated_params)
			undo_choice;
}
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;

        auto backtrack = [&](auto& self, vector<int>& arr, int start) -> void{
            if( arr.size() == k ){
                answer.push_back(arr);
                return;
            }
            for( start; start <= n; start++ ){
                arr.emplace_back(start);
                self(self, arr, start+1);
                arr.pop_back();
            }
        };

        vector<int> arr;
        backtrack(backtrack, arr, 1);
        return answer;
    }
};