#include "pch.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

namespace {
	using std::string;
}

int main()
{

	LinkedList<int> list;

	Node<int> *one = new Node<int>();
	one->setData(1);

	Node<int> *three = new Node<int>();
	three->setData(3);

	Node<int> *seven = new Node<int>();
	seven->setData(7);

	Node<int> *twelve = new Node<int>();
	twelve->setData(12);

	Node<int> *two = new Node<int>();
	two->setData(2);

	Node<int> *four = new Node<int>();
	four->setData(4);

	Node<int> *nine = new Node<int>();
	nine->setData(9);

	Node<int> *eight = new Node<int>();
	eight->setData(8);

	Node<int> *ninenine = new Node<int>();
	ninenine->setData(99);

	list.insert(one);
	list.search(2);
	list.insert(three);
	list.search(2);
	list.insert(seven);
	list.insert(twelve);
	list.insert(two);
	list.insert(four);
	list.search(2);
	list.insert(nine);
	list.insert(eight);
	list.remove(3);
	list.remove(6);
	list.insert(ninenine);



	list.display();

	//LinkedList<string> stringList;

	//Node<string> *word = new Node<string>();
	//word->setData("Well hello there");

	//Node<string> *animal = new Node<string>();
	//animal->setData("The dragons are coming..");

	//stringList.insert(word);
	//stringList.insert(animal);

}