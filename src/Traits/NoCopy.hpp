#pragma once

namespace Traits {
class NoCopy {
 public:
    NoCopy() {}
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
};
}  // namespace Traits
