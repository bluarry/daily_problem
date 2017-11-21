#include "client.h"

Client::Client()
{
    //初始化为未注册
    this->STATUS=Client::NOTREGISTED;
}
Client::~Client(){
    delete oneinstance;
}

//只返回一个实例
Client* Client::oneinstance=NULL;

Client* Client::Getinstance(){
    if(NULL==oneinstance){
        oneinstance=new Client;
    }
    return oneinstance;
}
 void Client::myclose(int fd){
     close(fd);
 }

/**
 * 初始化客户端所有的参数
 */
int Client::init(QWidget *parent){
    QInputDialog input;
    bool ok;
    QString input_ip=input.getText(parent,QObject::tr("Init Process"),
                                QObject::tr("Server IP Adress"),
                                 QLineEdit::Normal,"127.0.0.1",&ok);
//    qDebug()<< input_ip;
    if(!ok) return 0;
    PORT=input.getInt(parent,QObject::tr("Init Process"),
                              QObject::tr("Input Server Port (1000--100000):"),
                                12345,1000,100000,1,&ok);
//    qDebug()<< PORT;
    if(!ok) return 0;
    //开始初始化
    MSG_size=sizeof(msg);
    bzero(&msg,MSG_size);
    cli_fd=socket(AF_INET,SOCK_DGRAM,0);
    if(cli_fd<0){
        QMessageBox::warning(parent,QObject::tr("Waring"),
                             QObject::tr("socket 创建失败"),QMessageBox::Abort);
        return 0;
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=PORT;
    //QString 转为char *
    QByteArray ba = input_ip.toLatin1();
    const char* realip=ba.data();
    servaddr.sin_addr.s_addr=inet_addr(realip);

    return 1;
}
//登录
int Client::login(char* name,char* password){
    int fd=cli_fd;

    msg.type=2;

    strcpy(msg.name,name);
    strcpy(msg.password,password);

    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[1024],str[1024];
    memset(buff,0,sizeof(buff));
    sprintf(str, "登录成功\n");
    int size=recvfrom(fd,buff,1024,0,NULL,NULL);

    if(size > 0)
    {
        if(0==strcmp(str,buff))
        {
            strcpy(loginanme,msg.name);
            STATUS=LOGIN;
            memset(&cliaddr,0,sizeof(cliaddr));
            //从服务端获取当前客户端的sockaddr_in
            recvfrom(fd,&cliaddr,sizeof(cliaddr),0,NULL,NULL);
            return 1;
        }
    }

    return 0;
}
void Client::setstatus(int st){
     this->STATUS=st;
 }
//登出
int Client::logout(){
    int fd=cli_fd; //client socket 文件描述符

    //logout
    msg.type=3;
    msg.status=LOGOUT;
    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[1024],str[1024];
    memset(buff,0,sizeof(buff));
    sprintf(str, "登出成功\n");
    //等待服务端确认退出
    int size=recvfrom(fd,buff,1024,0,NULL,NULL);

    if(size > 0)
    {
        if(0==strcmp(str,buff))
        {
            STATUS=LOGOUT;
            return 1;
        }
    }
    return 0;
}
//在线成员列表
void Client::getonlielist(char onlinename[][30],int &num){
    for(int i=0;i<50;i++)
        memset(onlinename[i],0,strlen(onlinename[i]));
    num=0;
    int fd=cli_fd;

    msg.type=4;
    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[30];
    int size=-1;
    while(1){
        memset(buff,0,sizeof(buff));
        size=recvfrom(fd,buff,30,0,NULL,NULL);
        //qDebug() << size << " "<<buff;
        if(size==0) break;
        if(size>0){
             strcpy(onlinename[num++],buff);
        }
    }
}
//离线成员列表
void Client::getoflielist(char oflinename[][30],int& num){
    for(int i=0;i<50;i++)
        memset(oflinename[i],0,strlen(oflinename[i]));
    num=0;
    int fd=cli_fd;

    msg.type=5;
    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);


    char buff[30];
    int size=-1;
    while(1){
        memset(buff,0,sizeof(buff));
        size=recvfrom(fd,buff,30,0,NULL,NULL);
        if(size==0) break;
        if(size>0){
             strcpy(oflinename[num++],buff);
        }
    }
}
//注册
int Client::regist(char * username,char* password){
    int fd=cli_fd;

    msg.type=1;
    strcpy(msg.name,username);
    strcpy(msg.password,password);

    msg.status=NOTREGISTED;

    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[1024];
    char str[1024];
    memset(buff,0,sizeof(buff));
    memset(str,0,sizeof(str));

    sprintf(str,"注册成功\n");
    int size=recvfrom(fd,buff,1024,0,NULL,NULL);

    if(size>0 && strcmp(str,buff)==0)
    {
        STATUS=NOTLOGIN;
        return 1;
    }
    else
    {
        return 0;
    }
}
// 6查询 res为查询结果
int Client::getcli_t(char* username,char res[]){
    int fd=cli_fd;

    msg.type=6;
    strcpy(msg.name,username);

    //发送查询请求 username
    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[50];
    memset(buff,0,sizeof(buff));
    int size=recvfrom(fd,buff,50,0,NULL,NULL);

    if(size > 0 && (0==strcmp(buff,"0")||0==strcmp(buff,"1"))){
        strcpy(res,buff);
        return 1;
    }
    return 0;
}
//res为要设置的值
int Client::setcli_t(char username[],char res[]){
    int fd=cli_fd;

    msg.type=7;
    strcpy(msg.name,username);
    strcpy(msg.password,res);
    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    char buff[1024];
    char str[1024];
    memset(buff,0,sizeof(buff));
    memset(str,0,sizeof(str));

    sprintf(str,"设置成功\n");
    int size=recvfrom(fd,buff,1024,0,NULL,NULL);

    if(size>0 && strcmp(str,buff)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//根据username 获得相应的地址存入传入的参数里
void Client::getclitstu(struct sockaddr_in &cliiaddr,char* username){
    int fd=cli_fd;
    msg.type=8;

    strcpy(msg.name,username);

    int addrlen=sizeof(struct sockaddr);
    sendto(fd,&msg,MSG_size,0,(struct sockaddr *)&servaddr,addrlen);

    int size=recvfrom(fd,&msg,1024,0,NULL,NULL);//收回server发来的addr
    if(size>0){
        cliiaddr=msg.addr;
    }
    return;
}
int Client::myconnect(int sockfd, const struct sockaddr *addr,socklen_t addrlen){
    return connect(sockfd,addr,addrlen);
}





