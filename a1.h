template <typename T>
class DList{
	struct Node{
		Node(const T& data=T{}, Node* next=nullptr, Node* prev=nullptr);
	};
public:
	class const_iterator{

	public:
		const_iterator();
		bool operator==(const_iterator rhs);
		bool operator!=(const_iterator rhs);
		const_iterator operator++(); 
		const_iterator operator++(int);  
		const_iterator operator--(); 
		const_iterator operator--(int);
		const T& operator*() const; 
	};
	class iterator:public const_iterator{
	public:
		iterator();
		T& operator*();  
		iterator operator++(); 
		iterator operator++(int);  
		iterator operator--(); 
		iterator operator--(int);  
	};
	DList();
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();	
	iterator insert(iterator loc, const T& data);
	void erase(iterator it);
	void erase(iterator first, iterator last);
	iterator search(const T& data);
	const_iterator search(const T& data) const;
	bool empty() const;
	int size() const;
	~DList();
	DList(const DList&);
	DList& operator=(const DList&);
	DList(DList&&);
	DList& operator=(DList&&);
};