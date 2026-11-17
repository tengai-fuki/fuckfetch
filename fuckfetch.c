#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <dirent.h>
#include "fuckfetch_logos.h"
#define COL "\033[48G"

void os_fetch(){
	char line[256];
	FILE *fp;
	fp = fopen ("/etc/slackware-version", "r");
	if (fp != NULL){
	   fgets(line, sizeof(line), fp);
	   printf("os: %s", line);
	   fclose(fp);
	}
	else {
	    printf("none\n");
	}
}

void host_fetch(){

	struct utsname uname_data;
	if(uname(&uname_data) == 0){
	printf("host: %s\n", uname_data.machine);
	}
	else {
	perror("siki tuttum");
	}
}

void hostname_fetch(){

	struct utsname uname_data;
	if(uname(&uname_data) == 0){
	printf("hostname: %s\n", uname_data.nodename);
	}
	else {
	perror("siki tuttum");
	}
}

void kernel_fetch(){	
	struct utsname uname_data;
	if(uname(&uname_data) == 0){
	printf("kernel: %s\n", uname_data.release);
	}
	else {
	perror("siki tuttum");
	}
}

void uptime_fetch(){
	FILE *fp;
	double uptime_sec;
	int hi, jikan, bun, byou;
	fp = fopen("/proc/uptime", "r");
	fscanf(fp, "%lf", &uptime_sec);
	hi = ((int)uptime_sec / 86400);
	jikan = ((int)uptime_sec % 86400) / 3600;
	bun = ((int)uptime_sec % 3600 ) / 60;
	byou = (int)uptime_sec % 60;
	printf("uptime: %d days %d hours %d minutes %d seconds\n", hi, 
jikan, bun, byou);
	fclose(fp);
}

void package_fetch(){
	DIR *d;
	struct dirent *dir;
	int count = 0;
	d = opendir("/var/log/packages");
	if(d != NULL){
		while((dir = readdir(d)) != NULL)
		if(dir->d_name[0] != '.')
		count++;
		closedir(d);
		printf("packages: %d (pkgtools)\n", count);
	}
}

void shell_fetch(){
	char *shell = getenv("SHELL");
	char *slash;
	slash = strrchr(shell, '/');
	if(shell != NULL){
	printf("shell: %s\n", slash + 1);
	}
	else {
	printf("shell: %s\n", shell);	
	}
}

void cpu_fetch(){
	FILE *fp;
	char line[256];
	fp = fopen("/proc/cpuinfo", "r");
	if(fp != NULL){
		while (fgets(line, sizeof(line), fp) != NULL) {
			if (strncmp(line, "model name", 10) == 0) {
			char *colon = strchr(line, ':');
				if(colon != NULL) {
				printf("cpu: %s", colon + 2);
				break;
				}
			}
		}
		fclose(fp);
	}
}

void mem_fetch(){
	FILE *fp;
	char line[256];
	long total_kb = 0, free_kb = 0; 
	long total_mb = 0, used_mb = 0;
	fp = fopen("/proc/meminfo", "r");
	if(fp != NULL){
		while(fgets(line, sizeof(line), fp) != NULL) {
			if (strncmp(line, "MemTotal: ", 9) == 0) {
				sscanf(line + 9, "%ld", &total_kb);
			}

			if (strncmp(line, "MemFree: ", 8) == 0) {
				sscanf(line + 8, "%ld", &free_kb);
			}
		}
		fclose(fp);
	}
	total_mb = total_kb / 1024;
	used_mb = (total_kb - free_kb) / 1024;
	printf("memory: %ld mb / %ld mb\n", used_mb, total_mb);
}

int main(void) {
    print_slackware();

    printf("\033[18A");

    printf(COL); os_fetch();
    printf(COL); host_fetch();
    printf(COL); hostname_fetch();
    printf(COL); kernel_fetch();
    printf(COL); uptime_fetch();
    printf(COL); package_fetch();
    printf(COL); shell_fetch();
    printf(COL); cpu_fetch();
    printf(COL); mem_fetch();

    printf("\033[11B");
    return 0;
}

