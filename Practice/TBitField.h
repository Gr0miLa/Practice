#pragma once

class TBitField
{
private:
    unsigned int* mem;
    int size;

    // k - номер элемента универса, который хотим добавить (1 <= k <= universe)
    int GetNumberMem(int k, int universe)
    {
        int L = -1;
        if (k >= 1 && k <= universe)
            L = (k - 1) / (sizeof(unsigned int) * 8);

        return L;
    }
    int GetNumberBit(int k, int universe)
    {
        int L = -1;
        if (k >= 1 && k <= universe)
            L = (k - 1) % (sizeof(unsigned int) * 8);

        return L;
    }

public:
    TBitField(int universe = 0)
    {
        size = universe / (sizeof(unsigned int) * 8) + 1;

        mem = new unsigned int[size];
        for (int i = 0; i < size; i++)
        
            mem[i] = 0;
    }
    TBitField(const TBitField& tmp)
    {
        size = tmp.size;
        mem = new unsigned int[size];

        for (int i = 0; i < size; i++)
        {
            mem[i] = tmp.mem[i];
        }
    }

    ~TBitField()
    {
        delete[] mem;
    };

    string TBitFieldToString(int universe)
    {
        string STR = "";

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < sizeof(unsigned int) * 8; j++)
            {
                int K = i * sizeof(unsigned int) + j + 1;

                if (K <= universe)
                    if ((mem[i] & (1 << j)) > 0)
                        STR = STR + to_string(K) + " ";
            }
        }

        return STR;
    }

    void Add(int k, int universe)
    {
        int pos = GetNumberBit(k, universe);

        int m = GetNumberMem(k, universe);

        mem[m] = mem[m] | (1 << pos);
    }

    TBitField& operator = (TBitField tmp)
    {
        if (size != tmp.size)
        {
            if (this->size != 0)
                delete[] mem;
            size = tmp.size;
            mem = new unsigned int[size];
        }
        for (int i = 0; i < size; i++)
        {
            mem[i] = tmp.mem[i];
        }

        return *this;
    }

    /*void Del(int k, int universe)
    {
        if ((k < 0) && (k <= universe))
        {
            int pos = GetNumberBit(k, universe);
            int m = GetNumberMem(k, universe);

            mem[m] & (~(1 << pos));
        }
    }*/

    TBitField operator & (TBitField tmp)
    {
        TBitField res;

        if (size == tmp.size)
        {
            res = TBitField(*this);

            for (int i = 0; i < size; i++)
            {
                res.mem[i] = mem[i] & tmp.mem[i];
            }
        }

        return res;
    }

    TBitField operator | (TBitField tmp)
    {
        TBitField res;

        if (size == tmp.size)
        {
            res = TBitField(*this);

            for (int i = 0; i < size; i++)
            {
                res.mem[i] = mem[i] | tmp.mem[i];
            }
        }

        return res;
    }

    TBitField operator ~ ()
    {
        TBitField res(*this);

        for (int i = 0; i < size; i++)
        {
            res.mem[i] = ~(mem[i]);
        }

        return res;
    }
};

