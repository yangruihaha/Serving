// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <string>
#include "common/inner_common.h"
#include "framework/channel.h"
#include "op/op.h"

namespace baidu {
namespace paddle_serving {
namespace predictor {

struct DemoData {
  boost::unordered_map<std::string, int> name_id;
  int data;
};

class StructOp : public OpWithChannel<DemoData> {
 public:
  DECLARE_OP(StructOp);

  int inference() {
    DemoData* data = mutable_data<DemoData>();
    data.data = 1;

    return 0;
  }
};

DEFINE_OP(StructOp);

}  // namespace predictor
}  // namespace paddle_serving
}  // namespace baidu
