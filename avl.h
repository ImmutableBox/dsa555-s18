#include "arrqueue.h"
#include <iostream>
template <class T>
class AVL{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int height_;
		Node(const T& data,Node* lt=nullptr,Node* rt=nullptr){
			data_=data;
			left_=lt;
			right_=rt;
			height_=1;
		}
		int leftHeight() const{
			return left_?left_->height_:0;
		}
		int rightHeight() const{
			return right_?right_->height_:0;
		}
		int nodeBalance() const{
			return rightHeight() - leftHeight();
		}
		void updateHeight(){
			if(rightHeight() > leftHeight()){
				height_=rightHeight() + 1;
			}
			else{
				height_=leftHeight() + 1;
			}
		}
	};
	Node* root_;

	//insert data into subtree with root subroot
	void insert(const T& data, Node*& subroot){
		if(subroot == nullptr){
			subroot=new Node(data);
		}
		else{
			if(data < subroot->data_){
				insert(data,subroot->left_);
			}
			else{
				insert(data,subroot->right_);
			}
			if(subroot->nodeBalance() >= 2){
				//fix with rotation
			}
			else if(subroot->nodeBalance() <= -2){
				//fix with rotation
			}
			subroot->updateHeight();
		}
	}

	void leftRotate(Node*& A){
		Node* B=A->right_;
		Node* Y=B->left_;
		A->right_=Y;
		B->left_=A;
		A=B;

	}
	void rightRotate(Node*& A){

	}
	void printPreOrder(Node* subroot)const{
		if(subroot){
			std::cout << subroot->data_ << " ";		
			printPreOrder(subroot->left_);
			printPreOrder(subroot->right_);
		}
	}
	void printInOrder(Node* subroot)const{
		if(subroot){
			printInOrder(subroot->left_);
			std::cout << subroot->data_ << " ";
			printInOrder(subroot->right_);
		}
	}
	void destroy(Node* subroot){
		if(subroot){
			destroy(subroot->left_);
			destroy(subroot->right_);
			delete subroot;
		}
	}
public:
	AVL(){
		root_=nullptr;
	}
	void printPreOrder() const{
		printPreOrder(root_);
		std::cout << std::endl;
	}
	void printInOrder() const{
		printInOrder(root_);
		std::cout << std::endl;
	}
	void insert(const T& data){
		insert(data,root_);
	}

	bool exists(const T& data) const{
		bool rc=false;
		Node* curr=root_;
		while(curr && curr->data_ != data){
			if(data < curr->data_){
				curr=curr->left_;
			}
			else{
				curr=curr->right_;
			}
		}

		return (bool)curr;
	}

	void print() const{
		Queue<Node*> theNodes;
		if(root_){
			theNodes.enqueue(root_);
			while(theNodes.isEmpty()==false){
				Node* curr=theNodes.front();
				theNodes.dequeue();
				std::cout << curr->data_ << " ";
				if(curr->left_)
					theNodes.enqueue(curr->left_);
				if(curr->right_)
					theNodes.enqueue(curr->right_);
			}
			std::cout << std::endl;

		}
		else{
			std::cout << "tree is empty" << std::endl;
		}
	}
	~AVL(){
		destroy(root_);
	}
};

