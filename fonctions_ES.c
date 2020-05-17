#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitHostMem(float *Layer1_Weights_CPU,float *Layer2_Weights_CPU,float *Layer3_Weights_CPU,float *Layer4_Weights_CPU)
{
	// initial layer 1 weight
	FILE * pFile1 = fopen("lw1.wei","rb");
	if (pFile1 != NULL)
	{
	    int i;
	    for(i=0;i<156;++i)
		fread(&(Layer1_Weights_CPU[i]),sizeof(float),1,pFile1);
		fclose (pFile1);
	}

	// initial layer 2 weight
	FILE * pFile2 = fopen("lw2.wei","rb");
	if (pFile2 != NULL)
	{
		fread(Layer2_Weights_CPU,sizeof(float),7800,pFile2);
		fclose (pFile2);
	}
	// initial layer 3 weight
	FILE * pFile3 = fopen("lw3.wei","rb");
	if (pFile3 != NULL)
	{
		fread(Layer3_Weights_CPU,sizeof(float),125100,pFile3);
		fclose (pFile3);
	}
	// initial layer 4 weight
	FILE * pFile4 = fopen("lw4.wei","rb");
	if (pFile4 != NULL)
	{
		fread(Layer4_Weights_CPU,sizeof(float),1010,pFile4);
		fclose (pFile4);
	}
}

// void WEItoTXT()
// {
// 	FILE* pFile1 = fopen("lw1.wei", "rb");
// 	FILE* file = fopen("lw1.txt", "w");
// 	float buf;
// 	if (pFile1 != NULL)
// 	{
// 		int i;
// 		for(i=0;i<156;++i){
// 			fread(&buf, sizeof(float),1,pFile1);
// 			fprintf(file, "%lf\n", buf);
// 		}
// 		fclose (pFile1);
// 		fclose(file);
// 	}
//
// 	FILE* pFile2 = fopen("lw2.wei", "rb");
// 	FILE* file2 = fopen("lw2.txt", "w");
// 	float bufe;
// 	for(int j = 0; j < 7800; j++){
// 		fread(&bufe, sizeof(float),1,pFile2);
// 		fprintf(file2, "%lf\n", bufe);
// 	}
// 	fclose (pFile2);
// 	fclose(file2);
// }

const char binaire[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
const char hex[17] = "0123456789abcdef";

//Envoie les quatre bits correpondant au caractère hexadecimal h
const char* HEXtoBIN(char h){
	int i = 0;
	while(h != hex[i]) i += 1;

	return binaire[i];

}

//Permet de transformer un nombre float normé IEEE 754 écrit en hexadecimal en un nombre binaire
// -0x1.079342p-3 => 1
char* FLOATtoBIN_IEEE(float f){
	char strFloatHex[32];
	sprintf(strFloatHex, "%a", f);

	char* strFloatBin = malloc(33*sizeof(char));
	char mantisse[25];
	char signe;
	char exposant[9] = "00000000";

	//Indice du début de la mantisse
	int m = 0;

	//On determine le signe
	if(strFloatHex[0] == '-'){
		signe = '1';
		m = 5;
	}
	else{
		signe = '0';
		m = 4;
	}

	mantisse[0] = '\0';
	//Mantisse
	while(strFloatHex[m] != 'p'){
		strcat(mantisse, HEXtoBIN(strFloatHex[m]));
		m += 1;
	}

	m += 1;

	//Exposant
	int signeExp = 1;
	if(strFloatHex[m] == '-'){ //On détermine le signe de l'exposant
		signeExp = -1;
	}
	m += 1;
	int p = strFloatHex[m] - '0'; //On convertit l'exposant en entier
	p = p*signeExp;

	p = p + 127; //On retire le décalage de 127
	//On convertit l'exposant en binaire
	for(int i=7; p>0; i--)
	{
		exposant[i]=p%2 + '0';
		p=p/2;
	}

	sprintf(strFloatBin, "%c%s%s", signe, exposant, mantisse);

	return strFloatBin;
}

char* FLOATtoBIN(float f){
	int entier = f*1000000;
	char* strBin = malloc(33*sizeof(char));
	if(strBin == NULL) printf("Erreur d'allocation\n");

	char chaineBin[33] = "00000000000000000000000000000000";

	//Conversion en binaire
	int absEntier = abs(entier);
	for(int i = 31; absEntier > 0; i--){
		chaineBin[i] = absEntier%2 + '0';
		absEntier = absEntier/2;
	}

	printf("Chaine : %s\n", chaineBin);

	//Conversion en complément à 2
	if(entier < 0){
		int i = 31;
		while(chaineBin[i] != '1') i--;
		i--;
		for(int j = i; j >= 0; j--){
			if(chaineBin[j] == '0'){
				chaineBin[j] = '1';
			}
			else if(chaineBin[j] == '1'){
				chaineBin[j] = '0';
			}
		}

	}

	strBin = chaineBin;

	return strBin;
}

void WEItoCOE(char* nomWei, char* nomTxt){
	FILE* pFile = fopen(nomWei, "rb");
	FILE* file = fopen(nomTxt, "w");
	float buf;
	char* str;
	fprintf(file, ";Fichier d'initilisation de RAM pour les poids\n");
	fprintf(file, "memory_initialization_radix = 2;\n");
	fprintf(file, "memory_initialization_vector =\n");

	if(pFile != NULL){
		while(!feof(pFile)){
			fread(&buf, sizeof(float),1,pFile);
			printf("%lf\n", buf);
			str = FLOATtoBIN(buf);
			fprintf(file, "%s\n", str);
		}
	}
	fclose (pFile);
	fclose(file);
}

void readIn(float *layer1)
{
	FILE *fp;
	fp=fopen("in.neu","rb");
	if(fp)
	{
		fread(layer1,sizeof(float),29*29,fp);
		fclose(fp);
	}
}

void output(double *final)
{
	FILE *fp=0;
	fp=fopen("out.res","wb");
	if(fp)
	{
		fwrite(final,sizeof(double),10,fp);
		fclose(fp);
	}
}
