#include "bst.h"
int main(void){
	BST<int> tree1;
	BST<int> tree2;
	int dataset[20]={20,10,30,15,5,50,45};
	for(int i=0;i<7;i++){
		tree1.insert(dataset[i]);
		tree2.insertRecursive(dataset[i]);
	}
	return 0;
}