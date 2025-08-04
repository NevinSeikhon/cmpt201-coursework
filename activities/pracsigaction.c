

char *message = "CTRL-C pressed";
sig_hander(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction act;
  act.sa_handler = sig_hander;
  act.sa_flags = 0;
  act.sa_mask = sigemptyset(&act.sa_mask);

  int ret = sigaction(SIGINT, &act, NULL);
  if (ret == -1) {
    perror("sigaction() failed\n");
    exit(EXIT_FAILURE);
  } else {

    while (true) {
      sleep(1);
    }
