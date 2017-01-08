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
// Code for program WafsTiled2Mdv
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
    tt->comment_hdr = tdrpStrDup("WafsTiled2Mdv Parameter file");
    tt->comment_text = tdrpStrDup("WafsTiled2Mdv reads in raw WAFS model data files, which are tiled to cover the entire globe. Each file covers part of the globe. The files are merged and written out into a single MDV file.");
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
    tt->descr = tdrpStrDup("Operation mode");
    tt->help = tdrpStrDup("REALTIME: files are processed as they arrive in the input directory. ARCHIVE: files in the input directory with times between the start and end times are processed. FILELIST: the files specified on the command line are processed in the order specified.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("mode_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[0].val = REALTIME;
      tt->enum_def.fields[1].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[1].val = ARCHIVE;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("INPUT DATA");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Input directory.");
    tt->help = tdrpStrDup("Directory which contains raw WAFS files. REALTIME and ARCHIVE modes only.");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup(".");
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max valid age of input data files (secs)");
    tt->help = tdrpStrDup("REALTIME mode only. This the max valid age for an incoming file. Files older than this will be ignored.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->single_val.i = 7200;
    tt++;
    
    // Parameter 'latest_data_info_avail'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("latest_data_info_avail");
    tt->descr = tdrpStrDup("Is _latest_data_info fiel available in input_dir?");
    tt->help = tdrpStrDup("REALTIME mode only. Set to TRUE if _latest_data_info file is available, FALSE otherwise.");
    tt->val_offset = (char *) &latest_data_info_avail - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'tiles'
    // ctype is '_tile_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("tiles");
    tt->descr = tdrpStrDup("ID letter for each tile in the file name.");
    tt->help = tdrpStrDup("File names end with the tile identifier. For example, fh.000_tl.press_ar.octantm is a file for tile 'm' at forecast hour 0.");
    tt->array_offset = (char *) &_tiles - &_start_;
    tt->array_n_offset = (char *) &tiles_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(tile_t);
    tt->array_n = 8;
    tt->struct_def.name = tdrpStrDup("tile_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("id");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_tiles->id - (char *) _tiles;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("description");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_tiles->description - (char *) _tiles;
    tt->n_struct_vals = 16;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("i");
      tt->struct_vals[1].s = tdrpStrDup("lon:-030to+060,lat:00to+90");
      tt->struct_vals[2].s = tdrpStrDup("j");
      tt->struct_vals[3].s = tdrpStrDup("lon:+060to+150,lat:00to+90");
      tt->struct_vals[4].s = tdrpStrDup("k");
      tt->struct_vals[5].s = tdrpStrDup("lon:+150to-120,lat:00to+90");
      tt->struct_vals[6].s = tdrpStrDup("l");
      tt->struct_vals[7].s = tdrpStrDup("lon:-120to-030,lat:00to+90");
      tt->struct_vals[8].s = tdrpStrDup("m");
      tt->struct_vals[9].s = tdrpStrDup("lon:-030to+070,lat:-90to00");
      tt->struct_vals[10].s = tdrpStrDup("n");
      tt->struct_vals[11].s = tdrpStrDup("lon:+060to+150,lat:-90to00");
      tt->struct_vals[12].s = tdrpStrDup("o");
      tt->struct_vals[13].s = tdrpStrDup("lon:+150to-120,lat:-90to00");
      tt->struct_vals[14].s = tdrpStrDup("p");
      tt->struct_vals[15].s = tdrpStrDup("lon:-120to-030,lat:-90to00");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_url");
    tt->descr = tdrpStrDup("Url for output mdv files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/wafs");
    tt++;
    
    // Parameter 'output_path_in_forecast_format'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_path_in_forecast_format");
    tt->descr = tdrpStrDup("Option to create output path in forecast format.");
    tt->help = tdrpStrDup("If false, the output path is determined  using the valid time: topdir/yyyymmdd/hhmmss.mdv. If true, the output path is determined using the model initialization (generate) time and the forecast lead time in secs: yyyymmdd/g_hhmmss/f_ssssssss.mdv");
    tt->val_offset = (char *) &output_path_in_forecast_format - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'data_set_info'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_set_info");
    tt->descr = tdrpStrDup("Data set info.");
    tt->help = tdrpStrDup("This is placed in the MDV master header for documentation purposes.");
    tt->val_offset = (char *) &data_set_info - &_start_;
    tt->single_val.s = tdrpStrDup("This MDV file was created by WafsTiled2Mdv.");
    tt++;
    
    // Parameter 'data_set_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_set_name");
    tt->descr = tdrpStrDup("Data set name.");
    tt->help = tdrpStrDup("This is placed in the MDV master header for documentation purposes.");
    tt->val_offset = (char *) &data_set_name - &_start_;
    tt->single_val.s = tdrpStrDup("WAFS model data.");
    tt++;
    
    // Parameter 'data_set_source'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_set_source");
    tt->descr = tdrpStrDup("Data set source details.");
    tt->help = tdrpStrDup("This is placed in the MDV master header for documentation purposes.");
    tt->val_offset = (char *) &data_set_source - &_start_;
    tt->single_val.s = tdrpStrDup("WAFS output.");
    tt++;
    
    // Parameter 'output_min_longitude'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_min_longitude");
    tt->descr = tdrpStrDup("Longitude of W side of output grid. (deg)");
    tt->help = tdrpStrDup("The output grid should span 360 degrees in longitude. You can choose where to start the grid, so that your part of the world is not near an edge.");
    tt->val_offset = (char *) &output_min_longitude - &_start_;
    tt->has_min = TRUE;
    tt->has_max = TRUE;
    tt->min_val.i = -360;
    tt->max_val.i = 0;
    tt->single_val.i = -180;
    tt++;
    
    // Parameter 'output_fields'
    // ctype is '_out_field_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("output_fields");
    tt->descr = tdrpStrDup("List of output fields for MDV file.");
    tt->help = tdrpStrDup("Grib field list:\n  PRES = 1: pressure (Pa)\n  PRMSL = 2: pressure reduced to MSL (Pa)\n  HGT = 7: geopotential height (m)\n  TMP = 11: temperature (K)\n  WSPD = 32: Wind speed derived from U and V (m/s)\n  UGRD = 33: U wind (m/s)\n  VGRD = 34: V wind (m/s)\n  VVEL = 39: vertical velocity (m/s)\n  RH = 52: relative humidity (%)\nThe WSPD field is derived from U and V, both of which must be present if this is selected.\n");
    tt->array_offset = (char *) &_output_fields - &_start_;
    tt->array_n_offset = (char *) &output_fields_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(out_field_t);
    tt->array_n = 5;
    tt->struct_def.name = tdrpStrDup("out_field_t");
    tt->struct_def.nfields = 6;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("mdv_name");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_output_fields->mdv_name - (char *) _output_fields;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("mdv_long_name");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_output_fields->mdv_long_name - (char *) _output_fields;
      tt->struct_def.fields[2].ftype = tdrpStrDup("string");
      tt->struct_def.fields[2].fname = tdrpStrDup("mdv_units");
      tt->struct_def.fields[2].ptype = STRING_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_output_fields->mdv_units - (char *) _output_fields;
      tt->struct_def.fields[3].ftype = tdrpStrDup("grib_field_id_t");
      tt->struct_def.fields[3].fname = tdrpStrDup("grib_field_id");
      tt->struct_def.fields[3].ptype = ENUM_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_output_fields->grib_field_id - (char *) _output_fields;
        tt->struct_def.fields[3].enum_def.name = tdrpStrDup("grib_field_id_t");
        tt->struct_def.fields[3].enum_def.nfields = 9;
        tt->struct_def.fields[3].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[3].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[3].enum_def.fields[0].name = tdrpStrDup("PRES");
        tt->struct_def.fields[3].enum_def.fields[0].val = PRES;
        tt->struct_def.fields[3].enum_def.fields[1].name = tdrpStrDup("PRMSL");
        tt->struct_def.fields[3].enum_def.fields[1].val = PRMSL;
        tt->struct_def.fields[3].enum_def.fields[2].name = tdrpStrDup("HGT");
        tt->struct_def.fields[3].enum_def.fields[2].val = HGT;
        tt->struct_def.fields[3].enum_def.fields[3].name = tdrpStrDup("TMP");
        tt->struct_def.fields[3].enum_def.fields[3].val = TMP;
        tt->struct_def.fields[3].enum_def.fields[4].name = tdrpStrDup("WSPD");
        tt->struct_def.fields[3].enum_def.fields[4].val = WSPD;
        tt->struct_def.fields[3].enum_def.fields[5].name = tdrpStrDup("UGRD");
        tt->struct_def.fields[3].enum_def.fields[5].val = UGRD;
        tt->struct_def.fields[3].enum_def.fields[6].name = tdrpStrDup("VGRD");
        tt->struct_def.fields[3].enum_def.fields[6].val = VGRD;
        tt->struct_def.fields[3].enum_def.fields[7].name = tdrpStrDup("VVEL");
        tt->struct_def.fields[3].enum_def.fields[7].val = VVEL;
        tt->struct_def.fields[3].enum_def.fields[8].name = tdrpStrDup("RH");
        tt->struct_def.fields[3].enum_def.fields[8].val = RH;
      tt->struct_def.fields[4].ftype = tdrpStrDup("units_conversion_t");
      tt->struct_def.fields[4].fname = tdrpStrDup("units_conversion");
      tt->struct_def.fields[4].ptype = ENUM_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_output_fields->units_conversion - (char *) _output_fields;
        tt->struct_def.fields[4].enum_def.name = tdrpStrDup("units_conversion_t");
        tt->struct_def.fields[4].enum_def.nfields = 6;
        tt->struct_def.fields[4].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[4].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[4].enum_def.fields[0].name = tdrpStrDup("NO_CHANGE");
        tt->struct_def.fields[4].enum_def.fields[0].val = NO_CHANGE;
        tt->struct_def.fields[4].enum_def.fields[1].name = tdrpStrDup("MPS_TO_KNOTS");
        tt->struct_def.fields[4].enum_def.fields[1].val = MPS_TO_KNOTS;
        tt->struct_def.fields[4].enum_def.fields[2].name = tdrpStrDup("PASCALS_TO_MBAR");
        tt->struct_def.fields[4].enum_def.fields[2].val = PASCALS_TO_MBAR;
        tt->struct_def.fields[4].enum_def.fields[3].name = tdrpStrDup("KELVIN_TO_CELSIUS");
        tt->struct_def.fields[4].enum_def.fields[3].val = KELVIN_TO_CELSIUS;
        tt->struct_def.fields[4].enum_def.fields[4].name = tdrpStrDup("PERCENT_TO_FRACTION");
        tt->struct_def.fields[4].enum_def.fields[4].val = PERCENT_TO_FRACTION;
        tt->struct_def.fields[4].enum_def.fields[5].name = tdrpStrDup("WSPD_FROM_U_AND_V");
        tt->struct_def.fields[4].enum_def.fields[5].val = WSPD_FROM_U_AND_V;
      tt->struct_def.fields[5].ftype = tdrpStrDup("encoding_type_t");
      tt->struct_def.fields[5].fname = tdrpStrDup("encoding");
      tt->struct_def.fields[5].ptype = ENUM_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_output_fields->encoding - (char *) _output_fields;
        tt->struct_def.fields[5].enum_def.name = tdrpStrDup("encoding_type_t");
        tt->struct_def.fields[5].enum_def.nfields = 3;
        tt->struct_def.fields[5].enum_def.fields = (enum_field_t *) tdrpMalloc
          (tt->struct_def.fields[5].enum_def.nfields * sizeof(enum_field_t));
        tt->struct_def.fields[5].enum_def.fields[0].name = tdrpStrDup("INT8");
        tt->struct_def.fields[5].enum_def.fields[0].val = INT8;
        tt->struct_def.fields[5].enum_def.fields[1].name = tdrpStrDup("INT16");
        tt->struct_def.fields[5].enum_def.fields[1].val = INT16;
        tt->struct_def.fields[5].enum_def.fields[2].name = tdrpStrDup("FLOAT32");
        tt->struct_def.fields[5].enum_def.fields[2].val = FLOAT32;
    tt->n_struct_vals = 30;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("U");
      tt->struct_vals[1].s = tdrpStrDup("U-wind");
      tt->struct_vals[2].s = tdrpStrDup("knots");
      tt->struct_vals[3].e = UGRD;
      tt->struct_vals[4].e = MPS_TO_KNOTS;
      tt->struct_vals[5].e = INT8;
      tt->struct_vals[6].s = tdrpStrDup("V");
      tt->struct_vals[7].s = tdrpStrDup("V-wind");
      tt->struct_vals[8].s = tdrpStrDup("knots");
      tt->struct_vals[9].e = VGRD;
      tt->struct_vals[10].e = MPS_TO_KNOTS;
      tt->struct_vals[11].e = INT8;
      tt->struct_vals[12].s = tdrpStrDup("Temp");
      tt->struct_vals[13].s = tdrpStrDup("Temperature");
      tt->struct_vals[14].s = tdrpStrDup("C");
      tt->struct_vals[15].e = TMP;
      tt->struct_vals[16].e = KELVIN_TO_CELSIUS;
      tt->struct_vals[17].e = INT8;
      tt->struct_vals[18].s = tdrpStrDup("RH");
      tt->struct_vals[19].s = tdrpStrDup("Relative Humidity");
      tt->struct_vals[20].s = tdrpStrDup("%");
      tt->struct_vals[21].e = RH;
      tt->struct_vals[22].e = NO_CHANGE;
      tt->struct_vals[23].e = INT8;
      tt->struct_vals[24].s = tdrpStrDup("WSPD");
      tt->struct_vals[25].s = tdrpStrDup("Wind Speed");
      tt->struct_vals[26].s = tdrpStrDup("knots");
      tt->struct_vals[27].e = WSPD;
      tt->struct_vals[28].e = WSPD_FROM_U_AND_V;
      tt->struct_vals[29].e = INT8;
    tt++;
    
    // Parameter 'output_wind_speed'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("output_wind_speed");
    tt->descr = tdrpStrDup("Output wind speed field, derived from U and V fields.");
    tt->help = tdrpStrDup("The wind speed field will be derived from the raw WAFS fields. For this to succeed, there must be an output_field named 'U', and one named 'V'. The wind speed will be computed from these two fields.");
    tt->val_offset = (char *) &output_wind_speed - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'output_compression'
    // ctype is '_compression_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_compression");
    tt->descr = tdrpStrDup("Compression type for output files");
    tt->help = tdrpStrDup("See <mdv/mdv_macros.h> for the C definitions to which these correspond.");
    tt->val_offset = (char *) &output_compression - &_start_;
    tt->enum_def.name = tdrpStrDup("compression_t");
    tt->enum_def.nfields = 5;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("_MDV_COMPRESSION_NONE");
      tt->enum_def.fields[0].val = _MDV_COMPRESSION_NONE;
      tt->enum_def.fields[1].name = tdrpStrDup("_MDV_COMPRESSION_RLE");
      tt->enum_def.fields[1].val = _MDV_COMPRESSION_RLE;
      tt->enum_def.fields[2].name = tdrpStrDup("_MDV_COMPRESSION_ZLIB");
      tt->enum_def.fields[2].val = _MDV_COMPRESSION_ZLIB;
      tt->enum_def.fields[3].name = tdrpStrDup("_MDV_COMPRESSION_BZIP");
      tt->enum_def.fields[3].val = _MDV_COMPRESSION_BZIP;
      tt->enum_def.fields[4].name = tdrpStrDup("_MDV_COMPRESSION_GZIP");
      tt->enum_def.fields[4].val = _MDV_COMPRESSION_GZIP;
    tt->single_val.e = _MDV_COMPRESSION_GZIP;
    tt++;
    
    // Parameter 'output_level_type'
    // ctype is '_output_level_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("output_level_type");
    tt->descr = tdrpStrDup("Option to choose vertical levels for output file.");
    tt->help = tdrpStrDup("If FLIGHT_LEVELS or HEIGHT_LEVELS, vertical levels will be interpolated accordingly. If NATIVE_PRESSURE_LEVELS, no interpolation is done and the data is output on the original pressure levels.");
    tt->val_offset = (char *) &output_level_type - &_start_;
    tt->enum_def.name = tdrpStrDup("output_level_type_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("NATIVE_PRESSURE_LEVELS");
      tt->enum_def.fields[0].val = NATIVE_PRESSURE_LEVELS;
      tt->enum_def.fields[1].name = tdrpStrDup("FLIGHT_LEVELS");
      tt->enum_def.fields[1].val = FLIGHT_LEVELS;
      tt->enum_def.fields[2].name = tdrpStrDup("HEIGHT_LEVELS");
      tt->enum_def.fields[2].val = HEIGHT_LEVELS;
    tt->single_val.e = FLIGHT_LEVELS;
    tt++;
    
    // Parameter 'flight_levels'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("flight_levels");
    tt->descr = tdrpStrDup("Array of output flight levels.");
    tt->help = tdrpStrDup("Only used if output_levels is FLIGHT_LEVELS. The flight levels in the output are taken from this array.");
    tt->array_offset = (char *) &_flight_levels - &_start_;
    tt->array_n_offset = (char *) &flight_levels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 11;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].i = 10;
      tt->array_vals[1].i = 50;
      tt->array_vals[2].i = 100;
      tt->array_vals[3].i = 150;
      tt->array_vals[4].i = 200;
      tt->array_vals[5].i = 250;
      tt->array_vals[6].i = 300;
      tt->array_vals[7].i = 350;
      tt->array_vals[8].i = 400;
      tt->array_vals[9].i = 450;
      tt->array_vals[10].i = 500;
    tt++;
    
    // Parameter 'height_levels'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("height_levels");
    tt->descr = tdrpStrDup("Array of output height levels (km).");
    tt->help = tdrpStrDup("Only used if output_levels is HEIGHT_LEVELS. The height levels in the output are taken from this array.");
    tt->array_offset = (char *) &_height_levels - &_start_;
    tt->array_n_offset = (char *) &height_levels_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(double);
    tt->array_n = 17;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].d = 0.2;
      tt->array_vals[1].d = 1;
      tt->array_vals[2].d = 2;
      tt->array_vals[3].d = 3;
      tt->array_vals[4].d = 4;
      tt->array_vals[5].d = 5;
      tt->array_vals[6].d = 6;
      tt->array_vals[7].d = 7;
      tt->array_vals[8].d = 8;
      tt->array_vals[9].d = 9;
      tt->array_vals[10].d = 10;
      tt->array_vals[11].d = 11;
      tt->array_vals[12].d = 12;
      tt->array_vals[13].d = 13;
      tt->array_vals[14].d = 14;
      tt->array_vals[15].d = 15;
      tt->array_vals[16].d = 16;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
