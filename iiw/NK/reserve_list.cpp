/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
    static int count;
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode *node=head;
        ListNode *prepre=NULL;
        ListNode *tmp=NULL;
        
        ListNode *pre=head;
        ListNode *gopre=head;
        ListNode *golast=head->next;

        
        while(node->next!=NULL)
        {
            node=node->next;
            count++;
            if(count%k==0)
            {
                while(golast!=node)
                {
                    tmp=golast->next;
                    golast->next=gopre;
                    gopre=golast;
                    golast=tmp;
                }
                
                pre->next=node;
                if(prepre==NULL)
                {
                    head=gopre;
                }
                if(prepre!=NULL)
                {
                    prepre->next=gopre;
                }
                prepre=pre;
                pre=pre->next;
                gopre=pre;
                golast=golast->next;
            }
        }
        return head;
        
    }
};

int Solution::count=0;