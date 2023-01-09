#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAX_MESSAGE_LEN 819200 // Longitud máxima del mensaje

int main(int argc, char* argv[])
{

    if (argc != 3)
    {
        printf("Use: %s <ip> <port>.\n", argv[0]);
        return 7;
    }
    int port = atoi(argv[2]);
    int sock; // Socket del cliente
    struct sockaddr_in server; // Dirección del servidor
    int message_len; // Longitud del mensaje
    printf("");
    // Crea el socket del cliente
    int i = 0;
    do
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
            printf("\033[31mError al crear el socket\033[0m\n");
            return 1;
        }

        // Establece la dirección del servidor
        server.sin_addr.s_addr = inet_addr(argv[1]); // Dirección IP del servidor
        server.sin_family = AF_INET; // Familia de direcciones
        server.sin_port = htons(port); // Puerto del servidor

        // Conecta el socket al servidor
        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
        {
            printf("\033[31mError al conectar con el servidor\033[0m\n");
            return 1;
        }

        if (i == 0)
        {
            printf("\033[32mConectado al servidor\033[0m\n");
        }
        char message[MAX_MESSAGE_LEN]; // Buffer para almacenar el mensaje
        char message2[MAX_MESSAGE_LEN];
        memset(message, 0, MAX_MESSAGE_LEN);
        memset(message2, 0, MAX_MESSAGE_LEN);
        // Envía un mensaje al servidor
        if (i == 0)
        {
            strcpy(message, "echo \"\" >> .IniciandoConexion");
            // printf("\n\033[32m$ ");
        }
        else
        {
            fgets(message, MAX_MESSAGE_LEN, stdin);
        }
        message_len = strlen(message);

        if (send(sock, message, message_len, 0) < 0)
        {
            printf("\033[31mError al enviar el mensaje\033[0m\n");
            return 1;
        }

        // printf("\033[32mEsperando respuesta.\n");

        // Recibe un mensaje del servidor
        if (recv(sock, message2, MAX_MESSAGE_LEN, 0) < 0)
        {
            printf("\033[31mError al recibir el mensaje\033[0m\n");
            return 1;
        }

        printf("\033[32m%s\033[0m", message2);
        i = 1;
        close(sock);
    } while (1);
    // Cierra el socket

    return 0;
}
