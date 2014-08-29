#include "iostream"
#include "string"
using namespace std;
typedef struct node  {
	struct node *left;
	struct node *right;
	char value;
}Tree,*PTree;

PTree creatTree()
{
	char a ;
	PTree Node;
	scanf_s("%c",&a);
	if (a == '#'){
		Node = NULL;
	}
	else
	{
		
		Node = (PTree )malloc(sizeof(Tree));
		if (!Node)
		{
			exit(-1);
		}
	
		Node ->value = a;
		//printf("%c",a);
		Node ->left = creatTree();
		Node ->right = creatTree();
	}
	return Node;
}

//ÏÈĞò±éÀú¶ş²æÊ÷
void PreOrderTraverse(PTree T){
	if(T){
		printf("%c",T->value);
		PreOrderTraverse(T->left);
		PreOrderTraverse(T->right);
	}
}
int main()
{
	int a = 0;
	string str = "ie";
	str.append("kk");
	cout << str.begin() << "\n";
	//PTree T;
	//T = creatTree();
	//PreOrderTraverse(T);
	//scanf_s("%d",&a);
	//printf("%d\n",a);
	
	return 0;
}