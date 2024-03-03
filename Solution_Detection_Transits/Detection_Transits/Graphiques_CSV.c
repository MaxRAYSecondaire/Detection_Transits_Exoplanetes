#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "outils.h"

void main(void)
{
	/*Cr�ation des donn�es � aficher.
	Les donn�es seront des valeurs d'intensit�s al�atoire et on admettra que entre chaques donn�es et il y 1 sec*/

	srand(time(NULL));

	TABLEAU_INT data=allocationDynamiqueInt(10);
	initialisationAleatoireTableauInt(data.data, 10, 0, 10);
	affichageTableauInt(data.data, data.taille);    
	
	/*Cr�ation d'un fichier csv contenant en ent�te le nombres de mesures et ensuites un tableau de ces mesures avec comme abscisse son num�ro */
	{
		FILE* F = NULL;

		F = fopen("Graph.csv", "w");
		fprintf(F, "%d \n", data.taille); //Ent�te

		for (int i = 0; i < data.taille; i++)  //boucle pour le tableau des valeurs avec comme abscisse i+1
		{
			fprintf(F, "%d ; %d \n", i + 1, data.data[i]);
		}

		fclose(F);
	}

	free(data.data);  //Lib�ration de l'espace du tableau de donn�es.

}