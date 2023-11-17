int suma(double x0, double dx, int n, double *pres) {
    double s= 0;

    int fds[2];
    pipe(fds);
    pid_t pid = fork();

    if(pid == 0){
        close(fds[0]);
        for(int k=0; k<n; k++){
            double gx= g(x0+dx*k);
            write(fds[1], &gx, sizeof(gx));
        }
        exit(0);
    }else{
        close(fds[1]);
        for(int k=0; k<n; k++){
            double gx;
            read(fds[0], &gx, sizeof(gx));  // read espera a que se escriba algo
            s += f(gx);
        }
        close(fds[0]);
        waitpid(pid, NULL, 0);
    }

    /*
    for (int k= 0; k<n; k++)
        s+= f(g(x0+dx*k));
    */

    *pres= s;
    return 0;
}




