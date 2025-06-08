#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
  printf("--------------------------------------------------------------------------------------\n");
  printf("| %-3s | %-25s |  %-13s | %-30s |\n","S.No","NAME","PHONE NUMBER","E-MAIL");
   printf("--------------------------------------------------------------------------------------\n");
    for(int i=0;i< addressBook->contactCount;i++ )// 
    {
        printf("| %-3d  | %-25s | %-13s  | %-30s |\n",i+1,addressBook ->contacts[i].name,addressBook ->contacts[i].phone,addressBook ->contacts[i].email);

    }
    printf("--------------------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook)
 {
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	char name[100];
  char phone[10];
  char email[50];
  printf("Enter Name : ");
  scanf(" %[^\n]",name);
  strcpy(addressBook->contacts[addressBook->contactCount].name,name);
  getchar();
  while(1)
{
  printf("Enter the Phone number : ");
  scanf("%s",phone);
  int s=phone_no(phone,addressBook);
  if(s)
  {
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
     break;
  }
  else 
  {
     printf("------------------------\n");
     printf("|Enter the Valid Number|\n");
     printf("------------------------\n");
  }
}
 while(1)
  {
   printf("Enter the E-mail : "); 
  scanf(" %[^\n]",email);
  int n=email_valid(email,addressBook);
  if(n)
     {
         strcpy(addressBook->contacts[addressBook->contactCount].email,email);
         break;
     }
     else
     {
           printf("------------------------\n");
           printf("|Enter the Valied E-mail|\n");
           printf("------------------------\n");
     }
  }
  addressBook->contactCount++;
  printf("Contact creat Successfully\n\n"); 
}

void searchContact(AddressBook *addressBook) 
{
    char str[100];
    int num=0;
    
    printf("\n 1.Name\n 2.Phone\n 3.Email\n");
    printf("Enter the searching option: ");
    scanf("%d",&num);
    getchar();//for clearing the buffer
        switch (num)
        {
        case 1:
               printf("Enter the Name: ");
               scanf("%[^\n]",str);
               printf("\n");
               int ch=0;
              for(int i=0;i<addressBook->contactCount;i++)    //run the loop until the size
              {
                if(strcasecmp(addressBook->contacts[i].name,str)==0)  //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                {
                 printf("%s\t %s\t %s\t\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                 ch++;
                }
              } 
              printf("\n");
              if(!ch)//there is not matching any given input means it will show this
              {
                   printf("Name is not founded\n");
              }
              break;
        case 2:
             printf("Enter the Phone number: ");
             scanf("%s ",str);
             int h=0;
                 for(int i=0;i<addressBook->contactCount;i++)//run the loop until the size
                  {
                     if(strcmp(addressBook->contacts[i].phone,str)==0) //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                      {
                        printf("%s\t %s\t %s\t\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        printf("\n");
                        h++;
                        break;
                      }
                  }
                  if(!h)//there is not matching any given input means it will show this
                   {
                        printf("Phone number is not founded\n");
                        break;
                   }

        case 3:
               printf("Enter Your E-mail: ");
               scanf("%s",str);
               int a=0;
               for(int i=0;i<addressBook->contactCount;i++)//run the loop until the size
               {
                   if(strcmp(addressBook->contacts[i].email,str)==0) //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                  {
                    printf("%s\t %s\t %s\t\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    printf("\n");
                    a++;
                    break;
                  }    
                }
                if(!a)//there is not matching any given input means it will show this
                {
                    printf("E-mail is not founded\n");
                }
                break;
        default:
              printf("Invalid input\n");
            break;
            }
}

void editContact(AddressBook *addressBook)
{
	 char str[100];
   char str1[100];
    int num=0;
    
    printf("\n 1.Name\n 2.Phone\n 3.Email\n");
    printf("Enter the option: ");
    scanf("%d",&num);
    getchar();//for clearing the buffer
        switch (num)
        {
        case 1:
               printf("Enter the Changing Name: ");
               scanf("%[^\n]",str);
               int ch=0;
              for(int i=0;i<addressBook->contactCount;i++)    //run the loop until the size
              {
                if(strcasecmp(addressBook->contacts[i].name,str)==0)  //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                {
                   printf("Enter the Name: ");
                   scanf(" %[^\n]",str1);
                   strcpy(addressBook->contacts[i].name,str1);
                   printf("Name ia Changed");
                   printf("\n");
                   ch++;
                   break;
                }
              } 
              if(!ch)//there is not matching any given input means it will show this
              {
                   printf("Name is not founded\n");
              }
              break;
        case 2:
             printf("Enter the Phone number: ");
             scanf(" %s",str);
                  int h=0;  
                 for(int i=0;i<addressBook->contactCount;i++)//run the loop until the size
                  {
                     if(strcmp(addressBook->contacts[i].phone,str)==0) //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                      {
                        while(1)
                        {
                        printf("Enter the Changing number: ");
                        scanf(" %[^\n]",str1);
                          int s=phone_no(str1,addressBook);//Check the all condition using Phone number function
                          
                                if(s)
                                    {
                                        strcpy(addressBook->contacts[i].phone,str1);//condition true means enterd if condition otherwise false
                                        printf("Number ia Changed");
                                        printf("\n");
                                        h++;
                                        break;
                                    }
                                else
                                   {
                                     printf("------------------------\n");
                                      printf("|Enter the Valid Number|\n");
                                      printf("------------------------\n");  
                                   }
                          }
                      }
                  }
                  if(!h)//there is not matching any given input means it will show this
                   {
                        printf("Phone number is not founded\n");
                   }
                   break;

        case 3:
               printf("Enter Your E-mail: ");
               scanf(" %s",str);
               int a=0;
               for(int i=0;i<addressBook->contactCount;i++)//run the loop until the size
               {
                   if(strcmp(addressBook->contacts[i].email,str)==0) //Checking the given input and already exisiting input.The two sting will be matched means then run that array iteration 
                  {
                    while(1)
                    {
                    printf("Enter the E-mail: ");
                    scanf(" %[^\n]",str1);
                    int j=email_valid(str1,addressBook);//Check the all condition using Email function
                    if(j)                              //condition true means enterd if condition otherwise false
                    {
                      strcpy(addressBook->contacts[i].email,str1);    
                      printf("E-mail is Changed");
                      printf("\n");
                      a++;
                      break;
                    }
                    else
                    {
                          printf("------------------------\n");
                          printf("|Enter the Valid E-mail |\n");
                          printf("------------------------\n"); 
                    }
                  }    
                }
              }
                if(!a)//there is not matching any given input means it will show this
                {
                    printf("E-mail is not founded\n");
                }
                break;
        default:
              printf("Invalid input\n");
            break;
            }
    
}

void deleteContact(AddressBook *addressBook)
{
	       char str[100];
         int ch=0,num;
         printf("Enter the Deleted Option\n 1.Name\n 2.Number\n 3.E-mail\n");
         printf("Enter yor Preferances: ");
         scanf("%d",&num);
         switch(num)
         {
         case 1:
                 printf("Enter your Name :");
                 scanf(" %[^\n]",str);
                 for(int i=0;i<addressBook->contactCount;i++)  
                 {   
                 if(strcasecmp(addressBook->contacts[i].name,str)==0) //Check the given string is name or not 
                  {  
                     for(int j=i;j<addressBook->contactCount;j++)    //run the loop until the size
                    {                                                        
                     addressBook->contacts[j]=addressBook->contacts[j+1];//The condition true means swap the next array to this array
                    }  
                     ch++;
                     addressBook->contactCount--;    //the consition true means size will be decrease on time
                      printf("Deleted Successfully\n");
                  }
                }
                    
                     break;
            case 2:
                 printf("Enter your Phone :");
                 scanf(" %[^\n]",str);
                 for(int i=0;i<addressBook->contactCount;i++)
                 {
                  if(strcasecmp(addressBook->contacts[i].phone,str)==0) //Check the given string is phone number or not 
                  {  
                     for(int j=i ;j<addressBook->contactCount;j++)    //run the loop until the size
                    {                                                          
                        addressBook->contacts[j]=addressBook->contacts[j+1];  //The condition true means swap the next array to this array
                    }
                      ch++;
                      addressBook->contactCount--;    //the consition true means size will be decrease on time
                      printf("Deleted Successfully\n");
                  }
                 }
                     break;
          
              case 3:
                 printf("Enter your E-mail :");
                 scanf(" %[^\n]",str);
                 for(int i=0;i<addressBook->contactCount;i++)
                 {
                  if(strcasecmp(addressBook->contacts[i].email,str)==0) //Check the given string is email or not 
                  {  
                     for(int j=i;j<addressBook->contactCount;j++)    //run the loop until the size
                    {                                                          
                     addressBook->contacts[j]=addressBook->contacts[j+1];  //The condition true means swap the next array to this array
                    }
                     ch++;
                     addressBook->contactCount--; //the consition true means size will be decrease on time
                      printf("Deleted Successfully\n");
                  }
                 }
                     break;

                }
              if(!ch)//there is not matching any given input means it will show this
                 {
                      printf("Name or Phone or E-mail is not founded\n");
                      printf("\n");
                 }
}
int phone_no(char *str,AddressBook *addressBook)
{
     int i;
     int len=strlen(str);
     //The given number should in 10 only
     if(len!=10)
     {
       return 0;
     }
     //The given string is only number not a character
     for(i=0;i<len;i++)
     {
        if(!(str[i]>='0' && str[i]<='9'))
         {
             return 0;
         }
     }
     //Check the duplicate
     for(i=0;i<addressBook->contactCount;i++)
     {
       if((strcmp(addressBook->contacts[i].phone,str)==0))
       {
             return 0;
       }
     }

     return 1;
}        

  int email_valid(char *str,AddressBook *addressBook)
{
      int i,found=0,count=0;
      int n=strlen(str);
      //In E-mail first letter should be small letter
      for(i=0;i<n;i++)
      {
        if(!(str[0]>='a' && str[0]<='z'))   //This condition is true means only enter the return o part, otherwise the condition false means it will check tha next condition
        {
          return 0;
        }
      }
      //The given input should be small letter,numbers,@ and . only contain.otherwise it will return 0
      for(i=0;i<n;i++)
      {
        if(!((str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9') || str[i]=='@'||str[i]=='.') )
        {
          return 0;
        }
      }
      //In the email @ character should be needed ,so @ present means true.The last value is .com, so we can check that also.
      for(i=0;i<n;i++)
      {
        if(str[i]=='@')
        {
          found=1;
        }
        if(str[i]=='.' && str[i+1]=='c' && str[i+2]=='o' && str[i+3]=='m' && str[i+4]=='\0')
        {
          count=1;
        }
      }
      //The @ and .com is present means true 
      if(!(found && count))  
      {
        return 0;
      }
      //When @ occured the next character should be alphabets
       for(i=0;i<n;i++)
      {
        if(str[i]=='@' && ((str[i+1]>='0' && str[i+1]<='9') || str[i+1]=='.'))
        {
          return 0;
        }
      }
      //the @ should be present only one time
      int ha=0;
      for(i=0;i<n;i++)
      {
        if(str[i]=='@')
        {
          ha++;
        }
      }
      if(!(ha==1))
      {
        return 0;
      }
      //The duplicate checking
       for(i=0;i<addressBook->contactCount;i++)
     {
       if((strcmp(addressBook->contacts[i].email,str)==0))
       {
             return 0;
       }
     }
     //The all condtion is true means return 1
    return 1;
}              