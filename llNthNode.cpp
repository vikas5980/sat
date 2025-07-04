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
    printLL(deleteNode(phead, 2));
    
    printLL(segregate(phead));   
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

    removeDuplicatesOptimization(phead);
    printLL(phead);

    main2();

    return 0;
}