#include <trunk-recorder/plugin_manager/plugin_api.h>
#include <trunk-recorder/systems/system.h>
#include <boost/dll/alias.hpp> // for BOOST_DLL_ALIAS
#include <boost/foreach.hpp>
#include <boost/log/trivial.hpp>

class Example_Plugin : public Plugin_Api {

public:


int unit_registration(System *sys, long source_id) {
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_data_registration " << short_name;
    return 0;
}

int unit_deregistration(System *sys, long source_id) { 
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_deregistration " << short_name;
    return 0;
}  
int unit_acknowledge_response(System *sys, long source_id) { 
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_ack_response " << short_name;
    return 0;
}

int unit_group_affiliation(System *sys, long source_id, long talkgroup_num) {
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_group_affiliation " << short_name;
    return 0;
}

int unit_data_grant(System *sys, long source_id) {
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_data_grant " << short_name;
    return 0;
}

int unit_answer_request(System *sys, long source_id, long talkgroup) {
    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_answer_request " << short_name;
    return 0;
}

int unit_location(System *sys, long source_id, long talkgroup_num) {

    std::string short_name = sys->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - unit_location " << short_name;
    return 0;

}

int call_start(Call *call) {

    std::string short_name = call->get_short_name();
    BOOST_LOG_TRIVIAL(info) << "EXAMPLE PLUGIN - call_start " << short_name;
}

int parse_config(boost::property_tree::ptree &cfg) {

    return 0;
  }

  static boost::shared_ptr<Example_Plugin> create() {
    return boost::shared_ptr<Example_Plugin>(
        new Example_Plugin());
  }
};

BOOST_DLL_ALIAS(
    Example_Plugin::create, // <-- this function is exported with...
    create_plugin             // <-- ...this alias name
)
