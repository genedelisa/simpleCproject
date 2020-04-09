
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *logfile = NULL;
extern int errno;

void openLogfile() {
  int errnum;

  logfile = fopen("logfile", "a+");
  if (logfile == NULL) {
    fprintf(stderr, "could not open log file");
    errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errno);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
  }
}

void closeLogfile() {
  if (logfile != NULL) {
    int status = 0;
    status = fflush(logfile);
    if (status != 0) {
      fprintf(stderr, "error flushing logfile. %d\n", status);
    }
    status = fclose(logfile);
    if (status != 0) {
      fprintf(stderr, "error closing logfile. %d\n", status);
    }
    logfile = NULL;
  }
}

void logMessage(char *s) {
  // fprintf(logfile, "%s\n", s);
  if (logfile != NULL) {
    fputs(s, logfile);
  }
}
