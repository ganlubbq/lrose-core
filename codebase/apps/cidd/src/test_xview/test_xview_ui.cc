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
/*
 * test_xview_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `test_xview.G'.
 * DO NOT EDIT BY HAND.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/canvas.h>
#include <xview/panel.h>
#include <xview/scrollbar.h>
#include <xview/svrimage.h>
#include <xview/termsw.h>
#include <xview/text.h>
#include <xview/tty.h>
#include <xview/xv_xrect.h>
#include "test_xview_ui.h"

/*
 * Initialize an instance of object `window1'.
 */
test_xview_window1_objects *
test_xview_window1_objects_initialize(test_xview_window1_objects *ip, Xv_opaque owner)
{
	if (!ip && !(ip = (test_xview_window1_objects *) calloc(1, sizeof (test_xview_window1_objects))))
		return (test_xview_window1_objects *) NULL;
	if (!ip->window1)
		ip->window1 = test_xview_window1_window1_create(ip, owner);
	if (!ip->controls1)
		ip->controls1 = test_xview_window1_controls1_create(ip, ip->window1);
	if (!ip->button1)
		ip->button1 = test_xview_window1_button1_create(ip, ip->controls1);
	return ip;
}

/*
 * Create object `window1' in the specified instance.
 */
Xv_opaque
test_xview_window1_window1_create(test_xview_window1_objects *ip, Xv_opaque owner)
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 170,
		XV_HEIGHT, 128,
		XV_LABEL, "Base Window",
		FRAME_SHOW_FOOTER, TRUE,
		FRAME_SHOW_RESIZE_CORNER, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `controls1' in the specified instance.
 */
Xv_opaque
test_xview_window1_controls1_create(test_xview_window1_objects *ip, Xv_opaque owner)
{
	extern Notify_value	control_panel_proc(Xv_window, Event *, Notify_arg, Notify_event_type);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		WIN_BORDER, FALSE,
		NULL);
	xv_set(obj, WIN_CONSUME_EVENTS,
		WIN_MOUSE_BUTTONS,
		LOC_MOVE,
		LOC_DRAG,
		LOC_WINENTER,
		LOC_WINEXIT,
		WIN_ASCII_EVENTS,
		WIN_LEFT_KEYS,
		WIN_RIGHT_KEYS,
		WIN_TOP_KEYS,
		NULL, NULL);
	notify_interpose_event_func(obj,
		(Notify_func) control_panel_proc, NOTIFY_SAFE);
	return obj;
}

/*
 * Create object `button1' in the specified instance.
 */
Xv_opaque
test_xview_window1_button1_create(test_xview_window1_objects *ip, Xv_opaque owner)
{
	extern void		quit_bt_proc(Panel_item, Event *);
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 56,
		XV_Y, 56,
		PANEL_LABEL_STRING, "QUIT",
		PANEL_NOTIFY_PROC, quit_bt_proc,
		NULL);
	return obj;
}
