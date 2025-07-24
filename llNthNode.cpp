// C program to find n'th
// node in linked list (iteratively)

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

Node *createNewNode(int new_data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == nullptr)
        return nullptr;

    new_node->data = new_data;
    new_node->next = nullptr;

    return new_node;
}

void printLL(Node *head)
{
    while(head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the nth node in the list
int GetNth(Node *head, int index)
{
    Node *curr = head;
    int count = 1;
    while (curr != NULL) 
    {
        if (count == index)
            return curr->data;
        count++;
        curr = curr->next;
    }

    return -1;
}

// Given only a pointer/reference to a node to be deleted in a singly linked list
void deleteNode(struct Node* delNode)
{
    // delNode should not be the last node
    if (delNode  == nullptr || delNode ->next == nullptr) {
        return;  
    }

    Node *temp = delNode->next;
    
    delNode->data = delNode->next->data;
    delNode->next = delNode->next->next;
    
    free(temp);
}

//Find Middle of the Linked List
int middleNodeLL(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

//Nth node from the end of a Linked List
Node* nthNodeFromEndLL(Node *head, int n)
{
    Node *main = head;
    Node *ref = head;  
    int count = 1;

    while(count < n)
    {
        ref = ref->next;
        count++;

        if (ref == NULL)   // N > length of LL
            return NULL; 
    }

    while (ref->next != NULL)
    {
        ref = ref->next;
        main = main->next;
    }

    return main;
}

// reverse the LL
void reverse(Node **head)
{
    Node *curr = *head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

// reverse the LL in in group of K nodes
void reverseKgroupLL(Node **head, int num)
{
    stack<Node *> st;

    Node *curr = *head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL)
    {
        count = 0;
        while (curr != NULL && count < num)
        {
            st.push(curr);
            curr = curr->next;
            count++;
        }    

        while(st.empty() == false)
        {
            Node *temp = st.top();
            st.pop();

            if (prev == NULL)
            {
                prev = temp;
                *head = prev;
            }
            else
            {
                prev->next = temp;
                prev = prev->next;
            }
        }
    }
    prev->next = NULL;
}

void reverseKgroupItrativelyLL(Node **head, int num)
{
    Node *curr = *head;
    Node *newHead = NULL;
    Node *tail = NULL;


    while(curr != NULL)
    {
        Node *ghead = curr;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;
        
        while (curr != NULL && count < num)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (newHead == NULL)
        {
            newHead = prev;
        }

        if (tail != NULL)
        {
            tail->next = prev;
        }
        tail = ghead;
    }

    *head = newHead;
}

void printRecursivly(Node *head)
{
    if (head == NULL)
        return;

    printRecursivly(head->next);

    printf("%d->", head->data);
}

//Remove Duplicates from an Unsorted Linked List
void removeDuplicates(Node *head)
{
    Node *temp = head;
    Node *curr = NULL;

    if (head == NULL)
    {
        printf("Empty list, returning");
        return;
    }

    while(temp)
    {
        curr = temp;

        while(curr)
        {
            Node *nextNode = curr->next;
            
            if(nextNode && temp->data == nextNode->data)
            {
                curr->next = nextNode->next;
                free(nextNode);
            }
            else
            {
                curr = curr->next;
            }
        }

        temp = temp->next;
    }
}

//Remove Duplicates from an Unsorted Linked List
void removeDuplicatesOptimization(Node *head)
{
    // your code goes here
    set<int> s;
    vector<int> v;
    Node *temp = head; 
    Node *prev = nullptr;
    
    while(temp)
    {
        int data = temp->data;
        
        if (s.find(data) == s.end())
        {
            s.insert(data);
            
            if (prev == nullptr)
            {
                prev = temp;
            }
            else
            {
                prev = prev->next;
            }
                
            temp = temp->next;
        }
        else
        {
            Node *t = temp;
            
            prev->next = temp->next;
            temp = temp->next;
            free(t);
        }
    }
}

// Function to remove duplicates from sorted linked list.
Node* removeDuplicatesFromSortedLL(Node* head) 
{
    Node *curr = head;

    while(curr)
    {
        Node *nextNode = curr->next;
            
        if(curr->next != nullptr && curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
    
    return head;
}

// Function to check whether the list is palindrome.
bool isPalindrome(Node *head) 
{
    // Your code here
    stack<int> stk;
    Node *curr = head;
    
    while(curr)
    {
        stk.push(curr->data);
        curr = curr->next;
    }
    
    curr = head;
    
    while(curr && stk.empty() == false)
    {
        int stData = stk.top();
        stk.pop();
        
        if(curr->data != stData)
        {
            return false;
        }
        
        curr = curr->next;
    }
    
    return true;
}

//Given the head of two singly linked lists, return the point where these two linked lists intersect.
Node* intersectPoint(Node* head1, Node* head2) 
{
    //  Code Here
    set <Node *> s;
    Node *temp = head1;
    
    while(temp)
    {
        s.insert(temp);
        
        temp = temp->next;
    }
    
    temp = head2;
    
    while (temp)
    {
        if (s.find(temp) != s.end())
        {
            return temp;
        }
        
        temp = temp->next;
    }
    
    return nullptr;
}

// Function to find the length of a loop in the linked list.
int countNodesinLoop(Node *head) 
{
    // Code here
    Node *slow = head, *fast = head;
    bool isLoop = false;
    int cnt = 0;
    
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        {
            isLoop = true;
            break;
        }
    }
    
    if (isLoop == true)
    {
        slow = slow->next;
        cnt++;
        
        while(slow != fast)
        {
            slow = slow->next;
            cnt++;
        }
        
    }
    
    return cnt;
    
}

// Sort a linked list of 0s, 1s and 2s
Node* segregate(Node* head) 
{
    // code here
    multimap<int, Node *> m;
    Node *temp = head;
    
    while(temp)
    {
        m.insert(pair<int, Node*>(temp->data, temp));
        temp = temp->next;
    }
    
    int i = 1;
    for (auto &e : m)
    {
        if (i == 1)
        {
            head = e.second;
            temp = head;
        }
        else
        {
            temp->next = e.second;
            temp = temp->next;
        }
        i++;
    }
    temp->next = nullptr;
    
    return head;
}

/* Function to delete a node from a linked list */
Node* deleteNode(Node* head, int x) 
{
    // code here
    Node *temp = head, *t = nullptr;
    Node *prev = nullptr;
    int count = 1; 
    
    while(temp)
    {
        if (count == x)
        {
            if (head == temp)
            {
                t = temp->next;
                head = t;
                free(temp);
                return head;
            }
            else
            {
                t = prev->next;
                prev->next = temp->next;
                temp = temp->next;
                free(t);
                return head;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
    
    return head;
}

Node* addTwoLists(Node* num1, Node* num2) 
{
    // code here
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    int c = 0;
    int i = 0, n3 = 0; 
    
    Node *n = num1;
    Node *temp = nullptr, *start = nullptr;
    
    while(n != nullptr)
    {
        s1.push(n->data);
        n = n->next;
    }
    
    n = num2;
    while(n != nullptr)
    {
        s2.push(n->data);
        n = n->next;
    }
    
    int s1S = s1.size();
    int s2S = s2.size();
    
    for (i = 0; (i < s1S || i < s2S); i++)
    {
        int n1 = 0, n2 = 0, n3 = 0;
        
        if (i < s1S)
        {
            n1 = s1.top();
            s1.pop();
        }

        if (i < s2S)
        {
            n2 = s2.top();
            s2.pop();
        }
        
        n3 = n1 + n2 + c;
        if (n3 > 9)
        {
            c = 1;
            n3 = n3%10;
        }
        else
        {
            c = 0;
        }

        s3.push(n3);
    }
    
    if (c == 1)
        s3.push(c);

    for (i = 0; false == s3.empty();i++)
    {
        n3 = s3.top();
        s3.pop();

        Node *node = createNewNode(n3);

        if (i == 0)
        {
            start = node;
            temp = start;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }
    
    return start;
}

//Delete nodes having greater value on right
Node *compute(Node *head) 
{
    // your code goes here
    Node *t = head;
    Node *prev = nullptr;
    bool noDeletion = false;
    
    while(t->next)
    {
        Node *temp = nullptr;
        
        if (t->data < t->next->data)
        {
            if (t == head)
            {
                temp = t;
                head = head->next;
                delete temp;
                t = head;
                noDeletion = true;
            }
            else
            {
                temp = t;
                prev->next = temp->next;
                delete temp;
                t = prev->next;
                noDeletion = true;
            }
        }
        else
        {
            prev = t;
            t = t->next;
        }
    }
    
    if (noDeletion == true)
        compute(head);
    else
        return head;
}

Node* deleteMid(Node* head) 
{
    // Your Code Here
    Node *f = head, *s = head, *p = nullptr;
    Node *t;
    
    if (head->next == nullptr)
        return nullptr;
        
    while(f != nullptr && f->next != nullptr)
    {
        p = s;
        s = s->next;
        f = f->next->next;
    }
    
    
    if (f != nullptr && f->next == nullptr) // odd number of nodes
    {
       p->next = s->next;
       delete s;
    }
    else if (f == nullptr)   // even number of nodes
    {
        p->next = s->next;
        delete s;
    }
    
    return head;
}

// Should return head of the modified linked list
Node* sortedInsert(Node* head, int key) 
{
    // Code here
    Node *t = head;
    Node *n = createNewNode(key);
    
    while(t)
    {
        if (t == head && key <= t->data)
        {
            n->next = t;
            head = n;
            return head;
        }
        else if (t->next == nullptr && key >= t->data)
        {
            t->next = n;
            return head;
        }
        else if (t->data <= key && t->next->data >= key)
        {
            n->next = t->next;
            t->next = n;
            return head;
        }
        
        t = t->next;
    }
    
}

// Given a sorted circular linked list, the task is to insert a new node in this
// circular linked list so that it remains a sorted circular linked list.
Node* sortedInsertInCircularLL(Node* head, int data) 
{
    // code here
    Node *t = head;
    Node *n = createNewNode(data);
    
    printf("sortedInsertInCircularLL : ");
    do
    {
        printf(" %d, ", t->data);
        if (t == head && data <= t->data)
        {
            n->next = t;
            
            while(t->next != head)
            {
                t = t->next;
            }

            t->next = n;
            head = n;
            return head;
        }
        else if (t->data < data && data <= t->next->data)
        {
            n->next = t->next;
            t->next = n;
            return head;
        }
        else if (t->next == head && data > t->data)
        {
            t->next = n;
            n->next = head;
            return head;
        }
        else
        {
            t = t->next;
        }
    }
    while (t != head || t != nullptr);
    
    return head;
}

// Function to delete a node at given position.
/*Node* deleteNode(Node* head, int x) 
{
    // Your code here
    int cnt = 1;
    
    if (x == 1)
    {
        head = head->next;
        head->prev = nullptr;
        return head;
    }
    
    Node *t = head;
    while(t->next )
    {
        if (cnt == x)
        {
            Node *temp = t;
            t = t->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
            
            delete temp;
            return head;
        }
        else
        {
            t = t->next;
            cnt++;
        }
    }
    
    if (cnt == x)
    {
        t->prev->next = nullptr;
        
        delete t;
    }
    
    return head;
}*/

void main4()
{
    Node *phead1 = createNewNode(4);
    phead1->next = createNewNode(5);
    phead1->next->next = createNewNode(6);
    phead1->next->next->next = createNewNode(7);

    phead1->next->next->next->next = phead1;

    sortedInsertInCircularLL(phead1, 8);
}

void main3()
{
    Node *phead1 = createNewNode(4);
    phead1->next = createNewNode(5);

    Node *phead2 = createNewNode(9);
    phead2->next = createNewNode(7);
    phead2->next->next = createNewNode(5);

    printLL(addTwoLists(phead1, phead2));

    main4();
}

void main2()
{
    Node *phead = createNewNode(2);
    phead->next = createNewNode(0);
    phead->next->next = createNewNode(1);
    phead->next->next->next = createNewNode(0);
    phead->next->next->next->next = createNewNode(2);
    phead->next->next->next->next->next = createNewNode(1);
    phead->next->next->next->next->next->next = createNewNode(0);

    printLL(phead);
    printf("\ndeleteMid :");
    printLL(deleteMid(phead));

    printLL(deleteNode(phead, 2));
    
    printLL(segregate(phead));
    printf("\n compute :");
    printLL(compute(phead));  


    main3(); 
}

int main() 
{
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5-> 6 -> 7 -> 7 -> 7 -> NULL

    Node *head = createNewNode(1);
    Node *temp = head;
    int i = 0;

    // LL creation 
    for (i = 2; i < 8; i++)
    {
        temp->next = createNewNode(i);
        temp = temp->next;
    }

    temp->next = createNewNode(i-1);
    temp->next->next = createNewNode(i-1);

    // print LL
    printLL(head);

    removeDuplicates(head);    //Remove Duplicates from an Unsorted Linked List

    printLL(head);
	printf("Element at index 3 is %d\n", GetNth(head, 3));

    deleteNode(head->next->next);  // Given only a pointer/reference to a node to be deleted in a singly linked list
    printLL(head);

    printf("Middle Node LL - %d\n", middleNodeLL(head));

    temp = nthNodeFromEndLL(head, 5);  //Nth node from the end of a Linked List
    printf("Nth node from the end of a LL -  %d\n", ((temp == NULL)? -1: temp->data));

    printf("reversing the LL\n");
    reverse(&head);   // reverse the LL
    printLL(head);

    int k = 4;
    printf("reversing the LL in group of %d \n", k);
    reverseKgroupLL(&head, k);            // reverse the LL in in group of K nodes
    printLL(head);

    printf("reversing the LL in group of %d, itrative approach \n", k);
    reverseKgroupItrativelyLL(&head, k);
    printLL(head);

    printf("print list recursivly.");
    printRecursivly(head);

    Node *phead = createNewNode(1);
    phead->next = createNewNode(1);
    phead->next->next = createNewNode(2);
    phead->next->next->next = createNewNode(3);
    phead->next->next->next->next = createNewNode(2);
    phead->next->next->next->next->next = createNewNode(1);
    phead->next->next->next->next->next->next = createNewNode(1);

    printf("\nisPalindrome: %d \n", isPalindrome(phead));

    printLL(phead);

    removeDuplicatesFromSortedLL(phead);
    printLL(phead);

    printf("\nsortedInsert: ");
    printLL(sortedInsert(phead, 4));

    removeDuplicatesOptimization(phead);
    printLL(phead);

    main2();

    return 0;
}