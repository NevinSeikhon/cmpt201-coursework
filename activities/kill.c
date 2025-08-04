else {
  // child to send signals
  while (true) {
    sleep(2);
    printf("HEY Parent!\n");
    if (kill(getppid(), SIGINT) == -1) { // 0 == succesfully sent
        perror("unable to send signal to paren.");
        exit(EXIT_FAILURE);
    }
  }
}
