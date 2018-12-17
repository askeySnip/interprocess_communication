#include "../header/unpipc.h"
#include "../header/wrapper_func.h"

/* read from stdin and write into writefd(the pipe for client to server)
* and read from the readfd(the pipe for server to client)
* finally print the read content to stdout*/
void
client(int readfd, int writefd) {
  size_t len;
  ssize_t n;
  char buff[MAXLINE];
  /* read pathname */
  Fgets(buff, MAXLINE, stdin);
  len = strlen(buff);
  if(buff[len-1] == '\n')
    len--;
  Write(writefd, buff, len);

  /* read from IPC, write to standard output */
  while( (n = Read(readfd, buff, MAXLINE)) > 0)
    Write(STDOUT_FILENO, buff, n);
}
