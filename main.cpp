#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

namespace fs = boost::filesystem;
namespace pt = boost::property_tree;

void json() {
	pt::ptree root;
	pt::read_json("data.json", root);
	cout << root.get<string>("some.complex.path");
}

void file_system() {
	fs::path p(fs::current_path());

	try
	{
		if (exists(p))
		{
			if (is_regular_file(p))
				cout << p << " size is " << file_size(p) << '\n';

			else if (is_directory(p))
			{
				cout << p << " is a directory containing:\n";

				for (const fs::directory_entry& x : fs::directory_iterator(p))
					cout << "    " << x.path().generic_path() << '\n';
			}
			else
				cout << p << " exists, but is not a regular file or directory\n";
		}
		else
			cout << p << " does not exist\n";
	}

	catch (const fs::filesystem_error & ex)
	{
		cout << ex.what() << '\n';
	}
}

int main(int argc, char* argv[])
{
	cout << "json" << endl;
	json();
	cout << endl;
	cout << endl;

	cout << "file system" << endl;
	file_system();
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}