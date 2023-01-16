#ifndef TICTACTOE__H
#define TICTACTOE__H
/* ************************************************************** */
/* Auteur : Olivier Fabre						                              */
/* TP : Morpion Algorithmes Minimiser Maximiser				            */
/* Date dernière maj : 01/01/2023       				                  */
/* ************************************************************** */

/* ************************************************************** */
/* Objectif : Classe représentant une nouvelle grille morpion     */
/* ************************************************************** */
class TicTacToe
{
public:
  int T[3][3];          // Grille du jeu morpion
  TicTacToe();          // le constructeur de la classe
  int pointsHUMAIN;     // Pour connaitre les poinst encours de l'humain (carrée magique)
  int pointsORDINATEUR; // Pour connaitre les poinst encours de l'ordinateur (carrée magique)
  bool erreurHumain;    // Recommence le coup quand l'humain valide une case déjà validée

  void affichage(bool start);
  bool vide();
  int JeuOrdi(int &bestMoveLigne, int &bestMoveColonne);   // contenant les instructions permettant d'évaluer les coups de l'ordinateur
  int JeuHumain(int &bestMoveLigne, int &bestMoveColonne); // contenant les instructions permettant d'évaluer les coups de l'humain.
  int minimax(bool humain);
  int arbitre();                                                                // méthode arbitrant l'état du jeu
  int aQuiLeTour(int playingJoueur);                                            // méthode qui décide aléatoirement qui commence une nouvelle partie et qui définie qui a la main
  void jouer(int playingJoueur, int caseChoix);                                 // méthode pour valider le choix d'un joueur
  void simulation(int playingJoueur, int ligne, int colonne, bool destruction); // méthode pour simuler le choix d'un joueur
};
#endif