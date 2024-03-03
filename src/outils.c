#include "outils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int factorielle(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
		res = res * i;

	return(res);
}

void echange(int* pa, int* pb)
{
	int inter; /* ne sert que localement */

	inter = *pa;
	*pa = *pb;
	*pb = inter;

	/*pour l'utiliser faire: echange(&a &b);*/
}

int ValeurAleatoire(int valMin, int valMax)
{
	int Val = 0;
	Val = valMin + rand() % (valMax + 1 - valMin);
	return (Val);
}

// Tableaux
void miseTableauAuCarre(int tIn[], int nIn, int tOut[], int nOut)
{

	for (int i = 0; i < nIn; i++)
		tOut[i] = tIn[i] * tIn[i];
}


void affichageTableauInt(int t[], int n)
{
	printf("\naffichage tableau ---------\n");
	for (int i = 0; i < n; i++)
		printf("%d ", t[i]);
	printf("\nfin affichage tableau -----\n");
}

void initialisationAleatoireTableauInt(int t[], int n, int valMin, int valMax)
{
	for (int i = 0; i < n; i++)
		t[i] = valMin + rand() % (valMax + 1 - valMin);
}


void copieTableauInt(int t1[], int t2[], int n)
{
	for (int i = 0; i < n; i++)
		t2[i] = t1[i];
}


int minTableauInt(int t[], int n)
{
	int min = t[0];
	for (int i = 0; i < n; i++)
	{
		if (t[i] <= min)
		{
			min = t[i];
		}
	}
	return min;
}

int maxTableauInt(int t[], int n)
{
	int max = t[0];
	for (int i = 0; i < n; i++)
	{
		if (t[i] >= max)
		{
			max = t[i];
		}
	}
	return max;
}

void triEchangeTableauInt(int t[], int n) /* Sert à trier les valeurs d'un tableaux dans l'ordre croissant*/
{
	int min = 0;
	int temp = 0;
	for (int p = 0; p < n; p++)
	{
		min = p;
		for (int i = p; i < n; i++)
		{
			if (t[i] <= t[min])
			{
				min = i;
			}
		}

		temp = t[p];
		t[p] = t[min];
		t[min] = temp;


	}
}

double calculTableauInt(int t[], int n)
{
	double somme = 0;

	if (t[0] % 2 == 0)
	{
		somme = t[0];
	}
	else
	{
		somme = t[0] * sqrt(2);
	}

	for (int i = 1; i < n; i++)
	{
		if (t[i] % 2 == 0)
		{
			somme = somme + t[i];
		}
		else
		{
			somme = somme + t[i] * sqrt(2);
		}


	}
	return(somme);
}

void fusionTableauInt(int tab1[], int nTab1, int tab2[], int
	nTab2, int tabFusion[], int nTabFusion)
{


	for (int i = 0; i < nTabFusion; i++)
	{
		if (i < nTab1)
		{
			tabFusion[i] = tab1[i];
		}
		if (i >= nTab1)
		{
			tabFusion[i] = tab2[i - nTab1];
		}
	}
}

int medianeTableauInt(int t[], int n)
{
	triEchangeTableauInt(t, n);

	int Med = 0;
	Med = n / 2;


	return t[Med];
}


void histoTableauInt(int tIn[], int nIn, double h[])
{
	triEchangeTableauInt(tIn, nIn);
	int nh = 0;
	nh = 9;

	for (int i = 0; i < nh; i++)
	{
		h[i] = 0;
	}

	for (int u = 0; u < nh; u++)
	{
		for (int i = 0; i < nIn; i++)
		{
			if (tIn[i] == u)
			{
				h[u] = h[u] + 1;
			}
		}
	}
	for (int i = 0; i < nIn; i++)
	{
		if (tIn[i] == nh)
		{
			h[nh] = h[nh] + 1;
		}
	}



}


double distanceTableauxInt(int tab1[], int nTab1, int tab2[],
	int nTab2)
{
	double Hist1[100];
	int nHist1 = 9;


	double Hist2[100];
	int nHist2 = 9;

	histoTableauInt(tab1, nTab1, Hist1);
	histoTableauInt(tab2, nTab2, Hist2);

	printf("\naffichage Histograme 1 ---------\n");
	for (int i = 0; i < nHist1; i++)
		printf("%.2lf ", Hist1[i]);
	printf("\nfin affichage Histograme 1 -----\n");

	printf("\naffichage Histograme 2 ---------\n");
	for (int i = 0; i < nHist2; i++)
		printf("%.2lf ", Hist2[i]);
	printf("\nfin affichage Histograme 2 -----\n");



	double distance = 0;

	for (int i = 0; i < 9; i++)
	{
		if (Hist1[i] <= Hist2[i])
		{
			distance = distance + Hist1[i];
		}
		else
		{
			distance = distance + Hist2[i];
		}
	}
	return distance;
}

TABLEAU_INT allocationDynamiqueInt(int n) /* Aloue la mémoire nécessaire à un tableau de taille n et l'initialise à 0 */
{
	TABLEAU_INT t = { NULL,0 };
	t.taille = n;
	t.data = (int*)calloc(n, sizeof(int));

	return(t);
}



// MATRICES

MATRICE_INT  allocationDynamiqueMatriceInt(int Nblig, int Nbcol)
{
	MATRICE_INT matrice = { NULL,0,0, };

	matrice.data = (int**)malloc(Nblig * sizeof(int*));
	if (matrice.data == NULL)
		printf("Pb allocation matrice.\n");
	else
	{
		int i;
		for (i = 0; i < Nblig; i++)
			matrice.data[i] = (int*)malloc(Nbcol * sizeof(int));
		if (matrice.data[i] == NULL)
			printf("Pb allocation ligne %d.", i);
	}
	matrice.Nblig = Nblig;
	matrice.Nbcol = Nbcol;
	return matrice;

}

MATRICE_INT initialisationAleatoireMatriceInt(int Nblig, int Nbcol, int ValMin, int ValMax)
{
	MATRICE_INT matrice = { NULL,0,0, };

	matrice = allocationDynamiqueMatriceInt(Nblig, Nbcol);

	for (int i = 0; i < Nblig; i++)
		for (int j = 0; j < Nbcol; j++)
			matrice.data[i][j] = ValMin + rand() % (ValMax + 1 - ValMin);
	return matrice;
}

void affichageMatriceInt(MATRICE_INT matrice)
{
	printf("\naffichage matrice ---------\n");
	for (int i = 0; i < matrice.Nblig; i++)
	{
		for (int j = 0; j < matrice.Nbcol; j++)
			printf("%d ", matrice.data[i][j]);
		printf("\n");
	}
	printf("\nfin affichage matrice ---------\n");


}

void liberationMatriceInt(MATRICE_INT* m)
{
	for (int i = 0; i < (*m).Nblig; i++)
	{
		free((*m).data[i]);
	}
	free((*m).data);
	(*m).data = NULL;
}

int TraceMatriceInt(MATRICE_INT matrice)
{
	int trace = 0;
	if (matrice.Nblig == matrice.Nbcol)
	{
		for (int i = 0; i < matrice.Nblig; i++)
			trace += matrice.data[i][i];
	}
	return(trace);
}

MATRICE_INT AdditionMatriceInt(MATRICE_INT M1, MATRICE_INT M2)
{
	MATRICE_INT M = { NULL,0,0, };
	M = allocationDynamiqueMatriceInt(M1.Nblig, M1.Nbcol);
	for (int i = 0; i < M1.Nblig; i++)
		for (int j = 0; j < M1.Nbcol; j++)
			M.data[i][j] = M1.data[i][j] + M2.data[i][j];
	return(M);
}

MATRICE_INT MultiplicationMatriceInt(MATRICE_INT M1, MATRICE_INT M2)
{
	MATRICE_INT M = { NULL,0,0, };
	M = allocationDynamiqueMatriceInt(M1.Nblig, M2.Nbcol);

	for (int i = 0; i < M1.Nblig; i++)
	{
		for (int j = 0; j < M2.Nbcol; j++)
		{
			int tmp = 0;

			for (int k = 0; k < M1.Nbcol; k++)
			{
				tmp = M1.data[i][k] * M2.data[k][j] + tmp;
				M.data[i][j] = tmp;
			}
		}
	}
	return(M);
}


// IMAGES

IMAGE_INT  allocationDynamiqueIMAGEInt(int Nblig, int Nbcol)
{
	IMAGE_INT img = { NULL, NULL, 0,0 };

	img.pixel = (int**)malloc(Nblig * sizeof(int*));
	img.data = (int*)calloc(Nblig * Nbcol, sizeof(int)); /*Allocation de la ligne contenant l'image entiere*/

	for (int i = 0; i < Nblig; i++)
	{
		img.pixel[i] = &img.data[i * Nbcol];
	}

	return (img);
}

void liberationIMAGEInt(IMAGE_INT* img)
{
	free((*img).data);
	(*img).data = NULL;
	free((*img).pixel);
	(*img).pixel = NULL;
}

IMAGE_INT initialisationAleatoireIMAGEInt(int Nblig, int Nbcol, int ValMin, int ValMax)
{
	IMAGE_INT img = { NULL, NULL, 0, 0 };

	img = allocationDynamiqueIMAGEInt(Nblig, Nbcol);
	img.Nblig = Nblig;
	img.Nbcol = Nbcol;

	for (int i = 0; i < Nblig; i++)
		for (int j = 0; j < Nbcol; j++)
			img.pixel[i][j] = ValMin + rand() % (ValMax + 1 - ValMin);
	return img;

}

void affichageIMAGEInt(IMAGE_INT img)
{
	printf("\naffichage image ---------\n");
	for (int i = 0; i < img.Nblig; i++)
	{
		for (int j = 0; j < img.Nbcol; j++)
		{
			printf("%d ", img.pixel[i][j]);
		}
		printf("\n");
	}
	printf("\nfin affichage image ---------\n");


}

TABLEAU_INT histogrammeIMAGEIntBits(IMAGE_INT img, int NbBits) //En nombre de bits de l'image
{
	TABLEAU_INT Hist = { NULL, 0 };


	int Vmax;
	Vmax = pow(2, NbBits) - 1;
	Hist = allocationDynamiqueInt(Vmax);
	int tmp;


	for (int i = 0; i < img.Nblig; i++)
	{
		for (int j = 0; j < img.Nbcol; j++)
		{
			Hist.data[img.pixel[i][j]] = Hist.data[img.pixel[i][j]] + 1;
		}
	}

	return(Hist);
}

TABLEAU_INT histogrammeImageInt(IMAGE_INT img, int nbBins) //Ne marche que pour des images de 0 à 255,En nombre de bins que l'on veut. C'est donc le nombre de niveaux de gris sur lequel sera définit l'hist, il est donc compresser.
{
	TABLEAU_INT Hist = { NULL, 0 };
	int pas = 256 / nbBins;
	Hist = allocationDynamiqueInt(nbBins);



	for (int i = 0; i < (img.Nblig * img.Nbcol); i++)
	{
		Hist.data[(img.data[i]) / pas] += 1;
	}

	return Hist;
}

void sauvegardeHistogrammeImageInt(TABLEAU_INT h, char* nameFile)
{
	FILE* F = NULL;

	F = fopen(nameFile, "w");

	fprintf(F, "%d \n", h.taille);

	for (int i = 0; i < h.taille; i++)
	{
		fprintf(F, "%d ; %d \n", i, h.data[i]);
	}

	fclose(F);

}


//Couleurs
void affichageCouleur(COULEUR c)
{
	printf("%s -> (%d,%d,%d)\n", c.couleur, c.R, c.G, c.B);
}

double distanceEuclidienneCouleur(COULEUR c1, COULEUR c2)
{
	double ecart = (double)(c1.R - c2.R) * (c1.R - c2.R);
	double d = ecart;

	ecart = (double)(c1.G - c2.G) * (c1.G - c2.G);
	d += ecart;

	ecart = (double)(c1.B - c2.B) * (c1.B - c2.B);
	d += ecart;

	d = sqrt(d);

	return d;
}

COULEUR lectureCouleur(void)
{
	COULEUR c = { "", 0, 0, 0 };
	printf("NON ?"); scanf("%s", &c.couleur);
	printf("R ?"); scanf("%d", &c.R);
	printf("G ?"); scanf("%d", &c.G);
	printf("B ?"); scanf("%d", &c.B);

	return c;
}

// Points
POINT lecturePoint(void)
{
	POINT pt = { 0, 0 };

	printf("Abscisse ? "); scanf("%f", &pt.abscisse);
	printf("Ordonnee ?"); scanf("%f", &pt.ordonnee);
	return(pt);
}

void affichePoint(POINT p)
{
	printf("(%.2f,%.2f)\n", p.abscisse, p.ordonnee);
}

float distancePoints(POINT p1, POINT p2)
{
	float ecart = (float)(p1.abscisse - p2.abscisse) * (p1.abscisse - p2.abscisse);
	ecart += (float)(p1.ordonnee - p2.ordonnee) * (p1.ordonnee - p2.ordonnee);
	return ((float)sqrt((double)ecart));
}

POINT millieuPoints(POINT p1, POINT p2)
{
	POINT m = { 0 ,0 };
	m.abscisse = (p1.abscisse + p2.abscisse) / 2;
	m.ordonnee = (p1.ordonnee + p1.ordonnee) / 2;

	return (m);
}

void generationAleatoirePoints(POINT t[], int n, float min, float max) /* n est le nombres d'éléments de notre tableau*/
{
	for (int i = 0; i < n; i++)
	{
		t[i].abscisse = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
		t[i].ordonnee = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
	}
}

POINT centreGravitePoint(POINT t[], int n)
{
	POINT CG = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		CG.abscisse += t[i].abscisse;
		CG.ordonnee += t[i].ordonnee;
	}
	CG.abscisse /= n;
	CG.ordonnee /= n;

	return(CG);
}

void rechercheAbscissesExtremes(POINT tab[], int n, float* absMin, float* absMax)
{
	for (int i = 0; i < n; i++)
	{
		if (tab[i].abscisse > *absMax)
		{
			*absMax = tab[i].abscisse;
		}
		if (tab[i].abscisse < *absMin)
		{
			*absMin = tab[i].abscisse;
		}
	}
}

void recherchePointsExtremes(POINT tab[], int n, POINT* ptDistMin, POINT* ptDistMax)/* recherche le point le plus proche et le plus éloigner du centre de gravité*/
{
	POINT CG = centreGravitePoint(tab, n);
	for (int i = 0; i < n; i++)
	{
		POINT pt = tab[i];
		if (distancePoints(CG, pt) < distancePoints(CG, *ptDistMin))
		{
			*ptDistMin = pt;
		}
		if (distancePoints(CG, pt) > distancePoints(CG, *ptDistMax))
		{
			*ptDistMax = pt;
		}
	}

}

// Complexes (lf:pour double; f:pour float; .2lf: limite le nombre de décimales à 2)

void afficheComplexe(COMPLEXE c)
{
	printf("(%.2lf + i * %.2lf)\n", c.Re, c.Im);
}

COMPLEXE lectureComplexe(void)
{
	double Re = 0, Im = 0;
	printf("Re:");
	scanf("%lf", &Re);
	printf("\Im:");
	scanf("%lf", &Im);
	COMPLEXE c = { Re,Im };
	return(c);
}

COMPLEXE conjugueComplexe(COMPLEXE c)
{
	c.Im = -c.Im;
	return (c);
}

double moduleComplexe(COMPLEXE c)
{
	double module = sqrt((c.Re * c.Re) + (c.Im * c.Im));
	return (module);
}

// Gestion de temps 

void decompositionTemps(int tps, int* h, int* m, int* s)
{
	*h = tps / 3600;
	*m = (tps % 3600) / 60;
	*s = ((tps % 3600) % 60);
}

void lectureTemps(int* tps)
{
	printf("Temp en sec:\n");
	scanf("%d", &(*tps));
}

// Chaines de charactères
int indicePremiereOccurence(char str[], char c)/*Détecte a quel indice est notre  caractrère c*/
{
	int i = 0;
	while ((str[i] != c) && (str[i] != '\0'))
		i = i + 1;
	if (str[i] == '\0')
		i = -1;
	return (i);
}

void insertionCaractereChaine(char str[], char c, int place)
{
	int Fdc = 0;
	while (str[Fdc] != '\0')
	{
		Fdc = Fdc + 1;
	}
	Fdc = Fdc + 1;


	for (int i = Fdc; i >= place; i--)
	{
		str[i + 1] = str[i];
	}
	str[place] = c;
}

void suppressionCaractereChaine(char str[], int place)
{
	for (int i = place; str[i] != '\0'; i++)
	{
		str[i] = str[i + 1];
	}
}

char tirageLettre(void)
{
	int Val = 0;
	Val = 0 + rand() % (25 + 1 - 0);
	Val = Val + 'a';
}

char* tirageMot(int taille)
{
	char* mot = NULL;
	mot = (char*)malloc((taille + 1) * sizeof(char));

	for (int i = 0; i < taille; i++)
	{
		mot[i] = tirageLettre();
	}
	mot[taille] = '\0';
	return (mot);
}

char* copieMot(char* mot1, int taille)

{
	char* mot2 = NULL;
	mot2 = (char*)malloc((taille + 1) * sizeof(char));

	for (int i = 0; i <= taille; i++)
	{
		mot2[i] = mot1[i];
	}

	return (mot2);
}
