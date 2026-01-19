class Solution {
  public:
    Node* rev(Node* head) 
    {
        Node* prev=NULL;
        Node* curr=head;
        while (curr!=NULL) 
        {
            Node*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head=rev(head);
        Node*temp=head;
        int carry=1;
        while(temp!=NULL && carry==1) 
        {
            int val=temp->data + carry;
            if (val>=10) 
            {
                temp->data=0;
                carry=1;
            }
            else 
            {
                temp->data=val;
                carry=0;
            }
            if (temp->next==NULL && carry==1) 
            {
                temp->next=new Node(1);
                carry=0;
            }
            temp=temp->next;
        }
        return rev(head);
        // return head of list after adding one
    }
};