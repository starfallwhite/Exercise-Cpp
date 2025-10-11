#include<iostream>
#include<vector>
#include<string>

using namespace std;

//建立演讲管理类封装程序
class speechManage{
public:
    speechManage(){

    }

    //显示菜单
    void showmenu();

    //开始比赛
    void startGame();
    //保存数据

    //清空数据

    //退出程序
    void exitSys();
};

//选手类
class speecher{
public:
    speecher(string Name,float Score){
        m_Name = Name;
        m_Score = Score;
    }
    string showName(){return m_Name;}
    float showScore(){return m_Score;}

private:
    string m_Name;
    float m_Score;

};                                                             

//显示菜单
void speechManage::showmenu(){
    cout<<"**********************************************************"<<endl;
    cout<<"********演讲比赛管理系统******"<<endl;
    cout<<"*****************1.开始比赛********************"<<endl;
    cout<<"*****************2.查看记录********************"<<endl;
    cout<<"*****************3.清空记录********************"<<endl;
    cout<<"*****************4.退出程序********************"<<endl;
    cout<<"请输入功能前的编号进行操作"<<endl;
    cout<<"**********************************************************"<<endl;
}

//初始化参赛选手


//选手分组


//第一轮比赛  分组--打分--排序

//第二轮比赛    打分---排序

//1.开始比赛
void speechManage::startGame(){
    //第一轮12人
    vector<speecher> First_speecher;

    //第二轮6人
    vector<speecher> Second_speecher;

    
    //决胜者3人
    vector<speecher> Last_speecher;


}
//2.保存结果

//3.清空结果

//4.退出程序
void speechManage:: exitSys(){
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}


void test01(){

}

int main(){
    speechManage speech;
    
    int chioce = 0;

    while(true){
        speech.showmenu();
        cin>>chioce;
        switch (chioce)
        {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            speech.exitSys();
            break;

        default:
            system("cls");//清屏
            break;
        }
    }

    return 0;
}