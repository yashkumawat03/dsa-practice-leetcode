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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int anslevel = 1;
        int maxSum = root->val;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                anslevel = level;
            }
            level++;
        }
        return anslevel;
    }
};