/* editor.h - public interface for the ultra-minimal line editor
   Extracted from editor.c so other translation units can interact
   with the editor or re-use its primitives.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#ifndef EDITOR_H
#define EDITOR_H

#include <stddef.h>   /* for size_t */

/*--------------------------------------------------------------------
  Compile-time limits
  (guarded so we do not complain if already defined elsewhere)
 --------------------------------------------------------------------*/
#ifndef MAX_LINES
#define MAX_LINES 1000
#endif

#ifndef MAX_LINE_LEN
#define MAX_LINE_LEN 1024
#endif


/*--------------------------------------------------------------------
  Global text buffer (very small editor = very small global state)
 --------------------------------------------------------------------*/
extern char *lines[MAX_LINES];   /* dynamically allocated lines       */
extern size_t line_count;        /* number of active lines in buffer  */

/*--------------------------------------------------------------------
  File I/O helpers
 --------------------------------------------------------------------*/
void load_file(const char *filename);
void save_file(const char *filename);

/*--------------------------------------------------------------------
  Buffer manipulation
 --------------------------------------------------------------------*/
void insert_line(size_t index, const char *text);   /* 1-based index */
void delete_line(size_t index);                     /* 1-based index */

/*--------------------------------------------------------------------
  UI helpers
 --------------------------------------------------------------------*/
void draw_buffer(void);
void run_editor(const char *filename);

#endif /* editor_H */
