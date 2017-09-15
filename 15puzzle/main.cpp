#include<string>
#include<cassert>
using namespace std;

const int size = 4; //?

class state
{
private:
	int matrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
	enum direction { Up, Down, Left, Right };
	int empty_ind;

	bool is_valid_move(direction d)
	{
		if (d == Up && empty_ind <= 4)
			return false;
		else if (d == Down && empty_ind >= 12)
			return false;
		else if (d == Left &&)
			return false;
		else if (d == Right &&)

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