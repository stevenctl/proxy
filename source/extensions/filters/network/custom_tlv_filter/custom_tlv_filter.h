#pragma once

#include "envoy/network/filter.h"
#include "envoy/server/filter_config.h"
#include "source/common/common/logger.h"
#include "source/extensions/filters/network/custom_tlv_filter/config.pb.h"

namespace Envoy {
namespace Network {
namespace CustomTLV {

class CustomTLVFilterConfig {
public:
  CustomTLVFilterConfig() {}
};

using ConfigSharedPtr = std::shared_ptr<CustomTLVFilterConfig>;

class CustomTLVFilter : public Network::ListenerFilter,
                        protected Logger::Loggable<Logger::Id::filter> {
public:
  CustomTLVFilter(const ConfigSharedPtr& config) {
    (void)config; // silence unused param
  }

  // Network::ListenerFilter
  Network::FilterStatus onAccept(Network::ListenerFilterCallbacks& cb) override;
  Network::FilterStatus onData(Network::ListenerFilterBuffer& buffer) override;
  size_t maxReadBytes() const override { return 0; }
};

}
}
}
