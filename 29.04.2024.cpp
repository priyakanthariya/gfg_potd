class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
      Node *curr = head, *prv = NULL;
      int index = 1;
      if(K==1)
      {
      delete head;
      return NULL;
      }
      while(curr!=NULL)
      {
        if(index%K==0)
        {
          Node* temp = curr;
          curr = curr->next;
          prv->next=curr;
          temp->next=NULL;
          delete temp;
        }
        else
        {
          prv = curr;
          curr = curr->next;
        }
       index++;
      }
    return head;
    }
};