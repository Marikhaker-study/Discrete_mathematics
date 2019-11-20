// Laba10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


class LLD
{
private:
	char* data;
	LLD *next;
	LLD *prev; 
	LLD *iterator;
private:
	LLD *head;
	LLD *tail;
public:

	LLD()
	{
		this->data = NULL;
		this->next = NULL;
		this->prev = NULL;
		this->head = NULL;
		this->tail = NULL;
		this->iterator = NULL;
	}
	LLD(char* data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

	LLD &addnodeback(char *data)
	{
		
		if (head == NULL)
		{
			LLD * node = new LLD;
			node->data = data;
			head = tail = node;
		}
		else
		{
			LLD * node = new LLD(data);
			tail->next = node;
			node->prev = tail;
			tail = node;
		}	
		return *this;
	}

	LLD &delnodeback()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return *this;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}
		return *this;
	}

	LLD &addnodefront(char *data)
	{

		if (head == NULL)
		{
			LLD * node = new LLD;
			node->data = data;
			head = tail = node;
		}
		else
		{
			LLD * node = new LLD(data);
			head->prev = node;
			node->next = head;
			head = node;
		}
		return *this;
	}

	LLD &delnodefront()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return *this;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		return *this;
	}

	void printlist()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			cout << "List: " << endl;
			iterator = head;
			while (iterator)
			{
				cout << iterator->data << endl;
				iterator = iterator->next;

			}
		}
		cout << endl;
	}

	void dellist()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			iterator = tail;
			while (iterator)
			{
				if (iterator->prev == NULL)
				{
					delete iterator;// ->next;
					iterator = NULL;
					break;
				}
				iterator = iterator->prev;
				
				delete iterator->next;
				
				iterator->next = NULL;

			}
			head = tail = NULL;
			cout << "List is cleared" << endl;
		}
		cout << endl;
	}

	void delnode_w_key(char *key)
	{
		bool flag = 0; // Перевірка чи був знайдений елемент
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			iterator = head;
			while (iterator)
			{
				if (iterator->data == key)
				{
					flag = 1;
					if (iterator == head)
					{
						delnodefront();
						iterator = head;
						cout << "Element with key has been deleted!" << endl;
					}
					if (iterator == tail)
					{
						delnodeback();
						iterator = tail;
						cout << "Element with key has been deleted!" << endl;
						return;
					}
					else
					{
						iterator->prev->next = iterator->next;
						iterator->next->prev = iterator->prev;
						delete iterator;
						iterator = NULL;
						cout << "Element with key has been deleted!" << endl;
					}					
				}
				else
				{
					iterator = iterator->next;
				}	
			}
		}

		if (!flag)
		{
			cout << "Element not found!" << endl;
		}

	}

	void file_write(char* filename)
	{
		FILE *f;
		if ((f = fopen(filename, "wb")) == NULL)
		{
			perror("Some bad things about file< error has been cast: ");
			exit(1);
		}

		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}
		else
		{
			iterator = head;
			while (iterator)
			{
				fwrite(iterator->data, 20, 1, f);
				iterator = iterator->next;

			}
		}
		cout << endl;

		if (ferror(f)) {
			printf("File Error\n");
			exit(2);
		}

		fclose(f);
		dellist();
	}

	LLD &file_read(char* filename ) /////////////// SOMETHING WRONG ABOUT THIS FUNCTION:: DONT WRITE DATA INTO LIST
	{
		FILE *f;
		if ((f = fopen(filename, "rb")) == NULL)
		{
			perror("Some bad things about file< error has been cast: ");
			exit(1);
		}
			iterator = head;
			do
			{
				char *temp = new char[20]{};
				fread(temp, 20, 1, f);
				addnodeback(temp);
			//	printlist();
				if (fgetc(f) == EOF) break;
				else fseek(f, -1, SEEK_CUR);
				delete[] temp;
			} while (true);

			//printlist(); // Друкуєм

		cout << endl;

		if (ferror(f)) {
			printf("File Error\n");
			exit(2);
		}

		fclose(f);
		printlist();
		dellist();
		return *this;
	}

	LLD &addnode_b_number(int number)
	{
		bool flag = 0; // Перевірка чи був знайдений елемент
		int count = 0;
		LLD *t_head;
		t_head = head;
		LLD *t_tail;
		int n = 0;
		if (head == NULL)
		{
			cout << "List is empty" << endl;
			return *this;
		}
		else
		{
			cout << "List: " << endl;
			iterator = head;
			while (iterator)
			{
				if (count == number)
				{
					flag = 1;
					t_tail = iterator->prev;
					head = iterator;
					cout << "How many push?" << endl;
					cin >> n;
					char **str = new char*[n]; // massive with items to push
					for (int i = 0; i < n; i++)
					{
						str[i] = new char[20]{};
					}

					cout << "Enter imput strings up to 20 characters" << endl;
					
					for (int i = 0; i < n; i++)
					{
						cin >> str[i];
						addnodefront(str[i]); // Додаємо
					}
					cout << endl;
					head->prev = t_tail;
					t_tail->next = head;
					this->head = t_head;

					this->printlist(); // Вивід оновленого листа
					file_write("smth.bin"); /////////////////// ЗЧИТУЄМО

					for (int i = 0; i < n; i++)
					{
						delete[] str[i];
					}
					delete[] str;
					break;
				}
				iterator = iterator->next;
				count++;
			}
		}

		cout << endl;
		if (!flag)
		{
			cout << "Element not found!" << endl;
		}
		return *this;
	}

};


int main()
{
	LLD list;

	list.file_read("smth.bin"); // Зчитування з файлу
	cout << endl;
	///////////////MENU//////////////
	//list.delnodeback().delnodeback().delnodefront().dellist();

	//list.addnodeback("Kaaka").addnodeback("ZAAAAA").addnodeback("DDDDADADAAA");
	//list.printlist();

	//list.delnodeback();
	//list.printlist();

	//list.addnodefront("sinaps").addnodefront("randomdata");
	//list.printlist();

	//list.delnode_w_key("ZAAAAA");
	//list.printlist();

	//list.addnode_b_number(2);
	////list.printlist();
	//list.dellist();
	//list.printlist();
	
	getch();
    return 0;
}

