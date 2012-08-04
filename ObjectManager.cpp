#include "headers/ObjectManager.hpp"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

unsigned int ObjectManager::newObject(float x,float y,bool draw,int texture_id)
{
	Object tempobject(x,y,draw,texture_id);
	objectList.push_back(tempobject);
	int id = objectList.size() - 1;
	return id;
}

unsigned int ObjectManager::newObject(std::string name,float x,float y,bool draw,int texture_id)
{
	Object tempobject(x,y,draw,texture_id);
	objectList.push_back(tempobject);
	unsigned int id = objectList.size() - 1;
	objectNames.push_back(name);
	objectNameIDS.push_back(id);
	return id;
}

Object* ObjectManager::getObjectByID(unsigned int id)
{
	return &objectList.at(id);
}
Object* ObjectManager::getObjectByName(std::string name)
{
	int id = -1;
	for(unsigned int i = 0;i<objectNames.size();i++)
	{
		if(objectNames[i] == name)
		{
			id = objectNameIDS[i];
			break;
		}
	}
	return &objectList.at(id);
}

unsigned int ObjectManager::objectListSize()
{
	return objectList.size();
}
