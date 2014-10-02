#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTraverseInOrder(Node *root)
{
    Node *CurrentNode = root;
    Stack *stack = stackNew();
    printf("created a stack\n");

    printf("\nEntered Node\n\n");
    CurrentNode->state = ENTERED_NODE ;

    if (CurrentNode->left == NULL && CurrentNode ->right == NULL )
        {
            display(CurrentNode->data);
            CurrentNode -> state = VISITED_RIGHT_NODE;
        }
        
    if (CurrentNode->left != NULL)
        {
            stackPush(stack,(Node *)CurrentNode);
            CurrentNode = CurrentNode->left ;   //Go to left node
            CurrentNode->state = ENTERED_NODE;
            
            display(CurrentNode->data); //Display left node data
            printf("CurrentNode data : %d\n",CurrentNode->data);
            
            
            //--------------------------------------------------//
            CurrentNode = (Node *)stackPop(stack); //Return to previous node
            CurrentNode->state = VISITED_LEFT_NODE ;
            printf("Visited Left Node\n\n");
            
            display(CurrentNode->data); //Display parent data
            printf("CurrentNode data : %d\n\n",CurrentNode->data);
        }    
    
    else if (CurrentNode ->right != NULL) //Left node must be NULL
        {
            CurrentNode->state = VISITED_LEFT_NODE ;
            printf("Visited Left Node\n");
            //--------------------------------------------------//
            display(CurrentNode->data); //Display parent data
            printf("CurrentNode data : %d\n\n",CurrentNode->data);
        }
    
 
    
    if (CurrentNode->right != NULL && CurrentNode->state == VISITED_LEFT_NODE)
        {   
            stackPush(stack,(Node *)CurrentNode);
            CurrentNode = CurrentNode->right ; // Go to right node
                
            display(CurrentNode->data); // Display right node data
            printf("CurrentNode data : %d\n",CurrentNode->data);
                
            CurrentNode = (Node *)stackPop(stack);
            CurrentNode->state = VISITED_RIGHT_NODE ;
            printf("Visited Right Node\n");
                
        }   

    else 
    if (CurrentNode->state == VISITED_RIGHT_NODE );
        CurrentNode = (Node *)stackPop(stack);
        
        
    stackDel(stack);
    printf("deleted a stack\n");
    printf("--------------------------------------------------------------------------\n\n");
}

