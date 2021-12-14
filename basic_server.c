#include "pipe_networking.h"

void revstr(char *str1);
int main() {

  int to_client;
  int from_client;

  //from_client = server_handshake( &to_client );

  while(1) {
    //handshake
    from_client = server_handshake( &to_client );

    while(1) {
      char input[100];
      int r = read(from_client, input, sizeof(input));
      if (r == 0) break;

      //process
      input[strlen(input)-1] = '\0';
      strcat(input, "manipulated");

      write(to_client, input, sizeof(input));
    }
  }
}
