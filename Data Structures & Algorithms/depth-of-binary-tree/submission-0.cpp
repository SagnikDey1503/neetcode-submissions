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
    int maxx= 0;
    void find (TreeNode* root , int score){
        if(!(root->left) && !(root->right)){
            maxx= max(score, maxx);
            return;
        }
        if((root->left)) find( root->left , score+1);
        if((root->right)) find( root->right , score+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
    find(root,1);
    return maxx;
    }
};
