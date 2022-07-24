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
    private:
    ListNode *reverse(ListNode *head){
         ListNode* temp=head->next;
        head->next=NULL;
        while(temp!=NULL){
             ListNode* p=temp->next;
            temp->next=head;
            head=temp;
            temp=p;
        }
        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return head;
         ListNode* temp=head;
         ListNode* dummy1=new  ListNode();
         ListNode* dummy2=new  ListNode(); 
         ListNode* prev=head;  
        bool flag=0; 
        int count=1; 
        bool flag2=0;
        while(head!=NULL)
        {
            if(count==left){
                dummy1=prev; 
                flag=1;
            }
            if(count==right){
                dummy2=head->next;  
                flag2=1;
                head->next=NULL;
            }  
            if(flag && flag2) 
                break;
            count++;
            prev=head;
            head=head->next;
        } 
        if(flag){ 
            ListNode* p;
            if(left!=1){
           p=reverse(dummy1->next); 
          dummy1->next=p;
          while(p->next!=NULL)
            p=p->next;
             p->next=dummy2;
        }
       else{ 
          p=reverse(dummy1);  
           temp=p;
        while(p->next!=NULL){
            // cout<<p->val<< " ";
                p=p->next;  
        }
           if(dummy2!=NULL)
             p->next=dummy2;
       }
        }
        return temp;
    }
};