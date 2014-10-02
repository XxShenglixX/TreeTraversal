#include "unity.h"
#include "mock_Print.h"
#include "mock_Stack.h"
#include "BinaryTree.h"
#include "Traversal.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 *      10
 *     /  \ 
 *    -    -
 */
void test_binary_tree_with_1_node(void)
{
	Node root = {NULL,NULL,10};
    Stack stack;
    
    printf("Starts test_binary_tree_with_1_node\n");
    
    stackNew_ExpectAndReturn(&stack);
    display_Expect(10);
    stackPop_ExpectAndReturn(&stack,NULL);
    stackDel_Expect(&stack);
  
    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     /  \ 
 *    5   -
 */
void test_binary_tree_with_2_nodes_parent_and_left_child(void)
{
    Node leftChild = {NULL,NULL,5};
	Node root = {&leftChild,NULL,10};
    
    Stack stack;
    
    printf("Starts test_binary_tree_with_2_nodes_parent_and_left_child\n");
    
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    display_Expect(5);
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);
    stackPop_ExpectAndReturn(&stack,NULL);
    stackDel_Expect(&stack);
    
    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     /  \ 
 *    5   20
 */
void test_binary_tree_with_3_nodes_parent_left_child_and_right_child(void)
{
    Node leftChild  = {NULL,NULL,5};
    Node rightChild = {NULL,NULL,20};
	Node root       = {&leftChild,&rightChild,10};
    
    Stack stack;
    
    printf("Starts test_binary_tree_with_3_nodes_parent_left_child_and_right_child\n");
    
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    display_Expect(5);
    
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);
    
    stackPush_Expect(&stack,&root);
    display_Expect(20);
    stackPop_ExpectAndReturn(&stack,&root);
    
    stackPop_ExpectAndReturn(&stack,NULL);
    stackDel_Expect(&stack);
    
    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     /  \ 
 *    -   20
 */
void test_binary_tree_with_2_nodes_parent_and_right_child(void)
{
    Node rightChild = {NULL,NULL,20};
	Node root       = {NULL,&rightChild,10};
    
    Stack stack ;
    
    printf("Starts test_binary_tree_with_2_nodes_parent_and_right_child\n");
    
    stackNew_ExpectAndReturn(&stack);
    display_Expect(10);
    
    stackPush_Expect(&stack,&root);
    display_Expect(20);
    
    stackPop_ExpectAndReturn(&stack,&root);
    stackPop_ExpectAndReturn(&stack,NULL);
    stackDel_Expect(&stack);
    
    binaryTreeTraverseInOrder(&root);
}   

/**
 *               10
 *              /  \ 
 *             5    -
 *            / \
 *           1   7 
 */ 
 void test_binary_tree_with_4_nodes_parent_middle_left_and_right_child(void)
{
    Node leftChild  = {NULL,NULL,1};
    Node rightChild = {NULL,NULL,7};
    Node middle     = {&leftChild,&rightChild,5};
	Node root       = {&middle,NULL,10};    

    Stack stack ;
    
    printf("Starts test_binary_tree_with_4_nodes_parent_middle_left_and_right_child\n");
    
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    
    stackPush_Expect(&stack,&middle);
    display_Expect(1);
    
    stackPush_Expect(&stack,&root);

}