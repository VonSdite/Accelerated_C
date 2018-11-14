#include "iostream"
#include "vector"

using namespace std;

template<class _InIt1,
    class _InIt2,
    class _Pr> inline
    bool _Equal(_InIt1 _First1, _InIt1 _Last1,
        _InIt2 _First2, _Pr _Pred=[](int &m, int &n) { return m == n; })
    {    // compare [_First1, _Last1) to [_First2, ...) using _Pred
        for (; _First1 != _Last1; ++_First1, ++_First2)
            if (!_Pred(*_First1, *_First2))
                return (false);
        return (true);
    }


int main(int argc, char const *argv[])
{
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    b.push_back(1);
    cout<< _Equal(a.begin(),a.end(),b.begin(),);

    return 0;
}