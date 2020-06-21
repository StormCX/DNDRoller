
#include <iostream>
#include <string>

int main()
{
	//initialization
	int n, d;
	std::cout << "\n| Welcome to the D&D Die Roller!";
	std::cout << "\n| Created by Nader K. Atout" << std::endl;	

	while (1) 
	{
		int average = 0, sum = 0;	//for final results
		std::string ans;
		
		std::cout << "\n| Roll Information (XdY): ";
		std::getline(std::cin, ans);

		if (_strcmpi(ans.c_str(), "exit") == 0)		//allows user to exit anytime.
			break;

		try //ensures no errors in the input string
		{
			if (ans.size() < 3)
				throw 3;

			int x = ans.find("d");
			std::string a = ans.substr(0, x);
			std::string b = ans.substr(x + 1, ans.size() - 1);
			n = stoi(a);
			d = stoi(b);
		}
		catch (...) 
		{
			std::cout << "| Error! Invalid input. Try again..." << std::endl;
			continue;
		}
		
		for (int i = 0; i < n; ++i) 
		{
			int x = rand() % d + 1;
			std::cout << "| Roll: " << x << std::endl;
			sum += x;
		}
		average = sum / n;

		std::cout << "| Average: \t" << average << std::endl 
			<< "| Sum: \t\t" << sum << std::endl;

		//test if user wants to continue.
		std::cout << "\n| Continue? (Press [Enter] or type \"exit\") ";	
		std::getline(std::cin, ans);

		if (_strcmpi(ans.c_str(), "exit") == 0 || !ans.empty())
			break;
	}
	std::cout << "\n| Thank you for using the D&D Roller!\n" << std::endl;	//exit message
	system("pause");
	return 0;
}