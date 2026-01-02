#pragma once
#include <string>
#include <vector>

class ALogger;

class PluginManager {
public:
	PluginManager( ALogger* logger = nullptr );
	~PluginManager() = default;

	void load_plugins();
	void unload_plugins();

private:
	std::vector<std::string> loaded_plugins;
    ALogger* m_logger;
};
