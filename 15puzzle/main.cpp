#include<string>
#include<cassert>
using namespace std;

const size_t width = 4; //?

class state
{
private:
	int matrixs[width*width] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
	enum direction { Up, Down, Left, Right };
	int empty_ind;

	bool is_valid_move(direction d)
	{
		if (d == Up && empty_ind <= width)
			return false;
		else if (d == Down && empty_ind >= width*width - width)
			return false;
		else if (d == Left && empty_ind % width == 0)
			return false;
		else if (d == Right && empty_ind % width == width - 1)
			return false;
		else return true;

	}

public:
	state() {}
	void generate(string s)
	{
		assert(s.length() == 16);
		// switch?
	}

	void print()
	{
		
	}

	bool is_valid()
	{

	}

	bool is_final()
	{
		
	}

	state make_move(direction d)
	{

	}


};

int main()
{

}