#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define TFTP_SERVER_IP "srvtpinfo1.ensea.fr"
#define TFTP_SERVER_PORT 69

struct TFTPHeader {
    short opcode; // Opération code (RRQ, ACK, DAT, etc.)
    char data[512]; // Données
};

int main() {
    // Créer un socket
    int clientSocket = socket(AF_INET, SOCK_DGRAM, );
    if (clientSocket == -1) {
        perror("Erreur lors de la création du socket");
        return 1;
    }

    // Configuration de l'adresse du serveur
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(TFTP_SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(TFTP_SERVER_IP);

    // a) Construction d'une requête en lecture (RRQ)
    struct TFTPHeader request;
    request.opcode = htons(1); // RRQ opcode
    strcpy(request.data, "test1"); // Nom du fichier

    // Envoi de la requête au serveur
    sendto(clientSocket, &request, sizeof(request), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // b) Réception d'un fichier constitué d'un seul paquet de données (DAT) et son acquittement (ACK)
    struct TFTPHeader dataPacket;
    recvfrom(clientSocket, &dataPacket, sizeof(dataPacket), 0, NULL, NULL);

    // Envoi de l'acquittement (ACK)
    struct TFTPHeader ackPacket;
    ackPacket.opcode = htons(4); // ACK opcode
    sendto(clientSocket, &ackPacket, sizeof(ackPacket), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    while (1) {
        ssize_t bytesRead = recvfrom(clientSocket, &dataPacket, sizeof(dataPacket), 0, NULL, NULL);
        sendto(clientSocket, &ackPacket, sizeof(ackPacket), 0, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

        // Vérification si c'est le dernier paquet
        if (bytesRead < sizeof(dataPacket)) {
            break;
        }
    }

// ...


    // Fermer le socket
    close(clientSocket);

    return 0;
}
