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
    void inorder(TreeNode* root, vector<TreeNode*> & temp){
        if(root == nullptr)
            return;
        inorder(root->left, temp);
        temp.push_back(root);
        inorder(root->right, temp);
    }
    TreeNode* BinarySearch(vector<TreeNode*> &arr, int low, int high){
        if(high  < low){
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        arr[mid]->left = BinarySearch(arr, low, mid-1);
        arr[mid]->right = BinarySearch(arr, mid+1, high);
        return arr[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> temp;
        inorder(root, temp);
        return BinarySearch(temp,0,temp.size()-1);
    }
};