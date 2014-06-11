#include "iostream"
typedef struct node  {
	struct node *left;
	struct node *right;
	int value;
}Node;
static Node rootNode ;
bool createRootNode()
{
	rootNode.left = (Node *)malloc(sizeof(Node));
	rootNode.right = (Node *)malloc(sizeof(Node));
	rootNode.left = &rootNode;
	rootNode.right = &rootNode;
	rootNode.value =10; 
	return true;
}
bool creatTree(unsigned int num)
{

}
int main()
{
	createRootNode();
	printf("%d",rootNode.right->value);
	getchar();
	
	return 0;
}