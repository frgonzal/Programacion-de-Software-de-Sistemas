```c
//Funciones utiles
int fopen(File *fp);
int fclose(File *fp);
fread;
fwrite;
fseek;

//otras
int fprintf(File* fp, char* format, ...)
int fscanf(File* fp, char* format,...)
int feof(File* fp) => verifica EOF
int ferror(File* fp)

//punteros
stdin    -> entrada estandar
stdout   -> salida estandar
stderror -> salida estandar errores
```




```c
int fputs(char* s, File* fp);


```
```c
int fseek(File *fp, long offset, int mode);

mode = {
    SEEK_SET -> comienzo del archivo
    SEEK_CUR -> comienzo del puntero
    SEEK_END -> final del archivo
}


```
```c
//Escritura
size_t fwrite(void *ptr, size_t size, size_t nmemb, File* fp);

ej:
fwrite(buf, sizeof(char), 43, f);
```

```c
//Lectura
size_t fread(void* ptr, size_t size, size_t nmemb, File * fp);

ptr   -> donde se guarda
size  -> tamaño de bytes de un elemento
nmemb -> cantidad de bytes a leer

ej:
char buf[44];
fread(buf, sizeof(char), 43, f);

```

