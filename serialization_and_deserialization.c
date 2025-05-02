//Improves CSV handling by quoting strings (to support commas in names) and provides reusable write_contact and read_contact functions.

#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_NUMBER 15

typedef struct
{
    char name[MAX_NAME];
    char number[MAX_NUMBER];
} Contact;

void write_contact(FILE *file, Contact *c)
{
    fprintf(file, "\"%s\", \"%s\"\n", c->name, c->number); // quote string for csv
}

int read_contact(FILE *file, Contact *c)
{
    char name[MAX_NAME], number[MAX_NUMBER];
    if (fscanf(file, "\"%49[^\"]\",\"%14[^\"]\"\n", name, number) == 2)
    {
        strncpy(c->name, name, MAX_NAME);
        strncpy(c->number, number, MAX_NUMBER);
        return 1;
    }
    return 0;
}

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    Contact c = {"Poopocalypse", "9987654321"};
    write_contact(file, &c);

    rewind(file);
    Contact read_c;
    while (read_contact(file, &read_c))
    {
        printf("Name: %s, Number: %s\n", read_c.name, read_c.number);
    }

    fclose(file);
    return 0;
}
