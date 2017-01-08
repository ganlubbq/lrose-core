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
// Code for program ZdrCalSimHv
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
    tt->comment_hdr = tdrpStrDup("ZdrCalSimHv computes the cross-polar ratios between H and V returns, in simulataneous mode. This is used for the cross-polar method of ZDR calibration, in conjunction with SunScan analysis - see SunCal.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[3].val = DEBUG_EXTRA;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'register_with_procmap'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("register_with_procmap");
    tt->descr = tdrpStrDup("Option to register with the process mapper.");
    tt->help = tdrpStrDup("If true, this application will try to register with procmap once per minute. (If unable to do so, no error occurs.)");
    tt->val_offset = (char *) &register_with_procmap - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_mode'
    // ctype is '_input_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("input_mode");
    tt->descr = tdrpStrDup("Input mode - files or time series API.");
    tt->help = tdrpStrDup("If TS_FMQ_INPUT, the application will read the time series from a file message queue and process the pulses as they come in. If TS_FILE_INPUT, the application will process all the files specified on the command line.");
    tt->val_offset = (char *) &input_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("input_mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TS_FILE_INPUT");
      tt->enum_def.fields[0].val = TS_FILE_INPUT;
      tt->enum_def.fields[1].name = tdrpStrDup("TS_FMQ_INPUT");
      tt->enum_def.fields[1].val = TS_FMQ_INPUT;
    tt->single_val.e = TS_FILE_INPUT;
    tt++;
    
    // Parameter 'input_fmq_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_fmq_name");
    tt->descr = tdrpStrDup("FMQ name. For TS_FMQ_INPUT only.");
    tt->help = tdrpStrDup("Path to FMQ files. There are 2 files, one with a .buf extension and one with a .stat extention. This path does not include the extensions.");
    tt->val_offset = (char *) &input_fmq_name - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/fmq/ts");
    tt++;
    
    // Parameter 'max_pulse_queue_size'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_pulse_queue_size");
    tt->descr = tdrpStrDup("Max size of pulse queue.");
    tt->help = tdrpStrDup("The input queue is trimmed to this size. This keeps memory usage under control.");
    tt->val_offset = (char *) &max_pulse_queue_size - &_start_;
    tt->single_val.i = 512;
    tt++;
    
    // Parameter 'max_data_interval_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_data_interval_secs");
    tt->descr = tdrpStrDup("Max time between pulses for valid data (secs).");
    tt->help = tdrpStrDup("If the interval between pulses exceeds this value, the power accumulation arrays will be reset to 0.");
    tt->val_offset = (char *) &max_data_interval_secs - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("ANALYSIS PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'azimuth_resolution'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("azimuth_resolution");
    tt->descr = tdrpStrDup("Resolution of the analysis in azimuth (deg).");
    tt->help = tdrpStrDup("The data is analyzed in evenly-spaced azimuth dwells. This is the angular resolution of the dwells.");
    tt->val_offset = (char *) &azimuth_resolution - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'min_samples_per_dwell'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_samples_per_dwell");
    tt->descr = tdrpStrDup("Min number of samples in an azimuth resolution.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &min_samples_per_dwell - &_start_;
    tt->single_val.i = 16;
    tt++;
    
    // Parameter 'stationary_mode'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("stationary_mode");
    tt->descr = tdrpStrDup("Antenna collects data while stationary.");
    tt->help = tdrpStrDup("In this mode, the power values are averaged for successive H and V time periods, and the ratios are then computed.");
    tt->val_offset = (char *) &stationary_mode - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'n_samples_stationary_mode'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("n_samples_stationary_mode");
    tt->descr = tdrpStrDup("Number of samples in a beam, in stationary mode.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &n_samples_stationary_mode - &_start_;
    tt->single_val.i = 256;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("RANGE LIMITS FOR ANALYSIS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'start_range'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("start_range");
    tt->descr = tdrpStrDup("Start range for analysis (km).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &start_range - &_start_;
    tt->single_val.d = 5;
    tt++;
    
    // Parameter 'end_range'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("end_range");
    tt->descr = tdrpStrDup("End range for analysis (km).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &end_range - &_start_;
    tt->single_val.d = 25;
    tt++;
    
    // Parameter 'gate_spacing'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("gate_spacing");
    tt->descr = tdrpStrDup("Gate spacing for analysis (km).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &gate_spacing - &_start_;
    tt->single_val.d = 0.25;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("AZIMUTH LIMITS FOR ANALYSIS");
    tt->comment_text = tdrpStrDup("Allows you to just analyze a specified sector.");
    tt++;
    
    // Parameter 'start_az'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("start_az");
    tt->descr = tdrpStrDup("Start azimuth for analysis (deg).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &start_az - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'end_az'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("end_az");
    tt->descr = tdrpStrDup("End azimuth for analysis (deg).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &end_az - &_start_;
    tt->single_val.d = 360;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("CPA LIMITS");
    tt->comment_text = tdrpStrDup("CPA - clutter phase alignment - is a good indicator of clutter.");
    tt++;
    
    // Parameter 'min_cpa'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_cpa");
    tt->descr = tdrpStrDup("Minimum CPA for analysis.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &min_cpa - &_start_;
    tt->single_val.d = 0.9;
    tt++;
    
    // Parameter 'max_cpa'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_cpa");
    tt->descr = tdrpStrDup("Maximum CPA for analysis.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_cpa - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("CALIBRATION XML PATH");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'cal_xml_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("cal_xml_file_path");
    tt->descr = tdrpStrDup("Path for XML calibration file.");
    tt->help = tdrpStrDup("At a minimum, the calibration file should contain noiseDbm values for each channel.");
    tt->val_offset = (char *) &cal_xml_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("./spol_cal.xml");
    tt++;
    
    // Parameter 'get_noise_from_time_series'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("get_noise_from_time_series");
    tt->descr = tdrpStrDup("Option to read the noise from the time series data stream.");
    tt->help = tdrpStrDup("Some time series formats (e.g. SIGMET tsarchive) includes noise values. If this parameter is true, the noise is read from the time series and this overrides the calibration file.");
    tt->val_offset = (char *) &get_noise_from_time_series - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 8'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 8");
    tt->comment_hdr = tdrpStrDup("SNR LIMITS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'min_snr'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_snr");
    tt->descr = tdrpStrDup("Minimum SNR for analysis (dB).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &min_snr - &_start_;
    tt->single_val.d = 15;
    tt++;
    
    // Parameter 'max_snr'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_snr");
    tt->descr = tdrpStrDup("Maximum SNR for analysis (dB).");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_snr - &_start_;
    tt->single_val.d = 70;
    tt++;
    
    // Parameter 'Comment 9'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 9");
    tt->comment_hdr = tdrpStrDup("DETERMINING H or V transmit");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'h_minus_v_threshold'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("h_minus_v_threshold");
    tt->descr = tdrpStrDup("Threshold for determining H or V transmit (dB).");
    tt->help = tdrpStrDup("For each beam, we compute the mean difference between Hc and Vx, or Hx and Vc, depending on whether we are in H-only or V-only transmit. If H exceeds V by this threshold, we assume H transmit. If V exceeds H by this threshold, we assume V transmit. If the absolute difference is less than or equal to this threshold, we do not use the beam.");
    tt->val_offset = (char *) &h_minus_v_threshold - &_start_;
    tt->single_val.d = 4.5;
    tt++;
    
    // Parameter 'Comment 10'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 10");
    tt->comment_hdr = tdrpStrDup("COMPUTING CROSS-POLAR POWER RATIO");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'min_valid_ratio_db'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_ratio_db");
    tt->descr = tdrpStrDup("Minimum valid Vx/Hx ratio (dB).");
    tt->help = tdrpStrDup("Sometimes, odd data leads to inappropriate ratios. This puts limits on the ratios to be used in the analysis.");
    tt->val_offset = (char *) &min_valid_ratio_db - &_start_;
    tt->single_val.d = -10;
    tt++;
    
    // Parameter 'max_valid_ratio_db'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_valid_ratio_db");
    tt->descr = tdrpStrDup("Maximum valid Vx/Hx ratio (dB).");
    tt->help = tdrpStrDup("Sometimes, odd data leads to inappropriate ratios. This puts limits on the ratios to be used in the analysis.");
    tt->val_offset = (char *) &max_valid_ratio_db - &_start_;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'Comment 11'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 11");
    tt->comment_hdr = tdrpStrDup("OVERRIDE RADAR LOCATION");
    tt->comment_text = tdrpStrDup("In cases where location is not stored in the meta data");
    tt++;
    
    // Parameter 'override_radar_location'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("override_radar_location");
    tt->descr = tdrpStrDup("Option to override radar location.");
    tt->help = tdrpStrDup("If TRUE, the program will use location specified in the 'radar_location' parameter.");
    tt->val_offset = (char *) &override_radar_location - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'radar_location'
    // ctype is '_radar_location_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("radar_location");
    tt->descr = tdrpStrDup("Radar location if override is set true.");
    tt->help = tdrpStrDup("The radar_location is only used if 'override_radar_location' is set true. Otherwise the information in the input data stream is used. Note that the altitude is in kilometers, not meters.");
    tt->val_offset = (char *) &radar_location - &_start_;
    tt->struct_def.name = tdrpStrDup("radar_location_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("latitude");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &radar_location.latitude - (char *) &radar_location;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("longitude");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &radar_location.longitude - (char *) &radar_location;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("altitude_km");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &radar_location.altitude_km - (char *) &radar_location;
    tt->n_struct_vals = 3;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 0;
      tt->struct_vals[1].d = 0;
      tt->struct_vals[2].d = 0;
    tt++;
    
    // Parameter 'Comment 12'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 12");
    tt->comment_hdr = tdrpStrDup("WRITE RESULTS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir");
    tt->descr = tdrpStrDup("Dir for output files.");
    tt->help = tdrpStrDup("The results will be written to sub-directories named from the data time.");
    tt->val_offset = (char *) &output_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./output");
    tt++;
    
    // Parameter 'write_results'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_results");
    tt->descr = tdrpStrDup("Option to write summary results to files.");
    tt->help = tdrpStrDup("If true, files will be written to output_dir.");
    tt->val_offset = (char *) &write_results - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'write_data_pairs'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_data_pairs");
    tt->descr = tdrpStrDup("Option to write individual hx/vx data pairs to an output file.");
    tt->help = tdrpStrDup("The raw pairs can then be used for generating plots. The file appears in output_dir, and the file name includes the start time for the analysis.");
    tt->val_offset = (char *) &write_data_pairs - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'radar_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("radar_name");
    tt->descr = tdrpStrDup("Used in file names.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_name - &_start_;
    tt->single_val.s = tdrpStrDup("spol");
    tt++;
    
    // Parameter 'Comment 13'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 13");
    tt->comment_hdr = tdrpStrDup("WRITE MDV FILES FOR DEBUGGING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_mdv_files'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_mdv_files");
    tt->descr = tdrpStrDup("Option to write MDV files for debugging.");
    tt->help = tdrpStrDup("These files contain the mean x-polar powers, and ratio, at each gate.");
    tt->val_offset = (char *) &write_mdv_files - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'mdv_output_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("mdv_output_dir");
    tt->descr = tdrpStrDup("Dir for MDV files.");
    tt->help = tdrpStrDup("See 'write_mdv'");
    tt->val_offset = (char *) &mdv_output_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./mdv");
    tt++;
    
    // Parameter 'Comment 14'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 14");
    tt->comment_hdr = tdrpStrDup("TESTING IN ALTERNATING H/V mode");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'alternating_hv_mode'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("alternating_hv_mode");
    tt->descr = tdrpStrDup("Radar operation is alternating H/V mode.");
    tt->help = tdrpStrDup("This is only used for testing. If true, the HV flag in the time series indicates which transmission path was in use for each pulse.");
    tt->val_offset = (char *) &alternating_hv_mode - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'switching_receiver'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("switching_receiver");
    tt->descr = tdrpStrDup("Does the receiver path switch between each pulse.");
    tt->help = tdrpStrDup("In some alternating mode radars, the receiver chain switches between pulses. This is done to create a co-polar and cross-polar receiver system which is more stable for ZDR. If this is set to TRUE, then the receiver is assumed to switch and the data for each channel is gathered accordingly.");
    tt->val_offset = (char *) &switching_receiver - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'also_compute_results_by_gate'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("also_compute_results_by_gate");
    tt->descr = tdrpStrDup("Option to compute the CP ratio on a gate-by-gate basis.");
    tt->help = tdrpStrDup("This is only used for testing with alternating data. If true, it also computes the ratio as is done by AltCpCompute, so that we can check the gate-by-gate results against the ppi-by-ppi results.");
    tt->val_offset = (char *) &also_compute_results_by_gate - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'averaging_period_in_stationary_mode'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("averaging_period_in_stationary_mode");
    tt->descr = tdrpStrDup("Sampling periond in stationary mode (secs).");
    tt->help = tdrpStrDup("Averages will be computed successively in H and V, using this sampling period.");
    tt->val_offset = (char *) &averaging_period_in_stationary_mode - &_start_;
    tt->single_val.d = 60;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
