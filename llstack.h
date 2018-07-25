#include "a1.h"
template <class T>
class Stack{
	DList theStack_;

public:
	Stack(){}
	void push(const T& data){
		theStack_.push_front(data);
	}
	void pop(){
		if(!isEmpty())
			theStack_.pop_front();
	}
	T top() const{
		if(!isEmpty()){
			return (*theStack_.begin());
	}
	bool isEmpty(){
		return (theStack_.begin() == theStack_.end());
	}	
};