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
    TreeNode* find (TreeNode* root, int p, int q ){
      if(!root) return root;
      int val= root->val;
      if(p <= val && q>=val) return root;
      if(p < val && q<val) return find(root->left,p,q);
      if(p > val && q>val) return find( root->right,p,q);

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find( root , min(q->val, p->val),  max(q->val, p->val));
    }
};
