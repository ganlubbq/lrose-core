/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/***************************************************************************
 * read_elevations.c
 *
 * Read in elevations array generated by dva_mklookup
 *
 * Mike Dixon
 * Marion Mittermaier
 *
 * RAP, NCAR, Boulder, Colorado, USA
 *
 * Aug 1998
 *
 ****************************************************************************/

#include "dva_cart.h"

int read_elevations(int *n_elev_p,
		    double **elevations_p)

{

  FILE *fp;
  int i, n_elev;
  double *elevations;
  
  if ((fp = fopen(Glob->params.radar_elevations_file_path, "r")) == NULL) {
    fprintf(stderr, "ERROR - %s\n", Glob->prog_name);
    fprintf(stderr, "Cannot open elevations file\n");
    perror(Glob->params.radar_elevations_file_path);
    return (-1);
  }

  if (fscanf(fp, "%d", &n_elev) != 1) {
    fprintf(stderr, "ERROR - %s\n", Glob->prog_name);
    fprintf(stderr, "Cannot read elevations array\n");
    perror(Glob->params.radar_elevations_file_path);
    fclose(fp);
    return (-1);
  }
  *n_elev_p = n_elev;

  elevations = (double *) umalloc(n_elev * sizeof(double));
  *elevations_p = elevations;

  for (i = 0; i < n_elev; i++) {
    if (fscanf(fp, "%lg", &elevations[i]) != 1) {
      fprintf(stderr, "ERROR - %s\n", Glob->prog_name);
      fprintf(stderr, "Cannot read elevations array\n");
      perror(Glob->params.radar_elevations_file_path);
      fclose(fp);
      return (-1);
    }
  }
  fclose(fp);

  return (0);

}
