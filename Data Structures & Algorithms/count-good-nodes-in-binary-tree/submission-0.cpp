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
    int counter=0;
    void find ( TreeNode* root , int currMax){
        if(!root) return;
        if(root->val >= currMax){
            counter++; currMax=root->val;
        }
          find (root-> left , currMax);
        find (root->right , currMax);
    }
public:
    
    int goodNodes(TreeNode* root) {
       int currMax= root->val;
        find (root , currMax);
        return counter;
    }
};
