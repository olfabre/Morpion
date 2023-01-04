///     ___  _ _       _             _____     _
///    / _ \| (_)_   _(_) ___ _ __  |  ___|_ _| |__  _ __ ___
///   | | | | | \ \ / / |/ _ \ '__| | |_ / _` | '_ \| '__/ _ \
///   | |_| | | |\ V /| |  __/ |    |  _| (_| | |_) | | |  __/
///    \___/|_|_| \_/ |_|\___|_|    |_|  \__,_|_.__/|_|  \___|
///
///               _ _____ _   ___  __   ____
///              | | ____| | | \ \/ /  / ___| _     _
///           _  | |  _| | | | |\  /  | |   _| |_ _| |_
///          | |_| | |___| |_| |/  \  | |__|_   _|_   _|
///           \___/|_____|\___//_/\_\  \____||_|   |_|
///
///
#include <iostream>

using namespace std;

#include "tictactoe.h"

/* ********************************************** */
/* Programme principal				                    */
/* ********************************************** */
int main()
{
  bool startJeu = true;
  bool stopJeu = false;
  bool quitJeu = false;
  char reponse;
  int playingJoueur = -2;
  int caseJoueur;
  int bestMove;
  do
  {

    // Initialisation objet pour une nouvelle grilleet partie de morpion
    TicTacToe *maPartie;        // Création d'un pointeur qui pointera sur un objet de type TicTacToe
    maPartie = new TicTacToe(); // Création d'une nouvelle instance d'objet.

    // INTRO JEU /////

    // Affichage grille
    maPartie->affichage(startJeu);

    // Qui démarre?
    playingJoueur = maPartie->aQuiLeTour(playingJoueur);

    // Fin de l'intro jeu
    startJeu = false;

    // Debut Boucle de jeu //
    do
    {

      // VERIF: Si la partie est finie ///////////////////////
      if ((maPartie->arbitre() == 1) || (maPartie->arbitre() == -1) || (maPartie->arbitre() == 0))
      {
        if (maPartie->arbitre() == 1)
        {
          cout << "L'ordinateur a GAGNÉ!!!" << endl;
        }
        if (maPartie->arbitre() == -1)
        {
          cout << "Vous avez GAGNÉ!!!" << endl;
        }
        if (maPartie->arbitre() == 0)
        {
          cout << "Match Nul!!!" << endl;
        }
        // Fin de la partie
        stopJeu = true;
      }
      else
      {

        // Si la partie continue ///////////////////////
        if (playingJoueur == 0)
        {
          playingJoueur = 1;
        }
        else
        {
          playingJoueur = 0;
        }

        // JOUEUR HUMAIN

        if (playingJoueur == 1)
        {
          // Cas 1: au tour de l'humain à jouer
          cout << "> A vous maintenant! Quelle case jouez-vous? [0-1-2-3-4-5-6-7-8]" << endl;
          cout << "> ";
          cin >> caseJoueur;
          // C'est l'humain qui joue actuellement
          maPartie->jouer(playingJoueur, caseJoueur); // Valider le coup
        }

        // JOUEUR ORDINATEUR

        if (playingJoueur == 0 && maPartie->erreurHumain == false)
        {
          // Cas 2: au tour de l'ordinateur à jouer
          // Intelligence IA
          maPartie->JeuOrdi(bestMove);
        }

        // Fin du coup
        maPartie->affichage(startJeu);
        cout << "numero joueur: " << playingJoueur << endl;
      }

      // Partie finie
    } while (stopJeu == false);
    cout << "> Souhaitez-vous refaire une partie ? (O/N): ";
    cin >> reponse;
    if (reponse == 'o' || reponse == 'O')
    {
      delete maPartie;
      maPartie = new TicTacToe();
      startJeu = true;
      stopJeu = false;
      quitJeu = false;
      playingJoueur = -2;
    }
    else
    {
      quitJeu = true;
    }

    // On quitte le jeu
  } while (quitJeu == false);
  // Fin du programme prinicpal
  // delete (maPartie);
  return (1);
}