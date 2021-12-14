#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while (1) {
    char input[100];
    printf("Enter input to send:");
    fgets(input, 100, stdin);
    write(to_server, input, sizeof(input));


    int r = read(from_server, input, sizeof(input));
    if(r == 0) break;

    printf("Response from server: %s\n", input);
  }

}
