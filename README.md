# File-I-O
reading and manipulating files

// saves names and numbers to a csv files

#include <stdio.h>
#include <string.h>

int main(void)
{
    // open csv file
    FILE *file = fopen("phonebook.csv", "a");

    if (file == NULL)
    {
        return 1;
    }

    // get name and number
    char name[50];
    printf("Name: ");
    scanf("%49s", name);

    char number[15];
    printf("Number: ");
    scanf("%14s", number);

    // print to file

    fprintf(file, "%s,%s\n", name, number);

    // close the file

    fclose(file);
}
