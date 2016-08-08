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
	Xv_opaque	fr_begin_msg;
	Xv_opaque	fcast_per_tx;
	Xv_opaque	facst_time_usits_msg;
	Xv_opaque	start_time_tx;
	Xv_opaque	start_st;
	Xv_opaque	movie_type_st;
	Xv_opaque	end_frame_tx;
	Xv_opaque	time_interval_tx;
	Xv_opaque	min_msg;
	Xv_opaque	save_loop_bt;
	Xv_opaque	sweep_st;
	Xv_opaque	movie_frame_sl;
	Xv_opaque	movie_speed_sl;
	Xv_opaque	movie_dwell_sl;
	Xv_opaque	prod_title_msg;
	Xv_opaque	grid_title_msg;
	Xv_opaque	time_can;
} movie_pu_movie_pu_objects;

extern movie_pu_movie_pu_objects	*movie_pu_movie_pu_objects_initialize(movie_pu_movie_pu_objects *, Xv_opaque);

extern Xv_opaque	movie_pu_movie_pu_movie_pu_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_movie_cp_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_fr_begin_msg_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_fcast_per_tx_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_facst_time_usits_msg_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_start_time_tx_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_start_st_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_movie_type_st_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_end_frame_tx_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_time_interval_tx_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_min_msg_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_save_loop_bt_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_sweep_st_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_movie_frame_sl_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_movie_speed_sl_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_movie_dwell_sl_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_prod_title_msg_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_grid_title_msg_create(movie_pu_movie_pu_objects *, Xv_opaque);
extern Xv_opaque	movie_pu_movie_pu_time_can_create(movie_pu_movie_pu_objects *, Xv_opaque);
#endif