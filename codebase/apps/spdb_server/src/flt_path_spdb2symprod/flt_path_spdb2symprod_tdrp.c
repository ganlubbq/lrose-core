/*******************************************
 * flt_path_spdb2symprod_tdrp.c
 *
 * TDRP C code file 'flt_path_spdb2symprod' module.
 *
 * Code for program flt_path_spdb2symprod
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "flt_path_spdb2symprod_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[21];
static flt_path_spdb2symprod_tdrp_struct *Params;
static char *Module = "flt_path_spdb2symprod";

/*************************************************************
 * flt_path_spdb2symprod_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   flt_path_spdb2symprod_tdrp_struct *params: loads up this struct
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

int flt_path_spdb2symprod_tdrp_load_from_args(int argc, char **argv,
                         flt_path_spdb2symprod_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  flt_path_spdb2symprod_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than flt_path_spdb2symprod_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   flt_path_spdb2symprod_tdrp_struct *params: loads up this struct
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

int flt_path_spdb2symprod_tdrp_load(char *param_file_path,
               flt_path_spdb2symprod_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  flt_path_spdb2symprod_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See flt_path_spdb2symprod_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int flt_path_spdb2symprod_tdrp_load_defaults(flt_path_spdb2symprod_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  flt_path_spdb2symprod_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void flt_path_spdb2symprod_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_print()
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

void flt_path_spdb2symprod_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int flt_path_spdb2symprod_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int flt_path_spdb2symprod_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void flt_path_spdb2symprod_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int flt_path_spdb2symprod_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int flt_path_spdb2symprod_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *flt_path_spdb2symprod_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * flt_path_spdb2symprod_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *flt_path_spdb2symprod_tdrp_init(flt_path_spdb2symprod_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  flt_path_spdb2symprod_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(flt_path_spdb2symprod_tdrp_struct));
  params->struct_size = sizeof(flt_path_spdb2symprod_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'flt_path_spdb2symprod_debug_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("debug level");
  tt->help = tdrpStrDup("Level of debug messages to print.");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug_t");
  tt->enum_def.nfields = 5;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_ERRORS");
    tt->enum_def.fields[1].val = DEBUG_ERRORS;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_MSGS");
    tt->enum_def.fields[2].val = DEBUG_MSGS;
    tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_ROUTINES");
    tt->enum_def.fields[3].val = DEBUG_ROUTINES;
    tt->enum_def.fields[4].name = tdrpStrDup("DEBUG_ALL");
    tt->enum_def.fields[4].val = DEBUG_ALL;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("malloc debug level");
  tt->help = tdrpStrDup("0 = none, 1 = corruption checking, 2 = record all malloc blocks and checks, 3 = printout of all mallocs, etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'wait_msecs' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("wait_msecs");
  tt->descr = tdrpStrDup("wait msecs");
  tt->help = tdrpStrDup("Number of milliseconds to wait before timing out socket operations.");
  tt->val_offset = (char *) &(pp.wait_msecs) - (char *) &pp;
  tt->single_val.l = 100;
  tt++;
  
  /* Parameter 'database_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("database_dir");
  tt->descr = tdrpStrDup("database directory");
  tt->help = tdrpStrDup("Directory containing SPDB database.");
  tt->val_offset = (char *) &(pp.database_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup(".");
  tt++;
  
  /* Parameter 'product_label' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("product_label");
  tt->descr = tdrpStrDup("product label");
  tt->help = tdrpStrDup("The product label used in the SPDB database to uniquely identify this product.");
  tt->val_offset = (char *) &(pp.product_label) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Flight Path Data");
  tt++;
  
  /* Parameter 'product_id' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("product_id");
  tt->descr = tdrpStrDup("product id");
  tt->help = tdrpStrDup("Number which uniquely identifies this product in the SPDB database.");
  tt->val_offset = (char *) &(pp.product_id) - (char *) &pp;
  tt->single_val.l = 400;
  tt++;
  
  /* Parameter 'port' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("port");
  tt->descr = tdrpStrDup("port");
  tt->help = tdrpStrDup("Server port number.");
  tt->val_offset = (char *) &(pp.port) - (char *) &pp;
  tt->single_val.l = 62000;
  tt++;
  
  /* Parameter 'servmap_type' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_type");
  tt->descr = tdrpStrDup("servmap type");
  tt->help = tdrpStrDup("Server mapper type for this server.");
  tt->val_offset = (char *) &(pp.servmap_type) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Spdb");
  tt++;
  
  /* Parameter 'servmap_subtype' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_subtype");
  tt->descr = tdrpStrDup("servmap subtype");
  tt->help = tdrpStrDup("Server mapper subtype for this server.  The type is always Spdb.");
  tt->val_offset = (char *) &(pp.servmap_subtype) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Symprod");
  tt++;
  
  /* Parameter 'servmap_instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("servmap_instance");
  tt->descr = tdrpStrDup("servmap instance");
  tt->help = tdrpStrDup("Server mapper instance for this server.  The type is always Spdb.");
  tt->val_offset = (char *) &(pp.servmap_instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'realtime_avail' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("realtime_avail");
  tt->descr = tdrpStrDup("realtime available flag");
  tt->help = tdrpStrDup("Flag indicating if realtime data is available from this server.");
  tt->val_offset = (char *) &(pp.realtime_avail) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'latest_data_only_for_type' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("latest_data_only_for_type");
  tt->descr = tdrpStrDup("latest data for data type flag");
  tt->help = tdrpStrDup("If TRUE, only the latest data for any data type will be returned by the server.");
  tt->val_offset = (char *) &(pp.latest_data_only_for_type) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'past_polyline_color' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("past_polyline_color");
  tt->descr = tdrpStrDup("past polyline color");
  tt->help = tdrpStrDup("Name of color suggested for rendering the past polyline.");
  tt->val_offset = (char *) &(pp.past_polyline_color) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("gold");
  tt++;
  
  /* Parameter 'future_polyline_color' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("future_polyline_color");
  tt->descr = tdrpStrDup("future polyline color");
  tt->help = tdrpStrDup("Name of color suggested for rendering the future polyline.");
  tt->val_offset = (char *) &(pp.future_polyline_color) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("green");
  tt++;
  
  /* Parameter 'polyline_line_type' */
  /* ctype is 'flt_path_spdb2symprod_line_type_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("polyline_line_type");
  tt->descr = tdrpStrDup("polyline line type");
  tt->help = tdrpStrDup("Type of line suggested for rendering the polyline.");
  tt->val_offset = (char *) &(pp.polyline_line_type) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("line_type_t");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("LINE_TYPE_SOLID");
    tt->enum_def.fields[0].val = LINE_TYPE_SOLID;
    tt->enum_def.fields[1].name = tdrpStrDup("LINE_TYPE_DASH");
    tt->enum_def.fields[1].val = LINE_TYPE_DASH;
    tt->enum_def.fields[2].name = tdrpStrDup("LINE_TYPE_DOT_DASH");
    tt->enum_def.fields[2].val = LINE_TYPE_DOT_DASH;
  tt->single_val.e = LINE_TYPE_SOLID;
  tt++;
  
  /* Parameter 'polyline_line_width' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("polyline_line_width");
  tt->descr = tdrpStrDup("polyline width");
  tt->help = tdrpStrDup("Width of line suggested for rendering the polyline.");
  tt->val_offset = (char *) &(pp.polyline_line_width) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 1;
  tt->single_val.l = 1;
  tt++;
  
  /* Parameter 'polyline_capstyle' */
  /* ctype is 'flt_path_spdb2symprod_capstyle_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("polyline_capstyle");
  tt->descr = tdrpStrDup("polyline capstyle");
  tt->help = tdrpStrDup("Capstyle of line suggested for rendering the polyline.");
  tt->val_offset = (char *) &(pp.polyline_capstyle) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("capstyle_t");
  tt->enum_def.nfields = 4;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("CAPSTYLE_BUTT");
    tt->enum_def.fields[0].val = CAPSTYLE_BUTT;
    tt->enum_def.fields[1].name = tdrpStrDup("CAPSTYLE_NOT_LAST");
    tt->enum_def.fields[1].val = CAPSTYLE_NOT_LAST;
    tt->enum_def.fields[2].name = tdrpStrDup("CAPSTYLE_PROJECTING");
    tt->enum_def.fields[2].val = CAPSTYLE_PROJECTING;
    tt->enum_def.fields[3].name = tdrpStrDup("CAPSTYLE_ROUND");
    tt->enum_def.fields[3].val = CAPSTYLE_ROUND;
  tt->single_val.e = CAPSTYLE_BUTT;
  tt++;
  
  /* Parameter 'polyline_join_style' */
  /* ctype is 'flt_path_spdb2symprod_join_style_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("polyline_join_style");
  tt->descr = tdrpStrDup("polyline join style");
  tt->help = tdrpStrDup("Join style of line suggested for rendering the polyline.");
  tt->val_offset = (char *) &(pp.polyline_join_style) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("join_style_t");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("JOIN_STYLE_BEVEL");
    tt->enum_def.fields[0].val = JOIN_STYLE_BEVEL;
    tt->enum_def.fields[1].name = tdrpStrDup("JOIN_STYLE_MITER");
    tt->enum_def.fields[1].val = JOIN_STYLE_MITER;
    tt->enum_def.fields[2].name = tdrpStrDup("JOIN_STYLE_ROUND");
    tt->enum_def.fields[2].val = JOIN_STYLE_ROUND;
  tt->single_val.e = JOIN_STYLE_BEVEL;
  tt++;
  
  /* Parameter 'curr_pos_icon_color' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("curr_pos_icon_color");
  tt->descr = tdrpStrDup("current position icon color");
  tt->help = tdrpStrDup("Suggested color for rendering the current position icon.");
  tt->val_offset = (char *) &(pp.curr_pos_icon_color) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("green");
  tt++;
  
  /* Parameter 'curr_pos_icon' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("curr_pos_icon");
  tt->descr = tdrpStrDup("current position icon");
  tt->help = tdrpStrDup("Array defining the icon to be used for the current positions.  The icon is a bit-mapped 16x16 icon.  You put 1's in the positions of the icon where the bit should be displayed, and 0's in the positions that are not a part of the icon.  You may want to look at an example parameter file to see how this is done.");
  tt->val_offset = (char *) &(pp.curr_pos_icon.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.curr_pos_icon.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._curr_pos_icon) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.curr_pos_icon_n) - (char *) &pp;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(long);
  tt->array_n = 1;
  tt->array_vals = (tdrpVal_t *)
      tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt->array_vals[0].l = 0;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
