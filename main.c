#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "buildTree.h"
#include "structureTree.h"
#include "writeTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( int argc, char **argv ) 
{
    Node *head;
    int i,j;
    int st[2];
    st[0]=st[1]=0; 
    
    // make the head node
    head = makeNode( 0.0,0.0, 0 );

    // make a tree
    //makeChildren( head );
    //makeChildren( head->child[1]);
    
    /*
     growTree(head);
     growTree(head);
     writeTree( head );//level 2 full---task 1-1
     destroyTree( head );
     */
    
    
    /*
     growTree(head);
     makeChildren(head->child[1]);
     writeTree( head );
     destroyTree( head );
     // print the tree for Gnuplot task1-2
    */
    
    
    /*
     growTree(head);
     growTree(head);
     removeChildren(head->child[1]);// task2-1
     writeTree( head );
     destroyTree(head);
     */
    
    
    
    /*
     growTree(head);
     makeChildren( head->child[1]);
     makeChildren( head->child[2]);
     removeChildren(head->child[1]);
     writeTree( head );
     destroyTree(head);//task2-2
     */
   
    
    
    
    
    
    /*
    growTree(head);
    growTree(head);
    growTree(head);
    judge(head);
    change( head , st);
    printf("%i\n",st[0]);
    printf("%i\n",st[1]);
    writeTree( head );//task3-1
    */
    

    

    
    
    growTree(head);
    growTree(head);
    growTree(head);
    adapt( head , st);
    writeTree(head);  //task3-2
    
    
    
    
  return 0;
}
