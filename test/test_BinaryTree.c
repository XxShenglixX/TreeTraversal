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
    printf("test_binary_tree_with_1_node\n\n");
	Node root = {NULL,NULL,10};
    Stack stack;


    stackNew_ExpectAndReturn(&stack);
    display_Expect(10);
    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");
}

/**
 *      10
 *     /  \
 *    5   -
 */
void test_binary_tree_with_2_nodes_parent_and_left_child(void)
{
    printf("test_binary_tree_with_2_nodes_parent_and_left_child\n\n");
    Node leftChild = {NULL,NULL,5};
	Node root = {&leftChild,NULL,10};

    Stack stack;

    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    display_Expect(5);
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);
    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");
}

/**
 *      10
 *     /  \
 *    -   20
 */
void test_binary_tree_with_2_nodes_parent_and_right_child(void)
{
    printf("test_binary_tree_with_2_nodes_parent_and_right_child\n\n");
    Node rightChild = {NULL,NULL,20};
	Node root       = {NULL,&rightChild,10};

    Stack stack ;


    stackNew_ExpectAndReturn(&stack);
    display_Expect(10);

    stackPush_Expect(&stack,&root);
    display_Expect(20);

    stackPop_ExpectAndReturn(&stack,&root);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");
}


/**
 *      10
 *     /  \
 *    5   20
 */
void test_binary_tree_with_3_nodes_parent_left_child_and_right_child(void)
{
    printf("test_binary_tree_with_3_nodes_parent_left_child_and_right_child\n\n");

    Node leftChild  = {NULL,NULL,5};
    Node rightChild = {NULL,NULL,20};
	Node root       = {&leftChild,&rightChild,10};

    Stack stack;


    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    display_Expect(5);

    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);

    stackPush_Expect(&stack,&root);
    display_Expect(20);
    stackPop_ExpectAndReturn(&stack,&root);


    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");
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
    printf("test_binary_tree_with_4_nodes_parent_middle_left_and_right_child\n\n");

    Node leftChild  = {NULL,NULL,1};
    Node rightChild = {NULL,NULL,7};
    Node middle     = {&leftChild,&rightChild,5};
	Node root       = {&middle,NULL,10};

    Stack stack ;


    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);

    stackPush_Expect(&stack,&middle);
    display_Expect(1);

    stackPop_ExpectAndReturn(&stack,&middle);
    display_Expect(5);

    stackPush_Expect(&stack,&middle);
    display_Expect(7);

    stackPop_ExpectAndReturn(&stack,&middle);
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");

}

/**
 *               10
 *              /  \
 *             5    15
 *            / \
 *           1   7
 */
 void test_binary_tree_with_5_nodes_parent_leftmid_left_right_child_rightmid(void)
{
    printf("test_binary_tree_with_5_nodes_parent_leftmid_left_right_child_rightmid\n\n");

    Node leftChild  = {NULL,NULL,1};
    Node rightChild = {NULL,NULL,7};
    Node leftmid    = {&leftChild,&rightChild,5};
    Node rightmid   = {NULL,NULL,15};
	Node root       = {&leftmid,&rightmid,10};

    Stack stack ;


    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);

    stackPush_Expect(&stack,&leftmid);
    display_Expect(1);

    stackPop_ExpectAndReturn(&stack,&leftmid);
    display_Expect(5);

    stackPush_Expect(&stack,&leftmid);
    display_Expect(7);

    stackPop_ExpectAndReturn(&stack,&leftmid);
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);

    stackPush_Expect(&stack,&root);
    display_Expect(15);
    stackPop_ExpectAndReturn(&stack,&root);
    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");

}

/**
 *               10
 *              /  \
 *             5    15
 *                 / \
 *                13  20
 */
 void test_binary_tree_with_5_nodes_parent_leftmid_rightmid_rightleft_rightright(void)
{
    printf("test_binary_tree_with_5_nodes_parent_leftmid_rightmid_rightleft_rightright\n\n");

    Node rightleftChild  = {NULL,NULL,13};
    Node rightrightChild = {NULL,NULL,20};

    Node leftmid    = {NULL,NULL,5};
    Node rightmid   = {&rightleftChild,&rightrightChild,15};
	Node root       = {&leftmid,&rightmid,10};

    Stack stack ;


    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);
    display_Expect(5);

    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);

    stackPush_Expect(&stack,&root);

    stackPush_Expect(&stack,&rightmid);
    display_Expect(13);

    stackPop_ExpectAndReturn(&stack,&rightmid);
    display_Expect(15);

    stackPush_Expect(&stack,&rightmid);
    display_Expect(20);

    stackPop_ExpectAndReturn(&stack,&root);
    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");

}




/**
 *               10
 *              /  \
 *             5    15
 *            / \   / \
 *           1  7 13  20
 */
 void test_binary_tree_with_7_nodes_parent_leftmid_leftleft_leftright_child_rightmid_rightleft_rightright(void)
{
     printf("test_binary_tree_with_7_nodes_parent_leftmid_leftleft_leftright_child_rightmid_rightleft_rightright\n\n");

    Node leftleftChild  = {NULL,NULL,1};
    Node leftrightChild = {NULL,NULL,7};

    Node rightleftChild  = {NULL,NULL,13};
    Node rightrightChild = {NULL,NULL,20};

    Node leftmid    = {&leftleftChild,&leftrightChild,5};
    Node rightmid   = {&rightleftChild,&rightrightChild,15};
	Node root       = {&leftmid,&rightmid,10};

    Stack stack ;


    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack,&root);

    stackPush_Expect(&stack,&leftmid);
    display_Expect(1);

    stackPop_ExpectAndReturn(&stack,&leftmid);
    display_Expect(5);

    stackPush_Expect(&stack,&leftmid);
    display_Expect(7);

    stackPop_ExpectAndReturn(&stack,&leftmid);
    stackPop_ExpectAndReturn(&stack,&root);
    display_Expect(10);

    stackPush_Expect(&stack,&root);

    stackPush_Expect(&stack,&rightmid);
    display_Expect(13);

    stackPop_ExpectAndReturn(&stack,&rightmid);
    display_Expect(15);

    stackPush_Expect(&stack,&rightmid);
    display_Expect(20);

    stackPop_ExpectAndReturn(&stack,&root);
    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
    printf("\n______________________________________________________\n\n");

}


/**
 *               10
 *              /  \
 *             5    -
 *            / \
 *           1   -
 *          / \
 *         -   -
 */
void test_printLinear_given_3_nodes_parents_leftChild_left_grandChild()
{
    printf("test_printLinear_given_3_nodes_parents_leftChild_left_grandChild\n\n");


    Node leftgrandChild = {NULL,NULL,1};
	Node leftChild      = {&leftgrandChild,NULL,5};
    Node root           = {&leftChild,NULL,10};


    printLinear(&root);
    printf("\n______________________________________________________\n\n");

}

/**
 *               10
 *              /  \
 *             5    15
 *            / \   / \
 *           3  -  12
 *
 */
void test_binaryTreePrintInOrder_given_5_nodes_should_print_3_5_10_12_15()
{
    printf("test_binaryTreePrintInOrder_given_5_nodes_should_print_3_5_10_12_15\n\n");
    
    Node left_leftgrandChild    = {NULL,NULL,3};
    Node right_leftgrandChild   = {NULL,NULL,12};
    Node rightChild             = {&right_leftgrandChild,NULL,15};
	Node leftChild              = {&left_leftgrandChild,NULL,5};
    Node root                   = {&leftChild,&rightChild,10};


    binaryTreePrintInOrder(&root);
    printf("\n______________________________________________________\n\n");

}


