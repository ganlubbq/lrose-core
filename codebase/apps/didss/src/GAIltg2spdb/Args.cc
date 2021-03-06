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
/*********************************************************************
 * Args.cc: class controlling the command line arguments for the
 *          GAIltg2spdb program.
 *
 * RAP, NCAR, Boulder CO
 *
 * June 2002
 *
 * Gary Blackburn
 *
 *********************************************************************/

#include "Args.hh"  
#include "Params.hh"
#include <string.h>
#include <toolsa/umisc.h>
#include <toolsa/str.h>
using namespace std;

/**********************************************************************
 * Constructor
 */

Args::Args (int argc, char **argv, string &prog_name)
{

  // Intialize
  okay = true;

  char tmp_str[256];


  TDRP_init_override(&override);
  
  // search for command options
  
  for (int i =  1; i < argc; i++)
  {
    if (STRequal_exact(argv[i], "--") ||
	STRequal_exact(argv[i], "-h") ||
	STRequal_exact(argv[i], "-help") ||
	STRequal_exact(argv[i], "-man"))
    {
      _usage(prog_name, cout);
      exit(0);
    }
    else if (STRequal_exact(argv[i], "-debug")) {
      sprintf(tmp_str, "debug = true;");
      TDRP_add_override(&override, tmp_str);
    }
    else if (STRequal_exact(argv[i], "-five_fields")) {
      sprintf(tmp_str, "five_fields = true;");
      TDRP_add_override(&override, tmp_str);
    }
    else if (!strcmp(argv[i], "-start")) {
   
      if (i < argc - 1) {
        date_time_t start;
        if (sscanf(argv[++i], "%d %d %d %d %d %d",
                   &start.year, &start.month, &start.day,
                   &start.hour, &start.min, &start.sec) != 6) {
          okay = false;
        } else {
          uconvert_to_utime(&start);
          startTime = start.unix_time;
        }
      } 
      else {
        okay = false;
      }

      sprintf(tmp_str, "mode = ARCHIVE;");
      TDRP_add_override(&override, tmp_str);

    } 
    else if (!strcmp(argv[i], "-end")) {
   
      if (i < argc - 1) {
        date_time_t end;
        if (sscanf(argv[++i], "%d %d %d %d %d %d",
                   &end.year, &end.month, &end.day,
                   &end.hour, &end.min, &end.sec) != 6) {
          okay = false;
        } else {
          uconvert_to_utime(&end);
          endTime = end.unix_time;
        }
      } 
      else {
        okay = false;
      }

      sprintf(tmp_str, "mode = ARCHIVE;");
      TDRP_add_override(&override, tmp_str);

    } 
    else if (!strcmp(argv[i], "-f")) {

      if (i < argc - 1) {
        // load up file list vector. Break at next arg which
        // start with -
        for (int j = i + 1; j < argc; j++) {
          if (argv[j][0] == '-') {
            break;
          } else {
            inputFileList.push_back(argv[j]);
          }
        }
      } 
      else {
        okay = false;
      }
   
      sprintf(tmp_str, "mode = ARCHIVE;");
      TDRP_add_override(&override, tmp_str);

    } // if
   
  } // i
  
  if (!okay)
  {
    _usage(prog_name, cerr);
  }
    
}


/**********************************************************************
 * Destructor
 */

Args::~Args(void)
{
  TDRP_free_override(&override);
}
  

/**********************************************************************
 *              Private Member Functions                              *
 **********************************************************************/

/**********************************************************************
 * _usage() - Print the usage for this program.
 */

void Args::_usage(string &prog_name, ostream &out)
{
  out <<  "Usage:\n\n" << prog_name << " [options] as below:\n\n"
      <<  "       [ --, -h, -help, -man ] produce this list.\n"
      <<  "       [ -debug ] debugging on\n"
      <<  "       [ -end \"yyyy mm dd hh mm ss\"] end time\n"
      <<  "         sets ARCHIVE mode\n"
      <<  "       [ -f ? ?] input track file list (.GAI files)\n"
      <<  "         sets ARCHIVE mode\n"
      <<  "       [ -start \"yyyy mm dd hh mm ss\"] start time\n"
      <<  "         sets ARCHIVE mode\n"
      <<  "       [ -five_fields ] allow processing of old GAI data \n"
      << endl;


  Params::usage(out);
}






