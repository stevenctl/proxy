#pragma once

#include "envoy/server/filter_config.h"
#include "source/extensions/filters/network/custom_tlv_filter/config.pb.h"

namespace Envoy {
namespace Network {
namespace CustomTLV {

/**
 * Config registration for the filter. @see
 *  NamedNetworkFilterConfigFactory.
 */
class CustomTLVFilterConfigFactory
    : public Server::Configuration::NamedListenerFilterConfigFactory {
public:
  Network::ListenerFilterFactoryCb 
  createListenerFilterFactoryFromProto(const Protobuf::Message&,
                                       const Network::ListenerFilterMatcherSharedPtr& listener_filter_matcher,
                                       Server::Configuration::ListenerFactoryContext&) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override;

  std::string name() const override { return "custom_tlv_filter"; }

private:
  Network::ListenerFilterFactoryCb
  createFilterFactory(const io::istio::custom_tlv_filter::CustomTLVFilterConfig& proto_config,
                      Server::Configuration::FactoryContext& context);

  Network::ListenerFilterFactoryCb 
  createFilterFactory(const io::istio::custom_tlv_filter::CustomTLVFilterConfig& proto_config,
                      const Network::ListenerFilterMatcherSharedPtr& listener_filter_matcher,
                      Server::Configuration::ListenerFactoryContext& context);

};

} // namespace CustomTLV
} // namespace Network
} // namespace Envoy
