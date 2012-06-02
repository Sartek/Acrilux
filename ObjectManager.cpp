#include "headers/ObjectManager.hpp"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

int ObjectManager::newObject(int x,int y,bool draw,int texture_id)
{
	Object tempobject(x,y,draw,texture_id);
	objectList.push_back(tempobject);
	int id = objectList.size() - 1;
	return id;
}

Object& ObjectManager::getObject(unsigned int id)
{
	return objectList.at(id);
}

unsigned int ObjectManager::objectListSize()
{
	return objectList.size();
}
