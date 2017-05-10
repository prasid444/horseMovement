#include<iostream>
#include<cmath>
using namespace std;


int c=2;
struct pos {
int x;
int y;
pos  *UP3LEFT;
pos  *UP3RIGHT;
pos  *DOWN3LEFT;
pos  *DOWN3RIGHT;
pos  *UP1LEFT;
pos  *UP1RIGHT;
pos  *DOWN1LEFT;
pos  *DOWN1RIGHT;
};

class myTree{
public:
    myTree(int x, int y);
    //~myTree();
    void insert(int x,int y);

    pos *root;
    void insert(int x,int y, pos *branch);


};

myTree::myTree(int x, int y){
    root= new pos;
    root->x=x;
    root->y=y;
    root->UP3LEFT=NULL;
    root->UP3RIGHT=NULL;
    root->DOWN3LEFT=NULL;
    root->DOWN3RIGHT=NULL;
    root->UP1LEFT=NULL;
    root->UP1RIGHT=NULL;
    root->DOWN1LEFT=NULL;
    root->DOWN1RIGHT=NULL;
}

/*void myTree::insert(int x,int y,pos *branch)
{
    branch= new pos;
    branch->x=x;
    branch->y=y;
    branch->UP3LEFT=NULL;
    branch->UP3RIGHT=NULL;
    branch->DOWN3LEFT=NULL;
    branch->DOWN3RIGHT=NULL;
    branch->UP1LEFT=NULL;
    branch->UP1RIGHT=NULL;
    branch->DOWN1LEFT=NULL;
    branch->DOWN1RIGHT=NULL;


}
*/

//void maketree(pos i, int c){
//
//i.UP1RIGHT=   new pos;
//i.UP1LEFT=    new pos;
//i.DOWN1RIGHT= new pos;
//i.DOWN1LEFT=  new pos;
//i.DOWN3RIGHT= new pos;
//i.DOWN3LEFT=  new pos;
//i.UP3RIGHT=   new pos;
//i.UP3LEFT=    new pos;
//
// ad3ad1=makenode(i.x+3,i.y+1);
// ad3sub1=makenode(i.x+3,i.y-1);
// ad1ad3=makenode(i.x+1,i.y+3);
// ad1sub3=makenode(i.x+1,i.y-3);
// sub3ad1=makenode(i.x-3,i.y+1);
// sub3sub1=makenode(i.x-3,i.y-1);
// sub1ad3=makenode(i.x-1,i.y+3);
// sub1sub3=makenode(i.x-1,i.y-3);
//
//
//}

bool validate(int a, int b){
    if(a>=0 && a<8 && b>=0 && b<8)
        return true;
    else
        return false;
}



void generateTree(int x, int y,pos *p,int c){



if(c>0){
p->DOWN1LEFT=new pos;
p->DOWN1LEFT->x=x-3;
p->DOWN1LEFT->y=y-1;

p->DOWN3LEFT=new pos;
p->DOWN3LEFT->x=x-1;
p->DOWN3LEFT->y=y-3;

p->DOWN1RIGHT=new pos;
p->DOWN1RIGHT->x=x+3;
p->DOWN1RIGHT->y=y-1;

p->DOWN3RIGHT=new pos;
p->DOWN3RIGHT->x=x+1;
p->DOWN3RIGHT->y=y-3;

p->UP1LEFT=new pos;
p->UP1LEFT->x=x-3;
p->UP1LEFT->y=y+1;

p->UP3LEFT=new pos;
p->UP3LEFT->x=x-1;
p->UP3LEFT->y=y+3;

p->UP1RIGHT=new pos;
p->UP1RIGHT->x=x+3;
p->UP1RIGHT->y=y+1;

p->UP3RIGHT=new pos;
p->UP3RIGHT->x=x+1;
p->UP3RIGHT->y=y+3;

        c--;
generateTree(p->DOWN1LEFT->x,p->DOWN1LEFT->y,p->DOWN1LEFT,c);
generateTree(p->DOWN1RIGHT->x,p->DOWN1RIGHT->y,p->DOWN1RIGHT,c);
generateTree(p->DOWN3LEFT->x,p->DOWN3LEFT->y,p->DOWN3LEFT,c);
generateTree(p->DOWN3RIGHT->x,p->DOWN3RIGHT->y,p->DOWN3RIGHT,c);
generateTree(p->UP1LEFT->x,p->UP1LEFT->y,p->UP1LEFT,c);
generateTree(p->UP1RIGHT->x,p->UP1RIGHT->y,p->UP1RIGHT,c);
generateTree(p->UP3LEFT->x,p->UP3LEFT->y,p->UP3LEFT,c);
generateTree(p->UP3RIGHT->x,p->UP3RIGHT->y,p->UP3RIGHT,c);
}

}
int height=0;
void showelement(pos *p, int h){
if(p)
{
    cout<<"("<<p->x<<","<<p->y<<")" <<"height"<<h<<endl;
    if(p->DOWN1LEFT) {showelement(p->DOWN1LEFT, ++h);}
    if(p->DOWN1RIGHT) {showelement(p->DOWN1RIGHT,h);}
    if(p->DOWN3LEFT) {showelement(p->DOWN3LEFT, h);}
    if(p->DOWN3RIGHT) {showelement(p->DOWN3RIGHT,h);}
    if(p->UP1LEFT) {showelement(p->UP1LEFT, h);}
    if(p->UP1RIGHT) {showelement(p->UP1RIGHT,h);}
    if(p->UP3LEFT) {showelement(p->UP3LEFT, h);}
    if(p->UP3RIGHT) {showelement(p->UP3RIGHT,h);}
}


}

int main(void){

pos initial, target;



cout<<"give initial and target position"<<endl;
cin>>initial.x>>initial.y>>target.x>>target.y;

myTree top(initial.x,initial.y);

if(!(validate(initial.x,initial
              .y) && validate(target.x,target.y)))
    {
    cout<<"not within board";
    }
else
    {
        cout<<"within board"<<endl;
        cout<<"The least number of steps is:"<<endl;

        generateTree(initial.x,initial.y,top.root,c);
        showelement(top.root,height);

    }




return 0;
}

