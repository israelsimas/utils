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

int u_msleep(int nMsec) {
  
  int sleepTime = nMsec * 1000;

  if ((sleepTime >= 0) && (sleepTime <= USLEEP_MAX)) {
    return usleep(sleepTime);
  } else if (nMsec >= 0) {
    return sleep(nMsec/1000);
  } else {
    return ERROR;
  }
}

void u_log_open(char *pchLogAppName, int facility) {
  openlog(pchLogAppName, 0, facility);
}

void u_log_close() {
  closelog();
}

void u_reset_board() {
	system("reboot");
}

void u_restore_config() {
	system("rm -rf /data/*");
	system("sync");
	system("/etc/init.d/files_default start");
	system("/etc/init.d/mac start");
	system("sync");
}

void u_retrieve_date_time(struct tm *pTmCallTime, char *pchDateTime) {
  // Format 'YYYY-MM-DD HH:MM:SS'
  strftime(pchDateTime, LENGTH_DATETIME_PARAM, "%Y-%m-%d %H:%M:%S", pTmCallTime);
}

int u_restart_syslog(void) {

	if (system(SYSLOG_RESTART_COMMAND) != 0) {
    return ERROR;
  }

	return SUCCESS;
}

int u_file_exist(char *pchFile) {

	struct stat buffer;

	return (stat(pchFile, &buffer) == 0);
}
