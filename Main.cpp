#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <map>
#include <utility>//std::pair
#include <unordered_map>
#include "Race.h"
//Что хранит  всебе узел двухсвязного списка
//map
//unordered_map
//шаблоны классов
template <typename T>
struct Node
{
	T val;//значчение узла каккую информацию он хранит
	Node* prev;//предидущий сосед
	Node* next;//следующий сосед
};
template <typename T>
struct Node_of_forward_list
{
	T val;//значчение узла каккую информацию он хранит
	Node_of_forward_list<T>* next;//следующий сосед
};

template <typename T>
class Calculator
{
public:
	Calculator() {};
	Calculator(T x, T y) : _x(x), _y(y) {};
	T getSum()
	{
		return _x + _y;
	}
	T getSub()
	{
		return _x - _y;
	}
	T getMultiply()
	{
		return _x * _y;
	}
	T getDiv()
	{
		if (_y == 0)
		{
			std::cout << "Error\n";
		return 0;
		}
		return _x / _y;
	}
private:
	T _x = 0;
	T _y = 0;
};
int main()
{
	/*setlocale(LC_ALL, "Russian");
	Node<int>* n = new Node<int>;
	std::vector<int> vec2;
	vec2.push_back(n->val);
	while (n->next != nullptr)
	{
		vec2.push_back(n-> next -> val);
		n = n->next;
	}*/


	/*std::cout << "Hello world!\n";
	std::vector<int> vec{ 1,2,3 };
	//ranged-base for loop
	for(const auto &el : vec)
	{
	}
	for(std::vector<int>::const_iterator it = vec.begin();
		it != vec.end(); it ++)
	{
	}
	//быстрее если бежим от начала к конццу вектора
	for(int i = 0; i < vec.size(); i++)
	{
		int x = vec[i];
	}*/


	//List двухсвязный список который состоит из узлов(Node) сложность O(1)
	//каждый узел знает прроо своего следующего и преидущего соседа
	//push.back и hush front добавляет элементы либо с конца либо с начала
	//при замене сообщает соседним значениям новое значение, может выполняться болле долгое 
	//время так каксодержет два адреса соседних элементов а указатели на эти адреса 
	//могут находится в любом месте  памяти и получение доступа к нему займет у программы время
	/*std::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	for (const auto& el : myList)
	{
		std::cout << el << " ";
	}
	std::cout << '\n';
	myList.push_front(0);
	myList.push_front(-1);
	myList.push_front(-2);
	for (const auto& el : myList)
	{
		std::cout << el << " ";
	}
	std::cout << '\n';*/

	//auto команда автоматического определения типа данных
	//Forward_list тоже самое но в одностороннем порядке , 
	//занимает меньше места и времени так как содержит только дрес на следующий элемент
	/*std::forward_list<int> fwl;
	fwl.push_front(1);
	fwl.push_front(2);
	fwl.push_front(3);
	for (const auto& el : fwl)
	{
		std::cout << el << " ";
	}*/
	//пробегает сначала до конца, сложность O(1);

	//3 спопоба добавления данных в мапу

	//std::map<int, std::string> mymap;
	//
	//mymap[245] = "abc";
	//
	//mymap.insert({ 5,"Bob" });
	//mymap.insert(std::make_pair(5, "bob"));//make_pair создать пару

	//std::pair<int, std::string> mypair;
	//mypair.first = 6;
	//mypair.second = "Tanya";
	//mymap.insert(mypair);	

	//for(const auto &[key, value] : mymap)
	//{
	//	std::cout << key << " " << value << '\n';//std::cout << el.first <<" "<<el.second << "\n";
	//}

	//unordered_map
	//создает уникальный ключ и щет каждый элемент по этому ключу 
	//не сортируя но тратя больше памяти на храение ключа сложность O(1)
	//unordered_map проблемы - при большом количестве элементов может дублироваться hash ключа
	//чтобы избежать  -> hash_new, или хеширование хеша
	/*std::unordered_map<int, std::string> umap;
	umap.insert({ 1,"Hello" });
	umap.insert({ 2,"Hi" });
	umap.insert({ 3,"Gelo" });
	for(const auto &[key, value] : umap)
	{
		std::cout << key << " " << value << '\n';
	}*/
	//insert -> hash(key) -> hashed_key

	/*std::map<int, std::string> mymap2;
	mymap2.insert({ 5, "abc"});
	const auto& [it, isInserted] = mymap2.insert({ 5,"def" });

	std::cout << "isInserted: " << isInserted << std::endl;*/

	Race<Car> myRace;
	Car c1(50, "BMW");
	Car c2(40, "Mesr");
	std::cout << "+++++++++++++++++++\n";
	myRace.race(c1, c2);
	std::cout << "+++++++++++++++++++\n";
	Calculator<char> val(4, 0);
	std::cout << val.getSum() << "\n";
	std::cout << "+++++++++++++++++++\n";
	std::cout << val.getDiv() << "\n";
	
	return 0;
}