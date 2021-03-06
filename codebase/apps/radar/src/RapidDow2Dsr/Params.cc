// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program RapidDow2Dsr
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
        << "   [ -params path ] specify params file path\n"
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
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
    tt->comment_hdr = tdrpStrDup("Program name: RapidDow2Dsr");
    tt->comment_text = tdrpStrDup("RapidDow2Dsr reads radial moments data from the RapidDow, corrects the data appropriately for pointing angles and range, and writes the data to a DsRadarQueue beam by beam.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("PROCESS CONTROL AND DEBUGGING");
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
    
    // Parameter 'mode'
    // ctype is '_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("Operating mode");
    tt->help = tdrpStrDup("In REALTIME mode, the program waits for a new input file. In ARCHIVE mode, it moves through the data between the start and end times set on the command line. In FILELIST mode, it moves through the list of file names specified on the command line.");
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
    tt->single_val.e = FILELIST;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Directory for input data.");
    tt->help = tdrpStrDup("This is watched for input files. The files for the various channels are found in the directories specified in the channel parameters.");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./input");
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max age of input data - REALTIME mode.");
    tt->help = tdrpStrDup("For realtime only - max age of input data for it to be valid. If the input file is older than this, the program waits for new data.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 0;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'use_latest_data_info'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("use_latest_data_info");
    tt->descr = tdrpStrDup("Option to watch for _latest_data_info file in input dir.");
    tt->help = tdrpStrDup("For realtime only. If true the program watches for the _latest_data_info file to change. If false, it scans the directory for new file.");
    tt->val_offset = (char *) &use_latest_data_info - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'latest_file_only'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("latest_file_only");
    tt->descr = tdrpStrDup("Option to only process the latest file in the directory.");
    tt->help = tdrpStrDup("For realtime mode only, and only if use_latest_data_info is false, which implies that the program is scanning the input_dir for new files. If true, only the latest file will be processed. If false, all files younger than max_realtime_valid_age will be processed.");
    tt->val_offset = (char *) &latest_file_only - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("CHANNEL DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'channels'
    // ctype is '_channel_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("channels");
    tt->descr = tdrpStrDup("Details for each channel");
    tt->help = tdrpStrDup("\tname: name for the channel. \n\tdir: directory for the data files. \n\tfrequency: in Ghz. \t\nelevation_offset: offset relative to elevation in file (deg). \n\tazimuth_offset: offset relative to azimuth in file (deg). \n\tstart_range: range to center of first gate (km). \n\tgate_spacing: spacing between gates (km)");
    tt->array_offset = (char *) &_channels - &_start_;
    tt->array_n_offset = (char *) &channels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(channel_t);
    tt->array_n = 6;
    tt->struct_def.name = tdrpStrDup("channel_t");
    tt->struct_def.nfields = 7;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_channels->name - (char *) _channels;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("dir");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_channels->dir - (char *) _channels;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("frequency");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_channels->frequency - (char *) _channels;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("elevation_offset");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_channels->elevation_offset - (char *) _channels;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("azimuth_offset");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_channels->azimuth_offset - (char *) _channels;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("start_range");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_channels->start_range - (char *) _channels;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("gate_spacing");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &_channels->gate_spacing - (char *) _channels;
    tt->n_struct_vals = 42;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("ch0");
      tt->struct_vals[1].s = tdrpStrDup("/tmp/ch0");
      tt->struct_vals[2].d = 9.31;
      tt->struct_vals[3].d = -10.9;
      tt->struct_vals[4].d = 0;
      tt->struct_vals[5].d = 0.0375;
      tt->struct_vals[6].d = 0.075;
      tt->struct_vals[7].s = tdrpStrDup("ch1");
      tt->struct_vals[8].s = tdrpStrDup("/tmp/ch1");
      tt->struct_vals[9].d = 9.394;
      tt->struct_vals[10].d = -9.78;
      tt->struct_vals[11].d = -0.66;
      tt->struct_vals[12].d = 0.0375;
      tt->struct_vals[13].d = 0.075;
      tt->struct_vals[14].s = tdrpStrDup("ch2");
      tt->struct_vals[15].s = tdrpStrDup("/tmp/ch2");
      tt->struct_vals[16].d = 9.478;
      tt->struct_vals[17].d = -8.66;
      tt->struct_vals[18].d = -1.32;
      tt->struct_vals[19].d = 0.0375;
      tt->struct_vals[20].d = 0.075;
      tt->struct_vals[21].s = tdrpStrDup("ch3");
      tt->struct_vals[22].s = tdrpStrDup("/tmp/ch3");
      tt->struct_vals[23].d = 9.562;
      tt->struct_vals[24].d = -7.54;
      tt->struct_vals[25].d = -1.98;
      tt->struct_vals[26].d = 0.0375;
      tt->struct_vals[27].d = 0.075;
      tt->struct_vals[28].s = tdrpStrDup("ch4");
      tt->struct_vals[29].s = tdrpStrDup("/tmp/ch4");
      tt->struct_vals[30].d = 9.646;
      tt->struct_vals[31].d = -6.42;
      tt->struct_vals[32].d = -2.64;
      tt->struct_vals[33].d = 0.0375;
      tt->struct_vals[34].d = 0.075;
      tt->struct_vals[35].s = tdrpStrDup("ch5");
      tt->struct_vals[36].s = tdrpStrDup("/tmp/ch5");
      tt->struct_vals[37].d = 9.73;
      tt->struct_vals[38].d = -5.3;
      tt->struct_vals[39].d = -3.3;
      tt->struct_vals[40].d = 0.0375;
      tt->struct_vals[41].d = 0.075;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("RADAR PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'override_radar_name'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("override_radar_name");
    tt->descr = tdrpStrDup("Option to override the radar name in the data.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &override_radar_name - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'radar_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("radar_name");
    tt->descr = tdrpStrDup("Radar name for output data.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_name - &_start_;
    tt->single_val.s = tdrpStrDup("DOWR");
    tt++;
    
    // Parameter 'override_radar_location'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("override_radar_location");
    tt->descr = tdrpStrDup("Option to override the radar location.");
    tt->help = tdrpStrDup("If true, the location in this file will be used. If not, the location in the time series data will be used.");
    tt->val_offset = (char *) &override_radar_location - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'radar_latitude'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_latitude");
    tt->descr = tdrpStrDup("Radar latitude (deg).");
    tt->help = tdrpStrDup("See override_radar_location.");
    tt->val_offset = (char *) &radar_latitude - &_start_;
    tt->single_val.d = 39.9321;
    tt++;
    
    // Parameter 'radar_longitude'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_longitude");
    tt->descr = tdrpStrDup("Radar longitude (deg).");
    tt->help = tdrpStrDup("See override_radar_location.");
    tt->val_offset = (char *) &radar_longitude - &_start_;
    tt->single_val.d = -105.182;
    tt++;
    
    // Parameter 'radar_altitude_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_altitude_km");
    tt->descr = tdrpStrDup("Radar altitude (meters).");
    tt->help = tdrpStrDup("See override_radar_location.");
    tt->val_offset = (char *) &radar_altitude_km - &_start_;
    tt->single_val.d = 1.742;
    tt++;
    
    // Parameter 'correct_for_azimuth_error'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("correct_for_azimuth_error");
    tt->descr = tdrpStrDup("Option to apply an extra correction to azimuth.");
    tt->help = tdrpStrDup("This is intended to correct for a north-pointing error.");
    tt->val_offset = (char *) &correct_for_azimuth_error - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'azimuth_correction'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("azimuth_correction");
    tt->descr = tdrpStrDup("Azimuth correction (deg).");
    tt->help = tdrpStrDup("This value will be ADDED to the recorded azimuths, to correct for north-pointing error.");
    tt->val_offset = (char *) &azimuth_correction - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'set_transition_flag'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("set_transition_flag");
    tt->descr = tdrpStrDup("Option to set transition flag when elevation error is excessive.");
    tt->help = tdrpStrDup("The flag will be set if the difference between the actual elevation and target elevation exceeds max_elevation_error.");
    tt->val_offset = (char *) &set_transition_flag - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'max_elevation_error'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_elevation_error");
    tt->descr = tdrpStrDup("Max valid elevation error (deg).");
    tt->help = tdrpStrDup("If the actual elevation differs from the target elevation by more than this, the transition flag will be set.");
    tt->val_offset = (char *) &max_elevation_error - &_start_;
    tt->single_val.d = 5;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("DETERMINING END OF VOLUME");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'locate_end_of_volume'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("locate_end_of_volume");
    tt->descr = tdrpStrDup("Option to find the end of volume.");
    tt->help = tdrpStrDup("If true, the end of volume will be determined by a drop in the elevation angle");
    tt->val_offset = (char *) &locate_end_of_volume - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'elev_change_for_end_of_volume'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("elev_change_for_end_of_volume");
    tt->descr = tdrpStrDup("Change in elevation to indicate end of volume (deg).");
    tt->help = tdrpStrDup("If negative, we will look for a decrease in elevation angle. If positive, we will look for an increase in elevation angle.");
    tt->val_offset = (char *) &elev_change_for_end_of_volume - &_start_;
    tt->single_val.d = -10;
    tt++;
    
    // Parameter 'min_beams_in_volume'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("min_beams_in_volume");
    tt->descr = tdrpStrDup("Min number of beams in a volume.");
    tt->help = tdrpStrDup("After an end-of-volume is found, at least this number of beams must be found before we look for the subsequent end of volume.");
    tt->val_offset = (char *) &min_beams_in_volume - &_start_;
    tt->single_val.i = 7200;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Output URL for DsRadarQueue fmq.");
    tt->help = tdrpStrDup("The URL is of the form 'fmqp:://host::dir/name'. If the output is to the local host you can use just 'dir/name'.");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("fmq/dowr");
    tt++;
    
    // Parameter 'data_mapper_report_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("data_mapper_report_interval");
    tt->descr = tdrpStrDup("Number of seconds between reports to DataMapper.");
    tt->help = tdrpStrDup("If > 0, the program will register with the DataMapper when the output FMQs are written to. If <= 0, registration will not be performed.");
    tt->val_offset = (char *) &data_mapper_report_interval - &_start_;
    tt->single_val.i = 5;
    tt++;
    
    // Parameter 'write_blocking'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_blocking");
    tt->descr = tdrpStrDup("Option to block on write when the radar queue fills up.");
    tt->help = tdrpStrDup("If false, the program writes data to the output queue without regard to whether the reader is keeping up. This mode should usually be used in realtime, to avoid holding things up if a client becomes slow. If true, the program will not overwrite data in the queue which has not been read by the reader. This is recommended for ARCHIVE and FILELIST mode. In this mode there should be only one reader. If you need to service more than one reader, use Fmq2Fmq in write blocking mode with multiple output urls to multiplex the queue.");
    tt->val_offset = (char *) &write_blocking - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'output_compression'
    // ctype is '_compression_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_compression");
    tt->descr = tdrpStrDup("Output compression options.");
    tt->help = tdrpStrDup("The data may be optionally compressed for output. BZIP is generally the slowest but most compact. ZLIB uses the gzip compression algorithm, which is faster than BZIP, and for some data more compact as well. LZO is faster than BZIP and ZLIB, but not as compact. RLE is simple run-length encoding compression, which is the fastest and least compact.");
    tt->val_offset = (char *) &output_compression - &_start_;
    tt->enum_def.name = tdrpStrDup("compression_t");
    tt->enum_def.nfields = 5;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("NO_COMPRESSION");
      tt->enum_def.fields[0].val = NO_COMPRESSION;
      tt->enum_def.fields[1].name = tdrpStrDup("RLE_COMPRESSION");
      tt->enum_def.fields[1].val = RLE_COMPRESSION;
      tt->enum_def.fields[2].name = tdrpStrDup("LZO_COMPRESSION");
      tt->enum_def.fields[2].val = LZO_COMPRESSION;
      tt->enum_def.fields[3].name = tdrpStrDup("ZLIB_COMPRESSION");
      tt->enum_def.fields[3].val = ZLIB_COMPRESSION;
      tt->enum_def.fields[4].name = tdrpStrDup("BZIP_COMPRESSION");
      tt->enum_def.fields[4].val = BZIP_COMPRESSION;
    tt->single_val.e = NO_COMPRESSION;
    tt++;
    
    // Parameter 'output_n_slots'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_n_slots");
    tt->descr = tdrpStrDup("Number of slots in output FMQ.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_n_slots - &_start_;
    tt->single_val.i = 500;
    tt++;
    
    // Parameter 'output_buf_size'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_buf_size");
    tt->descr = tdrpStrDup("Size of buffer in output FMQ.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_buf_size - &_start_;
    tt->single_val.i = 1000000000;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
