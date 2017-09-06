/*
 * Balloon
 *
 * Copyright IBM, Corp. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_BALLOON_H
#define QEMU_BALLOON_H

#include "qapi-types.h"

typedef void (QEMUBalloonEvent)(void *opaque, ram_addr_t target);
typedef void (QEMUBalloonStatus)(void *opaque, BalloonInfo *info);
typedef bool (QEMUBalloonFreePageSupport)(void *opaque);
typedef int (QEMUBalloonFreePageStart)(void *opaque);
typedef int (QEMUBalloonFreePageStop)(void *opaque);

int qemu_add_balloon_handler(QEMUBalloonEvent *event_fn,
                             QEMUBalloonStatus *stat_fn,
                             QEMUBalloonFreePageSupport *free_page_support_fn,
                             QEMUBalloonFreePageStart *free_page_start_fn,
                             QEMUBalloonFreePageStop *free_page_stop_fn,
                             void *opaque);
void qemu_remove_balloon_handler(void *opaque);
bool qemu_balloon_is_inhibited(void);
void qemu_balloon_inhibit(bool state);
bool balloon_free_page_support(void);
int balloon_free_page_start(void);
int balloon_free_page_stop(void);

#endif
