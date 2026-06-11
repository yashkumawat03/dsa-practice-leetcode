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
    void RightView(TreeNode* Node, int level, vector<int> &ans){
        if(Node == NULL)
            return;
        if(ans.size() == level)
            ans.push_back(Node->val);
        RightView(Node->right, level + 1, ans);
        RightView(Node->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // Using recursion
        RightView(root, 0, ans);
        return ans;
    }
};