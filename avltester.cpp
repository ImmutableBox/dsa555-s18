#include "avl.h"
#include <iostream>
int main(void){
	AVL<int> tree1;
	AVL<int> tree2;
	int dataset[20]={10,20,30,40,50,60,70};
	for(int i=0;i<7;i++){
		tree1.insert(dataset[i]);
		tree2.insert(dataset[6-i]);
	}
//	tree1.print();

	std::cout << "tree1, inorder:" << std::endl;
	tree1.printInOrder();
	std::cout << "tree2, inorder:" << std::endl;
	tree2.printInOrder();

	std::cout << "tree1, preorder:" << std::endl;
	tree1.printPreOrder();
	std::cout << "tree2, preorder:" << std::endl;
	tree2.printPreOrder();
	if(tree1.exists(10)){
		std::cout << "10 exists" << std::endl;
	}
	else{
		std::cout << "10 does not exist" << std::endl;
	}
	if(tree1.exists(55)){
		std::cout << "55 exists" << std::endl;
	}
	else{
		std::cout << "55 does not exist" << std::endl;
	}
	return 0;
}