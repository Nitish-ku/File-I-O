//Creates a temporary file, writes to it, reads from it, and closes it (deleting the file automatically)

#include <stdio.h>

int main(void)
{
    FILE *temp = tmpfile();
    if (temp == NULL)
    {
        printf("Error creating temorary file!\n");
        return 1;
    }

    // write to temp file

    fprintf(temp, "Temporary data\n");

    // rewind and read

    rewind(temp);
    char buffer[100];
    if (fgets(buffer, 100, temp) != NULL)
    {
        printf("Read: %s", buffer);
    }

    fclose(temp); // temp file is closed
    return 0;
}
