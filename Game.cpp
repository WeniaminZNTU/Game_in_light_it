#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_nam(int from, int before);//функция для получения рандомного числа в заданном диапазоне


class players{
	  int heal;//здоровье
	  int hit;//переменная силы удара
public:
	  string name;

	   players(string input_name)//конструктор
	   {
	    name = input_name;
	    heal = 100;
	    hit = 0;
	   }

	   int power_hit(){
       hit = rand_nam(18, 25);//рандомное значение(сила удара) в диапазоне 18 - 25
	   return hit;
	   };

	   int medium_hit()
	   {
	   	hit = rand_nam(10, 35);//рандомное значение(сила удара) в диапазоне 10 - 35
		return hit;
	   };

	   int healing()//функция - лечение
	   {
   	    int heals;
		heals = rand_nam(18, 25);//рандомное значение для излечения
		heal = heal + heals;
		return heals;
	   };

	   void max_heal_check(){if(heal >= 100) heal = 100;}//проверка на превышение макс кол здоровья(100)

	   void damage(int dam){ heal = heal - dam;}//принятие урона

	   int ret_heal(){return heal;}//метод для проверки количества здоровья
};


void move_player(players comput, players player);//функция хода игрока

void move_computer(players comput, players player);//функция хода компьютера

void Game();//Главная функция программы


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
 again:						//В данном случае если рандомное число меньше
  nam = (rand() % before);  //нижней границы заданного диапазонна(from - before)
  if(nam <= (from-1))		//происходит переход по метке и ещё
 goto again;				//один подбор нужного числа
else return nam;
}

void move_player(players *comput, players *player)
{
int ch;    //int'овская переменная для сохранения числового кода символа из таблицы АСКИ
int damage;//Переенная для хранения очков урона
int heals; //Переенная для хранения очков исцеления
again:     
     ch = getch();//Приём символа с клавиатуры и сохранение его значения АСКИ
	 //Если символ не 1 2 или 3 происходит переход по метке again:(как альтернатива циклам
     if(ch == 49){//1 сильный удар
     	damage = player->power_hit();                            //удар
     	comput->damage(damage);                                  //приём компьюбером удара
     	cout<<"Вы ударили с силой:"<<damage<<endl; //вывод сообщения о силе удара
     	cout<<"У компьютера осталось:"<<comput->ret_heal()<<endl;//вывод сообщения о оставщемся здоровьи у К
     	}
else if(ch == 50){//2 средний удар
     	damage = player->medium_hit();
     	comput->damage(damage);
     	cout<<"Вы ударили с силой:"<<damage<<endl;
     	cout<<"У компьютера осталось:"<<comput->ret_heal()<<endl;
		}
else if(ch == 51){//3 лечение
	    heals = player->healing();
		player->healing();
		player->max_heal_check();
	    cout<<"Вы восстановили себе здоровье в "<<heals<<"едениц"<<endl;
	    cout<<"Теперь у вас "<<player->ret_heal()<<"Едениц здоровья"<<endl;
		}
else goto again;
}            


void move_computer(players *comput, players *player)
{
int temp = rand() % 3 + 1;//Рандом поведения компьютера, от этого рандомного числа зависит то
//что будет делать компьютер в зависимости от того сколько у него здоровья
int damage;//переменная урона
int heals; //переменная для очков исцеления

	 if((comput->ret_heal()) >= 67 && (comput->ret_heal() <= 100))//При 100 - 67 пр здоровья К
	 {
	  if(temp == 1 || temp == 2){// с вероятностью в 66 процентов ударит мощным ударом
	   damage = comput->power_hit(); //Удар
	   player->damage(damage);	     //принятие игроком удара
	   cout<<"Компьютер нанёс вам "<<damage<<" едениц урона"<<endl;//сообщение о нанесённос К уроне
	   cout<<"У вас осталось:"<<player->ret_heal()<<endl;          //сообщение о ост кол здоровья у игрока
      }
	  else{ //Остальные 33 на средний удар
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"Компьютер нанёс вам "<<damage<<" едениц урона"<<endl;
	   cout<<"У вас осталось:"<<player->ret_heal()<<" едениц здоровья"<<endl;
	  }
     }

	 if((comput->ret_heal() >= 36) && (comput->ret_heal() <= 66))//При 66 - 36 пр здоровья К
	 {
	  if(temp == 1){ //с вероятностью 33 пр ударит сильно
	   damage = comput->power_hit();
	   player->damage(damage);
	   cout<<"Компьютер нанёс вам "<<damage<<" едениц урона"<<endl;
	   cout<<"У вас осталось:"<<player->ret_heal()<<endl;

	  }
	  if(temp == 2){ //с вероятностью 33 пр ударит средне
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"Компьютер нанёс вам "<<damage<<" едениц урона"<<endl;
	   cout<<"У вас осталось:"<<player->ret_heal()<<" едениц здоровья"<<endl;
	  }
	  if(temp == 3){ //и с вероятностью 33 пр выберет исцеоение
	  	heals = comput->healing();
	  	cout<<"Компьютер исцелил себя на "<<heals<<" едениц здоровья"<<endl;
	  	cout<<"У компьютера "<<comput->ret_heal()<<" едениц здоровья"<<endl;
	  }
	 } 

	 if((comput->ret_heal() >= 1) && (comput->ret_heal() <= 35))////При 35 - 1 пр здоровья К
	 {
	  if(temp == 1 || temp == 2){//c вероятностью в 66 пр выберет исцеление
	  	heals = comput->healing();
	  	cout<<"Компьютер исцелил себя на "<<heals<<"едениц здоровья"<<endl;
	  	cout<<"У компьютера "<<comput->ret_heal()<<" едениц здоровья"<<endl;
	  }
	  if(temp == 3){             //а 33 средний, более точный удар
	   damage = comput->medium_hit();
	   player->damage(damage);
	   cout<<"Компьютер нанёс вам "<<damage<<" едениц урона"<<endl;
	   cout<<"У вас осталось:"<<player->ret_heal()<<" едениц здоровья"<<endl;
	  }
     }
}


void Game()
{
string input, name_comp = "Компьютер";
int ch;	//int'овская переменная для сохранения числового кода символа из таблицы АСКИ
bool first_player;//Булевы переменные для проверки того кто ходит первым
bool first_comput;

cout<<"Правила игры:"<<endl;
cout<<"Вы можете ударить сильно(1) с силой удара 18 - 25"<<endl;
cout<<"Вы можете ударить средне(2) с силой удара 10 - 35"<<endl;
cout<<"Либо выбрать лечение(3), что восстановит 18 - 25 едениц здоровья"<<endl;
cout<<"Поочерёдно ходите(наносите удары) вы и компьютер"<<endl;
cout<<"Игра закорчиться когда у вас либо компьютера количество здоровья уменьшится до 0"<<endl;
cout<<"Ваше имя(ввод латиницей):";
cin>>input;//Ввод имени
players computer(name_comp), player(input);//Создание объектов игрока и компьютера
cout<<"Поехали!"<<endl;
while(ch != 13) ch = getch();//Начало игры после нажатия "энтер"
cout<<"Первый ";

if((rand() % 2) == 1 ) first_player = true;//Определение случайным образом того кто будет ходить первым
else first_comput = true;
//1 - игрок, 0 - компютер

for(int i = 0, tmp = 1; ; i++, tmp++)//условие выхода из цикла, - условие выхода из игры
{
 if(first_player == true && i % 2 == 0)//Если первым ходит игрок
    {
	  cout<<endl<<tmp<<". Ваш ход "<<player.name<<endl<<endl;//вывод соообщения о том кто ходит и какой ход
     move_player(&computer, &player);                 //функция хода игрока
    }
 else if(first_player == true && i % 2 == 1){
	 cout<<endl<<tmp<<". Ход компьютера"<<endl<<endl;
	 move_computer(&computer, &player); 	 		  //функция хода компьютера
    }

 else if(first_comput == true && i % 2 == 0)//Если первым ходит компьютер
    {
	 cout<<endl<<tmp<<". Ход компьютера"<<endl<<endl;
	 move_computer(&computer, &player); 	 
    }
 else if(first_comput == true && i % 2 == 1){
 	 cout<<endl<<tmp<<". Ваш ход "<<player.name<<endl<<endl;
     move_player(&computer, &player);
    }

 	 if(computer.ret_heal() <= 0){	//Условие выхода из игры, если количество очков здоровья
		 cout<<endl<<"Игра окончена"<<endl<<"Вы выйграли!"<<endl;
		 return;
		 }
	 if(player.ret_heal() <= 0){    //у игрока или компьютера опкститься до нуля или ниже
         cout<<endl<<"Игра окончена"<<endl<<"Выйграл компьютер"<<endl;
		 return;
		 }
 }
}


