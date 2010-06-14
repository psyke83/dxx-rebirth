#ifndef __JUKEBOX_H__
#define __JUKEBOX_H__

void jukebox_unload();
void jukebox_load();
int jukebox_play();
char *jukebox_current();
int jukebox_is_loaded();
int jukebox_is_playing();
int jukebox_numtracks();
void jukebox_list();

#endif
