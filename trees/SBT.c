#include<stdio.h>
#include<stdlib.h>

void insert();
struct node* search(struct node*,int);
int height(struct node*);
void in_order(struct node*);
void pre_order(struct node*);
void post_order(struct node*);
void level_order(struct node*,int);
void left_child(struct node*);
void right_child(struct node*);

int key=0,left=0,right=0;

struct node
{
	int d;
	struct node *l,*r;
};
struct node *s=NULL;
struct node *address=NULL;

int main()
{
    	struct node *t=NULL;
    	int f=1,c,i,m=0;
    	printf("\n WELCOME TO THE SIMPLE BINARY TREE IMPLEMENTATION....");
    	while(f==1)
    	{
    	    	printf("\n\n choose your operation:");
        	printf("\n 1.INSERT AN ELEMENT\n 2.SEARCH AN ELEMENT \n 3. DISPLAY THE TREE \n 4.HEIGHT OF THE TREE\n 5.EXIT");
        	scanf("%d",&c);
        	switch(c)
        	{
        	    	case 1: insert();
            	        	break;
            		case 2: printf("\n enter the element to be searched ");
            	        	scanf("%d",&i);
            	        	t=search(s,i);
            	        	if(t==NULL)
                	        	printf("\n element not found..");
                	    	else
                	        	printf("\n element found...");
                    		break;
            		case 3:
                	    	printf("\n choose type of display...");
                    		printf("\n1.in-order\n2.pre-order\n3.post-order\n4.level-by-level order\n");
                    		scanf("%d",&m);
                    		switch(m)
                    		{
                        		case 1: in_order(s); break;
                        		case 2: pre_order(s);break;
                        		case 3: post_order(s);break;
                        		case 4:
                            		for(i=1;i<=height(s);i++)
                            		{
                                		level_order(s,i);
                            		}break;
                        		default :printf("\n choose valid option");
				}break;
            		case 4: printf("\n HEIGHT OF THE TREE IS %d",height(s));
                    		break;
            		case 5: f=0;
                    		break;
            		default:printf("\n enter valid option");
        	}
    }
    return 0;
}
void insert()
{
    	struct node *t=NULL;
    	int c,f;
    	if(s==NULL)
    	{
        	s=(struct node*)malloc(sizeof(struct node));
        	printf("\n enter the element to be inserted..");
        	scanf("%d",&(s->d));
        	s->l=NULL;
        	s->r=NULL;
        	printf("\n INSERTED SUCCESSFULLY....");
    	}
    	else
    	{
        	address=NULL;
        	printf("\n enter the key element to which the given element is assigned as a child");
        	scanf("%d",&key);
        	search(s,key);
        	t=address;
        	if(t==NULL)
            		printf("\nkey element not found");
        	else
		{
        		printf("\n key element %d is found ...",(t->d));
        		if(t->l!=NULL && t->r!=NULL)
            			printf("\n no space to insert..try another key element..");
        		else
        		{
        			printf("\n on which side you want insert the element.... ");
        			printf("\n 1. left child\n 2. right child");
        			scanf("%d",&c);
        			switch(c)
        			{
            				case 1: 
					if(t->l!=NULL)
                     			{
                         			printf("\n left child is full....do you want to insert on the right....\n 1. yes \n 2. no");
                         			scanf("%d",&f);
                         			switch(f)
                         			{
                         	    			case 1:right_child(t);break;
                            				case 2:break;
                            				default : printf("\n choose valid option..");
                         			}
                     			}
                     			else
                     			{
                         			left_child(t);
                     			}break;
            				case 2:  
					if(t->r!=NULL)
                     			{
                         			printf("\n right child is full....do you want to insert on the left....\n 1. yes \n 2. no");
                          			scanf("%d",&f);
                         			switch(f)
                         			{
                             				case 1:left_child(t);break;
                             				case 2:break;
                            				default: printf("\n choose valid option..");
                         			}
					}
                     			else
                     			{
                         			right_child(t);
                     			}break;
        			}
        		}
		}
    	}
}
struct node* search(struct node* t, int k)
{	
    	if(address==NULL)
	{
    		if(t!=NULL)
    		{
			search(t->l,k);
            		if(t->d==k)
                		address=t;
            		search(t->r,k);
		}
	}
}
void in_order(struct node *t)
{
    	if(t!=NULL)
     	{
       		in_order(t->l);
       		printf("\n%d",t->d);
       		in_order(t->r);
     	}
}
void pre_order(struct node *t)
{
    	if(t!=NULL)
     	{
       		printf("\n%d",t->d);
       		pre_order(t->l);
       		pre_order(t->r);
     	}
}
void post_order(struct node *t)
{
    	if(t!=NULL)
     	{
       		post_order(t->l);
       		post_order(t->r);
       		printf("\n%d",t->d);
     	}
}
void level_order(struct node *t,int level)
{
	if(t == NULL)
        return;
    	if(level == 1)
        printf("%d ", t->d);
    	else if(level > 1)
    	{
        	level_order(t->l, level-1);
        	level_order(t->r, level-1);
    	}
}
int height(struct node *t)
{
    	if(t==NULL)
        	return 0;
    	else
    	{
        	left=height(t->l);
        	right=height(t->r);
        	if(left > right)
            		return (left+1);
        	else
            		return (right+1);
    	}
}
void right_child(struct node *t)
{
   	t->r=(struct node*)malloc(sizeof(struct node));
    	t=t->r;
    	printf("\n enter the value to be inserted..");
    	scanf("%d",&(t->d));
    	t->l=NULL;
    	t->r=NULL;
     	printf("\n INSERTED SUCCESSFULLY....");
}
void left_child(struct node* t)
{
  	t->l=(struct node*)malloc(sizeof(struct node));
  	t=t->l;
  	printf("\n enter the value to be inserted..");
  	scanf("%d",&(t->d));
  	t->l=NULL;
  	t->r=NULL;
  	printf("\n INSERTED SUCCESSFULLY....");
}
