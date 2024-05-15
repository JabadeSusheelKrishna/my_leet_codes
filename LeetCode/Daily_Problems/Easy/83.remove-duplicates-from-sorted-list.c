/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp = head;
    while(temp != NULL && temp -> next != NULL)
    {
        int temp_val = temp -> val;
        if(temp -> next -> val == temp_val)
            temp -> next = temp -> next -> next;
        else
            temp = temp -> next;
    }
    return head;
}
