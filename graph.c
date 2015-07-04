#include<stdio.h>
struct vertex {
    char value;
    struct vertex *next; 
   
};
typedef struct vertex Vertex;

 Vertex *head;
 Vertex *tail;
Vertex *v1;
Vertex *v2;
struct edge{
 
char user1;
char user2;
  struct edge *next;
  
};
typedef struct edge Edge;
Edge *head1;
Edge *tail1;
char value1;
main()
{
char user1;
char user2;   
    
int choice;

	
	while(1) {
		printf("What do you want to do?\n\n");
		printf("1. Insert a user \n2. Insert a friendship \n3. To show friendship \n4. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				
				insertuser();
				printf("\nInserted the user %c into linkedList\n", value1); 
				break;
			case 2:
				printf("\nEnter the First user name for friendship!!\n");
              fflush(stdin);
              scanf("%c",&user1);
              printf("\nEnter the Second user name for friendship!!\n");
              fflush(stdin);
              scanf("%c",&user2);
				insertfri(user1,user2);
				printf("\nFriendship is built between %c and %c\n",user1,user2); 
				break;
			case 3:
				
				display();
                break;
            
           case 4:
                printf("\nExiting...\n"); 
                  exit(0);   
			default:
				break;
		}
	}
}

void insertuser()
{
    
    printf("\nEnter the user name!!\n");
    fflush(stdin);
    scanf("%c", &value1);
    
    if(head == NULL) {
		head = (Vertex *)malloc(sizeof(Vertex));
		head->value = value1;
		head->next = NULL;
		tail = head;
	} else {
		tail->next = (Vertex *)malloc(sizeof(Vertex));
		tail->next->value = value1;
		tail->next->next = NULL;
		tail = tail->next;
	}

}

void insertfri(char user1, char user2)
{
   printf("You Entered Users %c, %c\n", user1, user2);
    check(user1, user2);
    
    
   if(head1 == NULL) {
		head1 = (Edge *)malloc(sizeof(Edge));
		head1->user1 = user1;
       head1->user2 = user2;
		head1->next = NULL;
		tail1 = head1;
	} else {
		tail1->next = (Edge *)malloc(sizeof(Edge));
		tail1->next->user1 = user1;
       tail1->next->user2 = user2;
		tail1->next->next = NULL;
		tail1 = tail1->next;
	} 
    

}
void display()
{
    
int i;
     Edge *im;
     
    im=head1;
    if (head1==NULL)
    {
        printf("Linklist is empty\n");
    }
   
    else
    {
        printf ("\n The status of the Friendshi is \n");
       
        
            while(im->next!=NULL)
            {
           
                
                printf ("%c , %c \n",im->user1,im->user2);
                im=im->next;
                
        
            }
            printf ("%c , %c \n",im->user1,im->user2);
            return;
        
    }
}

void check(char user1, char user2)
{
int temp=0;
int temp1=0;
char choice2;
v1=v2=head;
while(v1!=NULL)    
{
    if (v1->value != user1){
        v1=v1->next;
    temp=1;}
    else{
        temp=0;
    break;}
    }
if(temp==1)
{
printf("User %c not found. Do you want to insert? (Y/N)\n", user1);
fflush(stdin);
scanf("%c", &choice2);
if(choice2=='Y'||choice2=='y')
    insertuser();
    else 
        main();
    
  
}
    
while(v2!=NULL)    
{
    if (v2->value != user2){
        v2=v2->next;
    temp1=1;}
    else{
        temp1=0;
    break;}
    }
if(temp1==1)
{
printf("User %c not found. Do you want to insert? (Y/N)\n", user2);
fflush(stdin);
scanf("%c", &choice2);
if(choice2=='Y'||choice2=='y')
    insertuser();
    else 
    main();
  
}
}