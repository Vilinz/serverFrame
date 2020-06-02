#include "vilin/config.h"
#include "vilin/log/log.h"
#include <yaml-cpp/yaml.h>

vilin::ConfigVar<int>::ptr g_int_value_config = vilin::Config::Lookup("system.port", (int)8080, "system port");

vilin::ConfigVar<float>::ptr g_float_value_config = vilin::Config::Lookup("system.value", (float)1.1f, "system value");

vilin::ConfigVar<std::vector<int>>::ptr g_int_vec_value_config = vilin::Config::Lookup("system.int_vec", std::vector<int>{1,2}, "system int vector");

void print_yaml(const YAML::Node& node, int level) {
	if(node.IsScalar()) {
		VILIN_LOG_INFO(VILIN_LOG_ROOT()) << std::string(level * 4, ' ')
			<< node.Scalar() << " - " << node.Type() << " - " << level;
	} else if(node.IsNull()) {
		VILIN_LOG_INFO(VILIN_LOG_ROOT()) << std::string(level * 4, ' ')
			<< "NULL - " << node.Type() << " - " << level;
	} else if(node.IsMap()) {
		for(auto it = node.begin(); it != node.end(); ++it) {
			VILIN_LOG_INFO(VILIN_LOG_ROOT()) << std::string(level * 4, ' ')
			<< it->first << " - " << it->second.Type() << " - " << level << " IsMap";
			print_yaml(it->second, level + 1);
		}
	} else if(node.IsSequence()) {
		for(size_t i = 0; i < node.size(); ++i) {
			VILIN_LOG_INFO(VILIN_LOG_ROOT()) << std::string(level * 4, ' ')
			<< i << " - " << node[i].Type() << " - " << level << " IsSequence";
			print_yaml(node[i], level + 1);
		}
	}
}

void test_yaml() {
	YAML::Node root = YAML::LoadFile("/home/vilingif/Desktop/serverFrame/bin/conf/log.yml");
	print_yaml(root, 0);

	VILIN_LOG_INFO(VILIN_LOG_ROOT()) << root.Scalar();
}

void test_config() {
	VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "before: " << g_int_value_config->getValue();
	VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "before: " << g_float_value_config->getValue();

	auto v = g_int_vec_value_config->getValue();
	for(auto &i : v) {
		VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "before int_vec " << i;
	}

	YAML::Node root = YAML::LoadFile("/home/vilingif/Desktop/serverFrame/bin/conf/log.yml");
	vilin::Config::LoadFromYaml(root);

	VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "after: " << g_int_value_config->getValue();
	VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "after: " << g_float_value_config->getValue();

	v = g_int_vec_value_config->getValue();
	for(auto &i : v) {
		VILIN_LOG_INFO(VILIN_LOG_ROOT()) << "after int_vec " << i;
	}
}

int main(int argc, char** argv) {
	

	//test_yaml();
	test_config();
	return 0;
}