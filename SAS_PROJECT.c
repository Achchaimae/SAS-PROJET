 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int x,y,i,j,N,m,nbr,choix;
char code_cherch[20];
int quantite_cherch;
int quantite_ajou;
//char * prod_acheter;
int count = 0;
float somme=0;
int somme_Quantite=0;
//structure du produit 
typedef struct  {
    char CodeBar[50];
    char nom[50];
    int quantite;
    float prix;
}produit;
//structure de statique
typedef struct  {
    char CodeBar_vendus[50];
    int quantite_vendus;
    float prix_total_vendus;
    int jour;
    int mois;
    int annee;
}statisque;

statisque stati[100];
//structure date
typedef struct 
{
  int jour,mois,annee;
}date;


//saisie(DONE)
produit* saisie(produit*p ,int m, int N){
    int i;
    for(i=m;i<N;i++){
     printf("Produit %d: ",i+1);
     printf("\nNom : ");
     scanf("%s",&p[i].nom);
     printf("CodeBar: ");
     scanf("%s",&p[i].CodeBar);
     printf("Quantite : ");
     scanf("%d",&p[i].quantite);
     printf("Prix : ");
     scanf("%f",&p[i].prix);
    }return p;
}
//affichage des produits(DONE)
void affichage(produit *p,int N){
    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);
int i;
    for(i=0;i<N;i++){
                 printf("\n\tProduit %d: ",i+1);
                 printf("\nNom : %s",p[i].nom);
                 printf("\nCodeBar: %s",p[i].CodeBar);
                 printf("\nQuantite: %d",p[i].quantite);
                 printf("\nPrix: %.f",p[i].prix);
                 printf("\nPrix TTC: %.f\n",p[i].prix+(0.15*p[i].prix));//prix ttc 15 %

               }
}

//tri decroissante(DONE)
produit* tri_decroiss(produit *tab,int N){
        int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(tab[i].prix<tab[i+1].prix){
           produit tmp;
           tmp=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=tmp;
           c++;// c ++ pour le but de quiter le programme au moment que la conditions est realise
        }
      }
    }while(c>0);
        return tab;
    }
//tri alphabetique(DONE)
produit* Tri_Alpha(produit *tab,int N){
        int c,i;
        do{
       c=0;
      for(i=0;i<N-1;i++){
        if(strcmp(tab[i].nom,tab[i+1].nom)==1){//strcmp pour comparer les deux chaine caractere
           produit tmp;
           tmp=tab[i];
           tab[i]=tab[i+1];
           tab[i+1]=tmp;
           c++;// c ++ pour le but de quiter le programme au moment que la conditions est realise
        }
      }
    }while(c>0);
        return tab;
    }
//acheter(DONE)
void Acheter(produit *tab){
    //fonction de time
    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);
    int prix_TTC;
    printf("Entrer le code de produit : ");
    scanf("%s", &code_cherch);
    printf("entrer la quantite que vous voulez achete : ");
    scanf("%d", &quantite_ajou);
    for (i = 0; i < N; i++) {
        if (strcmp(code_cherch,tab[i].CodeBar) == 0) {
           // prix_TTC= (tab[i].prix +(tab[i].prix*0.15)) ;
            tab[i].quantite -= quantite_ajou;
            strcpy(stati[i].CodeBar_vendus,tab[i].CodeBar);
            stati[i].quantite_vendus=quantite_ajou;
            stati[i].prix_total_vendus=tab[i].prix * quantite_ajou +(tab[i].prix * quantite_ajou *0.15);//NEED UPDATE
            stati[i].jour=date.tm_mday;
            stati[i].mois=date.tm_mon+1;
            stati[i].annee=date.tm_year +1900;
            count++;

            printf("le traitement est bien execute\n\n");
            break;
        }
    }
                printf("\n\tProduit %d: ",i+1);
                 printf("\nNom : %s",tab[i].nom);
                 printf("\nCodeBar: %s",tab[i].CodeBar);
                 printf("\nQuantite: %d",tab[i].quantite);
                 printf("\nPrix: %.f\n",tab[i].prix);
}
//recherche par CodeBar(DONE)
void Recher_CodeBa(produit *tab, int N, char*code_cherch){
int c=0;
    for(i=0;i<N;i++){
            if(strcmp(tab[i].CodeBar,code_cherch)==0){
                printf("\n\tProduit %d: ",i+1);
                printf("\nNom : %s",tab[i].nom);
                printf("\nCodeBar: %s",tab[i].CodeBar);
                printf("\nQuantite: %d",tab[i].quantite);
                printf("\nPrix: %.f\n",tab[i].prix);
              c++;// c ++ pour le but de quiter le programme au moment que la conditions est realise
            }
    }
    if(c==0) {
            printf("ce code bar n'existe pas dans le stock actuel");
            }

}
//recherche par quantite(DONE)
void Recher_quantite(produit *tab, int N, int quantite_cherch){
 int c=0;

          for(i=0;i<N;i++){
        
            if(quantite_cherch ==(tab[i].quantite)){
                 printf("\n\tProduit %d: ",i+1);
                 printf("\nNom : %s",tab[i].nom);
                 printf("\nCodeBar: %s",tab[i].CodeBar);
                 printf("\nQuantite: %d",tab[i].quantite);
                 printf("\nPrix: %.f\n",tab[i].prix);
              c++;// c ++ pour le but de quiter le programme au moment que la conditions est realise
            }
            
    }if(c==0)
    {printf("ce code bar n'existe dans le stock actuel");}
            
     } 
//quantite inferieur a 3(DONE)
void quantite_in_troi(produit *tab, int N){
  int c=0 ;
   for(i=0;i<N;i++){
        
            if(tab[i].quantite <3){//comparaison simple si inferieur a 3 i doit afficher 
            printf("\n\tProduit %d: ",i+1);
                 printf("\nNom : %s",tab[i].nom);
                 printf("\nCodeBar: %s",tab[i].CodeBar);
                 printf("\nQuantite: %d",tab[i].quantite);
                 printf("\nPrix: %.f\n",tab[i].prix);
              c++;// c ++ pour le but de quiter le programme au moment que la conditions est realise
            }
            
    }if(c==0)
    {printf("ce code bar n'existe dans le stock actuel");}
    

}
//Alimenter le stock(DONE)
void Alimenter(produit *tab){
    printf("Entrer le code de produit : ");
    scanf("%s", &code_cherch);
    printf("entrer la quantite que vous voulez ajouter  : ");
    scanf("%d", &quantite_ajou);
    for (i = 0; i < N; i++) {
        if (strcmp(code_cherch,tab[i].CodeBar) == 0) {//comparer le code bar et le code donne
            tab[i].quantite += quantite_ajou;//ajouter la nouvelle quantite
            printf("le traitement est bien execute\n\n");
            break;// pour focer de quiter le code
        }
    }
    //affichage 
                printf("\n\tProduit %d: ",i+1);
                 printf("\nNom : %s",tab[i].nom);
                 printf("\nCodeBar: %s",tab[i].CodeBar);
                 printf("\nQuantite: %d",tab[i].quantite);
                 printf("\nPrix: %.f\n",tab[i].prix);
}
//supprimer in produit(DONE)
void Supprimer(produit *tab){
    printf("Entrer le code de produit : ");
    scanf("%s", &code_cherch);
        for (i = 0; i < N; i++) {
            if(strcmp(tab[i].CodeBar,code_cherch)==0){
            tab[i]=tab[i+1];
            N--;//pour incrementer la taille du tableau
            }
            printf("le traitement est bien execute\n\n");
            break;// pour focer de quiter le code
        }
    }
void total_vendu(){
    //fonction de time
    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);
     for (i = 0; i < N; i++) {
        if((stati[i].jour==date.tm_mday) && (stati[i].mois==date.tm_mon+1) &&(stati[i].annee==date.tm_year +1900))//pour tester le jour avec meme jour
         {
            somme += stati[i].prix_total_vendus;//pour calculer la somme des prix
            somme_Quantite+=stati[i].quantite_vendus;// pour calculer la some des quantite 
            printf("\n\tProduit %d: ",i+1);
            printf("\nCodeBar: %s",stati[i].CodeBar_vendus);
            printf("\nQuantite: %d",stati[i].quantite_vendus);
            printf("\nPrix: (TTC)%.f\n",stati[i].prix_total_vendus);
        }
    }
     printf("\n>>>La somme des produits vendu en joure courant : %.2f (Avec TTC )\n\n", somme);
}
//fonction pour calculer la moyen qui vendu par jours(DONE)
void moyenne_prix() {
float moyenne;
  moyenne = somme / somme_Quantite;

    printf("\n* La moyenne des prix des produits vendus est : %.2f (en TTC). \n\n", moyenne);

}
//fonction qui donner le max vendus avec ttc(DONE)
void max_prix_jours() {

    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);

    float max_prix_vendu = stati[0].prix_total_vendus;// declarer un variable et stocker la premiere case du tableau dans le variable
    for (i = 0; i < N; i++) {  
        if (stati[i].jour == date.tm_mday && stati[i].mois == date.tm_mon + 1 && stati[i].annee == date.tm_year + 1900) {
            if (max_prix_vendu < stati[i].prix_total_vendus)//condition pour comparer les cases
                max_prix_vendu = stati[i].prix_total_vendus;
        }
    }
    printf("--> Le Max des prix des produits vendu aujourd'hui : %.2f(TTC) \n\n", max_prix_vendu);
}
void min_prix_jours() {

    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);

    float min_vendu = stati[0].prix_total_vendus;// declarer un variable et stocker la premiere case du tableau dans le variable
    for (i = 0; i < N; i++) {       
        if (stati[i].jour == date.tm_mday && stati[i].mois == date.tm_mon + 1 && stati[i].annee == date.tm_year + 1900) {
            if (min_vendu > stati[i].prix_total_vendus)//condition pour comparer les cases
                min_vendu = stati[i].prix_total_vendus;
        }
    }
    printf("--> Le Min des prix des produits vendu aujourd'hui : %.2f(TTC) \n\n", min_vendu);
}
    int main(){
        produit *p;
    statisque * tab_Vendus;//tableau pour les produits vendus


        do{// menu principal
            printf("\n              _______              \n");
            printf("              | MENU |              \n");
            printf("              |______|              \n");
            printf("   _____________________________________________________");
            printf("\n  | \tAjouter un produit [1]\t\t\t\t|");
            printf("\n  | \tAjouter plusieurs produit [2]\t\t\t|");
            printf("\n  | \tLister les produits: [3]\t\t\t|");
            printf("\n  | \tAcheter un produit : [4]\t\t\t|");
            printf("\n  | \tRechercher un produit : [5]\t\t\t|");
            printf("\n  | \tLes produits disponible de quantite < 3 : [6]\t|");
            printf("\n  | \tAlimenter le stock :[7] \t\t\t|");
            printf("\n  | \tSupprimer un produit :[8]\t\t\t|");
            printf("\n  | \tStatique de vente : [9]\t\t\t\t|");
            printf("\n  | \tQuiter le systeme : [0]\t\t\t\t|");
            printf("\n  |_____________________________________________________|                  \n");

            printf("* choisir : ");
            scanf("%d",&x);
                switch (x)
                {
                case 0:
                  printf("DONE!\n");
                    break;
                case 1:// condition pour un seule produits le if else pour le choix de si il existe deja des produit 
                if (N==0){
                        m=N;
                       N=1;  
                    p=malloc(N*sizeof(produit));
                    p=saisie(p,m,N);
                    affichage(p,N);
                    }
                    else{

                        m=N;
                        N=N+1;
                        p=realloc(p,(N*sizeof(produit)));
                        p=saisie(p,m,N);
                        affichage(p,N);
                    }
                  
                break;
                 case 2:// meme pour case 1 et pour reealloc
                    printf("Combien des produits vous voulez entrer :\n ");
                    scanf("%d",&nbr);
                    if (N==0){
                        m=N;
                       N=nbr;  
                    p=malloc(N*sizeof(produit));
                    p=saisie(p,m,N);
                    affichage(p,N);
                    }
                    else{

                        m=N;
                        N=N+nbr;
                        p=realloc(p,(N*sizeof(produit)));
                        p=saisie(p,m,N);
                        affichage(p,N);
                    }
                  
                    
                break;
                case 3 :
                    do{/*sous menu pour lister les produits pour ordre croissante ou alphabetique*/
                        printf(" \t  ________________________________________________________\n");
                        printf("\t |[1]: Lister les produits avec ordre alphabethique\t  |\n");
                        printf("\t |[2]: Lister les produits avec ordre decroissante de prix|\n");
                        printf("\t |[0]: quitter !!\t\t\t\t\t  |\n");
                        printf(" \t |________________________________________________________|\n");
                        scanf("%d",&y);
                        switch(y){
                            case 0:
                                printf("A beintot !\n");
                            break;
                            case 1 ://tri des produits alphabetiquement
                               p=Tri_Alpha(p,N);
                               affichage(p,N);
                            break;
                            case 2:// tri des produits decroissante /prix
                                p=tri_decroiss(p,N);
                              affichage(p,N);
                            break;
                        }
                    }while(y!=0);
                break ;
                case 4://fonction d'achats
                        Acheter(p);

                break;
                case 5:// case pour la recherche de deux facon
                    do{ 
                        printf("\n  ___________________________________________________________                  \n");
                        printf(" |\t[1]: Chercher le produits en utilisant le CodeBar    |\n");
                        printf(" |\t[2]: Chercher le produits en utilisant la quantite   |\n");
                        printf(" |\t[0]: quitter !!  \t \t \t\t     |\t\n");
                        printf(" |___________________________________________________________|                  \n");
                        scanf("%d",&y);
                          switch(y){
                            case 0:
                                printf(" Merci !\n");
                            break;

                            case 1 :
//recherche par code bar
                            printf("donner le CodeBar du produit que vous voulez rechercher\n");
                            scanf("%s",code_cherch);
                            Recher_CodeBa(p,N,code_cherch);

                            break;
                            case 2 :
                            printf("donner la quantite du produit que vous voulez rechercher\n");
                            scanf("%d",&quantite_cherch);
                            Recher_quantite(p,N,quantite_cherch);
                            
                            break;
                            }
                        }while(y!=0);
                break;
                case 6:// produits de quantite inferieur a 3 au niveau de quantite
                     quantite_in_troi(p,N);
                    
                break;
                case 7:// case pour alimenter le stock / ajout quantite recherche par code
                    Alimenter(p);
                break;
                 case 8:// suppression d'un produits de cas final
                    Supprimer(p);
                    printf("les produits valable au stock est \n");
                    affichage(p,N);
                break;
                case 9 :
                    do { 
                        printf("\n  ______________________________________________________________________________     \n");
                        printf(" |\t[1]: Le total des prix des produits vendus(journee courante.)           |\n");
                        printf(" |\t[2]: La moyenne des prix des produits vendus (journee courante.)        |\n");
                        printf(" |\t[3]: Le max des prix des produits vendus (journee courante.)            |\n");
                        printf(" |\t[4]: Le min des prix des produits vendus(journee courante.)             |\n");
                        printf(" |\t[0]: quitter !!  \t \t \t\t                        |\t\n");
                        printf(" |______________________________________________________________________________|                  \n");
                        printf("* Choisir : ");
                        scanf("%d", &choix);

                        switch (choix) {
                            case 0 :
                                printf("Au revoir \n");
                                break;
                            case 1 :            
                                total_vendu();
                                break;
                            case 2 :
                                moyenne_prix();
                                break;
                            case 3 :
                                max_prix_jours();
                                break;
                            case 4 :
                                //affiche_min_prix();
                                min_prix_jours() ;
                                break;
                            
                        }
                    }while (choix != 0);
                            
                    break;
                default:
                printf("tu dois entrer un nombre compris entre [1-9]\n");
                    break;
                }
        }while (x!=0);

printf("test pour le git hub idee branche et tag\n");




}