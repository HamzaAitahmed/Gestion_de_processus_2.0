#include <stdio.h>
#include <stdlib.h>

/*
    ----------------------------------------------  Les Objectifs qui reste ------------------------------------------------------

    • décrémenter tous les processus qui sont dans la memoire ( cpt )     ######################################## 10/10  ( easy )

    • ajouter une variable ( nbr ) de type int dans la structure node pour connaître le numéro du processus   #### 10/10  ( easy )

    • liberer un processus dans la memoire     ################################################################### 10/10  ( easy )

    • cpt_total     ############################################################################################## 10/10  ( moyen )

    • prendre un processus dans la file d'attente et l'ajouter dans la memoire     ############################### 07/10  ( Hard )

    • Probleme Dans La Fil D'attete cpt_total et nbr du processus                  ############################### 00/10  ( Hard )

*/

/*


        entrer La taille du P1 : 100
        entrer Le temps d'execu du P1 : 3
        entrer La Date D'arrivee du P1 : 2


        entrer La taille du P2 : 10
        entrer Le temps d'execu du P2 : 3
        entrer La Date D'arrivee du P2 : 0


        entrer La taille du P3 : 80
        entrer Le temps d'execu du P3 : 3
        entrer La Date D'arrivee du P3 : 1


        entrer La taille du P4 : 15
        entrer Le temps d'execu du P4 : 3
        entrer La Date D'arrivee du P4 : 0

*/

typedef struct node
{
    char type;
    int cpt ;
    int taille;
    int nbr;
    int dtv;
    struct node *next;
}node;

node *head = NULL , *fl = NULL , *lsd = NULL ; /// Des Variables Globales

enum ListType { FL, LH, LD } ;

node *add(char Type[])   /// cree un block
{
    node  *temp1, *n = (node*)malloc( sizeof(node) );

    n->type = 'F';
    n->next = NULL;

    if(fl == NULL)
    {
        fl = n;
        return n;
    }

    while(temp1->next != NULL)
    {
        temp1 = temp1->next ;
    }
    temp1->next = n;

    return n;
}

node *addhead() /// cree un block dans la memoire        pour un processus ( pour l'execution )
{
    node *n = (node*)malloc( sizeof(node) );
    n->next = NULL;
    n->type = 'O';

    return n;
}

node *addfl()   /// cree un block dans la file d'attend  pour un processus
{
    node  *temp1 = fl, *n = (node*)malloc( sizeof(node) );

    n->type = 'F';
    n->next = NULL;

    if(fl == NULL)
    {
        fl = n;
        return n;
    }

    while(temp1->next != NULL)
    {
        temp1 = temp1->next ;
    }
    temp1->next = n;

    return n;
}

node *addlsd()  /// cree un block dans la liste d'attend pour un processus
{
    node  *temp = lsd, *n = (node*)malloc( sizeof(node) );

    n->next = NULL;
    n->type = 'X';
    if(lsd == NULL)
    {
        lsd = n;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next ;
        }
        temp->next = n;
    }

    return n;
}

void afficherCompactage(char message[])
{
    node *temp1 ;
    printf("'//////////////////////////////////////////////////////////\n   '/////////////////////  Compactage %s  ////////////////////\n      '//////////////////////////////////////////////////////////\n",message);
    temp1 = head;
    printf(" --------------- \n");
    while(temp1 != NULL) /// décrémenter le temps d'execution des processus
    {
        if(temp1->type == 'O')
        {
            temp1->cpt--;
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t-> type : %c", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv , temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n");

            printf(" --------------- \n");
            if(temp1->cpt==0) // liberer un processus
            {
                //printf("|\t%d\t|\n",temp1->taille);
                //printf(" --------------- \n");
                temp1->type = 'L';
            }
            /*else
            {
                printf("|\tP%d\t|\n",temp1->nbr);
                printf(" --------------- \n");
            }*/
        }
        else
        {
            printf("|\t%d\t|    ->\ttype : %c",temp1->taille,temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n") ;
            printf(" --------------- \n");
        }
        temp1 = temp1->next ;
    } // nadiii 10/10
}

void afficherHead()
{
    node *temp1 ;

    temp1 = head;
    printf(" --------------- \n");
    while(temp1 != NULL) /// décrémenter le temps d'execution des processus
    {
        if(temp1->type == 'O')
        {
            temp1->cpt--;
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t-> type : %c", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv , temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n");

            printf(" --------------- \n");
            if(temp1->cpt==0) // liberer un processus
            {
                //printf("|\t%d\t|\n",temp1->taille);
                //printf(" --------------- \n");
                temp1->type = 'L';
            }
            /*else
            {
                printf("|\tP%d\t|\n",temp1->nbr);
                printf(" --------------- \n");
            }*/
        }
        else
        {
            printf("|\t%d\t|    ->\ttype : %c",temp1->taille,temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n") ;
            printf(" --------------- \n");
        }
        temp1 = temp1->next ;
    } // nadiii 10/10
}

void afficherFL()
{
    node *temp1 ;

    temp1 = fl;
    if(fl!=NULL)
    {
        printf("\n FILE D'ATTENTE : \n\n --------------- \n");
        while(temp1 != NULL) // décrémenter le temps d'execution des processus
        {
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t-> type : %c", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv , temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n");
            printf(" --------------- \n");
            temp1 = temp1->next ;
        }
        printf("\n\n");
    }
}

void afficherLSD()
{
    node *temp1 ;

    temp1 = lsd;
    if(lsd!=NULL)
    {
        printf("\n LISTE D'ARRIVEE : \n\n --------------- \n");
        while(temp1 != NULL) // décrémenter le temps d'execution des processus
        {
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t-> type : %c", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv , temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n");
            printf(" --------------- \n");
            temp1 = temp1->next ;
        }
        printf("\n\n");
    }
}

void compactage()  /// naaaaadi  10/10
{
    int taille=0;
    node *temp11 , *temp12 , *temp13 ;

    node *n = (node *)malloc(sizeof(node) ); // créer un block pour remplacer tous les zones libres dans un seul block qui est n

    n->next = NULL;
    n->type = 'L';

    afficherCompactage("Avant");

    temp11 = head;
    while(temp11!=NULL)   // pour calculer La taille des zones libres
    {
        if(temp11->type == 'L')
        {
            taille += temp11->taille;
        }
        temp11 = temp11->next ;
    }

    temp11 = head;
    temp12 = temp11;
    if(temp11->next != NULL)
    {
        while(temp11 != NULL) // pour éliminer les blocs des zones libres et les remplacer tous dans un seul block
        {

            if(temp11->type == 'L')
            {
                if(temp11 == temp12) // c'est pour verifier si Le 1 er block a une zone libre
                {
                    //taille += temp11->taille ;  est deja utulisee dans la boocle precedent
                    temp11 = temp11->next;
                    head = temp11;
                    free(temp12);
                    temp12 = temp11;
                }
                else
                {
                    //taille += temp11->taille ;   est deja utulisee dans la boocle precedent
                    temp12->next = temp11->next;
                    free(temp11);
                    temp11 = temp12->next;
                }
            }
            else
            {
                temp12 = temp11;
                temp11 = temp11->next;
            }
        }
        if(head==NULL)
        {
            head = n;
            n->taille = taille;
        }
        else
        {
            temp12->next = n;
            n->taille = taille; // après avoir supprimer les zones libres et compter leur taille
        }
    }
    afficherCompactage("Apres");

}

void afficher(int t) /// naaaaadi  10/10
{
    printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");

    printf("#####");
    printf("  A : %d  ",t);
    printf("#####\n");

            //////////////////////////////////////////////////////////
        ///////////////////////  La Memoire  /////////////////////
    //////////////////////////////////////////////////////////

    afficherHead();

            //////////////////////////////////////////////////////////
        /////////////////////  File D'attend  ////////////////////
    //////////////////////////////////////////////////////////

    afficherFL();

            //////////////////////////////////////////////////////////
        /////////////////////  Liste D'Arrivee  //////////////////
    //////////////////////////////////////////////////////////

    afficherLSD();

    printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");

}

void afficher2()
{
    node *temp22 = fl, *temp11 = head ;

    printf(" La Memoire :  \n");
    printf(" --------------- \n");
    while(temp11 != NULL)
    {
        if(temp11->type == 'O')
        {
            printf("|\tP%d\t|    ->\ttaille : %d\n", temp11->nbr , temp11->taille);
            printf(" --------------- \n");
        }
        else
        {
            printf("|\t%d\t|\n", temp11->taille);
            printf(" --------------- \n");

        }
        temp11 = temp11->next ;
    }
    printf("\n\n");

    if(fl!=NULL)
    {
        printf(" La File D'attente :  \n");
        printf(" --------------- \n");

        while(temp22 != NULL)
        {
            printf("|\tP%d\t|    ->\ttaille : %d\n", temp22->nbr , temp22->taille);
            printf(" --------------- \n");
            temp22 = temp22->next ;
        }
        printf("\n\n");
    }
    printf(" ############################################################################ \n");
    printf("\n");
}

int saisieLesProcessusDansLaListe(int nbrProcessus)
{
    int  ordre , taille_Processus , temps_exe_Pr , date_arr_Pr , taille_max , dtvmax;
    node  *temp;

    printf("\n\n");
    printf(" --------------- \n");
    printf("|\t%d\t|\n",head->taille);
    printf(" --------------- \n");
    printf("\n\n");

    /*
    for(ordre=1 , dtvmax=0 ; ordre<nbrProcessus+1 ; ordre++)
    {
        taille_max=head->taille;
        do
        {
            printf("\tentrer La taille du P%d : ",ordre);
            scanf("%d",&taille_Processus);
            if(taille_max < taille_Processus)
            {
                printf("\n\tERROR ( La Taille Du Processus Est Superieur A La Taille De La Memoire %d > %d) \n\n",taille_Processus,taille_max);
                continue;
            }

            printf("\tentrer Le temps d'execu du P%d : ",ordre);
            scanf("%d",&temps_exe_Pr);
            if(temps_exe_Pr <= 0)
            {
                printf("\n\tERROR ( Le temps d'execution est Inferieure ou Egale a 0 ( %d <= 0 ) \n\n",temps_exe_Pr);
                continue;
            }

            printf("\tentrer La Date D'arrivee du P%d : ",ordre);
            scanf("%d",&date_arr_Pr);
            if(date_arr_Pr < 0)
            {
                printf("\n\tERROR ( La Date D'arrivee est Inferieure a 0 ( %d < 0 ) \n\n",date_arr_Pr);
                continue;
            }

            if(dtvmax<=date_arr_Pr)
                dtvmax=date_arr_Pr;

            printf("\n\n");

        }while(taille_max < taille_Processus || temps_exe_Pr < 0 || date_arr_Pr < 0 );
        temp = addlsd();
        temp->taille = taille_Processus;
        temp->cpt    = temps_exe_Pr;
        temp->dtv    = date_arr_Pr;
        temp->nbr    = ordre;
    }
    return dtvmax;

    */
        temp = addlsd(); temp->taille = 100;    temp->cpt    = 3;   temp->dtv    = 2;   temp->nbr    = 1;
        temp = addlsd(); temp->taille = 180;    temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 2;
        temp = addlsd(); temp->taille = 10;     temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 3;
        temp = addlsd(); temp->taille = 80;     temp->cpt    = 5;   temp->dtv    = 1;   temp->nbr    = 4;
        temp = addlsd(); temp->taille = 15;     temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 5;
        temp = addlsd(); temp->taille = 15;     temp->cpt    = 3;   temp->dtv    = 3;   temp->nbr    = 6;
    return 2;

}


void FB_TO_MFB(node *Current_RL, node *Current_SL, enum ListType Sender_Liste) // First Block To First Block ( ajouter le processus dans le premier block de la memoire )
{
    if(Sender_Liste==LD)
    {
        lsd = Current_SL->next;
    }
    if(Sender_Liste==FL)
    {
        fl = Current_SL->next;
    }


    head = Current_SL;
    Current_SL->type = 'O';
    Current_RL->taille -= Current_SL->taille;
    if(Current_RL->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
    {
        Current_SL->next = Current_RL->next;
        free(Current_RL);
    }
    else
    {
        Current_SL->next = Current_RL;
    }


    Current_RL = Current_SL; // l'ordre est important

}

void MB_TO_MFB(node *Current_RL, node *Current_SL, node *Previous_SL) // Middle Block To First Block ( ajouter le processus dans le premier block de la memoire )
{

    Previous_SL->next = Current_SL->next;
    Current_SL->next = Current_RL;

    head = Current_SL;
    Current_SL->type = 'O';
    Current_RL->taille -= Current_SL->taille;

    if(Current_RL->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
    {
        Current_SL->next = Current_RL->next;
        free(Current_RL);
    }

    Current_RL = Current_SL; // l'ordre est important

}

void FB_TO_MMLB(node *Current_RL, node *Previous_RL, node *Current_SL, node *Previous_SL, enum ListType Sender_Liste) // First Block To Middle or Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
{

    if(Sender_Liste==LD)
    {
        lsd = Current_SL->next;
    }
    if(Sender_Liste==FL)
    {
        fl = Current_SL->next;
    }

    Previous_RL->next = Current_SL;
    Current_SL->next = Current_RL;


    Current_SL->type = 'O';
    Current_RL->taille -= Current_SL->taille;
    if(Current_RL->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
    {
        Current_SL->next = Current_RL->next;
        free(Current_RL);
    }

    Current_RL = Current_SL; // l'ordre est important

}

void MB_TO_MMLB(node *Current_RL, node *Previous_RL, node *Current_SL, node *Previous_SL) // Middle Block To Middle or Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
{
    Current_SL->type = 'O';
    Previous_RL->next = Current_SL;

    Previous_SL->next = Current_SL->next;
    Current_SL->next = Current_RL;

    Current_RL->taille -= Current_SL->taille;
    if(Current_RL->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
    {
        Current_SL->next = Current_RL->next;
        free(Current_RL);
    }

    Current_RL = Current_SL; // l'ordre est important

}


/*

    void FB_TO_MFB(node *Current_Head, node *Current_FL) // First Block To Memory First Block ( ajouter le processus dans le premier block de la memoire )
    {
        fl = Current_FL->next;
        head = Current_FL;
        Current_FL->type = 'O';
        Current_Head->taille -= Current_FL->taille;

        if(Current_Head->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
        {
            Current_FL->next = Current_Head->next;
            free(Current_Head);
        }
        else
        {
            Current_FL->next = Current_Head;
        }

        Current_Head = Current_FL; // l'ordre est important
        printf("\n############################################   La taille HEAD : %d\n",head->taille);

    }

    void MB_TO_MFB(node *Current_Head, node *Current_FL, node *Previous_FL) // First Block To Memory First Block ( ajouter le processus dans le premier block de la memoire )
    {
        Previous_FL->next = Current_FL->next;
        Current_FL->type = 'O';
        head = Current_FL;
        Current_Head->taille -= Current_FL->taille;

        if(Current_Head->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
        {
            Current_FL->next = Current_Head->next;
            free(Current_Head);
        }
        else
        {
            Current_FL->next = Current_Head;
        }

        Current_Head = Current_FL; // l'ordre est important
        printf("\n############################################   La taille HEAD : %d\n",head->taille);

    }

    void FB_TO_MMLB(node *Current_Head, node *Previous_Head, node *Current_FL, node *Previous_FL) // Memory Middle or Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
    {
        fl = Current_FL->next;
        Current_FL->type = 'O';
        Current_Head->taille -= Current_FL->taille;
        Previous_Head->next = Current_FL;

        if(Current_Head->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
        {
            Current_FL->next = Current_Head->next;
            free(Current_Head);
        }
        else
        {
            Current_FL->next = Current_Head;
        }

        Current_Head = Current_FL; // l'ordre est important
        printf("\n############################################   La taille HEAD : %d\n",head->taille);

    }

    void MB_TO_MMLB(node *Current_Head, node *Previous_Head, node *Current_FL, node *Previous_FL) // Memory Middle or Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
    {
        Previous_FL->next = Current_FL->next;
        Current_FL->type = 'O';
        Current_Head->taille -= Current_FL->taille;
        Previous_Head->next = Current_FL;

        if(Current_Head->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
        {
            Current_FL->next = Current_Head->next;
            free(Current_Head);
        }
        else
        {
            Current_FL->next = Current_Head;
        }

        Current_Head = Current_FL; // l'ordre est important
        printf("\n############################################   La taille HEAD : %d\n",head->taille);

    }

*/

node *pointingLastBlock(enum ListType type)
{
    node *temp ;

    if(type==LH)
        temp = head;
    if(type==LD)
        temp = lsd;
    if(type==FL)
        temp = fl;

    while(temp->next != NULL) // pointer sur le derniere block ( parce que il est libre )
        temp = temp->next;

    return temp;
}

/*
	Si on ( + ) on a 3 etapes
	1 - ajouter le proecssus dans la memoire directement s'il y a un bloc libre est sa taille et superieur a la taille du processus sinon on passe a la 2eme etape
	2 - si la taille du processus est superieure a la taille totale des blocs libres on fait le compactage sinon on passe a la 3eme etape
	3 - ajouter le processus dans la fil d'attente

	Si on ( - ) on 3 etapes
	1 - trouver le processus qu'on va liberer
	2 - trouver le processus qui a la petite taille SJF ( Short Job First ) dans FL ( la fil d'attente)
	3 - ajouter ce processus dans head ( la memoire ) s'il ya un bloc libre qui la taille sup ou egale a la taille du processus sinon
	4 - compactage si on peut ajouter le proecssus dans head ( la memoire )
	5 - afficher()

	On passe au processus suivant qui est dans le fichier tailleoriginal.txt

*/

void firstfit(int x)
{
    int  t, jhead, jfl, taille_total, cpt_total, dtvmax;
    node *temp7, *temp6, *temp5, *temp4, *temp3, *temp2, *temp1, *Current_Head, *Previous_Head, *Current_FL, *Previous_FL, *Current_LSD, *Previous_LSD;


    dtvmax = x;
    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        Current_LSD   = lsd;
        Previous_LSD  = Current_LSD;

        Current_FL    = fl;
        Previous_FL   = Current_FL;

        while(Current_LSD!=NULL) // pour saisir toutes les Processus dans La Memoire a condition ( si t==dtv et s'il y a des block libres ) sinon dans La FL
        {
            if(t==Current_LSD->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {

                Current_Head = head;
                Previous_Head = Current_Head;

                taille_total = 0;
                jhead=0;
                if(fl==NULL)
                {
                    while(Current_Head!=NULL && jhead==0) //  chercher une place dans La memoir libre
                    {
                        if(head->next == NULL) // ça signifie qu'il y a un seul block dans la memoire
                        {
                            if(head->type == 'L')
                            {
                                if(Current_LSD->taille <= head->taille)
                                {
                                    if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = Current_LSD->cpt+1;
                                    }
                                    if(Current_LSD->taille == head->taille)
                                    {
                                        head->cpt = Current_LSD->cpt;
                                        head->dtv = Current_LSD->dtv;
                                        head->type = 'O';
                                        head->nbr = Current_LSD->nbr;
                                    }
                                    else
                                    {
                                        temp2 = addhead(); // temp2 = n    &    n->next = NULL    &    n->type = 'O'
                                        temp2->cpt = Current_LSD->cpt;
                                        temp2->dtv = Current_LSD->dtv;
                                        temp2->nbr = Current_LSD->nbr;
                                        temp2->taille = Current_LSD->taille;
                                        head->taille -= Current_LSD->taille;
                                        temp2->next = head;
                                        head = temp2;
                                    }
                                    if(Current_LSD==Previous_LSD)
                                    {
                                        lsd = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=lsd;
                                        Previous_LSD=Current_LSD;
                                    }
                                    else
                                    {
                                        Previous_LSD->next = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=Previous_LSD->next;
                                    }

                                    jhead=1; // si le processus a trouve une place dans la memoire
                                }
                            }
                        }
                        else // Current_Head et Previous_Head pour remplacez le block dans la list & temp2 pour creer le block
                        {
                            if(Current_Head->type == 'L')  // si Le block a trouvee une place dans La memoir
                            {
                                taille_total += Current_Head->taille;

                                if(Current_LSD->taille <= Current_Head->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = Current_LSD->cpt+1;
                                    }
                                    if(Current_Head == Previous_Head) // si le 1 er block est vide
                                    {
                                        if(Current_Head->taille == Current_LSD->taille)
                                        {
                                            Current_Head->type = 'O';
                                            Current_Head->cpt = Current_LSD->cpt;
                                            Current_Head->dtv = Current_LSD->dtv;
                                            Current_Head->nbr = Current_LSD->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = Current_LSD->cpt;
                                            temp2->dtv = Current_LSD->dtv;
                                            temp2->nbr = Current_LSD->nbr;
                                            temp2->taille = Current_LSD->taille;
                                            Current_Head->taille -= Current_LSD->taille;
                                            temp2->next = Current_Head;
                                            head = temp2;
                                        }
                                    }
                                    else
                                    {
                                        if(Current_Head->taille == Current_LSD->taille )
                                        {
                                            Current_Head->type = 'O';
                                            Current_Head->cpt = Current_LSD->cpt;
                                            Current_Head->dtv = Current_LSD->dtv;
                                            Current_Head->nbr = Current_LSD->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = Current_LSD->cpt;
                                            temp2->dtv = Current_LSD->dtv;
                                            temp2->nbr = Current_LSD->nbr;
                                            temp2->taille = Current_LSD->taille;
                                            Current_Head->taille -= Current_LSD->taille;
                                            temp2->next = Current_Head;
                                            Previous_Head->next = temp2;
                                        }
                                    }
                                    if(Current_LSD==Previous_LSD)
                                    {
                                        lsd = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=lsd;
                                        Previous_LSD=Current_LSD;
                                    }
                                    else
                                    {
                                        Previous_LSD->next = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=Previous_LSD->next;
                                    }

                                    jhead=1;
                                }
                            }
                        }
                        Previous_Head = Current_Head;
                        Current_Head = Current_Head->next;
                    }

                    if(jhead==0 && Current_LSD->taille <= taille_total) // si La taille du processus est inferieur a La taille total des blocks libres
                    {
                        compactage();

                        Current_Head = head;
                        Previous_Head = Current_Head;
                        // pointer sur le derniere block ( parce qu'il est libre a cause du compactage ) et Verifier s'il y a un seul block dans la memoire apres le compactage ()
                        while(Current_Head->next != NULL)
                        {
                            Previous_Head=Current_Head;
                            Current_Head = Current_Head->next;
                        }
                        if(Current_LSD==Previous_LSD)
                        {
                            if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                            {
                                FB_TO_MFB(Current_Head, Current_LSD, LD);
                            }
                            else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                            {
                                FB_TO_MMLB(Current_Head, Previous_Head, Current_LSD, Previous_LSD, LD);
                            }
                            jhead=1;
                            Current_LSD = lsd;
                            Previous_LSD = Current_LSD;
                        }
                        else
                        {
                            if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                            {
                                MB_TO_MFB(Current_Head, Current_LSD, Previous_LSD);
                            }
                            else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                            {
                                MB_TO_MMLB(Current_Head, Previous_Head, Current_LSD, Previous_LSD);
                            }
                            jhead=1;
                            Current_LSD = Previous_LSD->next;
                        }

                        /*
                        while(Current_Head!=NULL) //  chercher une place dans La memoir libre
                        {

                            if(Current_Head->type == 'L')  // si Le block a trouvee une place dans La memoir
                            {

                                if(Current_LSD->taille <= Current_Head->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = Current_LSD->cpt+1;
                                    }
                                    if(Current_LSD->taille == Current_Head->taille)
                                    {
                                        Current_Head->type = 'O';
                                        Current_Head->cpt = Current_LSD->cpt;
                                        Current_Head->dtv = Current_LSD->dtv;
                                        Current_Head->nbr = Current_LSD->nbr;
                                    }
                                    else
                                    {
                                        if(Current_Head==Previous_Head)
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = Current_LSD->cpt;
                                            temp2->dtv = Current_LSD->dtv;;
                                            temp2->nbr = Current_LSD->nbr;
                                            temp2->taille = Current_LSD->taille;
                                            Current_Head->taille -= Current_LSD->taille;
                                            temp2->next = Current_Head;
                                            head = temp2;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = Current_LSD->cpt;
                                            temp2->dtv = Current_LSD->dtv;;
                                            temp2->nbr = Current_LSD->nbr;
                                            temp2->taille = Current_LSD->taille;
                                            Current_Head->taille -= Current_LSD->taille;
                                            temp2->next = Current_Head;
                                            Previous_Head->next = temp2;
                                        }
                                    }
                                    if(Current_LSD==Previous_LSD)
                                    {
                                        lsd = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=lsd;
                                        Previous_LSD=Current_LSD;
                                    }
                                    else
                                    {
                                        Previous_LSD->next = Current_LSD->next;
                                        free(Current_LSD);
                                        Current_LSD=Previous_LSD->next;
                                    }
                                    jhead=1;
                                }


                            }
                            Previous_Head = Current_Head;
                            Current_Head = Current_Head->next;
                        }
                        */
                    }
                }

                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    temp2 = addfl();
                    temp2->cpt = Current_LSD->cpt;
                    temp2->nbr = Current_LSD->nbr;
                    temp2->dtv =  Current_LSD->dtv;
                    temp2->taille = Current_LSD->taille;

                    if(Current_LSD==Previous_LSD) //printf("La Ligne -> 397 \n");
                    {
                        lsd = Current_LSD->next;
                        free(Current_LSD);
                        Current_LSD=lsd;
                        Previous_LSD=Current_LSD;
                    }
                    else
                    {
                        Previous_LSD->next = Current_LSD->next;
                        free(Current_LSD);
                        Current_LSD=Previous_LSD->next;
                    }


                    jhead=1;
                }
            }
            else
            {
                Previous_LSD = Current_LSD;
                Current_LSD = Current_LSD->next;
            }

        }



        //printf("La Ligne 423 \n");

        /*

                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################

         */

        /*
                #########################################################################################################################

            #########################################################  ?????????  ###################################################

        #########################################################################################################################

        */
        Current_FL  = fl;
        Previous_FL = Current_FL;

        while(Current_FL!=NULL)
        {
            Current_Head=head;
            Previous_Head=Current_Head;

            jfl=0;
            taille_total = 0;
            while(Current_Head!=NULL && jfl==0)
            {
                if(Current_Head->type == 'L')
                {
                    taille_total += Current_Head->taille;
                    // Calculer la taille totale de tous les blocs libres lorsque nous recherchons la taille du processus
                    // si nous n'avons pas trouvé la taille du processus qu'on cherche on passe au compactage et on verifier s'il est possible ( taille_total <= Current_FL->taille )

                    if(Current_FL->taille <= Current_Head->taille)
                    {
                        if(cpt_total <= Current_FL->cpt)  // pour augmenter Le temps d'execution total
                        {
                            cpt_total = Current_FL->cpt + 1;
                        }
                        if(Current_FL==Previous_FL)  //  si le block est le 1er block dans la liste FL  ( file d'attend )
                        {
                            if(Current_Head == Previous_Head)  // si le zone libre est le 1er block dans la liste head  ( la memoire )
                            {
                                FB_TO_MFB(Current_Head, Current_FL, FL);
                            }
                            else  // si le zone libre est au milieu dans la liste head  ( la memoire )
                            {
                                FB_TO_MMLB(Current_Head, Previous_Head, Current_FL, Previous_FL, FL);
                            }
                            Current_FL = fl;
                            Previous_FL = Current_FL;
                        }
                        else  // si le processus est au milieu de la FL
                        {
                            if(Current_Head == Previous_Head) // si le zone libre est le 1er block dans la liste head  ( la memoire )
                            {
                                MB_TO_MFB(Current_Head,Current_FL,Previous_FL);
                            }
                            else // si le zone libre est au milieu dans la liste head  ( la memoire )
                            {
                                MB_TO_MMLB(Current_Head,Previous_Head,Current_FL,Previous_FL);
                            }

                            Current_FL = Previous_FL->next;
                        }
                        jfl=1;
                    }
                }
                if(jfl==0)
                {
                    Previous_Head=Current_Head;
                    Current_Head=Current_Head->next;
                }
            }

            if(jfl==0)
            {
                if(Current_FL->taille <= taille_total)
                {
                    if(cpt_total <= Current_FL->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_FL->cpt + 1;
                    }

                    compactage();

                    Current_Head = head;
                    Previous_Head=Current_Head;

                    // pointer sur le derniere block ( parce qu'il est libre a cause du compactage ) et Verifier s'il y a un seul block dans la memoire apres le compactage ()
                    while(Current_Head->next != NULL)
                    {
                        Previous_Head=Current_Head;
                        Current_Head = Current_Head->next;
                    }

                    if(Current_FL==Previous_FL)
                    {
                        if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                        {
                            FB_TO_MFB(Current_Head, Current_FL, FL);
                        }
                        else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                        {
                            FB_TO_MMLB(Current_Head, Previous_Head, Current_FL, Previous_FL, FL);
                        }
                        jfl=1;
                        Current_FL = fl;
                        Previous_FL = Current_FL;
                    }
                    else
                    {
                        if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                        {
                            MB_TO_MFB(Current_Head,Current_FL,Previous_FL);
                        }
                        else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                        {
                            MB_TO_MMLB(Current_Head,Previous_Head,Current_FL,Previous_FL);
                        }
                        jfl=1;
                        Current_FL = Previous_FL->next;
                    }
                }
            }
            if(jfl==0)
            {
                Previous_FL = Current_FL;
                Current_FL = Current_FL->next;
            }

        }

        /*
                #########################################################################################################################

            #########################################################  ?????????  ###################################################

        #########################################################################################################################

        */

        /*



        temp1 = head;
        temp4 = temp1;
        while(temp1 != NULL) // prendre un processus dans la file d'attente et l'ajouter dans la memoire sans campactage  """"""""""""""""""""""""""""""""""""""""""""""""""""""""
        {
            if(temp1->type == 'L')
            {
                temp2 = fl;
                temp3 = temp2;
                jfl=0;
                while(temp2 != NULL && jfl==0 )
                {
                    if(temp2->taille <= temp1->taille)
                    {
                        if(cpt_total <= temp2->cpt) // pour augmenter Le temps d'execution total
                        {
                            cpt_total = temp2->cpt + 1 ;
                        }
                        if(temp2 == temp3)   // si le processus est le 1er block de FL
                        {
                            if(temp2->taille == temp1->taille)  // si la taille du processus est la meme taille de la zone libre dans la liste head ( la memoire )
                            {
                                fl = temp2->next;
                                temp1->type = 'O';
                                temp1->cpt = temp2->cpt;
                                temp1->nbr = temp2->nbr;
                                free(temp2);
                                jfl=1;

                            }
                            else
                            {
                                if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                {
                                    fl = temp2->next;
                                    temp2->type = 'O';
                                    temp2->next = temp1;
                                    temp1->taille -= temp2->taille;
                                    temp1 = temp2;
                                    head = temp2;
                                    jfl=1;

                                }
                                else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                {
                                    fl = temp2->next;
                                    temp2->type = 'O';
                                    temp2->next = temp1;
                                    temp1->taille -= temp2->taille;
                                    temp4->next = temp2;
                                    temp1 = temp2;
                                    jfl=1;

                                }

                            }
                        }
                        else  // si le processus est au milieu de la FL
                        {
                            if(temp2->taille == temp1->taille)   // si la taille du processus est la meme taille de la zone libre dans la liste head ( la memoire )
                            {
                                temp3->next = temp2->next;
                                temp1->type = 'O';
                                temp1->cpt = temp2->cpt;
                                temp1->nbr = temp2->nbr;
                                free(temp2);
                                jfl=1;


                            }
                            else
                            {
                                if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                {
                                    temp3->next = temp2->next;
                                    temp2->type = 'O';
                                    temp2->next = temp1;
                                    temp1->taille -= temp2->taille;
                                    temp1 = temp2;
                                    head = temp2;
                                    jfl=1;

                                }
                                else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                {
                                    temp3->next = temp2->next;
                                    temp2->type = 'O';
                                    temp2->next = temp1;
                                    temp1->taille -= temp2->taille;
                                    temp4->next = temp2;
                                    temp1 = temp2;
                                    jfl=1;

                                }

                            }

                        }
                    }

                    if(jfl == 0)
                    {
                        temp3 = temp2;
                        temp2 = temp2->next ;
                    }
                }
            }
            temp4 = temp1;
            temp1 = temp1->next ;
        }

        temp2 = head;
        taille_total = 0;
        while(temp2!=NULL)
        {
            if(temp2->type == 'L')
            {
                taille_total += temp2->taille;
            }
            temp2 = temp2->next;
        }

        temp3 = fl;
        temp4 = temp3;
        jfl=0;
        while(temp3!=NULL && jfl==0 )
        {
            if(temp3->taille <= taille_total)
            {
                if(cpt_total <= temp3->cpt) // pour augmenter Le temps d'execution total
                {
                    cpt_total = temp3->cpt + 1;
                }
                compactage();
                temp1=head;
                temp2=temp1;
                while(temp1->next != NULL)
                {
                    temp2=temp1;
                    temp1 = temp1->next;
                }
                if(temp3==temp4)
                {
                    if(temp3->taille == taille_total)
                    {
                        temp4->next = temp3->next;
                        temp1->type = 'O';
                        temp1->cpt = temp3->cpt;
                        temp1->nbr = temp3->nbr;
                        free(temp3);
                        jfl=1;

                    }
                    else
                    {
                        fl = temp3->next;
                        temp3->type = 'O';
                        temp3->next = temp1;
                        temp1->taille -= temp3->taille;
                        taille_total -= temp3->taille;
                        temp2->next = temp3;
                        jfl=1;

                    }
                }
                else
                {
                    if(temp3->taille == taille_total)
                    {
                        temp4->next = temp3->next;
                        temp1->type = 'O';
                        temp1->cpt = temp3->cpt;
                        temp1->nbr = temp3->nbr;
                        free(temp3);
                        jfl=1;

                    }
                    else
                    {
                        temp4->next = temp3->next;
                        temp3->type = 'O';
                        temp3->next = temp1;
                        temp1->taille -= temp3->taille;
                        taille_total -= temp3->taille;
                        temp2->next = temp3;
                        temp3 = temp4->next;
                        jfl=1;

                    }
                }
            }
            else
            {
                temp4 = temp3 ;
                temp3= temp3->next;
            }
        }
        */


        /*
                #########################################################################################################################

            #########################################################  Affichage  ###################################################

        #########################################################################################################################

        */

        afficher(t);
    }
}


void BestFit(int x)
{
    int  i , t , pos , jpos  , max , jhead , jfl , taille2 , taille_total , cpt2 , dtv2 , cpt_total , taille_max , dtvmax;
    node *temp7 , *temp6 , *temp5 , *temp4 , *temp3 , *temp2 , *temp1;

    dtvmax = x ;
    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        temp5=lsd;
        temp6=temp5;
        while(temp5!=NULL) // pour sasir toutes les P dans La Memoire ou La FL a condition si t==dtv
        {
            if(t==temp5->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                jhead=0 ;
                temp1 = head ;
                temp3 = head ;
                taille_total = 0 ;


                temp7 = head ;
                for(i=1 , pos=0 , jpos=0 , max=0 ; temp7!=NULL && jpos==0  ; i++)
                {
                    if(temp7->type=='L')
                    {
                        if(temp5->taille <= temp7->taille)
                        {
                            if(pos==0)
                            {
                                max = temp7->taille;
                                pos=i;
                            }
                            if(temp5->taille == temp7->taille)
                            {
                                pos = i;
                                jpos=1;
                            }
                            else
                            {
                                if(max > temp7->taille)
                                {
                                    pos = i;
                                    max = temp7->taille ;
                                }
                            }
                        }
                    }
                    temp7 = temp7->next;
                }
                if(fl==NULL)
                {
                    //printf("La Ligne 202 \n");
                    //while(temp1!=NULL && jhead==0) //  chercher une place dans La memoir libre
                    for(i=1 ; temp1!=NULL && jhead==0 ; i++)
                    {
                        if(temp1->type == 'L')  // si Le block a trouvee une place dans La memoir
                        {
                            taille_total += temp1->taille;
                            if(i==pos)
                            {
                                if(temp5->taille <= temp1->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= temp5->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = temp5->cpt+1;
                                    }
                                    if(temp1 == temp3) // si le 1 er block est vide
                                    {
                                        if(temp1->taille == temp5->taille)
                                        {
                                            temp1->type = 'O';
                                            temp1->cpt = temp5->cpt;
                                            temp1->dtv = temp5->dtv;
                                            temp1->nbr = temp5->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            head = temp2;
                                        }
                                    }
                                    else
                                    {
                                        if(temp1->taille == temp5->taille )
                                        {
                                            temp1->type = 'O';
                                            temp1->cpt = temp5->cpt;
                                            temp1->dtv = temp5->dtv;
                                            temp1->nbr = temp5->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            temp3->next = temp2;
                                        }
                                    }
                                    if(temp5==temp6)
                                    {
                                        lsd = temp5->next;
                                        free(temp5);
                                        temp5=lsd;
                                        temp6=temp5;
                                    }
                                    else
                                    {
                                        temp6->next = temp5->next;
                                        free(temp5);
                                        temp5=temp6->next;
                                    }

                                    jhead=1;
                                }
                            }
                        }
                        temp3 = temp1;
                        temp1 = temp1->next;
                    }
                    if(jhead==0 && temp5->taille <= taille_total) // si La taille du processus est inferieur a La taille total des blocks libres
                    {
                        compactage();
                        temp1 = head;
                        temp3 = head;
                        while(temp1!=NULL) //  chercher une place dans La memoir libre
                        {
                            if(temp1->type == 'L')  // si Le block a trouvee une place dans La memoir
                            {
                                if(temp5->taille <= temp1->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= temp5->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = temp5->cpt+1;
                                    }
                                    if(temp5->taille == temp1->taille)
                                    {
                                        temp1->type = 'O';
                                        temp1->cpt = temp5->cpt;
                                        temp1->dtv = temp5->dtv;
                                        temp1->nbr = temp5->nbr;
                                    }
                                    else
                                    {
                                        if(temp1==temp3)
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            head = temp2;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            temp3->next = temp2;
                                        }
                                    }
                                    if(temp5==temp6)
                                    {
                                        lsd = temp5->next;
                                        free(temp5);
                                        temp5=lsd;
                                        temp6=temp5;
                                    }
                                    else
                                    {
                                        temp6->next = temp5->next;
                                        free(temp5);
                                        temp5=temp6->next;
                                    }
                                    jhead=1;
                                }
                            }
                            temp3 = temp1;
                            temp1 = temp1->next;
                        }
                    }
                }
                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    temp2 = addfl();
                    temp2->cpt = temp5->cpt;
                    temp2->nbr = temp5->nbr;
                    temp2->dtv =  temp5->dtv;
                    temp2->taille = temp5->taille;
                    if(temp5==temp6)
                    {
                        lsd = temp5->next;
                        free(temp5);
                        temp5=lsd;
                        temp6=temp5;
                    }
                    else
                    {
                        temp6->next = temp5->next;
                        free(temp5);
                        temp5=temp6->next;
                    }
                    jhead=1;
                }
            }
            else
            {
                temp6 = temp5;
                temp5 = temp5->next;
            }
        }

        /*
                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################                                  */
        temp2=fl;
        temp3=temp2;
        while(temp2!=NULL)
        {
            temp1=head;
            temp4=temp1;
            jfl=0;
            taille_total = 0;

            temp7 = head ;
            for(i=1 , pos=0 , jpos=0 , max=0 ; temp7!=NULL && jpos==0  ; i++)
            {
                if(temp7->type=='L')
                {
                    taille_total += temp7->taille;
                    if(temp1->taille <= temp7->taille)
                    {
                        if(pos==0)
                        {
                            max = temp7->taille;
                            pos=i;
                        }
                        if(temp1->taille == temp7->taille)
                        {
                            pos = i;
                            jpos=1;
                        }
                        else
                        {
                            if(max > temp7->taille)
                            {
                                pos = i;
                                max = temp7->taille ;
                            }
                        }
                    }
                }
                temp7 = temp7->next;
            }

            //while(temp1!=NULL && jfl==0)
            for( i=1 ; temp1!=NULL && jfl==0 ; i++ )
            {
                if(temp1->type == 'L')
                {
                    if(pos==i)
                    {
                        if(temp2->taille <= temp1->taille)
                        {
                            if(cpt_total <= temp2->cpt) // pour augmenter Le temps d'execution total
                            {
                                cpt_total = temp2->cpt + 1;
                            }
                            if(temp2==temp3)
                            {
                                if(temp2->taille == temp1->taille)
                                {
                                    fl = temp2->next;
                                    temp1->type = 'O';
                                    temp1->cpt = temp2->cpt; //## ## ## ## ## ## ## ##
                                    temp1->dtv = temp1->dtv;
                                    temp1->nbr = temp2->nbr;
                                    free(temp2);
                                }
                                else
                                {
                                    if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                    {
                                        fl = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp1 = temp2;
                                        head = temp2;
                                    }
                                    else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                    {
                                        fl = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp4->next = temp2;
                                        temp1 = temp2;
                                    }
                                }
                                temp2 = fl;
                                temp3 = temp2;
                            }
                            else  // si le processus est au milieu de la FL
                            {
                                if(temp2->taille == temp1->taille)   // si la taille du processus est la meme taille de la zone libre dans la liste head ( la memoire )
                                {
                                    temp3->next = temp2->next;
                                    temp1->type = 'O';
                                    temp1->cpt = temp2->cpt;
                                    temp1->nbr = temp2->nbr;
                                    free(temp2);
                                }
                                else
                                {
                                    if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                    {
                                        temp3->next = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp1 = temp2;
                                        head = temp2;
                                    }
                                    else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                    {
                                        temp3->next = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp4->next = temp2;
                                        temp1 = temp2;
                                    }
                                }
                                temp2 = temp3->next;
                            }
                            jfl=1;
                        }
                    }
                }
                if(jfl==0)
                {
                    temp4=temp1;
                    temp1=temp1->next;
                }
            }
            if(jfl==0)
            {
                if(temp2->taille <= taille_total)
                {
                    if(cpt_total <= temp2->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = temp2->cpt + 1;
                    }
                    compactage();
                    temp1=head;
                    temp4=temp1;
                    while(temp1->next != NULL)
                    {
                        temp4=temp1;
                        temp1 = temp1->next;
                    }
                    if(temp2==temp3)
                    {
                        if(temp2->taille == taille_total)
                        {
                            fl = temp2->next;
                            temp1->type = 'O';
                            temp1->cpt = temp2->cpt;
                            temp1->nbr = temp2->nbr;
                            free(temp2);
                            jfl=1;
                        }
                        else
                        {
                            if(temp1==temp4)
                            {
                                fl = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                head = temp2;
                                jfl=1;
                            }
                            else
                            {
                                fl = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                                jfl=1;
                            }
                        }
                        temp2 = fl;
                        temp3 = temp2;
                    }
                    else
                    {
                        if(temp2->taille == taille_total)
                        {
                            temp3->next = temp2->next;
                            temp1->type = 'O';
                            temp1->cpt = temp2->cpt;
                            temp1->nbr = temp2->nbr;
                            free(temp2);
                            jfl=1;
                        }
                        else
                        {
                            if(temp1==temp4)
                            {
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                head = temp2;
                                jfl=1;
                            }
                            else
                            {
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                                jfl=1;
                            }
                        }
                        temp2 = temp3->next;
                    }
                }
            }
            if(jfl==0)
            {
                temp3=temp2;
                temp2=temp2->next;
            }
        }

        // afficher(t);

        temp1 = head;
        printf("#####");
        printf("  A : %d  ",t);
        printf("#####\n");
        printf(" --------------- \n");
        while(temp1 != NULL) // décrémenter le temps d'execution des processus
        {
            if(temp1->type == 'O')
            {
                temp1->cpt--;
                printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\n", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv);
                printf(" --------------- \n");
                if(temp1->cpt==0) // liberer un processus
                {
                    temp1->type = 'L';
                }
            }
            else
            {
                printf("|\t%d\t|\n",temp1->taille);
                printf(" --------------- \n");
            }
            temp1 = temp1->next ;
        } // nadiii 10/10
        printf("\n\n");

    }
}


void WorstFit(int x)
{
    int  i , t , pos , jpos  , max , jhead , jfl , taille2 , taille_total , cpt2 , dtv2 , cpt_total , taille_max , dtvmax;
    node *temp7 , *temp6 , *temp5 , *temp4 , *temp3 , *temp2 , *temp1;

    dtvmax = x;
    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        temp5=lsd;
        temp6=temp5;
        while(temp5!=NULL) // pour sasir toutes les P dans La Memoire ou La FL a condition si t==dtv
        {
            if(t==temp5->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                jhead=0 ;
                temp1 = head ;
                temp3 = head ;
                taille_total = 0 ;


                temp7 = head ;
                for(i=1 , pos=0 , jpos=0 , max=0 ; temp7!=NULL && jpos==0  ; i++)
                {
                    if(temp7->type=='L')
                    {
                        if(temp5->taille <= temp7->taille)
                        {
                            if(max < temp7->taille)
                            {
                                pos = i;
                                max = temp7->taille ;
                            }
                        }
                    }
                    temp7 = temp7->next;
                }
                if(fl==NULL)
                {
                    //printf("La Ligne 226 \n");
                    //while(temp1!=NULL && jhead==0) //  chercher une place dans La memoir libre
                    for(i=1 ; temp1!=NULL && jhead==0 ; i++)
                    {
                        if(temp1->type == 'L')  // si Le block a trouvee une place dans La memoir
                        {
                            taille_total += temp1->taille;
                            if(i==pos)
                            {
                                if(temp5->taille <= temp1->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= temp5->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = temp5->cpt+1;
                                    }
                                    if(temp1 == temp3) // si le 1 er block est vide
                                    {
                                        //printf("La Ligne    '->  243 \n");
                                        if(temp1->taille == temp5->taille)
                                        {
                                            temp1->type = 'O';
                                            temp1->cpt = temp5->cpt;
                                            temp1->dtv = temp5->dtv;
                                            temp1->nbr = temp5->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            head = temp2;
                                        }
                                    }
                                    else
                                    {
                                        //printf("La Ligne    '->  266 \n");
                                        if(temp1->taille == temp5->taille )
                                        {
                                            temp1->type = 'O';
                                            temp1->cpt = temp5->cpt;
                                            temp1->dtv = temp5->dtv;
                                            temp1->nbr = temp5->nbr;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            temp3->next = temp2;
                                        }
                                    }
                                    if(temp5==temp6)
                                    {
                                        lsd = temp5->next;
                                        free(temp5);
                                        temp5=lsd;
                                        temp6=temp5;
                                    }
                                    else
                                    {
                                        temp6->next = temp5->next;
                                        free(temp5);
                                        temp5=temp6->next;
                                    }

                                    jhead=1;
                                }
                            }
                        }
                        temp3 = temp1;
                        temp1 = temp1->next;
                    }
                    if(jhead==0 && temp5->taille <= taille_total) // si La taille du processus est inferieur a La taille total des blocks libres
                    {
                        compactage();
                        temp1 = head;
                        temp3 = head;
                        //printf("La Ligne  311 \n");
                        while(temp1!=NULL) //  chercher une place dans La memoir libre
                        {
                            if(temp1->type == 'L')  // si Le block a trouvee une place dans La memoir
                            {
                                if(temp5->taille <= temp1->taille) // si La taille du processuss est inferieur a La La taille du block
                                {
                                    if(cpt_total <= temp5->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = temp5->cpt+1;
                                    }
                                    if(temp5->taille == temp1->taille)
                                    {
                                        //printf("La Ligne    '->  324 \n");
                                        temp1->type = 'O';
                                        temp1->cpt = temp5->cpt;
                                        temp1->dtv = temp5->dtv;
                                        temp1->nbr = temp5->nbr;
                                    }
                                    else
                                    {
                                        //printf("La Ligne    '->  331 \n");
                                        if(temp1==temp3)
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            head = temp2;
                                        }
                                        else
                                        {
                                            temp2 = addhead();
                                            temp2->cpt = temp5->cpt;
                                            temp2->dtv = temp5->dtv;;
                                            temp2->nbr = temp5->nbr;
                                            temp2->taille = temp5->taille;
                                            temp1->taille -= temp5->taille;
                                            temp2->next = temp1;
                                            temp3->next = temp2;
                                        }
                                    }
                                    if(temp5==temp6)
                                    {
                                        lsd = temp5->next;
                                        free(temp5);
                                        temp5=lsd;
                                        temp6=temp5;
                                    }
                                    else
                                    {
                                        temp6->next = temp5->next;
                                        free(temp5);
                                        temp5=temp6->next;
                                    }
                                    jhead=1;
                                }
                            }
                            temp3 = temp1;
                            temp1 = temp1->next;
                        }
                    }
                }
                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    //printf("La Ligne  379 \n");
                    temp2 = addfl();
                    temp2->cpt = temp5->cpt;
                    temp2->nbr = temp5->nbr;
                    temp2->dtv =  temp5->dtv;
                    temp2->taille = temp5->taille;
                    if(temp5==temp6)
                    {
                        lsd = temp5->next;
                        free(temp5);
                        temp5=lsd;
                        temp6=temp5;
                    }
                    else
                    {
                        temp6->next = temp5->next;
                        free(temp5);
                        temp5=temp6->next;
                    }
                    jhead=1;
                }
            }
            else
            {
                temp6 = temp5;
                temp5 = temp5->next;
            }
        }

        /*
                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################                                  */
        temp2=fl;
        temp3=temp2;
        while(temp2!=NULL)
        {
            temp1=head;
            temp4=temp1;
            jfl=0;
            taille_total = 0;

            temp7 = head ;
            for(i=1 , pos=0 , jpos=0 , max=0 ; temp7!=NULL && jpos==0  ; i++)
            {
                if(temp7->type=='L')
                {
                    taille_total += temp7->taille;
                    if(temp1->taille <= temp7->taille)
                    {
                        if(max < temp7->taille)
                        {
                            pos = i;
                            max = temp7->taille ;
                        }
                    }
                }
                temp7 = temp7->next;
            }

            //while(temp1!=NULL && jfl==0)
            for( i=1 ; temp1!=NULL && jfl==0 ; i++ )
            {
                if(temp1->type == 'L')
                {
                    if(pos==i)
                    {
                        if(temp2->taille <= temp1->taille)
                        {
                            //printf("La Ligne  450 \n");
                            if(cpt_total <= temp2->cpt) // pour augmenter Le temps d'execution total
                            {
                                cpt_total = temp2->cpt + 1;
                            }
                            if(temp2==temp3)
                            {
                                if(temp2->taille == temp1->taille)
                                {
                                    //printf("La Ligne      '-> 459 \n");
                                    fl = temp2->next;
                                    temp1->type = 'O';
                                    temp1->cpt = temp2->cpt; //## ## ## ## ## ## ## ##
                                    temp1->dtv = temp1->dtv;
                                    temp1->nbr = temp2->nbr;
                                    free(temp2);
                                }
                                else
                                {
                                    //printf("La Ligne      '-> 469 \n");
                                    if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                    {
                                        fl = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp1 = temp2;
                                        head = temp2;
                                    }
                                    else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                    {
                                        fl = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp4->next = temp2;
                                        temp1 = temp2;
                                    }
                                }
                                temp2 = fl;
                                temp3 = temp2;
                            }
                            else  // si le processus est au milieu de la FL
                            {
                                //printf("La Ligne  494 \n");
                                if(temp2->taille == temp1->taille)   // si la taille du processus est la meme taille de la zone libre dans la liste head ( la memoire )
                                {
                                    //printf("La Ligne      '-> 497 \n");
                                    temp3->next = temp2->next;
                                    temp1->type = 'O';
                                    temp1->cpt = temp2->cpt;
                                    temp1->nbr = temp2->nbr;
                                    free(temp2);
                                }
                                else
                                {
                                    //printf("La Ligne      '-> 506 \n");
                                    if(temp1 == temp4)      // si le zone libre est le 1er block dans la liste head  ( la memoire )
                                    {
                                        temp3->next = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp1 = temp2;
                                        head = temp2;
                                    }
                                    else                    // si le zone libre est au milieu dans la liste head  ( la memoire )
                                    {
                                        temp3->next = temp2->next;
                                        temp2->type = 'O';
                                        temp2->next = temp1;
                                        temp1->taille -= temp2->taille;
                                        temp4->next = temp2;
                                        temp1 = temp2;
                                    }
                                }
                                temp2 = temp3->next;
                            }
                            jfl=1;
                        }
                    }
                }
                if(jfl==0)
                {
                    temp4=temp1;
                    temp1=temp1->next;
                }
            }
            if(jfl==0)
            {
                if(temp2->taille <= taille_total)
                {
                    if(cpt_total <= temp2->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = temp2->cpt + 1;
                    }
                    compactage();
                    temp1=head;
                    temp4=temp1;
                    while(temp1->next != NULL)
                    {
                        temp4=temp1;
                        temp1 = temp1->next;
                    }
                    if(temp2==temp3)
                    {
                        //printf("La Ligne      '-> 557 \n");
                        if(temp2->taille == taille_total)
                        {
                            //printf("La Ligne      '-> 559 \n");
                            fl = temp2->next;
                            temp1->type = 'O';
                            temp1->cpt = temp2->cpt;
                            temp1->nbr = temp2->nbr;
                            free(temp2);
                            jfl=1;
                        }
                        else
                        {
                            if(temp1==temp4)
                            {
                                //printf("La Ligne      '-> 575 \n");
                                fl = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                head = temp2;
                                jfl=1;
                            }
                            else
                            {
                                //printf("La Ligne      '-> 5685 \n");
                                fl = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                                jfl=1;
                            }
                        }
                        temp2 = fl;
                        temp3 = temp2;
                    }
                    else
                    {
                        //printf("La Ligne      '-> 582 \n");
                        if(temp2->taille == taille_total)
                        {
                            //printf("La Ligne      '-> 585 \n");
                            temp3->next = temp2->next;
                            temp1->type = 'O';
                            temp1->cpt = temp2->cpt;
                            temp1->nbr = temp2->nbr;
                            free(temp2);
                            jfl=1;
                        }
                        else
                        {
                            if(temp1==temp4)
                            {
                                //printf("La Ligne      '-> 614 \n");
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                head = temp2;
                                jfl=1;
                            }
                            else
                            {
                                //printf("La Ligne      '-> 625 \n");
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                                jfl=1;
                            }
                        }
                        temp2 = temp3->next;
                    }
                }
            }
            if(jfl==0)
            {
                temp3=temp2;
                temp2=temp2->next;
            }
        }

        afficher(t);

    }
}


int main()
{
    node *p = (node *)malloc(sizeof(node) );
    int nbrProcessus;
    int x;
    //printf("entrer La taille total de La memoire : ");
    //scanf("%d",&p->taille);
    //printf("entrer le nombre des processus : ");
    //scanf("%d",&nbrProcessus);
    p->taille = 180;
    nbrProcessus = 6;

    head = p;
    p->next = NULL;
    p->type = 'L';

    x = saisieLesProcessusDansLaListe(nbrProcessus); // return dtv max


    firstfit(x);

    return 0;
}
