#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>

int main(void)
{
    FILE *file = fopen("pikachu.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Lock the file (exclusive lock)

    if (flock(fileno(file), LOCK_EX) == -1)
    {
        printf("Error locking file!\n");
        fclose(file);
        return 1;
    }

    // safe to write now

    fprintf(file, "Alexa,1234567890\n");

    // unlock the file

    flock(fileno(file), LOCK_UN);
    fclose(file);
    return 0;
}
