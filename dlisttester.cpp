#include "dlist.h"
int main(void){
	DList<int> ll;
	ll.push_front(5);
	ll.push_front(4);
	ll.push_front(10);
	ll.print();
	return 0;
}