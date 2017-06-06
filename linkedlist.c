#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
};

void printList(struct Node * root){
	while(root){
		if(root->next == NULL)cout << root->data << "--|";
		else cout << root->data << "->";
		
		root = root->next; 
	}
	cout << endl;
	return;
}

//Search an element in the list 
bool searchElement(struct Node * root,int element){
	while(root){
		if(root->data == element)return true;
		root = root->next;
	}
	return false;
}


//insert @ head of lis
void insertAtHead(struct Node ** root,int data){
	
	struct Node* tmp = (struct Node *)malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->next = NULL;
	if(*root == NULL){
		*root = tmp;
	}
	else{
		tmp->next = *root;
		*root = tmp;;
	}
}


//insertion at kth position
void insertAtK(struct Node ** root,int k,int data){
	struct Node* tmp = *root;
	while(k>1){
		if(!tmp)cout << "unavailable k" << endl;
		tmp = tmp->next;
		k--;
	}
	struct Node * X = (struct Node *)malloc(sizeof(struct Node));
	X->data = data;
	X->next = tmp->next;
	tmp->next = X;
}


//insert at tail
struct Node * insertAtEnd(struct Node *root,int data){
	struct Node * tmp = root;
	struct Node * X = (struct Node *)malloc(sizeof(struct Node));
	X->data = data;
	X->next = NULL;
	while(root->next){
		root = root->next;
	}
	root->next = X;
	return tmp;
}

//sorted order insertion
//return new root;
struct Node * sortedInsert(struct Node * root,int data){
	struct Node * head;
	head = root;
	struct Node * tmp = (struct Node *)malloc(sizeof(struct Node));
	tmp->data = data;
	tmp->next = NULL;
	if(!head){return tmp;}
	if(head->data > data){tmp->next = head;return tmp;}
	while(head->next && head->next->data < data)head = head->next;
	tmp->next = head->next;
	head->next = tmp;
	return root;
}

//##############################################################################################################
//##########################################///  SKIP M DLT N  ////#############################################


void skipMdeleteN(struct Node* root,int m,int n){
	struct Node * head = root,*t;
	while(head){
		int skip = m,dlt = n;

		//cout << "ptr @ : " << head->data << endl;
		for(int i=1;i<skip && head ;i++)head = head->next;
		if(!head)return;
		//cout << "ptr @ : " << head->data << endl;
		
		t = head->next;
		for(int i=1;i<=dlt && head;i++){
			
			struct Node * tmp = t;
			t = t->next;
			cout << "deleted :> " << tmp->data << endl;
			free(tmp);
		}
		head->next = t;
		
		cout << "ptr @ : " << head->data << endl;
		printList(root);
		head = t;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#########################################  REVERSAL  #########################################################

void reverse(struct Node ** root){
	struct Node *p=NULL,*c=*root;
	struct Node *n=c->next;
	while(n){
		c->next = p;
		p = c;c = n;
		n = c->next;
	}
	c->next = p;
	*root = c;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#########################################  Kth rotation  #########################################################
int lenList(struct Node *head){
    int len=0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

struct Node* rotateKright(struct Node * A,int B){ 
	int len = lenList(A);
    if(len == 1 || B%len == 0)return A;
    B = B%len;
    struct Node *newTail = A,*head = A,*newHead = A;
    struct Node *t = A;
    int x = len-B;
    while(x > 1){
        t = t->next;
        x--;
    }
    newHead = t->next;
    while(newTail->next)newTail = newTail->next;
    newTail->next = head;
    t->next = NULL;
    
    
    return newHead;
}


////##########################################################################################/////////////////
//										MERGESORT ON LIST 
////##########################################################################################/////////////////

struct Node * sortedMerge(struct Node * a,struct Node * b){
	if(!a)return b;
	if(!b)return a;

	struct Node * merged;

	if(a->data >= b->data){
		merged = b;
		merged->next = sortedMerge(a,b->next);
	}
	else{
		merged = a;
		merged->next = sortedMerge(a->next,b);
	}

	return merged;
}

void mergeSort(struct Node ** root){
	struct Node * head = *root;
	if(!head || !head->next)return;

	struct Node *firstHalf,*secondHalf;

	struct Node *fast=head,*slow=head;
	while(fast->next){
		fast = fast->next;
		if(fast->next){
			slow = slow->next;
			fast = fast->next;
		}
	}

	//slow points to midpoint
	firstHalf = head;
	secondHalf = slow->next;
	slow->next = NULL;//end of firstHalf

	mergeSort(&firstHalf);
	mergeSort(&secondHalf);

	*root = sortedMerge(firstHalf,secondHalf);

}

// ////##########################################################################################/////////////////
// //										QuickSort ON LIST 
// ////##########################################################################################/////////////////
// struct Node * getTail(struct Node * head){
// 	while(head->next)head=head->next;
// 	return head;
// }

// void deleteNode(struct Node ** root,struct Node ** del){
// 	struct Node * tmp = *root;
// 	while(tmp->next != NULL)tmp = tmp->next;
// 	if(!tmp){
// 		struct Node *x = tmp->next;
// 		tmp->next = tmp->next->next;
// 		free(x);
// 	}
// }

// struct Node* q_partition(struct Node *head,struct Node * tail){
// 	struct Node * pivot = tail;
// 	struct Node * iter = head;
// 	while(!iter->next->next){
// 		if(iter->data > pivot->data){
// 			struct Node * temp = iter;
// 			head = insertAtEnd(head,iter->data);
// 			deleteNode(&head,&iter);
// 		}
// 	}
// 	return pivot->next;
// }

// void quickSort(struct Node ** head,struct Node ** tail){
// 	while(head != tail){

// 		struct Node * part = q_partition(*head,*tail);
// 		quickSort(head,&part);
// 		quickSort(&(part->next),tail);
// 	}
// }




//######################################################################################################
				//		remove duplicates on unsorted list


//O(n^2) time O(1) space;  
void removeDup1(struct Node ** root){
	struct Node *head = *root;
	while(head->next){
		struct Node *ptr = head->next,*prev = head;
		while(ptr){
			if(ptr->data == head->data){
				struct Node *t = ptr;
				prev->next = ptr->next;
				//prev = prev->next;
				ptr = prev->next;
				free(t);
			}
			else{
				ptr = ptr->next;
				prev = prev->next;
			}
		}
		head = head->next;
	}
}

// O(n)time  O(n)space
void removeDup2(struct Node ** root){
	struct Node *head = *root;
	struct Node *prev = NULL;
	int n = lenList(head);
	//int occurance[];memset(occurance,0,sizeof(occurance));
	set <int> occurance;
	while(head){
		if(!occurance.insert(head->data).second){
			struct Node *t = head;
			prev->next = head->next;
			head = prev->next;
			free(t);
		}
		else{
			prev = head;
			head = head->next;
		}	
	}
}


//######################################################################################################
//							Kth from last Node
//######################################################################################################
int kfromLast(struct Node *head,int k){
	struct Node *header=head,*trailer=NULL;
	while(k > 1){
		header = header->next;
		k--;
	}
	trailer = head;
	//cout << header->next->data << " " << trailer->data << endl;
	while(header->next){
		trailer = trailer->next;
		header = header->next;
	}

	return trailer->data;
}



int main(){
	struct Node * root = NULL;
	insertAtHead(&root,9);
	insertAtHead(&root,4);
	insertAtHead(&root,3);
	insertAtHead(&root,2);

	//printList(root);
	
	insertAtK(&root,2,3);
	insertAtK(&root,4,14);

	//printList(root);

	root = insertAtEnd(root,31);
	root = insertAtEnd(root,32);

	root = sortedInsert(root,7);
	//printList(root);
	root = sortedInsert(root,3);
	//printList(root);
	root = sortedInsert(root,1);
	//printList(root);
	root = sortedInsert(root,8);
	//printList(root);
	root = sortedInsert(root,9);
	printList(root);

	//skipMdeleteN(root,2,2);
	//mergeSort(&root);

	//reverse(&root);
	//struct Node * tail = getTail(root);
	//quickSort(&root,&tail);
	//removeDup2(&root);

	//printList(root);

	cout << kfromLast(root,4) << endl;

	return 0;
}