/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head2 = new ListNode(0);
        head2->next = head;
        ListNode* f = head2;
        ListNode* s = head2;

        for(int i=0; i<=n; i++){
            f = f->next;
        }

        while( f != NULL){
            f = f->next;
            s = s->next;
        }
        
        s->next = s->next->next;

        return head2->next;
    }
};