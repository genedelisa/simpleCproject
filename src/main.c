
#include "main.h"

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "logger.h"
#include "sigz.h"

int main(int argc, char *argv[]) {
  openLogfile();
  logMessage("running\n");

  // signal(SIGTERM, onExit);

  setupSignals();

  printf("Type a character: ");
  int x = getchar();

  char s[80];
  sprintf(s, "you typed %d %c\n", x, x);
  logMessage(s);
  printf("%s", s);

  closeLogfile();

  return EXIT_SUCCESS;
}
