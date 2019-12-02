/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "scan.h"


void
scanprog_1(char *host)
{
	CLIENT *clnt;
	Stat  *result_1;
	Input_file  file_1_arg;
	int  *result_2;
	Input_dir  dir_1_arg;
	char input[256];

#ifndef	DEBUG
	clnt = clnt_create (host, SCANPROG, SCANVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("Inserisci 'f' per la funzione file_scan o 'd' per dir_scan: ");
	while(gets(input)) {
		if(input[0] == 'f'){
			printf("Inserisci il nome di un file remoto: ");
			gets(file_1_arg.file);
			result_1 = file_1(&file_1_arg, clnt);
			if (result_1 == (Stat *) NULL) {
				clnt_perror (clnt, "call failed");
			}

			if(result_1->chars == -1) {
				printf("Errore di lettura del file.\n");
			} else {
				printf("File %s:\n\tcaratteri:%d\n\tparole:%d\n\trighe:%d\n",
					file_1_arg.file, result_1->chars, result_1->words, result_1->rows);
			}
		} else if(input[0] == 'd'){
			printf("Inserisci il nome di una directory remota: ");
			gets(dir_1_arg.directory);
			printf("Inserisci un intero (num. di byte minimi): ");
			scanf("%d", &(dir_1_arg.threshold));
			result_2 = dir_1(&dir_1_arg, clnt);
			if (result_2 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}

			if(result_2 == -1) {
				printf("Errore di lettura della directory.\n");
			} else {
				printf("Directory %s:\n\tFile con dimensione>%d: %d",
					dir_1_arg.directory, dir_1_arg.threshold, *result_2);
			}
		}

		printf("Operazione terminata.\n- - - - - -\n");
		printf("Inserisci 'f' per la funzione file_scan o 'd' per dir_scan: ");
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	scanprog_1 (host);
exit (0);
}
