// Writes to phonebook.csv, checks for errors at each step, and uses errno to print specific error messages. fflush ensures data is written to disk immediately.

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    char *data = "Alice,1234567890\n";
    if (fprintf(file, "%s", data) < 0)
    {
        printf("Error writing to file: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    if (fflush(file) != 0)
    { // Force write to disk
        printf("Error flushing file: %s\n", strerror(errno));
    }

    if (fclose(file) != 0)
    {
        printf("Error closing file: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
