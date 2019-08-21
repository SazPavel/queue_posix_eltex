#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>

int main()
{
    char tmp[4];
    int prio, size;
    struct mq_attr attr;
    mqd_t mq;
    mq = mq_open("/nme", O_RDWR);
    if(mq < 0)
    {
        perror("mqopen");
        exit(-1);
    }
    mq_getattr(mq, &attr);
    
    size = mq_receive(mq, tmp, attr.mq_msgsize, &prio);
    if(size < 0)
    {
        perror("mqreceive");
        
    }
    printf("client %s", tmp);
    mq_close(mq);
    mq_unlink("/nme");
    exit(0);
}
