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
    ListNode* middleNode(ListNode* head) {
        int counter = 0;
        ListNode*current = head;
        ListNode*tracker = current;
        while (current!= nullptr){
            counter++;
            current = current -> next;
        }
        int middle = counter/2;
        for (int i=0; i<middle; i++){
            tracker = tracker->next;
            
        }
        return tracker;
        }

        };




        
    
