#include "source/extensions/filters/network/custom_tlv_filter/custom_tlv_filter.h"

#include <cstdint>
#include <string>

#include "envoy/network/connection.h"

namespace Envoy {
namespace Network {
namespace CustomTLV {


Network::FilterStatus CustomTLVFilter::onAccept(Network::ListenerFilterCallbacks& cb) {
    (void)cb; // silence unused param
    ENVOY_LOG(debug, "custom_tlv: onAccept");
    return Network::FilterStatus::StopIteration;
}

Network::FilterStatus CustomTLVFilter::onData(Network::ListenerFilterBuffer& buffer) {
    (void)buffer; // silence unused param
    ENVOY_LOG(debug, "custom_tlv: onData");
    return Network::FilterStatus::Continue;
}

}
}
}
