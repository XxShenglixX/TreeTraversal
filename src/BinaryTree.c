#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTraverseInOrder(Node *root)
{
    Node *CurrentNode = root;
    
    if (CurrentNode != NULL)
        CurrentNode->state = ENTERED_NODE ; //Root state to ENTERED_NODE
    
    Stack *stack = stackNew();
 
    while (root->state != VISITED_RIGHT_NODE)
    {
        if (CurrentNode->state == ENTERED_NODE)
            {
                printf( "\nCurrentNode state = ENTERED_NODE \n");
                if (CurrentNode->left == NULL && CurrentNode ->right == NULL) 
                {
                    printf( "CurrentNode left and right are NULL \n");
                    display(CurrentNode->data);
                    printf( "Changing CurrentNode state to VISITED_RIGHT_NODE \n");
                    CurrentNode -> state = VISITED_RIGHT_NODE;
                    printf( "CurrentNode->data : %d\n",CurrentNode->data);
                   
                }
    
                else if (CurrentNode->left != NULL)
                {
                    printf( "CurrentNode ->left not NULL \n");
                
                    stackPush(stack,(Node *)CurrentNode); // Push parent to stack
                    CurrentNode = CurrentNode->left ;   //Go to left node
                    printf( "Changing child state to ENTERED_NODE \n");
                    CurrentNode->state = ENTERED_NODE; //Left child state to ENTERED_NODE
                }
                else if (CurrentNode->right != NULL)
                {
                    printf( "CurrentNode->left is NULL but CurrentNode-> right not NULL \n");
                    printf( "Changing parent state to VISITED_LEFT_NODE \n");
                    display(CurrentNode->data);
                    printf( "CurrentNode->data : %d\n",CurrentNode->data);
                    CurrentNode->state = VISITED_LEFT_NODE ; //Parent state to visited left
                    stackPush(stack,(Node *)CurrentNode); //Push parent into the stack
                    CurrentNode = CurrentNode->right ; // Go to right node   
                    printf( "Changing child state to ENTERED_NODE \n");
                    CurrentNode->state = ENTERED_NODE ;// Right child state to ENTERED_NODE
                }
                
            }
    
        else if (CurrentNode->state == VISITED_LEFT_NODE)    
        {
           printf( "\nCurrentNode state = VISITED_LEFT_NODE \n");
           if (CurrentNode->right != NULL)
            {
                printf( "CurrentNode ->right not NULL \n");
                display(CurrentNode->data); //Display parent data 
                printf( "CurrentNode->data : %d\n",CurrentNode->data);
                stackPush(stack,(Node *)CurrentNode); //Push parent into the stack
                CurrentNode = CurrentNode->right ; // Go to right node
                printf( "Changing child state to ENTERED_NODE \n");                
                CurrentNode->state = ENTERED_NODE ; //Right child state to ENTERED_NODE 
            }
           else
            {
                printf( "CurrentNode ->right = NULL \n");
                display(CurrentNode->data);
                printf( "CurrentNode->data : %d\n",CurrentNode->data);
                printf( "Changing parent state to VISITED_RIGHT_NODE \n");
                CurrentNode -> state = VISITED_RIGHT_NODE;
            }
        }
    
        else if (CurrentNode ->state == VISITED_RIGHT_NODE )
        {
            printf( "\nCurrentNode state = VISITED_RIGHT_NODE \n");
            CurrentNode = (Node *)stackPop(stack); //Pop parent out of stack
            if (CurrentNode != NULL)
            {
                if (CurrentNode->state == ENTERED_NODE) //Parents just visited left if true
                    CurrentNode->state = VISITED_LEFT_NODE ;
                else
                    CurrentNode->state = VISITED_RIGHT_NODE ;
            }
        }  
    }
  
    
    stackDel(stack);
   
}






void printLinear(Node *node)
{
    if (node != NULL)
    {
        printLinear(node->left);
        printf("Node : %d  ",node->data);
    }
}

void binaryTreePrintInOrder(Node *node)
{
     if (node != NULL)
    {
        binaryTreePrintInOrder(node->left);
        printf("Node : %d  ",node->data);
        binaryTreePrintInOrder(node->right);
    }
}
