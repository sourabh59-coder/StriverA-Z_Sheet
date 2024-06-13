//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* ReverseLinkedList(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL)
        {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* ptr = ReverseLinkedList(head);
        
        Node* temp = ptr;
        
        int b = 1;
        int carry = 0;
        Node* prev_ptr = NULL;
        
        while(temp!=NULL && (b+carry)!=0)
        {
            int a = temp->data;
            a = (a+b+carry);
            temp->data = a % 10;
            b = 0;
            carry = a/10;
            prev_ptr = temp;
            temp = temp->next;
        }
        
        if(carry!=0)
        {
            Node* ptr_carry = new Node(carry);
            prev_ptr->next = ptr_carry;
        }
        
        Node* ans = ReverseLinkedList(ptr);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
