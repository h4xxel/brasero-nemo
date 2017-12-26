#include <gtk/gtk.h>
#include "brasero-utils.h"

GtkWidget *
brasero_utils_create_message_dialog (GtkWidget *parent,
				     const gchar *primary_message,
				     const gchar *secondary_message,
				     GtkMessageType type)
{
	GtkWidget *message;

	message = gtk_message_dialog_new (GTK_WINDOW (parent),
					  0,
					  type,
					  GTK_BUTTONS_CLOSE,
					  "%s",
					  primary_message);

	gtk_window_set_icon_name (GTK_WINDOW (message),
	                          parent? gtk_window_get_icon_name (GTK_WINDOW (parent)):"brasero");

	gtk_window_set_title (GTK_WINDOW (message), "");

	if (secondary_message)
		gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG (message),
							  "%s.",
							  secondary_message);

	return message;
}

void
brasero_utils_message_dialog (GtkWidget *parent,
			      const gchar *primary_message,
			      const gchar *secondary_message,
			      GtkMessageType type)
{
	GtkWidget *message;

	message = brasero_utils_create_message_dialog (parent,
						       primary_message,
						       secondary_message,
						       type);

	gtk_dialog_run (GTK_DIALOG (message));
	gtk_widget_destroy (message);
}
