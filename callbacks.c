#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "yassAjoutRegister.h"
#include "yassVerifLogin.h"
#include "fonctions.h"



void on_yasmine_register_button_clicked(GtkWidget *objet_graphique, gpointer user_data){
  
GtkWidget *yasmine_login_window;

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

    } else {
	gtk_label_set_text(GTK_LABEL(yasmine_login_label_error),"error : User invalid");	

        
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

// from home to ajout window
void
on_yasmine_home_ajouter_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data)
{
GtkWidget *yasmine_home_window;
GtkWidget *yasmine_ajout_window;
yasmine_home_window = lookup_widget(objet_graphique, "yasmine_home_window");
gtk_widget_hide(yasmine_home_window);
yasmine_ajout_window= create_yasmine_ajout_window();
gtk_widget_show(yasmine_ajout_window);
}

// from home to update window
void
on_yasmine_home_modifier_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data)
                                     
{
GtkWidget *yasmine_home_window;
GtkWidget *yasmine_update_window;
yasmine_home_window = lookup_widget(objet_graphique, "yasmine_home_window");
gtk_widget_hide(yasmine_home_window);
yasmine_update_window= create_yasmine_update_window();
gtk_widget_show(yasmine_update_window);
}

// from home to delete window
void
on_yasmine_home_supprimer_button_clicked (GtkWidget *objet_graphique,  gpointer   user_data)
{
GtkWidget *yasmine_home_window;
GtkWidget *yasmine_delete_window;

yasmine_home_window = lookup_widget(objet_graphique, "yasmine_home_window");
gtk_widget_hide(yasmine_home_window);
yasmine_delete_window= create_yasmine_delete_window();
gtk_widget_show(yasmine_delete_window);
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

// hneee

void
on_yasmine_treeview_row_activated (GtkTreeView *treeview,GtkTreePath  *path, GtkTreeViewColumn *column, gpointer user_data)
{
/*
GtkTreeIter iter;
GtkWidget* yasmine_treeview;
gchar* type_de_sang;

don d;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)) {

   gtk_tree_model_get(GtkTreeModel*(model), &iter,
                      0, &d.id_donneur,
                      1, &d.id_du_don,
                      2, &type_de_sang,
                      3, &d.id_ETS,
                      4, &d.quantite_sang,
                      5, &d.date.jour,
                      6, &d.date.mois,
                      7, &d.date.annee,
                      -1);

  
   d.id_donneur = atoi(d.id_donneur);
   d.id_du_don = atoi(d.id_du_don);
   strcpy(d.type_de_sang, type_de_sang);
   d.id_ETS = atoi(d.id_ETS);
   d.quantite_sang = atoi(d.quantite_sang);
   d.date.jour = atoi(d.date.jour);
   d.date.mois = atoi(d.date.mois);
   d.date.annee = atoi(d.date.annee);

   afficher_don(yasmine_treeview);
}



*/
}


void
on_yasmine_home_retour_button_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}

//
void on_yasmine_ajout_button_clicked        (GtkWidget*   objet, gpointer   user_data)
{
    int id_donneur;
    int id_du_don;
    char type_de_sang[100];
    int id_ETS;
    int quantite_sang;
    date_du_don date;

don d;
GtkWidget *yasmine_ajout_entryIdDonneur;
GtkWidget* yasmine_ajout_entryId;
GtkWidget* yasmine_ajout_comboBox_typeSang;
GtkWidget* yasmine_ajout_comboBox_Ets;
GtkWidget* yasmine_ajout_entry_spinbutton_qte;
GtkWidget* yasmine_ajout_jour_spinBtn;
GtkWidget* yasmine_ajout_mois_spinBtn;
GtkWidget* yasmine_ajout_annee_spinBtn;


yasmine_ajout_entryIdDonneur = lookup_widget(objet, "yasmine_ajout_entryIdDonneur");
yasmine_ajout_entryId= lookup_widget(objet,"yasmine_ajout_entryId");
yasmine_ajout_comboBox_typeSang= lookup_widget(objet,"yasmine_ajout_comboBox_typeSang");
yasmine_ajout_comboBox_Ets= lookup_widget(objet,"yasmine_ajout_comboBox_Ets");
yasmine_ajout_entry_spinbutton_qte= lookup_widget(objet,"yasmine_ajout_entry_spinbutton_qte");
yasmine_ajout_jour_spinBtn= lookup_widget(objet,"yasmine_ajout_jour_spinBtn");
yasmine_ajout_mois_spinBtn= lookup_widget(objet,"yasmine_ajout_mois_spinBtn");
yasmine_ajout_annee_spinBtn= lookup_widget(objet,"yasmine_ajout_annee_spinBtn");



id_donneur = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_entryIdDonneur)));
id_du_don = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_entryId)) ) ;

strcpy(type_de_sang ,gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_comboBox_typeSang)));
id_ETS = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_comboBox_Ets)) ) ;
quantite_sang = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_entry_spinbutton_qte)) ) ;
date.jour = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_jour_spinBtn)) ) ;
date.mois = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_mois_spinBtn)) ) ;
date.annee = atoi(gtk_entry_get_text(GTK_ENTRY(yasmine_ajout_annee_spinBtn)) ) ;

ajouter(d);
}


void on_yasmine_ajout_button_afficher_clicked  (GtkWidget*   objet, gpointer user_data)
{/*
    GtkWidget *yasmine_ajout_window;
    GtkWidget *yasmine_home_window;
    GtkTreeView *yastreeview;

    yasmine_ajout_window = lookup_widget(objet, "yasmine_ajout_window");
    gtk_widget_destroy(yasmine_ajout_window);

    yasmine_home_window = create_yasmine_home_window();
    gtk_widget_show(yasmine_home_window);

    yastreeview = lookup_widget(objet, "yasmine_treeview");
   afficher_don(yastreeview);
*/
}
