#include "../header/unpipc.h"
#include "../header/wrapper_func.h"

int
main(int argc, char** argv)
{
  size_t n;
  char buff[MAXLINE], command[MAXLINE];
  FILE* fd;

  /* read pathname */
  Fgets(buff, MAXLINE, stdin);
  n = strlen(buff);
  if(buff[n-1] == '\n')
    n--;

  snprintf(command, sizeof(command), "cat %s", buff);
  fd = Popen(command, "r");

  /* copy from pipe to standard output */
  while(fgets(buff, MAXLINE, fd) != NULL)
    Fputs(buff, stdout);

  Pclose(fd);
  exit(0);
}
