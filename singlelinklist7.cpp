#include<iostream>
using namespace std;
class Node{
public:
   int data;
   Node*next;
   Node(int d){
      data=d;
      Node*next= NULL;
   }
};
void insertAt(Node*&head, int data){
   Node*n= new Node(data);
   n->next= head;
   head= n;
}
bool searchSequential(Node*head,int key){
   if(head==NULL){
      return false;
   }
   if(head->data==key){
      return true;
   }
   else{
      return searchSequential(head->next, key);
   }
}
void printvalue(Node*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
int main(){
   Node*head= NULL;
   insertAt(head,5);
   insertAt(head,4);
   insertAt(head,3);
   insertAt(head,2);
   insertAt(head,1);
   printvalue(head);
   if(searchSequential(head,7)){
      cout<<"present"<<endl;
   }
   else{
      cout<<"Not Present"<<endl;
   }
}
