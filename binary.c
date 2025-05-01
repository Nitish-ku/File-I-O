#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_NUMBER 15

typedef struct
{
    char name[MAX_NAME];
    char number[MAX_NUMBER];
} Contact;

int main(void)
{
    // write to a binary file
    FILE *file = fopen("phonebook.bin", "wb"); // binary write mode
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Contact contact = {"Tanisha", "1234567890"};
    fwrite(&contact, sizeof(Contact), 1, file);
    fclose(file);

    // read from binary file
    file = fopen("phonebook.bin", "rb"); // binary read mode
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Contact read_contact;
    fread(&read_contact, sizeof(Contact), 1, file);
    printf("Name: %s, Number: %s\n", read_contact.name, read_contact.number);
    fclose(file);
    return 0;
}
