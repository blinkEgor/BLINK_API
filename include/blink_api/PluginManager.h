#pragma once
#include <string>
#include <vector>

class PluginManager {
public:
	PluginManager() = default;
	~PluginManager() = default;

	void load_plugins();
	void unload_plugins();

private:
	std::vector<std::string> loaded_plugins;
};
