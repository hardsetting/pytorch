#include "caffe2/operators/experimental/c10/schemas/add.h"
#include <ATen/core/dispatch/OpSchemaRegistration.h>
#include "caffe2/core/operator_c10wrapper.h"

using caffe2::CPUContext;

C10_DEFINE_OP_SCHEMA(caffe2::ops::Add);

namespace {

struct LegacyBroadcastParameter final {
  using type = bool;
  static constexpr const char* name() {
    return "legacy_broadcast";
  }
  static constexpr bool default_value() {
    return true;
  }
};
struct AxisParameter final {
  using type = int;
  static constexpr const char* name() {
    return "axis";
  }
  static constexpr int default_value() {
    return -1;
  }
};
} // namespace

namespace caffe2 {
REGISTER_C10_OPERATOR_FOR_CAFFE2_DISPATCH_WITH_PARAMETERS(
    ops::Add,
    C10Add_DontUseThisOpYet,
    ParameterHelper<LegacyBroadcastParameter>,
    ParameterHelper<AxisParameter>)
}
