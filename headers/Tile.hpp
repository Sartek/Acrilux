#ifndef TILE
#define TILE


class Tile
{
	public:
		Tile(int id);
		~Tile();
		int getID();
		void setID(int id);
	private:
		int id;
};

#endif // TILE
