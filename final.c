#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
//Global constants
#define BURGER 50
#define PIZZA 75
#define CUTLET 30
#define FRIEDRICE 100
#define BIRIYANI 150
#define NUGGETS 110
#define MAX 30
#define size 51
// Function Declaration
void mainm();
void entry();
void modify();
void delet();
void view();
void food();
struct node
{
 char food[MAX];
 struct node *next;
};
typedef struct node *NodePointer;
typedef NodePointer Node;
typedef NodePointer position;
Node CreateList();
void insertIntoLinkedList(char*, Node);
void displayLinkedList(Node);
Node order(Node);
int calc(Node head);
char cha[MAX],*p;
struct hoteldata
{
 char name[size][30];
 char nic[size][20];
 char rdate[size][12];
 char cdate[size][12];
};
struct hoteldata guest;
struct hoteldata1
{
char name[size][30], nic[size][20],rdate[size][12],cdate[size][12];
};
struct hoteldata1 guest1;
// Initializations
int li,lp,sr[size],dr[size],rno,i,e;
char rc,ch,choice,echoice,rchoice,temp[80],vchoice,mf,addn_room;
// Main Function
void main(void)
{
 clrscr();
 sr[0]=1;dr[0]=1;
 //Welcome Page
 for(li=10;li<71;li++)
 {
gotoxy(li,15);
delay(30);
printf("*");
 }
 for(li=70;li>=10;li--)
 {
gotoxy(li,22);
delay(30);
printf("*");
 }
 for(lp=16;lp<=21;lp++)
 {
gotoxy(10,lp);
delay(100);
printf("*");
 }
 for(lp=21;lp>=16;lp--)
 {
gotoxy(70,lp);
delay(100);
printf("*");
 }
 gotoxy(16,17);
 textcolor(WHITE);
 printf("Press Any Key To ..........Continue :");
 getch();
 mainm();
}
//End of Main Function
//Main Menu Function
void mainm(void)
{
 clrscr();
 gotoxy(15,10);
 textcolor(LIGHTGRAY);
 cprintf("Press the corresponding Keys for the desired action");
 gotoxy(17,12);
 textcolor(BROWN);
 cprintf("C: CheckIn");
 gotoxy(17,14);
 textcolor(LIGHTMAGENTA);
 cprintf("V: Room Status");
 gotoxy(17,16);
 textcolor(LIGHTBLUE);
 cprintf("M: Modification");
 gotoxy(17,18);
 textcolor(LIGHTRED);
 cprintf("O: CheckOut");
 gotoxy(17,20);
 textcolor(BLUE);
 cprintf("F:Food");
 textcolor(LIGHTGREEN);
 gotoxy(17,22);
 cprintf("Q:Quit");
 textcolor(GREEN);
 gotoxy(17,24);
 cprintf("Make your choice");
 textcolor(WHITE);
 choice=getch();
 switch(choice)
 { // Choice Switch Begin
case 'C': entry();
case 'V': view();
case 'M': modify();
case 'O': delet();
case 'F': food();
case 'Q': exit(0);
default:
{ //Choice Default
 gotoxy(33,40);
 printf("\n\nInvalid choice");
 getch();
 mainm();
} //Choice Default End
 } //End of switch case
} //End of main menu
void entry(void) //Data Entry function
{
 clrscr();
 printf("Do You Want To reserve A Room? (Y/N) :");
 echoice=getch();
 switch(echoice) // Echoice Switch Begin
 {
case 'Y':
{ // Case 'Yes'
 printf("\n\nEnter S for Single Room or D for Double Room\n\n");
 rchoice=getch();
 switch(rchoice) // RoomType choice Switch
 {
case 'S': // Case Single Room
{
 for(i=1;i<size;i++) //Move i to the next available room
 if(sr[i]==0)
 {
clrscr();
sr[i]=1;
printf("\n\nRoom No : %d Is available For Reservation",i);
printf("\n\nEnter Occupant's Name :");
gets(guest.name[i]);
printf("\n\nEnter Occupant's Aadhaar Number :");
gets(guest.nic[i]);
printf("\n\nEnter Check In Date :");
gets(guest.rdate[i]);
printf("\n\nEnter Check Out Date :");
gets(guest.cdate[i]);
printf("\n\n\n\nDo You Want To Reserve Another Room? Y/N :");
addn_room=getch();
switch (addn_room)
{ //Additional Room choice
 case 'Y':
 entry();
 case 'N':
 mainm();
 default:
 {
printf("\n\nInvalid choice");
getch();
mainm();
 }
} // AdditionalRoom Switch End
 }
} //End of single room case
case 'D': //Case Double Room
{
 for(i=1;i<size;i++)
 if(dr[i]==0)
 {
clrscr();
dr[i]=1;
printf("\n\nRoom No : %d Is available For Reservation",i);
printf("\n\nEnter Occupant's Name :");
gets(guest1.name[i]);
printf("\n\nEnter Occupant's Aadhaar Number :");
gets(guest1.nic[i]);
printf("\n\nEnter Check In Date :");
gets(guest1.rdate[i]);
printf("\n\nEnter Check Out Date :");
gets(guest1.cdate[i]);
printf("\n\n\n\nDo You Want To Reserve Another Room? Y/N :");
addn_room=getch();
switch (addn_room)
{
 case 'Y': entry();
 case 'N': mainm();
 default:
 {
printf("\n\nInvalid choice");
getch();
mainm();
 }
}
 }
} //End case of Double Room
default: // Rchoice Default
{
 printf("\n\nInvalid choice");
 getch();
 mainm();
}
 }
} //End Case 'YES' for reserving room
case 'N': // Case 'NO'
{
 mainm(); //Redirect to Main Menu
}
default:
{
 printf("\n\nInvalid choice");
 getch();
 mainm();
}
 } // End of Entry choice switch
} //Data Entry Function End
// View Data Function
void view(void)
{
 clrscr();
 printf("Press S for Sequential Display of the room status\n\nPress R for Manual Check Of Room Status\n\n");
 vchoice=getch();
 switch(vchoice)
 {
case 'S':
{ //Case 'sequential'
 clrscr();
 printf("R.No.\tName\tAadhaar Number\tCheck In\tCheck Out\n");
 for(i=1;i<size;i++) //Loop through all booked single rooms
 {
if(sr[i]==1)
{

printf("\n%d\t%s\t%s\t%s\t%s\n",i,guest.name[i],guest.nic[i],guest.rdate[i],guest.cdate[i]);
}
 }
 printf("\n\n\nPress Any Key For Double Room Status:\n\n");
 getch();
 clrscr();
 printf("R.No.\tName\tAadhaar Number\tCheck In\tCheck Out\n");
 for(i=1;i<size;i++) //Loop through all booked single rooms
 {
if(dr[i]==1)
{

printf("\n%d\t%s\t%s\t%s\t%s\n",i,guest1.name[i],guest1.nic[i],guest1.rdate[i],guest1.cdate[i]);
}
 }
 printf("\n\n\nPress Any Key To Return To The Main Menu\n\n");
 getch();
 mainm();
} //End of 'sequential' case
case 'R': //Case 'Manual Check'
{
 clrscr();
 printf("Enter The Room Number That Needs To Be Checked For Occupancy\n\n");
 gets(temp);
 rno=atoi(temp);
 if(rno<1 || rno >51) //Check if room number exceeds limit
 {
printf("\n\nRoom Number Out of bounds");
getch();
mainm();
 }
 else
 {
if(sr[rno]==1) //Check if single room booked
{
 printf("\n\nSingle Room No %d Is Reserved",rno);
 printf("\n\nOccupant's Name : %s \n\nOccupant's Aadhar Number : %s\n\nCheck In Date : %s\n\nCheck Out Date : %s\n\n",guest.name[rno],guest.nic[rno],guest.rdate[rno],guest.cdate[rno]);
}
else
{
 printf("\n\nSingle Room No %d is Vacant",rno);
 getch();
}
if(dr[rno]==1) //Check if double room booked
{
 printf("\n\nDouble Room No %d Is Reserved",rno);
 printf("\n\nOccupant's Name : %s \n\nOccupant's Aadhar Number : %s \n\nCheck In Date : %s\n\nCheck Out Date : %s\n\n",guest1.name[rno],guest1.nic[rno],guest1.rdate[rno],guest1.cdate[rno]);
 printf("\n\nPress Any Key To Return To The Main Menu");
 getch();
 mainm();
}
else
{
 printf("\n\nDouble Room No %d is Vacant",rno);
 getch();
 mainm();
}
 } // Falsified Limit End
} //Vchoice Case R End
default:
{
 printf("\n\nInvalid Choice");
 getch();
 mainm();
}
 } // Vchoice Switch End
} // Data View Function End
//Modify Function
void modify(void)
{
 clrscr();
 printf("\t\t\t\tData Modification\n\n\n");
 printf("Enter The Room Number To Be Modified\n");
 gets(temp);
 rno=atoi(temp);
 if(rno<1 || rno >51) // Room Number Limit Check
 {
printf("\n\nRoom number out of bounds");
getch();
mainm();
 }
 else
 {
printf("Enter S For Single Room / D For Double Room\n");
rc=getch();
switch(rc)
{
 case 'S':
 {
if(sr[rno]==1) //Check if single room is reserved
{
 clrscr();
 printf("\n\nSingle Room No %d Is Reserved",rno);
 printf("\n\nOccupant's Name : %s \n\nOccupant's Aadhar Number :%s \n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n",guest.name[rno],guest.nic[rno],guest.rdate[rno],guest.cdate[rno]);
 printf("\n\nPress N : Change Of Name\nI : Change In Aadhar\nR :Check In Date\nO : Check Out Date\n\n");
 mf=getch();
 switch(mf)
 {
case 'N':
{
 printf("\n\nEnter New Name\n");
 gets(guest.name[rno]);
 getch();
 mainm();
}
case 'I':
{
 printf("\n\nEnter New Aadhar Number\n");
 gets(guest.nic[rno]);
 getch();
 mainm();
}
case 'R':
{
 printf("\n\nEnter New Check In Date\n");
 gets(guest.rdate[rno]);
 getch();
 mainm();
}
case 'O':
{
 printf("\n\nEnter New Check Out Date\n");
 gets(guest.cdate[rno]);
 getch();
 mainm();
}
default:
{
 printf("\n\nInvalid Entry");
 getch();
 mainm();
}
 }
}
else //If single room not reserved
{
 printf("\n\nSingle Room No %d is Vacant",rno);
 getch();
 mainm();
}
 }
 case 'D':
 {
if(dr[rno]==1) //Check if double room booked
{
 clrscr();
 printf("\n\nDouble Room No %d Is Reserved",rno);
 printf("\n\nOccupant's Name : %s \n\nOccupant's Aadhar Number :%s \n\nCheck In Date : %s\n\nCheck Out Date : %s \n\n",guest1.name[rno],guest1.nic[rno],guest1.rdate[rno],guest1.cdate[rno]);
 printf("\n\nPress N : Change Of Name\nI : Change In Aadhar\nR : Check In Date\nO : Check Out Date\n\n");
 mf=getch();
 switch(mf)
 {
case 'N':
{
 printf("\n\nEnter New Name\n");
 gets(guest1.name[rno]);
 getch();
 mainm();
}
case 'I':
{
 printf("\n\nEnter New Aadhar Number\n");
 gets(guest1.nic[rno]);
 getch();
 mainm();
}
case 'R':
{
 printf("\n\nEnter New Check In Date\n");
 gets(guest1.rdate[rno]);
 getch();
 mainm();
}
case 'O':
{
 printf("\n\nEnter New Check Out Date\n");
 gets(guest1.cdate[rno]);
 getch();
 mainm();
}
default:
{
 printf("\n\Invalid choice");
 getch();
 mainm();
}
 }
}
else //If double room is not reserved
{
 printf("\n\nDouble Room No %d is Vacant",rno);
 getch();
 mainm();
}
 }
 default:
 {
printf("\n\n\nInvalid choice");
getch();
mainm();
 }
} //End case for double room
 }
} //Modify Function End
//Delete Function
void delet(void)
{
 clrscr();
 printf("Enter The Room Number To Vacate\n");
 gets(temp);
 rno=atoi(temp);
 if(rno<1 || rno >51) //Room Limit Check
 {
printf("\n\nInvalid Room Number");
getch();
mainm();
 }
 else
 {
printf("\n\nSingle Or Double Room? (S/D) :");
rc=getch();
switch(rc)
{
 case 'S': //Case 'Single'
 {
sr[rno]=0;
printf("\n\nRoom Vacated");
printf("\n\nPress Any Key To Exit To The Main Menu");
getch();
mainm();
 }
 case 'D': //Case 'Double'
 {
dr[rno]=0;
printf("\n\nRoom Vacated");
printf("\n\nPress Any Key To Exit To The Main Menu");
getch();
mainm();
 }
 default:
 {
printf("\n\nInvalid choice");
getch();
mainm();
 }
}
 }
} // Delete Function End
void food()
{
Node head = CreateList();
clrscr();
printf("\nWELCOME TO FOODIE CORNER,");
printf("MAY I TAKE YOUR ORDER!!!!\n\n");
order(head);
displayLinkedList(head);
printf("\nTOTAL COST: %d\n",calc(head));
printf("THANK YOU VISIT AGAIN!!!\n");
getch();
mainm();
}
Node order(Node head)
{
 int choic;char c;
 printf("************************* \n");
 printf("%13s\n","MENU");
 printf("************************* \n");
 printf("ID");
 printf("%10s","NAME");printf("%13s","RATE");
 printf("\n*************************");
printf("\n1.\tBURGER %d \n", BURGER);
printf("2.\tPIZZA %d \n", PIZZA);
printf("3.\tCUTLET %d \n", CUTLET);
printf("4.\tFRIED RICE %d \n", FRIEDRICE);
printf("5.\tBIRIYANI %d \n", BIRIYANI);
printf("6.\tNUGGETS %d \n", NUGGETS);
printf("7.\tExit\n\n");
printf("ENTER AN ITEM ID: ");
scanf("%d", &choic);
 switch(choic){
case 1:
strcpy(cha,"BURGER\t50");
break;
case 2:
strcpy(cha,"PIZZA\t\t75");
break;
case 3:
strcpy(cha,"CUTLET\t30");
break;
case 4:
 strcpy(cha,"FRIED RICE\t100");
break;
case 5:
strcpy(cha,"BIRIYANI\t150");
break;
case 6:
strcpy(cha,"NUGGETS\t110");
break;
case 7:
printf("ThanK you for ordering! \n");
mainm();
break;
default:
printf(" Error: This is not on the menu. \n");
break;
}
p=&cha[0];
insertIntoLinkedList(p,head);
printf("WANT TO ORDER MORE ????(Y/N):");
 printf("\n");
c=getch();
if(c=='Y')
 {
order(head);
 }
return head;
}
Node CreateList()
{
 Node head = (struct node*)malloc(sizeof(struct node));
 head->next = NULL;
 return head;
}
int calc(Node head)
{
 int amount=0;
 position temp = head->next;
while (temp != NULL)
{
if(strcmp(temp->food,"BURGER\t50")==0)
amount+=BURGER;
else if(strcmp(temp->food,"PIZZA\t\t75")==0)
amount+=PIZZA;
else if(strcmp(temp->food,"CUTLET\t30")==0)
amount+=CUTLET;
else if(strcmp(temp->food,"FRIED RICE\t100")==0)
amount+=FRIEDRICE;
else if(strcmp(temp->food,"BIRIYANI\t150")==0)
amount+=BIRIYANI;
else if(strcmp(temp->food,"NUGGETS\t110")==0)
amount+=NUGGETS;
temp=temp->next;
 }
 return amount;
}
void insertIntoLinkedList(char *word2, Node head)
{
 position TmpCell;
 TmpCell = (struct node*)malloc(sizeof(struct node));
 if( TmpCell == NULL )
 printf( "Out of space!!!" );
 strcpy(TmpCell->food,word2);
 while (head->next!=NULL)
{
head= head->next;
}
 TmpCell->next = head->next;
 head->next = TmpCell;
}
void displayLinkedList(Node head)
{
 position temp=head->next;
 i=1;
 printf("\nORDERED ITEMS: \n");
 if(head==NULL)
 printf("empty");
 else
 {
while (temp != NULL)
{
printf("%d.%s\n",i,temp->food);
temp=temp->next;
i++;
 }
 }
}
// END OF PROGRAM