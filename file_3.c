#include<stdio.h>
#include<stdlib.h>
#include "file_1.h"

int main (void)
{
    liste l ;
    ouvrier a ;
    int nombre , i , choix , choix2 , choix3 ;
    float somme ;
    l = (liste)malloc(sizeof(liste)) ;
    l = initialisation_liste () ;
    printf("1) ajoute ouvrier \n") ;                         /* le menu */
    scanf("%i",&choix) ;
    if ( choix == 1)
    {
        printf("tapper le nombre des ouvrier pour l'enregistrement \n") ;
        scanf("%i",&nombre) ;
        for (i = 1 ; i <= nombre ; i++ )
        {
            a = remplissage_ouvrier () ;
            l = remplissage_liste (l , a) ;
            creation_fichier(l) ;
        }
            
            printf("1) recherche ouvrier \n") ;
            printf("2) calcule somme des salaires \n") ;
            scanf("%i",&choix2) ;
            switch (choix2)
            {
            case 1 :
                recherche_ouvrier (l) ; 
                printf("1) calcule somme des salaires \n")   ;
                scanf("%i",&choix3) ;
                if (choix3 == 1)
                {
                    somme = somme_salaire (l) ; 
                    printf("%f est la somme des salaires \n",somme) ;
                }
                break;

            case 2 :
                somme = somme_salaire (l) ;   
                printf("%f est la somme des salaire \n",somme) ; 
                break ;
            
            default:
            printf("erreur \n") ;
                break;
            }
    }

    
    else
    {
         printf("erreur \n") ;  
         exit ; 
    }
    return 0 ;
    
}