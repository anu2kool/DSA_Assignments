#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data; 
    Node *parent; 
    Node *left; 
    Node *right; 
    int color; 
    int size;  
    int value;  
    int sum;   
};

typedef Node *node_ptr;

class RBTree 
{
public:
    node_ptr root;
    node_ptr TNULL;
    void Initialize(node_ptr node, node_ptr parent) 
	{
        node->data = 0;
        node->parent = parent;
        node->left = NULL;
        node->right = NULL;
        node->color = 0;
        node->size = 0;
        node->sum = 0;
        node->value = 0;
    }
    Node* Find(Node* root , int i)
	{
        int current_rank = root->left->size + 1; 
    	node_ptr y = root; 
    	while (y!=NULL && current_rank != i) 
		{ 
	        if (i < current_rank) 
	        {
	        	y = y->left; 
			}
	        else 
			{ 
	            i = i - current_rank; 
	            y = y->right; 
	        } 
	        if (y == NULL)
			{
				return NULL; 
			} 
	        current_rank = y->left->size + 1; 
    	} 
    	return y; 
    }
    int Sum(Node* root,int i)
	{
        int sum = 0;
        int current_rank = root->left->size + 1; 
    	node_ptr y = root; 
    	while (y != NULL && current_rank != i) 
		{ 
	        if (i < current_rank) 
	        {
	        	y = y->left; 	
			}
	        else 
			{ 
	            i = i - current_rank; 
	            sum += y->left->sum + y->value;
	            y = y->right; 
	        } 
	        if (y == NULL) 
	        {
	        	return 0; 
			}
	        current_rank = y->left->size + 1; 
    	} 
    	return sum + y->value + y->left->sum; 
    }
    void Fix_Violation(node_ptr x) 
	{
        node_ptr s;
        while (x != root && x->color == 0) 
		{
            if (x == x->parent->left) 
			{
                s = x->parent->right;
                if (s->color == 1) 
				{
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                if (s->left->color == 0 && s->right->color == 0) 
				{
                    s->color = 1;
                    x = x->parent;
                } 
				else 
				{
                    if (s->right->color == 0) 
					{
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    } 
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            } 
			else 
			{
                s = x->parent->left;
                if (s->color == 1) 
				{
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                if (s->right->color == 0 && s->right->color == 0) 
				{
                    s->color = 1;
                    x = x->parent;
                } 
				else 
				{
                    if (s->left->color == 0) 
					{
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    } 
                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            } 
        }
        x->color = 0;
    }
    void RB_Translate(node_ptr u, node_ptr v)
	{
        if (u->parent == NULL)
		{
            root = v;
        } 
		else if (u == u->parent->left)
		{
            u->parent->left = v;
        } 
		else 
		{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    void Delete_Helper(node_ptr node, int key) 
	{
        node_ptr z = TNULL;
        node_ptr x, y;
        z = Find(root,key);
        if (z == TNULL) 
		{
            cout<<"Key not found"<<endl;
            return;
        } 
        if (z != node) 
		{ 
        node_ptr temp = z->parent; 
        while (temp != NULL) 
		{ 
            temp->size--; 
            temp->sum -= z->value;
            temp = temp->parent; 
        } 
    } 
        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) 
		{
            x = z->right;
            RB_Translate(z, z->right);
        } 
		else if (z->right == TNULL) 
		{
            x = z->left;
            RB_Translate(z, z->left);
        } 
		else 
		{
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) 
			{
                x->parent = y;
            } 
			else 
			{
                RB_Translate(y, y->right);
                y->right = z->right;
                y->right->parent = y;
                node_ptr temp = x->parent; 
                 while (temp != y) 
				 { 
	                temp->sum -= z->value;
	                temp->size--; 
	                temp = temp->parent; 
           		 } 
	            y->size = y->left->size + 1; 
	            y->sum = y->left->sum + y->value; 
            }
            RB_Translate(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        y->size = y->left->size + y->right->size + 1; 
        y->sum = y->left->sum + y->right->sum + y->value; 
        if (y_original_color == 0)
		{
            Fix_Violation(x);
        }
    }
    void Fix_Insert(node_ptr k)
	{
        node_ptr u;
        while (k->parent->color == 1) 
		{
            if (k->parent == k->parent->parent->right) 
			{
                u = k->parent->parent->left; 
                if (u->color == 1) 
				{
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } 
				else 
				{
                    if (k == k->parent->left) 
					{
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } 
			else 
			{
                u = k->parent->parent->right; 

                if (u->color == 1) 
				{
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;  
                } 
				else 
				{
                    if (k == k->parent->right) 
					{
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) 
			{
                break;
            }
        }
        root->color = 0;
    }
public:
    RBTree() 
	{
        TNULL = new Node;
        TNULL->color = 0;
        TNULL->left = NULL;
        TNULL->right = NULL;
        root = TNULL;
        TNULL->size = 0;
        TNULL->value = 0;
        TNULL->sum = 0;
    }
    node_ptr minimum(node_ptr node) 
	{
        while (node->left != TNULL) 
		{
            node = node->left;
        }
        return node;
    }
    node_ptr maximum(node_ptr node) 
	{
        while (node->right != TNULL) 
		{
            node = node->right;
        }
        return node;
    }
    void leftRotate(node_ptr x) 
	{
        node_ptr y = x->right;
        x->right = y->left;                          
        if (y->left != TNULL) 
		{
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL) 
		{
            this->root = y;
        } 
		else if (x == x->parent->left) 
		{
            x->parent->left = y;
        } 
		else 
		{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
        y->size = x->size; 
        y->sum = x->sum;
        x->size = x->left->size + x->right->size +1; 
        x->sum = x->left->sum + x->right->sum + x->value;   
    }
    void rightRotate(node_ptr x) 
	{
        node_ptr y = x->left;
        x->left = y->right;
        if (y->right != TNULL) 
		{
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL) 
		{
            this->root = y;
        } 
		else if (x == x->parent->right) 
		{
            x->parent->right = y;
        } 
		else 
		{
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
        x->size = y->size; 
        y->size = y->left->size + y->right->size + 1; 
        x->sum = y->sum; 
        y->sum = y->left->sum + y->right->sum + y->value; 
    }
    void Insert(int key,int value) 
	{
        node_ptr node = new Node;
        node->parent = NULL;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1; 
        node->size = 1;
        node->value = value;
        node->sum = value;
        node_ptr y = NULL;
        node_ptr x = this->root;
        while (x != TNULL) 
		{
            y = x;
            y->size++;
            y->sum += value;
            if(node->data > x->data) 
			{
                x = x->right;
            } 
			else 
			{
                x = x->left;
            }
        }
        node->parent = y;
        if (y == NULL) 
		{
            root = node;
        } 
		else if (node->data <= y->data) 
		{
            y->left = node;
        } 
		else 
		{
            y->right = node;
        }
        if (node->parent == NULL)
		{
            root = node;
            node->color = 0;
            return;
        }
        if (node->parent->parent == NULL) 
		{
            return;
        }
        Fix_Insert(node);
    }
    void Delete_Node(int data) 
	{
        Delete_Helper(this->root, data);
    }
};

int main() 
{
	int choice;
    RBTree BST;
    int index,value,rank,l,r;
    double sum1;
    Node* p;
    int Q;
    cin>>Q;
    while(Q--)
	{           
    	cin>>choice;
    	if(choice==1)
    	{
    		cin>>index>>value;
	        BST.Insert(index,value);
	        break; 
		}
		else if(choice==2)
		{
			cin>>index;
	        BST.Delete_Node(index);
	        break;
	    }                  
	    else if(choice==3)
	    {
	    	cin>>rank;
	        p= BST.Find(BST.root,rank);
	        cout<<p->value<<"\n";
	        break;
		}
		else if(choice==4)
		{
			cin>>l>>r;
	        sum1 = double(BST.Sum(BST.root,r));
	        if(l>1)
			{
	             sum1-=double(BST.Sum(BST.root,l-1));
	        }
	        double length = double(r-l+1);
	        sum1 /= length;
	        cout<<sum1<<"\n";
	        break;
		}
    }

    return 0;
}		
