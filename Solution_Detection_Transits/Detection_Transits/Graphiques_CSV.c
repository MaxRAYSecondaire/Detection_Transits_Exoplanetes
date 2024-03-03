#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "outils.h"

void main(void)
{
	/*Création des données à aficher.
	Les données seront des valeurs d'intensités aléatoire et on admettra que entre chaques données et il y 1 sec*/

	srand(time(NULL));

	TABLEAU_INT data=allocationDynamiqueInt(10);
	initialisationAleatoireTableauInt(data.data, 10, 0, 10);
	affichageTableauInt(data.data, data.taille);    
	
	/*Création d'un fichier csv contenant en entête le nombres de mesures et ensuites un tableau de ces mesures avec comme abscisse son numéro */
	{
		FILE* F = NULL;

		F = fopen("Graph.csv", "w");
		fprintf(F, "%d \n", data.taille); //Entête

		for (int i = 0; i < data.taille; i++)  //boucle pour le tableau des valeurs avec comme abscisse i+1
		{
			fprintf(F, "%d ; %d \n", i + 1, data.data[i]);
		}

		fclose(F);
	}

	free(data.data);  //Libération de l'espace du tableau de données.

}