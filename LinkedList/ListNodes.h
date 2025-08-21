#ifndef ListNodes_H_
#define ListNodes_H_

struct Listnode{
    int node;
    struct Listnode *nextnode;
};

void Set_Debug(_Bool setter);
void Add_Node_To_List(struct Listnode** HEAD, int data);
struct Listnode* Add_Node_To_List_Returns(struct Listnode* HEAD, int data);
void Remove_from_Node_List(struct Listnode** HEAD, int index);
void Loop_Node_List(struct Listnode* HEAD);

#endif