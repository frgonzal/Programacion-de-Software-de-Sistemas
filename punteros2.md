# Cambio de parametros (swap)

### Swap Variables
```c
int main(){
    int a=1;
    int b=2;
    swap(&a, &b);
    printf("a=%d, b=%d\n",a,b);
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
```
### Swap Punteros
```c
void swap_ptr(int **px, int **py){
    int *temp = *px;
    *px = *py;
    *py = temp;
}
```
## Punteros a Estructuras
```c
typeder struct nodo{
    char *str;
    struct nodo *prox;
}Nodo;
```

#### version mala
```c
void eliminar(Nodo *cabeza){
    Nodo *aux = cabeza;
    cabeza = cabeza -> prox;
    free(aux);
}
```
#### version buena
h -> | | | |;
p_cabeza -> h;
p_cabeza | | | |;


```c
void eliminar(Nodo **p_cabeza){
    Nodo *cabeza = *p_cabeza;
    *p_cabeza = cabeza -> prox;
    free(cabeza);
}
```
### Agregar nodo
```c
void agregar(Nodo **p_cabeza, char *val){
    Nodo *new = malloc(sizeof(Nodo));  //espacio para el nodo
    new -> str = malloc(strlen(val)+1);//espacio para el string
    strcpy(new->str, val);             //copiar val en new->str
    new->prox = *p_cabeza;             //conectar nodos
    *p_cabeza = new;                   //asignar nuevo nodo como cabeza
    // agregar free(new->str) si se quiere eliminar un nodo agregado de esta forma
}
```
## Recursividad
```c
void elimRec(Nodo **p_cabeza, char *pal){
    Nodo *cabeza = *p_cabeza;           //puntero a la cabeza
    if (cabeza == NULL)                 //caso base
        return;
    if (!strcmp(cabeza->str, pal)){     //comparar
        *p_cabeza = cabeza->prox;       //modificar puntero original, no la copia
        elimRec(p_cabeza, pal);         //llamar a la funcion para el mismo nodo
    }else
        elimRec(&cabeza->prox, pal);    //llamar funcion para sig
}
```
#### Lista
```c
typedef struct nodo{
    int x;
    struct nodo *prox;
}Nodo;
```
```c
void mezclar(Nodo **h1, Nodo *h2){
    if(h2==NULL)
        return;
    if(h1==NULL){
        *h1 = h2;
        return;
    }
    if((*h1)->x <= h2->x)
        mezclar(&(*h1)->prox, h2);//avanzar en h1
    else{
        mezclar(&h2->prox, *h1);
        *h1 = h2;
    }

}
```
## Punteros a funciones
```c
double f(double x);

double integral(double xi, double xf, int n){
    double h = (xf-xi)/n;
    double sum = (f(xi) + f(xf))/2;
    for(int k=1; k<n; k++){
        sum += f(xi+k*n);
    }
    return sum*h;
}
```
```c
double integral2(double(*fn)(double x), double xi, double xf, int n){
    double h = (xf-xi)/n;
    double sum = ( (*fn)(xi) + (*fn)(xf) )/2;
    for(int k=1; k<n; k++){
        sum += (*fn)(xi+k*n);
    }
    return sum*h;
}
```
T fn(t1 x, t2 y,..., tn z)

T (*fn2)(t1 x, t2 y,..., tn z)
(*fn2)(x, y, x)





- https://wiki.dcc.uchile.cl/cc3301/punteros