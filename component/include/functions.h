#include "mashatypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Separator a string
 * @param source_string the string to be separated
 * @param separator the string used to separate source_string
 * @return the position of separator in source_string on success
 *         -1 on failed
 */ 
int stringSeparate(const char *source_string, const char *separator);

/** Copy size bytes source_string to dest
 * @param dest destiny array 
 * @param source_string source string to be copy
 * @param separator the char used to separate source_string
 * @param size capacity of dest array
 * @return NULL on failed 
 *         Next position in source_string on success
 */
const char *cLoopCopy(char *dest, const char *source_string, const char separator, BufferSize_t size);
