#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   
#include <unistd.h> //Per sleep()


int game_over(char m[][3]) {
    for (int i = 0; i < 3; i++) {
        // Controllo righe e colonne
        if ((m[i][0] == m[i][1] && m[i][0] == m[i][2] && m[i][0] != ' ') ||
            (m[0][i] == m[1][i] && m[0][i] == m[2][i] && m[0][i] != ' '))
            return 1;
    }
    // Controllo diagonali
    if ((m[0][0] == m[1][1] && m[0][0] == m[2][2] && m[0][0] != ' ') ||
        (m[0][2] == m[1][1] && m[0][2] == m[2][0] && m[0][2] != ' '))
        return 1;

    return 0;  // Nessuna vittoria
}

void bot_medium(char m[][3]){//cerca di evitare il tris dell'avversario
	int i, j;
    // Controlla righe
    for (i=0; i<3; i++){
        if(m[i][0]=='X' && m[i][1]=='X' && m[i][2]==' ') { m[i][2]='O'; return; }
        if(m[i][0]=='X' && m[i][2]=='X' && m[i][1]==' ') { m[i][1]='O'; return; }
        if(m[i][1]=='X' && m[i][2]=='X' && m[i][0]==' ') { m[i][0]='O'; return; }
    }

	//controlla colonne
	for(j=0; j<3;j++){
    if(m[0][j]=='X' && m[1][j]=='X' && m[2][j]==' ') { m[2][j]='O'; return; }
	if(m[0][j]=='X' && m[2][j]=='X' && m[1][j]==' ') { m[1][j]='O'; return; }
	if(m[1][j]=='X' && m[2][j]=='X' && m[0][j]==' ') { m[0][j]='O'; return; }
	}
	// Controlla diagonale principale
    if (m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == ' ') { m[2][2] = 'O'; return; }
    if (m[0][0] == 'X' && m[2][2] == 'X' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'X' && m[2][2] == 'X' && m[0][0] == ' ') { m[0][0] = 'O'; return; }

    // Controlla diagonale secondaria
    if (m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == ' ') { m[2][0] = 'O'; return; }
    if (m[0][2] == 'X' && m[2][0] == 'X' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'X' && m[2][0] == 'X' && m[0][2] == ' ') { m[0][2] = 'O'; return; }

    // Se nessun blocco è necessario, scegli una casella casuale
    int riga, colonna;
    do {
        riga = rand() % 3;
        colonna = rand() % 3;
    } while (m[riga][colonna] != ' '); // Assicura che la casella sia vuota

    m[riga][colonna] = 'O';
}

void bot_hard(char m[][3]){ //prova a fare tris ed evita il tris dell'avversario
	int i, j;
	//prova a fare tris
    // Controlla righe
    for (i=0; i<3; i++){
        if(m[i][0]=='O' && m[i][1]=='O' && m[i][2]==' ') { m[i][2]='O'; return; }
        if(m[i][0]=='O' && m[i][2]=='O' && m[i][1]==' ') { m[i][1]='O'; return; }
        if(m[i][1]=='O' && m[i][2]=='O' && m[i][0]==' ') { m[i][0]='O'; return; }
    }

	//controlla colonne
	for(j=0; j<3;j++){
    if(m[0][j]=='O' && m[1][j]=='O' && m[2][j]==' ') { m[2][j]='O'; return; }
	if(m[0][j]=='O' && m[2][j]=='O' && m[1][j]==' ') { m[1][j]='O'; return; }
	if(m[1][j]=='O' && m[2][j]=='O' && m[0][j]==' ') { m[0][j]='O'; return; }
	}
	// Controlla diagonale principale
    if (m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == ' ') { m[2][2] = 'O'; return; }
    if (m[0][0] == 'O' && m[2][2] == 'O' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'O' && m[2][2] == 'O' && m[0][0] == ' ') { m[0][0] = 'O'; return; }

    // Controlla diagonale secondaria
    if (m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == ' ') { m[2][0] = 'O'; return; }
    if (m[0][2] == 'O' && m[2][0] == 'O' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'O' && m[2][0] == 'O' && m[0][2] == ' ') { m[0][2] = 'O'; return; }

    //evita il tris dell'avversario
	for (i=0; i<3; i++){
        if(m[i][0]=='X' && m[i][1]=='X' && m[i][2]==' ') { m[i][2]='O'; return; }
        if(m[i][0]=='X' && m[i][2]=='X' && m[i][1]==' ') { m[i][1]='O'; return; }
        if(m[i][1]=='X' && m[i][2]=='X' && m[i][0]==' ') { m[i][0]='O'; return; }
    }

	//controlla colonne
	for(j=0; j<3;j++){
    if(m[0][j]=='X' && m[1][j]=='X' && m[2][j]==' ') { m[2][j]='O'; return; }
	if(m[0][j]=='X' && m[2][j]=='X' && m[1][j]==' ') { m[1][j]='O'; return; }
	if(m[1][j]=='X' && m[2][j]=='X' && m[0][j]==' ') { m[0][j]='O'; return; }
	}
	// Controlla diagonale principale
    if (m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == ' ') { m[2][2] = 'O'; return; }
    if (m[0][0] == 'X' && m[2][2] == 'X' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'X' && m[2][2] == 'X' && m[0][0] == ' ') { m[0][0] = 'O'; return; }

    // Controlla diagonale secondaria
    if (m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == ' ') { m[2][0] = 'O'; return; }
    if (m[0][2] == 'X' && m[2][0] == 'X' && m[1][1] == ' ') { m[1][1] = 'O'; return; }
    if (m[1][1] == 'X' && m[2][0] == 'X' && m[0][2] == ' ') { m[0][2] = 'O'; return; }

    // Se nessun blocco è necessario, scegli una casella casuale
    int riga, colonna;
    do {
        riga = rand() % 3;
        colonna = rand() % 3;
    } while (m[riga][colonna] != ' '); // Assicura che la casella sia vuota

    m[riga][colonna] = 'O';
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
//scelta modalità
printf("INSERISCI 0 PER GIOCARE COL BOT, 1 PER GIOCARE IN DUE\n");
 scanf("%d", &mod);
 while(mod!=0 && mod!=1){
 	printf("Errore, inserisci 0 o 1\n");
 	scanf("%d", &mod);
 }
 
switch (mod){
case 0:
//scelta difficoltà
 char diff;
 printf("Inserisci 'm' per giocare a difficolta' media, oppure 'h' per una difficolta' maggiore\n");
 scanf(" %c", &diff);
 while(diff!='m' && diff!='h'){
	printf("Carattere non valido, riprova\n");
	scanf(" %c", &diff);
 }

 while(game_over(matrix)==0) { //la funzione game_over restituisce 1 quando avviene un tris
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
 	if(game_over(matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! HAI VINTO :)");
 		return 0;
	 } 
 	
 	printf("Turno del bot\n");
 	
	if(diff=='m') bot_medium(matrix);
	else bot_hard(matrix);
	 
     sleep(2);

 	printf("\n");
 	
 	//stampa aggiornata della matrice
 	print_matrix(matrix); 

     printf("\n\n");
     play++;
     //controllo che il gioco non sia finito, se si hanno vinto i O
     if(game_over(matrix)==1){
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
printf("Inserisci il nome del secondo giocatore (O)\n");
scanf("%29s", player2);


 while(game_over(matrix)==0) {
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
 	if(game_over(matrix)==1){
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
     if(game_over(matrix)==1){
 		printf("\n\t\t\t\tTRIS!!! Vincitore: %s", player2);
 		return 0;
	 } 
     printf("\n");
     
 }
}//fine switch

 printf("\t\t\t\t\tPAREGGIO :(");
 return 0;	
 }