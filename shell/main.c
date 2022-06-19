#include "shell.h"
#include <sys/stat.h>

char prompt[100];

int main()
{
  int len;
  char linha[1024]; /* um comando */
  char *args[64];   /* com um maximo de 64 argumentos */

  strcpy(prompt, "SOSHELL: Introduza um comando : prompt>");
  while (1)
  {
    printf("%s", prompt);
    if (fgets(linha, 1023, stdin) == NULL)
    {
      printf("\n");
      exit(0);
    }
    len = strlen(linha);
    if (1 == len)
      continue; /* linha é apenas \n */
    if (linha[len - 1] == '\n')
      linha[len - 1] = '\0';
    int numargs = parse(linha, args); /* particiona a string em argumentos */

    if (!builtin(args, numargs))
      execute(numargs, args); /* executa o comando */
  }
  return 0;
}

int builtin(char **args, int numargs)
{
  if (strcmp(args[0], "sair") == 0)
  {
    exit(0);
    return 1;
  }
  if (strncmp(args[0], "42", 2) == 0)
  {
    printf("42 is the answer to life the universe and everything\n");
    return 1; /* funcionalidade embutida */
  }
  if (0 == strcmp(args[0], "obterinfo"))
  {
    printf("SoShell 2022 versaõ 1.0\n");
    return 1; // comando embutido
  }
  if (strlen(args[0]) > 4 && 0 == strncmp(args[0], "PS1=", 4))
  {
    strcpy(prompt, args[0] + 4);
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "quemsoueu"))
  {
    system("id");
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "cd"))
  {
    int err;
    if (NULL == args[1] || strcmp(args[1], "~") == 0)
      err = chdir(getenv("HOME"));
    else
      err = chdir(args[1]);
    if (err < 0)
      perror(args[1]);
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "calc") && numargs == 4)
  {
    calc(args[1], args[2], args[3]);
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "bits") && numargs == 4)
  {
    bits(args[1], args[2], args[3]);
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "isjpeg"))
  {
    int fd = open(args[1], O_RDONLY, 0);
    if (fd < 0)
      printf("File doesnt exists.\n");
    else
    {
      if (isjpeg(fd))
        printf("%s is JPEG!\n", args[1]);
      else
        printf("%s isn't JPEG!\n", args[1]);
    }
    return 1; // comando embutido
  }
  if (0 == strcmp(args[0], "socp"))
  {
    socp(args[1], args[2]);
    return 1; // comando embutido
  }
  if (strcmp(args[0], "aviso") == 0)
  {
    pthread_t th;
    aviso_t *ptr = (aviso_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo = atoi(args[2]);
    pthread_create(&th, NULL, avisowrapper, (void *)ptr);
    return 1;
  }
  if (strcmp(args[0], "socpth") == 0)
  {
    pthread_t th;
    copiar_t *ptr = (copiar_t *)malloc(sizeof(copiar_t));
    strcpy(ptr->fonte, args[1]);
    strcpy(ptr->destino, args[2]);
    pthread_create(&th, NULL, socpwrapper, (void *)ptr);
    return 1;
  }
  if (strcmp(args[0], "maior") == 0)
  {
    long int sizef1 = findSize(args[1]);
    long int sizef2 = findSize(args[2]);

    if (sizef1 < sizef2)
      printf("%s -> %fKB\n", args[2], sizef2 * 0.001);
    else if (sizef1 > sizef2)
      printf("%s -> %fKB\n", args[1], sizef1 * 0.001);
    else
    {
      printf("%s -> %fKB\n", args[2], sizef2 * 0.001);
      printf("%s -> %fKB\n", args[1], sizef1 * 0.001);
    }

    return 1;
  }
  if (strcmp(args[0], "setx") == 0)
  {
    char command[50] = "chmod u=rxw ";
    strcat(command, args[1]);
    system(command);

    return 1;
  }
  if (strcmp(args[0], "removerl") == 0)
  {
    char command[50] = "chmod go-r ";
    strcat(command, args[1]);
    system(command);

    return 1;
  }
  if (strcmp(args[0], "sols") == 0)
  {
    listar(args[1]);

    return 1;
  }
  /* IMPORTANTE :
   Devolver 0 para indicar que não existe comando embutido e que
   será executado usando exec() na função execute.c
  */
  return 0;
}
