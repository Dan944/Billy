#include "structureTree.h"

#ifndef BUILDTREE_H
#define BUILDTREE_H
void growTree( Node *head) ;
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void destroyTree( Node *parent );
void removeChildren(Node *parent);
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
double judge( Node *head);
int *change( Node *node , int st[2]);
int *chang( Node *node , int st[2]);
int *adapt( Node *node , int st[2]);
#endif
