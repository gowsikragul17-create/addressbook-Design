#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

int validateName(char name[])
{
    int i;
    if(strlen(name) < 2)
    {
        return 0;
    }
    for(i=0;name[i] !='\0';i++)
    {
        if(!isalpha(name[i]) && name[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

int validatePhone(char phone[])
{
    if(strlen(phone) != 10)
    {
        return 0;
    }
     if(phone[0] < '6' || phone[0] > '9')
     {
        return 0;
     }
     for(int i=0;phone[i] != '\0';i++)
     {
        if(!isdigit(phone[i]))
        {
            return 0;
        }
     }
     return 1;
}

int validateEmail(char  email[])
{
    int atcount=0;
    int atposition = -1;
    for(int i=0;email[i] !='\0';i++)
    {
        if(isupper(email[i]))
        {
            return 0;
        }
        if(email[i] == '@')
        {
            atcount++;
            atposition = i;
        }
    }
    if(atcount !=1)
    {
        return 0;
    }
    if(email[strlen(email)-4] !='.' || email[strlen(email)-3] !='c' || email[strlen(email)-2] !='0' || != 'o' || email[strlen(email)-1] != 'm' )
    {
        return 0;
    }
    if(email[0] == '@')
    {
        return 0;
    }
    if(atposition +1 >= strlen(email)-4)
    {
        return 0;
    }
    return 1;
}

void listContacts(AddressBook *addressBook) 
{
    int criteria;
    int i,j;
    printf("sort based on :\n1.name\n2.phone.\n3.email\n");
    scanf("%d",&criteria);

    if(criteria == 1)
    {
        for(i=0;i<addressBook->contactCount-1;i++)
        {
            for(j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name) > 0)
                {
                    Contact temp;
                    temp = addressBook->contacts[i];
                    addressBook->contacts[i] = addressBook->contacts[j];
                  addressBook->contacts[j] = temp;
                } 
            }
        }
    }
    if(criteria == 2)
    {
         for(i=0;i<addressBook->contactCount-1;i++)
        {
            for(j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone) > 0)
                {
                    Contact temp;
                    temp = addressBook->contacts[i];
                    addressBook->contacts[i] = addressBook->contacts[j];
                  addressBook->contacts[j] = temp;
                }  
            }
        }
    }
    if(criteria == 3)
    {
         for(i=0;i<addressBook->contactCount-1;i++)
        {
            for(j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email) > 0)
                {
                    Contact temp;
                    temp = addressBook->contacts[i];
                    addressBook->contacts[i] = addressBook->contacts[j];
                    addressBook->contacts[j] = temp;
                }    
            }
        }
    }
    for(i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	 while(1)
    {
	  printf("Enter the name: ");
      scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);

      if(validateName(addressBook->contacts[addressBook->contactCount].name))
      {
        break;
      }
      printf("Invalid Name! Try again.\n");
    }
    
    while(1)
    {
        printf("Enter the Phone number: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);

        if(validatePhone(addressBook->contacts[addressBook->contactCount].phone))
        {
            break;
        }
        printf("Invalid Number! Try again.\n");
    }

    while(1)
    {
        printf("Enter the Email: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);

        if(validateEmail(addressBook->contacts[addressBook->contactCount].email))
        {
            break;
        }
        printf("Invalid Email! Try again.\n");
    }
    //addressBook->contactCount++;
}


void searchContact(AddressBook *addressBook) 
{
    int found = 0;
    int i;
    char search[50];
    printf("Enter the name to search: ");
    scanf(" %[^\n]",search);
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strstr(addressBook->contacts[i].name,search) != NULL || strstr(addressBook->contacts[i].phone,search) != NULL 
         || strstr(addressBook->contacts[i].email,search) != NULL)
        {
            printf("Name = %s\n",addressBook->contacts[i].name);
            printf("Phone = %s\n",addressBook->contacts[i].phone);
            printf("Email = %s\n",addressBook->contacts[i].email);

            found = 1;
            
        }
    }
    if(found == 0)
    {
        printf("Contact not Found.\n");
    }
}



void editContact(AddressBook *addressBook)
{
	
    
}

void deleteContact(AddressBook *addressBook)
{
}
