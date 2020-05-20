#include <stdio.h>
#include <stdlib.h>

#define NOM_FICHIER "lw2.txt"
#define BRAM1 "BRAM_1.txt"
#define BRAM1 "BRAM_2.txt"
#define BRAM1 "BRAM_3.txt"
#define BRAM1 "BRAM_4.txt"
#define BRAM1 "BRAM_5.txt"
#define BRAM1 "BRAM_6.txt"
#define BRAM1 "BRAM_7.txt"
#define BRAM1 "BRAM_8.txt"
#define BRAM1 "BRAM_10.txt"
#define BRAM1 "BRAM_9.txt"
#define BRAM1 "BRAM_11.txt"
#define BRAM1 "BRAM_12.txt"
#define BRAM1 "BRAM_13.txt"
#define BRAM1 "BRAM_14.txt"
#define BRAM1 "BRAM_15.txt"

#define ECRITURE "r"

char number[32]; //stockage du nombre binaire en complement a 2
char c[10]; //lecture d'un weight dans lx2.txt
int bram; //bram a utiliser

FILE * bram1;
FILE * bram2;
FILE * bram3;
FILE * bram4;
FILE * bram5;
FILE * bram6;
FILE * bram7;
FILE * bram8;
FILE * bram9;
FILE * bram10;
FILE * bram11;
FILE * bram12;
FILE * bram13;
FILE * bram14;
FILE * bram15;

int main(){
  bram = 1;
  FILE * pfile;
  if((pfile = fopen(NOM_FICHIER, "r")) == NULL){
    printf("open failed\n");
    exit(1);
  }

  open_files()

  while(!feof(pfile)){
    fscanf(pfile, "%[^\n]", c); //on lit une ligne
    converttion_decimal2binaire_viruglefixe();
    write_bram_data();
  }
  close_files();
}

void converttion_decimal2binaire_viruglefixe(){
  int add = 0x0001;
  float temp = atof(c);
  int i = (int)(temp * 100000.0) //18 bits complément à 2 impliquent de ne garder que 5 chiffres après la virgule
  i = ~i; //on inverse les bits
  i = i + add; //i est en complement à 2 en ajoutant 1
  itoa(i, number, 2); //ecriture de i dans le buffer number en base 2
}

void write_bram_data(){
  FILE * temp;
  switch(bram){
    case 1 :
      temp = bram1;
      break;
    case 2 :
      temp = bram2;
      break;
    case 3 :
      temp = bram3;
      break;
    case 4 :
      temp = bram4;
      break;
    case 5 :
      temp = bram5;
      break;
    case 6 :
      temp = bram6;
      break;
    case 7 :
      temp = bram7;
      break;
    case 8 :
      temp = bram8;
      break;
    case 9 :
      temp = bram9;
      break;
    case 10 :
      temp = bram10;
      break;
    case 11 :
      temp = bram11;
      break;
    case 12 :
      temp = bram12;
      break;
    case 13 :
      temp = bram13;
      break;
    case 14 :
      temp = bram14;
      break;
    case 15 :
      temp = bram15;
      break;
    default :
      break;
  }

  fprintf(temp, "%s\n", number);
  if(bram == 15)
    bram = 1;
  else
    bram++;
}


void open_files(){
  if((bram1 = fopen(BRAM1, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram2 = fopen(BRAM2, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram3 = fopen(BRAM3, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram4 = fopen(BRAM4, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram5 = fopen(BRAM5, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram6 = fopen(BRAM6, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram7 = fopen(BRAM7, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram8 = fopen(BRAM8, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram9 = fopen(BRAM9, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram10 = fopen(BRAM10, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram11 = fopen(BRAM11, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram12 = fopen(BRAM12, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram13 = fopen(BRAM13, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram14 = fopen(BRAM14, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
  if((bram15 = fopen(BRAM15, ECRITURE)) == NULL){
    printf("open failed\n");
    exit(1);
  }
}

void close_files(){
  fclose(bram1);
  fclose(bram2);
  fclose(bram3);
  fclose(bram4);
  fclose(bram5);
  fclose(bram6);
  fclose(bram7);
  fclose(bram8);
  fclose(bram9);
  fclose(bram10);
  fclose(bram11);
  fclose(bram12);
  fclose(bram13);
  fclose(bram14);
  fclose(bram15);
}
