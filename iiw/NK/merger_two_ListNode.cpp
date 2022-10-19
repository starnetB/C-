/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode *tmp;
        ListNode *pre2=NULL;
        ListNode *node1=pHead1;
        ListNode *node2=pHead2;
        while(node1!=NULL && node2->next!=NULL)
        {
            if(node1->val<=node2->val)
            {
                tmp=node1;
                node1=node1->next;
                
                if(pre2==NULL){
                    pHead2=tmp;
                    tmp->next=node2;
                    pre2=tmp;
                }else{
                    tmp->next=node2;
                    pre2->next=tmp;
                    pre2=pre2->next;
                }
            }else
            {
                pre2=node2;
                node2=node2->next;
            }
        }
        if(node1!=NULL)
        {
            node2->next=node1;
        }
        return pHead2;
    }
};