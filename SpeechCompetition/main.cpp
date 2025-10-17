#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<random>
#include<fstream>
using namespace std;

//人数
//#define 

//建立演讲管理类封装程序
class speechManage{
public:
    speechManage(){
        m_gameEcoh = 1;
    }
    //第一轮12人,选手id
    vector<int> First_speecher;
    //第二轮6人
    vector<int> Second_speecher;
    //决胜者3人
    vector<int> Last_speecher;
    //id对应选手map
    map<int,speecher> m_speecher;
    //比赛次数
    int m_gameEcoh;
    //显示菜单
    void showmenu();
    //开始比赛
    void startGame();
    //保存数据
    void saveVictory();
    //查看数据

    //清空数据

    //退出程序
    void exitSys();

    //创建选手
    void createSpeech();
    //第一轮比赛
    void firstecohGame();
    //第二轮比赛 
    void secondecohGame();
    //比赛打分,六个人
    void speecheScore(vector<int>& v_id);
    //打印选手得分信息  id name score
    void printSpeecher(vector<int>& v_id);
    //得分排序
    void scoreSort(vector<int>& v_id);
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
//第一轮比赛  分组--打分--排序
void speechManage::firstecohGame(){
    //随机分组
    random_shuffle(First_speecher.begin(),First_speecher.end());
    vector<int>v1(First_speecher.begin(),First_speecher.begin()+First_speecher.size()/2);
    vector<int>v2(First_speecher.begin()+First_speecher.size()/2,First_speecher.end());
    //打分
    this->speecheScore(v1);
    this->speecheScore(v2);
    //显示分组打分结果
    cout<<"*************第一小组*************"<<endl;
    this->printSpeecher(v1);
    cout<<endl;
    cout<<"*************第二小组*************"<<endl;
    this->printSpeecher(v2);
    cout<<endl;
    //排序
    this->scoreSort(v1);
    this->scoreSort(v2);
    //返回晋级结果 Second_speecher
    this->Second_speecher.resize(6);
    copy(v1.begin(),v1.begin() + 3,Second_speecher.begin());
    copy(v2.begin(),v2.begin() + 3,Second_speecher.begin() + 3);
    //打印结果
    cout<<"第一轮比赛晋级结果"<<endl;
    this->printSpeecher(Second_speecher);
    cout<<endl;
}
//第二轮比赛    打分---排序
void speechManage::secondecohGame(){
    //抽签
    random_shuffle(this->Second_speecher.begin(),this->Second_speecher.end());
    //打分
    this->speecheScore(this->Second_speecher);
    //显示抽签打分结果
    cout<<"***********第二轮比赛抽签及得分结果*******"<<endl;
    this->printSpeecher(Second_speecher);
    cout<<endl;
    //排序
    this->scoreSort(this->Second_speecher);
    //决胜结果
    this->Last_speecher.resize(3);
    copy(Second_speecher.begin(),Second_speecher.begin() + 3,Last_speecher.begin());
    //打印结果
    cout<<"***********决胜结果*******"<<endl;
    this->printSpeecher(Last_speecher);
    cout<<endl;
}
//保存获胜者结果
void speechManage::saveVictory(){
    std::ifstream fin("VictoryRecord.csv", std::ios::binary | std::ios::ate);
    bool needHeader = true;
    if(fin.is_open()){
        needHeader = (fin.tellg() == 0); // 文件长度为0则需要表头
        fin.close();
    }
    
    ofstream fid;
    fid.open("VictoryRecord.csv",ios::app);
    if(needHeader){
        fid << "id,name,score" << endl;
    }
    fid<<"第 "<<this->m_gameEcoh<<" 届比赛结果"<<endl;
    for(vector<int>::iterator it = this->Last_speecher.begin(); it != this->Last_speecher.end(); it++){
        map<int,speecher>::iterator mp_it = m_speecher.find(*it);
        if(mp_it == m_speecher.end()){
            cout<<"保存获胜者信息过程中未查询到该选手的id"<<endl;
        }
        else{
            fid<<(*it)<<","<<mp_it->second.getName()<<","<<mp_it->second.getScore()<<endl;
        }
    }
    fid.close();
    cout<<"文件记录已保存"<<endl;
}
//打分
void speechManage::speecheScore(vector<int>& v_id){
    float score = 0;
    // 创建随机数引擎和分布
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(60.0f,nextafter(100.0f,numeric_limits<float>::max()));//创建范围在[60,100.0]的随机分布
    
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
void speechManage::printSpeecher(vector<int>& v_id){
    for(vector<int>::iterator it = v_id.begin(); it != v_id.end(); it++){
        map<int,speecher>::iterator mp_it = m_speecher.find(*it);
        if(mp_it == m_speecher.end()){
            cout<<"打印选手信息过程中未查询到该选手的id"<<endl;
        }
        else{
            cout<<"姓名： "<<mp_it->second.getName()<<" 得分: "<<mp_it->second.getScore()<<endl;
        }
    }
}
//得分排序
void speechManage::scoreSort(vector<int>& v_id){
    //使用multimap容器实现排序<分数，选手id>
    multimap<float,int,greater<float>> mp_scoreId;
    for(vector<int>::iterator it = v_id.begin(); it != v_id.end();it++){
        map<int,speecher>::iterator mp_it = m_speecher.find(*it);
        if(mp_it == m_speecher.end()){
            cout<<"得分排序过程中未查询到该选手的id"<<endl;
        }
        else{
            mp_scoreId.insert(make_pair(mp_it->second.getScore(),*it));
        }
    }
    vector<int>::iterator it_vId = v_id.begin();
    for(multimap<float,int,greater<float>>::iterator it = mp_scoreId.begin();it != mp_scoreId.end();it++){
        (*it_vId) = it->second;
        it_vId++;
    }
}

//1.开始比赛
void speechManage::startGame(){
    //创建选手
    this->createSpeech();
    //第一轮12人，分组打分
    this->firstecohGame();
    //第二轮6人
    this->secondecohGame();
    //保存结果
    this->saveVictory();
}
//2.查看结果

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