#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include <QInputDialog>
#include <QDebug>
#include <QMessageBox>
#include <QString>

class Client
{
protected:
    Client();
    static Client* oneinstance;
private:
    typedef struct MSG{
        int type;       /*消息的类型 1.用户注册  2.用户登录  3.用户退出  4. 在线用户查询 5.离线用户查询 6.查询cli_t  7.更新cli_t*/
        char name[30];
        char password[10];
        struct sockaddr_in addr; /*客户端的ip，客户端不发，在服务端自己设置*/
        int status;		//用户的状态
    }MSG;
    int PORT;       //需要加一个输入框来获得PORT
    MSG msg;        //和服务器传递消息
    int cli_fd;     //本机的socket的文件描述符cli_fd
    struct sockaddr_in servaddr;  //服务器地址
    int MSG_size;
    int STATUS;
public: //数据区
    const static int NOTREGISTED=999996;
    const static int LOGIN=999998;
    const static int LOGOUT=999997;
    const static int  NOTLOGIN=999995;//状态

    static Client* Getinstance();
    struct sockaddr_in cliaddr;   //本客户端的ip及端口
    char loginanme[30];
    void myclose(int fd);
    int myconnect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    void setstatus(int st);
    int init(QWidget *parent);
    int regist(char * username,char* password);
    int login(char* name,char* password);
    int logout();
    void getonlielist(char onlinename[][30],int& num);
    void getoflielist(char onlinename[][30],int& num);
    int getcli_t(char* username,char res[]);
    int setcli_t(char username[],char res[]);
    void getclitstu(struct sockaddr_in &cliiaddr,char* username);
    ~Client();
};

#endif // CLIENT_H
