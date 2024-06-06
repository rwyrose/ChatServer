#include "offlinemessagemodel.hpp"
#include "db.h"
#include<string>
using namespace std;

// 存储用户的离线消息
void offlineMsgModel::insert(int userid, string msg)
{
    //1、组装sql语句
    char sql[1024]={0};
    sprintf(sql,"insert into offlinemessage values('%d','%s')",userid,msg.c_str());

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

// 删除用户的离线消息
void offlineMsgModel::remove(int userid)
{
    //1、组装sql语句
    char sql[1024]={0};
    sprintf(sql,"delete from offlinemessage where userid=%d",userid);

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

// 查询用户的离线消息
vector<string> offlineMsgModel::query(int userid)
{
    //1、组装sql语句
    char sql[1024]={0};
    sprintf(sql,"select message from offlinemessage where userid=%d",userid);

    MySQL mysql;
    vector<string> vec;
    if(mysql.connect())
    {
        MYSQL_RES* res = mysql.query(sql);
        if(res!=nullptr)
        {
            //把userid用户的所有离线消息放入vec中返回
            MYSQL_ROW row;
            while((row=mysql_fetch_row(res))!=nullptr)
            {
                vec.push_back(row[0]);
            }
            mysql_free_result(res);
            return vec;
        }
    }
    return vec;
}