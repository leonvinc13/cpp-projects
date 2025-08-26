/*
Napisati program koji koristi predloške i klasu komparator za provjeru je li vektor cijelih brojeva poredan neoslabljujuće opadajuće.
*/

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Komparator {
public:
    auto vece_ili_jednako(T a, T b) {
        return a >= b;
    }
};

template <class P, class Komparator>
bool usporedi(const vector<P>& v, Komparator cmp) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (!cmp.vece_ili_jednako(v[i - 1], v[i])) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> v = { 12, 2, 1 };
    bool r = usporedi<int>(v, Komparator<int>());
    cout << "rezultat: " << r << endl;  // treba ispisati 1
    return 0;
}


