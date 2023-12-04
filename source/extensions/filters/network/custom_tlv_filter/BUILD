
load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_cc_library",
    "envoy_cc_test",
    "envoy_extension_package",
)

envoy_extension_package()

licenses(["notice"])


envoy_cc_extension(
    name = "filter_lib",
    srcs = ["custom_tlv_filter.cc"],
    hdrs = ["custom_tlv_filter.h"],
    repository = "@envoy",
    deps = [
        ":config_cc_proto",
        "//extensions/common:context",
        "//extensions/common:metadata_object_lib",
        "//extensions/common:proto_util",
        "//source/extensions/common/workload_discovery:api_lib",
        "@envoy//envoy/registry",
        "@envoy//source/common/network:utility_lib",
    ],
)


envoy_cc_library(
    name = "config_lib",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    repository = "@envoy",
    deps = [
        ":filter_lib",
        "//source/extensions/filters/network/metadata_exchange/config:metadata_exchange_cc_proto",
        "@envoy//envoy/registry",
        "@envoy//envoy/server:filter_config_interface",
    ],
)

cc_proto_library(
    name = "config_cc_proto",
    deps = ["config"],
)

proto_library(
    name = "config",
    srcs = ["config.proto"],
)
