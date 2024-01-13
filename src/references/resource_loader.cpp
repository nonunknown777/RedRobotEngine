#include "resource_loader.hpp"

namespace rre  {

Resource ResourceLoader::load(const char* path) {
	TIMER_START();

	// char* contents = LoadFileText(path);
	// ryml::Tree tree = ryml::parse_in_arena(ryml::to_csubstr(contents));
	// ryml::ConstNodeRef root = tree.crootref();

	// std::vector<ryml::csubstr> keys = std::vector<ryml::csubstr>();
	// std::vector<ryml::csubstr> vals = std::vector<ryml::csubstr>();
	// for(ryml::ConstNodeRef n : root.children()) {
	// 	keys.emplace_back(n.key());
	// 	vals.emplace_back(n.has_val() ? n.val() : ryml::csubstr{});
	// }


    // auto ref = root.find_child("nodes");
    
    // for(ryml::ConstNodeRef n : ref.children()) {
	// 	std::cout << n.key() << std::endl;
	// }

	TIMER_END("load_yaml");

    return Resource();
}

}
