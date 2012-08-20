#ifndef OBJECTMANAGER
#define OBJECTMANAGER

#include <vector>
#include "../headers/Object.hpp"
#include "../headers/Player.hpp"

class ObjectManager
{
public:
    ObjectManager();
    ~ObjectManager();
    unsigned int newObject(float x,float y,bool draw,int texture_id);
    unsigned int newObject(float x,float y,std::string type,bool draw,int texture_id);
    unsigned int newObject(std::string name,float x,float y,bool draw,int texture_id);
    unsigned int newObject(std::string name,float x,float y,std::string type,bool draw,int texture_id);
    Object* getObjectByID(unsigned int id);
    unsigned int objectListSize();
    Object* getObjectByName(std::string name);
private:
    std::vector<Object*> objectList;
    std::vector<std::string> objectNames;
    std::vector<unsigned int> objectNameIDS;
};
#endif // OBJECTMANAGER
