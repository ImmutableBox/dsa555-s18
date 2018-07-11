#include <iostream>
using namespace std;

template <class T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data,Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* first_;
	Node* last_;
public:
	DList(){
		first_ = nullptr;
		last_ = nullptr;
	}
	void push_front(const T& data){
		Node* nn= new Node(data,first_);
	
		if(last_==nullptr){
			last_=nn;
		}
		else{
			first_->prev_=nn;
		}
		first_=nn;


	}
	void push_back(const T& data){}
	void pop_front(){}
	void pop_back(){}
	void print() const{
		Node* i=first_;
		while(i!=nullptr){
			cout << i->data_ << " ";
			i=i->next_;
		}
		cout << endl;

	}
	~DList(){}
};