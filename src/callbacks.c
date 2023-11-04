#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "yassAjoutRegister.h"
#include "yassVerifLogin.h"

static GtkWidget *yasmine_ajout_calendar1;
void on_yasmine_register_button_clicked(GtkWidget *objet_graphique, gpointer user_data){
  
GtkWidget *yasmine_login_window;
GtkWidget *yasmine_register_window;

GtkWidget* yasmine_register_entryNom;
GtkWidget* yasmine_register_entryPrenom;
GtkWidget* yasmine_register_entryUsername;
GtkWidget* yasmine_register_entryPassword;
GtkWidget* yasmine_register_entryRole;

char nom[50];
char prenom[50];
char username[50];
char password[50];
int role;

yasmine_register_entryNom = lookup_widget(objet_graphique, "yasmine_register_entryNom");
yasmine_register_entryPrenom = lookup_widget(objet_graphique, "yasmine_register_entryPrenom");
yasmine_register_entryUsername = lookup_widget(objet_graphique, "yasmine_register_entryUsername");
yasmine_register_entryPassword = lookup_widget(objet_graphique, "yasmine_register_entryPassword");
yasmine_register_entryRole = lookup_widget(objet_graphique, "yasmine_register_entryRole");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(yasmine_register_entryNom)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(yasmine_register_entryPrenom)));
strcpy(username,gtk_entry_get_text(GTK_ENTRY(yasmine_register_entryUsername)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(yasmine_register_entryPassword)));

role = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_register_entryRole)) ) ;

	yassAjoutRegister(nom, prenom, username, password, role);

	 yasmine_login_window = create_yasmine_login_window ();
  	gtk_widget_show (yasmine_login_window);
   
// Get the register window and hide it
    yasmine_register_window = lookup_widget(objet_graphique, "yasmine_register_window");
    gtk_widget_hide(yasmine_register_window);
} 




void on_yasmine_login_button_clicked (GtkWidget *objet_graphique, gpointer user_data) {
  
    GtkWidget *yasmine_welcome_window;

  GtkWidget *yasmine_login_entryUsername;
    GtkWidget *yasmine_login_entryPassword;
    GtkWidget *yasmine_login_label_error;

    char usernameLogin[50];
    char passwordLogin[50];

    yasmine_login_entryUsername = lookup_widget(objet_graphique, "yasmine_login_entryUsername");
    yasmine_login_entryPassword = lookup_widget(objet_graphique, "yasmine_login_entryPassword");
    yasmine_login_label_error = lookup_widget(objet_graphique, "yasmine_login_label_error");

    strcpy(usernameLogin, gtk_entry_get_text(GTK_ENTRY(yasmine_login_entryUsername)) );
    strcpy(passwordLogin, gtk_entry_get_text(GTK_ENTRY(yasmine_login_entryPassword)) );

    if (yassVerifLogin(usernameLogin, passwordLogin) == 1) {
        yasmine_welcome_window = create_yasmine_welcome_window();
        gtk_widget_show(yasmine_welcome_window);
      // Set a timeout to destroy the welcome window after a 3-second delay
        g_timeout_add(3000, (GSourceFunc)gtk_widget_destroy, yasmine_welcome_window);
    } else {
        gtk_label_set_text(GTK_LABEL(yasmine_login_label_error), "error: User invalid");
    }
}


void
on_yasmine_home_navbar_viewAll_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_home_navbar_qtdispo_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_home_navbar_typerare_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_home_ajouter_button_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *yasmine_ajout_window = create_yasmine_ajout_window ();
gtk_widget_show(yasmine_ajout_window);
}


void
on_yasmine_home_modifier_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_home_supprimer_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_ajout_confirm_yes_radioBtn_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_ajout_confirm_non_radioBtn_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_update_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_delete_button_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_delete_checkbutton_non_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yasmine_update_confirm_checkbtn_oui_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


gboolean
on_yasmine_ajout_entryDate_focus_in_event (GtkWidget *widget, GdkEventFocus   *event, gpointer  user_data)
{
    	    GtkWidget *yasmine_ajout_calendar1 = lookup_widget(GTK_WIDGET(widget), "yasmine_ajout_calendar1");

    	if (yasmine_ajout_calendar1 != NULL) {
        	gtk_widget_show(yasmine_ajout_calendar1); 
   		 }

  
  	return FALSE;
}


void
on_yasmine_ajout_calendar1_day_selected
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
    char *date_str;
    GtkWidget *yasmine_ajout_entryDate = lookup_widget(GTK_WIDGET(calendar), "yasmine_ajout_entryDate");
    int year, month, day;

    gtk_calendar_get_date(calendar, &day, &month, &year);

    date_str = g_strdup_printf("%02d-%02d-%04d", day, month + 1, year);

    gtk_entry_set_text(GTK_ENTRY(yasmine_ajout_entryDate ), date_str);
    g_free(date_str);
}

