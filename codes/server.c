#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAX_MESSAGE_LEN 819200 // Longitud máxima del mensaje
#define MAX_PENDING_CONNECTIONS 5 // Número máximo de conexiones pendientes

char* read_file(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* buffer = malloc(size + 1);
    if (buffer == NULL)
    {
        perror("Error al asignar memoria");
        return NULL;
    }
    size_t read_size = fread(buffer, 1, size, file);
    if (read_size != size)
    {
        perror("Error al leer el archivo");
        return NULL;
    }
    buffer[size] = '\0';
    fclose(file);
    return buffer;
}
char* get_username_hostname()
{
    // Obtener nombre de usuario
    char* username = getlogin();
    if (username == NULL)
    {
        perror("getlogin");
        return NULL;
    }
    // Obtener nombre del host
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0)
    {
        perror("gethostname");
        return NULL;
    }
    // Crear cadena de la forma username@hostname
    char* username_hostname;
    if (asprintf(&username_hostname, "%s@%s", username, hostname) < 0)
    {
        perror("asprintf");
        return NULL;
    }
    return username_hostname;
}
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Use: %s <port>.\n", argv[0]);
        return 7;
    }
    int port = atoi(argv[1]);
    int sock; // Socket del servidor
    struct sockaddr_in server; // Dirección del servidor
    int message_len; // Longitud del mensaje
    int client_sock; // Socket del cliente
    struct sockaddr_in client; // Dirección del cliente
    unsigned int client_len; // Longitud de la dirección del cliente
    // Crea el socket del servidor
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error al crear el socket\n");
        return 1;
    }
    // Establece la dirección del servidor
    server.sin_family = AF_INET; // Familia de direcciones
    server.sin_addr.s_addr = INADDR_ANY; // Dirección IP del servidor (cualquiera)
    server.sin_port = htons(port); // Puerto del servidor
    // Asocia el socket al puerto del servidor
    if (bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        printf("Error al asociar el socket al puerto\n");
        return 1;
    }
    // Escucha por conexiones entrantes
    listen(sock, MAX_PENDING_CONNECTIONS);
    printf("Esperando por conexiones entrantes...\n");
    int i = 0;
    system("echo $PWD > .pwd.temp");
    char pwd[50];
    strcpy(pwd, read_file(".pwd.temp"));
    char* newline3 = strchr(pwd, '\n');
    if (newline3)
    {
        *newline3 = '\0';
    }
    char pwd2[MAX_MESSAGE_LEN];
    strcpy(pwd2, pwd);
    char* newline4 = strchr(pwd2, '\n');
    if (newline4)
    {
        *newline4 = '\0';
    }
    char pmessage[MAX_MESSAGE_LEN];
    char otemp[] = ".out.temp";
    char filedirctory[MAX_MESSAGE_LEN];
    do
    {
        if (i != 0)
        {
            printf(/*"\033[32mEsperando respuesta.*/ "\n");
        }
        char message[MAX_MESSAGE_LEN];
        char message2[MAX_MESSAGE_LEN]; // Buffer para almacenar el mensaje
        memset(message, 0, MAX_MESSAGE_LEN);
        memset(message2, 0, MAX_MESSAGE_LEN);
        memset(pmessage, 0, MAX_MESSAGE_LEN);
        memset(filedirctory, 0, MAX_MESSAGE_LEN);
        // Acepta una conexión entrante
        client_len = sizeof(client);
        client_sock = accept(sock, (struct sockaddr*)&client, &client_len);
        if (client_sock < 0)
        {
            printf("Error al aceptar la conexión\n");
            return 1;
        }
        // printf("Conexión aceptada desde %s\n", inet_ntoa(client.sin_addr));
        // Recibe un mensaje del cliente
        if (recv(client_sock, message, MAX_MESSAGE_LEN, 0) < 0)
        {
            printf("Error al recibir el mensaje de %s\n", inet_ntoa(client.sin_addr));
        }
        char* newline = strchr(message, '\n');
        if (newline)
        {
            *newline = '\0';
        }
        char* newline2 = strchr(message2, '\n');
        if (newline2)
        {
            *newline2 = '\0';
        }
        printf("\033[32m%s: %s", inet_ntoa(client.sin_addr), message);
        strcat(pmessage, "cd ");
        strcat(pmessage, pwd2);
        memset(pwd2, 0, MAX_MESSAGE_LEN);
        strcat(pmessage, " && ");
        strcat(pmessage, message);
        strcat(pmessage, " > ");
        strcat(pmessage, pwd);
        strcat(pmessage, "/.out.temp 2> ");
        strcat(pmessage, pwd);
        strcat(pmessage, "/.out.temp && echo $PWD > ");
        strcat(pmessage, pwd);
        strcat(pmessage, "/.pwdd.l");
        system(pmessage);
        strcpy(pwd2, read_file(".pwdd.l"));
        // printf("\n%s",pmessage);
        // getchar();
        // printf("\n%s mrrr\n",pmessage);
        // printf("\033[32m%s: %s",  inet_ntoa(client.sin_addr),message);
        // Envía un mensaje al cliente
        // printf("\033[32mIngrese mensaje: ");
        strcat(filedirctory, pwd);
        strcpy(filedirctory, otemp);
        strcpy(message2, read_file(filedirctory));
        // fgets(message2, MAX_MESSAGE_LEN, stdin);
        strcat(message2, get_username_hostname());
        strcat(message2, " | ");
        char* newline4 = strchr(pwd2, '\n');
        if (newline4)
        {
            *newline4 = '\0';
        }
        strcat(message2, pwd2);
        strcat(message2, " $ ");
        message_len = strlen(message2);
        if (send(client_sock, message2, message_len, 0) < 0)
        {
            printf("Error al enviar el mensaje\n");
            return 1;
        }
        // printf("Mensaje enviado\n");
        i = 1;
    } while (1);
    // Cierra el socket del cliente
    close(client_sock);
    // Cierra el socket del servidor
    close(sock);
    return 0;
}
