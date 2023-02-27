#include <bits/stdc++.h>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

bool isMatch(string &&p1, string &p2)
{
	return p1.find(p2) != string::npos;
}

// c plus plus has a recursive directory iterator, but it is not elegant and useless.
void find(string &&p, string &match)
{
	for (auto &entry : fs::directory_iterator(p, fs::directory_options::skip_permission_denied))
	{
		if (!fs::is_directory(entry.path()))
		{
			if (isMatch(entry.path().string(), match))
			{
				cout << entry << '\n';
			}
		}
		else
			find(entry.path().string(), match);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "args: path[str] and a file match[str]\n";
		return 0;
	}

	string match = argv[2];

	find(argv[1], match);
}
