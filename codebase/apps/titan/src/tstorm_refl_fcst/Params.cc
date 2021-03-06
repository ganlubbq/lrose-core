// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2017
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program tstorm_refl_fcst
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug_level'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug_level");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug_level - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_WARNINGS");
      tt->enum_def.fields[1].val = DEBUG_WARNINGS;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[2].val = DEBUG_NORM;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'malloc_debug_level'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("malloc_debug_level");
    tt->descr = tdrpStrDup("Malloc debug level");
    tt->help = tdrpStrDup("0 - none,\n1 - corruption checking,\n2 - records all malloc blocks and checks,\n3 - printout of all mallocs etc.");
    tt->val_offset = (char *) &malloc_debug_level - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.l = 0;
    tt->max_val.l = 3;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operational mode");
    tt->help = tdrpStrDup("Realtime mode - waits for new data;\narchive mode runs on file list");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[0].val = REALTIME;
      tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[1].val = ARCHIVE;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'storm_data_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("storm_data_url");
    tt->descr = tdrpStrDup("Input URL for storm data");
    tt->help = tdrpStrDup("The is the SPDB database directory for the storm data for which we'll keep the storm shapes but update the vectors.");
    tt->val_offset = (char *) &storm_data_url - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://host::directory");
    tt++;
    
    // Parameter 'gridded_data_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("gridded_data_url");
    tt->descr = tdrpStrDup("Input URL for gridded data");
    tt->help = tdrpStrDup("The is the directory which contains the gridded data, in MDV format, that will be extrapolated based on the storms and their motions.");
    tt->val_offset = (char *) &gridded_data_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://host::directory");
    tt++;
    
    // Parameter 'use_gridded_field_num'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_gridded_field_num");
    tt->descr = tdrpStrDup("Flag indicating whether to use field name or number for identifying the gridded field.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &use_gridded_field_num - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'gridded_field_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("gridded_field_num");
    tt->descr = tdrpStrDup("Field number for gridded data in MDV files");
    tt->help = tdrpStrDup("Used only if use_gridded_field_num is set to true");
    tt->val_offset = (char *) &gridded_field_num - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'gridded_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("gridded_field_name");
    tt->descr = tdrpStrDup("Field name for gridded data in MDV files");
    tt->help = tdrpStrDup("Used only if use_gridded_field_num is set to false");
    tt->val_offset = (char *) &gridded_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("DBZ");
    tt++;
    
    // Parameter 'max_valid_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_valid_age");
    tt->descr = tdrpStrDup("Maximum valid age in seconds for input data");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 3600;
    tt++;
    
    // Parameter 'time_offset_max'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("time_offset_max");
    tt->descr = tdrpStrDup("Maximum data offset time in seconds");
    tt->help = tdrpStrDup("Maximum amount of time allowed between the base storm data time and the gridded data time for the data to be used together.");
    tt->val_offset = (char *) &time_offset_max - &_start_;
    tt->single_val.l = 150;
    tt++;
    
    // Parameter 'sleep_msecs'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("sleep_msecs");
    tt->descr = tdrpStrDup("Sleep msecs between checks for new data");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sleep_msecs - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 1000;
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://host::directory");
    tt++;
    
    // Parameter 'output_empty_grids'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_empty_grids");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("Flag indicating whether a forecast grid should be created if no storms in the forecast are valid.  This flag was added because we were having data outage problems with the system that were adversely affecting our statistics.");
    tt->val_offset = (char *) &output_empty_grids - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'output_time_offsets'
    // ctype is '_time_offsets_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_time_offsets");
    tt->descr = tdrpStrDup("Number of seconds to add to the storm time to get the begin and end times for the output grid. The centroid time for the grid will be the storm time and the expire time for the grid will be the same as the end time.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_time_offsets - &_start_;
    tt->struct_def.name = tdrpStrDup("time_offsets_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("long");
      tt->struct_def.fields[0].fname = tdrpStrDup("begin_time_offset");
      tt->struct_def.fields[0].ptype = LONG_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &output_time_offsets.begin_time_offset - (char *) &output_time_offsets;
      tt->struct_def.fields[1].ftype = tdrpStrDup("long");
      tt->struct_def.fields[1].fname = tdrpStrDup("end_time_offset");
      tt->struct_def.fields[1].ptype = LONG_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &output_time_offsets.end_time_offset - (char *) &output_time_offsets;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].l = -150;
      tt->struct_vals[1].l = 150;
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'file_time_stamp'
    // ctype is '_file_time_stamp_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("file_time_stamp");
    tt->descr = tdrpStrDup("File time stamp");
    tt->help = tdrpStrDup("If GENERATE_TIME, file names match generate data time.\nIf FORECAST_TIME, file names match forecast time.");
    tt->val_offset = (char *) &file_time_stamp - &_start_;
    tt->enum_def.name = tdrpStrDup("file_time_stamp_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("GENERATE_TIME");
      tt->enum_def.fields[0].val = GENERATE_TIME;
      tt->enum_def.fields[1].name = tdrpStrDup("FORECAST_TIME");
      tt->enum_def.fields[1].val = FORECAST_TIME;
    tt->single_val.e = GENERATE_TIME;
    tt++;
    
    // Parameter 'forecast_durations'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("forecast_durations");
    tt->descr = tdrpStrDup("Forecast durations (secs)");
    tt->help = tdrpStrDup("Array of duration of precip forecast map.  If file_time_stamp is GENERATE_TIME, only the first duration is used, the rest are ignored.");
    tt->array_offset = (char *) &_forecast_durations - &_start_;
    tt->array_n_offset = (char *) &forecast_durations_n - &_start_;
    tt->has_min = TRUE;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(long);
    tt->array_n = 1;
    tt->min_val.l = 0;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].l = 1800;
    tt++;
    
    // Parameter 'round_forecast_times'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("round_forecast_times");
    tt->descr = tdrpStrDup("Option to round the forecast times");
    tt->help = tdrpStrDup("The interval used is given by the rounding_interval parameter.");
    tt->val_offset = (char *) &round_forecast_times - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'rounding_interval'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("rounding_interval");
    tt->descr = tdrpStrDup("Rounding interval for forecast times (secs)");
    tt->help = tdrpStrDup("If round_forecast_times is TRUE, the forecast times are rounded to this interval");
    tt->val_offset = (char *) &rounding_interval - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.l = 10;
    tt->max_val.l = 86400;
    tt->single_val.l = 600;
    tt++;
    
    // Parameter 'set_vlevel_limits'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_vlevel_limits");
    tt->descr = tdrpStrDup("Option to set plane vlevel limits");
    tt->help = tdrpStrDup("If false, composite is done over all vertical levels.");
    tt->val_offset = (char *) &set_vlevel_limits - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'lower_vlevel'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("lower_vlevel");
    tt->descr = tdrpStrDup("Lower plane vlevel limit.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &lower_vlevel - &_start_;
    tt->single_val.f = 3;
    tt++;
    
    // Parameter 'upper_vlevel'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("upper_vlevel");
    tt->descr = tdrpStrDup("Upper plane vlevel limit.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &upper_vlevel - &_start_;
    tt->single_val.f = 6;
    tt++;
    
    // Parameter 'thresholded_forecast'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("thresholded_forecast");
    tt->descr = tdrpStrDup("Option to produce thresholded forecast");
    tt->help = tdrpStrDup("Thresholded forecast uses individual storm motion. Unthresholded forecast uses area-weighted mean storm motion.");
    tt->val_offset = (char *) &thresholded_forecast - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'valid_forecasts_only'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("valid_forecasts_only");
    tt->descr = tdrpStrDup("Valid forecasts only flag");
    tt->help = tdrpStrDup("If set, only valid forecasts will be mapped. If not, all forecasts will be mapped.");
    tt->val_offset = (char *) &valid_forecasts_only - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'use_decay_trending'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_decay_trending");
    tt->descr = tdrpStrDup("Flag to include decay trending in forecast");
    tt->help = tdrpStrDup("If set, the decay trend will be used to calculate storm size.");
    tt->val_offset = (char *) &use_decay_trending - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'use_growth_trending'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_growth_trending");
    tt->descr = tdrpStrDup("Flag to include growth trending in forecast");
    tt->help = tdrpStrDup("If set, the growth trend will be used to calculate storm size.");
    tt->val_offset = (char *) &use_growth_trending - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'use_decay_intensity_trending'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_decay_intensity_trending");
    tt->descr = tdrpStrDup("Flag to include intensity decay trending in forecast");
    tt->help = tdrpStrDup("If set, the decay trend will be used to trend the intensity in storms smaller than max_intensity_trend_size.");
    tt->val_offset = (char *) &use_decay_intensity_trending - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'use_growth_intensity_trending'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_growth_intensity_trending");
    tt->descr = tdrpStrDup("Flag to include intensity growth trending in forecast");
    tt->help = tdrpStrDup("If set, the growth trend will be used to trend the intensity in storms smaller than max_intensity_trend_size.");
    tt->val_offset = (char *) &use_growth_intensity_trending - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'max_intensity_trend_size'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_intensity_trend_size");
    tt->descr = tdrpStrDup("Maximum storm size in km**2 or km**3 for intensity trending.");
    tt->help = tdrpStrDup("Used only if use_decay_intensity_trending or use_growth_intensity_trending is true.");
    tt->val_offset = (char *) &max_intensity_trend_size - &_start_;
    tt->single_val.d = 1000;
    tt++;
    
    // Parameter 'intensity_base_value'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("intensity_base_value");
    tt->descr = tdrpStrDup("Base value for intensity growth/decay");
    tt->help = tdrpStrDup("When growing or decaying the intensity of a grid point, this value is subtracted from the original grid value, then the growth/decay percentage is applied, then this value is added back in. This allows us to grow and decay intensities of fields that aren't centered around a 0 value.");
    tt->val_offset = (char *) &intensity_base_value - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'negate_intensity_changes'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("negate_intensity_changes");
    tt->descr = tdrpStrDup("Flag indicating whether to negate the intensity change direction.");
    tt->help = tdrpStrDup("This is used for fields, like the satellite IR fields, that decrease rather than increase.");
    tt->val_offset = (char *) &negate_intensity_changes - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'smooth_polygons'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("smooth_polygons");
    tt->descr = tdrpStrDup("polygon smoothing flag");
    tt->help = tdrpStrDup("If TRUE, the polygons will be smoothed using the constrained convex hull smoothing algorithm before being added to the output file.");
    tt->val_offset = (char *) &smooth_polygons - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'smooth_inner_multiplier'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("smooth_inner_multiplier");
    tt->descr = tdrpStrDup("polygon smoothing inner hull multiplier");
    tt->help = tdrpStrDup("The original polygon radial lengths are multiplied by this value to get the inner polygon for the constrained convex hull smoothing algorithm. This parameter is only used if smooth_polygons is set to TRUE.");
    tt->val_offset = (char *) &smooth_inner_multiplier - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0.001;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'smooth_outer_multiplier'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("smooth_outer_multiplier");
    tt->descr = tdrpStrDup("polygon smoothing outer hull multiplier");
    tt->help = tdrpStrDup("The original polygon radial lengths are multiplied by this value to get the outer polygon for the constrained convex hull smoothing algorithm. This parameter is only used if smooth_polygons is set to TRUE.");
    tt->val_offset = (char *) &smooth_outer_multiplier - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0.001;
    tt->single_val.d = 1;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
