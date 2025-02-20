#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   
#include <unistd.h> //Per sleep()


int game_over(char *m){
    // Controllo prima riga
    if (*(m + 0) == *(m + 1) && *(m + 0) == *(m + 2) && *(m + 0) != ' ') 
        return 1;   
    // Controllo seconda riga
    if (*(m + 3) == *(m + 4) && *(m + 3) == *(m + 5) && *(m + 3) != ' ') 
        return 1;  
    // Controllo terza riga
    if (*(m + 6) == *(m + 7) && *(m + 6) == *(m + 8) && *(m + 6) != ' ') 
        return 1; 
    // Controllo prima colonna
    if (*(m + 0) == *(m + 3) && *(m + 0) == *(m + 6) && *(m + 0) != ' ') 
        return 1; 
    // Controllo seconda colonna
    if (*(m + 1) == *(m + 4) && *(m + 1) == *(m + 7) && *(m + 1) != ' ') 
        return 1;
    // Controllo terza colonna
    if (*(m + 2) == *(m + 5) && *(m + 2) == *(m + 8) && *(m + 2) != ' ') 
        return 1;
    // Controllo diagonale principale
    if (*(m + 0) == *(m + 4) && *(m + 0) == *(m + 8) && *(m + 0) != ' ') 
        return 1;
    // Controllo diagonale secondaria
    if (*(m + 2) == *(m + 4) && *(m + 2) == *(m + 6) && *(m + 2) != ' ') 
        return 1;
    return 0;  // Nessuna vittoria
}

void print_matrix(char m[][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %c ", *(m[i]+j));
			if(j!=2) printf(" | ");
		}
		if(i!=2) printf("\n----+-----+----\n");
	}
}

 int main(){
 	
 srand(time(NULL));
 char matrix[3][3];
 int i,j;
 
 for(i=0;i<3;i++){
 	for(j=0;j<3;j++){
 		*(matrix[i]+j)=' ';
	 }
 }
 
printf("BENVENUTO AL GIOCO DEL TRIS\n\n");
for(i=0;i<3;i++){
 	for(j=0;j<3;j++){
 		printf("%d,%d", i,j);
 		if(j!=2) printf(" | ");
	 }
	 if(i!=2) printf("\n----+-----+----\n");
     
 }
  printf("\n\n\n");
 
 int mod,riga, colonna, play=0, numero_casuale;
 //(char *)matrix è un cast che forza matrix a essere trattato come un puntatore a char
 
//scelta modalità
printf("INSERISCI 0 PER GIOCARE COL BOT, 1 PER GIOCARE IN DUE\n");
 scanf("%d", &mod);
 while(mod!=0 && mod!=1){
 	printf("Errore, inserisci 0 o 1\n");
 	scanf("%d", &mod);
 }
 
switch (mod){
case 0:
 while(game_over((char *)matrix)==0) {
 	printf("Fai la tua giocata, inserendo le coordinate della casella\n");
 	scanf("%d,%d", &riga, &colonna);
 	
 	
 	//controllo che la casella sia vuota e che siano inseriti numeri da 0 a 2
 	while(riga<0 || riga>2 || colonna<0 || colonna>2 || (matrix[riga][colonna])!=' '){
 		printf("Hai inserito coordinate errate o la casella e' gia' piena, inserisci nuove coordinate\n");
 		scanf("%d,%d", &riga, &colonna);
	 }
	 
	matrix[riga][colonna]='X';
	printf("\n");
	
 	//stampa aggiornata della matrice 
 	print_matrix(matrix);

     printf("\n\n\n");
     play++;
     if(play==9) break;

     //controllo che il gioco non sia finito, se si hanno vinto le X
 	if(game_over((char *)matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! HAI VINTO :)");
 		return 0;
	 } 
 	
 	printf("Turno del bot\n");
 	numero_casuale = rand() % 3;
 	riga=numero_casuale;
 	numero_casuale = rand() % 3;
 	colonna=numero_casuale;

 	
     //controllo che la casella sia vuota 
 	while((matrix[riga][colonna])!=' '){
 	numero_casuale = rand() % 3;
 	riga=numero_casuale;
 	numero_casuale = rand() % 3;
 	colonna=numero_casuale;
	 }
	 
     sleep(2);
     
	matrix[riga][colonna]='O';
 	printf("\n");
 	
 	//stampa aggiornata della matrice
 	print_matrix(matrix); 

     printf("\n\n");
     play++;
     //controllo che il gioco non sia finito, se si hanno vinto i O
     if(game_over((char *)matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! HAI PERSO :(");
 		return 0;
	 } 
     printf("\n");
     
 }
 break;
case 1: 
//nomi giocatori
char player1[30];
char player2[30];
printf("Inserisci il nome del primo giocatore (X)\n");
scanf("%29s", player1);
printf("Inserisci il nome del primo giocatore (O)\n");
scanf("%29s", player2);


 while(game_over((char *)matrix)==0) {
 	printf("%s fai la tua giocata, inserendo le coordinate della casella\n", player1);
 	scanf("%d,%d", &riga, &colonna);
 	
 	
 	//controllo che la casella sia vuota e che siano inseriti numeri da 0 a 2
 	while(riga<0 || riga>2 || colonna<0 || colonna>2 || (matrix[riga][colonna])!=' '){
 		printf("Hai inserito coordinate errate o la casella e' gia' piena, inserisci nuove coordinate\n");
 		scanf("%d,%d", &riga, &colonna);
	 }
	 
	matrix[riga][colonna]='X';
	printf("\n");
	
 	//stampa aggiornata della matrice 
 	print_matrix(matrix);

     printf("\n\n\n");
     play++;
     if(play==9) break;

     //controllo che il gioco non sia finito, se si hanno vinto le X
 	if(game_over((char *)matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! Vincitore: %s", player1);
 		return 0;
	 } 
 	
 	printf("%s fai la tua giocata, inserendo le coordinate della casella\n", player2);
 	scanf("%d,%d", &riga, &colonna);
 	
     //controllo che la casella sia vuota e che siano inseriti numeri da 0 a 2
 	while(riga<0 || riga>2 || colonna<0 || colonna>2 || (matrix[riga][colonna])!=' '){
 		printf("Hai inserito coordinate errate o la casella e' gia' piena, inserisci nuove coordinate\n");
 		scanf("%d,%d", &riga, &colonna);
	 }
 
	matrix[riga][colonna]='O';
 	printf("\n");
 	
 	//stampa aggiornata della matrice
 	print_matrix(matrix);

     printf("\n\n");
     play++;
     //controllo che il gioco non sia finito, se si hanno vinto i O
     if(game_over((char *)matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! Vincitore: %s", player2);
 		return 0;
	 } 
     printf("\n");
     
 }
}//fine switch

 printf("\t\t\t\t\tPAREGGIO :(");
 return 0;	
 }