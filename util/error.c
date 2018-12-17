#include "../header/myerror.h"

#include <stdarg.h>             /* ANSI C header file. i.e. va_list*/
#include <syslog.h>             /* for syslog() */
#include <errno.h>

int daemon_proc;                /* set nonzero by daemon_init() */

static void err_doit(int, int, const char *, va_list);

void
myerr_sys(const char* fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(1);
}

void
err_quit(const char* fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, LOG_ERR, fmt, ap);
  va_end(ap);
  exit(1);
}

static void
err_doit(int errnoflag, int level, const char *fmt, va_list ap)
{
  int errno_save, n;
  char buf[MAXLINE];
  errno_save = errno;           /* value caller might want printed */
#ifdef HAVE_VSNPRINTF
  vsnprintf(buf, sizeof(buf), fmt, ap);
#else
  vsprintf(buf, fmt, ap);
#endif
  n = strlen(buf);
  if  (errnoflag)
    snprintf(buf+n, sizeof(buf)-n, ": %s", strerror(errno_save));
  strcat(buf, "\n");

  if(daemon_proc){
    syslog(level, buf);
  }else {
    fflush(stdout);
    fputs(buf, stderr);
    fflush(stderr);
  }
  return;
}
