/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    int visit(TreeNode *node)
    {
        return node->val;
    }
    //先序遍历
    void FirstOrderRead(TreeNode* node,vector<int>& first)
    {
        first.push_back(visit(node));
        if (node->left!=NULL)
            FirstOrderRead(node->left,first);
        if (node->right!=NULL)
            FirstOrderRead(node->right,first);
    }
    
    //中序遍历
    void midOrderRead(TreeNode* node,vector<int>& mid)
    {
        if (node->left!=NULL)
            midOrderRead(node->left,mid);
        mid.push_back(visit(node));
        if (node->right!=NULL)
            midOrderRead(node->right,mid);
    }
    
    //后序列遍历
    void LastOrderRead(TreeNode* node,vector<int>& last)
    {
        if (node->left!=NULL)
            midOrderRead(node->left,last);
        if (node->right!=NULL)
            midOrderRead(node->right,last);
        last.push_back(visit(node));
    }
    
    vector<vector<int>> threeOrders(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> first;
        FirstOrderRead(root,first);
        result.push_back(first);
        
        vector<int> mid;
        midOrderRead(root,mid);
        result.push_back(mid);
            
        vector<int> last;
        LastOrderRead(root,last);
        result.push_back(last);
        
        return result;
            
            
            
        // write code here
    }
};