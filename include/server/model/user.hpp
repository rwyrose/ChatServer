#ifndef USER_H
#define USER_H

#include<string>
using namespace std;

//user表的ORM类   ORM：对象关系映射表
class User
{
public:
    User(int id=-1,string name="",string pwd="",string state="offline")
    {
        this->id=id;
        this->name=name;
        this->password=pwd;
        this->state=state;
    }
    void setId(int id){this->id=id;}
    void setName(string name){this->name=name;}
    void setPwd(string password){this->password = password;}
    void setState(string state){this->state=state;}

    int getId(){return this->id;}
    string getName(){return this->name;}
    string getPwd(){return this->password;}
    string getState(){return this->state;}
protected:
    int id;
    string name;
    string password;
    string state;
};



#endif