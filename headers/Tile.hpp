#ifndef TILE
#define TILE


class Tile
{
public:
    Tile(int id,bool _solid);
    ~Tile();
    int getID();
    void setID(int id);
    bool isSolid();
    void Solid(bool x);
private:
    int id;
    bool solid;
};

#endif // TILE
