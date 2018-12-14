#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structureTree.h"	
int a=0;
int b=0;

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}
void growTree( Node *head ){
  int i;

  if( head->child[0] == NULL )
      makeChildren( head );
  else {
    for ( i=0; i<4; ++i ) {
      growTree( head->child[i] );
    }
  }
  return;
	
}

void destroyTree( Node *parent ) {
	int i;
	if( parent->child[0] == NULL ) 
		free(parent);
	else
	{	
	  for(i=0;i<4;++i)
	    {
	       destroyTree(parent->child[i]);	
		}
	  free(parent);
	}	
	return;
}

void removeChildren(Node *parent) {
	int i;
	for(i=0;i<4;i++)
	{
		free(parent->child[i]);		
		parent->child[i]=NULL;		
	}

}

// Data functionvalue

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

double judge( Node *head ){
	int i,j;
	head->flag=0;
	if(head->child[0]==NULL)
	{
		if( nodeValue(head,0) < -0.5 )
		head->flag=-1;
		else if( nodeValue(head,0) >  0.5 )
		head->flag= 1;
		else
		head->flag= 0;
	}
	else if(head->child[0]!=NULL)
	{	
	  for(i=0;i<4;i++)	 
	  	judge(head->child[i]);	  		  	
	}
}

int *change( Node *node , int st[])
{
	int i,j;
	judge( node );
	if(node->child[0]==NULL&& node->flag==1)
	{
		makeChildren(node);
		st[0]+=4;
	}
	else if(node->child[0]!=NULL)
	{
		for(i=0;i<4;i++)
			{
			change( node->child[i] , st);
			}		
		j=0;
		for(i=0;i<4;i++)
		{
			if(node->child[i]->flag==-1)
				j++;
		}	
		if(j==4)
		{
			removeChildren(node);
			st[1]+=4;
		}			
	}
	return st;
} 

int *chang( Node *node , int st[])
{
	int i,j;
	int maxlevel=6;
	if(node->child[0]==NULL&& node->flag==1&&node->level<maxlevel)
	{
		makeChildren(node);
		st[0]+=4;
	}
	else if(node->child[0]!=NULL)
	{
		for(i=0;i<4;i++)
			{
			change( node->child[i] , st);
			}		
		j=0;
		for(i=0;i<4;i++)
		{
			if(node->child[i]->flag==-1)
				j++;
		}	
		if(j==4)
		{
			removeChildren(node);
			st[1]+=4;
		}			
	}
	return st;
} 

int *adapt( Node *node , int st[])
{
	do
	{
		st[0]=0;
		st[1]=0;
		judge(node);
		chang( node , st);
		printf("%i\n%i\n",st[0],st[1]);
	}
	while(st[0]!=0 && st[1]!=0);
	return;
}





