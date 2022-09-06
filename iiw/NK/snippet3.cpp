/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

//返回数的最大深度
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};