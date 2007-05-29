/*
 * Initng, a next generation sysvinit replacement.
 * Copyright (C) 2006 Jimmy Wennlund <jimmy.wennlund@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
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

#include <initng.h>

#include <time.h>				/* time() */
#include <fcntl.h>				/* fcntl() */
#include <sys/un.h>				/* memmove() strcmp() */
#include <sys/wait.h>				/* waitpid() sa */
#include <linux/kd.h>				/* KDSIGACCEPT */
#include <sys/ioctl.h>				/* ioctl() */
#include <stdio.h>				/* printf() */
#include <stdlib.h>				/* free() exit() */
#include <sys/reboot.h>				/* reboot() RB_DISABLE_CAD */
#include <assert.h>
#include <ctype.h>				/* isgraph */

#include <initng-paths.h>


/* this frees an environment variable - not to be used on the output of
 * new_environ!
 */
void initng_env_free(char **tf)
{
	int i = 0;

	D_("free_environ();\n");
	assert(tf);
	for (i = 0; tf[i]; tf++)
		free(tf[i]);
	free(tf);
}
