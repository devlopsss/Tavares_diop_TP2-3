#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// fonction pour le client TFTP de telechargement
void gettftp(char *host, char *file) {
    // Logique pour télécharger le fichier depuis le serveur TFTP
    write(STDOUT_FILENO, "Client TFTP pour télécharger le fichier depuis le serveur TFTP.\n", 65);
    // Pour l'intant on n'ajoute pas le corps de la fonction. On le fera dans les questions suivantes
}

// fonction pour le client TFTP de televersement
void puttftp(char *host, char *file) {
    // Meme chose que pour la fontion gettftp
    write(STDOUT_FILENO, "Client TFTP pour téléverser le fichier vers le serveur TFTP.\n", 63);

}

int main(int argc, char *argv[]) {
    // Vérifier le nombre d'arguments
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: <program_name> <host> <file>\n", 36);
        exit(EXIT_FAILURE);
    }

    // On recupere les informations de requête depuis la ligne de commande
    char *host = argv[1];
    char *file = argv[2];

    //On appele la fonction appropriée en fonction du nom du programme
    if (strcmp(argv[0], "gettftp") == 0) {
        gettftp(host, file);
    } else if (strcmp(argv[0], "puttftp") == 0) {
        puttftp(host, file);
    } else {
        write(STDERR_FILENO, "Programme inconnu\n", 18);
        exit(EXIT_FAILURE);
    }

    return 0;
}
//L appel de la fonction ne renvoi rien puisqu'on n'a pas donne de corps aux fonctions.