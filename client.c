#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Adresse IP et numéro de port du serveur
    const char *serveur_ip = "10.10.17.42"; // Remplacez par l'adresse IP du serveur
    const int serveur_port = 12345; // Remplacez par le numéro de port du serveur

    // Création du socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Erreur lors de la création du socket");
        exit(EXIT_FAILURE);
    }

    // Configuration de l'adresse du serveur
    struct sockaddr_in serveur_addr;
    serveur_addr.sin_family = AF_INET;
    serveur_addr.sin_port = htons(serveur_port);
    inet_pton(AF_INET, serveur_ip, &(serveur_addr.sin_addr));

    // Connexion au serveur
    if (connect(client_socket, (struct sockaddr*)&serveur_addr, sizeof(serveur_addr)) == -1) {
        perror("Erreur lors de la connexion au serveur");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // À faire : Utilisez le socket pour envoyer et recevoir des données

    // Fermeture du socket
    close(client_socket);

    return 0;
}

