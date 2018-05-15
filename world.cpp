#include "world.h"
#include "icon.h"
#include <iostream>
#include <QTime>
#include <QTimer>
using namespace std;

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(8);
    this->_player.setPosY(8);
//tree
    RPGObj objt;
    int i;
    for(i=2;i<=23;i=i+2)
    {
        objt.initObj("tree");
        objt.setPosX(i);
        objt.setPosY(2);
        this->_objs.push_back(objt);
    }
    for(i=4;i<=16;i=i+2)
    {
        objt.initObj("tree");
        objt.setPosX(2);
        objt.setPosY(i);
        this->_objs.push_back(objt);
    }
    for(i=4;i<=16;i=i+2)
    {
        objt.initObj("tree");
        objt.setPosX(22);
        objt.setPosY(i);
        this->_objs.push_back(objt);
    }
    for(i=4;i<=20;i=i+2)
    {
        objt.initObj("tree");
        objt.setPosX(i);
        objt.setPosY(16);
        this->_objs.push_back(objt);
    }
    //stone 4 5
    RPGObj objs1, objs2, objs3,objs4,objs5,objs6;
    objs1.initObj("stone");
    objs1.setPosX(7);
    objs1.setPosY(9);

    objs2.initObj("stone");
    objs2.setPosX(8);
    objs2.setPosY(7);

    objs3.initObj("stone");
    objs3.setPosX(7);
    objs3.setPosY(7);

    objs4.initObj("stone");
    objs4.setPosX(8);
    objs4.setPosY(10);

    objs5.initObj("fruit");
    objs5.setPosX(7);
    objs5.setPosY(8);

    objs6.initObj("well");
    objs6.setPosX(5);
    objs6.setPosY(6);
    //npc
    _npc.initObj("npc");

    this->_objs.push_back(objs1);
    this->_objs.push_back(objs2);
    this->_objs.push_back(objs3);
    this->_objs.push_back(objs4);
    this->_objs.push_back(objs5);
    this->_objs.push_back(objs6);
    this->_objs.push_back(_npc);
}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);
    this->_npc.show(painter);
}

void World::handlePlayerMove(int direction, int steps){
    if(direction==1){
        if(nextStepName(_player.getPosX(),_player.getPosY()-1)=="tree");
        else if(nextStepName(_player.getPosX(),_player.getPosY()-1)=="stone");
        else if(nextStepName(_player.getPosX(),_player.getPosY()-1)=="fruit"){
            this->_player.move(direction, steps);
            _player.addGoal();
        }
        else if(nextStepName(_player.getPosX(),_player.getPosY()-1)=="well"){
            cout<<"You Lose!"<<endl;
            this->_player.setPosX(8);
            this->_player.setPosY(8);
        }
        else{this->_player.move(direction, steps);}
    }
    else if(direction==2){
        if(nextStepName(_player.getPosX(),_player.getPosY()+1)=="tree");
        else if(nextStepName(_player.getPosX(),_player.getPosY()+1)=="stone");
        else if(nextStepName(_player.getPosX(),_player.getPosY()+1)=="fruit"){
            this->_player.move(direction, steps);
            _player.addGoal();
        }
        else if(nextStepName(_player.getPosX(),_player.getPosY()+1)=="well"){
            cout<<"You Lose!"<<endl;
            this->_player.setPosX(8);
            this->_player.setPosY(8);
        }
        else{this->_player.move(direction, steps);}
    }
    else if(direction==3){
        if(nextStepName(_player.getPosX()-1,_player.getPosY())=="tree");
        else if(nextStepName(_player.getPosX()-1,_player.getPosY())=="stone");
        else if(nextStepName(_player.getPosX()-1,_player.getPosY())=="fruit"){
            this->_player.move(direction, steps);
            _player.addGoal();
        }
        else if(nextStepName(_player.getPosX()-1,_player.getPosY())=="well"){
            cout<<"You Lose!"<<endl;
            this->_player.setPosX(8);
            this->_player.setPosY(8);
        }
        else{this->_player.move(direction, steps);}
    }
    else{
        if(nextStepName(_player.getPosX()+1,_player.getPosY())=="tree");
        else if(nextStepName(_player.getPosX()+1,_player.getPosY())=="stone");
        else if(nextStepName(_player.getPosX()+1,_player.getPosY())=="fruit"){
            this->_player.move(direction, steps);
            _player.addGoal();
        }
        else if(nextStepName(_player.getPosX()+1,_player.getPosY())=="well"){
            cout<<"You Lose!"<<endl;
            this->_player.setPosX(8);
            this->_player.setPosY(8);
        }
        else{this->_player.move(direction, steps);}
    }
}

string World::nextStepName(int x,int y){
    if((x>=2)&&(x<=23)&&((y==2)||(y==15)))
        return "tree";
    if(((x==3)||(x==22))&&(y>=3)&&(y<=15))
        return "tree";
    if((x==8&&y==6)||(x==7&&y==6)||(x==7&&y==8)||(x==8&&y==9))
        return "stone";
    if(x==7&&y==8)
        return "fruit";
    if(x==6&&y==7)
        return "well";
    else
    return "player";
}

void World::handleNpcMove(){
    static int i=5;
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    i = qrand() %1;
    i++;
    if(i<=14)
        _npc.setPosY(i);
        _npc.setPosX(9);
        if(i==14)
            i=5;
}

