#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

int countUniqueIPs(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return -1;
    }

    std::unordered_set<std::string> unique_ips;
    std::string ip;

    while (file >> ip)
    {
        unique_ips.insert(ip);
    }

    file.close();
    return unique_ips.size();
}

int main()
{
    std::string filename = "ip_addresses.txt";
    int uniqueCount = countUniqueIPs(filename);

    if (uniqueCount != -1)
    {
        std::cout << "Number of unique IP addresses: " << uniqueCount << std::endl;
    }

    return 0;
}
