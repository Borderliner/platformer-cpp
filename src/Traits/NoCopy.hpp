#pragma once

namespace Traits {

/**
 * @brief By inheriting this class, you will remove copying functionality from your class
 * 
 */
class NoCopy {
 public:
    NoCopy() {}
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator=(const NoCopy&) = delete;
};
}  // namespace Traits
