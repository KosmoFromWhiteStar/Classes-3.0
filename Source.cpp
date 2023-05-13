#include <iostream>
#include <map>
#include <string>
#include <vector>

class Talent
{
public:
	virtual void talent() = 0;
	virtual void name_tal() = 0;
};

class Dancing : public Talent
{
public:
	void talent() override
	{
		std::cout << "\"Dancing\"" << std::endl;
	}
	void name_tal() override
	{
		std::cout << "Dancing" << std::endl;
	}
};

class Swimming : public Talent
{
public:
	void talent() override
	{
		std::cout << "\"Swimming\"" << std::endl;
	}
	void name_tal() override
	{
		std::cout << "Swimming" << std::endl;
	}
};

class Counting : public Talent
{
public:
	void talent() override
	{
		std::cout << "\"Counting\"" << std::endl;
	}
	void name_tal() override
	{
		std::cout << "Counting" << std::endl;
	}
};

class Dog
{
private:
	std::string name = "";
	std::vector<Talent*> dog_talents;
public:
	Dog(std::string in_name) : name(in_name)
	{
		dog_talents.push_back(new Dancing());
		dog_talents.push_back(new Swimming());
		dog_talents.push_back(new Counting());
	}
	void show_Talent()
	{
		if (dog_talents.size() == 0)
		{
			std::cout << "Dog haven't talantes" << std::endl;
		}
		else
		{
			std::cout << "Dog have talentes: " << std::endl;
		}

		for (int i = 0; i < dog_talents.size(); i++)
		{
			dog_talents[i]->name_tal();
		}

	}
	~Dog()
	{
		for (int i = 0; i < dog_talents.size(); i++)
		{
			delete dog_talents[i];
		}
	}
};


int main()
{
	Dog* dog = new Dog("Steve");

	dog->show_Talent();

	delete dog;
}

