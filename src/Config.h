/**
 * Author: rodrigo
 * 2015
 */
#pragma once

#include <string>

using namespace std;

enum DebugLevel
{
	NONE, LOW, MEDIUM, HIGH
};

class Config
{
public:
	~Config();

	// Returns the instance of the singleton
	static Config *getInstance()
	{
		static Config *instance = new Config();
		return instance;
	}
	// Loads the configuration file
	static void load(const string &_filename);

	static inline DebugLevel getDebugLevel()
	{
		return getInstance()->level;
	}

	static double getBallRadius();

private:
	Config();

	// Parses the given value according to the given key
	static void parse(const string _key, const string _value);

	DebugLevel level;
	double radius;
};

