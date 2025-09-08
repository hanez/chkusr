/*
 * Author: Johannes Findeisen <you@hanez.org> - 2025
 * Homepage: https://git.xw3.org/hanez/chkusr
 * License: Apache-2.0 (see LICENSE)
 */

#define VERSION "1.5.1"

/* For chkgrp */
#ifndef MAX_LINE
#define MAX_LINE 1024
#endif

/* MAX_NAME is also used by chkpwd */
#ifndef MAX_NAME
#define MAX_NAME 256
#endif

/* For chkpwd; Also uses MAX_NAME from chkgrp above */
#ifndef MAX_PASSWORD
#define MAX_PASSWORD 256
#endif

#ifndef MAX_UID
#define MAX_UID 1000
#endif

#ifndef MIN_UID
#define MIN_UID 1000
#endif

/* For chkpwr */
#ifndef MAX_PASSWORD_LENGTH
#define MAX_PASSWORD_LENGTH 32
#endif

#ifndef MIN_PASSWORD_LENGTH
#define MIN_PASSWORD_LENGTH 12
#endif

#ifndef MIN_LOWERCASE
#define MIN_LOWERCASE 2
#endif

#ifndef MIN_UPPERCASE
#define MIN_UPPERCASE 2
#endif

#ifndef MIN_DIGITS
#define MIN_DIGITS 2
#endif

#ifndef MIN_SPECIAL
#define MIN_SPECIAL 2
#endif

