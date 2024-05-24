#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

bool isNumber(const std::string& s)
{
	std::istringstream iss(s);
	double num;
	iss >> num; // try to read the number into num
	// check that there are no leftover characters and the stream did not encounter an error
	return iss.eof() && !iss.fail();
}


int main() {
	const int itemnameWidth = 40;
	const int quantityWidth = 10;
	const int itemtotalWidth = 6;



	string Name;
	std::map<string, int> Menu =
	{
		{"Xialong Bao (12 pcs)", 350},
		{"Fried Rice", 400},
		{"Shrimp & Kurobuta Pork Spicy Wontons", 250},
		{"Noodles with sesame sauce", 250},
		{"Bubble Milk tea", 150}
	};

	std::map<string, int> Orders;

	//Print get the name:
	std::cout << "Enter your name: " << std::endl;
	std::cin >> Name;
	//Display the menu
	for (const auto& item : Menu) {
		std::cout << "Item: " << item.first << ", Price: Php " << item.second << std::endl;
	}



	std::string header = "orders";

	int total_width = itemtotalWidth + itemnameWidth + quantityWidth;
	int numDashes = (total_width - header.length()) / 2;
	std::string line = std::string(numDashes, '-') + header + std::string(numDashes, '-');

	// If totalWidth is odd and header.length() is even (or vice versa), add one more dash
	if ((total_width % 2) != (header.length() % 2)) {
		line += '-';
	}

	std::cout << line << std::endl;
	//Get the order
	for (const auto& item : Menu) {
		int quantity;
		std::cout << "Enter the quantity for " << item.first << ": ";
		std::cin >> quantity;
		Orders[item.first] = quantity;
	}

	//calculate the total price
	double total = 0;
	for (const auto& item : Orders) {
		total += Menu[item.first] * item.second;
	}

	//Display the order


	std::cout << "\n" << "Customer Name: " << Name << std::endl;

	std::cout << std::left << std::setw(itemnameWidth) << "Name" << std::setw(quantityWidth) << "Quantity" << std::setw(itemtotalWidth) << "Total" << std::endl;
	std::cout << std::string(itemnameWidth + quantityWidth + itemtotalWidth, '-') << std::endl;

	//std::cout << "--------------Orders--------------" << std::endl;
	for (const auto& item : Orders) {
		if (Orders[item.first] > 0) {
			std::cout << std::left << std::setw(itemnameWidth) << item.first << std::setw(quantityWidth) << item.second << std::setw(itemtotalWidth) << Menu[item.first] * item.second << std::endl;

		}
	}
	std::cout << std::string(itemnameWidth + quantityWidth + itemtotalWidth, '-') << std::endl;
	std::cout << "Total Price: " << "Php " << total << std::endl;


	double money_paid = 0;
	double remaining = total;
	//Payment
	std::cout << "Please pay your money" << std::endl;
	std::string input = "";
	double payment = 0;
	while (remaining > 0) {
		money_paid += payment;
		remaining -= payment;
		if (remaining > 0) {
			std::cout << "You still need to pay: " << "Php " << remaining << std::endl;
			std::cin >> input;
		}
		while (!isNumber(input)) {
			std::cout << "Please enter a valid number" << std::endl;
			std::cin >> input;
		}
		payment = std::stod(input);
	}

	if (remaining < 0) {
		std::cout << "Your change is: " << "Php " << -remaining << std::endl;
	}
	else {
		std::cout << "Thank you for shopping with us!" << std::endl;
	}

	return 0;
}
