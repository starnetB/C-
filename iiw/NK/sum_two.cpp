class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    struct TreeNode
    {
        enum nodeType {Left,Right};
        int val;
        int index;
        nodeType type;
        TreeNode *left;
        TreeNode *right;
        TreeNode *Parent;
    };
    
    TreeNode *root;
    
    //查找叶子节点
    TreeNode *FindInsertPoint(TreeNode *node,int target)
    {
        TreeNode *result;
        if((target<=node->val)&&(node->left!=NULL))
        {
            result=FindInsertPoint(node->left, target);
        }
        if((target<=node->val)&&(node->left==NULL))
        {
            result=node;
        }
        if(target>node->val&&node->right!=NULL)
        {
            result=FindInsertPoint(node->right, target);
        }
        if(target>node->val&&node->right==NULL)
        {
            result=node;
        }
        return result;
    }
    
    
    bool FindTarget(TreeNode& result,TreeNode* node,int target)
    {
        if((target<node->val) && (node->left!=NULL))
        {
            FindTarget(result,node->left,target);
        }
        if((target<node->val) && (node->left==NULL))
        {
            return false;
        }
        if((target>node->val) && (node->right!=NULL))
        {
            FindTarget(result,node->right, target);
        }
        if((target>node->val) && (node->right==NULL))
        {
            return false;
        }
        if(target==node->val)
        {
            result=*node;
        }
        return true;
    }
    
    
    void MakeTree(vector<int>& numbers)
    {   
        TreeNode *last;
        
        for(int i=0;i<numbers.size();i++)
        {
            //1 左左
            //2 左右
            //3 右右
            //4 右左
            int TreeState=0;
            TreeNode *node=new TreeNode; 
            if (i==0){
                root=node;
                last=node;
                node->val=numbers[i];
                node->index=i;
                node->type=TreeNode::Left;
                node->left=NULL;
                node->right=NULL;
            }else{
                last=FindInsertPoint(root, numbers[i]);
                if(numbers[i]>last->val)
                {
                    node->val=numbers[i];
                    node->left=NULL;
                    node->right=NULL;
                    node->Parent=last;
                    last->right=node;
                    node->type=TreeNode::Right;
                    node->index=i;
                    //判断，是否需要调整
                    if((node->Parent!=NULL) && (node->Parent->Parent!=NULL) &&(node->Parent->Parent->Parent!=NULL))
                    {   
                        if((node->Parent->type==TreeNode::Right) 
                            && (node->Parent->left==NULL)
                            && (node->Parent->Parent->left==NULL))
                           TreeState=3;
                        else if((node->Parent->type==TreeNode::Left)
                            && (node->Parent->left==NULL)
                            && (node->Parent->Parent->right==NULL))
                        {
                            TreeState=2;
                        }else{
                            TreeState=0;
                        }
                    }
                }
                if(numbers[i]<=last->val)
                {
                    node->val=numbers[i];
                    node->left=NULL;
                    node->right=NULL;
                    node->Parent=last;
                    last->left=node;
                    node->type=TreeNode::Left;
                    node->index=i;
                    //判断是否需要调整
                    if((node->Parent!=NULL) && (node->Parent->Parent!=NULL) &&(node->Parent->Parent->Parent!=NULL))
                    { 
                        if((node->Parent->type==TreeNode::Left) 
                            && (node->Parent->right==NULL)
                            && (node->Parent->Parent->right==NULL))
                           TreeState=1;
                        else if((node->Parent->type==TreeNode::Right)
                            && (node->Parent->right==NULL)
                            && (node->Parent->Parent->left==NULL))
                        {
                            TreeState=4;
                        }else{
                            TreeState=0;
                        }
                    }
                }
            }
            if(TreeState==0)
                continue;
            if(TreeState==1){   //左左处理   //Parent 左旋
                node->Parent->Parent->Parent->left=node->Parent;
                node->Parent->Parent->left=NULL;
                node->Parent->right=node->Parent->Parent;
                
                node->Parent->Parent=node->Parent->right->Parent;
                node->Parent->right->Parent=node->Parent;
            }
            if(TreeState==2){  //左右处理 //当前右旋，Parent左旋
                node->Parent->Parent->left=node;
                node->Parent->right=NULL;
                node->left=node->Parent;
                node->Parent=node->left->Parent;
                node->left->Parent=node;
                node=node->left;
                
                node->Parent->Parent->Parent->left=node->Parent;
                node->Parent->Parent->left=NULL;
                node->Parent->right=node->Parent->Parent;
                node->Parent->Parent=node->Parent->right->Parent;
                node->Parent->right->Parent=node->Parent;
            }
            if(TreeState==3)
            {
                node->Parent->Parent->Parent->right=node->Parent;
                node->Parent->Parent->right=NULL;
                node->Parent->left=node->Parent->Parent;
                node->Parent->Parent=node->Parent->left->Parent;
                node->Parent->left->Parent=node->Parent;
            }
            if(TreeState==4)
            {
                node->Parent->Parent->right=node;
                node->Parent->left=NULL;
                node->right=node->Parent;
                node->Parent=node->right->Parent;
                node->right->Parent=node;
                node=node->right;
                
                node->Parent->Parent->Parent->right=node->Parent;
                node->Parent->Parent->right=NULL;
                node->Parent->left=node->Parent->Parent;
                node->Parent->Parent=node->Parent->left->Parent;
                node->Parent->left->Parent=node->Parent;        
            }
        }
    }
    
    TreeNode* FindMin(TreeNode *node)
    {
        TreeNode *result;
        if(node->left==NULL)
        {
            result=node;
        }
        else{
            result=FindMin(node->left);
        }
        return result;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        MakeTree(numbers);
//         TreeNode result;
//         FindTarget(result,root,4);
//         std::cout<<result.index<<std::endl;
        std::vector<int> result2;
        for(int i=0;i<numbers.size();i++)
        {
            result2.clear();
            TreeNode result;
            int second=target-numbers[i];
            if(second==numbers[i])
            {
                continue;
            }
            bool resultval=FindTarget(result,root,second);
            if (!resultval)
            {
                continue;
            }
            else
            {
                result2.push_back(i+1);
                result2.push_back(result.index+1);
                break;
            }
        }
        return result2;
    }
};