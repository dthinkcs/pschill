/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   if (head == NULL) 
        return -1;
   Node* slowptr, * fastptr;
   slowptr = fastptr = head;
   for (; fastptr && fastptr->next; slowptr = slowptr->next) {
        fastptr = fastptr->next->next;
   }
   
   return slowptr->data;
}
