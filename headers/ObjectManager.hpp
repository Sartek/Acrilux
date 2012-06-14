#ifndef OBJECTMANAGER
#define OBJECTMANAGER

#include <vector>
#include "../headers/Object.hpp"


class ObjectManager
{
	public:
		ObjectManager();
		~ObjectManager();
		unsigned int newObject(int x,int y,bool draw,int texture_id);
		unsigned int newObject(std::string name,int x,int y,bool draw,int texture_id);
		Object* getObjectByID(unsigned int id);
		unsigned int objectListSize();
		Object* getObjectByName(std::string name);
	private:
		std::vector<Object> objectList;
		std::vector<std::string> objectNames;
		std::vector<unsigned int> objectNameIDS;
};
#endif // OBJECTMANAGER
