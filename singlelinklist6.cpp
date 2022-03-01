#include<iostream>

using namespace std;

struct TV{
	string merek, jenis;
	int harga;
	
	TV *next;
	
};

TV *head, *tail, *cur, *newNode,*del, *after;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new TV();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

int countSingleLinkedList(){
	cur = head;
	int NO = 0;
	while(cur != NULL){
		NO++;
		cur = cur->next;
	}
	return NO;
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

void removeMiddle(int posisi){
	if ( posisi < 1 || posisi > countSingleLinkedList() ){
		cout << "Posisi Diluar jangkauan " << endl;
	}else if( posisi == 1 || posisi == countSingleLinkedList() ){
		cout << "Posisi bukan posisi tengah " << endl;
	} else {
	int NO = 1;
	cur = head;
	while (NO <= posisi){
		if (NO == posisi -1){
			after = cur;
		}
		if (NO == posisi){
			del = cur;
		}
		cur = cur->next;
		NO++;
	}
	after->next = cur;
	delete del;
	}
}

void printSingleLinkedList(){
	cout << "Nomor data ada : " << countSingleLinkedList() << endl;
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
	
	addMiddle("LG", "Tabung", 3000000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeMiddle(2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
