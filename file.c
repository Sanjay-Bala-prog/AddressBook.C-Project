#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{ 
    FILE *fp=fopen("contacts.txt","w");
    if(fp==NULL)
    {
        printf("file is not opening");
        return;
    }
    fprintf(fp,"%d\n",addressBook->contactCount);
    printf("count -> %d\n",addressBook->contactCount);
    for(size_t i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);

       
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp=fopen("contacts.txt","r");
    if(fp==NULL)
    {
        printf("file is not opening");
        return;
    }
    fscanf(fp,"%d\n",&addressBook->contactCount);
    printf("count -> %d\n",addressBook->contactCount);
    for(size_t i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
}