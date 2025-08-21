#include "ListNodes.h"
#include <stdlib.h>
#include <stdio.h>

_Bool debug = 0;

void Set_Debug(_Bool setter) {
    debug = setter;
}

void Add_Node_To_List(struct Listnode** HEAD, int data) {
    struct Listnode *next_node = (struct Listnode*)malloc(sizeof(struct Listnode)*1);
    next_node->node = data;
    if (debug) printf("- Adding: \n=> next_node_data=%d\n", next_node->node);
    next_node->nextnode = *HEAD;
    *HEAD = next_node;
    printf(":: Next node: %d added\n", data);
}

// struct Listnode* 
struct Listnode* Add_Node_To_List_Returns(struct Listnode* HEAD, int data) {
    struct Listnode *next_node = (struct Listnode*)malloc(sizeof(struct Listnode)*1);
    if (debug) printf("- Before addition: \n=> currnode_data=%d\n", HEAD->node);
    next_node->node = data;
    if (debug) printf("- Adding: \n=> next_node_data=%d\n", next_node->node);
    next_node->nextnode = HEAD;
    HEAD = next_node;
    if (debug) printf("- After Addition: \n=> currnode_data=%d\n=> nextnode_data=%d\n", HEAD->node, HEAD->nextnode->node);
    printf(":: Next node: %d added\n", HEAD->node);
    return HEAD;
}

void Remove_from_Node_List(struct Listnode** HEAD, int index) {
    struct Listnode *curr_node = *HEAD;
    struct Listnode *prev_node;
    for (int i = 0; i < index; i++) {
        if (i == index-1) {
            prev_node = curr_node;
            printf("- Previous node:\nprev_node=%d\n", prev_node->node);
            continue;
        }
        if (i ==  index) {
            curr_node->nextnode = prev_node;
            printf("- Updated node:\ncurr_next_node=%d\n", curr_node->nextnode->node);
        }
        curr_node = curr_node->nextnode;
    }
    *HEAD = curr_node;
    printf(":: Removed Node at %d\n", index);
}

void Loop_Node_List(struct Listnode* HEAD) {
    printf(":: Looping over the list\n");
    int i = 1;
    struct Listnode *curr_node = HEAD;
    while (curr_node != NULL) {
        int node_data = curr_node->node;
        printf("Node %d: %d\n", i, node_data);
        curr_node = curr_node->nextnode;
        i++;
    }
}