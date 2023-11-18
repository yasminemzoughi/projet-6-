#include <gtk/gtk.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} date_du_don;

typedef struct {
    int id_donneur;
    int id_du_don;
    char type_de_sang[100];
    int id_ETS;
    int quantite_sang;
    date_du_don date;
} don;
void ajouter(don d);
void afficher_don(GtkTreeView *liste);
void supprimer_don( int id_to_delete);


/*int quantite_type(char nomFichier[], char type_sang[]);
void sang_rare(char *file, char sangRare[]);
*/
