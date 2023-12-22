#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        // Utilisation incorrecte du programme
        write(STDERR_FILENO, "Usage: ", 7);
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, " hostname\n", 10);
        exit(EXIT_FAILURE);
    }

    // Extraction  du nom d'hôte à partir des arguments
    const char *hostname = argv[1];

    // On définit  les critères de recherche d'adresse
    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Résolution de  l'adresse IP du serveur
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0) {
        // Erreur lors de la résolution de l'adresse du serveur
        write(STDERR_FILENO, "Erreur lors de la résolution de l'adresse du serveur\n", 53);
        exit(EXIT_FAILURE);
    }

    // Parcourir les résultats et afficher les adresses IP
    for (rp = result; rp != NULL; rp = rp->ai_next) {

        struct sockaddr_in *addr = (struct sockaddr_in *)rp->ai_addr;

        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);

        // Affiche l'adresse IP
        write(STDOUT_FILENO, "Adresse IP de ", 14);
        write(STDOUT_FILENO, hostname, strlen(hostname));
        write(STDOUT_FILENO, ": ", 2);
        write(STDOUT_FILENO, ip, strlen(ip));
        write(STDOUT_FILENO, "\n", 1);
    }

    // Libérer la mémoire allouée par getaddrinfo
    freeaddrinfo(result);

    return 0;
}

