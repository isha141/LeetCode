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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *root=head;
        int pos=1;
        // string temp="";
        while(pos<left) {
            head=head->next;
            pos++;
        }
        vector<int>temp;
        while(pos<=right && head!=NULL){
            temp.push_back(head->val);
            head=head->next;
            pos++;
        }
        reverse(temp.begin(),temp.end());
        int k=0;
        pos=1;
        head=root;
        while(pos<left){
            head=head->next;
            pos++;
        }
        while(pos<=right){
            head->val=temp[k];
            pos++;
            head=head->next;
            k++;
        }
        return root;
    }
};