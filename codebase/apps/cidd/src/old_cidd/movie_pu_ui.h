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
#ifndef	movie_pu_HEADER
#define	movie_pu_HEADER

/*
 * movie_pu_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `movie_pu.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;


typedef struct {
	Xv_opaque	movie_pu;
	Xv_opaque	movie_cp;
	Xv_opaque	start_time_tx;
	Xv_opaque	time_interval_tx;
	Xv_opaque	min_msg;
	Xv_opaque	fcast_per_tx;
	Xv_opaque	facst_time_usits_msg;
	Xv_opaque	end_frame_tx;
	Xv_opaque	st_frame_tx;
	Xv_opaque	msg1;
	Xv_opaque	movie_type_st;
	Xv_opaque	start_st;
	Xv_opaque	movie_dwell_sl;
	Xv_opaque	movie_speed_sl;
	Xv_opaque	movie_frame_sl;
	Xv_opaque	fr_begin_msg;
	Xv_opaque	group2;
} movie_pu_movie_pu_objects;

extern movie_pu_movie_pu_objects	*movie_pu_movie_pu_objects_initialize();

extern Xv_opaque	movie_pu_movie_pu_movie_pu_create();
extern Xv_opaque	movie_pu_movie_pu_movie_cp_create();
extern Xv_opaque	movie_pu_movie_pu_start_time_tx_create();
extern Xv_opaque	movie_pu_movie_pu_time_interval_tx_create();
extern Xv_opaque	movie_pu_movie_pu_min_msg_create();
extern Xv_opaque	movie_pu_movie_pu_fcast_per_tx_create();
extern Xv_opaque	movie_pu_movie_pu_facst_time_usits_msg_create();
extern Xv_opaque	movie_pu_movie_pu_end_frame_tx_create();
extern Xv_opaque	movie_pu_movie_pu_st_frame_tx_create();
extern Xv_opaque	movie_pu_movie_pu_msg1_create();
extern Xv_opaque	movie_pu_movie_pu_movie_type_st_create();
extern Xv_opaque	movie_pu_movie_pu_start_st_create();
extern Xv_opaque	movie_pu_movie_pu_movie_dwell_sl_create();
extern Xv_opaque	movie_pu_movie_pu_movie_speed_sl_create();
extern Xv_opaque	movie_pu_movie_pu_movie_frame_sl_create();
extern Xv_opaque	movie_pu_movie_pu_fr_begin_msg_create();
extern Xv_opaque	movie_pu_movie_pu_group2_create();
#endif