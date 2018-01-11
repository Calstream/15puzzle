#include<string>
#include<cassert>
#include<iostream>
#include<iomanip>
using namespace std;

const size_t width = 4; //?
typedef char elem_type;

class state
{
private:
	elem_type matrix[width*width] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
	enum direction { Up, Down, Left, Right };
	int empty_ind = 15;

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

	state(int empty_i, elem_type m[width*width]) : empty_ind(empty_i)
	{
		for (int i = 0; i < 16; i++)
		{
			matrix[i] = m[i];
		}
	}

	void generate(string s)
	{
		assert(s.length() == 16);
		int i = 0;
		while (i < 16)
		{
			if (s[i] >= '0' && s[i] <= '9') matrix[i++] = s[i] - '0';
			else matrix[i++] = s[i] - 'A' + 10;
		}
	}

	void print()
	{
		for (int i = 0; i < 16; i++)
		{
			cout << setw(3) << left << (int)matrix[i];
			if (i % 4 == 3)
				cout << endl;
		}
	}

	bool is_valid()
	{
		int c = 0;
		int sum = 0;
		for (int i = 0; i < 15; ++i)
		{
			for (int j = i + 1; j < 15; ++j)
				if (matrix[j] < matrix[i])
					c++;
			sum += c;
			c = 0;
		}
		if ((sum + empty_ind + 1) % 2 == 1)
			return false;
		return true;
	}

	bool is_final()
	{
		if (matrix[15] != 0)
			return false;
		for (int i = 0; i < 15; ++i)
			if (matrix[i] != i+1)
				return false;
		return true;
	}

	state make_move(direction d)
	{
		if (!is_valid_move(d))
		{
			cout << "INVALID MOVE" << endl;
			return *this;
		}
		switch (d)
		{
		case Up:
			swap(matrix[empty_ind], matrix[empty_ind + 4]);
			empty_ind = empty_ind + 4;
			break;
		case Down: 
			swap(matrix[empty_ind], matrix[empty_ind - 4]);
			empty_ind = empty_ind - 4;
			break;
		case Left:
			swap(matrix[empty_ind], matrix[empty_ind + 1]);
			empty_ind = empty_ind + 1;
			break;
		case Right:
			swap(matrix[empty_ind], matrix[empty_ind - 1]);
			empty_ind = empty_ind - 1;
			break;
		}
		state new_state = state(empty_ind, matrix);
		return(new_state);
	}


};

int main()
{
	state s;
	s.generate("356FA7109C2B4D8E");
	s.print();
	cout << endl;
	//cout << s.is_final();
	s.generate("123456789ABCDEF0"); // 0
	s.print();
	cout << endl;
	//cout << s.is_valid() << endl;
	s.generate("213456789ABCDEF0"); // 1 (2 & 1)
	s.print();
	cout << endl;
	//cout << s.is_valid() << endl;
	s.generate("123456798ABCDFE0"); // 2 (F & E, 9 & 8)
	s.print();
	cout << endl;
	//cout << s.is_valid() << endl;
	s.generate("132456798ABCDFE0"); // 3 (3 & 2, F & E, 9 & 8)
	s.print();
	cout << endl;
	//cout << s.is_valid() << endl;
	getchar();
}
