/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//反转连表
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *Forward=NULL;
        ListNode *First=pHead;
        ListNode *Second=pHead->next;
        
        while(Second->next!=NULL)
        {
            if(Forward==NULL)
                First->next=NULL;
            Forward=First;
            First=Second;
            Second=Second->next;
            First->next=Forward;
        }
        Second->next=First;
        return Second;
    }
};