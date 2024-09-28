#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int vs, age, slot, id;

long int contactnumber;

char name[20], vaccination[50], timeslot[20], date[20];

void vaccinationdisplay()
 {

printf("Welcome to vaccination registration portal!\n");

printf(" \n");

printf("\n Vaccination list:\n\n");

printf("1. Typhoid vaccine\n2. Polio vaccine\n3. Nasal influenza vaccine\n4. MRV vaccine\n5. BCG vaccine\n6. Influenza vaccine\n7. Hepatitis vaccine\n8. Covishield dose1\n9. Covishield dose2\n10. HIV vaccine\n");

printf("\n Select one from the above available vaccines: ");

int choice =0;

while (scanf("%d", &choice) != 1 || choice < 1 || choice > 10) 
{
printf("Invalid entry! Please enter a valid choice (1-10): ");
}
switch (choice) 
{
case 1: strcpy(vaccination, "Typhoid vaccine"); break;
case 2: strcpy(vaccination, "Polio vaccine"); break;
case 3: strcpy(vaccination, "Nasal influenza vaccine"); break;
case 4: strcpy(vaccination, "MRV vaccine"); break;
case 5: strcpy(vaccination, "BCG vaccine"); break;
case 6: strcpy(vaccination, "Influenza vaccine"); break;

case 7: strcpy(vaccination, "Hepatitis vaccine"); break;

case 8: strcpy(vaccination, "Covishield dose1"); break;

case 9: strcpy(vaccination, "Covishield dose2"); break;

case 10: strcpy(vaccination, "HIV vaccine"); break;

default: printf("Invalid vaccination type, Kindly select from the list!\n"); strcpy(timeslot, "");

break;
}
}

void registration() {

printf("Enter your name: ");
scanf("%s", name);
printf("\nEnter your age: "); 
scanf("%d", &age);
printf("\nEnter your ID number (6 digits only): ");

while (1) 
{

scanf("%d", &id);

if (id >= 100000 && id <= 999999)
 {

break;
}
else 
{
printf("Invalid ID number! Please enter 6 digits only: ");

}

}

printf("\nEnter your contact number (10 digits only): ");
while (1) 
{
scanf("%ld", &contactnumber);

if (contactnumber>= 1000000000 && contactnumber<= 9999999999) 
{
    break;
}
else 
{
     printf("Invalid contact number! Please enter 10 digits only: ");
}
}
}
void dateSelection()
 {
time_t t =time(NULL); 
struct tm tm =*localtime(&t);
int year= tm.tm_year+1900;
int month= tm.tm_mon + 1;
int day=tm.tm_mday;
printf("\nSelect a date within the next three months from today's date:\n");
printf("%d-%02d-%02d\n",day, month, year);
struct tm entered_date= {0};
printf("\nSelect a date (dd-mm-yyyy): ");
scanf("%d-%d-%d", &entered_date.tm_mday, &entered_date.tm_mon,&entered_date.tm_year);
entered_date.tm_mon -= 1;
entered_date.tm_year -= 1900;
entered_date.tm_isdst =-1;
time_t entered_time = mktime(&entered_date);
time_t max_allowed_time = mktime(&tm)+3*30* 24 * 60 * 60; // Add 3 months in seconds
if (entered_time> max_allowed_time) 
{

printf("Error: Date is more than 3 months from today's date!\n");

exit(1);
}

time_t min_allowed_time =mktime(&tm);
if (entered_time < min_allowed_time) 
{ 
    printf("Error: Date is before today's date!\n");
    exit(1);
}

strftime(date, sizeof(date), "%d-%m-%Y", &entered_date);
 }
void slotbooking()
 {

printf("Available time slots:\n");

printf("1. 9 AM\n2. 12 PM\n3. 4 PM\n");

printf("\nSelect your time slot: ");

scanf("%d", &slot);

switch (slot) 
{

case 1: strcpy(timeslot, "9 AM"); break; 
case 2: strcpy(timeslot, "12 PM"); break; 
case 3: strcpy(timeslot, "4 PM"); break;
default:
    printf("Invalid slot time!\n"); 
    strcpy(timeslot, "");
    break;
}
}

int main()
 {

vaccinationdisplay(); 
registration();

dateSelection(); 
slotbooking();

printf("\033[1;34m\n\n-------------------------------------------------\n");

printf("Name: %s\n", name);

printf("Age: %d\n", age);

printf("ID: %d\n", id);

printf("Vaccination selected: %s\n", vaccination); printf("Time slot selected: %s\n", timeslot);

printf("Scheduled date: %s\n", date);

printf("Contact Number: %ld\n",contactnumber);

printf("Your vaccination registration is successfully completed.\n"); 

printf("-------------------------------------\n\003[0m");

return 0;
 }