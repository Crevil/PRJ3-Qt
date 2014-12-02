#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* SPI_api ERRORS*/
#define ACT_ERR 10
#define DEACT_ERR 11
#define VER_ERR 12
#define CONF_ERR 13
#define LOG_ERR 14

class SPI_api{
public:
	int activate(int unit) const;
	int deactivate(int unit) const;
	int verify(int unit) const;
	int config(int unit, float temp, float humi);
	int getLog(vector<string> &data, int* units, int size);
};
