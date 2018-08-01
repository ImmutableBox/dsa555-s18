#include "bst.h"
#include <iostream>
int main(void){
	BST<int> tree1;
	BST<int> tree2;
	int dataset[20]={20,10,30,15,5,50,45};
	for(int i=0;i<7;i++){
		tree1.insert(dataset[i]);
		tree2.insertRecursive(dataset[i]);
	}
	std::cout << "tree1 (non recursive insertion):" << std::endl;
	tree1.print();
	std::cout << "tree2 (recursive insertion):" << std::endl;
	tree2.print();

	std::cout << "tree1, inorder:" << std::endl;
	tree1.printInOrder();

	std::cout << "tree1, preorder:" << std::endl;
	tree1.printPreOrder();
	if(tree1.exists(5)){
		std::cout << "5 exists" << std::endl;
	}
	else{
		std::cout << "5 does not exist" << std::endl;
	}
	if(tree1.exists(55)){
		std::cout << "55 exists" << std::endl;
	}
	else{
		std::cout << "55 does not exist" << std::endl;
	}
	return 0;
}