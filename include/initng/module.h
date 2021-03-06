/*
 * Initng, a next generation sysvinit replacement.
 * Copyright (C) 2006 Jimmy Wennlund <jimmy.wennlund@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef INITNG_MODULE_H
#define INITNG_MODULE_H
#include <stdarg.h>

#include <initng/system_states.h>
#include <initng/list.h>
#include <initng/active_db.h>
#include <initng/msg.h>
#include <initng/event/event.h>

/* flags for f_module_h.what - correspond to the arguments of select() */
typedef enum {
	IOW_READ = 1,	/* Want notification when data is ready to be read */
	IOW_WRITE = 2,	/* when data can be written successfully */
	IOW_ERROR = 4,	/* when an exceptional condition occurs */
} e_fdw;

typedef struct ft_module_h f_module_h;
struct ft_module_h {
	void (*call_module) (f_module_h * module, e_fdw what);
	e_fdw what;
	int fds;
};

typedef union {
	/* a skeleton, newer use */
	void *pointer;

	/* put all hook functions here */
	int (*event)(s_event * event);
} uc __attribute__ ((__transparent_union__));


typedef struct s_callers_s s_call;
struct s_callers_s {
	char *from_file;
	uc c;
	int order;
	list_t list;
};

#define while_list(current, call) \
	initng_list_foreach_rev(current, &(call)->list, list)

#define while_list_safe(current, call, safe) \
	initng_list_foreach_rev_safe(current, safe, &(call)->list, list)

#endif /* INITNG_MODULE_H */
