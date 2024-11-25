/*#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
    const char *files[] = {"file1.txt", "file2.txt"};
    
    int fds[2];  // Tableau de descripteurs de fichier
    char *line;
    size_t i;

    // Ouvre tous les fichiers
    for (i = 0; i < sizeof(files) / sizeof(files[0]); i++)
    {
        fds[i] = open(files[i], O_RDONLY);
        if (fds[i] < 0)
        {
            perror("Error opening file");
            return (1);
        }
    }

    // Lecture des fichiers dans un ordre spécifique
    printf("Reading from file1.txt\n");
    while ((line = get_next_line(fds[0])) != NULL)
    {
        printf("file1: %s", line);
        free(line);
    }

    printf("\nReading from file2.txt\n");
    while ((line = get_next_line(fds[1])) != NULL)
    {
        printf("file2: %s", line);
        free(line);
    }
    // Ferme tous les descripteurs de fichier
    for (i = 0; i < sizeof(fds) / sizeof(fds[0]); i++)
    {
        close(fds[i]);
    }

    return (0);
}
*/
