#include "fonctions.h"

enum {
    EID_DONNEUR,
    EID_DU_DON,
    ETYPE_DE_SANG,
    EID_ETS,
    EQUANTITE_SANG,
    EDATE_JOUR,
    EDATE_MOIS,
    EDATE_ANNEE,
    COLUMNS,
};

// ajouter un don 
void ajouter(don d){
FILE *f;
f = fopen("don.txt","a+");
	if (f != NULL){
	fprintf(f, "%d %d %s %d %d %d %d %d\n", d.id_donneur, d.id_du_don,d.type_de_sang, d.id_ETS, d.quantite_sang, d.date.jour, d.date.mois, d.date.annee);
     fclose(f);
	}
}


//afficher un don 
void afficher_don(GtkTreeView *liste){

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;

	GtkTreeIter iter;

	GtkListStore *store;

	int id_donneur;
	int id_du_don;
	char type_de_sang[100];
	int id_ETS;
	int quantite_sang;
	date_du_don date;
don d ;
FILE *f;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
if(store==NULL){

//id_donneur
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id du donneur",renderer, "text",EID_DONNEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_du_don
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id du don",renderer, "text",EID_DU_DON, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//type_de_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type de sang",renderer, "text",ETYPE_DE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_ETS
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id ETS",renderer, "text",EID_ETS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//quantite_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("quantite sang",renderer, "text",EQUANTITE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//date  
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EDATE_JOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EDATE_MOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EDATE_ANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

}
      store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);

    f = fopen("don.txt", "r");
    if (f == NULL) {
        return;
    } else {
        while (fscanf(f, "%d %d %99s %d %d %d %d %d\n", &id_donneur, &id_du_don, type_de_sang, &id_ETS, &quantite_sang, &date.jour, &date.mois, &date.annee) == 8) {
            gtk_list_store_append(store, &iter);

  gchar date_str[20]; // Adjust size as needed
            sprintf(date_str, "%d/%d/%d", date.jour, date.mois, date.annee);

          gtk_list_store_set(store, &iter,
                               EID_DONNEUR, id_donneur, EID_DU_DON, id_du_don,
                               ETYPE_DE_SANG, type_de_sang, EID_ETS, id_ETS,
                               EQUANTITE_SANG, quantite_sang, EDATE_JOUR, date.jour,
                               EDATE_MOIS, date.mois, EDATE_ANNEE, date.annee, -1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
//supprimer
void supprimer_don(id_to_delete) {
    FILE *f = fopen("don.txt", "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f != NULL && f2 != NULL) {
        don d; // Declare a local variable to hold data read from the file

        while (fscanf(f, "%d %d %s %d %d %d %d %d\n", &d.id_donneur, &d.id_du_don, d.type_de_sang, &d.id_ETS, &d.quantite_sang, &d.date.jour, &d.date.mois, &d.date.annee) != EOF) {
            if (d.id_du_don != id_to_delete) {
                fprintf(f2, "%d %d %s %d %d %d %d %d\n", d.id_donneur, d.id_du_don, d.type_de_sang, d.id_ETS, d.quantite_sang, d.date.jour, d.date.mois, d.date.annee);
            }
        }
        fclose(f);
        fclose(f2);
        remove("don.txt");
        rename("nouv.txt", "don.txt");
    }
}


// vider tree view 

void vider(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;

GtkTreeIter iter;

 GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
    int id_donneur;
    int id_du_don;
    char type_de_sang[100];
    int id_ETS;
    int quantite_sang;
    date_du_don date;


FILE* f;
	if(store==NULL){
//id_donneur
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id du donneur",renderer, "text",EID_DONNEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_du_don
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id du don",renderer, "text",EID_DU_DON, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//type_de_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type de sang",renderer, "text",ETYPE_DE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_ETS
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id ETS",renderer, "text",EID_ETS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//quantite_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("quantite sang",renderer, "text",EQUANTITE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//date  jour 
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",EDATE_JOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//mois
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",EDATE_MOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//annee
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",EDATE_ANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//

    store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);

gtk_list_store_append(store, &iter);
 gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));


}	
	}


