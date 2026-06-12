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
 int preIdx=1;
 TreeNode* bt ( vector<int>& preorder, vector<int>& inorder, int i , int j ){
    if( i>j ) return NULL;
      int val= preorder[preIdx++];
       TreeNode* child = new TreeNode(val);
       int c;

       for(c =i;c<=j;c++){
      if(inorder[c]==val) break;
       }
     child->left=bt(preorder,inorder,i,c-1);
     child->right=bt(preorder,inorder,c+1,j);
     return child;
 }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n =inorder.size();
       int val= preorder[0];
       TreeNode* root = new TreeNode(val);
       int i;
       for( i=0;i<n;i++){
        if (inorder[i]==val) break;
       }
       root->left=bt(preorder,inorder,0,i-1);
     root->right=bt(preorder,inorder,i+1,n-1);
     return root;
    }
};
