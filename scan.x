/* 
 * scan.x
 *	+definizione strutture Input_file, Input_dir e Stat, definizione Metodi.
 * 	+rpcgen scan.x --> genera i seguenti file
 *		- scan.h --> libreria da includere in scan_proc.c
 *					e scan_client.c.
 *		- scan_xdr.c --> routine di conversione.
 * 		- scan_clnt.c; scan_svc.c --> stub C e S.
 */

struct Input_file{
    string file <50>;
};

struct Input_dir{
    string directory <50>;
    int threshold;
};

struct Stat{
    int chars;
    int words;
    int rows;
};

program SCANPROG {
	version SCANVERS {
		Stat FILE(Input_file) = 1;
		int DIR(Input_dir) = 2;
	} = 1;
} = 0x20000013;


