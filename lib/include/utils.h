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

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 * INCLUDES
 **************************************************************************/
#include <syslog.h>
#include <standard-types.h>

/**************************************************************************
 * DEFINITIONS
 **************************************************************************/

#define LENGTH_DATETIME_PARAM	40
#define USLEEP_MAX            (1000000 - 1)

#ifndef	ERROR
  #define	ERROR	-1
#endif

#ifndef	SUCCESS
  #define	SUCCESS	0
#endif

#define UNUSED_PARAMETER(x) (void)(x)

/* Number of elements in an array */
#define LENGTHOF(x) (sizeof(x) / sizeof((x)[0]))

#define EMPTY_VALUE		0x00
#define POINTER_NULL  '\0'

#define INVALID_FUNCTION_RET 	-1

#define SYSLOG_RESTART_COMMAND  "/etc/init.d/syslog restart"

#if !defined( MAX )
  #define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#if !defined( MIN )
  #define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#if !defined( max )
  #define max(a,b) ((a)>(b)?(a):(b))
#endif

#if !defined( min )
  #define min(a,b) ((a)<(b)?(a):(b))
#endif

#define log(str,...)      	PRINT_LOG((LOG_DEBUG | LOG_INFO),str,##__VA_ARGS__)
#define log_error(str,...)  PRINT_ERROR_LOG(LOG_ERR,str,##__VA_ARGS__)

#if 1 // SYSLOG or PRINTF
  #define PRINT_LOG(out,str,...)        syslog(out, "%s | %s() | "str" | %d", THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
  #define PRINT_ERROR_LOG(out,str,...)  syslog(out, "#Error# %s | %s() | "str" | %d", THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
#else
	#define PRINT_LOG(out,str,...)        printf("%s | %s() | "str" | %d\n",THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
  #define PRINT_ERROR_LOG(out,str,...)  printf("#Error# %s | %s() | "str" | %d\n",THIS_FILE,__FUNCTION__,##__VA_ARGS__,__LINE__)
#endif

/*************************************************************************
 * LIB FUNCTIONS
 *************************************************************************/

/**
 * Millisleep on system.
 *
 * @param nMsec time in millisecond.
 */
int u_msleep(int nMsec);

/**
 * Open syslog to start log capture.
 *
 * @param pchLogAppName pointer to application name.
 * @param facility facility number to be used on logs.
 */
void u_log_open(char *pchLogAppName, int facility);

/**
 * Close log capture.
 */
void u_log_close();

/**
 * Reset the board. Reboot command.
 */
void u_reset_board();

/**
 * Restore configuration to default.
 */
void u_restore_config();

/**
 * Retrieves date and time from system in format %Y-%m-%d %H:%M:%S.
 *
 * @param pTmCallTime pointer to parameters that need to be load.
 *
 * @return pchDateTime pointer to date and time.
 */
void u_retrieve_date_time(struct tm *pTmCallTime, char *pchDateTime);

/**
 * Restart syslog script.
 */
int u_restart_syslog();

/**
 * Check if file exist.
 *
 * @param pchFile pointer to file name.
 *
 * @return int Indicate if file exist.
 */
bool u_file_exist(char *pchFile);

#ifdef __cplusplus
}
#endif

#endif
