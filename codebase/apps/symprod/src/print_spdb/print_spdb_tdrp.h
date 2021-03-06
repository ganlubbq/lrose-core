/*******************************************
 * print_spdb_tdrp.h
 *
 * TDRP header file for 'print_spdb' module.
 *
 * Code for program print_spdb
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef _print_spdb_tdrp_h
#define _print_spdb_tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

typedef enum {
  DEBUG_OFF = 0,
  DEBUG_WARNINGS = 1,
  DEBUG_NORM = 2,
  DEBUG_EXTRA = 3
} print_spdb_debug;

/*
 * typedef for main struct - print_spdb_tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** debug *****/

  print_spdb_debug debug;

  /***** malloc_debug_level *****/

  long malloc_debug_level;

  /***** data_base_dir *****/

  char* data_base_dir;

  /***** string_len *****/

  long string_len;

  /***** decode_chunks *****/

  tdrp_bool_t decode_chunks;

  /***** full_printout *****/

  tdrp_bool_t full_printout;

  /***** data_format *****/

  struct {
    char* *val;
    int len;
  } data_format;
  char* *_data_format;
  int data_format_n;

  /***** time_margin *****/

  long time_margin;

} print_spdb_tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * print_spdb_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   print_spdb_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int print_spdb_tdrp_load_from_args(int argc, char **argv,
                                print_spdb_tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * print_spdb_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than print_spdb_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   print_spdb_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int print_spdb_tdrp_load(char *param_file_path,
                      print_spdb_tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * print_spdb_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See print_spdb_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int print_spdb_tdrp_load_defaults(print_spdb_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * print_spdb_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void print_spdb_tdrp_sync(void);

/*************************************************************
 * print_spdb_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

extern void print_spdb_tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * print_spdb_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void print_spdb_tdrp_free_all(void);

/*************************************************************
 * print_spdb_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int print_spdb_tdrp_check_all_set(FILE *out);

/*************************************************************
 * print_spdb_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int print_spdb_tdrp_check_is_set(char *param_name);

/*************************************************************
 * print_spdb_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int print_spdb_tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * print_spdb_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int print_spdb_tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * print_spdb_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *print_spdb_tdrp_table(void);

/*************************************************************
 * print_spdb_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *print_spdb_tdrp_init(print_spdb_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

