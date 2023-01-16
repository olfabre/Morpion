#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

#include "tictactoe.h"

/* ************************************************************************ */
/* Objectif : le constructeur de la classe permettant d'initialiser T a 0   */
/* ************************************************************************ */
TicTacToe::TicTacToe()
{
  // Initalisation du tableau à zéro
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      T[i][j] = 0;
      // cout << "ligne " << i << "colonne " << j << endl;
    }
  }
  // Initialise les attributs
  pointsHUMAIN = 0;
  pointsORDINATEUR = 0;
  erreurHumain = false;
}

/* ********************************************** */
/* Objectif : méthode affichant le contenu de T   */
/* ********************************************** */
void TicTacToe::affichage(bool start)
{
  string A = "0";
  string B = "1";
  string C = "2";
  string D = "3";
  string E = "4";
  string F = "5";
  string G = "6";
  string H = "7";
  string I = "8";
  if (T[0][0] == 1)
  {
    A = "O";
  }
  else if (T[0][0] == -1)
  {
    A = "X";
  }
  //
  if (T[0][1] == 1)
  {
    B = "O";
  }
  else if (T[0][1] == -1)
  {
    B = "X";
  }
  //
  if (T[0][2] == 1)
  {
    C = "O";
  }
  else if (T[0][2] == -1)
  {
    C = "X";
  }
  //
  if (T[1][0] == 1)
  {
    D = "O";
  }
  else if (T[1][0] == -1)
  {
    D = "X";
  }
  //
  if (T[1][1] == 1)
  {
    E = "O";
  }
  else if (T[1][1] == -1)
  {
    E = "X";
  }
  //
  if (T[1][2] == 1)
  {
    F = "O";
  }
  else if (T[1][2] == -1)
  {
    F = "X";
  }
  //
  if (T[2][0] == 1)
  {
    G = "O";
  }
  else if (T[2][0] == -1)
  {
    G = "X";
  }
  //
  if (T[2][1] == 1)
  {
    H = "O";
  }
  else if (T[2][1] == -1)
  {
    H = "X";
  }
  //
  if (T[2][2] == 1)
  {
    I = "O";
  }
  else if (T[2][2] == -1)
  {
    I = "X";
  }
  cout << endl;

  system("cls");   // Windows
  system("clear"); // Linux
  cout << "+ PARTIE DE MORPION +" << endl;

  cout << endl;

  cout << endl;
  cout << endl;
  cout << "    " << A << " "
       << "|"
       << " " << B << " "
       << "|"
       << " " << C << endl;

  cout << "  "
          "----|---|----"
       << endl;

  cout << "    " << D << " "
       << "|"
       << " " << E << " "
       << "|"
       << " " << F << endl;

  cout << "  "
          "----|---|----"
       << "      X = Humain / O = Ordinateur" << endl;

  cout << "    " << G << " "
       << "|"
       << " " << H << " "
       << "|"
       << " " << I << endl;

  cout << endl;
  cout << endl;
  cout << endl;
}

/* *********************************************************** */
/* Objectif : méthode pour évaluer les coups HUMAIN            */
/* *********************************************************** */
int TicTacToe::minimax(bool humain)
{

  if (humain == true)
  {
    int best = -10;

    for (int l = 0; l < 3; l++)
    {
      for (int c = 0; c < 3; c++)
      {
        // Check if cell is empty
        if (T[l][c] == 0)
        {
          // jouer le coup
          simulation(1, l, c, false);

          best = minimax(false);
          // supprimer le coup d'avant
          simulation(1, l, c, true);
        }
      }
    }
    return best;
  }
  else
  {
    int best = 10;

    for (int l = 0; l < 3; l++)
    {
      for (int c = 0; c < 3; c++)
      {
        // Check if cell is empty
        if (T[l][c] == 0)
        {
          // jouer le coup
          simulation(0, l, c, false);

          best = minimax(true);
          // supprimer le coup d'avant
          simulation(0, l, c, true);
        }
      }
    }
    return best;
  }
}
/* *********************************************************** */
/* Objectif : méthode pour évaluer les coups ORDINATEUR        */
/* *********************************************************** */
int TicTacToe::JeuOrdi(int &bestMoveLigne, int &bestMoveColonne)
{
  int score = -2;
  int scoreActuelle;

  // bestMoveLigne = -1;
  // bestMoveColonne = -1;

  for (int l = 0; l < 3; l++)
  {
    for (int c = 0; c < 3; c++)
    {
      // Check if cell is empty
      if (T[l][c] == 0)
      {
        // jouer le coup
        simulation(0, l, c, false);

        scoreActuelle = minimax(true);

        // supprimer le coup d'avant
        simulation(0, l, c, true);

        if (scoreActuelle > score)
        {
          score = scoreActuelle;
          bestMoveLigne = l;
          bestMoveColonne = c;
        }
      }
    }
  }

  return score;
}

/* *********************************************************** */
/* Objectif : méthode pour évaluer les coups HUMAIN            */
/* *********************************************************** */
int TicTacToe::JeuHumain(int &bestMoveLigne, int &bestMoveColonne)
{
  /* Elle affecte bestMove le meilleur coup de l’humain et renvoie la valeur de
  l’etat du jeu correspondant à ce coup.*/

  return (1);
}

/* *********************************************** */
/* Objectif : méthode arbitrant l'etat du jeu      */
/* *********************************************** */
int TicTacToe::arbitre()
{
  /* Elle renvoie 1 si l'ordinateur a gagné, -1 si c'est l'humain,
  0 si le match est nul et -2 si la partie n'est pas encore finie */

  // Cas Humain
  if (T[0][0] == -1 && T[0][1] == -1 && T[0][2] == -1)
  {
    return (-1);
  }
  if (T[1][0] == -1 && T[1][1] == -1 && T[1][2] == -1)
  {
    return (-1);
  }
  if (T[2][0] == -1 && T[2][1] == -1 && T[2][2] == -1)
  {
    return (-1);
  }

  if (T[0][0] == -1 && T[1][0] == -1 && T[2][0] == -1)
  {
    return (-1);
  }
  if (T[0][1] == -1 && T[1][1] == -1 && T[2][1] == -1)
  {
    return (-1);
  }
  if (T[0][2] == -1 && T[1][2] == -1 && T[2][2] == -1)
  {
    return (-1);
  }

  if (T[0][0] == -1 && T[1][1] == -1 && T[2][2] == -1)
  {
    return (-1);
  }
  if (T[0][2] == -1 && T[1][1] == -1 && T[2][0] == -1)
  {
    return (-1);
  }

  // Cas ordinateur
  if (T[0][0] == 1 && T[0][1] == 1 && T[0][2] == 1)
  {
    return (1);
  }
  if (T[1][0] == 1 && T[1][1] == 1 && T[1][2] == 1)
  {
    return (1);
  }
  if (T[2][0] == 1 && T[2][1] == 1 && T[2][2] == 1)
  {
    return (1);
  }

  if (T[0][0] == 1 && T[1][0] == 1 && T[2][0] == 1)
  {
    return (1);
  }
  if (T[0][1] == 1 && T[1][1] == 1 && T[2][1] == 1)
  {
    return (1);
  }
  if (T[0][2] == 1 && T[1][2] == 1 && T[2][2] == 1)
  {
    return (1);
  }

  if (T[0][0] == 1 && T[1][1] == 1 && T[2][2] == 1)
  {
    return (1);
  }
  if (T[0][2] == 1 && T[1][1] == 1 && T[2][0] == 1)
  {
    return (1);
  }

  // Match null
  if (T[0][0] != 0 && T[0][1] != 0 && T[0][2] != 0 && T[1][0] != 0 && T[1][1] != 0 && T[1][2] != 0 && T[2][0] != 0 && T[2][1] != 0 && T[2][2] != 0)
  {
    return (0);
  }

  // jeu en cours...
  return (-2);
}

/* *********************************************************************************** */
/* Objectif : méthode pour connaitre qui commence une nouvelle partie ou qui a la main */
/* *********************************************************************************** */
int TicTacToe::aQuiLeTour(int playingJoueur) // méthode qui décide aléatoirement qui commence une nouvelle partie
{
  /* Elle renvoie 0 si c'est l'ordinateur, 1 si c'est l'humain */
  cout << "coucou " << playingJoueur << endl;
  if (playingJoueur == -2)
  {
    int premierJoueur;
    int aleatoire;
    srand(time(NULL));
    aleatoire = rand() % 100 + 1;
    (aleatoire % 2 == 0) ? premierJoueur = 1 : premierJoueur = 0;
    return (premierJoueur);
    // return (1);
  }

  return (playingJoueur);
}

/* *************************************************** */
/* Objectif : méthode pour valider un coup d'un joueur */
/* *************************************************** */
void TicTacToe::jouer(int playingJoueur, int caseChoix)
{
  // Humain
  if (playingJoueur == 1)
  {

    switch (caseChoix)
    {
    case 0:
      if (T[0][0] == 0)
      {
        T[0][0] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 1:
      if (T[0][1] == 0)
      {
        T[0][1] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 2:
      if (T[0][2] == 0)
      {
        T[0][2] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 3:
      if (T[1][0] == 0)
      {
        T[1][0] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 4:
      if (T[1][1] == 0)
      {
        T[1][1] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 5:
      if (T[1][2] == 0)
      {
        T[1][2] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 6:
      if (T[2][0] == 0)
      {
        T[2][0] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 7:
      if (T[2][1] == 0)
      {
        T[2][1] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    case 8:
      if (T[2][2] == 0)
      {
        T[2][2] = -1;
        erreurHumain = false;
      }
      else
      {
        erreurHumain = true;
      }
      break;
    }
  }

  // Ordinateur
  if (playingJoueur == 0)
  {
    switch (caseChoix)
    {
    case 0:
      T[0][0] = 1;

      break;
    case 1:
      T[0][1] = 1;

      break;
    case 2:
      T[0][2] = 1;

      break;
    case 3:
      T[1][0] = 1;

      break;
    case 4:
      T[1][1] = 1;

      break;
    case 5:
      T[1][2] = 1;

      break;
    case 6:
      T[2][0] = 1;

      break;
    case 7:
      T[2][1] = 1;

      break;
    case 8:
      T[2][2] = 1;

      break;
    }
  }
}

/* *************************************************** */
/* Objectif : méthode pour valider un coup d'un joueur */
/* *************************************************** */
void TicTacToe::simulation(int playingJoueur, int ligne, int colonne, bool destruction)
{
  // Humain
  if (playingJoueur == 1)
  {
    if (destruction)
    {
      T[ligne][colonne] = 0;
    }
    if (destruction == false)
    {
      T[ligne][colonne] = -1;
    }
  }

  // Ordinateur
  if (playingJoueur == 0)
  {
    if (destruction)
    {
      T[ligne][colonne] = 0;
    }
    if (destruction == false)
    {
      T[ligne][colonne] = 1;
    }
  }
}