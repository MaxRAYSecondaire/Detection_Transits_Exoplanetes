#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct couleur {
	char couleur[20];
	int R;
	int G;
	int B;
}COULEUR;

typedef struct point {
	float abscisse;
	float ordonnee;
}POINT;

typedef struct complexe {
	double Re;
	double Im;
} COMPLEXE;

typedef struct tableau_int { /* Pour accéder à la bonne csase : t.data[i] */
	int* data;
	int taille;
}TABLEAU_INT;

typedef struct matrice_int {
	int** data;
	int Nblig;/* Nombres de lignes*/
	int Nbcol; /*Nombres de colonnes*/
} MATRICE_INT;

typedef struct image_int {
	int* data;
	int** pixel;
	int Nblig;/* Nombres de lignes*/
	int Nbcol; /*Nombres de colonnes*/

} IMAGE_INT;

int factorielle(int n);
void echange(int* pa, int* pb);
int ValeurAleatoire(int valMin, int valMax);

//Tableaux

void miseTableauAuCarre(int tIn[], int nIn, int tOut[], int nOut);

void affichageTableauInt(int t[], int n);

void initialisationAleatoireTableauInt(int t[], int n, int valMin, int valMax);

void copieTableauInt(int t1[], int t2[], int n);

int minTableauInt(int t[], int n);

int maxTableauInt(int t[], int n);

void triEchangeTableauInt(int t[], int n);

double calculTableauInt(int t[], int n);

void fusionTableauInt(int tab1[], int nTab1, int tab2[], int
	nTab2, int tabFusion[], int nTabFusion);

int medianeTableauInt(int t[], int n);

void histoTableauInt(int tIn[], int nIn, double h[]);

double distanceTableauxInt(int tab1[], int nTab1, int tab2[],
	int nTab2);

TABLEAU_INT allocationDynamiqueInt(int n);



// MATRICES :

MATRICE_INT  allocationDynamiqueMatriceInt(int Nblig, int Nbcol);

MATRICE_INT initialisationAleatoireMatriceInt(int Nblig, int Nbcol, int ValMin, int ValMax);

void affichageMatriceInt(MATRICE_INT);

void liberationMatriceInt(MATRICE_INT);

MATRICE_INT AdditionMatriceInt(MATRICE_INT M1, MATRICE_INT M2);

int TraceMatriceInt(MATRICE_INT matrice);

MATRICE_INT MultiplicationMatriceInt(MATRICE_INT M1, MATRICE_INT M2);

// IMAGES

IMAGE_INT  allocationDynamiqueIMAGEInt(int Nblig, int Nbcol);

void liberationIMAGEInt(IMAGE_INT);

IMAGE_INT initialisationAleatoireIMAGEInt(int Nblig, int Nbcol, int ValMin, int ValMax);

void affichageIMAGEInt(IMAGE_INT);

TABLEAU_INT histogrammeIMAGEIntBits(IMAGE_INT img, int NbBits);

TABLEAU_INT histogrammeImageInt(IMAGE_INT img, int nbBins);

void sauvegardeHistogrammeImageInt(TABLEAU_INT h, char* nameFile);

//Couleurs

void affichageCouleur(COULEUR c);

double distanceEuclidienneCouleur(COULEUR c1, COULEUR c2);

COULEUR lectureCouleur(void);


//Points
void affichePoint(POINT p);

float distancePoints(POINT p1, POINT p2);

void generationAleatoirePoints(POINT t[], int n, float min, float max);
void rechercheAbscissesExtremes(POINT tab[], int n, float* absMin, float* absMax);
void recherchePointsExtremes(POINT tab[], int n, POINT* ptDistMin, POINT* ptDistMax);


POINT lecturePoint(void);
POINT millieuPoints(POINT p1, POINT p2);
POINT centreGravitePoint(POINT t[], int n);


// Complexe
void afficheComplexe(COMPLEXE c);
COMPLEXE lectureComplexe(void);
COMPLEXE conjugueComplexe(COMPLEXE c);
double moduleComplexe(COMPLEXE c);

// Gestion de temps
void decompositionTemps(int tps, int* h, int* m, int* s);
void lectureTemps(int* tps);

// Chaine de charactères
int indicePremiereOccurence(char str[], char c);
void insertionCaractereChaine(char str[], char c, int place);
void suppressionCaractereChaine(char str[], int place);
char tirageLettre(void);
char* tirageMot(int taille);
char* copieMot(char* mot1, int taille);

