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
    void find (TreeNode* root, TreeNode* node){
     
       if(root->val > node->val){ 
        if(root->left)
        find(root->left, node);
        else
        root->left=node;
       }
       else
       { 
        if(root->right)
        find(root->right, node);
        else
        root->right=node;
       }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* node = new TreeNode(val);
          if(!root) {
        return node;
       }
        find(root,node);
        return root;
    }
};