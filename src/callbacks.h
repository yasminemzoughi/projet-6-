#include <gtk/gtk.h>


void on_yasmine_register_button_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_yasmine_login_button_clicked(GtkWidget *objet_graphique, gpointer user_data);

void
on_yasmine_home_navbar_viewAll_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_home_navbar_qtdispo_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_home_navbar_typerare_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_home_ajouter_button_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_home_modifier_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_home_supprimer_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_ajout_confirm_yes_radioBtn_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_ajout_confirm_non_radioBtn_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_update_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_delete_button_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_delete_checkbutton_non_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_update_confirm_checkbtn_oui_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_yasmine_ajout_entryDate_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_yasmine_ajout_calendar1_day_selected
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data);
