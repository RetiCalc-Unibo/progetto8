/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "scan.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

Stat *
file_scan_1_svc(Input_file *argp, struct svc_req *rqstp)
{
	static Stat  result;
    FILE *fp;
    char c, prec = EOF;

    result.chars = 0;
    result.words = 0;
    result.rows = 0;

    fp = fopen(argp->file, "rt");

	if (fp != NULL) { // Apertura ok
		while ((c = fgetc(fp)) != EOF) {
            result.chars += 1;
            if(c == '\n') result.rows += 1;
            if(c == ' ' && prec != '\n' && prec != ' ') result.words += 1;
            prec = c;
		}
		fclose(fp);
	} else {
        result.chars = -1;
        result.words = -1;
        result.rows = -1;
    }

	return &result;
}

int *
dir_scan_1_svc(Input_dir *argp, struct svc_req *rqstp)
{
	static int  result;

    DIR *dir;
    int fd;
    struct stat path_stat;
    result = 0;

	if((dir = opendir(argp->directory)) != NULL){
		while((ent = readdir(dir)) != NULL){
		    if(ent->d_name[0] == '.'){
				if(ent->d_name[1] == '.')
					if(ent->d_name[2] == '\0'){
						continue;
            		}
				if(ent->d_name[1] == '\0'){
					continue;
				}
			}

			stat(ent->d_name, &path_stat);
            if(S_ISREG(path_stat.st_mode) == 0) {
                fd = open(ent->d_name, O_RDONLY);
                if(fd != -1) {
                    if(lseek(fd, 0, SEEK_END) > argp->threshold)
                        result++;
                    close(fd);
                }
            }
		}
	    closedir(dir);
        printf("files (dim>%db): %d\n", argp->threshold, result);
	} else {
		perror("diropen");
	}

	return &result;
}
