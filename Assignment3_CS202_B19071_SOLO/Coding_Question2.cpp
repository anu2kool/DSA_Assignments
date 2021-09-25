//Anukool Dwivedi
//B19071
//SOLO
//Group13
//Question2
#include<iostream>
using namespace std;
//Defining the node that will be used in creating double ended queue using linked list(doubly)
struct Node  
{ 
    int data; 
    Node *prev, *next;  
    static Node* getnode(int data) 
    { 
        Node* newNode = new Node; 
        newNode->data = data; 
        newNode->prev = newNode->next = NULL; 
        return newNode; 
    } 
}; 
//Class of Dequeue for all its information
class Deque  
{ 
    Node* front; 
    Node* rear; 
    int Size; 
  
public: 
    Deque() 
    { 
        front = rear = NULL; 
        Size = 0; 
    } 
    void push_front(int data); 
    void push_back(int data); 
    void pop_front(); 
    void pop_back(); 
    int Front(); 
    int Back(); 
    int size(); 
    bool empty(); 
    void erase();
};
bool Deque::empty() 
{ 
    return (front == NULL); 
} 
int Deque::size() 
{ 
    return Size; 
} 
void Deque::push_front(int data) 
{ 
    Node* newNode = Node::getnode(data); 
    if (newNode == NULL) 
        cout << "OverFlow"; 
    else 
    { 
        if (front == NULL) 
            rear = front = newNode; 
        else 
        { 
            newNode->next = front; 
            front->prev = newNode; 
            front = newNode; 
        } 
        Size++; 
    } 
}
void Deque::push_back(int data) 
{ 
    Node* newNode = Node::getnode(data); 
    if (newNode == NULL) 
        cout << "OverFlow"; 
    else 
    { 
        if (rear == NULL) 
            front = rear = newNode;  
        else 
        { 
            newNode->prev = rear; 
            rear->next = newNode; 
            rear = newNode; 
        } 
  
        Size++; 
    } 
}
void Deque::pop_front() 
{  
    if (empty()) 
        cout << "UnderFlow"; 
    else 
    { 
        Node* temp = front; 
        front = front->next; 
        if (front == NULL) 
            rear = NULL; 
        else
            front->prev = NULL; 
        delete temp;  
        Size--; 
    } 
} 
void Deque::pop_back() 
{ 
    if (empty()) 
        cout << "UnderFlow"; 
    else 
    { 
        Node* temp = rear; 
        rear = rear->prev;  
        if (rear == NULL) 
            front = NULL; 
        else
            rear->next = NULL; 
        delete temp; 
        Size--; 
    } 
} 
int Deque::Front() 
{ 
    if (empty()) 
        return -1; 
    return front->data; 
} 
int Deque::Back() 
{ 
    if (empty()) 
        return -1; 
    return rear->data; 
} 
void Deque::erase() 
{ 
    rear = NULL; 
    while (front != NULL)  
    { 
        Node* temp = front; 
        front = front->next; 
        delete temp; 
    } 
    Size = 0; 
} 
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	int maximums[n-k+1];
	int minimums[n-k+1];
	int difference[n-k+1];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	Deque dq;
    int i;
    int count1=0, count2=0;
    //For finding the maximums of groups of size k
    for (i = 0; i < k; ++i) 
    {
        while ((!dq.empty()) && arr[i] >=arr[dq.Back()])
        	{
        		dq.pop_back();
			}
        dq.push_back(i);
    }
    for (; i < n; ++i) 
    {
    	maximums[count1++]=arr[dq.Front()];
        while ((!dq.empty()) && dq.Front() <= i - k)
        {
        	dq.pop_front(); 
		}
        while ((!dq.empty()) && arr[i] >= arr[dq.Back()])
        {
        	dq.pop_back();
		}
        dq.push_back(i);
    }
    maximums[count1++]=arr[dq.Front()];
    dq.erase();
    //For finding the minimums of groups of size k
    for (i = 0; i < k; ++i) 
    {
        while ((!dq.empty()) && arr[i] <=arr[dq.Back()])
        	{
        		dq.pop_back();
			}
        dq.push_back(i);
    }
    for (; i < n; ++i) 
    {
    	minimums[count2++]=arr[dq.Front()];
        while ((!dq.empty()) && dq.Front() <= i - k)
        {
        	dq.pop_front(); 
		}
        while ((!dq.empty()) && arr[i] <= arr[dq.Back()])
        {
        	dq.pop_back();
		}
        dq.push_back(i);
    }
    minimums[count2++]=arr[dq.Front()];
    for(i=0; i<n-k+1; i++)
    {
    	difference[i]=maximums[i]-minimums[i];
	}
	for(i=0; i<n-k+1; i++)
	{
		cout<<difference[i]<<" ";
	}
	cout<<endl;
	return 0;
}
