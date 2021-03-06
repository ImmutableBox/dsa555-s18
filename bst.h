#include "arrqueue.h"
#include <iostream>
template <class T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data,Node* lt=nullptr,Node* rt=nullptr){
			data_=data;
			left_=lt;
			right_=rt;
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
		}
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
	BST(){
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
	void insertRecursive(const T& data){
		insert(data,root_);
	}

	void insert(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{

			Node* curr=root_;
			while(curr != nullptr){
				if(data < curr->data_){
					//go left
					if(curr->left_){
						curr=curr->left_;
					}
					else{
						curr->left_=new Node(data);
						curr=nullptr;
					}
				}	
				else{
					//go right
					if(curr->right_){
						curr=curr->right_;
					}
					else{
						curr->right_=new Node(data);
						curr=nullptr;
					}
				}
			}
			/*v1
			Node* previous=nullptr;
			Node* curr=root_;
			while(curr != nullptr){
				previous = curr;
				if(data < curr->data_){
					//go left
					curr=curr->left_;
				}	
				else{
					//go right
					curr=curr->right_;
				}
			}
			if(data < previous->data_){
				previous->left_=new Node(data);
			}
			else{
				previous->right_=new Node(data);
			}*/

		}

	}
	void remove(const T& remove);
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
	~BST(){
		destroy(root_);
	}
};

