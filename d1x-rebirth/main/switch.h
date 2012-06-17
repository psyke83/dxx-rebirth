/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1998 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/

/*
 *
 * Triggers and Switches.
 *
 */

#ifndef _SWITCH_H
#define _SWITCH_H

#include "inferno.h"
#include "segment.h"

#define MAX_TRIGGERS        100
#define MAX_WALLS_PER_LINK  10

// Trigger flags	  
#define TRIGGER_CONTROL_DOORS      1    // Control Trigger
#define TRIGGER_SHIELD_DAMAGE      2    // Shield Damage Trigger
#define TRIGGER_ENERGY_DRAIN       4    // Energy Drain Trigger
#define TRIGGER_EXIT               8    // End of level Trigger
#define TRIGGER_ON                16    // Whether Trigger is active
#define TRIGGER_ONE_SHOT          32    // If Trigger can only be triggered once
#define TRIGGER_MATCEN            64    // Trigger for materialization centers
#define TRIGGER_ILLUSION_OFF     128    // Switch Illusion OFF trigger
#define TRIGGER_SECRET_EXIT      256    // Exit to secret level
#define TRIGGER_ILLUSION_ON      512    // Switch Illusion ON trigger

typedef struct trigger {
	sbyte		type;
	short		flags;
	fix     value;
	fix     time;
	sbyte		link_num;
	short 	num_links;
	short   seg[MAX_WALLS_PER_LINK];
	short   side[MAX_WALLS_PER_LINK];
} __pack__ trigger;

extern trigger Triggers[MAX_TRIGGERS];

extern int Num_triggers;

extern void trigger_init();

void check_trigger(segment *seg, short side, short objnum, int shot);
int check_trigger_sub(int trigger_num, int player_num, int shot);

extern void triggers_frame_process();

/*
 * reads a trigger structure from a PHYSFS_file
 */
extern void trigger_read(trigger *t, PHYSFS_file *fp);

/*
 * reads n trigger structs from a PHYSFS_file and swaps if specified
 */
extern void trigger_read_n_swap(trigger *t, int n, int swap, PHYSFS_file *fp);

extern void trigger_write(trigger *t, short version, PHYSFS_file *fp);

static inline int trigger_is_exit(const trigger *t)
{
	return t->flags == TRIGGER_EXIT;
}

#endif
 
