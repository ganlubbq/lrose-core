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
/////////////////////////////////////////////////////////////
// Radx2Esd.hh
//
// Radx2Esd object
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// Sept 2017
//
///////////////////////////////////////////////////////////////
//
// Reads radial radar data in file supported by Radx,
// writes out file in ESD ASCII format.
//
////////////////////////////////////////////////////////////////

#ifndef Radx2Esd_HH
#define Radx2Esd_HH

#include "Args.hh"
#include "Params.hh"
#include <string>
#include <Radx/Radx.hh>
class RadxVol;
class RadxFile;
class RadxRay;
class VarTransform;
using namespace std;

class Radx2Esd {
  
public:

  // constructor
  
  Radx2Esd (int argc, char **argv);

  // destructor
  
  ~Radx2Esd();

  // run 

  int Run();

  // data members

  int OK;

protected:
private:

  string _progName;
  char *_paramsPath;
  Args _args;
  Params _params;
  vector<string> _readPaths;

  vector<VarTransform *> _varTrans;

  int _volNum;

  int _runFilelist();
  int _runArchive();
  int _runRealtime();
  int _readFile(const string &filePath,
                RadxVol &vol);
  void _setupRead(RadxFile &file);
  void _finalizeVol(RadxVol &vol);
  int _writeVol(RadxVol &vol);
  void _writeRay(FILE *out, RadxRay *ray);
  int _calcCheckSum16(const char *pntr, size_t len);

};

#endif
