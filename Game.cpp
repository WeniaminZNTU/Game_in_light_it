#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_nam(int from, int before);//������� ��� ��������� ���������� ����� � �������� ���������


class players{
	  int heal;//��������
	  int hit;//���������� ���� �����
public:
	  string name;

	   players(string input_name)//�����������
	   {
	    name = input_name;
	    heal = 100;
	    hit = 0;
	   }

	   int power_hit(){
       hit = rand_nam(18, 25);//��������� ��������(���� �����) � ��������� 18 - 25
	   return hit;
	   };

	   int medium_hit()
	   {
	   	hit = rand_nam(10, 35);//��������� ��������(���� �����) � ��������� 10 - 35
		return hit;
	   };

	   int healing()//������� - �������
	   {
   	    int heals;
		heals = rand_nam(18, 25);//��������� �������� ��� ���������
		heal = heal + heals;
		return heals;
	   };

	   void max_heal_check(){if(heal >= 100) heal = 100;}//�������� �� ���������� ���� ��� ��������(100)

	   void damage(int dam){ heal = heal - dam;}//�������� �����

	   int ret_heal(){return heal;}//����� ��� �������� ���������� ��������
};


void move_player(players comput, players player);//������� ���� ������

void move_computer(players comput, players player);//������� ���� ����������

void Game();//������� ������� ���������


int main()
{
srand(time(NULL));
setlocale(LC_CTYPE, "rus");

Game();

system("pause");
return 0;
}

int rand_nam(int from, int before)
{
int nam;
 again:						//� ������ ������ ���� ��������� ����� ������
  nam = (rand() % before);  //������ ������� ��������� ����������(from - before)
  if(nam <= (from-1))		//���������� ������� �� ����� � ���
 goto again;				//���� ������ ������� �����
else return nam;
}

void move_player(players *comput, players *player)
{
int ch;    //int'������ ���������� ��� ���������� ��������� ���� ������� �� ������� ����
int damage;//��������� ��� �������� ����� �����
int heals; //��������� ��� �������� ����� ���������
again:     
     ch = getch();//���� ������� � ���������� � ���������� ��� �������� ����
	 //���� ������ �� 1 2 ��� 3 ���������� ������� �� ����� again:(��� ������������ ������
     if(ch == 49){//1 ������� ����
     	damage = player->power_hit();                            //����
     	comput->damage(damage);                                  //���� ����������� �����
     	cout<<"�� ������� � �����:"<<damage<<endl; //����� ��������� � ���� �����
     	cout<<"� ���������� ��������:"<<comput->ret_heal()<<endl;//����� ��������� � ���������� �������� � �
     	}
else if(ch == 50){//2 ������� ����
     	damage = player->medium_hit();
     	comput->damage(damage);
     	cout<<"�� ������� � �����:"<<damage<<endl;
     	cout<<"� ���������� ��������:"<<comput->ret_heal()<<endl;
		}
else if(ch == 51){//3 �������
	    heals = player->healing();
		player->healing();
		player->max_heal_check();
	    cout<<"�� ������������ ���� �������� � "<<heals<<"������"<<endl;
	    cout<<"������ � ��� "<<player->ret_heal()<<"������ ��������"<<endl;
		}
else goto again;
}            


void move_computer(players *comput, players *player)
{
int temp = rand() % 3 + 1;//������ ��������� ����������, �� ����� ���������� ����� ������� ��
//��� ����� ������ ��������� � ����������� �� ���� ������� � ���� ��������
int damage;//���������� �����
int heals; //���������� ��� ����� ���������

	 if((comput->ret_heal()) >= 67 && (comput->ret_heal() <= 100))//��� 100 - 67 �� �������� �
	 {
	  if(temp == 1 || temp == 2){// � ������������ � 66 ��������� ������ ������ ������
	   damage = comput->power_hit(); //����
	   player->damage(damage);	     //�������� ������� �����
	   cout<<"��������� ���� ��� "<<damage<<" ������ �����"<<endl;//��������� � ��������� � �����
	   cout<<"� ��� ��������:"<<player->ret_heal()<<endl;          //��������� � ��� ��� �������� � ������
      }
	  else{ //��������� 33 �� ������� ����
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"��������� ���� ��� "<<damage<<" ������ �����"<<endl;
	   cout<<"� ��� ��������:"<<player->ret_heal()<<" ������ ��������"<<endl;
	  }
     }

	 if((comput->ret_heal() >= 36) && (comput->ret_heal() <= 66))//��� 66 - 36 �� �������� �
	 {
	  if(temp == 1){ //� ������������ 33 �� ������ ������
	   damage = comput->power_hit();
	   player->damage(damage);
	   cout<<"��������� ���� ��� "<<damage<<" ������ �����"<<endl;
	   cout<<"� ��� ��������:"<<player->ret_heal()<<endl;

	  }
	  if(temp == 2){ //� ������������ 33 �� ������ ������
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"��������� ���� ��� "<<damage<<" ������ �����"<<endl;
	   cout<<"� ��� ��������:"<<player->ret_heal()<<" ������ ��������"<<endl;
	  }
	  if(temp == 3){ //� � ������������ 33 �� ������� ���������
	  	heals = comput->healing();
	  	cout<<"��������� ������� ���� �� "<<heals<<" ������ ��������"<<endl;
	  	cout<<"� ���������� "<<comput->ret_heal()<<" ������ ��������"<<endl;
	  }
	 } 

	 if((comput->ret_heal() >= 1) && (comput->ret_heal() <= 35))////��� 35 - 1 �� �������� �
	 {
	  if(temp == 1 || temp == 2){//c ������������ � 66 �� ������� ���������
	  	heals = comput->healing();
	  	cout<<"��������� ������� ���� �� "<<heals<<"������ ��������"<<endl;
	  	cout<<"� ���������� "<<comput->ret_heal()<<" ������ ��������"<<endl;
	  }
	  if(temp == 3){             //� 33 �������, ����� ������ ����
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"��������� ���� ��� "<<damage<<" ������ �����"<<endl;
	   cout<<"� ��� ��������:"<<player->ret_heal()<<" ������ ��������"<<endl;
	  }
     }
}


void Game()
{
string input, name_comp = "���������";
int ch;	//int'������ ���������� ��� ���������� ��������� ���� ������� �� ������� ����
bool first_player;//������ ���������� ��� �������� ���� ��� ����� ������
bool first_comput;

cout<<"������� ����:"<<endl;
cout<<"�� ������ ������� ������(1) � ����� ����� 18 - 25"<<endl;
cout<<"�� ������ ������� ������(2) � ����� ����� 10 - 35"<<endl;
cout<<"���� ������� �������(3), ��� ����������� 18 - 25 ������ ��������"<<endl;
cout<<"��������� ������(�������� �����) �� � ���������"<<endl;
cout<<"���� ����������� ����� � ��� ���� ���������� ���������� �������� ���������� �� 0"<<endl;
cout<<"���� ���(���� ���������):";
cin>>input;//���� �����
players computer(name_comp), player(input);//�������� �������� ������ � ����������
cout<<"�������!"<<endl;
while(ch != 13) ch = getch();//������ ���� ����� ������� "�����"
cout<<"������ ";

if((rand() % 2) == 1 ) first_player = true;//����������� ��������� ������� ���� ��� ����� ������ ������
else first_comput = true;
//1 - �����, 0 - ��������

for(int i = 0, tmp = 1; ; i++, tmp++)//������� ������ �� �����, - ������� ������ �� ����
{
 if(first_player == true && i % 2 == 0)//���� ������ ����� �����
    {
	  cout<<endl<<tmp<<". ��� ��� "<<player.name<<endl<<endl;//����� ���������� � ��� ��� ����� � ����� ���
     move_player(&computer, &player);                 //������� ���� ������
    }
 else if(first_player == true && i % 2 == 1){
	 cout<<endl<<tmp<<". ��� ����������"<<endl<<endl;
	 move_computer(&computer, &player); 	 		  //������� ���� ����������
    }

 else if(first_comput == true && i % 2 == 0)//���� ������ ����� ���������
    {
	 cout<<endl<<tmp<<". ��� ����������"<<endl<<endl;
	 move_computer(&computer, &player); 	 
    }
 else if(first_comput == true && i % 2 == 1){
 	 cout<<endl<<tmp<<". ��� ��� "<<player.name<<endl<<endl;
     move_player(&computer, &player);
    }

 	 if(computer.ret_heal() <= 0){	//������� ������ �� ����, ���� ���������� ����� ��������
		 cout<<endl<<"���� ��������"<<endl<<"�� ��������!"<<endl;
		 return;
		 }
	 if(player.ret_heal() <= 0){    //� ������ ��� ���������� ���������� �� ���� ��� ����
         cout<<endl<<"���� ��������"<<endl<<"������� ���������"<<endl;
		 return;
		 }
 }
}


