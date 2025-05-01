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
    FILE *file = fopen("pookies.bin", "ab"); // "ab" = append in binary mode
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    int count;
    printf("How many contacts do you want to add? ");
    scanf("%d", &count);

    Contact contact;
    for (int i = 0; i < count; i++)
    {
        printf("Enter name: ");
        scanf("%s", contact.name);
        printf("Enter number: ");
        scanf("%s", contact.number);

        fwrite(&contact, sizeof(contact), 1, file);
    }

    fclose(file);

    //  read from binary file

    file = fopen("pookies.bin", "rb"); // read all contacts
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nALL contacts:\n");
    Contact read_contact;
    while (fread(&read_contact, sizeof(contact), 1, file))
    {
        printf("Name: %s, Number: %s\n", read_contact.name, read_contact.number);
    }

    fclose(file);
    return 0;
}
