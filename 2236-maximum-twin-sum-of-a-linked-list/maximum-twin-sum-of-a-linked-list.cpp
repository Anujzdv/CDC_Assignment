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
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != nullptr && fast -> next  != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* sHalf = rev(slow -> next);
        ListNode* f = head;
        ListNode* s = sHalf;
        int ans = 0;
        while(s != nullptr){
           int sum = s -> val + f -> val;
           ans = max(ans, sum);
           s = s-> next;
           f = f -> next; 
        }
        return ans;
    }
};