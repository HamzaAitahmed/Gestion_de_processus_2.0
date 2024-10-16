#include <stdio.h>
#include <stdlib.h>

                        	// Hamza AitAhmed
				// 2APG4 EMSI Orangers , Casablanca , Maroc
				// 2022/2021


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
    printf("//////////////////////////////////////////////////////////\n   /////////////////////  Compactage %s  /////////////////\n      //////////////////////////////////////////////////////////\n",message);
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

void compactage()  /// naaaaadi  10/10
{
    int taille=0;
    node *Current , *Previous ;

    node *n = (node *)malloc(sizeof(node) ); // créer un block pour remplacer tous les zones libres dans un seul block qui est n

    n->next = NULL;
    n->type = 'L';

    //afficherCompactage("Avant");

    Current = head;
    Previous = Current;
    if(Current->next != NULL)
    {
        while(Current != NULL) // pour éliminer les blocs des zones libres et les remplacer tous dans un seul block
        {
            if(Current->type == 'L')
            {
                if(Current == Previous) // c'est pour verifier si Le 1 er block a une zone libre
                {
                    head = Current->next;
                    taille += Current->taille;
                    free(Current);
                    Current = head;
                    Previous = Current;
                }
                else
                {
                    Previous->next = Current->next;
                    taille += Current->taille;
                    free(Current);
                    Current = Previous->next;
                }
            }
            else
            {
                Previous = Current;
                Current = Current->next;
            }
        }
        if(head==NULL)
        {
            head = n;
            n->taille = taille;
        }
        else
        {
            Previous->next = n;
            n->taille = taille; // après avoir supprimer les zones libres et compter leur taille
        }
    }

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
        printf("\n FILE D'ATTENTE : \n ^^^^^^^^^^^^^^ \n --------------- \n");
        while(temp1 != NULL) // décrémenter le temps d'execution des processus
        {
            printf("|\tP%d\t|    ->\ttaille : %d\t-> cpt : %ds\t-> dtv : %ds\t-> type : %c", temp1->nbr , temp1->taille , temp1->cpt , temp1->dtv , temp1->type);
            if(temp1->next!=NULL) printf("\t-> next->taille : %d\n",temp1->next->taille); else printf("\n");
            printf(" --------------- \n");
            temp1 = temp1->next ;
        }
        //printf("\n");
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

void afficher(int t) /// naaaaadi  10/10
{
    printf("\n____________________________________________________________________________________________________________\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");

    printf(" ###  A : %d  ###\n",t);


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

}

int calculerTailleTotalBlockLibre()
{
    node *temp;
    temp=head;
    int taille = 0;
    if(head!=NULL)
    {
        if(head->next==NULL)
        {
            if(head->type=='L')
            {
                return head->taille;
            }
        }
        while(temp != NULL) // décrémenter le temps d'execution des processus
        {
            if(temp->type=='L')
            {
                taille += temp->taille;
            }
            temp = temp->next;
        }
    }
    return taille;
}

int saisieLesProcessusDansLaListe(int nbrProcessus)
{
    int  ordre , taille_Processus , temps_exe_Pr , date_arr_Pr , taille_max , dtvmax;
    node  *temp;

    printf("\n\n --------------- \n");
    printf("|\t%d\t|\n",head->taille);
    printf(" --------------- \n ");

/*
    for(ordre=1 , dtvmax=0 ; ordre<nbrProcessus+1 ; ordre++)
    {
        taille_max=head->taille;
        do
        {
            printf("\tentrer La taille du P%d : ",ordre);
            scanf("%d",&taille_Processus);
            if(taille_max < taille_Processus || taille_Processus <= 0)
            {
                printf("\n\tERROR ( La Taille Du Processus Est Inferieur A 1 ou bien est Superieur A La Taille De La Memoire %d > %d) \n\n",taille_Processus,taille_max);
                ordre--;
                continue;
            }

            printf("\tentrer Le temps d'execu du P%d : ",ordre);
            scanf("%d",&temps_exe_Pr);
            if(temps_exe_Pr <= 0)
            {
                printf("\n\tERROR ( Le temps d'execution est Inferieure ou Egale a 0 ( %d <= 0 ) \n\n",temps_exe_Pr);
                ordre--;
                continue;
            }

            printf("\tentrer La Date D'arrivee du P%d : ",ordre);
            scanf("%d",&date_arr_Pr);
            if(date_arr_Pr < 0)
            {
                printf("\n\tERROR ( La Date D'arrivee est Inferieure a 0 ( %d < 0 ) \n\n",date_arr_Pr);
                ordre--;
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

     Pour testet un cas exceptionnel et le repeter
*/
        temp = addlsd(); temp->taille = 100;    temp->cpt    = 3;   temp->dtv    = 2;   temp->nbr    = 1;
        temp = addlsd(); temp->taille = 180;    temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 2;
        temp = addlsd(); temp->taille = 10;     temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 3;
        temp = addlsd(); temp->taille = 80;     temp->cpt    = 5;   temp->dtv    = 1;   temp->nbr    = 4;
        temp = addlsd(); temp->taille = 15;     temp->cpt    = 3;   temp->dtv    = 0;   temp->nbr    = 5;
        temp = addlsd(); temp->taille = 15;     temp->cpt    = 3;   temp->dtv    = 3;   temp->nbr    = 6;
    afficherLSD();
    return 3;

}

int BestPosition(int taille)
{
    int  i , pos , jpos  , max ;
    node *temp = head;

    for(i=1 , pos=0 , jpos=0 , max=0 ; temp!=NULL && jpos==0  ; i++)
    {
        if(temp->type=='L')
        {
            if(taille <= temp->taille)
            {
                if(pos==0)
                {
                    max = temp->taille;
                    pos=i;
                }
                if(taille == temp->taille)
                {
                    pos = i;
                    jpos=1;
                }
                else
                {
                    if(max > temp->taille)
                    {
                        pos = i;
                        max = temp->taille ;
                    }
                }
            }
        }
        temp = temp->next;
    }
    //printf("\n ===> Current_FL taille : %d ===> pos : %d \n", taille,pos);

    return pos;
}

int WorstPosition(int taille)
{
    int  i , pos  , max ;
    node *temp = head;

    for(i=1 , pos=0 , max=0 ; temp!=NULL  ; i++)
    {
        if(temp->type=='L')
        {
            if(taille <= temp->taille)
            {
                if(pos==0)
                {
                    max = temp->taille;
                    pos=i;
                }
                if(max < temp->taille)
                {
                    pos = i;
                    max = temp->taille ;
                }
            }
        }
        temp = temp->next;
    }
    return pos;

}
void FB_TO_MFB(node *Current_RL, node *Current_SL, enum ListType Sender_Liste) // First Block To First Block ( ajouter le processus dans le premier block de la memoire )
{
    if(Sender_Liste==LD)
        lsd = Current_SL->next;

    if(Sender_Liste==FL)
        fl = Current_SL->next;


    head = Current_SL;
    Current_SL->type = 'O';
    Current_SL->next = Current_RL;

    Current_RL->taille -= Current_SL->taille;
    if(Current_RL->taille <= 0) // verifier le block contient une espace vide sinon il faut le supprimer ( en utilisant free() )
    {
        Current_SL->next = Current_RL->next;
        free(Current_RL);
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

void FB_TO_MMLB(node *Current_RL, node *Previous_RL, node *Current_SL, node *Previous_SL, enum ListType Sender_Liste) // First Block To Middle/Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
{
    if(Sender_Liste==LD)
        lsd = Current_SL->next;

    if(Sender_Liste==FL)
        fl = Current_SL->next;

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

void MB_TO_MMLB(node *Current_RL, node *Previous_RL, node *Current_SL, node *Previous_SL) // Middle Block To Middle/Last Block ( ajouter le processus dans un block au milieu ou dernier de la memoire )
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

node *pointingLastBlock(enum ListType type)
{
    node *temp = NULL ;

    if(type==LH)
        temp = head;
    if(type==LD)
        temp = lsd;
    if(type==FL)
        temp = fl;

    if(temp!=NULL)
    {
        while(temp->next != NULL) // pointer sur le derniere block ( parce que il est libre )
            {
                temp = temp->next;
            }
    }

    return temp;
}

void firstfit(int dtvmax)
{
    int  t, jhead, jfl, cpt_total;
    node *Current_Head, *Previous_Head, *Current_FL, *Previous_FL, *Current_LSD, *Previous_LSD;

    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {

        /*
                #########################################################################################################################

            #############  Ajouter Les Processus De Liste D'Arrivee à La Memoire  ###################################################

        #########################################################################################################################

        */
        Current_LSD   = lsd;
        Previous_LSD  = Current_LSD;

        while(Current_LSD!=NULL) // pour saisir toutes les Processus dans La Memoire a condition ( si t==dtv et s'il y a des block libres ) sinon dans La FL
        {
            if(t==Current_LSD->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                Current_Head = head;
                Previous_Head = Current_Head;

                jhead=0;
                if(fl==NULL)  // si nous avons un processus qui va libérer sa place et qu'il y a deux processus qui vont prendre sa place, un dans la liste d'arrivée et l'autre dans la file d'attente, donc ici la priorité pour la file d'attente
                {
                    while(Current_Head!=NULL && jhead==0) //  chercher une place dans La memoir libre
                    {
                        if(Current_Head->type == 'L')
                        {
                            if(Current_LSD->taille <= head->taille)
                            {
                                if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                                {
                                    cpt_total = Current_LSD->cpt+1;
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
                                    Current_LSD = Previous_LSD->next;
                                }

                                jhead=1; // si le processus a trouve une place dans la memoire
                            }
                        }
                        Previous_Head = Current_Head;
                        Current_Head = Current_Head->next;
                    }
                    if(jhead==0 && Current_LSD->taille <= calculerTailleTotalBlockLibre() ) // si La taille du processus est inferieur a La taille total des blocks libres
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
                        if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                        {
                            cpt_total = Current_LSD->cpt+1;
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
                    }
                }

                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    Current_FL = addfl();
                    Current_FL->cpt = Current_LSD->cpt;
                    Current_FL->nbr = Current_LSD->nbr;
                    Current_FL->dtv =  Current_LSD->dtv;
                    Current_FL->taille = Current_LSD->taille;

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

        /*

                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################

         */

        Current_FL  = fl;
        Previous_FL = Current_FL;

        while(Current_FL!=NULL)
        {
            Current_Head=head;
            Previous_Head=Current_Head;

            jfl=0;
            while(Current_Head!=NULL && jfl==0)
            {
                if(Current_Head->type == 'L')
                {
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
                if(Current_FL->taille <= calculerTailleTotalBlockLibre())
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
                    /*
                    if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_LSD->cpt+1;
                    }
                    */
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

            #########################################################  Affichage  ###################################################

        #########################################################################################################################

        */

        afficher(t); // la variable t  represente le temps qui s'affiche a cote du A ( exemple -->   #####  A : 8  ##### )
    }
}


void BestFit(int dtvmax)
{
    int  i, t, pos , jhead , jfl , cpt_total  ;
    node *Current_Head, *Previous_Head, *Current_FL, *Previous_FL, *Current_LSD, *Previous_LSD;

    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        Current_LSD=lsd;
        Previous_LSD=Current_LSD;
        while(Current_LSD!=NULL) // pour sasir toutes les P dans La Memoire ou La FL a condition si t==dtv
        {
            if(t==Current_LSD->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                Current_Head = head ;
                Previous_Head = head ;

                jhead=0 ;

                pos = BestPosition(Current_LSD->taille);

                if(fl==NULL) // si nous avons un processus qui va libérer sa place et qu'il y a deux processus qui vont prendre sa place, un dans la liste d'arrivée et l'autre dans la file d'attente, donc ici la priorité pour la file d'attente
                {
                    for(i=1 ; Current_Head!=NULL && jhead==0 && pos!=0 ; i++)
                    {
                        if(i==pos)
                        {
                            if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                            {
                                cpt_total = Current_LSD->cpt+1;
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

                                Current_LSD = Previous_LSD->next;
                            }
                            jhead=1;
                        }
                        Previous_Head = Current_Head;
                        Current_Head = Current_Head->next;
                    }

                    if(jhead==0 && Current_LSD->taille <= calculerTailleTotalBlockLibre() ) // si La taille du processus est inferieur a La taille total des blocks libres
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
                        if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                        {
                            cpt_total = Current_LSD->cpt+1;
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
                    }
                }

                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    Current_FL = addfl();
                    Current_FL->cpt = Current_LSD->cpt;
                    Current_FL->nbr = Current_LSD->nbr;
                    Current_FL->dtv =  Current_LSD->dtv;
                    Current_FL->taille = Current_LSD->taille;
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
            else
            {
                Previous_LSD = Current_LSD;
                Current_LSD = Current_LSD->next;
            }
        }

        /*
                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################                                  */

        Current_FL=fl;
        Previous_FL=Current_FL;
        while(Current_FL!=NULL)
        {
            Current_Head=head;
            Previous_Head=Current_Head;

            jfl=0;

            pos = BestPosition(Current_FL->taille);


            //while(Current_Head!=NULL && jfl==0)
            for( i=1 ; Current_Head!=NULL && jfl==0 && pos!=0 ; i++ )
            {
                if(pos==i)
                {
                    if(cpt_total <= Current_FL->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_FL->cpt + 1;
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
                        Current_FL = fl;
                        Previous_FL = Current_FL;
                    }
                    else
                    {
                        if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                        {
                            MB_TO_MFB(Current_Head, Current_FL, Previous_FL);
                        }
                        else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                        {
                            MB_TO_MMLB(Current_Head, Previous_Head, Current_FL, Previous_FL);
                        }

                        Current_FL = Previous_FL->next;
                    }
                    jfl=1;
                }
                if(jfl==0)
                {
                    Previous_Head=Current_Head;
                    Current_Head=Current_Head->next;
                }
            }



            if(jfl==0)
            {
                if(Current_FL->taille <= calculerTailleTotalBlockLibre())
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
                    if(cpt_total <= Current_FL->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_FL->cpt+1;
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
                Previous_FL=Current_FL;
                Current_FL=Current_FL->next;
            }
        }

        /*
                #########################################################################################################################

            #########################################################  Affichage  ###################################################

        #########################################################################################################################

        */

        afficher(t); // la variable t  represente le temps qui s'affiche a cote du A ( exemple -->   #####  A : 8  ##### )

    }
}


void WorstFit(int dtvmax)
{
    int  i, t, pos , jhead , jfl , cpt_total  ;
    node *Current_Head, *Previous_Head, *Current_FL, *Previous_FL, *Current_LSD, *Previous_LSD;

    for( t=0 , cpt_total = 1 ; cpt_total > 0 || t<dtvmax+1 ; t++ , cpt_total--) // boocle general ( Traitement )
    {
        Current_LSD=lsd;
        Previous_LSD=Current_LSD;
        while(Current_LSD!=NULL) // pour sasir toutes les P dans La Memoire ou La FL a condition si t==dtv
        {
            if(t==Current_LSD->dtv) // c'est pour ajouter Le processus dans La memoire ou dans La file d'attente
            {
                Current_Head = head ;
                Previous_Head = head ;

                jhead=0 ;

                pos = WorstPosition(Current_LSD->taille);

                if(fl==NULL) // si nous avons un processus qui va libérer sa place et qu'il y a deux processus qui vont prendre sa place, un dans la liste d'arrivée et l'autre dans la file d'attente, donc ici la priorité pour la file d'attente
                {
                    for(i=1 ; Current_Head!=NULL && jhead==0 && pos!=0 ; i++)
                    {
                        if(i==pos)
                        {
                            if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                            {
                                cpt_total = Current_LSD->cpt+1;
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

                                Current_LSD = Previous_LSD->next;
                            }
                            jhead=1;
                        }
                        Previous_Head = Current_Head;
                        Current_Head = Current_Head->next;
                    }

                    if(jhead==0 && Current_LSD->taille <= calculerTailleTotalBlockLibre() ) // si La taille du processus est inferieur a La taille total des blocks libres
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
                        if(cpt_total <= Current_LSD->cpt) // pour augmenter Le temps d'execution total
                        {
                            cpt_total = Current_LSD->cpt+1;
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
                    }
                }

                if(jhead==0) // si Le block n'a pas trouvee une place dans La memoir , ajouter dans La file d'attente
                {
                    Current_FL = addfl();
                    Current_FL->cpt = Current_LSD->cpt;
                    Current_FL->nbr = Current_LSD->nbr;
                    Current_FL->dtv =  Current_LSD->dtv;
                    Current_FL->taille = Current_LSD->taille;
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
            else
            {
                Previous_LSD = Current_LSD;
                Current_LSD = Current_LSD->next;
            }
        }

        /*
                #########################################################################################################################

            ######### ( if ) c'est la fin d'ajouter Le processus dans La memoire ou dans La file d'attente   ########################

        #########################################################################################################################                                  */

        Current_FL=fl;
        Previous_FL=Current_FL;
        while(Current_FL!=NULL)
        {
            Current_Head=head;
            Previous_Head=Current_Head;

            jfl=0;

            pos = WorstPosition(Current_FL->taille);


            //while(Current_Head!=NULL && jfl==0)
            for( i=1 ; Current_Head!=NULL && jfl==0 && pos!=0 ; i++ )
            {
                if(pos==i)
                {
                    if(cpt_total <= Current_FL->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_FL->cpt + 1;
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
                        Current_FL = fl;
                        Previous_FL = Current_FL;
                    }
                    else
                    {
                        if(Current_Head == Previous_Head)   // si le zone libre est le 1er block dans la liste head  ( la memoire )
                        {
                            MB_TO_MFB(Current_Head, Current_FL, Previous_FL);
                        }
                        else    // si le zone libre est au milieu dans la liste head  ( la memoire )
                        {
                            MB_TO_MMLB(Current_Head, Previous_Head, Current_FL, Previous_FL);
                        }

                        Current_FL = Previous_FL->next;
                    }
                    jfl=1;
                }
                if(jfl==0)
                {
                    Previous_Head=Current_Head;
                    Current_Head=Current_Head->next;
                }
            }



            if(jfl==0)
            {
                if(Current_FL->taille <= calculerTailleTotalBlockLibre())
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
                    if(cpt_total <= Current_FL->cpt) // pour augmenter Le temps d'execution total
                    {
                        cpt_total = Current_FL->cpt+1;
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
                Previous_FL=Current_FL;
                Current_FL=Current_FL->next;
            }
        }

        /*
                #########################################################################################################################

            #########################################################  Affichage  ###################################################

        #########################################################################################################################

        */

        afficher(t); // la variable t  represente le temps qui s'affiche a cote du A ( exemple -->   #####  A : 8  ##### )

    }
}



int main()
{
    head = (node *)malloc(sizeof(node) );

    int nbrProcessus;
    int x;
    printf("entrer La taille total de La memoire : ");
    scanf("%d",&head->taille);
    printf("entrer le nombre des processus : ");
    scanf("%d",&nbrProcessus);
    
    head->next = NULL;
    head->type = 'L';

    x = saisieLesProcessusDansLaListe(nbrProcessus); // return date arrivee max

    do
    {
        printf(" 1 -> FirstFit \n 2 -> BestFit \n 3 -> WorstFit \n");
        printf("Entrer L'algorithme : " );
        scanf("%d",&i);
        printf("\n\n");
    }while(i<1 || i>3);

    switch(i)
    {
        case 1:
            printf(" ### Vous Avez Choisis FirstFit ### \n\n");
            FirstFit(x);
            break;
        case 2:
            printf(" ### Vous Avez Choisis BestFit ### \n\n");
            BestFit(x);
            break;
        case 3:
            printf(" ### Vous Avez Choisis WorstFit ### \n\n");
            WorstFit(x);
            break;
    }

    return 0;
}

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
