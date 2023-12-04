#include "source/extensions/filters/network/custom_tlv_filter/config.h"

#include "envoy/network/connection.h"
#include "envoy/registry/registry.h"
#include "source/extensions/filters/network/custom_tlv_filter/custom_tlv_filter.h"

namespace Envoy {
namespace Network {
namespace CustomTLV {

Network::ListenerFilterFactoryCb CustomTLVFilterConfigFactory::createListenerFilterFactoryFromProto(
    const Protobuf::Message& config, 
    const Network::ListenerFilterMatcherSharedPtr& listener_filter_matcher,
    Server::Configuration::ListenerFactoryContext& context
) {
  return createFilterFactory(
      dynamic_cast<const io::istio::custom_tlv_filter::CustomTLVFilterConfig&>(config),
      listener_filter_matcher,
      context
  );
}

ProtobufTypes::MessagePtr CustomTLVFilterConfigFactory::createEmptyConfigProto() {
  return std::make_unique<io::istio::custom_tlv_filter::CustomTLVFilterConfig>();
}

Network::ListenerFilterFactoryCb CustomTLVFilterConfigFactory::createFilterFactory(
    const io::istio::custom_tlv_filter::CustomTLVFilterConfig& proto_config,
    const Network::ListenerFilterMatcherSharedPtr& listener_filter_matcher,
    Server::Configuration::ListenerFactoryContext& context
) {
  (void)context; // TODO unused
  (void)proto_config; // TODO unused
  ConfigSharedPtr filter_config(std::make_shared<CustomTLVFilterConfig>());
  return [filter_config, listener_filter_matcher](Network::ListenerFilterManager& filter_manager) -> void {
    filter_manager.addAcceptFilter(listener_filter_matcher, std::make_unique<CustomTLVFilter>(filter_config));
  };

}


/**
 * Static registration for the filter. @see RegisterFactory.
 */
static Registry::RegisterFactory<CustomTLVFilterConfigFactory,
                                 Server::Configuration::NamedListenerFilterConfigFactory>
    registered_;

}
}
}
