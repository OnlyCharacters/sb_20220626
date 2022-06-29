#include <unistd.h>
/* exec() */
#include <stdio.h>
/* fpritnf() snprintf() popen() perror() */
#include <math.h>
/* pow() */
#include <string.h>
/* strlen() strncat() memset()*/
#include <stdlib.h>
/* atoi() */
#include <sys/types.h>
#include <signal.h>
/* kill() */

#define URL_MAX_LEN 2084
#define True        1
#define False       0


int
get_url(char* uri)
{
    FILE*   fp;
    char    line_buff[BUFSIZ];
    char    buffer[BUFSIZ];
    char*   target;


    memset(uri, 0, URL_MAX_LEN);
    while (True) {
        fp = popen("/usr/bin/python3 /home/debian/victory/click2.py", "r");
        if (fp == NULL) {
            perror("popen");
            return False;
        }

        memset(buffer, 0, BUFSIZ);
        memset(line_buff, 0, BUFSIZ);
        while (fgets(line_buff, BUFSIZ, fp) != NULL) {
            strncat(buffer, line_buff, strlen(line_buff));
            memset(line_buff, 0, BUFSIZ);
        }

        if ((target = strstr(buffer, "https://")) != NULL)
            break;
        else
            sleep(2);
    }
    // fprintf(stderr, "获取成功: %s\n");
    char* nl = strchr(target, '\n');
	if (nl)
        *nl = '\0';
    memcpy(uri, target, strlen(target));

    pclose(fp);
    return True;
}

// int
// get_url(char* uri)
// {
//     char* uri_temp = "https://ibwwekdw20220629.oss-cn-shenzhen.aliyuncs.com/20220629/xjj_205100_sign.apk?OSSAccessKeyId=LTAI5t9HmPoNzsJjnV3pvaU3&Expires=1656505258&Signature=FwlLb0XBRkI3J7wfjBKZ5vVpVVg%3D";
//     snprintf(uri, URL_MAX_LEN, "%s", uri_temp);
//     return True;
// }

int
main(int argc, char** argv)
{
    pid_t child;
    char uri[URL_MAX_LEN];

    while (True) {
        if (get_url(uri) == True) {
            fprintf(stderr, "GET Valied Url: %s\n", uri);

            child = fork();

            if (child == -1) {
                perror("fork()");
                return False;
            }

            /**    Child    **/
            if (child == 0) {
                printf("Child\n");
                execl("/home/debian/victory/webBenchmark_linux_x64", "webBenchmark_linux_x64", "-c", "1", "-s", uri, (char*)0);
                printf("Excute");
            }
            /**    Parent    **/
            else {
                printf("Parent\n");
                sleep(180);
                kill(child, SIGKILL);
                fprintf(stderr, "epoch done\n");
            }
        }
        else {
            fprintf(stderr, "GET Uri Failed.\n");
            continue;
        }
    }

    return 0;
}