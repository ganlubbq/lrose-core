/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/*******************************************
 * ac_ingest_tdrp.c
 *
 * TDRP C code file 'ac_ingest' module.
 *
 * Code for program ac_ingest
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "ac_ingest_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[16];
static ac_ingest_tdrp_struct *Params;
static char *Module = "ac_ingest";

/*************************************************************
 * ac_ingest_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   ac_ingest_tdrp_struct *params: loads up this struct
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

int ac_ingest_tdrp_load_from_args(int argc, char **argv,
                         ac_ingest_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  ac_ingest_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * ac_ingest_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than ac_ingest_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   ac_ingest_tdrp_struct *params: loads up this struct
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

int ac_ingest_tdrp_load(char *param_file_path,
               ac_ingest_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  ac_ingest_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * ac_ingest_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See ac_ingest_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int ac_ingest_tdrp_load_defaults(ac_ingest_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  ac_ingest_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * ac_ingest_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void ac_ingest_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * ac_ingest_tdrp_print()
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

void ac_ingest_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * ac_ingest_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int ac_ingest_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * ac_ingest_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int ac_ingest_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * ac_ingest_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void ac_ingest_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * ac_ingest_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int ac_ingest_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * ac_ingest_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int ac_ingest_tdrp_array2D_realloc(char *param_name,
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
 * ac_ingest_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *ac_ingest_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * ac_ingest_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *ac_ingest_tdrp_init(ac_ingest_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  ac_ingest_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(ac_ingest_tdrp_struct));
  params->struct_size = sizeof(ac_ingest_tdrp_struct);

  /* Parameter 'debug' */
  /* ctype is 'ac_ingest_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[1].val = DEBUG_NORM;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
    tt->enum_def.fields[2].val = DEBUG_VERBOSE;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("Malloc debug level");
  tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("instance");
  tt->descr = tdrpStrDup("Process instance");
  tt->help = tdrpStrDup("Used for registration with procmap.");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'mode' */
  /* ctype is 'ac_ingest_mode' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Operating mode");
  tt->help = tdrpStrDup("In REALTIME_MODE, the aircraft data is read in from the serial connection. In TEST_MODE, aircraft data is generated for testing purposes.");
  tt->val_offset = (char *) &(pp.mode) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("mode");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("TEST_MODE");
    tt->enum_def.fields[0].val = TEST_MODE;
    tt->enum_def.fields[1].name = tdrpStrDup("REALTIME_MODE");
    tt->enum_def.fields[1].val = REALTIME_MODE;
  tt->single_val.e = REALTIME_MODE;
  tt++;
  
  /* Parameter 'input_device' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("input_device");
  tt->descr = tdrpStrDup("Input serial port: COM 2");
  tt->help = tdrpStrDup("Name of serial device for input data");
  tt->val_offset = (char *) &(pp.input_device) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("/dev/ttyS1");
  tt++;
  
  /* Parameter 'baud_rate' */
  /* ctype is 'ac_ingest_baud_rate' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("baud_rate");
  tt->descr = tdrpStrDup("Baud rate");
  tt->help = tdrpStrDup("Baud rate for incoming serial data port");
  tt->val_offset = (char *) &(pp.baud_rate) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("baud_rate");
  tt->enum_def.nfields = 7;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("BAUD_300");
    tt->enum_def.fields[0].val = BAUD_300;
    tt->enum_def.fields[1].name = tdrpStrDup("BAUD_1200");
    tt->enum_def.fields[1].val = BAUD_1200;
    tt->enum_def.fields[2].name = tdrpStrDup("BAUD_2400");
    tt->enum_def.fields[2].val = BAUD_2400;
    tt->enum_def.fields[3].name = tdrpStrDup("BAUD_4800");
    tt->enum_def.fields[3].val = BAUD_4800;
    tt->enum_def.fields[4].name = tdrpStrDup("BAUD_9600");
    tt->enum_def.fields[4].val = BAUD_9600;
    tt->enum_def.fields[5].name = tdrpStrDup("BAUD_19200");
    tt->enum_def.fields[5].val = BAUD_19200;
    tt->enum_def.fields[6].name = tdrpStrDup("BAUD_38400");
    tt->enum_def.fields[6].val = BAUD_38400;
  tt->single_val.e = BAUD_9600;
  tt++;
  
  /* Parameter 'archive_dir_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("archive_dir_path");
  tt->descr = tdrpStrDup("Archive directory path");
  tt->help = tdrpStrDup("Arcvive files are written to this directory");
  tt->val_offset = (char *) &(pp.archive_dir_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'realtime_file_path' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("realtime_file_path");
  tt->descr = tdrpStrDup("Realtime file path");
  tt->help = tdrpStrDup("The realtime data is written to this path");
  tt->val_offset = (char *) &(pp.realtime_file_path) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'data_interval' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("data_interval");
  tt->descr = tdrpStrDup("Data store interval (secs)");
  tt->help = tdrpStrDup("Time between data store - this is used to keep the data file size reasonable.");
  tt->val_offset = (char *) &(pp.data_interval) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 1;
  tt->max_val.l = 3600;
  tt->single_val.l = 1;
  tt++;
  
  /* Parameter 'use_spdb' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("use_spdb");
  tt->descr = tdrpStrDup("Option to store data using spdb.");
  tt->help = tdrpStrDup("Data will be stored in SPDB - symbolic products data base.");
  tt->val_offset = (char *) &(pp.use_spdb) - (char *) &pp;
  tt->single_val.b = pTRUE;
  tt++;
  
  /* Parameter 'single_database' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("single_database");
  tt->descr = tdrpStrDup("Option to store all aircraft data in a single data-base.");
  tt->help = tdrpStrDup("If TRUE, all data is stored in a single data-base directory, db_dir, regardless of callsign. The chunk type is comuted by hashing the callsign. If FALSE, each callsign has a separate data-base directory, computed as db_dir/callsign.");
  tt->val_offset = (char *) &(pp.single_database) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'db_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("db_dir");
  tt->descr = tdrpStrDup("Data base directory");
  tt->help = tdrpStrDup("The path to the data base directory. See single_database for computing the directory.");
  tt->val_offset = (char *) &(pp.db_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'callsigns' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("callsigns");
  tt->descr = tdrpStrDup("Callsign array");
  tt->help = tdrpStrDup("Array of valid callsigns");
  tt->val_offset = (char *) &(pp.callsigns.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.callsigns.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._callsigns) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.callsigns_n) - (char *) &pp;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(char*);
  tt->array_n = 1;
  tt->array_vals = (tdrpVal_t *)
      tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt->array_vals[0].s = tdrpStrDup("none");
  tt++;
  
  /* Parameter 'valid_period' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("valid_period");
  tt->descr = tdrpStrDup("Valid period (secs)");
  tt->help = tdrpStrDup("Time period over which the position is valid.");
  tt->val_offset = (char *) &(pp.valid_period) - (char *) &pp;
  tt->has_min = TRUE;
  tt->min_val.l = 1;
  tt->single_val.l = 120;
  tt++;
  
  /* Parameter 'test_aircraft' */
  /* ctype is 'ac_ingest_test_aircraft' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRUCT_TYPE;
  tt->param_name = tdrpStrDup("test_aircraft");
  tt->descr = tdrpStrDup("Details of aircraft for TEST_MODE.");
  tt->help = tdrpStrDup("The test aircraft have a starting location, speed (knots) and altitude (ft). They wander randomly around. If they go further that 100 km from their starting location they are brought back to the start.");
  tt->val_offset = (char *) &(pp.test_aircraft.val) - (char *) &pp;
  tt->len_offset = (char *) &(pp.test_aircraft.len) - (char *) &pp;
  tt->array_offset = (char *) &(pp._test_aircraft) - (char *) &pp;
  tt->array_n_offset = (char *) &(pp.test_aircraft_n) - (char *) &pp;
  tt->is_array = TRUE;
  tt->array_len_fixed = FALSE;
  tt->array_elem_size = sizeof(ac_ingest_test_aircraft);
  tt->array_n = 1;
  tt->struct_def.name = tdrpStrDup("test_aircraft");
  tt->struct_def.nfields = 5;
  tt->struct_def.fields = (struct_field_t *)
      tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
    tt->struct_def.fields[0].ftype = tdrpStrDup("double");
    tt->struct_def.fields[0].fname = tdrpStrDup("start_lat");
    tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[0].rel_offset = 
      (char *) &(pp.test_aircraft.val->start_lat) - (char *) pp.test_aircraft.val;
    tt->struct_def.fields[1].ftype = tdrpStrDup("double");
    tt->struct_def.fields[1].fname = tdrpStrDup("start_lon");
    tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[1].rel_offset = 
      (char *) &(pp.test_aircraft.val->start_lon) - (char *) pp.test_aircraft.val;
    tt->struct_def.fields[2].ftype = tdrpStrDup("double");
    tt->struct_def.fields[2].fname = tdrpStrDup("altitude");
    tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[2].rel_offset = 
      (char *) &(pp.test_aircraft.val->altitude) - (char *) pp.test_aircraft.val;
    tt->struct_def.fields[3].ftype = tdrpStrDup("double");
    tt->struct_def.fields[3].fname = tdrpStrDup("speed");
    tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
    tt->struct_def.fields[3].rel_offset = 
      (char *) &(pp.test_aircraft.val->speed) - (char *) pp.test_aircraft.val;
    tt->struct_def.fields[4].ftype = tdrpStrDup("string");
    tt->struct_def.fields[4].fname = tdrpStrDup("callsign");
    tt->struct_def.fields[4].ptype = STRING_TYPE;
    tt->struct_def.fields[4].rel_offset = 
      (char *) &(pp.test_aircraft.val->callsign) - (char *) pp.test_aircraft.val;
  tt->n_struct_vals = 5;
  tt->struct_vals = (tdrpVal_t *)
      tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt->struct_vals[0].d = 0;
    tt->struct_vals[1].d = 0;
    tt->struct_vals[2].d = 0;
    tt->struct_vals[3].d = 0;
    tt->struct_vals[4].s = tdrpStrDup("not_set");
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}