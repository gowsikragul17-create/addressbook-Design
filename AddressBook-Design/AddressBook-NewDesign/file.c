#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    // open the file in 'w' mode
    FILE* fptr = fopen("contact.txt", "r")
    if (fptr == NULL)

        
        // If the file couldn't be opened, print an error message and exit
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    // Write the header to the file
    fprintf(fptr, "ID\tNAME\t\t\t\t\tMobile_Number\t\tEMAIL\n");

    // Loop through all contacts in the address book and write them to the file
    for (int i = 0; i < addressBook->contactCount; i++)
    {

        // Write each contact's details to the file
        fprintf(fptr, "%d\t%-20s\t%-18s\t%s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    // Close the file after writing
    fclose(fptr);
}


void loadContactsFromFile(AddressBook *addressBook) {
    
}
