//
//  main.c
//  UnixTool
//
//  Created by steveluccy on 11/28/20.
//

#include <sys/types.h>
#include <dirent.h>
#include <ourheader.h>


/// unix列出目录
int main(int argc,char *argv[]) {
    DIR *dp;
    struct dirent *dirent;
    if (argc != 2) {
        err_quit("a single argument (the directory name) is requred");
    }
    if ((dp = opendir(argv[1]))== NULL)
    {
        err_sys("can't open %s",argv[1]);
    }
    while((dirent = readdir(dp)) != NULL)
    {
        printf("%s\n",dirent->d_name);
    }
    closedir(dp);
    return 0;
}
