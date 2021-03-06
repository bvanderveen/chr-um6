
/* 
 * File: event.h
 * Purpose: event interface
 *
 * Copyright (C) 2012 Tobias Simon, Ilmenau University of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef __EVENT_H__
#define __EVENT_H__


typedef struct
{
   void *(*create)(void);
   int (*timed_wait)(void *data, unsigned int timeout);
   void (*wait)(void *data);
   void (*signal)(void *data);
}
event_interface_t;


typedef struct
{
   void *data;
   event_interface_t *interface;
}
event_t;


void event_init(event_t *event, event_interface_t *interface);

int event_timed_wait(event_t *event, unsigned int timeout);

void event_wait(event_t *event);

void event_signal(event_t *event);


#endif /* __EVENT_H__ */

