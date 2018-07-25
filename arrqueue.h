template <class T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	void grow(){
		T* tmp=new T[capacity_*2];
		for(int i=0;i<used_;i++){
			tmp[i]=theQueue_[i];
		}
		delete [] theQueue_;
		theQueue_=tmp;
		caacity_=capacity_*2;
	}
public:
	Queue(){
		theQueue_=new T[50];
		capacity_=50;
		used_=0;
	}
	void enqueue(const T& data){
		if(used_==capacity_){
			grow();
		}
		theQueue_[used_++]=data;
	}
	void dequeue(){
		if(!isEmpty()){
			used_--;
		}
	}
	T front() const{
		if(!isEmpty()){
			return theQueue_[used_-1];
		}
	}
	bool isEmpty() const{
		return used_==0;
	}	
};