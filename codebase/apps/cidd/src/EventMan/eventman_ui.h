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
#ifndef	eventman_HEADER
#define	eventman_HEADER

/*
 * eventman_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `eventman.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;


typedef struct {
	Xv_opaque	em_bw;
	Xv_opaque	em_cp;
	Xv_opaque	goto_bt;
	Xv_opaque	rt_bt;
	Xv_opaque	help_bt;
	Xv_opaque	close_bt;
	Xv_opaque	event_list;
	Xv_opaque	fname_tx;
	Xv_opaque	summary_tx;
	Xv_opaque	date_tx;
	Xv_opaque	end_time_tx;
	Xv_opaque	add_bt;
	Xv_opaque	del_bt;
	Xv_opaque	save_bt;
	Xv_opaque	mailto_bt;
	Xv_opaque	msg1;
	Xv_opaque	em_tp;
} eventman_em_bw_objects;

extern eventman_em_bw_objects	*eventman_em_bw_objects_initialize(eventman_em_bw_objects *, Xv_opaque);

extern Xv_opaque	eventman_em_bw_em_bw_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_em_cp_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_goto_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_rt_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_help_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_close_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_event_list_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_fname_tx_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_summary_tx_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_date_tx_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_end_time_tx_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_add_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_del_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_save_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_mailto_bt_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_msg1_create(eventman_em_bw_objects *, Xv_opaque);
extern Xv_opaque	eventman_em_bw_em_tp_create(eventman_em_bw_objects *, Xv_opaque);
#endif
