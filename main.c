/*
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //int fd = open("file1.txt", O_RDONLY);  // Ouvrir un fichier en lecture
    char *line;

    while ((line = get_next_line(0)) != NULL) 
	{
        printf("%s", line);
        free(line);
    }
    //close(fd);
    return 0;
}
*/
/*
int main()
{
    const char *files[] = {"file1.txt", "file2.txt"};
    int fd[2];  // Tableau de descripteurs de fichier
    char *line1, *line2;
    size_t i;

    i = 0;
    while (i < sizeof(files) / sizeof(files[0])) 
    {
        fd[i] = open(files[i], O_RDONLY);
        if (fd[i] < 0) 
        {
            perror("Error opening file");
            return (1);
        }
        i++;
    }
    line1 = get_next_line(fd[0]);
    line2 = get_next_line(fd[1]);
    while (line1 || line2)
    {
        if (line1)
        {
            printf("file1: %s", line1);
            free(line1);
            line1 = get_next_line(fd[0]);
        }
        if (line2)
        {
            printf("file2: %s", line2);
            free(line2);
            line2 = get_next_line(fd[1]);
        }
    }
    close(fd[0]);
    close(fd[1]);
    return (0);
}*/
