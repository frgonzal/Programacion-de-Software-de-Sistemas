typedef struct nodo {
    char *val;
    struct nodo *izq, *der;
} Nodo;


Nodo *buscar(Nodo *a, char *val, char p){

    if(a==NULL)
        return NULL;

    if (srtcmp(a-> val, val)==0)    
        return a

    if(p == 1){
        Nodo *rizq = buscar(a->izq, val, 1); 
        if(rizq != NULL)
            return rizq;
        else
            return buscar(a->der, val, 1);
    }else{
        // pipe 
        int fds[2];
        pipe(fds);
        // id
        pid_t pid = fork();

        if(pid == 0){// El hijo
            close(fds[0]);
            Nodo *rizq = buscar(a->izq, val, p/2);  
            write(fds[1], &rizq, sizeof(rizq));
            exit(0);
            return NULL;

        }else{//El Padre
            close(fds[1]);
            Nodo *rder = buscar(a->der, val, p-p/2);  
            Nodo *rizq;
            read(fds[0], &rizq, sizeof(rizq));

            close(fds[0]); 
            waitpid(pid, NULL, 0);
            
            return rizq!=NULL ? rizq : rder;
        }
    }
}






