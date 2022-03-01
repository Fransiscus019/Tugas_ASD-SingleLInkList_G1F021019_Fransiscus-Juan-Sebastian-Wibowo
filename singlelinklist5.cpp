#include<iostream>

using namespace std;

struct TV{
	string merek, jenis;
	int harga, posisi;
	
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

void addMiddle(string merek, string jenis, int hrg, int posisi){
	newNode = new TV();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	
	cur = head;
	int NO = 1;
	while(NO < posisi - 1 ){
		cur = cur->next;
		NO++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;
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
	
	addFirst("POLYTRON", "Tabung", 3000000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("SHARP", "LED", 6000000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
