/*
 * main.c
 *
 *  Created on: Jul 26, 2023
 *      Author: shim
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
	non,
	slot1,
	slot2,
	slot3,
	slot4,
	slot5
}slot;
struct patian
 {
  char Name[100];
  int age;
  char gender;
  int ID;
  slot reserve_slot;
  struct N *Next;
 };
 /* Initialize nodes */
struct patian *head;
/*global variable*/
int reserveslot[5]={0,0,0,0,0};
char password[5] = "1234";
/*funcations prototype*/
void adminMode();
void userMode();
void Add_new_patient_record();
int search_ID_Entered(int item);
void Edit_patient_record();
void reserveSlot();
void viewPatientRecord();
void cancelReservation();
void viewTodayReservations();


int main(){
    int mode=0;

    printf("Welcome to the Clinic Management System\n");
    printf("Choose mode:\n");
    printf("1. Admin Mode\n");
    printf("2. User Mode\n");
    scanf("%d", &mode);
    if (mode == 1) {
        adminMode();
    } else if (mode == 2) {
        userMode();
    } 
    else {
        printf("Invalid mode choice. Exiting...\n");
    }

    return 0;
}
void adminMode(){
   char enteredPassword[5];
   int choice;
    printf("Enter password: ");
    scanf("%s", enteredPassword);

    if (strcmp(enteredPassword, password) == 0) {
        printf("Login successful. Welcome Admin!\n");


        do {
            printf("\nAdmin Mode Menu:\n");
            printf("1. Add new patient record\n");
            printf("2. Edit patient record\n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation\n");
            printf("5. Exit Admin Mode\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    Add_new_patient_record();
                    break;
                case 2:
                    Edit_patient_record();
                    break;
                case 3:
                    reserveSlot();
                    break;
                case 4:
                    cancelReservation();
                    break;
                case 5:
                    printf("Exiting Admin Mode...\n");
                    return;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        } while (1);

    }
    else {
        printf("Incorrect password\n");

        }
    }




void userMode(){
    int choice;

    do {
        printf("\nUser Mode Menu:\n");
        printf("1. View patient record\n");
        printf("2. View today’s reservations\n");
        printf("3. Exit User Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewPatientRecord();
                break;
            case 2:
                viewTodayReservations();
                break;
            case 3:
                printf("Exiting User Mode...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
}
/*sub funcations*/
void Add_new_patient_record()
{
    struct patian *ptr,*temp;
    int gender_type;
    int id;
    int flg;
    ptr = (struct patian*)malloc(sizeof(struct patian));

    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
 printf ("\nEnter patient ID");
 scanf ("%d", &id);
flg=search_ID_Entered(id);
if(flg){
   ptr->ID=id;
printf ("Enter patient Name\n");
 scanf ("%s", &ptr->Name);
  printf ("\nEnter patient age\n");
  scanf ("%d", &ptr->age);
  printf ("\nEnter patient gender type \n male 0\n female 1\n");
  scanf ("%d", &gender_type);
  if(gender_type)
  {
    ptr->gender="F";
  }
  else
  {
    ptr->gender="M";
  }

        if(head == NULL)
        {
            ptr -> Next = NULL;
            head = ptr;
            printf("\nnew patient recorded");
        }
        else
        {
            temp = head;
            while (temp -> Next != NULL)
            {
                temp = temp -> Next;
            }
            temp->Next = ptr;
            ptr->Next = NULL;
            printf("\nnew patient recorded");

        }
    }
    else
    {
     printf("\nThe entered ID is already exists");}
    }
}
int search_ID_Entered(int item)
{
    struct patian *ptr;
    int i=0,flag=0;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        while (ptr!=NULL)
        {
           if(ptr->ID == item)
            {

                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
            i++;
            ptr = ptr -> Next;
        }
    }
 return   flag;
}
void Edit_patient_record(){
    struct patian *ptr;
    int id,i=0,flag;
     int edit,gender_type,f;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
    printf ("\nEnter patient ID");
     scanf ("%d", &id);
        while (ptr!=NULL)
        {
            if(ptr->ID == id)
    { f=1;
  while (f)
    { printf("what is info you want edit\n 1  patient Name\n2 patient age\n3 gender type\n");
         scanf("%d",&edit);
      switch (edit)
    {
    case 1:
      printf ("Enter patient Name edited");
      scanf ("%s", &ptr->Name);

      break;
    case 2:
      printf ("\nEnter patient age edited");
      scanf ("%d", &ptr->age);

      break;
    case 3:
printf ("\nEnter patient gender type \n male 0\n female 1\n");
  scanf ("%s", &gender_type);
  if(gender_type)
  {
    ptr->gender="F";
  }
  else
  {
    ptr->gender="M";
  }
      break;
    default:
      break;
    }
      printf ("Any anther edit?\n press 1 if yes or 0 if not");
      scanf ("d", &f);
    }


                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> Next;
        }
        if(flag==1)
        {
            printf("Incorrect ID message.\n");
        }
    }

}
void reserveSlot(){
    int searchID,flag=0;
    printf("\nEnter patient ID: ");
    scanf("%d", &searchID);
    struct patian *temp = head;
    while (temp != NULL) {
        if (temp->ID == searchID){
			flag=1;
            printf("Available slots:\n");
            if(!reserveslot[0])
            printf("1. 2pm to 2:30pm\n");
             if(!reserveslot[1])
            printf("2. 2:30pm to 3pm\n");
             if(!reserveslot[2])
            printf("3. 3pm to 3:30pm\n");
             if(!reserveslot[3])
            printf("4. 4pm to 4:30pm\n");
             if(!reserveslot[4])
            printf("5. 4:30pm to 5pm\n");
            int slot;
            printf("Enter desired slot (1-5): ");
            switch(slot)
            {case 1:reserveslot[0]=1;
            temp->reserve_slot=slot1;
            break;
            case 2:reserveslot[1]=1;
            temp->reserve_slot=slot2;
            break;
            case 3:reserveslot[2]=1;
            temp->reserve_slot=slot3;
            break;
			case 4:reserveslot[3]=1;
            temp->reserve_slot=slot4;
            break;
			case 5:reserveslot[4]=1;
            temp->reserve_slot=slot5;
            break;
			default:
            printf("Invalid slot choice. Try again.\n");
            }
			break;
		}
			 temp = temp->Next;
    }
if(flag==0)
    printf("Error: Patient ID not found.\n");
}
void cancelReservation() {
    int searchID;
    printf("\nEnter patient ID to cancel reservation: ");
    scanf("%d", &searchID);

    struct patian *temp = head;
    while (temp != NULL) {
        if (temp->ID == searchID) {
			reserveslot[temp->reserve_slot]=0;
			temp->reserve_slot=non;

            return;
        }
        temp = temp->Next;
    }

    printf("Error: Patient ID not found.\n");
}


void viewPatientRecord() {
    int searchID;
    printf("\nEnter patient ID: ");
    scanf("%d", &searchID);

    struct patian *temp = head;
    while (temp != NULL) {
        if (temp->ID == searchID) {
            printf("Patient Information:\n");
            printf("Name: %s\n", temp->Name);
            printf("Age: %d\n", temp->age);
            printf("Gender: %c\n", temp->gender);
            printf("ID: %d\n", temp->ID);
            return;
        }
        temp = temp->Next;
    }

    printf("Error: Patient ID not found.\n");
}

void viewTodayReservations() {
    // Display today's reservations if available
    printf("Today's Reservations:\n");
	for(int i=0;i<5;i++)
    {
		if(reserveslot[0])
            printf("1. 2pm to 2:30pm\n");
             if(reserveslot[1])
            printf("2. 2:30pm to 3pm\n");
             if(reserveslot[2])
            printf("3. 3pm to 3:30pm\n");
             if(reserveslot[3])
            printf("4. 4pm to 4:30pm\n");
             if(reserveslot[4])
            printf("5. 4:30pm to 5pm\n");
	}
}
