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
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* RCS info
 *   $Author: cunning $
 *   $Locker:  $
 *   $Date: 2016/12/08 22:51:19 $
 *   $Id: PolarStereoFieldProcessor.hh,v 1.3 2016/12/08 22:51:19 cunning Exp $
 *   $Revision: 1.3 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * PolarStereoFieldProcessor : Class the converts TeraScan data to a lat/lon
 *                        projection Mdv field.
 *
 * RAP, NCAR, Boulder CO
 *
 * October 2001
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef PolarStereoFieldProcessor_HH
#define PolarStereoFieldProcessor_HH


#include <string>

#include "FieldProcessor.hh"

using namespace std;


class PolarStereoFieldProcessor : public FieldProcessor
{
 public:

  ////////////////////
  // Public members //
  ////////////////////

  ////////////////////
  // Public methods //
  ////////////////////

  //////////////////////////////
  // Constructors/Destructors //
  //////////////////////////////

  /*********************************************************************
   * Constructor
   */

  PolarStereoFieldProcessor(SETP input_dataset);
  

  /*********************************************************************
   * Destructor
   */

  virtual ~PolarStereoFieldProcessor(void);
  
  /*********************************************************************
   * Access Methods
   */

  inline void setMapScaleFactor(double msf) { _mapScaleFactor = msf; }
  

private:

  double _minX;
  double _minY;
  double _deltaX;
  double _deltaY;
  double _mapScaleFactor;
  

  /*********************************************************************
   * _calcIndex() - Calculate the MDV field index for the given satellite
   *                field location.
   */

  virtual int _calcIndex(const int x_index, const int y_index);


  /*********************************************************************
   * _initLocal() - Do any initialization needed locally by the derived
   *                class.  This method is called at the end of the
   *                FieldProcessor::_init() method.
   */

  virtual bool _initLocal(ETXFORM mxfm);


  /*********************************************************************
   * _setProjectionInfo() - Set the projection information in the given
   *                        field header.
   */

  virtual void _setProjectionInfo(Mdvx::field_header_t &fld_hdr);

};


#endif
