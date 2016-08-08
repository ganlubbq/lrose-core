// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program mdv2netCDF
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
    tt->comment_hdr = tdrpStrDup("Program name: mdv2netCDF");
    tt->comment_text = tdrpStrDup("mdv2netCDF converts MDV files to netCDF, using the COARDS convention.");
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
    
    // Parameter 'Instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &Instance - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("MODE OF OPERATION.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In REALTIME mode, the program waits for a new input file. In ARCHIVE mode, it moves through the data between the start and end times set on the command line. In FILELIST mode, it moves through the list of file names specified on the command line. Paths (in FILELIST mode, at least) MUST contain a day-directory below the data file -- ./data_file.mdv will not work as a file path");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
    tt->single_val.e = ARCHIVE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'InMdvURL'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("InMdvURL");
    tt->descr = tdrpStrDup("Input URL");
    tt->help = tdrpStrDup("Set to the URL for the input MDV files");
    tt->val_offset = (char *) &InMdvURL - &_start_;
    tt->single_val.s = tdrpStrDup("./");
    tt++;
    
    // Parameter 'RealtimeMaxAge'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("RealtimeMaxAge");
    tt->descr = tdrpStrDup("Maximum age for file to be considered valid");
    tt->help = tdrpStrDup("In realtime mode only");
    tt->val_offset = (char *) &RealtimeMaxAge - &_start_;
    tt->single_val.i = 3600;
    tt++;
    
    // Parameter 'Once'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("Once");
    tt->descr = tdrpStrDup("Set to TRUE to run once and exit");
    tt->help = tdrpStrDup("Set to TRUE in Realtime only");
    tt->val_offset = (char *) &Once - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("DATA CONVERSION.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'DoAllFields'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("DoAllFields");
    tt->descr = tdrpStrDup("Set to TRUE to convert all fields.");
    tt->help = tdrpStrDup("If FALSE then only fields in FieldNames are converted.");
    tt->val_offset = (char *) &DoAllFields - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'FieldNames'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("FieldNames");
    tt->descr = tdrpStrDup("Names of fields to be output in netCDF file.");
    tt->help = tdrpStrDup("Only used if DoAllFields is FALSE.");
    tt->array_offset = (char *) &_FieldNames - &_start_;
    tt->array_n_offset = (char *) &FieldNames_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("Pressure");
      tt->array_vals[1].s = tdrpStrDup("Temperature");
    tt++;
    
    // Parameter 'AddNumToFieldName'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("AddNumToFieldName");
    tt->descr = tdrpStrDup("Option to add the field number to the end of the field name for output.");
    tt->help = tdrpStrDup("If TRUE, the field number will be added to all field names, except for the first field.");
    tt->val_offset = (char *) &AddNumToFieldName - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'DataOrderingZYX'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("DataOrderingZYX");
    tt->descr = tdrpStrDup("Option to store data in ZYX order, in which Z changes slowest and Z fastest.");
    tt->help = tdrpStrDup("If FALSE, the default ordering will be used. This is YXZ.");
    tt->val_offset = (char *) &DataOrderingZYX - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'OutDir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutDir");
    tt->descr = tdrpStrDup("Output netCDF directory");
    tt->help = tdrpStrDup("Set to the name of the output netCDF directory");
    tt->val_offset = (char *) &OutDir - &_start_;
    tt->single_val.s = tdrpStrDup("./");
    tt++;
    
    // Parameter 'OutFileExt'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutFileExt");
    tt->descr = tdrpStrDup("Output file extension.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &OutFileExt - &_start_;
    tt->single_val.s = tdrpStrDup("nc");
    tt++;
    
    // Parameter 'OutputPathFromTime'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("OutputPathFromTime");
    tt->descr = tdrpStrDup("Compute output path from time.");
    tt->help = tdrpStrDup("If TRUE, path is OutDir/yyyymmdd/hhmmss.nc. If FALSE, the file path is OutDir/yyyymmdd_hhmmss.NetCDF_FileName.");
    tt->val_offset = (char *) &OutputPathFromTime - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'NetCDF_FileName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("NetCDF_FileName");
    tt->descr = tdrpStrDup("Base NetCDF filename, with or without .nc extension");
    tt->help = tdrpStrDup("Output NetCDF files will have the date/time pre-pended");
    tt->val_offset = (char *) &NetCDF_FileName - &_start_;
    tt->single_val.s = tdrpStrDup("RapData");
    tt++;
    
    // Parameter 'WriteLdataInfo'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("WriteLdataInfo");
    tt->descr = tdrpStrDup("Write _latest_data_info file in OutDir.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &WriteLdataInfo - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'CompressAfterWrite'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("CompressAfterWrite");
    tt->descr = tdrpStrDup("Option to try gzip -f on the netcdf file after it\nis written. If this is invoked, the program sleeps\nfor a second prior to trying to zip the file.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &CompressAfterWrite - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'includeFile'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("includeFile");
    tt->descr = tdrpStrDup("Option to include an existing ASCII file in the output.");
    tt->help = tdrpStrDup("If set, the file designated by includeFilename will be read and\nadded, line by line, to the netCDF output file as an attribute.\n");
    tt->val_offset = (char *) &includeFile - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'includeFilename'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("includeFilename");
    tt->descr = tdrpStrDup("ASCII file to be included in the netCDF output if\nincludeFile is TRUE.");
    tt->help = tdrpStrDup("The file will be read line by line and included as text\nin the netcdf output.");
    tt->val_offset = (char *) &includeFilename - &_start_;
    tt->single_val.s = tdrpStrDup("/Some/File/Name.ext");
    tt++;
    
    // Parameter 'applyVleveLimits'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("applyVleveLimits");
    tt->descr = tdrpStrDup("Option to apply vlevel limits.");
    tt->help = tdrpStrDup("If true, set the minVlevel and maxVlevel below.");
    tt->val_offset = (char *) &applyVleveLimits - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'minVlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("minVlevel");
    tt->descr = tdrpStrDup("Minimum Vlevel.");
    tt->help = tdrpStrDup("Applies only if applyVleveLimits is true.");
    tt->val_offset = (char *) &minVlevel - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'maxVlevel'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("maxVlevel");
    tt->descr = tdrpStrDup("Maximum Vlevel.");
    tt->help = tdrpStrDup("Applies only if applyVleveLimits is true.");
    tt->val_offset = (char *) &maxVlevel - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'composite'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("composite");
    tt->descr = tdrpStrDup("Option to perform compositing.");
    tt->help = tdrpStrDup("If true, a maximum value vertical composite is performed.");
    tt->val_offset = (char *) &composite - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'remap_xy'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("remap_xy");
    tt->descr = tdrpStrDup("Option to remap grid in x,y.");
    tt->help = tdrpStrDup("If true, set the remap parameters below.");
    tt->val_offset = (char *) &remap_xy - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'remap_projection'
    // ctype is '_projection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("remap_projection");
    tt->descr = tdrpStrDup("Projection for remapping in x,y.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &remap_projection - &_start_;
    tt->enum_def.name = tdrpStrDup("projection_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("PROJ_LATLON");
      tt->enum_def.fields[0].val = PROJ_LATLON;
      tt->enum_def.fields[1].name = tdrpStrDup("PROJ_LAMBERT_CONF");
      tt->enum_def.fields[1].val = PROJ_LAMBERT_CONF;
      tt->enum_def.fields[2].name = tdrpStrDup("PROJ_FLAT");
      tt->enum_def.fields[2].val = PROJ_FLAT;
    tt->single_val.e = PROJ_FLAT;
    tt++;
    
    // Parameter 'remap_grid'
    // ctype is '_grid_params_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("remap_grid");
    tt->descr = tdrpStrDup("Grid parameters for remapping in x,y.");
    tt->help = tdrpStrDup("These params apply to all projection types.");
    tt->val_offset = (char *) &remap_grid - &_start_;
    tt->struct_def.name = tdrpStrDup("grid_params_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("nx");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &remap_grid.nx - (char *) &remap_grid;
      tt->struct_def.fields[1].ftype = tdrpStrDup("int");
      tt->struct_def.fields[1].fname = tdrpStrDup("ny");
      tt->struct_def.fields[1].ptype = INT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &remap_grid.ny - (char *) &remap_grid;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("minx");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &remap_grid.minx - (char *) &remap_grid;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("miny");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &remap_grid.miny - (char *) &remap_grid;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("dx");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &remap_grid.dx - (char *) &remap_grid;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("dy");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &remap_grid.dy - (char *) &remap_grid;
    tt->n_struct_vals = 6;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 1;
      tt->struct_vals[1].i = 1;
      tt->struct_vals[2].d = 0;
      tt->struct_vals[3].d = 0;
      tt->struct_vals[4].d = 1;
      tt->struct_vals[5].d = 1;
    tt++;
    
    // Parameter 'remap_rotation'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("remap_rotation");
    tt->descr = tdrpStrDup("Remapped grid rotation.");
    tt->help = tdrpStrDup("This applies only to PROJ_FLAT projections.");
    tt->val_offset = (char *) &remap_rotation - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'remap_origin_lat'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("remap_origin_lat");
    tt->descr = tdrpStrDup("Remapped grid origin latitude.");
    tt->help = tdrpStrDup("This applies only to PROJ_FLAT and PROJ_LAMBERT_CONF projections.");
    tt->val_offset = (char *) &remap_origin_lat - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'remap_origin_lon'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("remap_origin_lon");
    tt->descr = tdrpStrDup("Remapped grid origin longitude.");
    tt->help = tdrpStrDup("This applies only to PROJ_FLAT and PROJ_LAMBERT_CONF projections.");
    tt->val_offset = (char *) &remap_origin_lon - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'remap_lat1'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("remap_lat1");
    tt->descr = tdrpStrDup("Remapped grid reference latitude 1.");
    tt->help = tdrpStrDup("This applies only to PROJ_LAMBERT_CONF projections.");
    tt->val_offset = (char *) &remap_lat1 - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'remap_lat2'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("remap_lat2");
    tt->descr = tdrpStrDup("Remapped grid reference latitude 2.");
    tt->help = tdrpStrDup("This applies only to PROJ_LAMBERT_CONF projections.");
    tt->val_offset = (char *) &remap_lat2 - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'zUnitLabel'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("zUnitLabel");
    tt->descr = tdrpStrDup("Label to use for Z axis units.");
    tt->help = tdrpStrDup("Another option might be Kilometers.");
    tt->val_offset = (char *) &zUnitLabel - &_start_;
    tt->single_val.s = tdrpStrDup("level");
    tt++;
    
    // Parameter 'substitutions'
    // ctype is '_substitution_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("substitutions");
    tt->descr = tdrpStrDup("These parameters offer the ability to substitute another\nfield name or units other than those from the MDV file.\nAlso a long name can be added.");
    tt->help = tdrpStrDup("Defaults are OK for adjoint 3D.");
    tt->array_offset = (char *) &_substitutions - &_start_;
    tt->array_n_offset = (char *) &substitutions_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(substitution_t);
    tt->array_n = 3;
    tt->struct_def.name = tdrpStrDup("substitution_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("mdvFieldname");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_substitutions->mdvFieldname - (char *) _substitutions;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("netCDFfieldname");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_substitutions->netCDFfieldname - (char *) _substitutions;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("units");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_substitutions->units - (char *) _substitutions;
      tt->struct_def.fields[3].ftype = tdrpStrDup("string");
      tt->struct_def.fields[3].fname = tdrpStrDup("longName");
      tt->struct_def.fields[3].ptype = STRING_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_substitutions->longName - (char *) _substitutions;
    tt->n_struct_vals = 12;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("uwind");
      tt->struct_vals[1].s = tdrpStrDup("uwind");
      tt->struct_vals[2].s = tdrpStrDup("m/s");
      tt->struct_vals[3].s = tdrpStrDup("u wind component");
      tt->struct_vals[4].s = tdrpStrDup("vwind");
      tt->struct_vals[5].s = tdrpStrDup("vwind");
      tt->struct_vals[6].s = tdrpStrDup("m/s");
      tt->struct_vals[7].s = tdrpStrDup("v wind component");
      tt->struct_vals[8].s = tdrpStrDup("wwind");
      tt->struct_vals[9].s = tdrpStrDup("wwind");
      tt->struct_vals[10].s = tdrpStrDup("m/s");
      tt->struct_vals[11].s = tdrpStrDup("w wind component");
    tt++;
    
    // Parameter 'addHeight'
    // ctype is '_addHeight_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("addHeight");
    tt->descr = tdrpStrDup("Option to add the height as a netCDF variable.");
    tt->help = tdrpStrDup("Fields have the following meaning :\n\n addHeightVar - set to TRUE to add the height as a netCDF\n                variable. If this is FALSE, then the remaining\n                settings are irrelevant.\n\n usePlaneNumber - By default, the actual plane heights are taken from\n                  the vlevel header. Setting this option to TRUE\n                  means that the plane numbers (starting at 0) will\n                  be used rather than the height values.\n\n mdvFieldName - mdv field to take the height values from.\n\n netcdfName - name to use for the height variable in the netcdf file.\n units - units for the height variable.");
    tt->val_offset = (char *) &addHeight - &_start_;
    tt->struct_def.name = tdrpStrDup("addHeight_t");
    tt->struct_def.nfields = 5;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[0].fname = tdrpStrDup("addHeightVar");
      tt->struct_def.fields[0].ptype = BOOL_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &addHeight.addHeightVar - (char *) &addHeight;
      tt->struct_def.fields[1].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[1].fname = tdrpStrDup("usePlaneNumber");
      tt->struct_def.fields[1].ptype = BOOL_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &addHeight.usePlaneNumber - (char *) &addHeight;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("mdvFieldName");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &addHeight.mdvFieldName - (char *) &addHeight;
      tt->struct_def.fields[3].ftype = tdrpStrDup("string");
      tt->struct_def.fields[3].fname = tdrpStrDup("netcdfName");
      tt->struct_def.fields[3].ptype = STRING_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &addHeight.netcdfName - (char *) &addHeight;
      tt->struct_def.fields[4].ftype = tdrpStrDup("string");
      tt->struct_def.fields[4].fname = tdrpStrDup("units");
      tt->struct_def.fields[4].ptype = STRING_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &addHeight.units - (char *) &addHeight;
    tt->n_struct_vals = 5;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].b = pFALSE;
      tt->struct_vals[1].b = pFALSE;
      tt->struct_vals[2].s = tdrpStrDup("DBZ");
      tt->struct_vals[3].s = tdrpStrDup("heightDBZ");
      tt->struct_vals[4].s = tdrpStrDup("elevationDegrees");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }