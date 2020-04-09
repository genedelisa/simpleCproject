#include "sigz.h"

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "logger.h"

void onExit(int signal) {
  printf("exiting. signal %d\n", signal);
  switch (signal) {
    case SIGTERM: printf("sigterm\n"); break;
    case SIGINT: printf("sigint\n"); break;
    case SIGHUP: printf("sighup\n"); break;
  }
  logMessage("exiting. signal\n");
  closeLogfile();
  exit(EXIT_SUCCESS);
}

void setupSignals() {
  struct sigaction sa;

  sa.sa_handler = &onExit;
  sa.sa_flags = SA_RESTART;
  sigemptyset(&sa.sa_mask);
  sigaddset(&sa.sa_mask, SIGINT);
  sigaddset(&sa.sa_mask, SIGTERM);
  sigaddset(&sa.sa_mask, SIGHUP);
  sigaddset(&sa.sa_mask, SIGQUIT);

  if (-1 == sigaction(SIGTERM, &sa, NULL)) {
    perror("Error: cannot handle SIGTERM");
  }

  if (-1 == sigaction(SIGINT, &sa, NULL)) {
    perror("Error: cannot handle SIGINT");
  }

  if (-1 == sigaction(SIGHUP, &sa, NULL)) {
    perror("Error: cannot handle SIGHUP");
  }

  if (-1 == sigaction(SIGQUIT, &sa, NULL)) {
    perror("Error: cannot handle SIGQUIT");
  }
}
