/**************************************************************************
 *
 * utils.c
 *
 *    Utils functions for platform
 *
 * Copyright 2019
 *
 **************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/stat.h>
#include <utils.h>

#define THIS_FILE "utils.c"

int msleep(int nMsec) {
  
  int sleepTime = nMsec * 1000;

  if ((sleepTime >= 0) && (sleepTime <= USLEEP_MAX)) {
    return usleep(sleepTime);
  } else if (nMsec >= 0) {
    return sleep(nMsec/1000);
  } else {
    return -1;
  }
}

void logOpen(char *pchLogAppName, int facility) {
  openlog(pchLogAppName, 0, facility);
}

void logClose() {
  closelog();
}

void resetBoard() {
	char *pcCommand[] = {"reboot", NULL};

  execvp(pcCommand[0], pcCommand);
}

void restoreConfig() {
	system("rm -rf /data/*");
	system("sync");
	system("/etc/init.d/files_default start");
	system("/etc/init.d/mac start");
	system("sync");
	system("reboot");
}

void retrieveDateAndTime(struct tm *pTmCallTime, char *pchDateTime) {
  // Format 'YYYY-MM-DD HH:MM:SS'
  strftime(pchDateTime, LENGTH_DATETIME_PARAM, "%Y-%m-%d %H:%M:%S", pTmCallTime);
}

int restartSyslog(void) {

	if (system("/etc/init.d/syslog restart") != 0) {
    return ERROR;
  }

	return SUCCESS;
}

int fileExist(char *pchFile) {

	struct stat buffer;

	return (stat(pchFile, &buffer) == 0);
}
