/**************************************************************************
 * utils.h
 *
 *  Create on: 21/06/2019
 *
 *  Header for utils tasks
 *
 * Copyrights, 2019
 *
 **************************************************************************/
#ifndef __UTILS_H__
#define __UTILS_H__

/**************************************************************************
 * INCLUDES
 **************************************************************************/
#include <syslog.h>

/**************************************************************************
 * DEFINITIONS
 **************************************************************************/

#define LENGTH_DATETIME_PARAM	40
#define USLEEP_MAX            (1000000 - 1)

#define TRUE      1
#define FALSE     0

#define ERROR	    -1
#define SUCCESS	  0

#define EMPTY_VALUE		0x00
#define POINTER_NULL  '\0'

#define INVALID_FUNCTION_RET 	-1

#define log(str,...)      	PRINT_LOG((LOG_DEBUG | LOG_INFO),str,##__VA_ARGS__)
#define log_error(str,...)  PRINT_ERROR_LOG(LOG_ERR,str,##__VA_ARGS__)

#if 1 // SYSLOG or PRINTF
  #define PRINT_LOG(out,str,...)                syslog(out, "%s | %s() | "str" | %d", THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
  #define PRINT_ERROR_LOG(out,str,...)          syslog(out, "#Error# %s | %s() | "str" | %d", THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
#else
	#define PRINT_LOG(out,str,...)                printf("%s | %s() | "str" | %d\n",THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
  #define PRINT_ERROR_LOG(out,str,...)          printf("#Error# %s | %s() | "str" | %d\n",THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
#endif

/*************************************************************************
 * LIB FUNCTIONS
 *************************************************************************/

int u_msleep(int nMsec);

void u_log_open(char *pchLogAppName, int facility);

void u_log_close();

void u_reset_board();

void u_restore_config();

void u_retrieve_date_time(struct tm *pTmCallTime, char *pchDateTime);

int u_restart_syslog(void);

int u_file_exist(char *pchFile);

#endif
