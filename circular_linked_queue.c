#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node *front=NULL,*rear = NULL;

void enQ(int x){
	struct node * tmp = (struct node *)malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = NULL;

	if(front == NULL){
		front = tmp;
		rear = tmp;
		rear->next = front;
	}
	else{
		rear->next = tmp;
		tmp->next = front;
		rear = tmp;
	}
}

int deQ(){
	if(front == NULL){cout << "empty Queue \n";return -1;}
	struct node *tmp = front;
	front = front->next;
	rear->next = front;
	int ans = tmp->data;
	free(tmp);
	return ans;
}

void display(){
	struct node *iter = front;
	cout << "|F| " ;
	while(iter->next != front){
		cout << iter->data << " | ";
		iter = iter->next;
	}
	cout << iter->data  << " --|R| "<< endl;
}

int main(){
	front = NULL;
	rear = NULL;
	// enQ(10);
	// enQ(20);
	// display();
	// enQ(30);
	// enQ(10);
	// display();
	// deQ();
	// display();
	// deQ();
	// display();
	// enQ(5);
	// display();
	string x="";
	while(true){
		cin >> x;
		if(!x.compare("exit")){cout << "ABORT INITIATED ..." << endl;break;}
		if(x[0] == 'E'){
			enQ(x[1]-'0');
			display(); 	
		}
		if(x[0] == 'D'){
			deQ();
			display(); 	
		}
	}

	cout << "Aborted." << endl;
	return 0;
}
