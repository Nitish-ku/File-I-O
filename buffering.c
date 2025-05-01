// disable buffering for real time logging 

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // disable buffering
    setvbuf(file, NULL, _IONBF, 0);

    // write log message
    fprintf(file, "Log entry 1\n");

    // without buffering, this is written immediately
    fprintf(file, "Log entrt 2\n");

    fclose(file);
    return 0;
}
