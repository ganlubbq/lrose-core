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
 * test_xview_stubs.c - Notify and event callback function stubs.
 * This file was generated by `gxv' from `test_xview.G'.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/panel.h>
#include <xview/textsw.h>
#include <xview/xv_xrect.h>
#include "test_xview_ui.h"


/*
 * Global object definitions.
 */
test_xview_window1_objects	*Test_xview_window1;

#ifdef MAIN

/*
 * Instance XV_KEY_DATA key.  An instance is a set of related
 * user interface objects.  A pointer to an object's instance
 * is stored under this key in every object.  This must be a
 * global variable.
 */
Attr_attribute	INSTANCE;

main(int argc, char **argv)
{
	/*
	 * Initialize XView.
	 */
	xv_init(XV_INIT_ARGC_PTR_ARGV, &argc, argv, NULL);
	INSTANCE = xv_unique_key();
	
	/*
	 * Initialize user interface components.
	 * Do NOT edit the object initializations by hand.
	 */
	Test_xview_window1 = test_xview_window1_objects_initialize(NULL, NULL);
	
	
	/*
	 * Turn control over to XView.
	 */
	xv_main_loop(Test_xview_window1->window1);
	exit(0);
}

#endif


/*
 * Event callback function for `controls1'.
 */
Notify_value
control_panel_proc(Xv_window win, Event *event, Notify_arg arg, Notify_event_type type)
{
	test_xview_window1_objects *ip = (test_xview_window1_objects *) xv_get(win, XV_KEY_DATA, INSTANCE);
	
	fprintf(stderr, "test_xview: control_panel_proc: event %d\n", event_id(event));
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

	return notify_next_event_func(win, (Notify_event) event, arg, type);
}

/*
 * Notify callback function for `button1'.
 */
void
quit_bt_proc(Panel_item item, Event *event)
{
	test_xview_window1_objects *ip = (test_xview_window1_objects *) xv_get(item, XV_KEY_DATA, INSTANCE);
	
	fputs("test_xview: quit_bt_proc\n", stderr);

	exit(0);
	
	/* gxv_start_connections DO NOT EDIT THIS SECTION */

	/* gxv_end_connections */

}
