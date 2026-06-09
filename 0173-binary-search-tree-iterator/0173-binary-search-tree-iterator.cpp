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
class BSTIterator {
    stack<TreeNode*> stk;
    void addLeft(TreeNode* root){
        TreeNode *ptr = root;
        while(ptr){
            stk.push(ptr);
            ptr = ptr->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        addLeft(root);
    }
    
    int next() {
        TreeNode* curr = stk.top();
        stk.pop();
        if(curr->right){
            addLeft(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return stk.empty() == false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */