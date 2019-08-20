class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_bit=0;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while(l1 && l2){
            int val=l1->val+l2->val+carry_bit;
            cur->next = new ListNode(val%10);
            carry_bit = val/10;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        for(auto node:vector<ListNode *>({l1, l2})){
            while(node){
                int val = node->val+carry_bit;
                cur->next = new ListNode(val%10);
                carry_bit = val/10;
                cur = cur->next;
                node = node->next;
            }
        }
        if(carry_bit)
            cur->next = new ListNode(1);

        return res->next;
    }
};