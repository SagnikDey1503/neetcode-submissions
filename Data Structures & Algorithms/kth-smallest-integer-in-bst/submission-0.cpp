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
     int reqd=0;
public:
void inorder ( TreeNode* root , int k , int & n){
            if(!root) return; 
            inorder(root->left,k,n);
              n++;
              if(n==k){
                reqd= root->val;
                return;
              }
              inorder(root->right,k,n);
 }
    int kthSmallest(TreeNode* root, int k) {
        // do an inorder traversal 
        int n=0;
        inorder( root, k ,n );
        return reqd;
    }
};
