#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "r+"); // open for reading and writing

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char line[100];
    long position;
    char target_name[] = "Pewcalypse";
    char new_number[] = "9999999999";

    // search for Rudru's record

    while (fgets(line, 100, file) != NULL)
    {
        position = ftell(file); // save position after reading line
        if (strncmp(line, target_name, strlen(target_name)) == 0)
        {
            // found Rudru, move back to start of the line
            fseek(file, position - strlen(line), SEEK_SET);
            // overwrite with new number (assuming same format)
            fprintf(file, "%s,%s\n", target_name, new_number);
            break;
        }
    }

    fclose(file);
    return 0;
}
