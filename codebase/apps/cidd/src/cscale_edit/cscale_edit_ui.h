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
#ifndef	cscale_edit_HEADER
#define	cscale_edit_HEADER

/*
 * cscale_edit_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `cscale_edit.G'.
 * DO NOT EDIT BY HAND.
 */

extern Attr_attribute	INSTANCE;


typedef struct {
	Xv_opaque	window1;
	Xv_opaque	controls1;
	Xv_opaque	read_file_button;
	Xv_opaque	delete_button;
	Xv_opaque	insert_above;
	Xv_opaque	insert_below;
	Xv_opaque	fields;
	Xv_opaque	max;
	Xv_opaque	write_file_button;
	Xv_opaque	sort_button;
	Xv_opaque	quit_button;
	Xv_opaque	min;
	Xv_opaque	slider1;
	Xv_opaque	value_setting;
	Xv_opaque	clear_button;
	Xv_opaque	color_label;
	Xv_opaque	color_message;
	Xv_opaque	status_message;
	Xv_opaque	canvas1;
	Xv_opaque	canvas2;
} cscale_edit_window1_objects;

extern cscale_edit_window1_objects	*cscale_edit_window1_objects_initialize();

extern Xv_opaque	cscale_edit_window1_window1_create();
extern Xv_opaque	cscale_edit_window1_controls1_create();
extern Xv_opaque	cscale_edit_window1_read_file_button_create();
extern Xv_opaque	cscale_edit_window1_delete_button_create();
extern Xv_opaque	cscale_edit_window1_insert_above_create();
extern Xv_opaque	cscale_edit_window1_insert_below_create();
extern Xv_opaque	cscale_edit_window1_fields_create();
extern Xv_opaque	cscale_edit_window1_max_create();
extern Xv_opaque	cscale_edit_window1_write_file_button_create();
extern Xv_opaque	cscale_edit_window1_sort_button_create();
extern Xv_opaque	cscale_edit_window1_quit_button_create();
extern Xv_opaque	cscale_edit_window1_min_create();
extern Xv_opaque	cscale_edit_window1_slider1_create();
extern Xv_opaque	cscale_edit_window1_value_setting_create();
extern Xv_opaque	cscale_edit_window1_clear_button_create();
extern Xv_opaque	cscale_edit_window1_color_label_create();
extern Xv_opaque	cscale_edit_window1_color_message_create();
extern Xv_opaque	cscale_edit_window1_status_message_create();
extern Xv_opaque	cscale_edit_window1_canvas1_create();
extern Xv_opaque	cscale_edit_window1_canvas2_create();
#endif
