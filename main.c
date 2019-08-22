#include <stdio.h>
#include <stdlib.h>
typedef struct Jobmarket{
    char name[100];
    char jobpost[100];
    double selary;
    int experience;
    float deadline;
    char jobtype[50];
    char location[100];
    int minage;
    int maxage;
    int vacancy;
    struct Jobmarket* next;
}jobs;
jobs* node;
typedef struct Head{
     int count;
     jobs* p;
}head;
head* ts;    //type definition of struct Head.
int year;    //global variable which can be used in all function of the code.
/*Creates node containing jobs information.*/
void create_node(){
      node =(jobs*)malloc(sizeof(jobs));
      printf("\nName of the company:\t");
      scanf("%s",node->name);
      printf("\nPost:\t\t\t");
      scanf("%s",node->jobpost);
      printf("\nSelary(tk):\t\t");
      scanf("%lf",&node->selary);
      printf("\nRecuired experience(year):\t");
      scanf("%d",&node->experience);
      printf("\nHow many days left:\t\t");
      scanf("%f",&node->deadline);
      printf("\nJob type:\t\t");
      scanf("%s",&node->jobtype);
      printf("\nLocation:\t\t");
      scanf("%s",&node->location);
      printf("\nMinimum age limit:\t\t");
      scanf("%d",&node->minage);
      printf("\nMaximum age limit:\t\t");
      scanf("%d",&node->maxage);
      printf("\nVacancy:\t\t");
      scanf("%d",&node->vacancy);
      node->next =NULL;
}
/*Inserts a node of job in the stack.*/
void push(){
      create_node();
      node->next = ts->p;
      ts->p =node;
      ts->count++;
}
/*Deletes a node of job in the stack.*/
void pop(){
        if(ts->p==NULL){
             printf("\nNO JOBS FOUND SORRY.\n");
             exit(0);
    }
    else{
          jobs* temp;
          temp =ts->p;
          ts->p =temp->next;
          free(temp);
          ts->count--;}
}
/*Displays all nodes of the stack of jobs.*/
void display(){
    jobs* temp;
   temp =ts->p;
   while(temp!=NULL){
        printf("\nName of the company:\t");
        printf("%s\n",temp->name);
        printf("\nPost:\t\t\t");
        printf("%s\n",temp->jobpost);
        printf("\nSelary:\t\t\t");
        printf("%.2lf tk\n",temp->selary);
        printf("\nRecuired experience:\t");
        printf("%d years\n",temp->experience);
        printf("\nDays left:\t\t");
        printf("%.2f days\n",temp->deadline);
        printf("\nJob type:\t\t");
        printf("%s\n",temp->jobtype);
        printf("\nLocation:\t\t");
        printf("%s\n",temp->location);
        printf("\nMinimum age limit:\t");
        printf("%d\n",temp->minage);
        printf("\nMaximum age limit:\t");
        printf("%d\n",temp->maxage);
        printf("\nVacancy:\t\t");
        printf("%d\n",temp->vacancy);
        printf("\n");
        printf(":::::::::::::::::::::::::::::::::\n");
        temp =temp->next;
    }
    printf("\n");
}
/*Counts number of nodes in the stack of jobs.*/
int count_node(){
    if(ts->count==0){
        printf("NO JOB FOUND SORRY\n");
        printf("++++++++++++++++++++++++++\n");
        exit(0);
    }
    else{
        jobs* temp;
        temp =ts->p;
        int c =1;
        while(temp->next!=NULL){
                  temp =temp->next;
                  c++;
    }
    printf("\n%d Jobs found\n",c);
    return c;}
}
typedef struct Applicants{
     char name[100];
     char dob[50];
     long int birthyear;
     float cgpa;
     int experiences;
     char email[100];
     char phone[100];
     char others[100];
     struct Applicants* next;
}cv;
cv* nodes;
typedef struct qHead{
      int count;
      struct qHead* front;
      struct qHead* rear;
}qhead;
qhead* tp;
/*Creates node for the queue containing applicants information.*/
void create_nodes(){
      nodes =(cv*)malloc(sizeof(cv));
      printf("Your name:\t");
      scanf("%s",nodes->name);
      printf("Date of birth:\t");
      scanf("%s",nodes->dob);
      printf("Your birthyear:\t");
      scanf("%ld",&nodes->birthyear);
      printf("Your cgpa:\t");
      scanf("%f",&nodes->cgpa);
      printf("Your exprience:\t");
      scanf("%d",&nodes->experiences);
      printf("Your email address:\t");
      scanf("%s",nodes->email);
      printf("Your phone number:\t");
      scanf("%s",nodes->phone);
      printf("Have you anything else?:\t");
      scanf("%s",nodes->others);
      nodes->next =NULL;
}
/*Insert node of applicants in the stack.*/
void enqueue(){
    if(tp->count ==0)
    {
        create_nodes();
        tp->front =nodes;
        tp->rear =nodes;
        tp->count++;
    }
    else
    {
        create_nodes();
        cv* temp1;
        temp1 =tp->front;
        while(temp1->next!=NULL)
        {
            temp1 =temp1->next;
        }
        temp1->next =nodes;
        tp->rear =nodes;
        tp->count++;
    }
}
/*Deletes a node of queue of applicants.*/
void dequeue(){
    if(tp->front==NULL)
    {
        printf("\nNo one to remove\n");
        exit(0);
    }
    else
    {
        cv* temp1;
        temp1 =tp->front;
        tp->front =temp1->next;
        free(temp1);
        tp->count--;
    }
}
/*Displays all nodes of the queue of applicants.*/
void display_queue(){
      cv* temp1;
      temp1 =tp->front;
      while(temp1!=NULL){
             printf("\nName :        %s\n",temp1->name);
             printf("Date of birth:  %s\n",temp1->dob);
             printf("Birthyear:      %ld\n",temp1->birthyear);
             printf("CGPA:           %.2f\n",temp1->cgpa);
             printf("Experience      %d\n",temp1->experiences);
             printf("Email:          %s\n",temp1->email);
             printf("Phone:          %s\n",temp1->phone);
             printf("Other:          %s\n",temp1->others);
            if(((temp1->birthyear>(year-node->minage))||(temp1->birthyear<(year-node->maxage)))||(node->experience>temp1->experiences))
            {
                    printf("\nSorry you'r rejected\n");
             }
            else
             {
                    printf("\nPlease check your mailbox\n");
            }
           printf("\n++++++++++++++++++++++++++++++\n");
           temp1 =temp1->next;
      }
      printf("\n");
}
/*Counts number of nodes in the queue of applicants.*/
void count_queue(){
     if(tp->count==0)
     {
          printf("NO APPLICANTS FOUND SORRY");
     }
    else
    {
          cv* temp1;
          temp1 =tp->front;
          int c =1;
          while(temp1->next!=NULL){
                temp1 =temp1->next;
                c++;
           }
          printf("\n%d APPLICANTS FOUND\n",c);
          return c;
    }
}


int main()
{
     printf("Current year\t");
     scanf("%d",&year);
     printf("\nNUMBERS OF REQUEST I'LL ACCEPT\n");
     int n=1,b;
     ts = (head*)malloc(sizeof(head));
     ts->count =0;
     ts->p =NULL;
     scanf("%d",&b);         // b takes request limit
     do{
             printf("Press 1 to accept request or 0 to decline\t");
             scanf("%d",&n);     //  n takes you want to accept request or not
             printf("\n");
             if(n==1)
                   push();
             if(n==0)
                   break;
    }while(ts->count!=b);
    int s=1;
    while(ts->count!=0){
          printf("Wanna delete any request?\t");
          scanf("%d",&s);          // s asks you do you want to delete request or not
          if(s!=0)
                 pop();
          else
                 break;
    }
   printf("*******************************\n");
   count_node();
   printf("==============================\n");
   display();
   printf("===============================\n");
   jobs* temp;
   temp =ts->p;
   while(temp!=NULL){
        printf("\nName of the company:\t");
        printf("%s\n",temp->name);
        printf("\nPost:\t\t\t");
        printf("%s\n",temp->jobpost);
        printf("\nSelary:\t\t\t");
        printf("%.2lf\n",temp->selary);
        printf("\nRecuired experience:\t\t");
        printf("%d years\n",temp->experience);
        printf("\nDays left:\t\t");
        printf("%.2f days\n",temp->deadline);
        printf("\nJob type:\t\t");
        printf("%s\n",temp->jobtype);
        printf("\nLocation:\t\t");
        printf("%s\n",temp->location);
        printf("\nMinimum age limit:\t");
        printf("%d\n",temp->minage);
        printf("\nMaximum age limit:\t");
        printf("%d\n",temp->maxage);
        printf("\nVacancy:\t\t");
        printf("%d\n",temp->vacancy);
        printf("\n");
        int m;
        tp =(qhead*)malloc(sizeof(qhead));
        tp->count =0;
        tp->front =NULL;
        tp->rear =NULL;
        if(temp->minage>temp->maxage){
                 printf("\nError, you cannot accept any request\n");
        }
        else{
           for(;;)                  //An infinite loop.
           {
               printf("Press 1 to accept applicant's request or 0 to decline\t");
               scanf("%d",&m);        //Asks for accept applicants request or not.
               printf("\n");
               if(m==1)
                     enqueue();
               if(m==0)
                      break;
           }
        }
        int k=1;
        while(tp->count!=0){
               printf("Wanna delete any request?\t");
               scanf("%d",&k);         //Asks for delete any request of applicant or not.
               if(k!=0)
                     dequeue();
               else
                      break;
        }
        printf("*******************************\n");
        display_queue();
        printf("==============================\n");
        count_queue();
        printf("===============================\n");
        temp =temp->next;
    }
    printf("\n");
    return 0;
}
