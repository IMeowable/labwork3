using namespace std;
#include <iostream>
#include <sstream>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
list<double> x_to_write;
list<double> y_to_write;

//Валидация вводимых значений, провеерка на принадлежность к вещественным числам

bool IsDouble(string check_string)
{

	istringstream iss{ (check_string) };
	double f;
	iss >> noskipws >> f;
	if (iss.eof() && !iss.fail() and f > -10)
	{

		return true;
	}
	else
	{

		return false;
	}
}

//функция поиска точки на графике
double find_y(double user_input)

{
	double curr_y;

	//определение принадлежности графику введенного значения условными операторами
	if (user_input <= -6)
	{
		//уравнение полукруга y = -1 * sqrt(R^2 - x^2)
		//r = 2, центр окружности (-8; 2)
		//(x+8)^2+(y-2)^2 = 4 
		//  (y-2)^2 = 4 - (x+8)^2
		//y = sqrt(4-(x+8))^2) + 2
		curr_y = -sqrt((4 - pow((user_input + 8), 2))) + 2;
		cout << "Y:\t" << curr_y << endl;;
	}
	if (user_input > -6 && user_input <= -4)
	{
		//на графике фнукция параллельна оси Ox
		curr_y = 2;
		cout << "Y:\t" << curr_y << endl;;

	}
	if (user_input == 0) {
		curr_y = 0;
		cout << "Y:\t" << curr_y << endl;;
	}
	if (user_input > -4 && user_input < 2 && user_input != 0)
	{
		//k = -1/2 , функция y = kx + m	
		curr_y = -user_input / 2.;
		cout << "Y:\t" << curr_y << endl;;
	}
	if (user_input >= 2)
	{
		//функция y = kx + m    k = 1 m = -3
		curr_y = user_input - 3.;
		cout << "Y:\t" << curr_y << endl;;
	}
	return curr_y;
}
void txt_write()
{
	std::ofstream out("numbers.txt", std::ios::app);//открываем в режиме записи в конец файла
	if (out.is_open())
	{
		out << "x\t";
		for (auto i : x_to_write)//перебираем наши иксы и отправляем в файл
		{
			out << i << "\t";

		}
		out << endl;
		out << "Y\t";
		for (auto i : y_to_write)//также перебираем Y
		{
			out << i << "\t";
		}
		out << endl;
		out << endl;
	}
	out.close();
}

//В каждую итерацю добавил добавление текущих значений X и Y в соответствущие списки
void cyclic_find()
{
	string check_first;
	string check_second;
	cin >> check_first;
	cout << "Enter 'xn':\n";
	cin >> check_second;
	if (IsDouble(check_first) && IsDouble(check_second))
	{
		double i = stod(check_first);
		cout << i<< endl;
		double last = stod(check_second);
		cout << last << endl;
		if (i < last)
		{
			for (i; i <= last; i++)
			{

				cout << "X:\t"<< i<<"\t";
				double to_write = find_y(i);
				x_to_write.push_back(i);
				y_to_write.push_back(to_write);
				

			}
			txt_write();
		}
		else cout << "Enter numbers from left to the right" << endl;
	}
	else
	{
		cout << "Wrong, try again" << endl;
	}
}

//При каждом запуске в консоль будет выводиться содержимое текстового файла, после ознакомления с ним - enter, консоль очистится, можно снова развлекаться с функцией.
void txt_read()

{
	
	cout << "Previous calculations: (from txt file)";
	cout << endl;
	string line;
	ifstream in("numbers.txt"); 
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // закрываем файл
	cout << "For next work press enter(and clean console)";
	getchar();
	system("cls");
}
 


int main()
{
	txt_read();
	while (1)
		
		cyclic_find();
}
