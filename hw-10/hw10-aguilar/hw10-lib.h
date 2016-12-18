/*
    structure definitions
    #define statements
    function declarations
*/

struct node {
    char* word;
    int count;
    struct node* left;
    struct node* right;
};
struct node *addNode (char *s);
void insert(struct node *root, char *s);
void printTree(struct node *root);
void freeMem(struct node *root);
