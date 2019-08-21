#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>


int main()
{
    char tmp2[4] = "Hi\n";
    mqd_t mq;
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 1024;
    mq = mq_open("/nme", O_RDWR|O_CREAT, S_IWUSR|S_IRUSR, &attr);
    if(mq < 0)
    {
        perror("mqopen");
        exit(-1);
    }
    if(mq_send(mq, tmp2, sizeof(tmp2), 1) < 0)
    {
        perror("mqsend");
        exit(-1);
    };
    mq_close(mq);
    exit(0);
}
