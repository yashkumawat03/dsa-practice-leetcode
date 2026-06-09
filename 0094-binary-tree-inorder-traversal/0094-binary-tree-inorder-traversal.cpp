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
    void func(TreeNode* root, vector<int> &temp){
        if(root == NULL)
            return;
        
        func(root->left, temp);
        temp.push_back(root->val);
        func(root->right, temp);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;
        func(root, temp);
        return temp;
    }
};