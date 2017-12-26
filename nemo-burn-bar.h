/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2005 William Jon McCann <mccann@jhu.edu>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Authors: William Jon McCann <mccann@jhu.edu>
 *
 */

#ifndef __NEMO_BURN_BAR_H
#define __NEMO_BURN_BAR_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define NEMO_TYPE_DISC_BURN_BAR         (nemo_disc_burn_bar_get_type ())
#define NEMO_DISC_BURN_BAR(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), NEMO_TYPE_DISC_BURN_BAR, NemoDiscBurnBar))
#define NEMO_DISC_BURN_BAR_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), NEMO_TYPE_DISC_BURN_BAR, NemoDiscBurnBarClass))
#define NEMO_IS_DISC_BURN_BAR(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), NEMO_TYPE_DISC_BURN_BAR))
#define NEMO_IS_DISC_BURN_BAR_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), NEMO_TYPE_DISC_BURN_BAR))
#define NEMO_DISC_BURN_BAR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), NEMO_TYPE_DISC_BURN_BAR, NemoDiscBurnBarClass))

typedef struct NemoDiscBurnBarPrivate NemoDiscBurnBarPrivate;

typedef struct
{
        GtkBox                     box;
        NemoDiscBurnBarPrivate *priv;
} NemoDiscBurnBar;

typedef struct
{
        GtkBoxClass          parent_class;

	void (* title_changed) (NemoDiscBurnBar *bar);
	void (* icon_changed)  (NemoDiscBurnBar *bar);
	void (* activate)      (NemoDiscBurnBar *bar);

} NemoDiscBurnBarClass;

GType       nemo_disc_burn_bar_get_type          (void);
GtkWidget  *nemo_disc_burn_bar_new               (void);

GtkWidget  *nemo_disc_burn_bar_get_button        (NemoDiscBurnBar *bar);

const gchar *
nemo_disc_burn_bar_get_icon (NemoDiscBurnBar *bar);

void
nemo_disc_burn_bar_set_icon (NemoDiscBurnBar *bar,
                                 const gchar *icon_path);

void
nemo_disc_burn_bar_set_title (NemoDiscBurnBar *bar,
                                  const gchar *title);

const gchar *
nemo_disc_burn_bar_get_title (NemoDiscBurnBar *bar);

G_END_DECLS

#endif /* __GS_BURN_BAR_H */
