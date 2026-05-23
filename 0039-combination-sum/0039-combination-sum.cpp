class Solution {
public:
    void combination(vector<int> &candidates, int target, int i, vector<int> &temp){
        // base case
        if(i == candidates.size()){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        // recursive case
        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            combination(candidates, target-candidates[i],i,temp);
            temp.pop_back();
        }
            combination(candidates, target,i+1,temp);
    }
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        combination(candidates, target, 0,temp);
        return ans;
    }
};