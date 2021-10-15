#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void brute_force(map<string, int>& map, ofstream& file, int s)
{
	multimap<int, string> m;
	for (auto& iter : map)
		m.insert({ iter.second, iter.first });
	for (multimap<int, string>::reverse_iterator iter = m.rbegin(); iter != m.rend(); ++iter)
		file << iter->second << "; " << iter->first << "; " << (double)((double)(s/100) * iter->first) << endl;
}

string clr_str(string x) {
	int s = x.size();
	for (int i = 0; i < s; i++)
		if ((!isdigit(x[i])) && (!isalpha(x[i])))
			x[i] = ' ';
	return x;
}


int main(int argc, char** argv) {
	string arr;
	string str;
	istringstream pot;
	int s = 0;
	map <string, int> mp;
	ifstream f(argv[1]);
	ofstream g(argv[2]);
    getline(f, arr);
	while (f) {
		arr = clr_str(arr);
		pot.clear();
		pot.str(arr);
		while (pot) {
			getline(pot, str, ' ');
			if (str == "")
				continue;
			else {
				mp[str]++;
				s++;
			}
		}
		getline(f, arr);
	}
	s /= 100;
	brute_force(mp, g, s);
    f.close();
	g.close();
	return 0;
}
