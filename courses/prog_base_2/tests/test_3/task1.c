#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

struct strings_s
{
    char *first;
    char  *second;
};
strings_t * strings_new(char * first,char * second){
    if(first == NULL || second == NULL)
        return;
    strings_t * strings =  (strings_t *)(malloc(sizeof(struct strings_s)));
    strings->first = malloc(strlen(first) * sizeof(char));
    strings->second = malloc(strlen(first) * sizeof(char));
    strcpy(strings->first,first);
    strcpy(strings->second,second);
    return strings;

}
int strings_exist(strings_t * self)
{
     if(self==NULL || self->first == NULL || self->second == NULL)
        return -1;
     int sizeFirst = strlen(self->first);
     int sizeSecond = strlen(self->second);
     if(sizeSecond > sizeFirst)
        return -1;
     int i = 0;
     int j = 0;
     int matchedSize =0;
     while(self->first[i] != '\0')
     {
         char qe = self->first[2];
         char p = self->first[i];
         char q = self->second[j];
         if(self->first[i] == '\n')
             {
                 i++;
             }
         if((self->first[i] == self->second[j]))
         {
             if(self->first[i] != '\n')
             {
                 matchedSize++;
             }
             i++;
             j++;

         }
         else
         {
             i++;
             break;
         }

     }
     if(matchedSize == sizeSecond)
        return 1;
     else
        return -1;

}
void strings_free(strings_t * self){
    self->first = malloc(5);
    free(self->first);
     self->second = malloc(5);
    free(self->second);
    free(self);
}
