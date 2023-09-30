```c
int main(int argc, char *agrv[]){
    if(argc!=3){
        fprintf(stderr,"uso %s <nom_dic><llave>\n",argv[0]);
        exit(1);
    }
    int tamlinea = 101;
    char *filename = argv[1];
    char *llave = argv[2];
    int tamllave = strlen(llave);
    FILE *fp = fopen(filename, "r");

    if(fp==NULL){
        perror(filename);
        exit(2);
    }
    fseek(fp,0,SEEK_END);
    int tomArch = ftell(fp);
    int cantDef = tamArch
    int i=0, j=contDef-1;
    char buf[tamLinea+1];

    //busqueda binaria
    while(i<=j){
        int k=(i+j+1)/2;
        if(fseek(fp, k*tamLinea, SEEK_SET) < 0){
            perror(filename);
            exit(3);
        }
        if(fread(buf, sizeof(char),tamLinea,fp) != tamLinea){
            perror(filename);
            exit(4);
        }
        buf[tamLinea] = 0;
        int rc = strncomp(llave, buf, tamlalve);
        if(rc==0){
            break;
        }else if(rc<0){
            j = k-1;
        }else{
            i = K+1;
        }
    }
    if(i>j){
        printf("llave %s no encontrada\n", llave);
    }else{
        printf("valor (%s): %s",llave, buf+20);
    }
    return 0;
}

```