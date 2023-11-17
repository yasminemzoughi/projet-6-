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

void on_yasmine_home_ajouter_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data);

void on_yasmine_home_modifier_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data);

void
on_yasmine_home_supprimer_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data);
                                       
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
//hneeeeee
void
on_yasmine_treeview_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_yasmine_home_retour_button_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_yasmine_ajout_button_clicked        (GtkWidget*   objet, gpointer   user_data);

void
on_yasmine_ajout_button_afficher_clicked  (GtkWidget*   objet, gpointer user_data);
