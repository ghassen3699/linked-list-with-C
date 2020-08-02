#define NB_MAX 30 

/* declaration de nouveau type de donnee qui s'appel ouvrier  */
typedef struct ouvrier 
{
    char nom[NB_MAX] ;
    char prenom [NB_MAX] ;
    int age ;
    float salaire ;
    int reference_de_travail ;
    char sex [NB_MAX] ;
}ouvrier ;


/*declaration d'une liste chainee */
typedef struct cellule cellule ;
struct cellule                        /* declaration de cellule de la liste chainee */
{
    ouvrier donnee_ouvrier  ;
    struct cellule *suivant ;           /* creation de pointeur pour acceder facillement a l'ouvrier suivant */
};
typedef struct cellule *liste ;



/* declaration de prototype de programme */
liste initialisation_liste () ;
ouvrier remplissage_ouvrier () ;
liste remplissage_liste (liste l , ouvrier a) ;
void creation_fichier(liste l) ;
void recherche_ouvrier (liste l) ;
float somme_salaire (liste l) ;