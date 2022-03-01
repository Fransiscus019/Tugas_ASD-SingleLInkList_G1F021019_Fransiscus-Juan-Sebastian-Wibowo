#include<iostream>

using namespace std;

struct TV{
	string merek, jenis;
	int harga;
	
	TV *next;
	
};

TV *head, *tail, *cur, *newNode;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new TV();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

void addFirst(string merek, string jenis, int hrg){
	newNode = new TV();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	newNode->next = head;
	head = newNode;
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
	
	createSingleLinkedList("SAMSUNG", "LED", 5000000 );
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addFirst("LG", "Tabung", 3000000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
