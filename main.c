#include <stdio.h>
#include <stdlib.h>
#include <time.h> // fournit un ensemble de fonctions permettant la manipulation de dates, de temps et d'intervals.
int main()
{
    printf("******************** APP Structures Conditionnelles! ********************\n");

    /*
    Tout d'abord, l'application demande au client de saisir les informations suivantes :
        ∙ Annee de naissance --> int annee_naissance;
        ∙ Taille --> int taille;
        ∙ Poids  --> int poids;
        ∙ Antecedents medicaux :
            - Intervention chirurgicale lors des 10 dernieres annees : 1 si oui, 0 si non --> int intervention_chirurgicale;
            - Arret de travail de plus d'un mois lors des 5 dernieres annees : 1 si oui, 0 sinon. --> int arret_travail;
            - Depistage de serologies virales : 0 si aucun, 1 si VHA[hepatite A], 2si VHB[hepatite B], 3 si VHC[hepatite C] et 4 si VIH[SIDA]. --> int depistage_serologies_virale;
        ∙ Budget maximal du client (budget) --> int budget;
    */

        int annee_naissance;
        int taille;
        int poids;
        int intervention_chirurgicale;
        int arret_travail;
        int depistage_serologies_virales;
        int budget;

        printf("Donnez l'annee de naissance : ");
        scanf("%d",&annee_naissance);

        printf("Donnez la taille en Cm : ");
        scanf("%d",&taille);

        printf("Donnez le poids en Kg: ");
        scanf("%d",&poids);

        printf("Avez vous Antecedents medicaux?\n");

        printf("\tIntervention chirurgicale lors des 10 dernieres annees : 1 si oui, 0 si non : ");
        scanf("%d",&intervention_chirurgicale);

        printf("\tArret de travail de plus d'un mois lors des 5 dernieres annees : 1 si oui, 0 si non :  ");
        scanf("%d",&arret_travail);

        printf("\tDepistage de serologies virales :\n\t\t0 si aucun, 1 si VHA[hepatite A], 2si VHB[hepatite B], 3 si VHC[hepatite C] et 4 si VIH[SIDA] : ");
        scanf("%d",&depistage_serologies_virales);

        printf("Donnez le budget maximal : ");
        scanf("%d",&budget);

        /*
        Apres la saisie de toutes les informations, l'application verifie la categorie du client : a haut risque, a faible risque ou a risque moyen.
        */

        int haut_risque, moyen_risque, faible_risque ;

        /*
        -- Un client potentiel est considere a haut risque si :
            - Il a fait l'objet d'une intervention chirurgicale lors des 10 dernieres annees(interchirurg =1)
            - Ou s'il a beneficie d'un arrêt de travail de plus d'un mois lors des 5 dernieres annees(arretTravail =1)
            - Ou s'il presente un depistage positif de serologies virales VHB OUVHCOUVIH. (depistage = 2 ou 3 ou 4)
        */
        haut_risque = intervention_chirurgicale || arret_travail || (depistage_serologies_virales>1);

        /*
        -- Sinon un client potentiel est considere a risque moyen si :
            - Il a plus de 50 ans
            - Ou s'il presente un depistage positif de serologie virale VHA (depistage =1)
            - Ou s'il presente un taux d'IMC (Indice de masse corporelle) inferieur a 16.5 ou superieur a 30.
                        La formule de l'IMC est donnee comme suit : IMC = Poids / Taille²
        */

        float taux_IMC= (float) poids/(taille*taille)*10000; // IMC = Poids (Kg) / Taille (m) ²
        const int annee_actuelle = 2022;
        int age= annee_actuelle-annee_naissance;

        moyen_risque = age>50 || (depistage_serologies_virales==1) || (taux_IMC<16.5 || taux_IMC>30);

        /*-- Sinon, un client potentiel est considere a faible risque. */

        faible_risque = !haut_risque && !moyen_risque ;

        if(haut_risque){
            printf("Demande d'adhesion rejetee\n");
        }else{
          /*
            - Si le client est a faible risque , il benefice du tarif de la cotisation de base sans aucune majoration.
                cotisation finale = cotisation de base

            - Si le client est a moyen risque, la compagnie impose une majoration de 15% de la cotisation de base.
                 cotisation finale = cotisation de base*15/100
          */
          int cotisation_finale_niveau1, cotisation_finale_niveau2, cotisation_finale_niveau3;;
          const int cotisation_de_base_niveau1 = 1500;
          const int cotisation_de_base_niveau2 = 1800;
          const int cotisation_de_base_niveau3 = 2100;

          if(moyen_risque){
            cotisation_finale_niveau1 = cotisation_de_base_niveau1 + cotisation_de_base_niveau1*15/100;
            cotisation_finale_niveau2 = cotisation_de_base_niveau2 + cotisation_de_base_niveau2*15/100;
            cotisation_finale_niveau3 = cotisation_de_base_niveau3 + cotisation_de_base_niveau3*15/100;
          } else{ // faible_risque
            cotisation_finale_niveau1 = cotisation_de_base_niveau1;
            cotisation_finale_niveau2 = cotisation_de_base_niveau2;
            cotisation_finale_niveau3 = cotisation_de_base_niveau3;
          }

          printf("\n\nListe des niveaux de prestations possibles : \n");
          if(budget>=cotisation_finale_niveau3){

          /*Liste des niveaux de prestations possibles :
                niveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire Tarif de cotisation total = 1500 DT.
                niveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataireTarif de cotisation total = 1800 DT.
                niveau 3 : maximum de prestations remboursees = 5000 DT par an et par prestataireTarif de cotisation total = 2100 DT.
          */
          printf("\t niveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau1);
          printf("\t niveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau2);
          printf("\t niveau 3 : maximum de prestations remboursees = 5000 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau3);
          }else          if(budget>=cotisation_finale_niveau2){
          printf("\t niveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau1);
          printf("\t niveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau2);
          }else          if(budget>=cotisation_finale_niveau1){
          printf("\t niveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = %d DT.\n",cotisation_finale_niveau1);
          }else{
          printf("\t budget non suffisant\n\n");
          return -1;
          }


        int niveau_prestattion;
        printf("\nVeuillez choisir le niveau de prestations souhaite: ");
        scanf("%d",&niveau_prestattion);

        switch(niveau_prestattion){
            case 1 : printf("\n\tNiveau 1 : details des plafonds de remboursement :\n"
                            "\t\tConsultations :20 DT / acte\n"
                            "\t\tMedicaments : 400 DT\n"
                            "\t\tAnalyses : 150 DT\n"
                            "\t\tRadiologie : 180 DT\n"
                            "\t\tChirurgie : 1500 DT\n"
                            "\tMaximum de prestations remboursees = 3000 DT par prestataire et par an\n");
                            break;

            case 2 : printf("\n\tNiveau 2 : details des plafonds de remboursement :\n"
                            "\t\tConsultations :30 DT / acte\n"
                            "\t\tMedicaments : 600 DT\n"
                            "\t\tAnalyses : 200 DT\n"
                            "\t\tRadiologie : 250 DT\n"
                            "\t\tChirurgie : 1800 DT\n"
                            "\tMaximum de prestations remboursees = 3500 DT par prestataire et par an\n");
                            break;

            case 3 : printf("\n\tNiveau 3 : details des plafonds de remboursement :\n"
                            "\t\tConsultations :40 DT / acte\n"
                            "\t\tMedicaments : 600 DT\n"
                            "\t\tAnalyses : 300 DT\n"
                            "\t\tRadiologie : 300 DT\n"
                            "\t\tChirurgie : 2000 DT\n"
                            "\tMaximum de prestations remboursees = 5000 DT par prestataire et par an\n");
                            break;

            default : printf("Niveau saisi non valide\n");
        }
        }


    return 0;
}
