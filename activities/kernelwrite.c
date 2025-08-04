int fd;

void handler(int signum) {
  close(fd);
  exit(0);
}

int main() {
  fd = open("tmp_k", O_CREAT | O_RDWR);
  if (fd == -1) {
    perror("open");
    // rest of it in docs 
