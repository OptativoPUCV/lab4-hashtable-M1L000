#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

long resuelve(HashMap *map, int posicion, char *key)
{
   for(long i = 0; i < map->capacity;i++)
     {
       if(is_equal(key,map->buckets[i]->key)==1) return -1;
     }
  for(long j = 0; j < map->capacity;j++)
    {
      if(map->buckets[j] == NULL) return j;
    }
  return -1;
}


void insertMap(HashMap * map, char * key, void * value) {
    if(map==NULL || strcmp(key==NULL) return;
    long indice = hash(key,map->capacity);
    if(map->buckets[indice] == NULL)
    {
      map->buckets[indice] = createPair(key, value);
      (map->size)++;
      (map->current) = indice;
    }
    else
    {
      long nuevo = resuelve(map,indice,key);
      if(nuevo != -1)  
      {  map->buckets[nuevo] = createPair(key,value);
        (map->size)++;
        (map->current) = nuevo;
      }
    }

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) 
{
    HashMap * map = (HashMap *)malloc(sizeof(HashMap));
    map->buckets = (Pair **)calloc(capacity, sizeof(Pair *));
    map->capacity = capacity;
    map->size = 0;
    map->current = -1;
    return map;
    
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
