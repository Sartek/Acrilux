#ifndef OBJECTMANAGER
#define OBJECTMANAGER

#include <vector>
#include "../headers/Object.hpp"


class ObjectManager
{
	public:
		ObjectManager();
		~ObjectManager();
		int newObject(int x,int y,bool draw,int texture_id);
		Object& getObjectByID(unsigned int id);
		unsigned int objectListSize();
	private:
		std::vector<Object> objectList;
};
#endif // OBJECTMANAGER
