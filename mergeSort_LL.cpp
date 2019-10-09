Node* findPtrBeforeMidpoint(Node* head) {
    if (head == NULL) 
        return NULL;

    Node* fastptr, * slowptr;
    slowptr = head;
    fastptr = head->next;
    while (fastptr && fastptr->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    return slowptr;
}

Node* merge(Node* head1, Node* head2) {
    Node* newHead = NULL; Node* ptrTail = NULL;
    Node* i1 = head1; Node* i2 = head2;
    while (i1 && i2) {
        if (i1->data < i2->data) {
            
            if (newHead == NULL) {
                newHead = new Node(i1->data);
                ptrTail = newHead;
            }
            else {
                ptrTail->next = new Node(i1->data);
                ptrTail = ptrTail->next;   
            }
            i1 = i1->next;
        } 
        else {
            
            if (newHead == NULL) {
                newHead = new Node(i2->data);
                ptrTail = newHead;
            }
            else {
                ptrTail->next = new Node(i2->data);
                ptrTail = ptrTail->next;   
            }
            i2 = i2->next;

        }
    }
    
    while (i1) {
        
        if (newHead == NULL) {
            newHead = new Node(i1->data);
            ptrTail = newHead;
        }
        else {
            ptrTail->next = new Node(i1->data);
            ptrTail = ptrTail->next;   
        }
        i1 = i1->next;

    }
    
    while (i2) {
        
        if (newHead == NULL) {
            newHead = new Node(i2->data);
            ptrTail = newHead;
        }
        else {
            ptrTail->next = new Node(i2->data);
            ptrTail = ptrTail->next;   
        }
        i2 = i2->next;

        
    }
    
    return newHead;
}

Node* mergeSort(Node* head) {
    // your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        Node* ptrBeforeMid = findPtrBeforeMidpoint(head);
        Node* head1 = head;
        Node* head2 = ptrBeforeMid->next;
        ptrBeforeMid->next = NULL; // detach
        
        head1 = mergeSort(head1); // sort left mutate head1
        head2 = mergeSort(head2); // sort right mutate head2
        return merge(head1, head2); // merge the two
        
    }
}
