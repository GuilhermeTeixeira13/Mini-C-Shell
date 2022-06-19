#include <stdio.h>
#include <dirent.h>
#include "shell.h"

void getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    printf("%s", ctime(&attr.st_mtime));
}

void listar(char *pasta)
{
    if (pasta == NULL)
        pasta = ".";

    DIR *d;
    struct dirent *dir;
    d = opendir(pasta);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%15s %i ", dir->d_name, dir->d_reclen);
            getFileCreationTime(pasta);
        }
        closedir(d);
    }
}