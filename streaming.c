// reads phonebook.csv in chunks

#include <stdio.h>

#define BUFFER_SIZE 1024

int main(void)
{
    FILE *file = fopen("phonebook.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        printf("%s", buffer); // process each line
    }

    if (ferror(file))
    {
        printf("Error reading file!\n");
    }

    fclose(file);
    return 0;
}
