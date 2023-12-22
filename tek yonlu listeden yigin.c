#include <stdio.h>
#include <stdlib.h>

struct sll{
	int data;
	struct sll * next;
};

typedef struct sll node;
node*start=NULL;
node*getnode(){
	node * newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Data giriniz\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}

void push(node * newnode){
	node * temp;
	temp=start;
	if(temp==NULL){
		start=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

node * pop(){
	int sayac=0;
	int i;
	node * temp;
	node * tm;
	temp=start;
	tm=start;
	while(temp->next!=NULL){
		temp=temp->next;
		sayac++;
	}
	for(i=0;i<(sayac-1);i++){
		tm=tm->next;
	}
	tm->next=NULL;
	return temp;
}

void display(){
	node * temp;
	temp=start;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

int main() {
	int secim;
	node * newnode;
while(1){
menu:
	printf("_________________________________________________\n");
	printf("YIGINA ELEMAN EKLEME MENUSUNE HOS GELDINIZ\n");
	printf("_________________________________________________\n");
	printf("1-Yigina Eleman Ekleme\n");
	printf("2-Yigindan Eleman Cikarma\n");
	printf("3-Goruntule\n");
	printf("4-Cikis\n");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			newnode=getnode();
			push(newnode);
			break;
		case 2:
			newnode=pop();
			free(newnode);
			break;
		case 3:
			display();
			printf("\n");
			break;
		case 4:
			exit(0);
			break;
		default:
			goto menu;
			
	}
}
}
