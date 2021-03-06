// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2017
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program DsMdvServer
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2
  } debug_t;

  typedef enum {
    HEIGHT_KM = 0,
    PRESSURE_MB = 1,
    FLIGHT_LEVEL = 2
  } vertical_units_t;

  typedef enum {
    FUNC_LINEAR = 0,
    FUNC_SPEED_FROM_U_V = 1,
    FUNC_DIRN_FROM_U_V = 2,
    FUNC_DIFF_FIELDS_SAME_FILE = 3,
    FUNC_DIFF_FIELDS = 4,
    FUNC_DIFF_IN_TIME = 5,
    FUNC_VERT_COMPOSITE = 6
  } function_t;

  typedef enum {
    CLIMO_HOURLY = 0,
    CLIMO_HOURLY_BY_MONTH = 1,
    CLIMO_3HOURLY_BY_MONTH = 2,
    CLIMO_HOURLY_DIURNAL = 3,
    DIURNAL_CLIMATOLOGY = 4,
    CLIMO_3HOURLY_DIURNAL = 5,
    CLIMO_DAILY = 6,
    CLIMO_DAILY_BY_YEAR = 7,
    CLIMO_MONTHLY = 8,
    CLIMO_MONTHLY_BY_YEAR = 9
  } climatology_type_t;

  typedef enum {
    FORMAT_MDV = 0,
    FORMAT_XML = 1,
    FORMAT_NCF = 2
  } data_format_t;

  typedef enum {
    DATA_PACK_FLOAT = 0,
    DATA_PACK_SHORT = 1,
    DATA_PACK_BYTE = 2,
    DATA_PACK_ASIS = 3
  } data_pack_t;

  typedef enum {
    CLASSIC = 0,
    NC64BIT = 1,
    NETCDF4 = 2,
    NETCDF4_CLASSIC = 3
  } ncformat_t;

  // struct typedefs

  typedef struct {
    double min_lat;
    double min_lon;
    double max_lat;
    double max_lon;
    char* url;
  } domain_t;

  typedef struct {
    int min_lead_time;
    int max_lead_time;
    tdrp_bool_t request_by_gen_time;
  } forecast_constraints_t;

  typedef struct {
    char* name;
    char* long_name;
    char* units;
    char* transform;
    function_t function;
    char* field_name_1;
    char* field_name_2;
    char* url_2;
    char* url_3;
    char* s_arg_1;
    char* s_arg_2;
    char* s_arg_3;
    char* s_arg_4;
    char* s_arg_5;
    char* s_arg_6;
    int i_arg_1;
    int i_arg_2;
    int i_arg_3;
    double d_arg_1;
    double d_arg_2;
    double d_arg_3;
    double multiplier;
    double constant;
  } derived_field_t;

  typedef struct {
    char* institution;
    char* references;
    char* comment;
  } ncf_global_attributes_t;

  typedef struct {
    char* mdv_field_name;
    char* ncf_field_name;
    char* ncf_standard_name;
    char* ncf_long_name;
    char* ncf_units;
    tdrp_bool_t do_linear_transform;
    float linear_multiplier;
    float linear_const;
    data_pack_t packed_data_type;
  } mdv2ncf_field_transform_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

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

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

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

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

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

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

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

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

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

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

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

  int arrayRealloc(const char *param_name,
                   int new_array_n);

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

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  tdrp_bool_t no_threads;

  char* instance;

  int port;

  int qmax;

  int max_clients;

  tdrp_bool_t run_secure;

  tdrp_bool_t run_read_only;

  tdrp_bool_t allow_http;

  tdrp_bool_t copy_message_memory;

  tdrp_bool_t vsection_set_nsamples;

  int vsection_nsamples;

  tdrp_bool_t vsection_disable_interp;

  tdrp_bool_t use_static_file;

  char* static_file_url;

  tdrp_bool_t use_failover_urls;

  char* *_failover_urls;
  int failover_urls_n;

  tdrp_bool_t serve_multiple_domains;

  domain_t *_domains;
  int domains_n;

  tdrp_bool_t auto_fail_over;

  tdrp_bool_t override_data_set_name_on_read;

  char* data_set_name_read_xml;

  tdrp_bool_t override_data_set_source_on_read;

  char* data_set_source_read_xml;

  tdrp_bool_t override_data_set_info_on_read;

  char* data_set_info_read_xml;

  tdrp_bool_t auto_remap_to_latlon;

  tdrp_bool_t constrain_forecast_lead_times;

  forecast_constraints_t forecast_constraints;

  tdrp_bool_t create_composite_on_read;

  tdrp_bool_t decimate;

  int decimation_max_nxy;

  tdrp_bool_t serve_rhi_data;

  char* rhi_url;

  tdrp_bool_t polar_rhi;

  int rhi_time_margin;

  double rhi_max_az_error;

  tdrp_bool_t respect_user_rhi_distance;

  tdrp_bool_t specify_vertical_units;

  vertical_units_t vertical_units;

  tdrp_bool_t handle_derived_fields;

  derived_field_t *_derived_fields;
  int derived_fields_n;

  tdrp_bool_t use_climatology_url;

  climatology_type_t climatology_type;

  char* climatology_dir;

  tdrp_bool_t fill_missing_regions;

  tdrp_bool_t set_valid_time_search_wt;

  double valid_time_search_wt;

  tdrp_bool_t forward_on_write;

  char* *_forward_on_write_urls;
  int forward_on_write_urls_n;

  tdrp_bool_t override_write_format;

  data_format_t write_format;

  tdrp_bool_t write_as_forecast;

  tdrp_bool_t if_forecast_write_as_forecast;

  tdrp_bool_t write_using_extended_paths;

  tdrp_bool_t control_mdv2ncf;

  ncf_global_attributes_t ncf_global_attributes;

  mdv2ncf_field_transform_t *_mdv2ncf_field_transforms;
  int mdv2ncf_field_transforms_n;

  tdrp_bool_t ncf_compress_data;

  int ncf_compression_level;

  char* ncf_filename_suffix;

  ncformat_t ncf_file_format;

  tdrp_bool_t ncf_output_latlon_arrays;

  tdrp_bool_t ncf_output_start_end_times;

  tdrp_bool_t ncf_output_mdv_attributes;

  tdrp_bool_t ncf_output_mdv_chunks;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[91];

  const char *_className;

  bool _exitDeferred;

};

#endif

