#include "TBitField.h"

#pragma once

class TSet
{
private:
	int universe;
	TBitField TB;

public:
	TSet(int u_size = 0)
	{
		universe = u_size;
		TB = TBitField(universe);
	}

	TSet(const TSet& tmp)
	{
		universe = tmp.universe;
		TB = tmp.TB;
	}

	~TSet() {};

	void Add(int k)
	{
		TB.Add(k, universe);
	}

	void Del(int k)
	{
		TB.Del(k, universe);
	}

	string TSetToString()
	{
		return TB.TBitFieldToString();
	}

	TSet& operator = (TSet tmp)
	{
		if (universe != tmp.universe)
		{
			universe = tmp.universe;
		}
		TB = tmp.TB;
	}

	TSet operator & (TSet tmp)
	{
		TSet res;

		if (universe == tmp.universe)
		{
			res.TB = TB & tmp.TB;
		}

		return res;
	}

	TSet operator | (TSet tmp)
	{
		TSet res;

		if (universe == tmp.universe)
		{
			res.TB = TB | tmp.TB;
		}

		return res;
	}

	TSet operator ~ ()
	{
		TSet res(*this);

		res.TB = ~TB;

		return res;
	}
};