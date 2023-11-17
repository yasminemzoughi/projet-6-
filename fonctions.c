#include "fonctions.h"

enum{
	EID_DONNEUR,
	EID_DU_DON,
	ETYPE_DE_SANG,
	EID_ETS,
	EQUANTITE_SANG,
	EDATE,
	COLUMNS,
} ;

void ajouter(don d){
FILE *f;
f = fopen("don.txt","a+");
	if (f != NULL){
	fprintf(f, "%d %d %s %d %d %d %d %d\n", d.id_donneur, d.id_du_don,d.type_de_sang, d.id_ETS, d.quantite_sang, d.date.jour, d.date.mois, d.date.annee);
     fclose(f);
	}
}


/////////////////////
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
FILE *f;
don d;
	store=NULL;
	store=gtk_tree_view_get_model(liste);
if(store ==NULL){

//id_donneur
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id_donneur",renderer, "text",EID_DONNEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_du_don
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id_du_don",renderer, "text",EID_DU_DON, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//type_de_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type_de_sang",renderer, "text",ETYPE_DE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//id_ETS
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id_ETS",renderer, "text",EID_ETS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//quantite_sang
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("quantite_sang",renderer, "text",EQUANTITE_SANG, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
//date
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date",renderer, "text",EDATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("don.txt", "r");
	if (f != NULL){
	return;


	}else {
	f=fopen("don.txt", "a+");
	 while (fscanf(f, "%d %d %s %d %d %d %d %d\n", &d.id_donneur, &d.id_du_don, d.type_de_sang, &d.id_ETS, &d.quantite_sang, &d.date.jour, &d.date.mois, &d.date.annee) != EOF){
        {
	gtk_list_store_append(store, &iter);
	gtk_list_store_set (store, &iter, EID_DONNEUR, id_donneur,EID_DU_DON, id_du_don,
ETYPE_DE_SANG,type_de_sang,EID_ETS, id_ETS,EQUANTITE_SANG,quantite_sang,EDATE,date, -1);
		
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);	



	}
}








}
