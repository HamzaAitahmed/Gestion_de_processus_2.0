#include <stdio.h>
#include <stdlib.h>

/*
    ----------------------------------------------  Les Objectifs qui reste ------------------------------------------------------

    � d�cr�menter tous les processus qui sont dans la memoire ( cpt )     ######################################## 10/10  ( easy )

    � ajouter une variable ( nbr ) de type int dans la structure node pour conna�tre le num�ro du processus   #### 10/10  ( easy )

    � liberer un processus dans la memoire     ################################################################### 10/10  ( easy )

    � cpt_total     ############################################################################################## 10/10  ( moyen )

    � prendre un processus dans la file d'attente et l'ajouter dans la memoire     ############################### 07/10  ( Hard )

    � Probleme Dans La Fil D'attete cpt_total et nbr du processus                  ############################### 00/10  ( Hard )

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

node *head = NULL , *fl = NULL , *lsd = NULL ; // Des Variables Globales

node *addhead() // cree un block pour un processus
{
    node *n = (node*)malloc( sizeof(node) );
    n->next = NULL;
    n->type = 'O';

    return n;
}

node *addfl() // cree un block pour un processus
{
    node  *temp1 = fl, *n = (node*)malloc( sizeof(node) );

    n->type = 'F';
    n->next = NULL;

    if(fl == NULL)
    {
        fl = n;
    }
    else
    {
        while(temp1->next != NULL)
        {
            temp1 = temp1->next ;
        }
        temp1->next = n;
    }

    return n;
}

node *addlsd() // cree un block pour un processus
{
    node  *temp1 = lsd, *n = (node*)malloc( sizeof(node) );

    n->next = NULL;

    if(lsd == NULL)
    {
        lsd = n;
    }
    else
    {
        while(temp1->next != NULL)
        {
            temp1 = temp1->next ;
        }
        temp1->next = n;
    }

    return n;
}

void afficher_compactage()
{
    node *temp1 = head;
    printf("\n Compactage !!!!  \n--------------- \n");
    while(temp1 != NULL) // d�cr�menter le temps d'execution des processus
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

void compactage()  /// naaaaadi  10/10
{
    int taille=0;
    node *temp11 , *temp12 , *temp13 ;

    node *n = (node *)malloc(sizeof(node) ); // cr�er un block pour remplacer tous les zones libres dans un seul block qui est n

    n->next = NULL;
    n->type = 'L';

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
        while(temp11 != NULL) // pour �liminer les blocs des zones libres et les remplacer tous dans un seul block
        {

            if(temp11->type == 'L') // c'est pour verifier si Le 1 er block a une zone libre
            {
                if(temp11 == temp12)
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
                    temp13 = temp11;
                    temp11 = temp11->next;
                    temp12->next = temp11;
                    free(temp13);
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
            n->taille = taille; // apr�s avoir supprimer les zones libres et compter leur taille
        }
    }
    afficher_compactage();
}

void afficher(int t)
{
    node *temp1 = head;
    printf(" ####");
    printf(" A : %d ",t);
    printf("####\t\t\t\t\t\t\t|\n");
    printf(" ---------------\t\t\t\t\t\t\t| \n");
    while(temp1 != NULL) // d�cr�menter le temps d'execution des processus
    {
        if(temp1->type == 'O')
        {
            temp1->cpt--;
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t|\n", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv);
            printf(" ---------------\t\t\t\t\t\t\t| \n");
            if(temp1->cpt==0) // liberer un processus
            {
                temp1->type = 'L';
            }
        }
        else
        {
            printf("|\t%d\t|\t\t\t\t\t\t\t|\n",temp1->taille);
            printf(" ---------------\t\t\t\t\t\t\t| \n");
        }
        temp1 = temp1->next ;
    } // nadiii 10/10

    //////////////////////////////////////////////////////////

    temp1 = fl;
    if(fl!=NULL)
    {
        printf("\t\t\t\t\t\t\t\t\t|\n FILE D'ATTENTE : \t\t\t\t\t\t\t|\n\t\t\t\t\t\t\t\t\t|\n ---------------\t\t\t\t\t\t\t| \n");
        while(temp1 != NULL) // decrementer le temps d'execution des processus
        {
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t|\n", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv);
            printf(" ---------------\t\t\t\t\t\t\t| \n");
            temp1 = temp1->next ;
        }
    }
    printf("\n************************************************************************\n\n");
}

void firstfit(int x)
{
    int  i , t , jhead , jfl , taille2 , taille_total , cpt2 , dtv2 , cpt_total , taille_max , dtvmax;
    node *temp7 , *temp6 , *temp5 , *temp4 , *temp3 , *temp2 , *temp1;

    printf("\n\t First Fit Last Version  ( FF-LV )\n");
    printf(" --------------- \n");
    printf("|\t%d\t|\n",head->taille);
    printf(" --------------- \n");
    printf("\n\n");

    for(i=1 , dtvmax=0 ; i<x+1 ; i++)
    {
        taille_max=head->taille;
        do
        {
            printf("\tentrer La taille du P%d : ",i);
            scanf("%d",&taille2);
            if(taille_max < taille2)
                printf("\n\tERROR ( La Taille Du Processus Est Superieur A La Taille De La Memoire %d > %d) \n\n",taille2,taille_max);
            else
            {
                printf("\tentrer Le temps d'execu du P%d : ",i);
                scanf("%d",&cpt2);
                printf("\tentrer La Date D'arrivee du P%d : ",i);
                scanf("%d",&dtv2);
                if(dtvmax<=dtv2)
                    dtvmax=dtv2;
            }
            printf("\n\n");

        }while(taille_max < taille2);
        temp1 = addlsd();
        temp1->taille = taille2;
        temp1->cpt    = cpt2;
        temp1->dtv    = dtv2;
        temp1->nbr    = i;
    }


    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        temp5=lsd;
        temp6=temp5;
        while(temp5!=NULL) // pour sasir toutes les P dans La Memoire ou La FL a condition si t==dtv
        {
            if(t==temp5->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                jhead=0;
                temp1 = head;
                temp3 = head;
                taille_total = 0;

                if(fl==NULL)
                {
                    //printf("La Ligne 202 \n");
                    while(temp1!=NULL && jhead==0) //  chercher une place dans La memoir libre
                    {
                        if(head->next == NULL) // �a signifie qu'il y a un seul block dans la list
                        {
                            if(head->type == 'L')
                            {
                                if(temp5->taille <= head->taille)
                                {
                                    if(cpt_total <= temp5->cpt) // pour augmenter Le temps d'execution total
                                    {
                                        cpt_total = temp5->cpt+1;
                                    }
                                    if(temp5->taille == head->taille)
                                    {
                                        head->cpt = temp5->cpt;
                                        head->dtv = temp5->dtv;
                                        head->type = 'O';
                                        head->nbr = temp5->nbr;
                                    }
                                    else
                                    {
                                        temp2 = addhead(); // temp2 = n    &    n->next = NULL    &    n->type = 'O'
                                        temp2->cpt = temp5->cpt;
                                        temp2->dtv = temp5->dtv;
                                        temp2->nbr = temp5->nbr;
                                        temp2->taille = temp5->taille;
                                        head->taille -= temp5->taille;
                                        temp2->next = head;
                                        head = temp2;
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

                                    jhead=1; // si le processus a trouve une place dans la memoire
                                }
                            }
                        }
                        else // temp1 et temp3 pour remplacez le block dans la list & temp2 pour creer le block
                        {
                            if(temp1->type == 'L')  // si Le block a trouvee une place dans La memoir
                            {
                                taille_total += temp1->taille;

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
            while(temp1!=NULL && jfl==0)
            {
                if(temp1->type == 'L')
                {
                    taille_total += temp1->taille;
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
                                    head = temp2;
                                    temp1 = temp2;
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
                                head = temp2;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                            }
                            else
                            {
                                fl = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                            }
                            jfl=1;
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
                        }
                        else
                        {
                            if(temp1==temp4)
                            {
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                head = temp2;
                                temp1->taille -= temp2->taille;
                            }
                            else
                            {
                                temp3->next = temp2->next;
                                temp2->type = 'O';
                                temp2->next = temp1;
                                temp1->taille -= temp2->taille;
                                temp4->next = temp2;
                            }
                        }
                        jfl=1;
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
    int z;

    printf("entrer La taille total de La memoire : ");
    scanf("%d",&p->taille);
    printf("entrer le nombre des processus : ");
    scanf("%d",&z);

    head = p;
    p->next = NULL;
    p->type = 'L';
    firstfit(z);
    return 0;
}


/*

    Exemple :
        int taille_pro[8] = {100 ,25 ,85 ,45 ,65 ,75 ,95 ,5};
        int temps_pro[8] =  {3   ,3  ,3  ,1  ,2  ,2  ,2  ,3};
        int datv_pro[8] =   {0   ,0  ,0  ,0  ,0  ,0  ,0  ,0};


        taille2 = taille_pro[i-1];
        cpt2 = temps_pro[i-1];
        dtv2 = datv_pro[i-1];

        entrer La taille du P1 : 100
        entrer Le temps d'execu du P1 : 3
        entrer La Date D'arrivee du P1 : 0


        entrer La taille du P2 : 25
        entrer Le temps d'execu du P2 : 3
        entrer La Date D'arrivee du P2 : 0


        entrer La taille du P3 : 85
        entrer Le temps d'execu du P3 : 3
        entrer La Date D'arrivee du P3 : 0


        entrer La taille du P4 : 45
        entrer Le temps d'execu du P4 : 1
        entrer La Date D'arrivee du P4 : 0


        entrer La taille du P5 : 65
        entrer Le temps d'execu du P5 : 2
        entrer La Date D'arrivee du P5 : 0


        entrer La taille du P6 : 75
        entrer Le temps d'execu du P6 : 2
        entrer La Date D'arrivee du P6 : 0


        entrer La taille du P7 : 95
        entrer Le temps d'execu du P7 : 2
        entrer La Date D'arrivee du P7 : 0


        entrer La taille du P8 : 5
        entrer Le temps d'execu du P8 : 3
        entrer La Date D'arrivee du P8 : 0

*/
