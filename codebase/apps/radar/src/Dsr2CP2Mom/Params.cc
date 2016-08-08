// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1992 - 2012 
// ** University Corporation for Atmospheric Research(UCAR) 
// ** National Center for Atmospheric Research(NCAR) 
// ** Research Applications Laboratory(RAL) 
// ** P.O.Box 3000, Boulder, Colorado, 80307-3000, USA 
// ** 2012/3/18 17:24:52 
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Dsr2CP2Mom
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
    tt->comment_hdr = tdrpStrDup("Dsr2CP2Mom program");
    tt->comment_text = tdrpStrDup("Dsr2CP2Momreads an input FMQ containing radar data, and writes out UDP data in CP2 moments format.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
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
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'sband_fmq_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("sband_fmq_url");
    tt->descr = tdrpStrDup("Input URL for S-band data via FMQ");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &sband_fmq_url - &_start_;
    tt->single_val.s = tdrpStrDup("fmq/Iq2Dsr_s");
    tt++;
    
    // Parameter 'xband_fmq_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("xband_fmq_url");
    tt->descr = tdrpStrDup("Input URL for X-band data via FMQ");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &xband_fmq_url - &_start_;
    tt->single_val.s = tdrpStrDup("fmq/Iq2Dsr_x");
    tt++;
    
    // Parameter 'seek_to_end_of_input'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("seek_to_end_of_input");
    tt->descr = tdrpStrDup("Option to seek to the end of the input FMQ.");
    tt->help = tdrpStrDup("If TRUE, the program will seek to the end of the fmq and only read in new data. If FALSE, it will start reading from the beginning of the FMQ.");
    tt->val_offset = (char *) &seek_to_end_of_input - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("FIELD INFORMATION");
    tt->comment_text = tdrpStrDup("Translate fields from DSR input to UDP output.");
    tt++;
    
    // Parameter 'sband_output_fields'
    // ctype is '_output_field_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("sband_output_fields");
    tt->descr = tdrpStrDup("Array of output fields for S band.");
    tt->help = tdrpStrDup("Associate each desired S-band output field with the DSR field name.");
    tt->array_offset = (char *) &_sband_output_fields - &_start_;
    tt->array_n_offset = (char *) &sband_output_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(output_field_t);
    tt->array_n = 9;
    tt->struct_def.name = tdrpStrDup("output_field_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("cp2_field_id_t");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_id");
      tt->struct_def.fields[0].ptype = ENUM_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_sband_output_fields->field_id - (char *) _sband_output_fields;
        tt->struct_def.fields[0].enum_def.name = tdrpStrDup("cp2_field_id_t");
        tt->struct_def.fields[0].enum_def.nfields = 16;
        tt->struct_def.fields[0].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[0].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[0].enum_def.fields[0].name = tdrpStrDup("PROD_S_DBMHC");
        tt->struct_def.fields[0].enum_def.fields[0].val = PROD_S_DBMHC;
        tt->struct_def.fields[0].enum_def.fields[1].name = tdrpStrDup("PROD_S_DBMVC");
        tt->struct_def.fields[0].enum_def.fields[1].val = PROD_S_DBMVC;
        tt->struct_def.fields[0].enum_def.fields[2].name = tdrpStrDup("PROD_S_DBZ");
        tt->struct_def.fields[0].enum_def.fields[2].val = PROD_S_DBZ;
        tt->struct_def.fields[0].enum_def.fields[3].name = tdrpStrDup("PROD_S_SNR");
        tt->struct_def.fields[0].enum_def.fields[3].val = PROD_S_SNR;
        tt->struct_def.fields[0].enum_def.fields[4].name = tdrpStrDup("PROD_S_VEL");
        tt->struct_def.fields[0].enum_def.fields[4].val = PROD_S_VEL;
        tt->struct_def.fields[0].enum_def.fields[5].name = tdrpStrDup("PROD_S_WIDTH");
        tt->struct_def.fields[0].enum_def.fields[5].val = PROD_S_WIDTH;
        tt->struct_def.fields[0].enum_def.fields[6].name = tdrpStrDup("PROD_S_RHOHV");
        tt->struct_def.fields[0].enum_def.fields[6].val = PROD_S_RHOHV;
        tt->struct_def.fields[0].enum_def.fields[7].name = tdrpStrDup("PROD_S_PHIDP");
        tt->struct_def.fields[0].enum_def.fields[7].val = PROD_S_PHIDP;
        tt->struct_def.fields[0].enum_def.fields[8].name = tdrpStrDup("PROD_S_ZDR");
        tt->struct_def.fields[0].enum_def.fields[8].val = PROD_S_ZDR;
        tt->struct_def.fields[0].enum_def.fields[9].name = tdrpStrDup("PROD_X_DBMHC");
        tt->struct_def.fields[0].enum_def.fields[9].val = PROD_X_DBMHC;
        tt->struct_def.fields[0].enum_def.fields[10].name = tdrpStrDup("PROD_X_DBMVX");
        tt->struct_def.fields[0].enum_def.fields[10].val = PROD_X_DBMVX;
        tt->struct_def.fields[0].enum_def.fields[11].name = tdrpStrDup("PROD_X_DBZ");
        tt->struct_def.fields[0].enum_def.fields[11].val = PROD_X_DBZ;
        tt->struct_def.fields[0].enum_def.fields[12].name = tdrpStrDup("PROD_X_SNR");
        tt->struct_def.fields[0].enum_def.fields[12].val = PROD_X_SNR;
        tt->struct_def.fields[0].enum_def.fields[13].name = tdrpStrDup("PROD_X_VEL");
        tt->struct_def.fields[0].enum_def.fields[13].val = PROD_X_VEL;
        tt->struct_def.fields[0].enum_def.fields[14].name = tdrpStrDup("PROD_X_WIDTH");
        tt->struct_def.fields[0].enum_def.fields[14].val = PROD_X_WIDTH;
        tt->struct_def.fields[0].enum_def.fields[15].name = tdrpStrDup("PROD_X_LDR");
        tt->struct_def.fields[0].enum_def.fields[15].val = PROD_X_LDR;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("dsr_name");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_sband_output_fields->dsr_name - (char *) _sband_output_fields;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("missing_val");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_sband_output_fields->missing_val - (char *) _sband_output_fields;
    tt->n_struct_vals = 27;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].e = PROD_S_DBMHC;
      tt->struct_vals[1].s = tdrpStrDup("DBZ");
      tt->struct_vals[2].d = -120;
      tt->struct_vals[3].e = PROD_S_DBMVC;
      tt->struct_vals[4].s = tdrpStrDup("DBZ");
      tt->struct_vals[5].d = -120;
      tt->struct_vals[6].e = PROD_S_DBZ;
      tt->struct_vals[7].s = tdrpStrDup("DBZ");
      tt->struct_vals[8].d = -40;
      tt->struct_vals[9].e = PROD_S_SNR;
      tt->struct_vals[10].s = tdrpStrDup("DBZ");
      tt->struct_vals[11].d = -30;
      tt->struct_vals[12].e = PROD_S_VEL;
      tt->struct_vals[13].s = tdrpStrDup("VEL");
      tt->struct_vals[14].d = -30;
      tt->struct_vals[15].e = PROD_S_WIDTH;
      tt->struct_vals[16].s = tdrpStrDup("DBZ");
      tt->struct_vals[17].d = -1;
      tt->struct_vals[18].e = PROD_S_RHOHV;
      tt->struct_vals[19].s = tdrpStrDup("DBZ");
      tt->struct_vals[20].d = -1;
      tt->struct_vals[21].e = PROD_S_PHIDP;
      tt->struct_vals[22].s = tdrpStrDup("DBZ");
      tt->struct_vals[23].d = -400;
      tt->struct_vals[24].e = PROD_S_ZDR;
      tt->struct_vals[25].s = tdrpStrDup("DBZ");
      tt->struct_vals[26].d = -100;
    tt++;
    
    // Parameter 'xband_output_fields'
    // ctype is '_output_field_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("xband_output_fields");
    tt->descr = tdrpStrDup("Array of X-band output fields.");
    tt->help = tdrpStrDup("Associate each desired X-band output field with the DSR field name.");
    tt->array_offset = (char *) &_xband_output_fields - &_start_;
    tt->array_n_offset = (char *) &xband_output_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(output_field_t);
    tt->array_n = 7;
    tt->struct_def.name = tdrpStrDup("output_field_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("cp2_field_id_t");
      tt->struct_def.fields[0].fname = tdrpStrDup("field_id");
      tt->struct_def.fields[0].ptype = ENUM_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_xband_output_fields->field_id - (char *) _xband_output_fields;
        tt->struct_def.fields[0].enum_def.name = tdrpStrDup("cp2_field_id_t");
        tt->struct_def.fields[0].enum_def.nfields = 16;
        tt->struct_def.fields[0].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[0].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[0].enum_def.fields[0].name = tdrpStrDup("PROD_S_DBMHC");
        tt->struct_def.fields[0].enum_def.fields[0].val = PROD_S_DBMHC;
        tt->struct_def.fields[0].enum_def.fields[1].name = tdrpStrDup("PROD_S_DBMVC");
        tt->struct_def.fields[0].enum_def.fields[1].val = PROD_S_DBMVC;
        tt->struct_def.fields[0].enum_def.fields[2].name = tdrpStrDup("PROD_S_DBZ");
        tt->struct_def.fields[0].enum_def.fields[2].val = PROD_S_DBZ;
        tt->struct_def.fields[0].enum_def.fields[3].name = tdrpStrDup("PROD_S_SNR");
        tt->struct_def.fields[0].enum_def.fields[3].val = PROD_S_SNR;
        tt->struct_def.fields[0].enum_def.fields[4].name = tdrpStrDup("PROD_S_VEL");
        tt->struct_def.fields[0].enum_def.fields[4].val = PROD_S_VEL;
        tt->struct_def.fields[0].enum_def.fields[5].name = tdrpStrDup("PROD_S_WIDTH");
        tt->struct_def.fields[0].enum_def.fields[5].val = PROD_S_WIDTH;
        tt->struct_def.fields[0].enum_def.fields[6].name = tdrpStrDup("PROD_S_RHOHV");
        tt->struct_def.fields[0].enum_def.fields[6].val = PROD_S_RHOHV;
        tt->struct_def.fields[0].enum_def.fields[7].name = tdrpStrDup("PROD_S_PHIDP");
        tt->struct_def.fields[0].enum_def.fields[7].val = PROD_S_PHIDP;
        tt->struct_def.fields[0].enum_def.fields[8].name = tdrpStrDup("PROD_S_ZDR");
        tt->struct_def.fields[0].enum_def.fields[8].val = PROD_S_ZDR;
        tt->struct_def.fields[0].enum_def.fields[9].name = tdrpStrDup("PROD_X_DBMHC");
        tt->struct_def.fields[0].enum_def.fields[9].val = PROD_X_DBMHC;
        tt->struct_def.fields[0].enum_def.fields[10].name = tdrpStrDup("PROD_X_DBMVX");
        tt->struct_def.fields[0].enum_def.fields[10].val = PROD_X_DBMVX;
        tt->struct_def.fields[0].enum_def.fields[11].name = tdrpStrDup("PROD_X_DBZ");
        tt->struct_def.fields[0].enum_def.fields[11].val = PROD_X_DBZ;
        tt->struct_def.fields[0].enum_def.fields[12].name = tdrpStrDup("PROD_X_SNR");
        tt->struct_def.fields[0].enum_def.fields[12].val = PROD_X_SNR;
        tt->struct_def.fields[0].enum_def.fields[13].name = tdrpStrDup("PROD_X_VEL");
        tt->struct_def.fields[0].enum_def.fields[13].val = PROD_X_VEL;
        tt->struct_def.fields[0].enum_def.fields[14].name = tdrpStrDup("PROD_X_WIDTH");
        tt->struct_def.fields[0].enum_def.fields[14].val = PROD_X_WIDTH;
        tt->struct_def.fields[0].enum_def.fields[15].name = tdrpStrDup("PROD_X_LDR");
        tt->struct_def.fields[0].enum_def.fields[15].val = PROD_X_LDR;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("dsr_name");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_xband_output_fields->dsr_name - (char *) _xband_output_fields;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("missing_val");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_xband_output_fields->missing_val - (char *) _xband_output_fields;
    tt->n_struct_vals = 21;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].e = PROD_X_DBMHC;
      tt->struct_vals[1].s = tdrpStrDup("DBMHC");
      tt->struct_vals[2].d = -120;
      tt->struct_vals[3].e = PROD_X_DBMVX;
      tt->struct_vals[4].s = tdrpStrDup("DBMVX");
      tt->struct_vals[5].d = -120;
      tt->struct_vals[6].e = PROD_X_DBZ;
      tt->struct_vals[7].s = tdrpStrDup("DBZ");
      tt->struct_vals[8].d = -40;
      tt->struct_vals[9].e = PROD_X_SNR;
      tt->struct_vals[10].s = tdrpStrDup("SNR");
      tt->struct_vals[11].d = -30;
      tt->struct_vals[12].e = PROD_X_VEL;
      tt->struct_vals[13].s = tdrpStrDup("VEL");
      tt->struct_vals[14].d = -30;
      tt->struct_vals[15].e = PROD_X_WIDTH;
      tt->struct_vals[16].s = tdrpStrDup("WIDTH");
      tt->struct_vals[17].d = -1;
      tt->struct_vals[18].e = PROD_X_LDR;
      tt->struct_vals[19].s = tdrpStrDup("LDRH");
      tt->struct_vals[20].d = 30;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("OUTPUT UDP DATA");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'udp_network'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("udp_network");
    tt->descr = tdrpStrDup("Address for UDP broadcast.");
    tt->help = tdrpStrDup("UDP packets are broadcast on this address.");
    tt->val_offset = (char *) &udp_network - &_start_;
    tt->single_val.s = tdrpStrDup("192.168.1");
    tt++;
    
    // Parameter 'udp_port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("udp_port");
    tt->descr = tdrpStrDup("Port for UDP broadcast.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &udp_port - &_start_;
    tt->single_val.i = 3200;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }