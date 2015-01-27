/*
 * Name:    Jonathan Bedard and Giovanni Briggs
 * Date:    1/21/14
 * Class:   COEN 70L Tuesday 2:15pm
 * Lab:     3
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;
class List {
public:
	List();
	~List();
	List(const List&);
	const List& operator=(const List&);
	friend ostream& operator<<(ostream&, const List&);
	void insert(const int&);
	class node {
	public:
		node(int, node*);
		int data;
		node* next;
	};
private:
	node * list;
	int size;
	node* cursor;
};
//node constructor
List::node::node(int i, node* n) {
	data = i;
	next = n;
}
//default constructor
List::List() {
	list = new node(0,NULL);
	size = 0;
	cursor = list;
}
//destructor
List::~List() {
	cursor = list->next;
	while(cursor != NULL) {
		delete list;
		list = cursor;
		cursor = list->next;
	}
}
//copy constructor
List::List(const List& l) {
    node* cursTemp;
	cursTemp = l.list->next;
	list = new node(0,NULL);
    cursor = list;
	size = 0;
	while(cursTemp != NULL) {
		cursor->next = new node(cursTemp->data, NULL);
		cursor=cursor->next;
        cursTemp=cursTemp->next;
	}
    size = l.size;
}

//assignment operator
const List& List::operator= (const List& l) {
	list = l.list;
	size = l.size;
	return l;
}
//print operator
ostream& operator <<(ostream & out, const List& l) {
	List print;
    print.cursor = l.list->next;
    while(print.cursor != NULL) {
		out << print.cursor->data << ", ";
		print.cursor = print.cursor->next;
	}
	out <<endl;
	return out;
}
//insert at end of list
void List::insert(const int & i ){
    cursor=list;
    //get to end of list
    while(cursor->next != NULL){
        cursor=cursor->next;
    }
    //insert
    cursor->next = new node (i, NULL);
    size++;
}
#endif
