#include "contact.h"

int main() 
{
        AddressBook info;
        initialize(&info);
   int a=0;
   while(1)
   {
   printf("............Address Book Details.................\n");
   printf("| %-45s |\n","1.Creat Contact");
   printf("| %-45s |\n","2.Search Contact");
   printf("| %-45s |\n","3.Edit Contact");
   printf("| %-45s |\n","4.Delete Contact");
   printf("| %-45s |\n","5.List Contact");
   printf("| %-45s |\n","6.Exit");
   printf(".................................................\n");
    printf("Enter the your option : ");
   scanf("%d",&a);

   switch (a)
   {
       case 1:
                createContact(&info);
                break;
        case 2:
                searchContact(&info);
                break;
        case 3:            
                editContact(&info);
                break;
        case 4:
                deleteContact(&info);
                break;
        case 5:
                listContacts(&info);
                break;
        case 6:
                saveAndExit(&info);
               return 0;
              
        default:
               printf("Invalid Input.Try Again");
               return 0;
   }
  }
}
