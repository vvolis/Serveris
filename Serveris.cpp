#include <iostream>
#include <fstream>
using namespace std;

class PC
{
public:
	long depth; //Mainigais lai atrastu talako no datoriem
	long tempDepth;
	bool encountered;
	PC()
	{
		depth = 0;
	};
};


//Rindas klases realizacija priekš BFS
class QueueArray 
{
private:
	int * table;
	int front;
	int length;
	int size;
public:
	QueueArray(int maxElementCount);
	~QueueArray();
	int isEmpty();
	int first();
	int enqueue(int value);
	int dequeue();
};

QueueArray::QueueArray(int maxElementCount) 
{
	if (maxElementCount < 1)
		maxElementCount = 1;  // at least one element can be stored
	table = new int[maxElementCount];
	front = 0;
	length = 0;
	size = maxElementCount;
}

QueueArray::~QueueArray() {
	delete[] table;
}

int QueueArray::isEmpty() {
	return length == 0;
}

int QueueArray::first() {
	if (isEmpty())
		return -1; // Error, Queue is empty
	return table[front];
}

int QueueArray::enqueue(int value) {
	if (length == size)
		return -1; // Error, Queue is full
	table[(front + length++) % size] = value;
	return 0; // OK, element is stored
}

int QueueArray::dequeue() {
	if (isEmpty())
		return -1; // Error, Queue is empty
	int value = table[front];
	length--;
	front = (front + 1) % size;
	return value;
}

void BFS(PC * datori, long ** tikls, long datSkaits, long dators, long & dzilums)
{
	//Resetojam apstaigatos datorus
	for (int i = 0; i < datSkaits; i++) datori[i].encountered = false;

	QueueArray rinda(datSkaits);
	rinda.enqueue(dators);
	datori[dators].encountered = true;
	datori[dators].tempDepth = 0;

	while (!rinda.isEmpty())
	{
		dators = rinda.dequeue();

		for (int i = 0; i < datSkaits; i++)
		{
			if (tikls[dators][i] == 1)
			{
				if (datori[i].encountered == false)
				{
					datori[i].encountered = true;
					rinda.enqueue(i);
					datori[i].tempDepth = datori[dators].tempDepth + 1;
					if (datori[i].tempDepth>dzilums) dzilums = datori[i].tempDepth;
				}
			}
		}
	}

}


int main()
{
	//------------------------------------------Ielasam visu info masiva------------------------------------------
	fstream file;
	file.open("serveris.in", ios::in);

	//Iegustam datoru skaitu
	long datSkaits = 0;
	file >> datSkaits;

	//Izveidojam tikla masivu
	long ** tikls = new long*[datSkaits];
	for (long i = 0; i < datSkaits; i++)
	{
		tikls[i] = new long[datSkaits];
	}

	//Aizpildam masivu
	long pc1 = 0;
	long pc2 = 0;
	file >> pc1;
	file >> pc2;
	while (pc1 != 0 && pc2 != 0)
	{
		tikls[pc1 - 1][pc2 - 1] = 1;
		tikls[pc2 - 1][pc1 - 1] = 1;
		file >> pc1;
		file >> pc2;
	}

	//--------------------------------------------Apstaigajam tiklu--------------------------------------------------
	PC * datori = new PC[datSkaits];
	//Meklejam katram datoram talako datur tikla ar BFS
	long lowestDepth = datSkaits;
	for (int dators = 0; dators < datSkaits; dators++)
	{
		long dzilums=0;
		BFS(datori, tikls, datSkaits, dators, dzilums);
		datori[dators].depth = dzilums;

		lowestDepth = (lowestDepth > dzilums) ? dzilums : lowestDepth;
	}

	//--------------------------------------------------Izvadam datus-------------------------------------------------
	fstream file2;
	file2.open("serveris.out", fstream::out);
	bool notFirst = false;

	file2 << lowestDepth << endl;
	for (int i = 0; i < datSkaits; i++)
	{
		if (datori[i].depth == lowestDepth)
		{
			if (notFirst) file2 << ' ';
			file2 << i+1;
			notFirst = true;
		}
	}

	file2.close();
	file.close();

	//--------------------------------------------------Savacam atminu-------------------------------------------------
	for (long i = 0; i < datSkaits; i++)
	{
		delete tikls[i];
	}
	delete tikls;
	delete datori;

	return 0;
}
