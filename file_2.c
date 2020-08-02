#include<stdio.h>
#include<stdlib.h>
#include "file_1.h"


/* initialisation de la liste chainee */
liste initialisation_liste ()
{
    return NULL ;             /* retourner NULL */
}



/* remplissage de la liste chainee */
liste remplissage_liste (liste l , ouvrier a)
{
    cellule *x ;                /* creation de nouveau cellule dans la liste */
    x = (cellule*)malloc(sizeof(cellule)) ;      /* alloue un espace de memoir pour la cellule*/
    x->donnee_ouvrier = a ;
    x->suivant = l ;                /* liee la cellule dans la liste */
    l = x ;
    printf("remplissage liste terminer \n") ;
    return l ;
}



/* remplissage les donnees de l'ouvrier */
ouvrier remplissage_ouvrier ()
{
    ouvrier a ;
    printf("tapper le nom : \n") ;           /*lire et ecrire la nom de l'ouvrier */
    scanf("%s",a.nom) ;
    printf("tapper le prenom : \n") ;              /*lire et ecrire le prenom de l'ouvrier */
    scanf("%s",a.prenom) ;
    printf("tapper l'age : \n") ;              /* lire et ecrire l'age de l'ouvrier */
    scanf("%i",&a.age) ;
    printf("tapper le salaire : \n") ;         /* lire et ecrire l'age de l'ouvrier */
    scanf("%f",&a.salaire) ;
    printf("tapper a reference de travail : \n") ;       /* lire et ecrire la reference de l'ouvrier */
    scanf("%d",&a.reference_de_travail) ;
    printf("tapper le sex : \n") ;                    /* lire et ecrire le sex de l'ouvrier */
    scanf("%s",a.sex) ;
    return a ;
}



/* recherche les donnees de l'ouvrier suivant votre reference */
void recherche_ouvrier (liste l)
{
    int ref ;
    liste p ;
    p = l ;
    printf("tapper votre reference : \n") ;            
    scanf("%d",&ref) ;
    if (p == NULL)
    {
        printf("aucun ouvrier enregistrer \n") ;
    }
    while (p != NULL)                             /* parcourir les cellules de la liste */
    {
        if (ref == p->donnee_ouvrier.reference_de_travail )       /* boucle if pour trouver l'ouvrier */
        {
            printf("LA REFERENCE : %d \n",p->donnee_ouvrier.reference_de_travail) ;
            printf("LE NOM : %s \n", p->donnee_ouvrier.nom) ;
            printf("LE PRENOM : %s \n", p->donnee_ouvrier.prenom) ;
            printf("L'AGE : %i \n", p->donnee_ouvrier.age) ;
            printf("LE SALAIRE : %f \n", p->donnee_ouvrier.salaire) ;
            printf("LE SEX : %s \n",p->donnee_ouvrier.sex) ;
        }
        else
        {
            printf("erreur de trouver votre ouvrier \n") ;
        }
         p = p->suivant ;                             /* passe a la cellule suivante */  
    }
    

}



/* creation de la fichier de donnee */
void creation_fichier(liste l)
{
    liste p ;
    p = l ;
    FILE *fp = NULL ;                                /* initialisation de fichier */
    fp = fopen("ouvrier.txt","wt") ;              /* ouverture de fichier */
    if (fp == NULL)                                                 /* boucle if pour eviter les erreurs */
    {
        printf("erreur d'ecriture de fichier \n") ;            
    }
    else
    {
        while (p != NULL)                      /* parcourir les cellules de la liste */
        {
            fprintf(fp,"LE NOM : %s \t",p->donnee_ouvrier.nom) ;                /* creation des donnees de l'ouvrier */
            fprintf(fp,"LE PRENOM: %s \t",p->donnee_ouvrier.prenom) ;
            fprintf(fp,"L'AGE : %d \t",p->donnee_ouvrier.age) ;
            fprintf(fp,"LE SALAIRE %f \t",p->donnee_ouvrier.salaire) ;
            fprintf(fp,"LE SEX : %s \n",p->donnee_ouvrier.sex) ;
            p = p->suivant ;
        }     
    }

    printf("creation de fichier terminer \n") ;
    fclose(fp) ;                                           /* fermeture de fichier */
}




/* calcule de la somme des salaire des ouvriers */
float somme_salaire (liste l)
{
    liste p ;
    p = l ;
    float somme = 0.0 ;
    while (p != NULL)              /* parcours de la liste */
    {
        somme = somme + p->donnee_ouvrier.salaire ;      /* operation de la somme des salaire */     
        p = p->suivant ;
    }
    return somme ;
}
