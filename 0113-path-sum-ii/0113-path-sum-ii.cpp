/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>> & ans){
        if(root == NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
            ans.push_back(temp);
            return;
        }
        help(root->left, targetSum - root->val, temp, ans);
        help(root->right, targetSum - root->val, temp, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(root, targetSum, temp, ans);
        return ans;
    }
};