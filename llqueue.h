#include "a1.h"
class Queue{
	DList theQueue_;

public:
	Queue(){}
	void enqueue(const T& data){
		theQueue_.push_front(data);
	}
	void dequeue(){
		if(!isEmpty())
			theQueue_.pop_back();
	}
	T front() const{
		if(!isEmpty()){
			return (*theQueue_.begin());
	}
	bool isEmpty(){
		return (theQueue_.begin() == theQueue_.end());
	}	
};