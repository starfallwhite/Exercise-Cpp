#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<random>
using namespace std;

//建立演讲管理类封装程序
class speechManage{
public:
    speechManage(){

    }
    //第一轮12人,选手id
    vector<int> First_speecher;
    //第二轮6人
    vector<int> Second_speecher;
    //决胜者3人
    vector<int> Last_speecher;
    //id对应选手map
    map<int,speecher> m_speecher;


    //显示菜单
    void showmenu();
    //开始比赛
    void startGame();
    //保存数据

    //清空数据

    //退出程序
    void exitSys();

    //创建选手
    void createSpeech();
    //第一轮比赛分组打分
    void firstecohGame();
    //比赛打分,六个人
    void speecheScore(vector<int>v_id);
    //打印选手得分信息  id name score
    void printSpeecher(vector<int>v_id);
};

//选手类
class speecher{
public:
    speecher(string Name,float Score){
        m_Name = Name;
        m_Score = Score;
    }

    speecher(const speecher& other){
        m_Name = other.m_Name;
        m_Score = other.m_Score;
    }
    string getName(){return m_Name;}
    float getScore(){return m_Score;}
    void setScore(float score){m_Score = score;}//修改分数


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

//初始化创建参赛选手
void speechManage::createSpeech(){
    string nameseed = "ABCDEFGHIJKL";
    string name = "选手";
    int id = 10001;
    for(int i = 0; i < 12; i++){
        name += nameseed[i];
        id += i;
        speecher sp(name,0);

        this->First_speecher.push_back(id);
        this->m_speecher.insert(make_pair(id,sp));

        name = "选手";
    }
}

//选手分组打分
void speechManage::firstecohGame(){
    //随机分组
    random_shuffle(First_speecher.begin(),First_speecher.end());
    vector<int>v1(First_speecher.begin(),First_speecher.begin()+First_speecher.size()/2);
    vector<int>v2(First_speecher.begin()+First_speecher.size()/2,First_speecher.end());
    //打分
    speecheScore(v1);
    speecheScore(v2);
    //显示分组打分结果
    
    //排序

    //返回晋级结果 Second_speecher

    //打印结果
}
//打分
void speechManage::speecheScore(vector<int>v_id){
    float score = 0;
    // 创建随机数引擎和分布
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f,nextafter(100.0f,numeric_limits<float>::max()));//创建范围在[0,100.0]的随机分布
    
    for(vector<int>::iterator it = v_id.begin(); it != v_id.end(); it++){
        map<int,speecher>::iterator mp_it = m_speecher.find(*it);
        if(mp_it == m_speecher.end()){
            cout<<"打分过程中未查询到该选手的id"<<endl;
        }
        else{
            score = dis(gen);
            (*mp_it).second.setScore(score);
        }
    }
}
//打印 打分结果选手信息
void speechManage::printSpeecher(vector<int>v_id){
    
}
//第一轮比赛  分组--打分--排序

//第二轮比赛    打分---排序

//1.开始比赛
void speechManage::startGame(){
    //创建选手
    createSpeech();
    //第一轮12人，分组打分
    firstecohGame();
    
    
    //分组并打分

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
    srand((unsigned int)time(NULL));
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