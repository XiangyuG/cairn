/*
 Copyright 2023 Google LLC

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef CAIRN_MIDEND_H_
#define CAIRN_MIDEND_H_

#include "frontends/common/resolveReferences/referenceMap.h"
#include "frontends/p4/typeMap.h"
#include "ir/pass_manager.h"
#include "GlobalVariableReplacement.h"
#include "ExtractandLookaheadConversion.h"

namespace cairn {

class MidEnd : public PassManager {
  ::P4::ReferenceMap ref_map_;
  ::P4::TypeMap type_map_;

 public:
  explicit MidEnd() {
    // Set internal name explicitly. Otherwise the pass dump file will use the
    // fully qualified class name namespace::to::MidEnd.
    internalName = "MidEnd";

    addPasses({
        // TODO: passes to add
        new ::P4::GlobalVariableReplacement(&ref_map_, &type_map_),
        new ::P4::ExtractandLookaheadConversion(&ref_map_, &type_map_),
        // new ::P4::LocalVariableInlining(),
        // new ::P4::ReplacingHeaderReferences(),
        // new ::P4::GlobalMemoryAllocation(),
        // new ::P4::KeyAllocation(),
        // new ::P4::StageAssignment(),
        // new ::P4::RuleTranslation(),
    });
  }
};

}  // namespace cairn

#endif  // CAIRN_MIDEND_H_
