#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "messageexc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(this->width(), this->height());    //设置不可改变窗口大小
    //去掉行号
    ui->online_member_list->verticalHeader()->setHidden(true);
    ui->offline_memeber_list->verticalHeader()->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    Client* client=Client::Getinstance();
    if(!client->logout()){
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("Logout Error!"),
                             QMessageBox::Abort);
    }
}

//刷新在线成员列表和离线成员列表
void MainWindow::on_action_triggered()
{
    Client* client=Client::Getinstance();
    char users_on[50][30];
    int num;
    client->getonlielist(users_on,num);
    //清空现有列表,比如有的可能已经下线
    ui->online_member_list->clearContents();
    for(int i=0;i<num;i++){
       bool isEmpty=ui->online_member_list
                ->findItems(QObject::tr(users_on[i]),Qt::MatchExactly).isEmpty();

        if(isEmpty){
            QTableWidgetItem* usnm=new QTableWidgetItem(QObject::tr(users_on[i]));
             ui->online_member_list->insertRow(0);
             ui->online_member_list->setItem(0,0,usnm);
        }
    }

    //更新离线成员列表
    client->getoflielist(users_on,num);
    ui->offline_memeber_list->clearContents();

    for(int i=0;i<num;i++){
        bool isEmpty=ui->offline_memeber_list
                ->findItems(QObject::tr(users_on[i]),Qt::MatchExactly).isEmpty();
        if(isEmpty){
             QTableWidgetItem* usnm=new QTableWidgetItem(QObject::tr(users_on[i]));
             ui->offline_memeber_list->insertRow(0);
             ui->offline_memeber_list->setItem(0,0,usnm);
        }
    }
}
//点击在线成员时弹出会话窗口
/**
 * 要建立会话需要建立tcp连接来完成
 * 如何完成呢？
 * 面对面完成吧，其他方法太复杂，可行性不高
 * 也就是说，需要和某一个用户建立连接的时候必须等其连接自己才行
 */
void MainWindow::on_online_member_list_itemClicked(QTableWidgetItem *item)
{
    //查询
    Client* client=Client::Getinstance();
    QString unm=item->text();
    QByteArray uba = unm.toLatin1();
    char* unm_re=uba.data();
    if(strcmp(unm_re,client->loginanme)==0){
        QMessageBox::warning(this,QObject::tr("Warning"),QObject::tr("You Can's Send Message To Youself!"),QMessageBox::Abort);
        return ;
    }
    char cli_stu[50]={0};
    client->getcli_t(unm_re,cli_stu);
//    qDebug()<<"clit_t: " <<cli_stu;
    /**
     * 创建tcp服务端 ip=this.ip,port=this.port+1;
     * 更新Server端的当前的Client端的Cli_t的状态
     * tcp服务端等待连接(accept() )
     * 当建立连接成功即可进行聊天等服务
     */


    if(strcmp(cli_stu,"0")==0){
        int clit_fd=socket(AF_INET,SOCK_STREAM,0);
        if(clit_fd<0) return;

        struct sockaddr_in cli_t_addr;
        memset(&cli_t_addr,0,sizeof(sockaddr_in));
        /******************建立ftp**************/
        cli_t_addr.sin_family=AF_INET;
        cli_t_addr.sin_port=htons(ntohs(client->cliaddr.sin_port)+1);
        cli_t_addr.sin_addr=client->cliaddr.sin_addr;
        //绑定端口 bind
        if(bind(clit_fd,(struct sockaddr*)&cli_t_addr,sizeof(struct sockaddr_in))<0)
        {
            client->myclose(clit_fd);
            return ;
        }
        int opt = 1;
          // 端口复用
        setsockopt(clit_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));

        //监听端口 listen
        if(listen(clit_fd,5)==-1) {
            client->myclose(clit_fd);
            return;
        }

        //accept();
        struct sockaddr_in clit_clientaddr;
        memset(&clit_clientaddr,0,sizeof(struct sockaddr_in));
        socklen_t addrlen_1=sizeof(sockaddr);
        /*********更新当前的server的cli_t*********/
        memset(cli_stu,0,sizeof(cli_stu));
        sprintf(cli_stu,"1");
        client->setcli_t(client->loginanme,cli_stu);
        /*****************************************/
        //这里会阻塞
        int final_fd=accept(clit_fd,
                (struct sockaddr*)&clit_clientaddr,&addrlen_1);
        if(final_fd<0) {
            client->myclose(clit_fd);
            return;
        }

        /****************发送消息等*******************/


        MessageExc m(0,final_fd,item->text());
        m.exec();

//        char message[1024];
//        memset(message,0,sizeof(message));
//        read(final_fd,message,1024);
//        qDebug() << "recive: "<< message;
//        bzero(message,sizeof(message));
//        sprintf(message,"hello client_client!!\n");
//        write(final_fd,message,strlen(message)+1);
//         qDebug() << "send: "<< message;

        /****************收尾*************************/
        client->myclose(clit_fd);
        client->myclose(final_fd);
        //更新回去
        memset(cli_stu,0,sizeof(cli_stu));
        sprintf(cli_stu,"0");
        client->setcli_t(client->loginanme,cli_stu);

        return;
    }else if(strcmp(cli_stu,"1")==0){
        int clit_fd=socket(AF_INET,SOCK_STREAM,0);
        if(clit_fd<0) return;

        struct sockaddr_in cli_t_addr;
        memset(&cli_t_addr,0,sizeof(sockaddr_in));

        client->getclitstu(cli_t_addr,unm_re);
        cli_t_addr.sin_family=AF_INET;
//        qDebug() << "fuck!! kale!";
        int opt = 1;
        setsockopt(clit_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));

//        qDebug() << "client_server:";
//        qDebug() << inet_ntoa(cli_t_addr.sin_addr);
//        qDebug() << ntohs(cli_t_addr.sin_port);
//        qDebug() << "*****end";

        if(client->myconnect(clit_fd,(struct sockaddr*)&cli_t_addr,sizeof(cli_t_addr)) < 0){
            client->myclose(clit_fd);
            return ;
        }
        /*******************聊天等操作*******************/
        MessageExc mm(0,clit_fd,item->text());
        mm.exec();

        //明天解决
//        char message[1024];
//        memset(message,0,sizeof(message));
//        sprintf(message,"hello client_server!\n");
//        write(clit_fd,message,strlen(message)+1);
//        qDebug() << "send: "<< message;
//        memset(message,0,sizeof(message));
//        read(clit_fd,message,1024);
//        qDebug() << "recive: "<< message;



        /***********************收尾*****************************/
        client->myclose(clit_fd);

        return ;
    }
    //设置
    /*
    memset(cli_stu,0,sizeof(cli_stu));
    sprintf(cli_stu,"0");
    client->setcli_t(client->loginanme,cli_stu);
    */
//    MessageExc ex;
//    ex.exec();
     return;
}
