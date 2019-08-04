#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l,*r;
};
struct node *s,*parent,*address;  

void search(struct node*,int);
void removeelement();
void insert();
void inorder(struct node*); // for displaying tree
void display();
void find();

int main()
{
	int f=1,c;  
	s=NULL;
	parent=NULL;
	while(f)
	{
		printf("\n 1.insert  2.delete  3.display   4. find  5.exit  \n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				insert();break;
			case 2:
				removeelement();break;
			case 3:
				display();break;
			case 4:
				find();break;
			case 5:
				f=0;break;
			default:
				printf("\n Not a valid option \n");
		}
	}
}
void insert()
{
    	struct node *t=s;
    	int k;
    	printf("\n Enter value \n");    
    	scanf("%d",&k);
	if(s==NULL)
	{
	        s= (struct node*) malloc(sizeof(struct node));
	        s->d=k;
	        s->l=NULL;
		s->r=NULL;
	}
	else
	{    
    		while(1)
    		{
        		if(k==t->d)
        		{
            			printf("\n Duplicate value error - value already exist \n");
            			break;
        		}
			else if(k<t->d)
		        {
				if(t->l==NULL)
				{
					t->l= (struct node*) malloc(sizeof(struct node));
		                	t=t->l;
		                	t->l=NULL;
		                	t->r=NULL;
					t->d=k;
					break; // come out of loop
				}
				else
                		t=t->l;
      			}
         		else if(k>t->d)
        		{
            			if(t->r==NULL)
            			{
                			t->r= (struct node*) malloc(sizeof(struct node));
                			t=t->r;
                			t->l=NULL;
                			t->r=NULL;
                			t->d=k;
                			break; // come out of loop
            			}	
            			else
                		t=t->r;
        		}
    		}
		printf("\n Insertion Success \n");
	}
}
void removeelement()
{
	struct node *t;
	struct node *t1;
	struct node *t2,*p;		

// t is element to be deleted , t2 is min element in right sub tree of t , p is parent of t2
	if(s==NULL)
    		printf("\n Sorry cannot delete -- overflow exception \n ");
    	else
	{
    		printf("\n Enter the element to be Deleted \n ");
    		int k;
    		scanf("%d",&k);    
    		search(s,k); // it updates address of the key and parent of key
    		t=address;
    		if(t==NULL)
    			printf("\n Sorry element you are looking for is not there \n");
    		else if(t->l==NULL && t->r==NULL) // Leaf node case
    		{
        		if(parent==NULL) // test if a node is root
    			{
            			free(s);
            			s=NULL;  // tree is empty now
    			}
    			else if (parent->l!=NULL && (parent->l)->d==t->d) // node is left child to its parent
    			{
        			parent->l=NULL;
        			free(t);
    			}
    			else if(parent->r!=NULL && (parent->r)->d==t->d) // node is right child to its parent
    			{
        			parent->r=NULL;
        			free(t);
    			}
    			printf("\n Deletion success \n ");
    		} // End of leaf node case
 		else if(t->l!=NULL && t->r==NULL) // Node has only left child
    		{
    			if(parent==NULL) // deleting a root 
    			{
        			s=t->l;
        			free(t);
    			}
    			else if((parent->l)->d==t->d) // node is left child to its parent
    			{
        			parent->l=t->l;
        			free(t);
    			}
    			else if((parent->r)->d==t->d) // node is right child to its parent
    			{
    	    			parent->r=t->l;
        			free(t);
    			}
			printf("\n Deletion success \n ");
    		} // End of node which has only left child
		else if(t->l==NULL && t->r!=NULL) // Node has only right child
    		{
			if(parent==NULL)
	    		{
        			s=t->r;
        			free(t);
    			}
    			else if( parent->l!=NULL && (parent->l)->d==t->d) // node is left child to its parent
    			{
        			parent->l=t->r;
        			free(t);
    			}
    			else if(parent->r!=NULL && (parent->r)->d==t->d) // node is right child to its parent
    			{
        			parent->r=t->r;
        			free(t);
    			}
    			printf("\n Deletion success \n ");
		} // End of node which has only right child
		else if(t->l!=NULL && t->r!=NULL) // if node has two childs, lets replace it with min element in// right sub tree
  		{
			printf("\n entered in right loop \n ");
			if((t->r)->l==NULL )// you wanted to delete root, but right sub tree of root has no left childs
			{
				t1=t->r;
				t->d=t1->d; // copy right elements value in root
				t->r=t1->r; // copy right pointer of right child to roots right
				free(t1); // delete the right child of root
				printf("\n Deletion success \n ");
			}	
			else
			{
				t2=t->r;
				while(t2->l!=NULL)
				{
					p=t2;
					t2=t2->l;
				}
				p->l=t2->r;
				t->d=t2->d;
				free(t2);
 				printf("\n Deletion success \n ");
  			}
		} //else if -- End of case where you wanted to delete a node which has two childs
	}// else when tree is not empty
}// end of function delete
void inorder(struct node *t)
{
    	if(t!=NULL)
    	{
    		inorder(t->l);
    		printf("   %d",t->d);;
    		inorder(t->r);
    	}
}
void search(struct node *t,int k)
{

	address=NULL;
	parent=NULL;
    	if(t==NULL)
    	printf("\n Exception -- Tree is empty \n");
    	else 
	{
        	while(1)
    		{
        		if(t->d==k)
         		{
         			address=t; // come out of function when you find element
         			printf("\n Element found successfully \n");
         			break;
         		}
        		else if(t->l==NULL && t->r==NULL) // when element is not in tree
        			break;
      			else if(k<(t->d)) // traverse left sub tree
        		{
        	    		if(t->l!=NULL)
            			{
                			parent=t;
                			t=t->l;
            			}
        		}
     			else if(k>(t->d)) // traverse right sub tree
        		{
            			if(t->r!=NULL)
            			{
                			parent=t;
                			t=t->r;
            			}	
        		}
    		} // end of loop
    	}
}
void find()
{
	int k;
	address=NULL;
	printf("\n Enter element to be searched \n");
	scanf("%d",&k);
	search(s,k); // will update address variable if element is found 
	if(address==NULL)
		printf("\n sorry element NOT found \n");
	else
		printf("\n Success -- Element found ");
}
void display()
{
	printf("\n Elements in Binary Search tree are :- ( Acc to inorder traversal )  \n ");
	inorder(s);
	printf("\n");
}
