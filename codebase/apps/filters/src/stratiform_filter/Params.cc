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
// Code for program stratiform_filter
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
    tt->comment_hdr = tdrpStrDup("stratiform_filter attempts to filter the stratiform regions from radar data stored in an MDV file.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters helpful in debugging problems with the process.");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("debug flag");
    tt->help = tdrpStrDup("Debug flag.");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS REGISTRATION PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters for registering process information.");
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
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("PROCESS OPERATIONS PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters for controlling process operations (e.g. realtime vs. archive mode).");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("process mode");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("REALTIME_MODE");
      tt->enum_def.fields[0].val = REALTIME_MODE;
      tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE_MODE");
      tt->enum_def.fields[1].val = ARCHIVE_MODE;
    tt->single_val.e = REALTIME_MODE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("PROCESS I/O PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters describing the input and output locations.");
    tt++;
    
    // Parameter 'input_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_url");
    tt->descr = tdrpStrDup("Input URL");
    tt->help = tdrpStrDup("RAP URL that describes the location of the input data.\nFor data on local disk, this can just be the directory containing the input MDV files.  For data retrieved from a server, it is the URL for the server.  A server URL looks like the following:\n\tmdvp:://host:port:directory_path\nThis URL specifies a DsMdvServer process running on the specified host and using the specified port.  The data would reside on the specified host under $RAP_DATRA_DIR/directory_path.");
    tt->val_offset = (char *) &input_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://host:port:directory_path");
    tt++;
    
    // Parameter 'max_valid_age'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("max_valid_age");
    tt->descr = tdrpStrDup("maximum valid age for a realtime file");
    tt->help = tdrpStrDup("The maximum valid age, in seconds, for a realtime file. In REALTIME_MODE, the process will only process files which are younger than this age.  In ARCHIVE_MODE, this parameter is ignored.");
    tt->val_offset = (char *) &max_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 3600;
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL");
    tt->help = tdrpStrDup("RAP URL that describes the location where the output should be written.\nFor data on local disk, this can just be the directory containing the input MDV files.  For data retrieved from a server, it is the URL for the server.  A server URL looks like the following:\n\tmdvp:://host:port:directory_path\nThis URL specifies a DsMdvServer process running on the specified host and using the specified port.  The data would reside on the specified host under $RAP_DATRA_DIR/directory_path.");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://host:port:directory_path");
    tt++;
    
    // Parameter 'field_name_for_convective_input_data'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("field_name_for_convective_input_data");
    tt->descr = tdrpStrDup("Field name for input data in convective regions.");
    tt->help = tdrpStrDup("The input data is filtered to only include the convective parts.");
    tt->val_offset = (char *) &field_name_for_convective_input_data - &_start_;
    tt->single_val.s = tdrpStrDup("conv partitioned data");
    tt++;
    
    // Parameter 'field_name_for_partition_flag'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("field_name_for_partition_flag");
    tt->descr = tdrpStrDup("Field name for the partition flag.");
    tt->help = tdrpStrDup("0: missing; 1: stratiform; 2: convective.");
    tt->val_offset = (char *) &field_name_for_partition_flag - &_start_;
    tt->single_val.s = tdrpStrDup("conv partition");
    tt++;
    
    // Parameter 'field_name_for_background_mean'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("field_name_for_background_mean");
    tt->descr = tdrpStrDup("Field name for the background mean.");
    tt->help = tdrpStrDup("This is the mean reflectivity in the background template.");
    tt->val_offset = (char *) &field_name_for_background_mean - &_start_;
    tt->single_val.s = tdrpStrDup("conv means");
    tt++;
    
    // Parameter 'include_input_field'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_input_field");
    tt->descr = tdrpStrDup("Flag indicating whether to add the input field to the output file.");
    tt->help = tdrpStrDup("If the input data is composited, the output field will be the composited field.");
    tt->val_offset = (char *) &include_input_field - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'include_debug_fields'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_debug_fields");
    tt->descr = tdrpStrDup("Write excess and threshold fields to output file");
    tt->help = tdrpStrDup("These may be useful for understanding what the algorithm is doing. The excess field is (input_dbz - background_dbz). The threshold field is computed using the value_diff_func (see below) with the input_dbz as the argument.");
    tt->val_offset = (char *) &include_debug_fields - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters defining how the algorithm will work.\nThis program is an implementation of the stratiform identification algorithm described by Steiner, etal in \"Climatological Characterization of Three-Dimensional Storm Structure from Operation Radar and Rain Guage Data\" in the Journal of Applied Meteorology, Sept. 1995, vol. 34, pp. 1983-1990.");
    tt++;
    
    // Parameter 'field_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("field_num");
    tt->descr = tdrpStrDup("field number to use for algorithm");
    tt->help = tdrpStrDup("The algorithm will only be run on this field.");
    tt->val_offset = (char *) &field_num - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'do_composite'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("do_composite");
    tt->descr = tdrpStrDup("To composite the input data or not.");
    tt->help = tdrpStrDup("If TRUE a composite is done between lower_comp_vlevel and upper_comp_vlevel - if FALSE then the level specified by level_num is used.");
    tt->val_offset = (char *) &do_composite - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'level_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("level_num");
    tt->descr = tdrpStrDup("level number to use for algorithm if do_composite is FALSE");
    tt->help = tdrpStrDup("The algorithm will only be run on this level.  For reflectivity, this level should be below the 0 degree C level.");
    tt->val_offset = (char *) &level_num - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 0;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'lower_comp_vlevel'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("lower_comp_vlevel");
    tt->descr = tdrpStrDup("lower vlevel for compositing if do_composite is TRUE");
    tt->help = tdrpStrDup("Use the right units.");
    tt->val_offset = (char *) &lower_comp_vlevel - &_start_;
    tt->single_val.f = -1;
    tt++;
    
    // Parameter 'upper_comp_vlevel'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("upper_comp_vlevel");
    tt->descr = tdrpStrDup("upper vlevel for compositing if do_composite is TRUE");
    tt->help = tdrpStrDup("Use the right units.");
    tt->val_offset = (char *) &upper_comp_vlevel - &_start_;
    tt->single_val.f = 100000;
    tt++;
    
    // Parameter 'data_increasing'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("data_increasing");
    tt->descr = tdrpStrDup("Set to true for data such as Radar were convection is defined by increasing data values. Choose false for data such as satellite IR were convection is defined by decreasing data values.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &data_increasing - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'conv_center_min'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("conv_center_min");
    tt->descr = tdrpStrDup("convective center min/max data value");
    tt->help = tdrpStrDup("Any grid point with a value greater than or equal to this value (less than or equal to if data_increasing flag is set to false) will automatically be considered a convective center.  This is used in criteria 1 for determining convective centers in the algorithm.");
    tt->val_offset = (char *) &conv_center_min - &_start_;
    tt->single_val.d = 40;
    tt++;
    
    // Parameter 'background_min_dbz'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("background_min_dbz");
    tt->descr = tdrpStrDup("Minimum dbz for analysis");
    tt->help = tdrpStrDup("Any values less than this are ignored when computing the background.");
    tt->val_offset = (char *) &background_min_dbz - &_start_;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'background_radius'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("background_radius");
    tt->descr = tdrpStrDup("background radius in grid units");
    tt->help = tdrpStrDup("The radius of the circle used to calculate the mean background value at each point in the grid.");
    tt->val_offset = (char *) &background_radius - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0;
    tt->single_val.d = 11;
    tt++;
    
    // Parameter 'value_diff_func'
    // ctype is '_value_diff_func_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("value_diff_func");
    tt->descr = tdrpStrDup("value difference function definition");
    tt->help = tdrpStrDup("This parameter defines the function to be used to see if a possible convective center satisfies the peakedness criteria. This function is a continuous function.  Difference values for mean background values not given in the function definition will be calculated by linearly interpolating between the surrounding given points.  Value before the minimum and after the maximum defined are considered to remain constant.  In this array, the function must be defined with the values for the mean_bkgnd_value field strictly increasing.  The default values for this parameter mirror the function given in figure 7 in the above referenced paper.");
    tt->array_offset = (char *) &_value_diff_func - &_start_;
    tt->array_n_offset = (char *) &value_diff_func_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(value_diff_func_t);
    tt->array_n = 6;
    tt->struct_def.name = tdrpStrDup("value_diff_func_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("mean_bkgnd_value");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_value_diff_func->mean_bkgnd_value - (char *) _value_diff_func;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("value_difference");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_value_diff_func->value_difference - (char *) _value_diff_func;
    tt->n_struct_vals = 12;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 0;
      tt->struct_vals[1].d = 10;
      tt->struct_vals[2].d = 10;
      tt->struct_vals[3].d = 9.44;
      tt->struct_vals[4].d = 20;
      tt->struct_vals[5].d = 7.78;
      tt->struct_vals[6].d = 30;
      tt->struct_vals[7].d = 5;
      tt->struct_vals[8].d = 40;
      tt->struct_vals[9].d = 1.11;
      tt->struct_vals[10].d = 42.43;
      tt->struct_vals[11].d = 0;
    tt++;
    
    // Parameter 'conv_area_radius_func'
    // ctype is '_conv_area_radius_func_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("conv_area_radius_func");
    tt->descr = tdrpStrDup("convective area radius function definition");
    tt->help = tdrpStrDup("This parameter defines the function to be used to calculate the convective area radius.  This function is taken as a step function where mean_bkgnd_value gives the beginning of the step and conv_radius gives the radius value, in grid squares, used at that step.  conv_radius retains the first function value before the first step and retains the last value forever on the last step. In this array, the steps must be given in ascending order of the mean_bkgnd_value.  The default values for this parameter mirror the function given in figure 6(b) in the above referenced paper.");
    tt->array_offset = (char *) &_conv_area_radius_func - &_start_;
    tt->array_n_offset = (char *) &conv_area_radius_func_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(conv_area_radius_func_t);
    tt->array_n = 5;
    tt->struct_def.name = tdrpStrDup("conv_area_radius_func_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("mean_bkgnd_value");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_conv_area_radius_func->mean_bkgnd_value - (char *) _conv_area_radius_func;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("conv_radius");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_conv_area_radius_func->conv_radius - (char *) _conv_area_radius_func;
    tt->n_struct_vals = 10;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 0;
      tt->struct_vals[1].d = 1;
      tt->struct_vals[2].d = 25;
      tt->struct_vals[3].d = 2;
      tt->struct_vals[4].d = 30;
      tt->struct_vals[5].d = 3;
      tt->struct_vals[6].d = 35;
      tt->struct_vals[7].d = 4;
      tt->struct_vals[8].d = 40;
      tt->struct_vals[9].d = 5;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
