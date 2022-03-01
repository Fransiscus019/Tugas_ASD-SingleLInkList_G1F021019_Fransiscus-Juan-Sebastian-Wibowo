#include<iostream>

using namespace std;

struct TV{
	string merek, jenis;
	int harga;
	
	TV *next;
	
};

TV *head, *tail, *cur, *newNode, *del;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new TV();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

void addLast(string merek, string jenis, int hrg){
	newNode = new TV();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	newNode->next = NULL;
	tail->next = newNode;
	tail=newNode;
}

void removeLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail= cur;
	tail->next =NULL;
	delete del;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Merek TV : "<< cur->merek <<endl;
		cout << "Jenis TV : "<< cur->jenis <<endl;
		cout << "Harga TV : "<< cur->harga <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("SAMSUNG", "LED", 5000000);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addLast("POLYTRON", "Tabung", 3000000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeLast();
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
