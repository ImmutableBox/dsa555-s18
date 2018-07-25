template <class T>
class Stack{
	T* theStack_;
	int capacity_;
	int used_;
	void grow(){
		T* tmp=new T[capacity_*2];
		for(int i=0;i<used_;i++){
			tmp[i]=theStack_[i];
		}
		delete [] theStack_;
		theStack_=tmp;
		caacity_=capacity_*2;
	}
public:
	Stack(){
		theStack_=new T[50];
		capacity_=50;
		used_=0;
	}
	void push(const T& data){
		if(used_==capacity_){
			grow();
		}
		theStack_[used_++]=data;
	}
	void pop(){
		if(!isEmpty()){
			used_--;
		}
	}
	T top() const{
		if(!isEmpty()){
			return theStack_[used_-1];
		}
	}
	bool isEmpty() const{
		return used_==0;
	}	
};