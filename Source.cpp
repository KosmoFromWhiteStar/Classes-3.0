#include <iostream>
#include <map>
#include <string>
#include <vector>

/// <summary>
/// Абслоютно безполезный класс. Такоже фигней занимается, мапа.
/// </summary>
class Talent
{
protected:
	/// <param name="pair_talent"> Типо сюда можно положить талант и потом сделать массив талантов.
	/// но есть Мапа в классе Анимал </param>
	std::pair<std::string, std::string> pair_talent;
public:
	virtual void talent() = 0
	{
		std::string name_skill = "";
	}
};


class Animal : public Talent
{
private:
	std::string name;
	int skills_ = 0;
protected:

	std::map<std::string, std::string> talants = { {"Swimming", "Swimming at pool, lake, sea."},
													{"Dancing", "Likes to dance to Frank Sinatra"},
													{"Counting","Conting to 10"} };

public:
	
	void new_talent(void)
	{
		std::cout << "Skill name:" << std::endl;
		std::string skill_name;
		std::cin >> skill_name;
		std::cout << "Means: " << std::endl << "";
		std::string means_skill;
		std::cin.ignore();
		std::getline(std::cin, means_skill);
		std::pair<std::string, std::string> new_pair(skill_name, means_skill);
		talants.insert(new_pair);
	}

	void set_Name(std::string in_name)
	{
		name = in_name;
	}
	std::string get_Name() const
	{
		return name;
	}
	void talent()
	{
		this->pair_talent;
	}
};


class Dog : public Animal
{
	int count_talants = 0;
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="in_name"> => name of pet</param>
	/// <param name="in_count_talants"> => on bit mask</param>
	Dog(std::string in_name, int in_count_talants)
	{
		if(in_count_talants > 0  && in_count_talants < 10) count_talants = in_count_talants;
		else
		{
			std::cout << "Not more 10 plz. Dog isnt ph.D" << std::endl;
		}
		this->set_Name(in_name);
	}
	void show_Talant()
	{
		std::cout << "This is " << this->get_Name();
		if (talants.size() == 0) std::cout << " and his haven't taltat" << std::endl;
		std::cout << std::endl;
		for (std::map<std::string, std::string>::iterator ip = talants.begin();
			ip != talants.end(); ip++)
		{
			std::cout << "It can \"" << ip->first << "\". That means \"" << ip->second << "\"" << std::endl;
		}

	}
	void swimming()
	{
		std::map<std::string, std::string>::iterator swim = talants.find("Swimming");
		std::cout << swim->first << std::endl << swim->second << std::endl;
	}

};

int main()
{
	Dog* dog = new Dog("Pochi", 7);
	dog->show_Talant();
	dog->new_talent();
	
	dog->show_Talant();

	delete dog;
}