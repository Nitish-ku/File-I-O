// write and read phonebook.csv

#include <stdio.h>

int main(void)
{
    // Write to file
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    char name[50], number[15];
    printf("Name: ");
    scanf("%49s", name);
    printf("Number: ");
    scanf("%14s", number);

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

    // Read from file
    file = fopen("phonebook.csv", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nPhonebook Contents:\n");
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
    }

    if (ferror(file)) {
        printf("Error reading file!\n");
    }
    fclose(file);
    return 0;
}
